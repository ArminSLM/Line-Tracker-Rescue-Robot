/*///////////////////////////////IN THE NAME OF GOD/////////////////////////////////////////////
                                    _        _   __
                               |/  /_\ \  / | | |__  |_|
                               |\ /   \ \/  |_|  __| | |
                               
////////////////////////////////////////////////////////////////////////////////////////////
*/
#include <KavoshLineLibrary.h>
#include <VL51new.h>
 
//********************************set up**************************************************************************
void sensor_setup (void)
    {
    char page=1,last_page=8,safhe=1,last_safhe=13;
    lcd_clear();
    while (1)
        {
        if (next_page==0)
            {
            while (next_page==0);
            delay_ms(50);
            page++;
            if (page>last_page) page=1;
            lcd_clear();
            }
        if (previuse_page==0)
            {
            while (previuse_page==0);
            delay_ms(50);
            page--;
            if (page<1) page=last_page;
            lcd_clear();
            }
        if (decrease==0)
            go(-50,-50);
        else if (increase==0)
            go(50,50);                   
        else
            go(0,0);
        if (exit==0)
            {
            while(exit==0);
            delay_ms(100);
            lcd_clear();
            break;
            }
        if (page==1)           // SENSOR
            {
            sprintf(text,"  %d%d%d%d    %d   %d%d%d%d",SL4,SL3,SL2,SL1,SM,SR1,SR2,SR3,SR4);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            sprintf(text,"%d                  %d",SL5,SR5);
            lcd_gotoxy(0,1);
            lcd_puts(text);

            sprintf(text," %d                %d   ",SL6,SR6);
            lcd_gotoxy(0,2);
            lcd_puts(text);

            sprintf(text,"%d                  %d",SL7,SR7);
            lcd_gotoxy(0,3);
            lcd_puts(text);
            
            lcd_gotoxy(2,3);
            lcd_puts("Entr Dsble Snsrs");
            if(enter==0) //Disable Senors
             {
             lcd_gotoxy(2,3);
             lcd_puts("                ");
             while(1)
              { 
                sprintf(text,"  %d%d%d%d    %d   %d%d%d%d",SL4,SL3,SL2,SL1,SM,SR1,SR2,SR3,SR4);
                lcd_gotoxy(0,0);
                lcd_puts(text);

                sprintf(text,"%d",SL5);
                lcd_gotoxy(0,1);
                lcd_puts(text);
                
                sprintf(text,"%d",SR5);
                lcd_gotoxy(19,1);
                lcd_puts(text);
                
                sprintf(text,"%d",SL6);
                lcd_gotoxy(1,2);
                lcd_puts(text);
                
                sprintf(text,"%d",SR6);
                lcd_gotoxy(18,2);
                lcd_puts(text);

                sprintf(text,"%d",SL7);
                lcd_gotoxy(0,3);
                lcd_puts(text);
                
                sprintf(text,"%d",SR7);
                lcd_gotoxy(19,3);
                lcd_puts(text);
                  
                  sprintf(text,"M %d",disable_SM);
                  lcd_gotoxy(7,1);
                  lcd_puts(text);
                   
                  sprintf(text,"R %d%d%d%d%d%d",disable_SR1,disable_SR2,disable_SR3,disable_SR4,disable_SR5,disable_SR7);
                  lcd_gotoxy(7,3); 
                  lcd_puts(text);
              
                   sprintf(text,"L %d%d%d%d%d%d",disable_SL1,disable_SL2,disable_SL3,disable_SL4,disable_SL5,disable_SL7);
                   lcd_gotoxy(7,2);
                   lcd_puts(text);
              if (next_page==0)
                    {
                    delay_ms(50);
                    safhe++;
                    if (safhe>last_safhe) safhe=1;
                    }
              if (previuse_page==0)
                    {
                    delay_ms(50);
                    safhe--;
                    if (safhe<1) safhe=last_safhe;
                    }              
              if(exit==0) break;   
                           
                      if(safhe==1)
                       {
                       lcd_gotoxy(5,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(10,1);
                       lcd_puts("^");
                       if(increase==0) disable_SM=1; 
                       if(decrease==0) disable_SM=0;                            
                       }             
                       else if(safhe==2)
                       {
                       lcd_gotoxy(10,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(14,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SR1=1; 
                       if(decrease==0) disable_SR1=0;                        
                       }              
                       else if(safhe==3)
                       {
                       lcd_gotoxy(14,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(15,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SR2=1; 
                       if(decrease==0) disable_SR2=0;                        
                       }              
                       else if(safhe==4)
                       {
                       lcd_gotoxy(15,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(16,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SR3=1; 
                       if(decrease==0) disable_SR3=0;                            
                           
                       }             
                       else if(safhe==5)
                       {
                       lcd_gotoxy(16,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(17,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SR4=1; 
                       if(decrease==0) disable_SR4=0;                            
                           
                       }              
                       else if(safhe==6)
                       {
                       lcd_gotoxy(17,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(18,1); 
                       lcd_puts(">");
                       if(increase==0) disable_SR5=1; 
                       if(decrease==0) disable_SR5=0;                            
                           
                       }              
                       else if(safhe==7)
                       {

                       lcd_gotoxy(18,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(18,3);
                       lcd_puts(">");
                       if(increase==0) disable_SR7=1; 
                       if(decrease==0) disable_SR7=0;                            
                       }             
                       else if(safhe==8)
                       {
                       lcd_gotoxy(18,3);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(1,3); 
                       lcd_puts("<");
                       if(increase==0) disable_SL7=1; 
                       if(decrease==0) disable_SL7=0;                        
                       }              
                       else if(safhe==9)
                       {
                       lcd_gotoxy(1,3);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(1,1); 
                       lcd_puts("<");
                       if(increase==0) disable_SL5=1; 
                       if(decrease==0) disable_SL5=0;                        
                       }              
                       else if(safhe==10)
                       {
                       lcd_gotoxy(1,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(2,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SL4=1; 
                       if(decrease==0) disable_SL4=0;                            
                           
                       }             
                       else if(safhe==11)
                       {
                       lcd_gotoxy(2,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(3,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SL3=1; 
                       if(decrease==0) disable_SL3=0;                            
                           
                       }              
                       else if(safhe==12)
                       {
                       lcd_gotoxy(3,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(4,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SL2=1; 
                       if(decrease==0) disable_SL2=0;                            
                           
                       }                 
                       else if(safhe==13)
                       {
                       lcd_gotoxy(4,1);
                       lcd_puts(" ");
                           
                       lcd_gotoxy(5,1); 
                       lcd_puts("^");
                       if(increase==0) disable_SL1=1; 
                       if(decrease==0) disable_SL1=0;                            
                           
                       }             
                                                
              }  
             }
            }
        else if (page==2)      // color
            {
            char sen_page=1,change=0;
            lcd_gotoxy(0,0);
            lcd_puts("APDS 9960press enter ");
            if(enter==0)
                { 
                while(enter==0);
                lcd_clear();
                while(1)
                    {
                    if (next_page==0)
                        {
                        while (next_page==0);
                        sen_page++;
                        if (sen_page>3) sen_page=1;
                        lcd_clear();
                        }
                    if (previuse_page==0)
                        {
                        while (previuse_page==0);
                        sen_page--;
                        if (sen_page<1) sen_page=4;
                        lcd_clear();
                        }

                    if (exit==0)
                        {
                        while(exit==0);
                        delay_ms(100);
                        lcd_clear();
                        break;
                        }
                    if(sen_page==1)
                        {  
                        color(left);
                        difL= abs(blue_L - red_L);                                        
                        sprintf(text,"dif L=%4d",difL);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);
                        sprintf(text,"grnL=%4d",green_L);
                        lcd_gotoxy(0,1);
                        lcd_puts(text);
                        sprintf(text,"val_L=%4d  ",value_l);
                        lcd_gotoxy(0,2);
                        lcd_puts(text);
                        
                     
                          if(increase==0)
                                {
                                while(increase==0);
                                value_l+=2;
                                }
                          else if(decrease==0)
                                {
                                while(decrease==0);
                                value_l-=2;
                                } 
                          if(enter==0) 
                           {
                              red_lcal=red_L;
                              green_lcal=green_L;
                              blue_lcal=blue_L;
                              amb_lcal=amb_L;                          
                            }                          
                          
                             
                        if(color(left)==green)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("greenL  ");
                            }
                        else if(color(left)==black)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("BlackL  ");
                            }
                        else if(color(left)==red)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("RedL  ");
                            }
                        else
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("      ");
                            }

                        }


                    if(sen_page==2)
                        {  
                        color(right);
                        difR= abs(blue_R - red_R);                                        
                        sprintf(text,"dif R=%4d",difR);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);
                        sprintf(text,"grnR=%4d",green_R);
                        lcd_gotoxy(0,1);
                        lcd_puts(text);
                        sprintf(text,"val_R=%4d  ",value_r);
                        lcd_gotoxy(0,2);
                        lcd_puts(text);
                        
                     
                          if(increase==0)
                                {
                                while(increase==0);
                                value_r+=2;
                                }
                          else if(decrease==0)
                                {
                                while(decrease==0);
                                value_r-=2;
                                } 
                          if(enter==0) 
                           {
                              red_rcal=red_R;
                              green_rcal=green_R;
                              blue_rcal=blue_R;
                              amb_rcal=amb_R;                          
                            }                          
                          
                             
                        if(color(right)==green)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("greenR  ");
                            }
                        else if(color(right)==black)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("BlackR  ");
                            }
                        else if(color(right)==red)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("RedR  ");
                            }
                         else
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("      ");
                            }

                        }

                    if(sen_page==3)
                        {
                        color(right);
                        color(left);
                        sprintf(text,"red=%4d    red=%4d",red_L,red_R);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);
                        sprintf(text,"grn=%4d    grn=%4d",green_L,green_R);
                        lcd_gotoxy(0,1);
                        lcd_puts(text);
                        sprintf(text,"blue=%4d  blue=%4d",blue_L,blue_R);
                        lcd_gotoxy(0,2);
                        lcd_puts(text);
                        sprintf(text,"amb=%4d    amb=%4d",amb_L,amb_R);
                        lcd_gotoxy(0,3);
                        lcd_puts(text);
                        }
                    if(sen_page==4)
                        {
                        color(right);
                        color(left);
                        sprintf(text,"Dif_GB= %4d %4d  ",difGBL,difGBR);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);
                        sprintf(text,"Dif_GR= %4d %4d  ",difGRL,difGRR);
                        lcd_gotoxy(0,1);
                        lcd_puts(text);
                        sprintf(text,"Dif_RB= %4d %4d  ",difRBL,difRBR);
                        lcd_gotoxy(0,2);
                        lcd_puts(text);
                        if(color(left)==green)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("greenL  ");
                            }
                        else if(color(left)==black)
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("BlackL  ");
                            }
                        else
                            {
                            lcd_gotoxy(0,3);
                            lcd_puts("      ");
                            }
                        if(color(right)==green)
                            {
                            lcd_gotoxy(14,3);
                            lcd_puts("greenR  ");
                            }
                        else if(color(right)==black)
                            {
                            lcd_gotoxy(14,3);
                            lcd_puts("BlackR  ");
                            }                       
                         else
                            {
                            lcd_gotoxy(14,3);
                            lcd_puts("      ");
                            }

                        }

                    }
                }
            }
        else if (page==3)      // ultra 
            {
            sprintf(text,"%3d     %3d     %3d ",UL,UF,UR);
            lcd_gotoxy(0,0);
            lcd_puts(text);
            sprintf(text,"dis= %5d   ",VLF);
            lcd_gotoxy(0,1);lcd_puts(text);
            }
        else if (page==4)      // silver
            {
            char sen_page=1;
            lcd_gotoxy(0,0);
            lcd_puts("silver calib");
            if(enter==0)
                {
                while(enter==0);
                lcd_clear();
                while(1)
                    {
                    sprintf(text,"SM= %1.1f value: %1.1f",VSM,silver_voltage);
                    lcd_gotoxy(0,0);lcd_puts(text);
                     if (increase==0)
                            {
                            silver_voltage+=0.1;
                            }
                        else if (decrease==0)
                            {
                            silver_voltage-=0.1;
                            }
                   if(VSM<=silver_voltage)
                        {
                        lcd_gotoxy(0,3);
                        lcd_puts("silverL  ");
                        delay_ms(100);
                        }
                    else
                        {
                        lcd_gotoxy(0,3);
                        lcd_puts("         ");
                        delay_ms(100);
                        }
                    
                    }
                }
            }
        else if (page==5)      // voltage R
            {
            sprintf(text,"Right  R1:%1.1f ",VSR1);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            sprintf(text,"2:%1.1f  3:%1.1f 4:%1.1f ",VSR2,VSR3,VSR4);
            lcd_gotoxy(0,1);
            lcd_puts(text);

            sprintf(text,"5:%1.1f  6:%1.1f 7:%1.1f ",VSR5,VSR6,VSR7);
            lcd_gotoxy(0,2);
            lcd_puts(text);
            }
        else if (page==6)      // voltage L
            {
            sprintf(text,"Left  SM:%1.1f L1:%1.1f ",VSM,VSL1);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            sprintf(text,"2:%1.1f  3:%1.1f 4:%1.1f ",VSL2,VSL3,VSL4);
            lcd_gotoxy(0,1);
            lcd_puts(text);

            sprintf(text,"5:%1.1f  6:%1.1f 7:%1.1f ",VSL5,VSL6,VSL7);
            lcd_gotoxy(0,2);
            lcd_puts(text);
            }
        else if (page==7)      // switches
            {
            sprintf(text,"ENC=%d , %d cd:%d",ENC_R,TCNT1,conductive);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            sprintf(text,"SFL:%d SFR:%d vic:%d%d",SFL,SFR,victim,check_kit);
            lcd_gotoxy(0,1);
            lcd_puts(text);

            sprintf(text,"SBL:%d VOLt:%1.1f  ob:%d",SBL,co_volt,check_obs);
            lcd_gotoxy(0,2);
            lcd_puts(text);
            }
        else if (page==8)      // cmp
            {
            sprintf(text,"deg=%3d   ",deg);
            lcd_gotoxy(0,0);
            lcd_puts(text);
                                                       
            sprintf(text,"pitch:%3d  ",pitch);
            lcd_gotoxy(0,1);
            lcd_puts(text);

            sprintf(text,"role:%3d",role);
            lcd_gotoxy(0,2);
            lcd_puts(text);
            
            sprintf(text,"DN:%3d",DN);
            lcd_gotoxy(0,3);
            lcd_puts(text);            
            if(increase==0)
             {
             DN=0;
             DN=deg;
             sprintf(text,"degnew=%d",deg);
             lcd_gotoxy(10,3);
             lcd_puts(text);
             
             }
            }
        
     }
    }
void robot_setup (void)
    {
    char page=1,last_page=10;
    #asm("cli")
    lcd_clear();
    while (1)
        {
        if (next_page==0)
            {
            while (next_page==0);
            delay_ms(50);
            page++;
            if (page>last_page) page=1;
            lcd_clear();
            }
        if (previuse_page==0)
            {
            while (previuse_page==0);
            delay_ms(50);
            page--;
            if (page<1) page=last_page;
            lcd_clear();
            }
        if (exit==0)
            {
            while(exit==0);
            delay_ms(100);
            lcd_clear();
            break;
            }
        if (page==1)            // speed
            {
            sprintf(text,"Line speed=%3d ",sp);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            if (decrease==0)
                {
                while(enter==0);delay_ms(200);
                go(-sp,-sp);
                delay_ms(2000);
                go(0,0);
                }
            else if (increase==0)
                {
                while(enter==0)
                delay_ms(200);
                go(sp,sp);
                delay_ms(2000);
                go(0,0);
                }
            }
        else if (page==2)       // T90L
            {
            sprintf(text,"   T90L=%3d  ",T90L);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            if (decrease==0)
                {
                T90L-=1;
                if (T90L<10)
                    T90L=10;
                delay_ms(50);
                }
            else if (increase==0)
                {
                T90L+=1;
                if (T90L>100)
                    T90L=100;
                delay_ms(50);
                }
            else if (enter==0)
                {
                while(enter==0);
                delay_ms(300);
                go(-sp,sp);
                count(T90L);
                go(0,0);
                }
            }
        else if (page==3)       // T90R
            {
            sprintf(text,"   T90R=%3d  ",T90R);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            if (decrease==0)
                {
                T90R-=1;
                if (T90R<10)
                    T90R=10;
                delay_ms(50);
                }
            else if (increase==0)
                {
                T90R+=1;
                if (T90R>100)
                    T90R=100;
                delay_ms(50);
                }
            else if (enter==0)
                {
                while(enter==0);
                delay_ms(300);
                go(sp,-sp);
                count(T90R);
                go(0,0);
                }
            }
        else if (page==4)       // Shoae charkheshe mane
            {
            sprintf(text,"radious of going around    =%4d ",rad_round);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            if (increase==0)
                {
                rad_round++;
                delay_ms(100);
                if (rad_round>100)
                    rad_round=100;
                }
            else if (decrease==0)
                {
                rad_round--;
                delay_ms(100);
                if (rad_round<1)
                    rad_round=1;
                }
            else if (enter==0)
                {
                while (enter==0);
                lcd_clear();
                lcd_putsf("Testing obstacle Turning");
                delay_ms(1000);
                go(900,900);
                while (UF>dis_obs);
                if(increase==0)
                obstacle(obstacle_dir);
                }
            }
        else if (page==5)       // faseleh az mane
            {
            sprintf(text,"distance from obs=%d ",dis_obs);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            if (increase==0)
                {
                dis_obs+=1;
                delay_ms(100);
                if (dis_obs>90)
                    dis_obs=90;
                }
            else if (decrease==0)
                {
                dis_obs-=1;
                delay_ms(100);
                if (dis_obs<10)
                    dis_obs=10;
                }
            }
        else if (page==6)       // direction of obstacle
            {
            lcd_gotoxy(0,0);
            lcd_puts("  press enter +  ");
            lcd_gotoxy(0,1);
            lcd_puts("inc=right , dec=left");
            if(enter==0)
                {
                while(enter==0);
                lcd_clear();
                while(1)
                    {
                    if (increase==0)
                        {
                        obstacle_dir=right;
                        lcd_clear();lcd_gotoxy(0,0);
                        lcd_puts("right");
                        }
                    else if (decrease==0)
                        {
                        obstacle_dir=left;
                        lcd_clear();lcd_gotoxy(0,0);
                        lcd_puts("left");
                        }
                    if(exit==0)
                        {
                        while(exit==0);break;
                        }
                    }
                }
            }
        else if (page==7)       // halat mane
            {
            if(increase==0)
                {
                while(increase==0);
                halat_mane=1;
                }
            if(decrease==0)
                {
                while(decrease==0);
                halat_mane=0;
                }                    
            sprintf(text,"halate mane = %d",halat_mane);
            lcd_puts(text);
            }

        else if(page==8)        // deg calibration
            {
            char cmp_page=1;
            lcd_gotoxy(0,0);lcd_puts("cmp setup");
            if(enter==0)
                {
                while(enter==0);
                while(1)
                    {
                    if (next_page==0)
                        {
                        while (next_page==0);
                        cmp_page++;
                        if (cmp_page>6) cmp_page=1;
                        lcd_clear();
                        }
                    if (previuse_page==0)
                        {
                        while (previuse_page==0);
                        cmp_page--;
                        if (cmp_page<1) cmp_page=6;
                        lcd_clear();
                        }
                    if (exit==0)
                        {
                        while(exit==0);
                        delay_ms(100);
                        lcd_clear();
                        break;
                        }
                    if(cmp_page==1)
                        {
                        sprintf(text,"deg=%3d   ",deg);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);

                        sprintf(text,"N_deg=%3d   ",direction_deg);
                        lcd_gotoxy(0,1);
                        lcd_puts(text);

                        if (enter==0)
                            {
                            DN=0;DN=deg;
                            direction_deg=deg;
                            DE=DN+90;
                            DS=DN+180;
                            DW=DN+270;                                                      
                            
                            }
                        }
                    if(cmp_page==2)
                        {
                        sprintf(text,"deg=%3d   ",deg);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);

                        sprintf(text,"S_deg=%3d   ",ev_out_deg);
                        lcd_gotoxy(0,1);
                        lcd_puts(text);

                        if (enter==0)
                            {
                            delay_ms(5);
                            ev_out_deg=deg;
                            }


                        }
                    if(cmp_page==3)
                        {
                        sprintf(text,"tedad kol=%d   ",x_ball);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);
                        if (increase==0)
                            {
                            while(increase==0);
                            x_ball++;
                            if(x_ball>12)
                            x_ball=12;
                            }
                        else if (decrease==0)
                            {
                            while(decrease==0);
                            x_ball--;
                            if(x_ball<2)
                            x_ball=2;
                            }

                        }
                    if(cmp_page==4)
                        {
                        sprintf(text,"tedad res=%d   ",x_s_ball);
                        lcd_gotoxy(0,0);
                        lcd_puts(text);
                        if (increase==0)
                            {
                            while(increase==0);
                            x_s_ball++;
                            if(x_ball>8)
                            x_s_ball=8;
                            }
                        else if (decrease==0)
                            {
                            while(decrease==0);
                            x_s_ball--;
                            if(x_s_ball<1)
                            x_s_ball=1;
                            }

                        }
                    if(cmp_page==5)
                        {
                        //pist_calibration();
                        }
                    if(cmp_page==6)
                        {
                        //cmps_calibrate(2);
                        }

                    }
                }
            }
        else if (page==9)       // gap time
            {
            sprintf(text,"gap time=%d ",gap_time_limit);
            lcd_gotoxy(0,0);
            lcd_puts(text);

            if (increase==0)
                {
                gap_time_limit+=1;
                delay_ms(80);
                if (gap_time_limit>120)
                    gap_time_limit=120;
                }
            else if (decrease==0)
                {
                gap_time_limit-=1;
                delay_ms(80);
                if (gap_time_limit<1)
                    gap_time_limit=1;
                }
            }
        else if (page==10)       // gap with cmps enable
            {
            sprintf(text,"gap with cmps=%d ",gap_cmp_en);
            lcd_gotoxy(0,0);
            lcd_puts(text);
                                        
            lcd_gotoxy(5,1);
            if ( gap_cmp_en ==1)
                lcd_puts("  enabled  ");
            else
                lcd_puts("  disabled  ");
            
            if (increase==0)
                {
                gap_cmp_en=1;
                }
            else if (decrease==0)
                {
                gap_cmp_en=0;
                }
            }
        }
    }
