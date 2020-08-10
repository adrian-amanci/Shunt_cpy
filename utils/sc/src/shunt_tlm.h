/* 
   ============================================================================
   File        : shunt_tlm.h
   Version     : 1.0.0
   Copyright (c) 2016-2020 IC Verimeter. All rights reserved.  
   Licensed under the MIT License. 
   See LICENSE file in the project root for full license information.  
   Description : shunt_tlm utils
   TCP/IP target/initiator SystemC TLM interface utils
   ============================================================================
*/

#ifndef SHUNT_TLM_H
#define SHUNT_TLM_H

#include <systemc>
#include "shunt_tlm.h"
#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"

//Title: Shunt-TLM SystemC API (namespace shunt_tlm)

namespace shunt_tlm 
{
  
  extern "C" {
#include "shunt_user_api.h"
#include "shunt_user_api.c"
#include "shunt_client_server.h"
#include "shunt_client_server.c"
#include "shunt_primitives.h"
#include "shunt_primitives.c"
  }
  
  using namespace sc_core;
  using namespace sc_dt;
  using namespace std;
  using namespace tlm;
  
  /*  
      TLM Enumerations:
      enum  tlm_sync_enum { TLM_ACCEPTED, TLM_UPDATED, TLM_COMPLETED }
      
      enum  tlm_command { TLM_READ_COMMAND, TLM_WRITE_COMMAND, TLM_IGNORE_COMMAND }
      
      enum  tlm_response_status {
      TLM_OK_RESPONSE = 1, TLM_INCOMPLETE_RESPONSE = 0, TLM_GENERIC_ERROR_RESPONSE = -1, TLM_ADDRESS_ERROR_RESPONSE = -2,
      TLM_COMMAND_ERROR_RESPONSE = -3, TLM_BURST_ERROR_RESPONSE = -4, TLM_BYTE_ENABLE_ERROR_RESPONSE = -5
      }
      
      enum  tlm_gp_option { TLM_MIN_PAYLOAD, TLM_FULL_PAYLOAD, TLM_FULL_PAYLOAD_ACCEPTED }
      
      enum  tlm_endianness { TLM_UNKNOWN_ENDIAN, TLM_LITTLE_ENDIAN, TLM_BIG_ENDIAN }
    
      enum  tlm_phase_enum {
      UNINITIALIZED_PHASE =0, BEGIN_REQ =1, END_REQ, BEGIN_RESP,END_RESP
      }
  */
  
