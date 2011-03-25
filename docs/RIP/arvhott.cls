
%---------------------------------------------------------------
% Lab version 1 style file by Richard Thavot, 2011
%---------------------------------------------------------------


%-------------------------- identification ---------------------
%\NeedsTeXFormat{LaTeX2e}[1995/12/01]
\ProvidesClass{arvhott}[2011/02/16 v1 Lab class]

%\LoadClass[titlepage,letterpaper,10pt]{revtex4}
\LoadClass[titlepage,letterpaper,10pt]{report}


\usepackage{graphicx} % For images
\usepackage{float}    % For tables and other floats
\usepackage{verbatim} % For comments and other
\usepackage{amsmath}  % For math
\usepackage{amssymb}  % For more math
\usepackage{fullpage} % Set margins and place page numbers at bottom center
\usepackage{listings} % For source code
\usepackage{subfig}   % For subfigures
\usepackage[usenames,dvipsnames]{color} % For colors and names
\usepackage[pdftex]{hyperref} % For hyperlinks and indexing the PDF


\newif\if@proposal
\newif\if@appnote
\newif\if@note
\newif\if@laboratory
\newif\if@report

\DeclareOption{proposal}{
	\@proposaltrue\@notefalse\@laboratoryfalse\@reportfalse\@appnotefalse
}
\DeclareOption{note}{
	\@proposalfalse\@notetrue\@laboratoryfalse\@reportfalse\@appnotefalse
}
\DeclareOption{laboratory}{
	\@proposalfalse\@notefalse\@laboratorytrue\@reportfalse\@appnotefalse
}
\DeclareOption{report}{
	\@proposalfalse\@notefalse\@laboratoryfalse\@reporttrue\@appnotefalse
}
\DeclareOption{appnote}{
	\@proposalfalse\@notefalse\@laboratoryfalse\@reportfalse\@appnotetrue
}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{note}}

\newcommand\@subclass{\relax}
\newcommand\@id{\relax}
\newcommand\id[1]{\renewcommand\@id{#1}}

\ProcessOptions
\if@proposal %
	\renewcommand\@subclass{Proposal}
\else \if@appnote %
	\renewcommand\@subclass{Application Note}
\else\if@laboratory %
	\renewcommand\@subclass{Laboratory}
\else\if@report %
	\renewcommand\@subclass{Report}
\else
	\renewcommand\@subclass{Note}
\fi\fi\fi\fi

\setcounter{chapter}{0}

\newcommand\@company{\relax}
\newcommand\@tcompany{\relax}
\newcommand\company[1]{\renewcommand\@company{\textnormal{#1}}%
                       \renewcommand\@tcompany{\par\textnormal{#1}}}

% HYPERLINKS %%%%%%%%%%%%%%%%%%%%%%%%
% SETUP
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\hypersetup{ % play with the different link colors here
    colorlinks,
    citecolor=blue,
    filecolor=blue,
    linkcolor=blue,
    urlcolor=blue % set to black to prevent printing blue links
}

% LST %%%%%%%%%%%%%%%%%%%%%%%%
% Define new language CAL
% newcommande inputcode[language]{file} 
%		language by default C++
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\lstdefinelanguage{CAL}%
 {classoffset=0,
  morekeywords={action,actor,bitand,else,end, function, priority,
    schedule, guard, var, do, if,lshift,not,then,network,entities,structure},
        classoffset=1,
  morekeywords={true, false,{==>}},
        literate  = {==>}{{$\Rightarrow$}}1,% rightarrow
        classoffset=0,%
        basicstyle=\footnotesize,
  morecomment=[s]{/*}{*/},%
  morecomment=[l]{//},%
  moredelim=[is][\color{DarkGoldenrod}]{|}{|},
  morestring=[b]",%
  morestring=[b]',%%
 }[keywords,comments,strings]%

\newcommand{\inputcode}[2][C]{
\lstset{ 
% choose the language of the code ("language=Verilog" is popular as well)
	language = #1,
% sets the size of the tabs in spaces (1 Tab is replaced with 3 spaces)
	tabsize=3,								
% the size of the fonts that are used for the code
	basicstyle=\footnotesize,
% where to put the line-numbers
	numbers=left,
% the size of the fonts that are used for the line-numbers
	numberstyle=\footnotesize,
% the step between two line-numbers. If it's 1 each line will be numbered
	stepnumber=2,
% how far the line-numbers are from the code
	numbersep=5pt,
% choose the background color. You must add \usepackage{color}        
	backgroundcolor=\color{White}, 
% adds a frame around the code    
	frame=single,
% sets the caption-position to bottom    
	captionpos=b,
% sets automatic line breaking    
	breaklines=true,
% sets if automatic breaks should only happen at whitespace
	breakatwhitespace=false,
% sets the comment style
	commentstyle=\color{ForestGreen},
% sets the keyword style
	keywordstyle=\color{BrickRed}
}
\lstinputlisting{#2}
}

% TITLE PAGE CONTENT %%%%%%%%%%%%%%%%
% Remember to fill this section out for each
% lab write-up.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


\renewcommand{\maketitle}{%
\begin{titlepage}
\begin{center}
{\LARGE \textsc{{\@subclass} {\@id}} \\ \vspace{5pt}} 
{\Large \textsc{{\@title}} \\ \vspace{10pt}} 
\rule[13pt]{\textwidth}{1pt} \\ \vspace{110pt}
{\large	\begin{tabular}[t]{l}%
      		\@author
    		\end{tabular} 
		\\ \vspace{70pt}
}
{\large {\@tcompany}\\ \vspace{10pt} }
\today
\end{center}
\end{titlepage}}

% END TITLE PAGE CONTENT %%%%%%%%%%%%%%%%%%%%