void dynamixel_setup (void)
    {
    char page=1,last_page=11;
    lcd_clear();
    while(1)
      {

      if(exit==0)
          {
          while(exit==0);
          delay_ms(100);
          lcd_clear();
          break;
          }
      else if (next_page==0)
          {
          while (next_page==0);
          delay_ms(50);
          page++;
          if (page>last_page)  page=1;
          lcd_clear();
          }                       
      else if (previuse_page==0)
          {
          while (previuse_page==0);
          delay_ms(50);
          page--;
          if (page<1) page=last_page;
          lcd_clear();
          }                       
        if(page<=4)
            {
            sprintf(text,"    ARM    %4d ",deg_arm); 
            lcd_gotoxy(0,0);
            lcd_puts(text);

            sprintf(text,"    BASKET    %4d ",deg_basket); 
            lcd_gotoxy(0,1);
            lcd_puts(text);

            sprintf(text,"    XL       %4d ",deg_xl); 
            lcd_gotoxy(0,2);
            lcd_puts(text);
            }
        else if (page<=8)
            {
            lcd_gotoxy(0,0);
            lcd_puts("    ARM NORMAL        ");

            lcd_gotoxy(0,1);
            lcd_puts("     ARM SEARCH       "); 

            lcd_gotoxy(0,2);
            lcd_puts("     ARM DROP         "); 

            lcd_gotoxy(0,3);
            lcd_puts("     ARM GET CHK      "); 
            }
        else if (page<=12)
            {
            lcd_gotoxy(0,0);
            lcd_puts("     ARM MOVE 5       ");

            lcd_gotoxy(0,1);
            lcd_puts("     ARM SHEADING 5   "); 

            lcd_gotoxy(0,2);
            lcd_puts("     BASKET NRML      "); 

            lcd_gotoxy(0,3);
            lcd_puts("     BASKET SHEADING  "); 
            }                           
        if(page==1)         //AX ARM
            {
            lcd_gotoxy(0,0);
            lcd_puts("-> ");
            if (increase==0)
                {
                delay_ms(10);
                if(deg_arm<1022)
                    deg_arm+=5;

                ax(13,deg_arm,50);  
                }
            else if (decrease==0)
                {
                delay_ms(10);

                if(deg_arm>1)
                    deg_basket -=5; 

                ax(13,deg_arm,50);  
                }

            }                     
        else if(page==2)    //AX BASKET
            {
            lcd_gotoxy(0,1);
            lcd_puts("-> ");
            if (increase==0)
                {
                delay_ms(10);
                if(deg_basket<1022)
                    deg_basket+=5;

                ax(17,deg_basket,50);  
                }

            else if (decrease==0)
                {
                delay_ms(10);

                if(deg_basket>1)
                    deg_basket -=5; 

                ax(17,deg_basket,50);  
                }
            }
        else if(page==3)    //XL BAZOO
            {
            lcd_gotoxy(0,2);
            lcd_puts("-> ");

            if (increase==0)
                {
                delay_ms(10);
                if(deg_xl<1022)
                    deg_xl+=5;

                xl(21,deg_xl,200); 
                xl(AL,1023-deg_xl,200);  
                }
            else if (decrease==0)
                {
                delay_ms(10);

                if(deg_xl>1)
                    deg_xl -=5; 

                xl(21,deg_xl,200); 
                xl(AL,1023-deg_xl,200);  
                }
            }
        else if(page==4)    //normal
            {
              lcd_gotoxy(0,0);
            lcd_puts("-> ");
            if (enter==0)
               move_arm(normal);
            }                              
        else if(page==5)    //search
            {
            lcd_gotoxy(0,1);
            lcd_puts("-> ");
            if (enter==0)
               move_arm(search);
            }
        else if(page==6)    //drop
            {
            lcd_gotoxy(0,2);
            lcd_puts("-> ");
            if (enter==0)
               move_arm(drop);
            }
        else if(page==7)    //get check
            {
            lcd_gotoxy(0,3);
            lcd_puts("-> ");
            if (enter==0)
               move_arm(get);
            }
        else if(page==8)    // move 5
            {
            lcd_gotoxy(0,0);
            lcd_puts("-> ");
            if (enter==0)
               move_arm(5);

            }
        else if(page==9)    // sheading 5
            {
            lcd_gotoxy(0,1);
            lcd_puts("-> ");
            if (enter==0)
               move_arm(6);
            }
        else if(page==10)   // normal
            {
            lcd_gotoxy(0,2);
            lcd_puts("-> ");
            if (enter==0)
               move_basket(1);
            }
        else if(page==11)   // sheading
            {
            lcd_gotoxy(0,3);
            lcd_puts("-> ");
            if (enter==0)
               move_basket(2);
            }            
                 
                
      }
    }
