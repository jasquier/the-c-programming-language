>h.oidts< edulcni#

021 HTGNEL_ENIL_XAM enifed#

;)eniLxam tni ,][enil rahc(eniLteg tni
;)ezis tni ,][lanigiro rahc(esrever diov

/* gnirts tupni eht sesrever */
)diov(niam tni
{
;htgnel tni    
;]HTGNEL_ENIL_XAM[eniLtnerruc rahc    
;]HTGNEL_ENIL_XAM[desreveReniLtnerruc rahc    

)0 > ))HTGNEL_ENIL_XAM ,eniLtnerruc(eniLteg = htgnel(( elihw    
{    
/* srahc erom ro 3 era ereht nehw esrever ylno ,enilwen+rahc elgnis a si 2=htgnel dna enilwen a si 1=htgnel */        
)3 => htgnel( fi        
{        
;)htgnel ,eniLtnerruc(esrever            
}        
;)eniLtnerruc ,"s%"(ftnirp        
}    
}

/* ni daer enil eht fo htgnel eht snruter ,][enil otni enil a daer :eniLteg */
)eniLxam tni ,][enil rahc(eniLteg tni
{
;i ,c tni    

)++i ;'n\' =! c && FOE =! ))(rahcteg = c( && 1 - eniLxam < i ;0 = i( rof    
;c = ]i[enil        

)'n\' == c( fi    
{    
;c = ]i[enil        
;++i        
}    

;'0\' = ]i[enil    

;i nruter    
}

/* senilwen gniliart esrever ton seod ,gnirts eht fo sretcarahc eht fo lasrever ecalp ni :esrever */
)ezis tni ,][lanigiro rahc(esrever diov
{
;0 = i tni    
3=ezis sah "0\n\ba" :gnirts tsetrohs // ;2 - ezis = j tni    
;pmet rahc    

)j < i( elihw    
{    
;]i[lanigiro = pmet        
;]j[lanigiro = ]i[lanigiro        
;pmet = ]j[lanigiro        

;++i        
;--j        
}    
}
