NDSummary.OnToolTipsLoaded("File:shunt_primitives.h",{214:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype214\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">long</span> shunt_prim_hash(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">str</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">simple hash function</div></div>",215:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype215\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> shunt_prim_error(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">msg</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">perror wrapper</div></div>",32:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype32\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">unsigned int</span> shunt_prim_init_initiator(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const unsigned</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PName last\">portno</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">TCP/IP initiator initialization</div></div>",218:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype218\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">unsigned int</span> shunt_prim_tcp_parent_init_initiator(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const unsigned</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PName last\">portno</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Multi-Slave TCP IP initialisation, create TCP/IP a parent(listener) and start listening for client connections</div></div>",219:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype219\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">unsigned int</span> shunt_prim_tcp_child_init_initiator(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const unsigned</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PName last\">parentfd</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Multi-Slave TCP IP initialisation, establish TCP/IP&nbsp; initiator-target connection</div></div>",246:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype246\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">unsigned int</span> shunt_prim_init_target(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const unsigned</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">portno,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">hostname</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">TCP/IP target initialization</div></div>",247:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype247\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_get_socket_error(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PName last\">fd</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">An auxiliary function: to clear any errors, which can cause close(fd) to fail ref to https://&#8203;stackoverflow&#8203;.com&#8203;/questions&#8203;/12730477&#8203;/close-is-not-closing-socket-properl&#8203;y</div></div>",248:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype248\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> shunt_prim_close_socket(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PName last\">fd</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gracefully terminating TCP socket</div></div>",223:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype223\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_send_int (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Int</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">send verilog/C &quot;int&quot; data over TCP/IP</div></div>",224:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype224\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_recv_int (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Int</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">fetch verilog/C &quot;int&quot; data from TCP/IP socket</div></div>",225:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype225\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_send_double (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">double</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Double</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">send verilog &quot;double&quot; over TCP/IP</div></div>",226:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype226\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_recv_double (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">double</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Double</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">fetch verilog &quot;real&quot;/&quot;shortreal&quot;/&quot;realtime&quot;/C &quot;double&quot;/&quot;float&quot;,&quot;double&quot; from TCP/IP</div></div>",227:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype227\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_send_float (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">float</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Float</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">send verilog &quot;real&quot;/&quot;shortreal&quot;/&quot;realtime&quot;/C &quot;double&quot;/&quot;float&quot;,&quot;double&quot; over TCP/IP</div></div>",228:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype228\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_recv_float (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">float</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Float</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">fetch verilog &quot;real&quot;/&quot;shortreal&quot;/&quot;realtime&quot;/C &quot;double&quot;/&quot;float&quot;,&quot;double&quot; from TCP/IP</div></div>",229:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype229\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_send_short (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const short</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Short</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">send verilog &quot;shortint&quot;/C &quot;short int&quot; over TCP/IP</div></div>",230:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype230\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_recv_short (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">short</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Short</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">fetch verilog &quot;shortint&quot;/C &quot;short int&quot; over TCP/IP</div></div>",231:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype231\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_send_long (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const long</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Long</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">send verilog &quot;longint&quot;/C &quot;long int&quot; over TCP/IP</div></div>",232:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype232\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_recv_long (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">long</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Long</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">fetch verilog &quot;longint&quot;/C &quot;long int&quot; over TCP/IP</div></div>",233:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype233\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_send_byte (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Byte</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">send verilog/C &quot;Byte/Char&quot; data over TCP/IP</div></div>",234:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype234\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_recv_byte (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Byte</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">fetch verilog/C &quot;Byte/Char&quot; data from TCP/IP socket</div></div>",235:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype235\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_send_integer(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const unsigned</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">svLogicVecVal&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Int</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">send&nbsp; verilog &quot;reg[31:0] 4 state aval,bval&quot; over TCP/IP</div></div>",236:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype236\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> shunt_prim_recv_integer (</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const unsigned</span>&nbsp;</td><td class=\"PType\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">sockfd,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">svLogicVecVal&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Int</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">fetch verilog &quot;reg[31:0] 4 state aval,bval&quot; from TCP/IP</div></div>"});