/********************Line********************/
void obstacle (char obs_direction)
    {
    int SLS=SL1+SL2+SL3;
    int SRS=SR1+SR2+SR3;

    int i=0,time=0,x=0;
    go(0,0);
    while (1)
       {
       delay_ms(15);
       if (UF<=70)         go(-100,-100);
       else if (UF>=75)     go(100,100);
       else if (UF>70 && UF<80)
            {
            go(0,0);
            delay_ms(50);
            break;
            }
       delay_ms(5);
       if (time++>400 || UF>100)
            {
            lcd_clear();
            lcd_putsf("break");
            break;
            }
       sprintf(text,"    UF=%3d  \n    time=%3d  ",UF,time);
       lcd_gotoxy(0,0);
       lcd_puts(text);
       }
    if(UF<100)
       {
       // in 2 ta if baraye Auto kardane jahate charkhesh ast
       if (UL<150)  
            obs_direction=right;  // hata age obs_direction ro rooye left tanzim kardeh bashim bayad az right bere 
       if (UR<150)
            obs_direction=left;
                   
       if(obs_direction==right)   // Right
        {
            go(255,-255); while(UF<100);
            go(255,-255); count(15);   
            go(255,255);
            count(20);
            TCNT1=0;i=0; 
            while( !SL7)
            { 
            i++;
            if(i>=150)break;
            if(UL<45 && UL>20)
               go(rad_round*2,255);
            else
               go(rad_round,255); 
            }
            
            //go(50,255);count(10); 
             x=0;
             while(SM==0 && SR1==0 && SR2==0 && x<300)
             { 
             go(210,-255);
             x++;

             }
            go(210,-255);count(8);

             x=0;
            if(!SM && i<300)
             {
               go(255,-255);
               count(T90R); 
               i++;
             }
            go(-255,-255);
            delay_ms(270);
        }
       else
        {
            go(-255,255); while(UF<100);
            go(-255,255); count(15);   
            go(255,255);
            count(20);
            TCNT1=0;i=0; 
            while(!SR7)
             { 
            i++;
            if(i>=150)break;
            if(UR<45 && UR>20)
               go(255,rad_round*2);
            else
               go(255,rad_round); 
            }
          
             go(255,50);count(15);
             x=0;
             while(SM==0 && SL1==0 &&SR1==0 && SL2==0 && x<300)
                { 
             go(-255,210);
             x++;

             }
             x=0;
            go(-255,210);count(8);
 
             i=0; 
             if(!SM && i<300)
                {
               go(-255,255);
               count(T90L); 
               i++;
              }
             i=0;
            go(-255,-255);
            delay_ms(270);
         }
       }
    else go(sp,sp);
    }
void gap(int enable)
    {   
    if (enable==1)
        {
        go(0,0);delay_ms(100);    
        if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   turnto(0);
        if (deg>=45 && deg<135)   turnto(90);
        if (deg>=135 && deg<225)  turnto(180);
        if (deg>=225 && deg<=315) turnto(270);       
                
        go(sp,sp); delay_ms(200);
        
        while(senscount_all==0)
            {
            t_gap++;
            if(t_gap>gap_time_limit*280) 
                ev_zone();   // in khoobe faghat bayad test koni ke hodoode 30 ya 40 sant bere jelo
            }
        }
    else
        go(sp,sp);
    t_gap=0; 
    }
void gap_rooz1(int number)
    {
    int i,tt;
    bit breaked=0;
    if(senscount_all==0)
         {
         go(-sp,-sp);
         while(SM==0 && SL1==0 && SR1==0)
            {
            go(-sp,-sp);
            if (UL + UR< 200)  // yani dare red room :)
                {
                go(0,0);delay_ms(1000);
                ev_zone();
                } 
            }
         for(i=0;i<40;i++)
            {
            delay_ms(1);
            go(-sp,-sp);
            if(SR7)       {go(255,-255);delay_ms(300);while(SM==0 && SL1==0 && SR1==0);breaked=1;break;}
            else if (SL7) {go(-255,255);delay_ms(300);while(SM==0 && SL1==0 && SR1==0);breaked=1;break;}             
            }
          if(breaked==0)  // means SL7==0 && SL6==0   =>  it is a big gap
            {  
            go(0,0);delay_ms(500);    
            if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   turnto(0);
            if (deg>=45 && deg<135)   turnto(90);
            if (deg>=135 && deg<225)  turnto(180);
            if (deg>=225 && deg<=315) turnto(270);       
            if(senscount_all==0){go(sp,sp);delay_ms(500);}  // bara vaghti ke vasate gap speed bump mizaran va sensor oono meshki mibineh
            while(senscount_all>0) // mire ta az khat kharej  beshe
                { 
                if (SM && SL1)     {go(255/25,255);}
                else if (SM && SR1)     {go(255,255/25);}

                else if (SM)            {go(255,255);}
                
                else if (SL1)           {go(255/(-3.5),255);}
                else if (SR1)           {go(255,255/(-3.5));}

                else if (SL2)           {go(255/(-2.5),255);}
                else if (SR2)           {go(255,255/(-2.5));}
                
                else if (SL3)           {go(-255,255/1.5);} 
                else if (SR3)           {go(255/1.5,-255);} 
                
                }
            
            go(sp,sp); while(senscount_all>0);
            go(sp,sp); while(senscount_all==0);
      

            }
         
         
         }
    t_gap=0;
    }
