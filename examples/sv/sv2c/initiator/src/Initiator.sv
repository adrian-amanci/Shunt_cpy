/*
============================================================================
 File        : Initiator.sv
 Version     : 1.0.0
 Copyright (c) 2016-2017 IC Verimeter. All rights reserved.
               Licensed under the MIT License.
               See LICENSE file in the project root for full license information.
 Description : TCP/IP SystemVerilog SHUNT
               All Types SystemVerilog examle  -Initiator(server)  
 ============================================================================
*/

`include "../../includes/cs_common.svh"

module automatic Initiator;
   
   import shunt_dpi_pkg::*;
   
   int Socket;
   cs_header_t      h_trnx_exp;
   cs_data_header_t h_data_exp;
   cs_header_t      h_trnx_act;
   cs_data_header_t h_data_act;
   
   
   
   initial
     begin
	int Pass;
	string Status;
	string Test_name;
	
	Pass   = 1;
	Socket = 0;
	
	$display("Initiator: START");
	
	Test_name = "\tinit_initiator";
	Socket = init_initiator(`MY_PORT);
	if (!Socket) Pass=0;
	$display("\tInitiator: socket=%0d",Socket);
	print_status(Test_name,Pass);
	
	Test_name = "\tshort loopback";
	Pass=short_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tint loopback";
	Pass=int_loopback_test(Socket);
	print_status(Test_name,Pass);
	
	Test_name = "\tlong loopback";
	Pass=long_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tbyte loopback";
	Pass=byte_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tinteger loopback";
	Pass=integer_loopback_test(Socket);
	print_status(Test_name,Pass);
 
	Test_name = "\ttime loopback";
	Pass=time_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tbit_loopback";
	Pass=bit_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\treg_loopback";
	Pass=reg_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tlogic_loopback";
	Pass=logic_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tbitN_loopback";
	Pass=bitN_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tregN_loopback";
	Pass=regN_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tlogicN_loopback";
	Pass=logicN_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\treal_loopback";
	Pass=real_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tshortreal_loopback";
	Pass=shortreal_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tstring_loopback";
	Pass=string_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tshortV loopback";
	Pass=shortV_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tlongV loopback";
	Pass=longV_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\trealV loopback";
	Pass=realV_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tshortrealV loopback";
	Pass=shortrealV_loopback_test(Socket);
	print_status(Test_name,Pass);

	Test_name = "\tintegerV loopback";
	Pass=integerV_loopback_test(Socket);
	print_status(Test_name,Pass);
	
	Test_name = "Initiator";
	print_status(Test_name,Pass);
     end

   //Functions:
   
   function int init_initiator(int portno);
      begin
	 int socket_id;
	 socket_id=0;
	 socket_id = shunt_dpi_initiator_init(portno);
	 return socket_id;
      end
   endfunction : init_initiator
   
   
   function int short_loopback_test(int socket_id);
      begin
	 int success;
         shortint Short_exp;
	 shortint Short_act;
         string Test_name = "initiator short_loopback_test";
	 
	 success = 1;
	 Short_exp = $urandom();
	 
	 //send
	 if (shunt_dpi_send_short (socket_id,Short_exp)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 //recv
	 if (shunt_dpi_recv_short(socket_id,Short_act)<= 0) success = 0;
	 if (success == 0 )  $display("\nShort loopback fail recv");
	 
	 if (Short_exp !== Short_act)success=0;
	 return  success;
      end
   endfunction : short_loopback_test

   function int int_loopback_test(int socket_id);
      begin
	 int success;
         int Int_exp;
	 int Int_act;
         string Test_name = "initiator int_loopback_test";
	 
	 success = 1;
	 Int_exp = $urandom();
	 
	 //send
	 if (shunt_dpi_send_int (socket_id,Int_exp)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 //recv
	 if (shunt_dpi_recv_int(socket_id,Int_act)<= 0) success = 0;
	 if (success == 0 )  $display("\nInt loopback fail recv");
	 
	 if (Int_exp !== Int_act)success=0;
	 return  success;
      end
   endfunction : int_loopback_test

   function int long_loopback_test(int socket_id);
      begin
	 int success;
         longint Long_exp;
	 longint Long_act;
         string Test_name = "initiator long_loopback_test";
	 
	 success = 1;
	 Long_exp = {$urandom(),$urandom()};
	 
	 //send
	 if (shunt_dpi_send_long (socket_id,Long_exp)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 //recv
	 if (shunt_dpi_recv_long(socket_id,Long_act)<= 0) success = 0;
	 if (success == 0 )  $display("\nLong loopback fail recv");
	 
	 if (Long_exp !== Long_act)success=0;
	 return  success;
      end
   endfunction : long_loopback_test

   function int byte_loopback_test(int socket_id);
      begin
	 int success;
         byte Byte_exp;
	 byte Byte_act;
         string Test_name = "initiator byte_loopback_test";
	 
	 success = 1;
	 Byte_exp = $urandom();
	 
	 //send
	 if (shunt_dpi_send_byte (socket_id,Byte_exp)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 //recv
	 if (shunt_dpi_recv_byte(socket_id,Byte_act)<= 0) success = 0;
	 if (success == 0 )  $display("\nByte loopback fail recv");
	 
	 if (Byte_exp !== Byte_act)success=0;
	 return  success;
      end
   endfunction : byte_loopback_test
   
   function int   integer_loopback_test(int socket_id);
      
      int 	success;
      integer   Integer_exp;
      integer   Integer_act;
      
      string 	Test_name = "initiator integer_loopback_test";
      success =1;
      
      //set up data
      Integer_exp = 32'hf0xx_zz5a;
      
      //send data
      if (shunt_dpi_send_integer(socket_id,Integer_exp)<=0) success = 0;
      if (shunt_dpi_recv_integer(socket_id,Integer_act)<=0) success = 0;
      
      //comp
      if(Integer_act !== Integer_exp) success = 0;  
      if (success == 0 )  $display("\ninitiator: fail comp data");
      
      return  success;
   endfunction :integer_loopback_test

   function int   time_loopback_test(int socket_id);
      
      int 	success;
      time   Time_exp;
      time   Time_act;
      
      string 	Test_name = "initiator time_loopback_test";
      success =1;
      
      //set up data
      Time_exp =  64'hf0xx_zz5a_dezz_67xx;
      Time_act = 0;
      
      
      //send data
      if (shunt_dpi_send_time(socket_id,Time_exp)<=0) success = 0;
      if (shunt_dpi_recv_time(socket_id,Time_act)<=0) success = 0;
      
      //comp
      if(Time_act !== Time_exp) success = 0;  
      if (success == 0 )  $display("\ninitiator: fail comp data");
      
   
      return  success;
   endfunction :time_loopback_test

   function int   bit_loopback_test(int socket_id);
      
      int 	success;
      bit   Bit_exp;
      bit   Bit_act;
      
      string 	Test_name = "initiator bit_loopback_test";
      success =1;
      
      //set up data
      Bit_exp = 0;//$random;
      Bit_act = 1;
      
      
      //send data
      if (shunt_dpi_send_bit(socket_id,Bit_exp)<=0) success = 0;
      if (shunt_dpi_recv_bit(socket_id,Bit_act)<=0) success = 0;
      
      //comp
      if(Bit_act !== Bit_exp) success = 0;  
      if (success == 0 )  $display("\ninitiator: fail comp data");
         
      return  success;
   endfunction :bit_loopback_test
   
   function int   reg_loopback_test(int socket_id);
      
      int 	success;
      reg   Reg_exp;
      reg   Reg_act;
      
      string 	Test_name = "initiator reg_loopback_test";
      success =1;
      
      //set up data
      Reg_exp = 1'bz;
      Reg_act = 0;
      
      
      //send data
      if (shunt_dpi_send_reg(socket_id,Reg_exp)<=0) success = 0;
      if (shunt_dpi_recv_reg(socket_id,Reg_act)<=0) success = 0;
      
      //comp
      if(Reg_act !== Reg_exp) success = 0;  
      if (success == 0 )  $display("\ninitiator: fail comp data");
         
      return  success;
   endfunction :reg_loopback_test

   function int   logic_loopback_test(int socket_id);
      
      int 	success;
      logic   Logic_exp;
      logic   Logic_act;
      
      string 	Test_name = "initiator logic_loopback_test";
      success =1;
      
      //set up data
      Logic_exp = 1'bx;
      Logic_act = 0;
      
      
      //send data
      if (shunt_dpi_send_logic(socket_id,Logic_exp)<=0) success = 0;
      if (shunt_dpi_recv_logic(socket_id,Logic_act)<=0) success = 0;
      
      //comp
      if(Logic_act !== Logic_exp) success = 0;  
      if (success == 0 )  $display("\ninitiator: fail comp data");
         
      return  success;
   endfunction :logic_loopback_test

   function int bitN_loopback_test(int socket_id,int n_payloads=1);
      begin
	 localparam N = 133;//N 4*32 bit max
	 
	 int success;
	 int i;
	 bit [N-1:0] BitN_exp;
	 bit [N-1:0] BitN_act;
	 string    s_me = "bitN_loopback_test";
	 success =1;
	 
	 //data set
	 BitN_exp =  {$urandom(),$urandom(),$urandom(),$urandom()};
	 
	 
	 //set up header
	 h_trnx_exp.trnx_type = $urandom;
	 h_trnx_exp.trnx_id   = $urandom;
	 h_trnx_exp.data_type = shunt_dpi_hash("SHUNT_BIT");
	 h_trnx_exp.n_payloads = N;
	 
	 //send
	 if (shunt_dpi_send_header(socket_id,h_trnx_exp)<= 0) success = 0;
	 if(!shunt_dpi_hs_send_bitN(socket_id,h_trnx_exp,BitN_exp))  success =0;
	 
	 //recv
	 if (shunt_dpi_recv_header(socket_id,h_trnx_act)<= 0) success = 0;
	 if(!shunt_dpi_hs_recv_bitN(socket_id,h_trnx_act,BitN_act))  success =0;
	 //
	 if(BitN_act !== BitN_exp) success =0;
	 
	 return  success;
      end
   endfunction : bitN_loopback_test


   function int regN_loopback_test(int socket_id,int n_payloads=1);
      begin
	 localparam N = 133;//N 4*32 bit max
	 
	 int success;
	 int i;
	 reg [N-1:0] XRegNV_exp;
         reg [N-1:0] RegNV_exp;
	 reg [N-1:0] RegNV_act;
	 string    s_me = "regN_loopback_test";
	 success =1;
	 
	 //data set
	 XRegNV_exp = 'hx;
	 RegNV_exp =  {$urandom(),$urandom(),$urandom(),$urandom()}& XRegNV_exp;
	 RegNV_exp =   RegNV_exp | {$urandom(),$urandom(),$urandom(),$urandom()};
	 
	 //set up header
	 h_trnx_exp.trnx_type = $urandom;
	 h_trnx_exp.trnx_id   = $urandom;
	 h_trnx_exp.data_type = shunt_dpi_hash("SHUNT_REG4S");
	 h_trnx_exp.n_payloads = N;
	 
	 //send
	 if (shunt_dpi_send_header(socket_id,h_trnx_exp)<= 0) success = 0;
	 if(!shunt_dpi_hs_send_regN(socket_id,h_trnx_exp,RegNV_exp))  success =0;
	 
	 //recv
	 if (shunt_dpi_recv_header(socket_id,h_trnx_act)<= 0) success = 0;
	 if(!shunt_dpi_hs_recv_regN(socket_id,h_trnx_act,RegNV_act))  success =0;
	 //
	 if(RegNV_act !== RegNV_exp) success =0;
	 
	 return  success;
      end
   endfunction : regN_loopback_test
   
   function int logicN_loopback_test(int socket_id,int n_payloads=1);
      begin
	 localparam N = 133;//N 4*32 bit max
	 
	 int success;
	 int i;
	 logic [N-1:0] XLogicN_exp;
         logic [N-1:0] LogicN_exp;
	 logic [N-1:0] LogicN_act;
	 string    s_me = "logicN_loopback_test";
	 success =1;
	 
	 //data set
	 XLogicN_exp = 'hx;
	 LogicN_exp =  {$urandom(),$urandom(),$urandom(),$urandom()}& XLogicN_exp;
	 LogicN_exp =   LogicN_exp | {$urandom(),$urandom(),$urandom(),$urandom()};
	 
	 //set up header
	 h_trnx_exp.trnx_type = $urandom;
	 h_trnx_exp.trnx_id   = $urandom;
	 h_trnx_exp.data_type = shunt_dpi_hash("SHUNT_REG4S");
	 h_trnx_exp.n_payloads = N;
	 
	 //send
	 if (shunt_dpi_send_header(socket_id,h_trnx_exp)<= 0) success = 0;
	 if(!shunt_dpi_hs_send_logicN(socket_id,h_trnx_exp,LogicN_exp))  success =0;
	 
	 //recv
	 if (shunt_dpi_recv_header(socket_id,h_trnx_act)<= 0) success = 0;
	 if(!shunt_dpi_hs_recv_logicN(socket_id,h_trnx_act,LogicN_act))  success =0;
	 //
	 if(LogicN_act !== LogicN_exp) success =0;
	 
	 return  success;
      end
   endfunction : logicN_loopback_test

   function int real_loopback_test(int socket_id);
      begin
	 int success;
         real Real_exp;
	 real Real_act;
	 string s_me = "real_loopback_test";
	 success =1;
	 Real_exp = $urandom()/7.5;
	 if(!shunt_dpi_send_real(socket_id,Real_exp)) success=0;
	 if(!shunt_dpi_recv_real(socket_id,Real_act)) success=0;
	 if (Real_exp != Real_act)success=0;
	 
	 return  success;
      end
   endfunction : real_loopback_test
 

   
   function int shortreal_loopback_test(int socket_id);
      begin
	 int success;
         shortreal Shortreal_exp;
	 shortreal Shortreal_act;
	 string s_me = "shortreal_loopback_test";
	 success =1;
	 
	 Shortreal_exp = 123;
	 
	 if(!shunt_dpi_send_shortreal(socket_id,Shortreal_exp)) success=0;
	 if(!shunt_dpi_recv_shortreal(socket_id,Shortreal_act)) success=0;
	 if (Shortreal_exp != Shortreal_act) success=0;
	 
	 return  success;
      end
   endfunction : shortreal_loopback_test

     function int string_loopback_test(int socket_id);
      begin
	 int success;
	 int i;
         string String_exp;
	 string String_act;
	 string s_me = "string_loopback_test";
	 String_exp = `STRING_MESSAGE;
	 String_act = `STRING_MESSAGE1;
	 success =1;
	 if(!shunt_dpi_send_string(socket_id,String_exp.len(),String_exp))  success =0;
	 if(!shunt_dpi_recv_string(socket_id,String_exp.len(),String_act))  success =0;
	 if(String_act != String_exp) success =0;
	 
	 return  success;
      end
     endfunction : string_loopback_test
   
   function int shortV_loopback_test(int socket_id);
      begin
	 int success;
	 int i;
         shortint ShortV_exp[`V_SIZE];
	 shortint ShortV_act[`V_SIZE];
	 string   s_me = "shortV_loopback_test";
	 success =1;
	 
	 foreach(ShortV_exp[i]) ShortV_exp[i] = 100+(i+1);
	 foreach(ShortV_act[i]) ShortV_act[i] = 300+(i+1);
	 if(!shunt_dpi_send_shortV(socket_id,`V_SIZE,ShortV_exp)) success =0;
	 if(!shunt_dpi_recv_shortV(socket_id,`V_SIZE,ShortV_act)) success =0;
	 foreach(ShortV_exp[i]) if(ShortV_act[i] != ShortV_exp[i]) success =0;
	 return  success;
      end
   endfunction : shortV_loopback_test
    
   function int longV_loopback_test(int socket_id);
      begin
	 int success;
	 int i;
         longint LongV_exp[`V_SIZE];
	 longint LongV_act[`V_SIZE];
	 string   s_me = "longV_loopback_test";
	 success =1;
	 
	 foreach(LongV_exp[i]) LongV_exp[i] = 100+(i+1);
	 foreach(LongV_act[i]) LongV_act[i] = 300+(i+1);
	 if(!shunt_dpi_send_longV(socket_id,`V_SIZE,LongV_exp)) success =0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 if(!shunt_dpi_recv_longV(socket_id,`V_SIZE,LongV_act)) success =0;
	 if (success == 0 )  $display("\ninitiator: fail recv data");
	 foreach(LongV_exp[i]) if(LongV_act[i] != LongV_exp[i]) success =0;
	 
	 return  success;
      end
   endfunction : longV_loopback_test

   function int realV_loopback_test(int socket_id,int n_payloads=1);
      begin
	 int success;
	 int i;
         real RealV_exp[`V_SIZE];
	 real RealV_act[`V_SIZE];
         string Test_name = "initiator realV_loopback_test";
	 success =1;
	 
	 for(int i=0;i<`V_SIZE;i++) RealV_exp[i] = 300.123+i;
	 
	 
	 if (shunt_dpi_send_realV  (socket_id,`V_SIZE,RealV_exp)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 if (shunt_dpi_recv_realV(socket_id,`V_SIZE,RealV_act)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail recv data");
	 
	 foreach (RealV_exp[i])if (RealV_exp[i] != RealV_act[i])success=0;
         return  success;	 
      end
   endfunction : realV_loopback_test
  
   function int shortrealV_loopback_test(int socket_id,int n_payloads=1);
      begin
	 int success;
	 int i;
         shortreal ShortrealV_exp[`V_SIZE];
	 shortreal ShortrealV_act[`V_SIZE];
         string Test_name = "initiator shortrealV_loopback_test";
	 success =1;
	 
	 for(int i=0;i<`V_SIZE;i++) ShortrealV_exp[i] = 540.123+i;
	 	 
	 if (shunt_dpi_send_shortrealV  (socket_id,`V_SIZE,ShortrealV_exp)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 if (shunt_dpi_recv_shortrealV(socket_id,`V_SIZE,ShortrealV_act)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail recv data");
	 foreach (ShortrealV_exp[i])  begin 
	    real zero_ = 0;
	    zero_ = ShortrealV_exp[i] - ShortrealV_act[i];
	    if (zero_ < 0)  zero_ = ShortrealV_act[i] - ShortrealV_exp[i];
	    if (zero_ > 0.0001) success=0;
	 end
	 if (success == 0 )  $display("\ninitiator: fail comp data");
         return  success;	 
      end
   endfunction : shortrealV_loopback_test
  
   function int integerV_loopback_test(int socket_id,int n_payloads=1);
      begin
	 int success;
	 int i;
         integer IntegerV_exp[`V_SIZE];
	 integer IntegerV_act[`V_SIZE];
         string Test_name = "initiator integerV_loopback_test";
	 success =1;
	 
	 for(int i=0;i<`V_SIZE;i++) IntegerV_exp[i] = 540+i;
	 
	 if (shunt_dpi_send_integerV  (socket_id,`V_SIZE,IntegerV_exp)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail send data");
	 if (shunt_dpi_recv_integerV(socket_id,`V_SIZE,IntegerV_act)<= 0) success = 0;
	 if (success == 0 )  $display("\ninitiator: fail recv data");
	 
	 foreach (IntegerV_exp[i]) if(IntegerV_act[i] !== IntegerV_exp[i])  success = 0;
	 if (success == 0 )  $display("\ninitiator: fail comp data");
         return  success;	 
      end
   endfunction : integerV_loopback_test
   
   
   function void print_status(string Test_name,int Status_int);
      begin
	 string Status;
	 if (!Status_int) Status = "FAIL";
	 else  Status = "PASS";
	 $display("%s TEST %s",Test_name,Status);
      end
   endfunction : print_status  
   
endmodule : Initiator

