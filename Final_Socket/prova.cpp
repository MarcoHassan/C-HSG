        while(iter)                                              
          {                                                      
            memset ( buffer, 0, 1024 );                          
            valread = read( sock , buffer, 1024);          
                                                                 
            int i = 0;                                           
                                                                 
            test = "";                                           
                                                                 
            do{                                                  
              test = test + buffer[i];                           
              i++;                                               
            }while(buffer[i] != 0);                              
                                                                 
            if(test != "send")                                   
                printf("%s\n",buffer);                           
                                                                 
                                                                 
            bye = test == "bye" ? true:false;                    
                                                                 
            if(test == "bye" || test == "send")                  
              iter = false;                                      
          }

        if(bye)                                                  
          break;  