void gap_ghabli(int number)
    {
    int i,tt;
    bit breaked=0;
     if(senscount_all==0)
      {

         go(-sp,-sp); while(SM==0 && SL1==0 && SR1==0);
         for(i=0;i<40;i++)
            {
            delay_ms(1);
            go(-sp,-sp);
//            if(SR7)       {go(255,-255);delay_ms(300);while(SM==0 && SL1==0 && SR1==0);breaked=1;break;}
//            else if (SL7) {go(-255,255);delay_ms(300);while(SM==0 && SL1==0 && SR1==0);breaked=1;break;}             
            }
          if(breaked==0)  // means SL7==0 && SL6==0   =>  it is a big gap
            {  
            go(0,0);delay_ms(500);    
            if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   turnto(0);
            if (deg>=45 && deg<135)   turnto(90);
            if (deg>=135 && deg<225)  turnto(180);
            if (deg>=225 && deg<=315) turnto(270);       
            if(senscount_all==0){go(sp,sp);delay_ms(500);}  // bara vaghti ke vasate gap speed bump mizaran va sensor oono meshki mibineh
            go(sp,sp);
            while(senscount_all>0) // mire ta az khat kharej  beshe
                { 
                if (SM && SL1)     {go(255/25,255);}
                else if (SM && SR1)     {go(255,255/25);}

                else if (SM)            {go(255,255);}
                
                else if (SL1)           {go(255/(-3.5),255);}
                else if (SR1)           {go(255,255/(-3.5));}

                else if (SL2)           {go(255/(-2.5),255);}
                else if (SR2)           {go(255,255/(-2.5));}
                
                else if (SL3)           {go(-255,255/1.5);} 
                else if (SR3)           {go(255/1.5,-255);} 
                
                }
            tt=0;
             while(senscount_all==0)
              {
               tt++;
               go(sp,sp);
               if(tt>10000) ev_zone();   // in khoobe faghat bayad test koni ke hodoode 30 ya 40 sant bere jelo
              }

            }
         
         
      }
    t_gap=0;
    }
void rampdown(void)
    { 
    if(pitch<=25 && pitch>=4)
        {
        lcd_clear();
        lcd_puts("ramp_dwn"); 
        //ax(13,350,500);delay_ms(5);
        while(pitch<=25 && pitch>=9)
            {
            color_detect_ramp();
            if(SM && SR1)      go(210,120);
            else if(SM && SL1) go(120,210);

            else if(SM)  {go(190,190); }

            else if(SR1) go(210,120);
            else if(SL1) go(120,210);

            else if(SR2) go(190,110);
            else if(SL2) go(110,190);

            else if(SR3) go(190,90);
            else if(SL3) go(90,190);

            else if(SR4) go(190,70);
            else if(SL4) go(70,190);
            
            else if(SR5) go(190,50);
            else if(SL5) go(50,190);
            
            else if(SR7) go(190,40);
            else if(SL7) go(40,190);
            }
        move_arm(normal);

        }

    }
void rampup(void)
    { 
    int XX,ttt=0;
    while(abs(pitch)>=90)
        {
        lcd_clear();
        lcd_puts("ramp_up");
        //ax(13,290,500);delay_ms(5);
         xl(AL,xl_2,800);
         delay_ms(5);
         xl(AR,1023-xl_2,800);        
        while(abs(pitch)>=85)
            {
            ttt++;
            //color_detect_ramp();
            //if(ttt>1000) {go(-255,255);count(15);} 
            
            if(SM && SR1)      go(sp,sp*0.85);
            else if(SM && SL1) go(sp*0.85,sp);

            else if(SM)  {go(sp,sp); }

            else if(SR1) go(sp,sp*0.7);
            else if(SL1) go(sp*0.7,sp);

            else if(SR2) go(sp,sp*0.5);
            else if(SL2) go(sp*0.5,sp);

            else if(SR3) go(sp,sp*0.25);
            else if(SL3) go(sp*0.25,sp);

            else if(SR4) go(sp,-50);
            else if(SL4) go(-50,sp);
            
            else if(SR5) go(sp,10);
            else if(SL5) go(10,sp);
        
           else if(SR7) go(sp,10);
            else if(SL7) go(10,sp);
            else go(sp,sp);
            }
        ax(13,ax_arm_1,500);delay_ms(5);
        }
    
    }    
void color_detect (void)
    {   
    char y,color_R,color_L,left_is_green,right_is_green,checkcolor,sens_num,tcntcolor,t_color,i,armin,q;

    left_is_green=0;    
    right_is_green=0;
    checkcolor = 0; 

 
    if (color(left) == green )  
        {
        lcd_clear();
        lcd_puts("greenL");
        checkcolor = 1;
        left_is_green=1; 
        color_L = 1;
        }
    if (color(right) == green )
        { 
        lcd_clear();
        lcd_puts("greenR");                
        checkcolor = 1;
        right_is_green=1;
        color_R = 1;
        }      
    if(checkcolor==1)                     
        { 
        if(senscount >= 3)
            {
            lcd_clear();
            lcd_puts("coli");
            if(senscount_l>= 2 && left_is_green==1)                     
                {
                if(color(left) == green)
                    { 
                    lcd_clear();
                    lcd_puts("lft");
                    left_is_green=2;
                    for(i = 0; senscount_l <= 2 && i<200; i++)
                        {
                        go(-20,100);
                        if(color(right) == green)  {right_is_green=1; break;}
                        }
                    }
                                       
                }
            if(senscount_r>= 2 && right_is_green==1)
                {

                if(color(right) == green)
                    {
                    lcd_clear();
                     lcd_puts("rght");  
                    right_is_green=2;
                    for(i=0; senscount_r <= 2 && i<200; i++)
                      {
                      go(100,-20);
                      if(color(left) == green)  {left_is_green=1; break;}
                      }
                    }
                }
            }
        if(right_is_green > 1 || left_is_green > 1)    // inja ghablan ==1 bood  
            {
            tcntcolor=0;
            while (tcntcolor<=15)
                {
                go(90,90);
                lcd_puts("check black");
                tcntcolor++;
                if(color(left) == green && left_is_green==0 )  left_is_green=1;
                if(color(right) == green && right_is_green==0) right_is_green=1; 
                 
                if (color(left) == black  && left_is_green==1 ) 
                left_is_green = 2;        
                        
                if (color(right) == black  && right_is_green==1 )   
                right_is_green = 2;        
    
                }   

            }      
        }
    if(left_is_green == 2 || right_is_green == 2)
        {
        if (left_is_green == 2 && right_is_green == 2)
            {     
            move(right,T90R*2.1);  
            move(back,3);
            left_is_green = 0;
            right_is_green = 0;
            }
        else if (left_is_green == 2)
            {
            color_selected = right;   
            move(front,5); 
            go(-sp,sp);count(28);
            y=0;
            while((!SR1 && !SR2) && y<200)
                {
                y++;
                go(-sp,sp);
                }
                                                         
            left_is_green = 0;
            right_is_green = 0;
            }                                     
        else if (right_is_green == 2)
            {  
            color_selected = left;     
            move(front,5); 
            go(sp,-sp);count(28); 
            y=0;
            while((!SL1 && !SL2) && y<200)
                {
                y++;
                go(sp,-sp);
                }                   
            right_is_green = 0; 
            left_is_green = 0;
            }                                       
        }
    }
void color_detect_ramp (void)
    {   
    char y,color_R,color_L,left_is_green,right_is_green,checkcolor,sens_num,tcntcolor,t_color,i,armin,q;

    left_is_green=0;    
    right_is_green=0;
    checkcolor = 0; 
    if (color(left) == green )  
        {
        lcd_clear();
        lcd_puts("greenL");
        checkcolor = 1;
        left_is_green=1; 
        color_L = 1;
        }
    if (color(right) == green )
        { 
        lcd_clear();
        lcd_puts("greenR");                
        checkcolor = 1;
        right_is_green=1;
        color_R = 1;
        }      
    if(checkcolor==1)                     
        { 
        if(senscount >= 3)
            {
            lcd_clear();
            lcd_puts("coli");
            if(senscount_l>= 2 && left_is_green==1)                     
                {
                if(color(left) == green)
                    { 
                    lcd_clear();
                    lcd_puts("lft");
                    left_is_green=2;
                    for(i = 0; senscount_l <= 2 && i<200; i++)
                        {
                        go(-20,100);
                        if(color(right) == green)  {right_is_green=1; break;}
                        }
                    }
                                       
                }
            if(senscount_r>= 2 && right_is_green==1)
                {

                if(color(right) == green)
                    {
                    lcd_clear();
                     lcd_puts("rght");  
                    right_is_green=2;
                    for(i=0; senscount_r <= 2 && i<200; i++)
                      {
                      go(100,-20);
                      if(color(left) == green)  {left_is_green=1; break;}
                      }
                    }
                }
            }
        if(right_is_green > 1 || left_is_green > 1)    // inja ghablan ==1 bood  
            {
            tcntcolor=0;
            while (tcntcolor<=15)
                {
                go(90,90);
                lcd_puts("check black");
                tcntcolor++;
                if(color(left) == green && left_is_green==0 )  left_is_green=1;
                if(color(right) == green && right_is_green==0) right_is_green=1; 
                 
                if (color(left) == black  && left_is_green==1 ) 
                left_is_green = 2;        
                        
                if (color(right) == black  && right_is_green==1 )   
                right_is_green = 2;        
    
                }   

            }      
        }
    if(left_is_green == 2 || right_is_green == 2)
        {
        if (left_is_green == 2 && right_is_green == 2)
            {     
            move(right,T90R*2.1);  
            move(back,3);
            left_is_green = 0;
            right_is_green = 0;
            }
        else if (left_is_green == 2)
            {
            color_selected = right;   
            move(back,10);
            move(left,T90L+15);
            y=0;
            move(front,15);                  
                                             
            left_is_green = 0;
            right_is_green = 0;
            }                                     
        else if (right_is_green == 2)
            {  
            color_selected = left;
            move(back,10);
     
            move(right,T90R+15);
 
            y=0;
                move(front,15);                  
            right_is_green = 0; 
            left_is_green = 0;
            }                                       
        }
    }
