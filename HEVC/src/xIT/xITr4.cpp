void xITr4(short coeff[4][4],short block[4][4], UInt uiMode)
{
  int shift_1st = SHIFT_INV_1ST;
#if FULL_NBIT
  int shift_2nd = SHIFT_INV_2ND - ((short)g_uiBitDepth - 8);
#else
  int shift_2nd = SHIFT_INV_2ND - g_uiBitIncrement;
#endif
  short tmp[4][4];
  
  if (uiMode != REG_DCT && g_aucDCTDSTMode_Vert[uiMode] )    // Check for DCT or DST
  {
    fastInverseDst(coeff,tmp,shift_1st);    // Inverse DST by FAST Algorithm, coeff input, tmp output
  }
  else
  {
    partialButterflyInverse4(coeff,tmp,shift_1st);    
  } 
  if (uiMode != REG_DCT && g_aucDCTDSTMode_Hor[uiMode] )    // Check for DCT or DST
  {
    fastInverseDst(tmp,block,shift_2nd); // Inverse DST by FAST Algorithm, tmp input, coeff output
  }
  else
  {
    partialButterflyInverse4(tmp,block,shift_2nd);
  }   
}