  /* Enum: shunt_tlm_command
     
  SHUNT_TLM_END_SIM - end of Client simulation, send by Server
  --- Code
  enum shunt_tlm_command {
  SHUNT_TLM_END_SIM =tlm_command::TLM_IGNORE_COMMAND+1
  };
  ---
  */ 
  enum shunt_tlm_command {
    SHUNT_TLM_END_SIM =tlm_command::TLM_IGNORE_COMMAND+1
  };
    //Section: Auxiliary
    /*
      Function: shunt_print_csgp
      print Client-Server Generic Payload (csgp header) structure 
      
      Parameters:
      
      csgp   - Ref. to <cs_tlm_generic_payload_header>
      
      prefix - Message prefix
      
    */
    void shunt_print_csgp (const cs_tlm_generic_payload_header csgp,string prefix="") {
      const char *print_string;
      
      switch (csgp.option) {
      case tlm::TLM_MIN_PAYLOAD: print_string="TLM_MIN_PAYLOAD"; break;
      case tlm::TLM_FULL_PAYLOAD: print_string="TLM_FULL_PAYLOAD"; break;
      case tlm::TLM_FULL_PAYLOAD_ACCEPTED : print_string="TLM_FULL_PAYLOAD_ACCEPTED"; break;
      default : print_string="TLM_UNKNOWN_OPTION"; break;
      }
      cout<< prefix <<" csgp .option("<<print_string<<")";
      
      switch ( csgp.command) {
      case tlm::TLM_WRITE_COMMAND  : print_string="TLM_WRITE_COMMAND"; break;
      case tlm::TLM_READ_COMMAND   : print_string="TLM_READ_COMMAND"; break;
      case tlm::TLM_IGNORE_COMMAND : print_string="TLM_IGNORE_COMMAND"; break;
      case SHUNT_TLM_END_SIM       : print_string="SHUNT_TLM_END_SIM"; break;
      default                 : print_string="TLM_UNKNOWN_COMMAND"; break;
      }
      cout<<" command("<< print_string<<")"
	  <<" addr("<< hex <<(unsigned)csgp.address<<")"
	  <<" length("<< hex <<(unsigned)csgp.length<<")"
	  <<" streaming_width("<< hex <<(unsigned)csgp.streaming_width<<")"
	  <<" byte_enable_length("<< hex <<(unsigned)csgp.byte_enable_length<<")";
      switch ( csgp.response_status) {
      case tlm::TLM_OK_RESPONSE            : print_string="TLM_OK_RESPONSE"; break;
      case tlm::TLM_INCOMPLETE_RESPONSE    : print_string="TLM_INCOMPLETE_RESPONSE"; break;
      case tlm::TLM_GENERIC_ERROR_RESPONSE : print_string="TLM_GENERIC_ERROR_RESPONSE"; break;
      case tlm::TLM_ADDRESS_ERROR_RESPONSE : print_string="TLM_ADDRESS_ERROR_RESPONSE"; break;
      case tlm::TLM_COMMAND_ERROR_RESPONSE : print_string="TLM_COMMAND_ERROR_RESPONSE"; break;
      case tlm::TLM_BURST_ERROR_RESPONSE   : print_string="TLM_BURST_ERROR_RESPONSE"; break;
      case tlm::TLM_BYTE_ENABLE_ERROR_RESPONSE  : print_string="TLM_BYTE_ENABLE_ERROR_RESPONSE"; break;
      default                 : print_string="TLM_UNKNOWN_RESPONSE"; break;
      }
      cout<<" response_status("<< print_string<<")"
	  <<" Shunt tlm header extension["
        <<" delay("<< hex <<csgp.delay<<")";
      
      switch ( csgp.tlm_phase) {
      case tlm::UNINITIALIZED_PHASE: print_string="UNINITIALIZED_PHASE"; break;
      case tlm::BEGIN_REQ : print_string="BEGIN_REQ"; break;
      case tlm::END_REQ : print_string="END_REQ"; break;
      case tlm::BEGIN_RESP: print_string="BEGIN_RESP"; break;
      case tlm::END_RESP: print_string="END_RESP"; break;
      default : print_string="TLM_UNKNOWN_PHASE"; break;
      }
      cout <<" tlm_phase("<< hex <<print_string<<","<<hex<<csgp.tlm_phase<<")";
      
      switch ( csgp.tlm_sync) {
      case tlm::TLM_ACCEPTED: print_string="TLM_ACCEPTED"; break;
      case tlm::TLM_UPDATED: print_string="TLM_UPDATED"; break;
      case tlm::TLM_COMPLETED: print_string="TLM_COMPLETED"; break; 
      default : print_string="TLM_UNKNOWN_SYNC"; break;
      }
    cout<<" tlm_sync("<<hex <<print_string<<")"
        <<"]"<<endl;
    }
       
    /*
      Function: is_shunt_tlm_end_sim
      get simulation status
      
      Parameters:
      csgp   - Ref. to <cs_tlm_generic_payload_header> 
      
      Returns:
      simulation status - 1- end of sim. 
    */
    int is_shunt_tlm_end_sim( cs_tlm_generic_payload_header csgp) {
      int Result_ =0;
      if (csgp.command == SHUNT_TLM_END_SIM) Result_ = 1;
      return Result_;
    }
      