void rescuekit(void)
 {

 if(check_kit==1) 
    {
    move(back,20);
    delay_ms(500);
    move_arm(search);
    go(0,0);
    delay_ms(500);
    rotation_motor(0);
    while(victim==0)
     {
       if (SM)          {go(255,255);}

        else if (SR1)         {go(255,255/(-3.5));}
        else if (SL1)         {go(255/(-3.5),255);}

        else if (SR2)         {go(255,255/(-2.5));}
        else if (SL2)         {go(255/(-2.5),255);}

        else if (SR3)         {go(255/1.5,-255);}
        else if (SL3)         {go(-255,255/1.5);}
     
     
     }
    go(0,0);
    move(front,2);
    move_arm(get);
    delay_ms(500);
    
    move_arm(drop);
    delay_ms(500);
    
    xl(AL,xl_2,180);
    xl(AR,1023-xl_2,180);
    delay_ms(800);
    
    go(sp,sp);delay_ms(150);
    go(0,0);
    
    delay_ms(500);
    move_arm(search);
    delay_ms(1000);
    
    barband[0]=3;
    rotation_motor(1);
    delay_ms(1000);
    move_arm(normal);
    rescue_kit=1;
    }
  
  
  } 
void line (void)
    {
    //lcd_puts("line");
    if      (SM && disable_SM==0 && SR1 && disable_SR1==0 && color_selected == right)        {go(255,255/25);}
    else if (SM && disable_SM==0 && SL1 && disable_SL1==0 && color_selected == right)   {go(255/25,255);}

    else if (SM && disable_SM==0 && color_selected == right)          {go(255,255);}

    else if (SR1 && disable_SR1==0 && color_selected == right)         {go(255,255/(-3.5));}
    else if (SL1  && disable_SL1==0 &&  color_selected == right)         {go(255/(-3.5),255);}

    else if (SR2   && disable_SR2==0 &&  color_selected == right)         {go(255,255/(-1.1));}
    else if (SL2  && disable_SL2==0 &&  color_selected == right)         {go(255/(-1.1),255);}

    else if (SR3  && disable_SR3==0 &&  color_selected == right)         {go(255/2.6,-255);}
    else if (SL3 && disable_SL3==0   && color_selected == right)         {go(-255,255/2.6);}

    else if (SR4  && disable_SR4==0 &&  color_selected == right)         {go(255/1.18,-255);}
    else if (SL4 && disable_SL4==0   && color_selected == right)         {go(-255,255/1.18);}

    else if (SR5  && disable_SR5==0 && color_selected == right)         {go(255,-255);}
    else if (SL5 && disable_SL5==0 && color_selected == right)         {go(-255,255);}

    else if (SR7  && disable_SR7==0 && color_selected == right)         {go(255,-255);}
    else if (SL7 && disable_SL7==0 && color_selected == right)         {go(-255,255);}
     
    else if (SM   && disable_SM==0 && SL1 && disable_SL1==0)     {go(255/25,255);}
    else if (SM  && disable_SM==0 && SR1 && disable_SR1==0)     {go(255,255/25);}

    else if (SM && disable_SM==0)            {go(255,255);}
    
    else if (SL1 && disable_SL1==0)           {go(255/(-3.5),255);}
    else if (SR1 && disable_SR1==0)           {go(255,255/(-3.5));}

    else if (SL2 && disable_SL2==0)           {go(255/(-1.1),255);}
    else if (SR2 && disable_SR2==0)           {go(255,255/(-1.1));}
    
    else if (SL3 && disable_SL3==0)           {go(-255,255/2.6);} 
    else if (SR3 && disable_SR3==0)           {go(255/2.6,-255);} 
    
    else if (SR4  && disable_SR4==0)         {go(255/3,-255);}
    else if (SL4 && disable_SL4==0)          {go(-255,255/3);}

    else if (SL5 && disable_SL5==0)           {go(-255,255);}
    else if (SR5 && disable_SR5==0)           {go(255,-255);}

    else if (SL7 && disable_SL7==0)           {go(-255,255);}
    else if (SR7 && disable_SR7==0)           {go(255,-255);}
    
    if (SL3 || SL2 || SL1 || SM || SR1 || SR2 || SR3)   str=1;
    else if (SL7 || SL6 || SL5 || SL4  || SR4 || SR5 || SR6 || SR7)  str=0; 
    if (senscount_all==0 && str==1) go(255,255);
    }
/********************RedRoom********************/
void count(int cnt)
    {
    char cntn;
    TCNT1=0;
    if(ENC_L)
        {
        TCCR1B=0x06;
        cntn=0;
        }
    else if(!ENC_L)
        {
        TCCR1B=0x07;
        cntn=1;
        }
    while(TCNT1+1<=cnt)
        {
        if(ENC_L && cntn==1)
            {
            cntn=0;
            TCCR1B=0x06;
            }
        else if(!ENC_L && cntn==0)
            {
            cntn=1;
            TCCR1B=0x07;
            }
        }

    }
void correction(char direction)
    {
    int t=0,m=0,l_touch=0,r_touch=0,ttt=0;
    char obs_check_time=0;
    while(1)
        {
        t++;
        if(t>1500){correct=1;both_touched=0;break;}
        delay_us(100);    
        vic();
        come_down();
        if(direction==front)
            {
            if(!SFL && !SFR)
              {
              /*
//              if(deg>2 && deg<30)        
//                    {
//                    move(back,15);move(left,T90L*0.2);
//                    }
//              else if(deg<358 && deg>325)        
//                    {
//                    move(back,15);move(right,T90R*0.2);
//                    }      
*/              
              obs_check_time=0;correct=1;both_touched=1;go(0,0);break;
              }
            else if(SFL==1 && SFR==1)
                {
                go(250,250);both_touched=0;correct=0;
                if(check_obs)break;
                }
            else if(SFL==1 && SFR==0)
                {
                first_touched=right;
                t++; 
                lcd_clear();
                lcd_puts("correct L");
                go(255,0);both_touched=0;correct=1;
                if(t>100)        
                    {
                    move(back,15);move(right,T90R*0.2);
                    t=0;
                    }
                }
            else if(SFL==0 && SFR==1)
                {
                first_touched=left;
                t++; 
                lcd_clear();
                lcd_puts("correct R");
                go(0,255);both_touched=0;correct=1;
                if(t>100)
                    {
                    move(back,15);move(left,T90L*0.2);
                    t=0;
                    }
                }
            else both_touched=0;
            silver();
            }
        else if(direction==back)
            {
            if(VSM<=silver_voltage){go(sp,sp);count(10);break;}
            if(t>3500)break;
            if(SBL && SBR){go(0,0);break;}
            else if(SBL==0 && SBR==0)
            {
            go(-500,-500);
            if(VSM<=silver_voltage){go(sp,sp);count(10);break;}
            }

            else if(SBL==0 && SBR==1)
            go(-500,50);

            else if(SBL==1 &&SBR==0)
            go(50,-500);

            }
        else if(direction==sides)
            {
            if(UR<=45)
               {
                redroom_dir=left;
               // move(back,5);
               if(UR<=35)
                       {
                       move(back,8);
                       move(left,T90L/3.5);          
                       side_check=1;             
                       } 
               }
            else if(UL<=45) 
               {
               redroom_dir=right;
               //move(back,5);
               if(UL<=35)
                      {
                       move(back,8);
                       move(right,T90R/3.5);               
                      side_check=1;
                      }
               }   
            else break;

            break;
            }
        }
        lcd_clear();
        sprintf(text,"t= %4d   ",t);
        lcd_gotoxy(0,0);lcd_puts(text);
        sprintf(text,"dis= %4d  ",VLF);
        lcd_gotoxy(0,1);lcd_puts(text);
    }
