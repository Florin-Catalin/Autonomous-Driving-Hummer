
const char MAIN_page[] PROGMEM = R"=====(
<HTML>
<TITLE>
 REMOTE CAR controlled
</TITLE>
<BODY>
<CENTER>
<FORM method="post" action="/form">
<TABLE>
<TR><TD colspan=2><B>Car controlled via node mcu webserver</B></TD></TR>

 
<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON1" name=submit>
<INPUT TYPE=SUBMIT VALUE="OFF1" name=submit>
</TD>
<TD>@@L1@@</TD></TR>
 
<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON2" name=submit>
<INPUT TYPE=SUBMIT VALUE="OFF2" name=submit>
</TD>
<TD>@@L2@@</TD></TR>
 
<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON3" name=submit>
<INPUT TYPE=SUBMIT VALUE="OFF3" name=submit>
</TD>
<TD>@@L3@@</TD></TR>
 
<TR><TD>
<INPUT TYPE=SUBMIT VALUE="ON4" name=submit>
<INPUT TYPE=SUBMIT VALUE="OFF4" name=submit>
</TD>
<TD>@@L4@@</TD></TR>
 
 

</TABLE>
</FORM>
 
</CENTER>
</BODY>
</HTML>
)=====";