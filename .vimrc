set rtp+=~/.vim/autoload/javacomplete.vim
set rtp+=~/.vim/bundle/Vundle
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" " alternatively, pass a path where Vundle should install plugins
" "call vundle#begin('~/some/path/here')
"
" " let Vundle manage Vundle, required
" "Plugin 'VundleVim/Vundle.vim'
"
" " The following are examples of different formats supported.
" " Keep Plugin commands between vundle#begin/end.
" " plugin on GitHub repo
" "Plugin 'tpope/vim-fugitive'
" " plugin from http://vim-scripts.org/vim/scripts.html
" " Plugin 'L9'
" " Git plugin not hosted on GitHub
" "Plugin 'git://git.wincent.com/command-t.git'
 "" git repos on your local machine (i.e. when working on your own plugin)""
" "Plugin 'file:///home/gmarik/path/to/plugin'
" " The sparkup vim script is in a subdirectory of this repo called vim.
" " Pass the path to set the runtimepath properly.
" "Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" " Install L9 and avoid a Naming conflict if you've already installed a
" " different version somewhere else.
" " Plugin 'ascenator/L9', {'name': 'newL9'}
"
Bundle 'Valloric/YouCompleteMe'
" " All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" " To ignore plugin indent changes, instead use:
" "filetype plugin on
" "
" "Bundle 'Valloric/YouCompleteMe'
" " Brief help
" " :PluginList       - lists configured plugins
" " :PluginInstall    - installs plugins; append `!` to update or just
" :PluginUpdate
" " :PluginSearch foo - searches for foo; append `!` to refresh local cache
" " :PluginClean      - confirms removal of unused plugins; append `!` to
" auto-approve removal
" "
" " see :h vundle for more details or wiki for FAQ
" " Put your non-Plugin stuff after this line
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

function Compile()
		if &filetype == 'cpp'
				exec "!g++ % -o %< -g -Wall -Wextra -Wconversion -std=c++14"
		elseif &filetype == 'c'
				exec "!gcc % -o %< -g -Wall -Wextra -Wconversion"
		elseif &filetype == 'pas'
				exec "!fpc % -g"
		elseif &filetype == 'tex'
				exec "!xelatex '%'"
		elseif &filetype == 'java'
				exec "!javac %"
		elseif &filetype == 'scss'
				exec "!sass % > %<.css"
		else
		   	exec "!echo filetypenotfound"
		endif
endfunction

function Debug()
		if &filetype == 'cpp' 
				exec "!gdb ./%<"
		elseif &filetype == 'tex'
				exec "!okular './%<.pdf'"
		elseif &filetype == 'java'
				exec "!jdb %<"
		endif
endfunction

function Run()
		if &filetype == 'cpp'
				exec "!time ./%<"
		elseif &filetype == 'tex'
				exec "!okular './%<.pdf'"
		elseif &filetype == 'java'
				exec "!java %<"
		elseif &filetype == 'ruby'
				exec "!ruby %"
		elseif &filetype == 'html'
				exec "!firefox %"
		elseif &filetype == 'php'
				exec "!php %"
		elseif &filetype == 'sh'
				exec "!bash %"
		elseif &filetype == 'pas'
				exec "!time ./%<"
		endif
endfunction

set hlsearch
set mouse=a
set smartindent
set fdm=marker
set number
set tabstop=4
set softtabstop=4
set shiftwidth=4
syntax on
filetype plugin indent on
imap jj <esc>
imap <C-s> <Esc>:w!<CR>i
map <C-s> :w!<CR>
map <C-F9> : call Compile() <CR>
map <C-F5> : call Debug() <CR>
map <C-F6> : call Run() <CR>
map <F8> : ! g++ % -o %< -O2 <CR>
map <F12> : ! subl ./% <CR>
map <F2> : ! python % <CR>

inoremap ( ()<Esc>i
inoremap ' ''<Esc>i
inoremap " ""<Esc>i
inoremap [ []<Esc>i
inoremap { {<CR>}<Esc>i
inoremap ) <c-r>=ClosePair(')')<CR>
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap } <c-r>=CloseBracket()<CR>
inoremap " <c-r>=QuoteDelim('"')<CR>
inoremap ' <c-r>=QuoteDelim("'")<CR>

function ClosePair(char)
 if getline('.')[col('.') - 1] == a:char
 return "\<Right>"
 else
 return a:char
 endif
endf

function CloseBracket()
 if match(getline(line('.') + 1), '\s*}') < 0
 return "\<CR>}"
 else
 return "\<Esc>j0f}a"
 endif
endf

function QuoteDelim(char)
 let line = getline('.')
 let col = col('.')
 if line[col - 2] == "\\"
 return a:char
 elseif line[col - 1] == a:char
 return "\<Right>"
 else
 return a:char.a:char."\<Esc>i"
 endif
endf


colors koehler 

setlocal omnifunc=javacomplete#Complete
if has("autocmd")
"	autocmd Filetype java setlocal omnifunc=javacomplete#Complete   
"	autocmd FileType java setlocal completefunc=javacomplete#CompleteParamsInf
autocmd Filetype java setlocal omnifunc=javacomplete#Complete
autocmd Filetype java setlocal completefunc=javacomplete#CompleteParamsInf
endif

inoremap <buffer><C-X><C-U> <C-X><C-U><C-P>
inoremap <buffer><C-S-Space> <C-X><C-U><C-P>
autocmd Filetype java inoremap <buffer>. .<C-X><C-O><C-P>

let g:ycm_server_python_interpreter='/usr/bin/python'
let g:ycm_global_ycm_extra_conf='~/.vim/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf=0
let g:syntastic_always_populate_loc_list = 1
nnoremap <leader>jd :YcmCompleter GoToDefinitionElseDeclaration<CR>
imap <C-d> <esc>:YcmCompleter GoToDefinitionElseDeclaration<CR>i
nnoremap <F5> :YcmForceCompileAndDiagnostics<CR>

"omnifunc=javacomplete#Complete
"autocmd FileType java set omnifunc=javacomplete#Complete
"autocmd FileType java set completefunc=javacomplete#CompleteParamsInf
"autocmd FileType java,javascript,jsp inoremap <buffer>..<C-X><C-O><C-P>