void contact(void)
    {
    int i=0,first_calibrate,time;
    lcd_puts("contact");
    lcd_gotoxy(0,0);   
    if(tekrar<2)                   //GIR NAKARDAN BE DAR
     {
     if ((UR>300 && (pich_sakoo==1 || malesh_rast==1 || chargoosh==1) && redroom_dir==left) || 
        (UL>300 && (pich_sakoo==1 || malesh_chap==1 || chargoosh==1) && redroom_dir==right))
      { 
       lcd_clear();sprintf(text," %d  %d  %d ",pich_sakoo,malesh_chap,chargoosh);lcd_puts(text);
        while(tekrar<2)
         {
            move(back,11);
            if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   turnto(0);
            if (deg>=45 && deg<135)                            turnto(90);
            if (deg>=135 && deg<225)                           turnto(180);
            if (deg>=225 && deg<=315)                          turnto(270);        
            tekrar+=1;
         }
         move(front,20);
        while(time<200)
         {
         time++;
         go(sp,sp);
         if (UR<250 && (pich_sakoo==1 || malesh_rast==1 || chargoosh==1) && redroom_dir==left) 
         {move(right,6); break;}
         else if(UL<250 && (pich_sakoo==1 || malesh_chap==1 || chargoosh==1) && redroom_dir==right)
         {move(left,6); break;}
         else if(SFL==0 || SFR==0 || VSM<=silver_voltage || color(right)==green || color(left)==green) break; 
         }
        malesh_rast=0;
        malesh_chap=0;
      }     
     }       
    if(check_obs == 1)            //OBSTACLE
     {  
       if(loop>2) loop=0;
       lcd_clear();
       lcd_puts("OBS");
           vic();
           loop+=1;
           move(back,5);
            if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   turnto(0);
            if (deg>=45 && deg<135)   turnto(90);
            if (deg>=135 && deg<225)  turnto(180);
            if (deg>=225 && deg<=315) turnto(270);          
           DN=0;
           DN=deg;
           calculate();                       
           if(SFL == 1 || SFR == 1 )
                {
                move(back,12);
                if(redroom_dir == left)
                    {

                    if(s_ball>=2 || (ev_s_ball+ball_num>=3) )
                        { 

                         turnto(L);
                         go(150,150);
                         TCNT1=0;
                            while(TCNT1<=5 && UR<124)
                                {
                                vic();
                                if(VSM<=silver_voltage)
                                    {
                                    move(back,45);
                                    break;
                                    }
                                if(!SFL||!SFR)  break;
                                }
                            if(SFL==1||SFR==1)
                                {
                                go(sp,sp);check_while();
                                turn2(right,90);
                                move(front,80);                           
                                if(SFL==0||SFR==0) {move(back,15);move(left,T90L*0.3);}
                                else turn2(right,30);
                                }
                            else
                                {
                                move(back,5);turnto(B);
                                }
                          
                        
                        }
                    else
                        {
                        if(loop>=2){turnto(L);if(pich_sakoo==1)move(front,55);else move(front,40);pich_sakoo=0;} //loope mane dar va if baraye bade deposit mane
                        turnto(B);redroom_dir=right;                     
                        }
                    }
                else if(redroom_dir == right)
                    {

                    if(s_ball>=2 || (ev_s_ball+ball_num>=3) )
                        {  
                          turnto(R);                    
                            go(150,150);
                            TCNT1=0;
                            while(TCNT1<=5 && UL<124)
                                {
                                vic();
                                if(VSM<=silver_voltage){move(back,45);break;}
                                if(!SFL||!SFR)break;
                                }
                            if(SFL==1||SFR==1)
                                {
                                go(sp,sp);check_while();
                                turn2(left,90);
                                move(front,80);
                                if(SFL==0 && SFR==0) {move(back,15);move(right,T90R*0.3);loop=0;}
                                else turn2(left,30);
                                }
                            else
                                {
                                move(back,5);turnto(B);
                                }
                         
                             
                        }
                    else
                        {
                        if(loop>=2){turnto(R);if(pich_sakoo==1)move(front,55);else move(front,40);pich_sakoo=0;} //loope mane dar va if baraye bade deposit mane
                        turnto(B);redroom_dir=left;                                                               
                        }
                    }
                }
        
       redroom_time=0;                   
     }  
    else if(SFL == 0 || SFR == 0) //DIVAR - DEPOSIT
       {
       tekrar=0;
       malesh_rast=0;
       malesh_chap=0;
       if(!SFL)         first_touched=left;
       else if(!SFR)    first_touched=right;
       correction(front);
       if(correct==1)          //Wall-Deposit
           {
            correction(sides);
            if(side_check==1){correction(front);}
            lcd_clear();
            sprintf(text," VLF=%d",VLF);
            lcd_puts(text);

            if(VLF>102 && VLF<400)     //sakoo ok
                {
                chargoosh=0;
                vic();                
                lcd_clear();
                sprintf(text,"dis=%4d;sb:%d;evs:%d",VLF,s_ball,ev_s_ball);
                lcd_gotoxy(0,0);lcd_puts(text);
                sprintf(text,"bb=%d;evb:%d;bn:%d",b_ball,ev_b_ball,ball_num);
                lcd_gotoxy(0,1);lcd_puts(text);
                sprintf(text,"et=%4d;1:%d;2:%d;3:%d;4:%d",ev_ball,barband[0],barband[1],barband[2],barband[3]);
                lcd_gotoxy(0,2);lcd_puts(text);       
                if(VLF>102 && rescue_kit==1)
                 {
                 rotation_motor(0);
                 delay_ms(500);
                 move_basket(2);delay_ms(800);
                 move_basket(1);delay_ms(500);
                 rescue_kit=0;
                 }
                if(VLF>102 && (s_ball>0  || (ev_s_ball>=2 && b_ball>=1)))    // deposit
                   {
                   found_dep+=1;
                   lcd_clear();
                    while(1)        //RESANA
                     {  
                        if(rotate(1)!=100)             
                            {
                            delay_ms(50);
                            ev_s_ball++;
                            s_ball--;
                            ball_num--;
                            barband[rotate(1)]=0;
                            delay_ms(500);
                            move_basket(2);delay_ms(800);
                            move_basket(1);delay_ms(500);
                            if(dooble==1){dooble=0;barband[rotate(1)]=0;s_ball--;ev_s_ball++;ball_num--;dooble=0;}

                            }
                        else if(rotate(1)==100){rotate(0);break;}
                     }
                   s_ball=0;            
                   if(ev_s_ball>=2) //NaRESANA
                     {
                         while(1)
                          {
                              if(rotate(2)!=100)
                                 {
                                    delay_ms(50);
                                    ev_b_ball++;
                                    b_ball--;
                                    ball_num--;
                                    barband[rotate(2)]=0; 
                                    move_basket(2);delay_ms(800);
                                    move_basket(1);delay_ms(500);
                                    if(dooble==1){dooble=0;barband[rotate(2)]=0;b_ball--;ev_b_ball++;ball_num--;}
                                 }
                              else {rotate(0);break;}
                          }
                     b_ball=0;                   
                     }
                   ev_ball=ev_s_ball+ev_b_ball;                     
                   move(back,5);
                   go(0,0);              
                   if(ev_ball>=3) {delay_ms(500);get_out();}
                   }       
                if(VLF>102)
                 {
                 if(redroom_dir==right && first_touched==right)
                   { 
                                           
                    turn2(left,70);
                    go(sp,sp);
                    for(i=0;i<=120;i++)
                       {
                       if(SFR==0)break;
                       if(VSM<=silver_voltage || color(right)==green || color(left)==green ) {move(back,30); break;}
                       vic();
                       }
                    turn2(left,38);
                    redroom_dir=left;
                       
                   }    
                 else  
                   {
                    turn2(right,70);
                    go(sp,sp);
                    for(i=0;i<=120;i++)
                       {
                       if(SFL==0)break;
                       if(VSM<=silver_voltage || color(right)==green || color(left)==green ) {move(back,30); break;}
                       vic();
                       }
                    turn2(right,38);
                    redroom_dir=right;  
                   } 
                 }
                no_side=1;  
                pich_sakoo=1;                                    
                }
            else                        //Wall ok
                {
                if(loop>2) loop=0; 
                DN=0;
                DN=deg;
                calculate();
                if(redroom_dir==right)
                    {
                    if(s_ball>=2 || (ev_s_ball+ball_num>=3))    
                       { 
                       chargoosh=1;
                        if(UR<=70) 
                            {    
                            redroom_dir=left;
                            move(back,2);
                            }
                        else        
                        turn2(right,75);
                       }
                    else
                       { 
                        if(UR<=70) 
                            {
                            redroom_dir=left;
                            move(back,2);
                            }                                           

                        else if(redroom_dir==right)
                            {
                             move(back,5);
                             turnto(R);
                             move(left,T90L*0.2);                                 
                             if(pich_sakoo==1)                       {move(front,30);pich_sakoo=0;}
                             else if (pich_sakoo==0 && pich_dar==1)  {move(front,9);pich_dar=0;}
                             go(sp,sp);
                             check_while();
                            } 
                        if(check_while_finished==0)
                            {
                            loop=0;    
                            turnto(B);                           
                            redroom_dir=left;
                            }  
                       }
                    }
                else if(redroom_dir==left)                           
                    {
                    if(s_ball>=2 || (ev_s_ball+ball_num>=3)) 
                      { 
                       chargoosh=1;
                       if(UL<=70) 
                            {
                            redroom_dir=right;
                            move(back,2);
                            } 
                       else
                        turn2(left,75);
                      } 
                    else
                      {
                         if(UL<=70) 
                          {
                            redroom_dir=right;
                            move(back,2);
                           }
                         else if(redroom_dir==left)
                          { 
                          move(back,5);
                           turnto(L); 
                           move(right,T90R*0.2);                                              
                             if(pich_sakoo==1)                       {move(front,30);pich_sakoo=0;}
                             else if (pich_sakoo==0 && pich_dar==1)  {move(front,9);pich_dar=0;}
                           go(sp,sp);
                           check_while();
                          }
                         if(check_while_finished==0)
                          {
                          loop=0;    
                          turnto(B);                        
                          redroom_dir=right;
                          }

                      }
                    }
                }

           }         
       redroom_time=0;
       }    
    else if(redroom_time>=600)    //TIME
       {
        DN=0;
        DN=deg;
        tekrar=0;
        calculate();        
        move(back,10);
        if(redroom_dir==right)
            {
                    if(s_ball>=2 || b_ball>=4 || toop_get_out==1)
                       move(right,T90R*0.85);
                    else
                        { 
                        if(UR<=50) 
                            {
                            redroom_dir=left;
                            move(back,2);
                            }                                           

                         if(redroom_dir==right)
                             {
                             turnto(R);
                             move(left,T90R*0.2);                                 
                             if(pich_sakoo==1)                       {move(front,40);pich_sakoo=0;}
                             else if (pich_sakoo==0 && pich_dar==1)  {move(front,20);pich_dar=0;}
                             go(sp,sp);
                             check_while();
                             }
                        if(check_while_finished==0)
                            {
                            turnto(B);
                            redroom_dir=left;
                            }
                            pich_sakoo=0;
                            pich_dar=0; 
                        
                        }
            }
        else if(redroom_dir==left)
            {
                    if(s_ball>=2 || b_ball>=4 || toop_get_out==1)
                        move(left,T90L*0.85);
                        
                    else
                        {
                         if(UL<=70) 
                           {
                            redroom_dir=right;
                            move(back,2);
                           }
                          if(redroom_dir==left)
                         { 
                            turnto(L); 
                           move(right,T90R*0.2);                                              
                             if(pich_sakoo==1)                       {move(front,40);pich_sakoo=0;}
                             else if (pich_sakoo==0 && pich_dar==1)  {move(front,20);pich_dar=0;}
                           go(sp,sp);
                           check_while();
                         }
                         if(check_while_finished==0)
                         {
                         turnto(B);                          
                         redroom_dir=right;
                         }
                        pich_sakoo=0;
                        pich_dar=0; 

                        }
            }
        redroom_time=0;
       }
    }   
