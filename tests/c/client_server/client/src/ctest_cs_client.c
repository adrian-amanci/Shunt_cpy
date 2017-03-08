
/* 
============================================================================
 File        : ctest_cs_client.c
 Author      : Victor Besyakov
 Version     : 0.0.0
 Copyright (c) 2016 IC Verimeter. All rights reserved.  
               Licensed under the MIT License. 
               See LICENSE file in the project root for full license information.  
	       Description : ctest server                  
	       System Verilog client server handshake (SVCS)
*/

#include "svcs_client_server.h"
#include "../../includes/cs_common.h"

int main(void) {
  puts("\nctest_cs_client start");
  int socket;
  char *hostname;
  int port;
  int success=1;
  
  //
  //SVCV_INSTR_HASH_INDEX_DEFINE;
  port = MY_PORT;
  hostname =   MY_HOST;
  //
  socket= svcs_prim_init_tcpclient(port,hostname);
  
  if (socket<0) {
    printf("\nctest_cs_client::FATAL ERROR");
    success=0;
  }
  //printf("\nctest_cs_client::socket=%d", socket);
  
  if (success>0) {
    //puts("\nctest_cs_client start: Echo loopback client test start");
    
    // Headers  Tests
    
    // trnx_header test
    cs_header h_trnx;
    //char* msg = "client: recv trnx_header";
    //recv
    if (svcs_cs_recv_header(socket,&h_trnx)<= 0) success = 0;
    if (success == 0 )  printf("\n client trnx_header fail to recv");
    //send loopback
    if (svcs_cs_send_header(socket,&h_trnx)<= 0) success = 0;
    if (success == 0 )  printf("\n client trnx_header fail to send");

    // data_header test
    cs_data_header h_data;
    //char* msg = "client: recv data_header";
    //recv+
    h_data.trnx_payload_sizes = malloc(h_trnx.n_payloads*sizeof(int));
    if (svcs_cs_recv_data_header(socket,h_trnx.n_payloads,&h_data)<= 0) success = 0;
    if (success == 0 )  printf("\n client data_header fail to recv");
    //send loopback
    if (svcs_cs_send_data_header(socket,h_trnx.n_payloads,&h_data)<= 0) success = 0;
    if (success == 0 )  printf("\n client data_header fail to send");

    //     INTV Test
    //Int Array
    //char* msg = "client: recv int_header";
    //cs_data_header h_int;
    //recv
    /*
    int* IntA;

    if (svcs_cs_recv_data_header(socket,&h_int)<= 0) success = 0;
    if (success == 0 )  printf("\n client data_header fail to recv");
    if (svcs_cs_recv_int(socket,&h_int,&IntA)<=0) success = 0;
    if (success == 0 )  printf("\n client Int data fail to recv");
    //send
    if (svcs_cs_send_data_header(socket,&h_int)<= 0)  printf("\nclient cs_header fail send");
    if (success == 0 )  printf("\nclient cs_header fail send");
    if (svcs_cs_send_int(socket,&h_int,IntA)<=0) success = 0;
    if (success == 0 )  printf("\n client Int data fail send");
    //
    if (svcs_cs_recv_data_header_clean(&h_int)<=0) success = 0;
    //if (svcs_cs_recv_int_clean(&IntA)<=0) success = 0;

    //Int Vector
    int* IntV;
    //recv
    if (svcs_cs_recv_data_header(socket,&h_int)<= 0) success = 0;
    if (success == 0 )  printf("\n client data_header fail to recv");
    if (svcs_cs_recv_int(socket,&h_int,&IntV)<=0) success = 0;
    if (success == 0 )  printf("\n client Int data fail to recv");

    //send
    if (svcs_cs_send_data_header(socket,&h_int)<= 0)  printf("\nclient cs_header fail send");
    if (success == 0 )  printf("\nclient cs_header fail send");
    if (svcs_cs_send_int(socket,&h_int,(int *)IntV)<=0) success = 0;
    if (success == 0 )  printf("\n client Int data fail send");
    //
    if (svcs_cs_recv_data_header_clean(&h_int)<=0) success = 0;
    if (svcs_cs_recv_int_clean(&IntV)<=0) success = 0;

    //Int value

    int *IntI;
    //recv
    if (svcs_cs_recv_data_header(socket,&h_int)<= 0) success = 0;
    if (success == 0 )  printf("\n client data_header fail to recv");
    if (svcs_cs_recv_int(socket,&h_int,&IntI)<=0) success = 0;
    if (success == 0 )  printf("\n client Int data fail to recv");

    //send
    if (svcs_cs_send_data_header(socket,&h_int)<= 0)  printf("\nclient cs_header fail send");
    if (success == 0 )  printf("\nclient cs_header fail send");
    if (svcs_cs_send_int(socket,&h_int,IntI)<=0) success = 0;
    if (success == 0 )  printf("\n client Int data fail send");
    //
    if (svcs_cs_recv_data_header_clean(&h_int)<=0) success = 0;
    if (svcs_cs_recv_int_clean(&IntI)<=0) success = 0;
    */
   /*
    int indx=0;
    for(int i=0;i<h_int.n_payloads;i++) {
     //Result_ = send(h->sockid,&Int,h->trnx_payload_sizes[i]*sizeof(int), 0);
     for (int j=0;j< h_int.trnx_payload_sizes[i];j++) {
     printf("\n client recv intA (%0d) IntA[%0d][%0d]=%d",indx,i,j,IntA[indx]);
     indx++;
       	    }
   	    }
   	    */
    
/*     if (success == 0 )  printf("\nString client fail send"); */
/*     //////////////////////////////////// */
    //puts("\nctest_cs_client end");
  }

  if ( success >0)
    return EXIT_SUCCESS;
  else 
    return EXIT_FAILURE;
}