  /*
      Function: shunt_tlmgp2csgp
      map tlm Generic Payload (tlmgp) object to Client-Server Generic Payload (csgp header) structure.
      
      Parameters:
      
      csgp   - Ref. to <cs_tlm_generic_payload_header> (output)
      tlmgp  - tlm Generic Payload (tlmgp) 
      
    */
    void shunt_tlmgp2csgp (cs_tlm_generic_payload_header *csgp,const tlm::tlm_generic_payload& tlmgp) {
      csgp->option             = (long) tlmgp.get_gp_option();                          
      csgp->command            = (long) tlmgp.get_command();
      csgp->address            = (long) tlmgp.get_address();
      csgp->length             = (long) tlmgp.get_data_length();
      csgp->byte_enable_length = (long) tlmgp.get_byte_enable_length();
      csgp->streaming_width    = (long) tlmgp.get_streaming_width();
      csgp->dmi                = (long) tlmgp.is_dmi_allowed(); 
      csgp->response_status    = (long) tlmgp.get_response_status();
      //tlmgp.get_data_ptr();
      //tlmgp.get_byte_enable_ptr();
    }
/*
      Function: shunt_csgp2tlmgp
      map Client-Server Generic Payload (csgp header) structure to tlm Generic Payload (tlmgp) object
      
      Parameters:
      tlmgp  - tlm Generic Payload (tlmgp) (output)
      csgp   - Ref. to <cs_tlm_generic_payload_header> 
      
    */
    void shunt_csgp2tlmgp         (tlm::tlm_generic_payload& tlmgp, const cs_tlm_generic_payload_header *csgp) {
      tlmgp.set_gp_option          ((tlm::tlm_gp_option)csgp->option);
      tlmgp.set_command            ((tlm::tlm_command)csgp->command);
      tlmgp.set_address            ((sc_dt::uint64)csgp->address);
      tlmgp.set_data_length        ((unsigned int)csgp->length);
      tlmgp.set_byte_enable_length ((unsigned int)csgp->byte_enable_length);
      tlmgp.set_streaming_width    ((unsigned int)csgp->streaming_width);
      tlmgp.set_dmi_allowed        ((bool)csgp->dmi);
      tlmgp.set_response_status    ((tlm::tlm_response_status)csgp->response_status);
      //tlmgp.set_data_ptr(unsigned char* data)
      //tlmgp.set_byte_enable_ptr(unsigned char* byte_enable)
    }
/*
      Function: shunt_tlm_string2tlm_phase
      map tlm_phase object to tlm_phase_enum 
      
      Parameters:
      phase - tlm_phase object
      
      Returns:
      --- Code 
      enum  tlm_phase_enum {
      UNINITIALIZED_PHASE =0, BEGIN_REQ =1, END_REQ, BEGIN_RESP,END_RESP
      }
      ---
    */
    
    tlm_phase_enum shunt_tlm_string2tlm_phase(tlm_phase& phase)
    {
      string phase_name;
      tlm_phase_enum Result_ =  tlm::UNINITIALIZED_PHASE;
      phase_name= phase.get_name();
      if(phase_name.compare("UNINITIALIZED_PHASE")==0) Result_ = tlm::UNINITIALIZED_PHASE;
      if(phase_name.compare("BEGIN_REQ")==0)           Result_ = tlm::BEGIN_REQ;
      if(phase_name.compare("END_REQ")==0)             Result_ = tlm::END_REQ;
      if(phase_name.compare("BEGIN_RESP")==0)          Result_ = tlm::BEGIN_RESP;
    if(phase_name.compare("END_RESP")==0)            Result_ = tlm::END_RESP;
    return  Result_; 
    }
  //Section:  TCP/IP Server/Client init
  /*
    Function:  shunt_tlm_init_server
    TCP/IP Server initialization
    
    Parameters: 
    
    port - socket port
    
    Returns:  
    
    socket id 
    
    See Also:
    - <shunt_prim_init_initiator>
    
  */
  int  shunt_tlm_init_server(int port=0) {
    return shunt_prim_init_initiator(port);
  };
  
  /*
    Function:  shunt_tlm_init_client
    TCP/IP Client initialization
    
    Parameters:
  
    port   - socket port
    hostname - Server name
    
    Returns: 
    socket id 
    
    See Also:
    - <shunt_prim_init_target>
    
  */
  int   shunt_tlm_init_client(int port,char* host ) {
    return shunt_prim_init_target(port,host);
  };
  
  //Section:  Shunt-TLM API (generic TCP transfer primitives)
  
  /*
    Function:  shunt_tlm_send_transport
    send tlm generic payload  packet ( cs_tlm_generic_payload_header  + byte data vector + byte_enable vector ) 
    
    Parameters:
    socket - socket id 
    trans  - tlm_generic_payload object
    csgp   - <cs_tlm_generic_payload_header>
    delay  - sc_time pbject
   phase  - tlm_phase_enum 
   
   
   See Also:
   - <shunt_cs_tlm_send_gp>
   
  */  
  void  shunt_tlm_send_transport( int socket,tlm::tlm_generic_payload& trans, cs_tlm_generic_payload_header& csgp,sc_time& delay,tlm_phase_enum & phase)
  {
    unsigned char*   ptr = trans.get_data_ptr();
    unsigned char*   byt = trans.get_byte_enable_ptr();
    
    shunt_tlmgp2csgp(&csgp,trans);
    csgp.delay =delay.to_default_time_units();
    csgp.tlm_phase = (unsigned long)phase;
    //print_csgp_header(csgp," shunt_tlm_send_transport() ");
    shunt_cs_tlm_send_gp(socket,&csgp,ptr ,byt);
    };
  
