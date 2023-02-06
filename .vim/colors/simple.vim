set background=dark
hi clear
if exists("syntax_on")
	sy reset
endif

let g:colors_name = "simple"

hi String ctermfg=6
hi Statement ctermfg=4
hi! link Type Statement
hi! link Identifier Statement

if &t_Co >= 256
	hi Normal ctermfg=231 ctermbg=16
	hi LineNr ctermfg=231 ctermbg=0
	hi Comment ctermfg=241
	hi Special ctermfg=250
	hi Number ctermfg=255
	hi Float ctermfg=255
	hi Boolean ctermfg=255
	hi Character ctermfg=255
	hi Constant ctermfg=250
	hi Function ctermfg=250
	hi PreProc ctermfg=245
else
	hi Normal ctermfg=15 ctermbg=8
	hi LineNr ctermfg=15 ctermbg=0
	hi Comment ctermfg=7
	hi Special ctermfg=7
	hi Number ctermfg=7
	hi Float ctermfg=7
	hi Boolean ctermfg=7
	hi Character ctermfg=7
	hi Constant ctermfg=7
	hi Function ctermfg=7
	hi PreProc ctermfg=7
endif

hi! link NonText Normal
