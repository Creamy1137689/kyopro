set number
set termguicolors

set expandtab
set smartindent
set shiftwidth=4
set softtabstop=4
set autochdir
set encoding=utf-8
set mouse=a

call plug#begin('~/.vim/plugged')
    Plug 'joshdick/onedark.vim'
    Plug 'w0ng/vim-hybrid'
    Plug 'jonathanfilip/vim-lucius'
    Plug 'itchyny/lightline.vim'
    Plug 'ntpeters/vim-better-whitespace'
    Plug 'Yggdroot/indentLine'
    Plug 'scrooloose/nerdtree', {'on': 'NERDTreeToggle'}
    Plug 'majutsushi/tagbar', {'on': 'TagbarToggle'}
    Plug 'junegunn/fzf', {'dir': '~/.fzf', 'do':'./install --all'}
    Plug 'junegunn/fzf.vim'
    Plug 'cohama/lexima.vim'
    Plug 'tpope/vim-fugitive'
    Plug 'airblade/vim-gitgutter'
    Plug 'dense-analysis/ale'
    Plug 'jistr/vim-nerdtree-tabs'
    Plug 'maximbaz/lightline-ale'
    Plug 'SirVer/ultisnips'
    Plug 'honza/vim-snippets'
    Plug 'neoclide/coc.nvim', {'branch': 'release'}
    Plug 'kassio/neoterm'
    Plug 'tpope/vim-commentary'
    Plug 'octol/vim-cpp-enhanced-highlight'
call plug#end()

let g:hybrid_custom_term_colors = 1
let g:hybrid_reduced_contrast = 1
colorscheme hybrid

let g:lightline = {'colorscheme': 'onedark'}
let g:lightline.component_expand = {
  \   'linter_checking': 'lightline#ale#checking',
  \   'linter_warnings': 'lightline#ale#warnings',
  \   'linter_errors': 'lightline#ale#errors',
  \   'linter_ok': 'lightline#ale#ok',
  \ }
let g:lightline.component_type = {
  \   'linter_checking': 'left',
  \   'linter_warnings': 'warning',
  \   'linter_errors': 'error',
  \   'linter_ok': 'left',
  \ }
let g:lightline.active = {
  \   'left': [
  \     ['mode', 'paste'],
  \     ['readonly', 'filename', 'modified'],
  \     ['linter_checking', 'linter_errors', 'linter_warnings', 'linter_ok'],
  \   ]
  \ }

nmap <C-e> :NERDTreeToggle<CR>
nmap <F8> :TagbarToggle<CR>

syntax enable
syntax on
set completeopt=menuone

let g:ale_cpp_cc_options = '-std=c++17 -Wall -I.'
let g:ale_sign_column_always = 1
let g:ale_fix_on_save = 1
let g:ale_completion_enabled = 1
let g:ale_sign_error = '>>'
let g:ale_sign_warning = '⚠'
let g:ale_echo_msg_format = '[%linter%] %s [%severity%]'
let g:ale_statusline_format = ['>> %d', '⚠ %d', '⬥ ok']
let g:ale_cpp_clangcheck_options = '-std=c++17 -I.'
let g:ale_cpp_clangd_options = '-std=c++17 -I.'
let g:ale_cpp_ccls_executable = ''

let g:UltiSnipsSnippetsDir = '~/.vim/snippets'
set runtimepath+=~/.vim/snippets
let g:UltiSnipsExpandTrigger='<C-k>'

nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)
nnoremap <silent> K :call <SID>show_documentation()<CR>

function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

let g:neoterm_default_mod='belowright'
let g:neoterm_size=10
let g:neoterm_autoscroll=1
tnoremap <silent> <C-w> <C-\><C-n><C-w>

let g:cpp_class_scope_highlight = 1
let g:cpp_concepts_highlight = 1
let g:cpp_class_decl_highlight = 1
let g:cpp_member_variable_highlight = 1

nnoremap <ESC><ESC> :noh<CR>