  /*
    Function: shunt_tlm_recv_transport  
    receive tlm generic payload  packet ( cs_tlm_generic_payload_header  + byte data vector + byte_enable vector )
    
    Parameters:
    socket - socket id 
   trans      - tlm_generic_payload object (output)
   csgp       - <cs_tlm_generic_payload_header> (output)
   
  
   See Also:
   - <shunt_cs_tlm_recv_gp_header> and <shunt_cs_tlm_recv_gp_data>
   
  */  
  void shunt_tlm_recv_transport( int socket,tlm::tlm_generic_payload& trans, cs_tlm_generic_payload_header& csgp)
  {
    int size_data_payload = 0;
    int size_byte_enable_payload =0;
    
    unsigned long* data_tcp= NULL;
    unsigned long* byte_enable_tcp=NULL;
    
    unsigned char*   ptr = trans.get_data_ptr();
    unsigned char*   byt = trans.get_byte_enable_ptr();
      
    shunt_cs_tlm_recv_gp_header(socket,&csgp);
    //print_csgp_header(csgp,"shunt_tlm_recv_transport() ");
    shunt_csgp2tlmgp (trans,&csgp);
    
      //
    if (csgp.length>0) {
      size_data_payload = shunt_cs_tlm_data_payload_size(csgp.length);
      size_byte_enable_payload= shunt_cs_tlm_data_payload_size(csgp.byte_enable_length);
      data_tcp = new long unsigned[size_data_payload];
      size_byte_enable_payload = shunt_cs_tlm_data_payload_size(csgp.byte_enable_length);
      if ( size_byte_enable_payload>0) byte_enable_tcp = new long unsigned[size_byte_enable_payload];
      //
      // cout<<"shunt_tlm_recv_transport() (pre-shunt_tlm_recv_gp_data) DEBUG: size_data_payload="<<hex<<size_data_payload
      //    <<" size_byte_enable_payload="<<size_byte_enable_payload<<endl;
      
      shunt_cs_tlm_recv_gp_data(socket,&csgp,data_tcp,byte_enable_tcp);
      
      
      
      //unpack to byte arrays
      memcpy(ptr,data_tcp,trans.get_data_length());
      
      if (csgp.byte_enable_length>0) memcpy(&byt,&byte_enable_tcp,trans.get_byte_enable_length());

      //for(int i=0;i<size_data_payload;i++) {
      //  cout<<"shunt_tlm_recv_transport() (post-shunt_tlm_recv_gp_data) DEBUG: data_tcp"<<"["<<i<<"]"<<"="<<hex<<data_tcp[i]<<endl;
      //}
      //for(int i=0;i<size_byte_enable_payload;i++) {
      //  cout<<"shunt_tlm_recv_transport() (post-shunt_tlm_recv_gp_data)DEBUG: byte_enable_tcp"<<"["<<i<<"]"<<"="<<hex<<byte_enable_tcp[i]<<endl;
      //}
      
      delete [] data_tcp;
      delete [] byte_enable_tcp;
      }
  };
  
  /*
    Function: shunt_tlm_send_command
    send hunt_tlm_command
    
    Parameters:
    socket -  socket id 
    Com   - <shunt_tlm_command> 
      
  */
  void shunt_tlm_send_command(int socket,shunt_tlm_command Com) {
    cs_tlm_generic_payload_header csgp={0};
    csgp.command = Com;//SHUNT_TLM_END_SIM;
      shunt_cs_tlm_send_gp(socket,&csgp,0 ,0);
  };
  
  
  //Section:  Shunt-TLM API (TLM blocking transport)
   
  /*
    Function: shunt_send_b_transport
    TLM b_transport analogy  (source side).
    
    Parameters:
    socket - socket id 
    trans  - tlm_generic_payload object
    delay  - sc_time 
    
    See Also:
    - <shunt_tlm_send_transport>
    
  */  
  void shunt_send_b_transport( int socket,tlm::tlm_generic_payload& trans, sc_time& delay )
  {
    cs_tlm_generic_payload_header csgp={0};
    tlm_phase_enum phase =UNINITIALIZED_PHASE;
    
    csgp.delay =delay.to_default_time_units();
    shunt_tlm_send_transport(socket,trans,csgp,delay,phase);
  };
  
  /*
    Function: shunt_recv_b_transport
    TLM b_transport analogy  (receiver side)
    
    
    Parameters:
    socket - socket id 
    trans  - tlm_generic_payload object (output)
    delay  - sc_time (output)
    
    See Also:
    - <shunt_tlm_recv_transport>
  */  
    void shunt_recv_b_transport( int socket,tlm::tlm_generic_payload& trans, sc_time& delay,sc_time_unit sc_time_units=SC_NS)
    {
      cs_tlm_generic_payload_header csgp={0};
      
      while(shunt_prim_get_status_socket(socket,0) !=1 );
      shunt_tlm_recv_transport( socket,trans,csgp);
      //print_csgp_header(csgp);
      delay = sc_time(csgp.delay,sc_time_units);
    };
    
    
    //Section:  Shunt-TLM API (TLM non-blocking transport)
    
