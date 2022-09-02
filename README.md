# 42cursus_minishell
42cursus_minishell by jham and hyunhole


Grammar BNF Notation

표기: <Variable>, TERMINAL, Terminal, ε(입실론 - 공문자열, empty)
<start>
::= <complete_command>
<complete_command>
::= <list> <separator>
| <list>
<list>
::= <list> <separator_op> <and_or>
| <and_or>
<and_or>
::= <pipeline>
| <and_or> AND_IF <linebreak> <pipeline>
| <and_or> OR_IF <linebreak> <pipeline>
<pipeline>
::= <command>
| <pipeline>'|' <linebreak> <command>
<command> 
::= <simple_command> 
| <compound_list>  
| <compound_list>  <redirect_list>
<compound_list> 
::= <term> 
| <newline_list> <term> 
| <term> <separator> 
| <newline_list> <term> <separator>
<term> 
::= <term> <separator> <and_or> 
| <and_or>
<simple_command> 
::= <cmd_prefix> <cmd_word> <cmd_suffix> 
| <cmd_prefix> <cmd_word> 
| <cmd_prefix> 
| <cmd_name> <cmd_suffix> 
| <cmd_name>
<cmd_name> 
::= WORD
<cmd_word> 
::= WORD
<cmd_prefix> 
::= <io_redirect> 
| <cmd_prefix> <io_redirect> 
| ASSIGNMENT_WORD 
| <cmd_prefix> ASSIGNMENT_WORD
<cmd_suffix> 
::= <io_redirect> 
| <cmd_prefix> <io_redirect> 
| WORD 
| <cmd_suffix> WORD
<io_redirect>
::= <io_file> 
| <io_here>
<io_file> 
::= '<' <filename> 
| '>' <filename> 
| DGREAT <filename> 
| CLOBBER <filename>
<filename>
::= WORD
<io_here> 
::= DLESS <here_end>
<here_end> 
::= WORD
<separator> 
::= <separator_op> <linebreak> 
| <newline_list>
<separator_op>
::= '&' 
| ';'
<linebreak> 
::= <newline_list> 
| ε
<newline_list> 
::= <newline_list> NEWLINE 
| NEWLINE