void wall_follow(void)
{
while(1)
 {
    if (UR< 50 ) go ( 200 ,255);
    else if (UR >50 && UR < 70)  go ( 255 ,200); 
    else go(500,500);
      if(SFL==0 || SFR==0 || victim==1 || check_obs==1)
   break;
 }
}
void vic(void)
{
int uuu;
signed int pitch_save;
lcd_clear();
lcd_puts("vic");
if(victim==1)
    {
    lcd_clear(); 
    lcd_puts("masdoom");
    move_arm(get);delay_ms(300);
    go(0,0);delay_ms(200);
    if(conductive==1){farz=resana;lcd_puts("resana");}
    else             {farz=naresana;}  
    pitch_save=pitch;
    if(victim==1)
        {   
            
            if      (farz==resana   &&   s_ball==0)  rotation_motor(1); 
            else if (farz==resana   &&   s_ball==1)  rotation_motor(2);  
            else if (farz==naresana &&   b_ball==0)  rotation_motor(3);  
            else                                     rotate(0);  
            go(-140,-140);delay_ms(300);
            move_arm(drop);go(0,0);
            if(victim_checked==1)
                {      
                    if(pitch>pitch_save+10 || pitch<pitch_save-10) move(front,8); 
                    xl(AL,xl_2,180);
                    xl(AR,1023-xl_2,180);
                    delay_ms(800);
                    if(check_obs==1)                                   
                        {
                        if     (farz==resana && s_ball==0){barband[1]=1;delay_ms(500);s_ball++; ball_num++;delay_ms(50);}
                        else if(farz==resana && s_ball==1){barband[2]=1;delay_ms(500);s_ball++; ball_num++;delay_ms(50);}
                        else if (farz==naresana)          {barband[3]=2;delay_ms(500);b_ball++; ball_num++;delay_ms(50);}

                        }
                    lcd_clear();
                    sprintf(text," s=%d   b=%d  ",s_ball,b_ball);
                    lcd_gotoxy(0,0);
                    lcd_puts(text);
                    sprintf(text," 1=%d 2=%d  3=%d  4=%d ",barband[0],barband[1],barband[2],barband[3]);
                    lcd_gotoxy(0,1);
                    lcd_puts(text);                   
                    move_arm(search);delay_ms(700);
                    lcd_clear();
                    lcd_puts("dare mikone");
                        
                if(VSM<=silver_voltage)
                       {move(back,20);
                               if(redroom_dir==right)
                                {
                                if(UR>65)
                                {move(right,T90R);}
                                else{move(left,T90L);}

                                if((ev_ball>0 && ball_num>=1)||(ball_num>=2));
                                else redroom_dir=left;
                                }
                            else                
                                {
                                if(UL>65){move(left,T90L);}
                                else {move(right,T90R);}
                                if((ev_ball>0 && ball_num>=1)||(ball_num>=2));
                                else redroom_dir=right;
                                }
                            }
                  
                }
            else{delay_ms(200);move_arm(search);delay_ms(200);} 
            

        go(sp,sp); 
        }
    else{delay_ms(200); move_arm(search);delay_ms(200); }
    correct=0;both_touched=0;
    }
}
void come_down(void)
{
lcd_clear();
lcd_puts("come down");
if(senscount_all>9)
    {
    move_arm(normal);delay_ms(400);
    move(back,30);
    if(UL<90)move(right,T90R/2.5);
    else if(UR<90)move(left,T90L/2.5);
    move(back,30);
    move_arm(search);  
    ax(13,ax_arm_2,500);
    delay_ms(2000);
    }

}
void check_while(void)
    {
    int save_ENC,x,i=0;
    check_while_finished=0;
    lcd_clear();
    lcd_puts("check while");

    TCNT1=0;
    while(TCNT1<=30)
        {
        if(victim==1)              
            {
            save_ENC=TCNT1;
            vic();
            go(sp,sp);
            move(front,T90R/1.5);
            TCNT1=save_ENC;
            check_while_finished=0;
            break;
            }
        else if(check_obs)                    
            {
            loop+=1;
            move(back,4);
            check_while_finished=0;
            break;
            }
        else if(SFL == 0|| SFR == 0)
           {
           if(!SFL)         first_touched=left;
           else if(!SFR)    first_touched=right;
           correction(front);
           if(correct==1)          //wall-deposit
               {
                correction(sides);
                if(side_check==1){correction(front);}
                lcd_clear();
                sprintf(text," VLF=%d",VLF);
                lcd_puts(text);

              if(VLF>102 && VLF<400)     //sakoo ok
                {
                chargoosh=0;
                vic();                
                lcd_clear();
                sprintf(text,"dis=%4d;sb:%d;evs:%d",VLF,s_ball,ev_s_ball);
                lcd_gotoxy(0,0);lcd_puts(text);
                sprintf(text,"bb=%d;evb:%d;bn:%d",b_ball,ev_b_ball,ball_num);
                lcd_gotoxy(0,1);lcd_puts(text);
                sprintf(text,"et=%4d;1:%d;2:%d;3:%d;4:%d",ev_ball,barband[0],barband[1],barband[2],barband[3]);
                lcd_gotoxy(0,2);lcd_puts(text);       
                if(VLF>102 && rescue_kit==1)
                 {
                 rotation_motor(0);
                 delay_ms(500);
                 move_basket(2);delay_ms(800);
                 move_basket(1);delay_ms(500);
                 rescue_kit=0;
                 }
                    
                if(VLF>102 && (s_ball>0  || (ev_s_ball>=2 && b_ball>=1)))    // deposit
                   {
                   found_dep+=1;
                   lcd_clear();
                    while(1)        //RESANA
                     {  
                        if(rotate(1)!=100)             
                            {
                            delay_ms(50);
                            ev_s_ball++;
                            s_ball--;
                            ball_num--;
                            barband[rotate(1)]=0;
                            delay_ms(500);
                            move_basket(2);delay_ms(800);
                            move_basket(1);delay_ms(500);
                            if(dooble==1){dooble=0;barband[rotate(1)]=0;s_ball--;ev_s_ball++;ball_num--;dooble=0;}

                            }
                        else if(rotate(1)==100){rotate(0);break;}
                     }
                   s_ball=0;            
                   if(ev_s_ball>=2) //NaRESANA
                     {
                         while(1)
                          {
                              if(rotate(2)!=100)
                                 {
                                    delay_ms(50);
                                    ev_b_ball++;
                                    b_ball--;
                                    ball_num--;
                                    barband[rotate(2)]=0; 
                                    move_basket(2);delay_ms(800);
                                    move_basket(1);delay_ms(500);
                                    if(dooble==1){dooble=0;barband[rotate(2)]=0;b_ball--;ev_b_ball++;ball_num--;}
                                 }
                              else {rotate(0);break;}
                          }
                     b_ball=0;                   
                     }
                   ev_ball=ev_s_ball+ev_b_ball;  
                   move(back,5);
                   go(0,0);              
                   if(ev_ball>=3) {delay_ms(500);get_out();}
                   }         
                if(VLF>102)
                 {
                 if(redroom_dir==left && first_touched==right)
                   {                        
                    turn2(left,70);
                    go(sp,sp);
                    for(i=0;i<=120;i++)
                       {
                       if(SFR==0)break;
                       if(VSM<=silver_voltage || color(right)==green || color(left)==green ) {move(back,30); break;}
                       vic();
                       }
                    turn2(left,38);
                    //redroom_dir=right;
                       
                   }    
                 else 
                   {
                    turn2(right,70);
                    go(sp,sp);
                    for(i=0;i<=120;i++)
                       {
                       if(SFL==0)break;
                       if(VSM<=silver_voltage || color(right)==green || color(left)==green ) {move(back,30); break;}
                       vic();
                       }
                    turn2(right,38);
                    //redroom_dir=left;  
                   } 
                 }    
                pich_sakoo=1;                                    
                }
              else                        //malesh be divar knj divar                 
                {
                    check_while_finished=1;
                    correction(sides);
                    move(back,6);
                    if(redroom_dir==right)
                        {
                        move(right,T90R);
                        move(back,4);
                        go(-sp,sp);
                        delay_ms(150);
                         go(0,0);
                        delay_ms(100);
                        malesh_chap=1;
                        }
                    else if(redroom_dir==left)
                        {
                        move(left,T90L);
                        move(back,4);
                        go(sp,-sp);
                        delay_ms(150);
                        go(0,0);
                        delay_ms(100);
                        malesh_rast=1;
                        }
                 }

              }         
           else                       //malesh be divar
             {
                    check_while_finished=1;
                    correction(sides);
                    move(back,6);
                    if(redroom_dir==right)
                        {
                        move(right,T90R);
                        move(back,4);//redroom_dir=left;
                        go(-sp,sp);
                        count(T90L/7);
                        //delay_ms(210);
                         go(0,0);
                        //correction(back);
                        delay_ms(100);

                        }
                    else if(redroom_dir==left)
                        {
                        move(left,T90L);
                        move(back,4);//redroom_dir=right;
                        go(sp,-sp); 
                        count(T90R/7);

                        //delay_ms(210);
                        go(0,0);
                        delay_ms(100);

                        //correction(back);



                        }
             }            
            check_while_finished=1;                   
            break;

           }
        else if(VSM<=silver_voltage || color(right)==green || color(left)==green )
            {
            move(back,20);
            if(redroom_dir==right)move(right,T90R*0.7);
            else                  move(left,T90L*0.7);
            break;
            }
        else check_while_finished=0;
        }
    }
int  rotate(int type)
    {
    int i,I;
    for(i=0;i<=3;i++)
        {
        if(barband[i]==type)
          {   
          I=i+1;
            if(barband[I]==type && type!=0)
            {dooble=1;rotation_motor(i+10);I=0;return i;}
            else  
            {rotation_motor(i);I=0;return i;}
               
          }
        }
    return 100;

    }
void silver(void)
{
int ttt;
lcd_clear();
lcd_puts("silver  ya  sabz");
if(VSM<=silver_voltage || color(right)==green || color(left)==green )
    {
    loop=0;
    move(back,50);
    if(redroom_dir==right)
        {
        if(s_ball>=2 || (ev_s_ball+ball_num>=3) )
         {        

         move(back,20);move(right,T90R*0.7);
          
         }
        else 
          {
             DN=0;DN=deg;calculate();
             turnto(R);
             move(left,T90L*0.2);
             if(pich_sakoo==1)                       {move(front,30);pich_sakoo=0;}
             else if (pich_sakoo==0 && pich_dar==1)  {move(front,9);pich_dar=0;}
             go(sp,sp);
             check_while();
             if(check_while_finished==0)
                 { 
                 turnto(B);
                 redroom_dir=left;
                 }         
          }
        }
    else                
        {
        pich_sakoo=0;     
        if(s_ball>=2 || (ev_s_ball+ball_num>=3) )
         {   
          move(back,20);move(left,T90L*0.7);
         }    
        else 
          {
             DN=0;DN=deg;calculate();
             turnto(L);
             move(right,T90R*0.2);
             if(pich_sakoo==1)                       {move(front,30);pich_sakoo=0;}
             else if (pich_sakoo==0 && pich_dar==1)  {move(front,9);pich_dar=0;}             
             go(sp,sp);
             check_while();
             if(check_while_finished==0)
                 { 
                 turnto(B);
                 redroom_dir=right;
                 }
          }
        }
        
    }
}
void get_out(void)
    {
    unsigned int i,exact,xxx=0;
    char check_dor=0,anjam=0;
    if(reset==0)
        {
        move_arm(search);
        move(back,20);
        go(sp,sp);count(16);     
        correction(front);
        move(back,5);
        turn2(left,75);
        go(sp,sp);
        for(i=0;i<=185;i++)
           {
           if(SFR==0)break;
           vic();
           }
        turn2(left,60);
        go(0,0);delay_ms(1000);
        }
        calculate();
        check_get_out=1;       
        while(1)
        {
            calculate();
            if(UR>300)
                { 
                go(sp,sp);
                count(18);
                turn2(right,90);
                go(sp,sp);
                while(1)
                    {
                    if(color(right)==green || color(left)==green) green_get_out();     
                    else if(VSM<=silver_voltage)
                        {
                          if (UL>=180) 
                           {
                           move(back,40);
                           move(left,T90L);
                           go(sp,sp);while(UR>150);
                           move(front,20);                     
                           }
                          else
                           {
                           move(back,40);   
                           turn2(left,175);
                           } 
                        break;
                        }
                    }
                }       
            else  if(victim) ev_zone();
            else if(SFR==0 || SFL==0)
                { 
                calculate();  
                correction(front);
                turnto(L);
                exact=deg;               
                }   
            else if (check_obs==1)
                { 
                calculate();
                move(back,10);
                 turn2(left,89);
                 go(sp,sp);
                while(UR<160 && xxx<250 ) xxx++;
                 go(0,0);
                 delay_ms(20);
                 move(front,15);                           
                 turn2(right,87);
                }
            if(color(right)==green || color(left)==green) green_get_out();               
            else if(VSM<=silver_voltage&&  check_obs==0 && SFR==1 && SFL==1 )
                       {
                       move(back,30);
                       turnto(L);
                       go(sp,sp);while(UR>200);
                       move(front,30);
                       }             
                
         
        }
    }