    /*
      Function: shunt_send_nb_transport
      TLM nb_transport_fw/nb_transport_bw analogy  (source side).

      Parameters:
      socket - socket id 
      trans  - tlm_generic_payload object 
      phase  - tlm_phase
      delay  - sc_time 
      
      See Also:
      - <shunt_tlm_send_transport>
      
    */  
    void shunt_send_nb_transport(int socket,tlm::tlm_generic_payload& trans, tlm_phase &phase,sc_time& delay ) 
    {
      tlm_phase_enum phase_enum;
      cs_tlm_generic_payload_header csgp={0};
      cs_tlm_generic_payload_header csgp_recv={0};
      tlm::tlm_generic_payload trans_recv;
      
      csgp.delay =delay.to_default_time_units();
      phase_enum = shunt_tlm_string2tlm_phase(phase);
      
      //while(shunt_prim_get_status_socket(socket,1) !=1 );
      shunt_tlm_send_transport(socket,trans,csgp,delay,phase_enum);
	//print_csgp_header(csgp,"shunt_send_nb_transport_fw send: ");
      
	//while(shunt_prim_get_status_socket(socket,0) !=1 );
        //shunt_tlm_recv_transport(socket,trans_recv,csgp_recv);
	//print_csgp_header(csgp_recv,"shunt_send_nb_transport_fw recv: ");
        //return (tlm_sync_enum)csgp_recv.tlm_sync;
    }
    
    /*
      Function: shunt_recv_nb_transport_tlm_sync_resp 
      complementary function for <shunt_send_nb_transport> (source side)
      
      Parameters:
      socket - socket id 
      
      Returns: tlm_sync_enum status.
      
      See Also:
      - <shunt_tlm_recv_transport>
    */  
    tlm_sync_enum shunt_recv_nb_transport_tlm_sync_resp(int socket) { 
      cs_tlm_generic_payload_header csgp={0};
      csgp.tlm_sync = -1;
            
      while(shunt_prim_get_status_socket(socket,0) !=1 );
      shunt_cs_tlm_recv_gp_header(socket,&csgp);
      //print_csgp_header(csgp,"shunt_recv_nb_transport_tlm_sync_resp:");
      return (tlm_sync_enum)csgp.tlm_sync;
    }; 
    

    /*
      Function: shunt_recv_nb_transport
      TLM nb_transport_fw/nb_transport_bw analogy (receiver side)
      
      Parameters:
      socket - socket id 
      trans  - tlm_generic_payload object  (output)
      phase  - tlm_phase (output)
      delay  - sc_time  (output)
      sc_time_units - sc_time_unit (input)
      
      See Also:
      - <shunt_tlm_recv_transport>
      
    */  
    
    void  shunt_recv_nb_transport(int socket,tlm::tlm_generic_payload& trans, tlm_phase &phase,sc_time& delay,sc_time_unit sc_time_units=SC_PS ) 
    {
      tlm_phase_enum phase_enum;
      cs_tlm_generic_payload_header csgp={0};
    
      while(shunt_prim_get_status_socket(socket,0) !=1 );
      shunt_tlm_recv_transport(socket,trans,csgp);
      delay = sc_time(csgp.delay,sc_time_units);
      //
      //print_csgp_header(csgp,"shunt_recv_nb_transport_fw:");
    }   
    
    /*
      Function:  shunt_send_nb_transport_tlm_sync_resp
      complementary function for  <shunt_recv_nb_transport> (receiver side)
      
      Parameters:
      socket - socket id 
      tlm_sync - tlm_sync_enum
      
      See Also:
      - <shunt_tlm_send_transport>
      
    */  
    void shunt_send_nb_transport_tlm_sync_resp(int socket,tlm_sync_enum tlm_sync) {
      cs_tlm_generic_payload_header csgp={0};
      csgp.tlm_sync = tlm_sync;
      
      while(shunt_prim_get_status_socket(socket,1) !=1 );
      shunt_cs_tlm_send_gp_header(socket,&csgp);
      //print_csgp_header(csgp,"shunt_send_nb_transport_tlm_sync_resp:");
  }; 
    

    
};

#endif // SHUNT_TLM_H

