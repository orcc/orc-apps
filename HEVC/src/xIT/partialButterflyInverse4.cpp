/** 4x4 inverse transform implemented using partial butterfly structure (1D)
 *
 *  UPM 20120212
 *  \callgraph
 *  \param src   input data (transform coefficients)
 *  \param dst   output data (residual)
 *  \param shift specifies right shift after 1D transform
 */
void partialButterflyInverse4(short src[4][4],short dst[4][4],int shift)
{
  int j;    
  int E[2],O[2];
  int add = 1<<(shift-1);

  for (j=0; j<4; j++)
  {    
    /* Utilizing symmetry properties to the maximum to minimize the number of multiplications */    
    O[0] = g_aiT4[1][0]*src[1][j] + g_aiT4[3][0]*src[3][j];
    O[1] = g_aiT4[1][1]*src[1][j] + g_aiT4[3][1]*src[3][j];
    E[0] = g_aiT4[0][0]*src[0][j] + g_aiT4[2][0]*src[2][j];
    E[1] = g_aiT4[0][1]*src[0][j] + g_aiT4[2][1]*src[2][j];
    
    /* Combining even and odd terms at each hierarchy levels to calculate the final spatial domain vector */
#if IT_CLIPPING
    dst[j][0] = Clip3( -32768, 32767, (E[0] + O[0] + add)>>shift );
    dst[j][1] = Clip3( -32768, 32767, (E[1] + O[1] + add)>>shift );
    dst[j][2] = Clip3( -32768, 32767, (E[1] - O[1] + add)>>shift );
    dst[j][3] = Clip3( -32768, 32767, (E[0] - O[0] + add)>>shift );
#else
    dst[j][0] = (E[0] + O[0] + add)>>shift;
    dst[j][1] = (E[1] + O[1] + add)>>shift;
    dst[j][2] = (E[1] - O[1] + add)>>shift;
    dst[j][3] = (E[0] - O[0] + add)>>shift;
#endif
  }
}

/** UPM 20120212
 *  \callgraph 
 */

#if NSQT
void partialButterflyInverse4(short *src,short *dst,int shift, int line)
{
  int j;    
  int E[2],O[2];
  int add = 1<<(shift-1);

  for (j=0; j<line; j++)
  {    
    /* Utilizing symmetry properties to the maximum to minimize the number of multiplications */    
    O[0] = g_aiT4[1][0]*src[line] + g_aiT4[3][0]*src[3*line];
    O[1] = g_aiT4[1][1]*src[line] + g_aiT4[3][1]*src[3*line];
    E[0] = g_aiT4[0][0]*src[0] + g_aiT4[2][0]*src[2*line];
    E[1] = g_aiT4[0][1]*src[0] + g_aiT4[2][1]*src[2*line];

    /* Combining even and odd terms at each hierarchy levels to calculate the final spatial domain vector */
#if IT_CLIPPING
    dst[0] = Clip3( -32768, 32767, (E[0] + O[0] + add)>>shift );
    dst[1] = Clip3( -32768, 32767, (E[1] + O[1] + add)>>shift );
    dst[2] = Clip3( -32768, 32767, (E[1] - O[1] + add)>>shift );
    dst[3] = Clip3( -32768, 32767, (E[0] - O[0] + add)>>shift );
#else
    dst[0] = (E[0] + O[0] + add)>>shift;
    dst[1] = (E[1] + O[1] + add)>>shift;
    dst[2] = (E[1] - O[1] + add)>>shift;
    dst[3] = (E[0] - O[0] + add)>>shift;
#endif
            
    src   ++;
    dst += 4;
  }
}
#endif