void green_get_out(void)
  {  int i;
    if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   turnto(0);
    if (deg>=45 && deg<135)   turnto(90);
    if (deg>=135 && deg<225)  turnto(180);
    if (deg>=225 && deg<=315) turnto(270);                                          
    
    go(sp,sp);count(22);                
    move_arm(normal);go(sp,sp);
    while(senscount_all==0);

  while(1)    
      {
       for(i=0;i<15;i++)  
        {
        color_detect();      
        line();  
        if(senscount_all==0)
            {
            t_gap++;
            if(t_gap>=gap_time_limit)
                gap(gap_cmp_en);
            }
        else if(senscount_all>0) t_gap=0;
        rampdown();
        rampup();     
        }
       if(UF<dis_obs){lcd_puts("ob");obstacle(obstacle_dir);}                   
      }
  }
void ev_zone(void)                   
{                                         
ball_num=0;
found_dep=0;
move(front,5);
delay_ms(1000);
move_arm(search);
delay_ms(1000);
rotation_motor(1);
if(VSM<=silver_voltage)move(front,45);
else                  move(front,35);
if(UR<UL) redroom_dir=left; 
else      redroom_dir=right; 
go(0,0);

if(VSM<=silver_voltage)move(front,15);
while(1)
    {
    sprintf(text,"dep=%d  time=%5d   ",found_dep,redroom_time);
    sprintf(text,"B=%d S=%d ES=%d EB=%d JAM=%d",b_ball,s_ball,ev_s_ball,ev_b_ball,ev_ball);
    lcd_gotoxy(0,2);lcd_puts(text);
    calculate();     
    if( ((UL>100 && malesh_rast==0) || (UR>100 && malesh_chap==0)) && pich_sakoo==0 && chargoosh==0 && loop<2) //Saf kardan go(sp,sp)
     {
        err2=0;
        er=posi-deg;
        err2=er;
        if(err2>180)                   err2=abs(err2-360);
        else if(err2<-180)             err2= err2+360;
        else if(err2<0 && err2 >=-180) err2=abs(err2);  
        if(er>0 && er<=180)       err2=-err2;
        if(er>0 && er>180);
        if(er<0 && er<=-180)      err2=-err2;
        if(er<0 && er>-180); 
        if(err2>45)            go(-sp,sp);     
        else if(err2<-45)      go(sp,-sp); 
        else go(sp-(err2*8),sp+(err2*8));
     }
    else go(sp,sp);
    //if(ev_ball>=3) {delay_ms(500);reset=1;get_out();}
    vic();
    contact();
    silver();
    redroom_time++;
    come_down();
    }                                         
}
void config(void)
    {
    DDRA=0b11000111;PORTA=0b00011000;
    DDRB=0b00000000;PORTB=0b11111110;      
    DDRC=0b00000000;PORTC=0b11000000;
    DDRD=0b00111000;PORTD=0b00000011;
    DDRE=0b00000000;PORTE=0b00000000;
    DDRF=0b00000000;PORTF=0b00000000;
    DDRG=0XFF;
    //TIMERS
                                                       
    TCCR1B=0x07;//ENC L
    TCCR2=0x07;//ENC R
    TCCR3B=0x01;//ULTRA                                                                 
    TIMSK=0x01;
    //USART:Baud Rate: 115000
    UCSR1A=0x00;
    UCSR1B=0x18;
    UCSR1C=0x06;
    UBRR1H=0x00;
    UBRR1L=0x05;   // USART1 Baud Rate: 115200(34)(16) //34 baraye ghabli bood
    sbi(UCSR1A,6); // SET_TXD1_FINISH; // Note. set 1, then 0 is read

    //ADC:
    ADMUX=ADC_VREF_TYPE & 0xff;
    ADCSRA=0x84;
    //LCD
    i2c_init();
    lcd_init(20);

    if(sp<150)
        {
        disable_SM=0;disable_SL1=0;disable_SL2=0;disable_SL3=0;disable_SL4=0;disable_SL5=0;disable_SL7=0;disable_SR1=0;disable_SR2=0;disable_SR3=0;disable_SR4=0;disable_SR5=0;disable_SR7=0;
        T90L=42;T90R=40;   
        gap_time_limit=40;
        dis_obs=71;
        sp=254;
        rescue_kit=0;
        x_ball=5;
        s_ball=0;
        b_ball=0;
        ball_num=0;
        ev_s_ball=0;
        ev_b_ball=0;
        rad_round=90;
        //red_rcal=0;blue_rcal=0;green_rcal=0;amb_rcal=0;
        //red_lcal=0;blue_lcal=0;green_lcal=0;amb_lcal=0;
        value_r=13;
        value_l=19;
        gap_time_limit=21;
        gap_cmp_en=1;
        silver_voltage=0.6;
        dif_silver=10;
        deg_arm=820;
        deg_basket=500;
        deg_xl=500;        
        basket_1=500;//normal basket
        basket_2=230;//sheading basket
        ax_arm_1=830;//normal
        ax_arm_2=220;//get                             
        ax_arm_3=830;//drop
        xl_1=360;
        xl_2=490;xl_4=160;
        xl_3=360;       
        xpos=500;xpos1=500;
        xpos2=500;
        halat_mane=0;
        direction_deg=280;
        ev_out_deg=43;
        ev_ball=0;
        //DN=DN_set;
        if(redroom_dir==left)redroom_dir=right;
        else redroom_dir=left;
        //DN=0;DN=deg;//DS=DN+90;DE=DN+180;DW=DN+270;
        found_deg=0;turnedtodeg=1;found_dep=0;
        ev_s_ball=0;ev_b_ball=0;x_s_ball=3;
        }

    barband[0]=0;barband[1]=0;barband[2]=0;barband[3]=0;
    go(0,0);
    move_basket(1);
    delay_ms(15);
    move_arm(normal);

    delay_ms(300);

    xl_430_torque(RB,0);//delay_us(200);
    xl_430_torque(RF,0);
    xl_430_dir(RB,1);//delay_us(200);
    xl_430_dir(RF,1);

    xl_430_torque(RF,1);
    xl_430_torque(RB,1);
    xl_430_torque(LF,1);
    xl_430_torque(LB,1);delay_ms(100);
    }
#pragma used-
void main(void)
    {
    char page=1,last_page=5;
    unsigned char a;
    int time_setup=0,i,arr,all;  
    int x,vl_dis;                
    config();
    sum_x=0;    
    while(SFR && SFL)                      
        {
        time_setup++;
        if(SBR)
            {
            if(redroom_dir==left)redroom_dir=right;
            else redroom_dir=left;
            found_deg=0;turnedtodeg=1;found_dep=0;
            ev_s_ball=0;ev_b_ball=0;x_s_ball=3;
            barband[0]=0;barband[1]=0;barband[2]=0;barband[3]=0;
            }
        if(next_page==0)
            {
            while(next_page==0);
            page++;
            if (page>last_page) page=1;
            lcd_clear();
            }
        if(previuse_page==0)
            {
            while(previuse_page==0);
            page--;
            if (page<1) page=last_page;
            lcd_clear();
            }
        if (page==1)
            {
            lcd_gotoxy(0,0);
            lcd_puts("-> Start      ");
            lcd_gotoxy(0,1);
            lcd_puts("   Sensor Test   ");
            lcd_gotoxy(0,2);
            lcd_puts("   Robot Setup    ");
            lcd_gotoxy(0,3);
            lcd_puts("   dynamixel setup");
            delay_ms(10);

//            if(time_setup>=70)
//                {
//                lcd_clear();
//                lcd_puts("   Ya mahdi  ");
//                delay_ms(100);
//                lcd_clear();
//                sprintf(text,"UF=  %d  ",UF);
//                lcd_gotoxy(0,1);lcd_puts(text);
//                delay_ms(150);lcd_clear();
//                break;
//                }
            }
        else if(page==2)
            {
            lcd_gotoxy(0,0);
            lcd_puts("   Start      ");
            lcd_gotoxy(0,1);
            lcd_puts("-> Sensor Test   ");
            lcd_gotoxy(0,2);
            lcd_puts("   Robot Setup    ");
            lcd_gotoxy(0,3);
            lcd_puts("   dynamixel setup");

            if (enter==0)
                {               
                while (enter==0);
                sensor_setup();
                }
            }
        else if (page==3)
            {
            lcd_gotoxy(0,0);
            lcd_puts("   Start      ");
            lcd_gotoxy(0,1);
            lcd_puts("   Sensor Test   ");
            lcd_gotoxy(0,2);
            lcd_puts("-> Robot Setup    ");
            lcd_gotoxy(0,3);
            lcd_puts("   dynamixel setup");

            if (enter==0)
                {
                while (enter==0);
                robot_setup();
                }
            }
        else if (page==4)
            {
            lcd_gotoxy(0,0);
            lcd_puts("   Start      ");
            lcd_gotoxy(0,1);
            lcd_puts("   Sensor Test   ");
            lcd_gotoxy(0,2);
            lcd_puts("   Robot Setup    ");
            lcd_gotoxy(0,3);
            lcd_puts(" ->dynamixel setup");

            if (enter==0)
                {
                while (enter==0);
                dynamixel_setup();
                }
            }
        else if (page==5)
            {
            lcd_clear();
            lcd_gotoxy(0,0);
            lcd_puts(" ->EEPROM INIT    ");            
            if (enter==0)
                { 
                 disable_SM=0;disable_SL1=0;disable_SL2=0;disable_SL3=0;disable_SL4=0;disable_SL5=0;disable_SL7=0;disable_SR1=0;disable_SR2=0;disable_SR3=0;disable_SR4=0;disable_SR5=0;disable_SR7=0;
                 found_deg=0;found_dep=0;
                ev_s_ball=0;ev_b_ball=0;
                }
            }
        } 
    lcd_clear();
    lcd_puts("   Ya mahdi  ");
    while(1) 
       { 
        for(i=0;i<15;i++)  
            {
            //rescuekit();
            color_detect();      
            line();  
            if(VSM<= silver_voltage) 
                {   
                if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   turnto(0);
                if (deg>=45 && deg<135)   turnto(90);
                if (deg>=135 && deg<225)  turnto(180);
                if (deg>=225 && deg<=315) turnto(270);       
                    
                    DN=deg;  
                    ev_zone();     
                }
            if(senscount_all==0)
                {
                t_gap++;
                if(t_gap>=gap_time_limit)
                    gap(gap_cmp_en);
                }
            else if(senscount_all>0) t_gap=0;
            rampdown();
            rampup();     
            }
        if(UF<dis_obs){lcd_puts("ob");obstacle(obstacle_dir);}    
       }    
    }

