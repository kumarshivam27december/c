// #include <iostream>
// #include <queue>
// #include <vector>
// #include <string>
// #include <string.h>
// #include <cstring>
// #include <stack>
// #include <math.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;
int main(){


    HANDLE console_color; 
    
    console_color = GetStdHandle( STD_OUTPUT_HANDLE); 


    SetConsoleTextAttribute(console_color, 1); 


    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;


    SetConsoleTextAttribute(console_color, 2); 
    cout<<"---------------------------"<<endl;
    cout<<"WELCOME TO A WONDERFUL GAME"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"WHO WANTS TO BE MILLIONARE "<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"---------------------------"<<endl;

    SetConsoleTextAttribute(console_color, 3); 
    cout<<" You need to know the rule "<<endl;
    cout<<"First Rule :"<<endl;
    cout<<"You must follow all the rule strictly"<<endl;
    cout<<"Second rule:"<<endl;
    cout<<"You have to give answer in limited time"<<"\n";
    cout<<"Third rule: "<<endl;
    cout<<"Any choosing of another options will be treated as malpractice and you will be exiting the game\n ";

    cout<<"You will be given 7 questions and you have to answer it"<<"\n";
    cout<<"1qn->$1000\n2qn->$5000\n3qn->$20,000\n4qn->$50,000\n5qn->$100,000\n6qn->$500,000\n7qn->1,000,000\n";
    cout<<endl;
    cout<<"You have option to leave the game in the middle on question 3rd,5th and 6th"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"---------------------------"<<endl;
  

    SetConsoleTextAttribute(console_color, 4); 


    cout<<"You will be given assistance or lifeline"<<"\n";
    cout<<"1-> 50:50 (Two of the options will be eliminated)"<<endl; 
    cout<<"2->phone your friend(you can ask your friend answer)"<<endl;
    cout<<"3->replace the question(Another question will be provided)"<<endl;
    cout<<"4->Exit the game with 3/4 of amount(75 % of the amount)"<<endl;

   int ff = 0;
   int pyf = 0;
   int rq=0;

    SetConsoleTextAttribute(console_color, 5); 
    cout<<"---------------------------"<<endl;
    cout<<"---------------------------"<<endl;

    cout<<"LETS BEGIN THE GAME"<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    SetConsoleTextAttribute(console_color, 6); 
    cout<<"Do you want start the game \nif yes press Y or any other key to exit\n";
    char start;cin>>start;
    if(start=='Y' || start=='y'){
         SetConsoleTextAttribute(console_color, 7); 
         cout<<"Starting the game\n";
         cout<<"LEVEL 1\n";
         int level = 1;
         int initial_amount = 0;
         cout<<"Question no-1"<<endl; 
         cout<<"who was the founder of c language ?\n";
         cout<<"A)Dennis Ritchie\n";
         cout<<"B)Bill gates\n";
         cout<<"C)Guido van Rossum\n";
         cout<<"D)Sam Altman\n";
         cout<<"choose your answer (A,B,C,D)\n";
         cout<<"IF YOU WANT HELP PRESS H\n";

         char qn1;cin>>qn1;

         
         if(qn1 == 'A' || qn1 == 'a'){
         SetConsoleTextAttribute(console_color, 10); 

            cout<<"You are correct\n";
            initial_amount = 1000;
            cout<<"You have won "<<initial_amount<<endl;
            cout<<"LEVEL 2"<<endl;
            cout<<"Congrats once again\n";

            cout<<"So, here we go with round 2\n";
            cout<<"What is the curreny of china?\n";
            cout<<"A)Yen\n";
            cout<<"B)Chinese dollar\n";
            cout<<"C)Ruble\n";
            cout<<"D)Yuan\n";
            cout<<"choose your answer (A,B,C,D)\n";
            cout<<"IF YOU WANT HELP PRESS H\n";
            char f;cin>>f;
            if(f=='D'||f=='d'){

               SetConsoleTextAttribute(console_color, 5); 

               cout<<"You are correct\n";
               cout<<"You have won $5000 "<<endl;
               cout<<"LEVEL 3"<<endl;
               cout<<"Congrats once again\n";

               cout<<"So, here we go with round 3\n";
               cout<<"In was the next pm of india after lal bahdur shashtri was assassined in Taskent uzbekistan?\n";
               cout<<"A)sonia gandhi\n";
               cout<<"B)rajiv gandhi\n";
               cout<<"C)rahul gandhi\n";
               cout<<"D)indira gandhi\n";
               cout<<"choose your answer (A,B,C,D)\n";
               cout<<"IF YOU WANT HELP PRESS H\n";
               char an;cin>>an;
               if( an =='D'||an=='d'){
                   SetConsoleTextAttribute(console_color, 12); 

                  cout<<"You are correct \n You have won $20,000\n";
                  cout<<"If you want to continue this game press 'Y' or 'y'\n else select any other key to exit the game\n";
                  char m;cin>>m;
                  if(m=='Y'||m=='y'){
                     SetConsoleTextAttribute(console_color, 2);
                     cout<<"Welcome to the LEVEL 4"<<endl;
                     cout<<"What is the largest organ in the human body?\nA. Liver\nB. Heart\nC. Skin\nD. Brain\n";
                     char ans1 ;cin>>ans1;
                     if(ans1=='c'||ans1=='C'){
                        SetConsoleTextAttribute(console_color, 13); 

                        cout<<"You are correct \n";
                        cout<<"You have won $50,000\n";
                        cout<<"Do you want to continue press 'Y' or 'y' else any key to exit\n";
                        char exit1;cin>>exit1;
                        if(exit1=='Y' || exit1=='y'){
                           SetConsoleTextAttribute(console_color, 14); 

                           cout<<"So , you wanted to continue this game\n";
                           cout<<"if, so then continue this \n";
                           cout<<"Level  5\n";
                           cout<<"Here is the next question \n";
                           cout<<"Which programming language is used for creating dynamic web pages?\nA. Java\nB. Python\nC. JavaScript\nD. C++\n";
                           char ans2;cin>>ans2;
                           if(ans2=='c' ||ans2=='C'){
                              SetConsoleTextAttribute(console_color, 6); 

                              cout<<"Hurray! you are correct\n ";
                              cout<<"You have won $100,000\n";
                              cout<<"You are playing really well \nif you want to continue the game press y or Y else press any other key to exit the game\n";
                              char exit2;cin>>exit2;
                              if(exit2=='Y'||exit2=='y'){
                                 
                                 cout<<"You have to continue the game\n";
                                 cout<<"Level 6\n";
                                 SetConsoleTextAttribute(console_color, 2);
                                 cout<<"Here is the next question \n";
                                 cout<<"Who is known as the 'Iron Man of India?\nA. Jawaharlal Nehru\nB. Sardar Vallabhbhai Patel\nC. Subhas Chandra Bose\nD. Mahatma Gandhi\n";
                                 char ans3;cin>>ans3;
                                 if (ans3=='B' ||ans3=='b')
                                 {
                                    cout<<"You are correct\n";
                                    cout<<"Congrats you have won $500,000\n";
                                    cout<<"You are doing preety well \n";
                                    cout<<"Press Y or y to continue or any other key to exit\n";
                                    char exit3;
                                    cin>>exit3;
                                    if(exit3=='Y'||exit3=='y'){
                                       cout<<"So , you are ready for the last level\n ";
                                       cout<<"Again if  you loose this qn you will loose all the money that you have won till her\n";
                                       cout<<"Are you sure  to take the risk\n";
                                       cout<<"Press p or P if you are ready\n";
                                       cout<<"else press any other key to exit the game\n";
                                       char exit4;cin>>exit4;
                                       if(exit4=='P' ||exit4=='p'){
                                          cout<<"As you are sure about the game\n";
                                          cout<<"LEVEL 7\n";
                                          cout<<"So here is the question\n";
                                          cout<<"Which organelle is responsible for producing energy in a cell?\nA. Nucleus\nB. Ribosome\nC. Mitochondrion\nD. Endoplasmic Reticulum";
                                          cout<<"\nThis is really a tough one\n";
                                          cout<<"press H for help\n";

                                          char ans4;cin>>ans4;
                                          if(ans4=='c' ||ans4=='C'){
                                              cout<<"Wooooooooooo ! you are correct\n";
                                              cout<<"Thats is an absolutely correct answer\n";
                                              cout<<"And you have won a million dollar\n";
                                              cout<<"Congrats you have nailed it\n";
                                              cout<<"Thanks for joining see you again\n";
                                              cout<<"Exiting the game";
                                              return 0;
                                          }else if(ans4=='H' ||ans4=='h'){

                                             cout<<"So you need help alright";
                                             cout<<"Choose\n1-> for 50:50\n2-> for phone your friend\n3->for question swap\n";
                                             char lifeline2;cin>>lifeline2;
                                             if (lifeline2=='1')
                                             {
                                               if (ff>=1)
                                                {
                                                   cout<<"you have already used this lifeline";
                                                }else{
                                                   cout<<"The incorrect options are A and B";
                                                   cout<<"So continue with your answer";
                                                   char lifeline3;cin>>lifeline3;
                                                   if (lifeline3=='c'||lifeline3=='C')
                                                   {
                                                     cout<<"Alright you are absolutely correct\n";
                                                     cout<<"c is the correct option\n";
                                                     cout<<"You have won $1,000,000\n";
                                                     cout<<"You have successfully completed whole of the game\n";
                                                     cout<<"congrats once again\n"<<endl;
                                                     cout<<"Amount will be deposited to your account\n";
                                                     cout<<"See you next time\n";
                                                     cout<<"completing the game\n";
                                                     return 0;
                                                   }else{
                                                      cout<<"It seems you were in hurry\n";
                                                      cout<<"You are wrong\n";
                                                      cout<<"The correct option was wrong\n";
                                                      cout<<"The answer was Mitochondrion\n";
                                                      cout<<"Better luck next time\n";
                                                      return 0;
                                                   }
                                                   
                                                }
                                             }
                                                                               

                                          }else{
                                                cout<<"you are wrong";
                                                cout<<"Well played";
                                                cout<<"better luck next time";
                                                cout<<"Exiting the game";
                                                return 0;                                        
                                          }
                                       }
                                    }
                                 }
                                 

                                 //continue the game

                              }else{
                                          SetConsoleTextAttribute(console_color, 15);
                                          cout<<"So you wanted to quiet the game \nso the total amount you won is $100,000\n";
                                          cout<<"Hope you enjoyed the game\n";
                                          cout<<"Thanks for all of your love and support\n";
                                          return 0;
                              }
                           }


                        }else{
                           SetConsoleTextAttribute(console_color, 15);
                           cout<<"So you wanted to quiet the game \nso the total amount you won is $50,000\n";
                           cout<<"Hope you enjoyed the game\n";
                           cout<<"Thanks for all of your love and support\n";
                           return 0;
                        }
                     }

                  }else{
                     SetConsoleTextAttribute(console_color, 16);
                     cout<<"So you wanted to quiet the game \nso the total amount you won is $20,000\n";
                     cout<<"Hope you enjoyed the game\n";
                     cout<<"Thanks for all of your love and support\n";
                     return 0;
                  }
               }

               //code here
            }else if(f=='H'||f=='h'){
                  //applying switch case here 
                  SetConsoleTextAttribute(console_color, 17);
                   cout<<"So you need help\n";
                   cout<<"Alright! \n";
                   cout<<"Choose\n1-> for 50:50\n2-> for phone your friend\n3->for question swap\n";
                   int lifeline ;cin>>lifeline;
                  switch (lifeline)
                  {
                     case 1:
                     cout<<"The incorrect options are \nRubles \nchinese dollar\n";
                     cout<<"So whats is your answer again\n";
                     char sans1;cin>>sans1;
                     if (sans1=='D' ||sans1=='d')
                     {
                        cout<<"you are correct\n";
                        cout<<"You have won this level- 2\n";
                        cout<<"You have $5000\n";
                        cout<<"Do you want to go further if yes type Y or y\n";
                        cout<<"Else any other key\n";
                        char sans2;cin>>sans2;
                        if(sans2=='Y' || sans2=='y'){
                           cout<<"As you have chosed to continue the game\n";
                           cout<<"So welcome to the level 3 of this WONDERFUL game \n";
                           cout<<"This question worth $20,000\n";
                           cout<<"Which gas do plants primarily absorb during photosynthesis?\nA. Oxygen\nB. Carbon Dioxide\nC. Nitrogen\nD. Hydrogen\n";
                           char sans3;cin>>sans3;
                           if(sans3=='B' ||sans3=='b'){
                              cout<<"Congrats you have won this level\n";
                              cout<<"You have won $20,000\n";
                              char sans4;cin>>sans4;
                              cout<<"If you want to continue please press Y or y else any other key to quit the game\n";
                              if (sans4=='Y' ||sans4=='y')
                              {
                                 cout<<"As you have chosed to continue the game\n";
                                 cout<<"So welcome to the level 4 of this WONDERFUL game \n";
                                 cout<<"This question worth $50,000\n";
                                 cout<<"Which ocean is the largest by surface area?\nA. Atlantic Ocean\nB. Indian Ocean\nC. Southern Ocean\nD. Pacific Ocean\n";

                                 char sans5;cin>>sans5;
                                 if (sans5=='D' ||sans5=='d')
                                 {
                                    cout<<"Correct\n";
                                    cout<<"You have won $50,000\n";
                                    cout<<"You have completed Level 4 successfully\n";
                                    cout<<"Do you want to go further if yes type Y or y\n";
                                    cout<<"Else any other key\n";

                                    char sans6;cin>>sans6;
                                    if (sans6=='Y' ||sans6=='y')
                                    {
                                       cout<<"As you have opted for continuation\n";
                                       cout<<"Welcome to level 5\n";
                                       cout<<"This next question worth $100,000\n";
                                       cout<<"Play with care\n";
                                       cout<<"In which century did the Industrial Revolution begin?\nA. 17th\nB. 18th\nC. 19th\nD. 20th\n";
                                       char sans7;cin>>sans7;
                                       if (sans7 == 'B' ||sans7 == 'b')
                                       {
                                             cout<<"Correct\n";
                                             cout<<"You have won $100,000\n";
                                             cout<<"You have completed Level 5 successfully\n";
                                             cout<<"Do you want to go further if yes type Y or y\n";
                                             cout<<"Else any other key\n";
                                             char sans8;cin>>sans8;
                                             if (sans8 == 'Y' ||sans8=='y')
                                             {
                                                cout<<"As you have opted for continuation\n";
                                                cout<<"Welcome to level 6\n";
                                                cout<<"This next question worth $500,000\n";
                                                cout<<"Play with care\n";
                                                cout<<"Which war is often referred to as the 'War of Independence' in the United States?\nA. World War I\nB. American Civil War\nC. American Revolutionary War\nD. Vietnam War\n";
                                                char sans9;cin>>sans9;
                                                if (sans9=='C'||sans9=='c')
                                                {
                                                   cout<<"Correct\n";
                                                   cout<<"You have won $500,000\n";
                                                   cout<<"You have completed Level 6 successfully\n";
                                                   cout<<"Do you want to go further if yes type Y or y\n";
                                                   cout<<"Else any other key\n";
                                                   char sans10;cin>>sans10;
                                                   if (sans10=='Y' || sans10=='y')
                                                   {
                                                      cout<<"As you have opted for continuation\n";
                                                      cout<<"Welcome to level 7 and the final level\n";
                                                      cout<<"This next question worth $1,000,000\n";
                                                      cout<<"Play with care\n";
                                                      cout<<"Who was the famous queen of ancient Egypt known for her beauty and intelligence?\nA. Cleopatra\nB. Nefertiti\nC. Hatshepsut\nD. Isis";
                                                      char sans11;cin>>sans11;
                                                      if (sans11=='A' ||sans11=='a')
                                                      {
                                                         cout<<"Wooooooooooo ! you are correct\n";
                                                         cout<<"Thats is an absolutely correct answer\n";
                                                         cout<<"And you have won a million dollar\n";
                                                         cout<<"Congrats you have nailed it\n";
                                                         cout<<"Thanks for joining see you again\n";
                                                         cout<<"Exiting the game";
                                                         return 0;
                                                      }else{
                                                         cout<<"You missed it\n";
                                                         cout<<"the correct answer was (A) Cleopatra\n";
                                                         cout<<"Better luck next time\n";
                                                         cout<<"Exiting the game\n";
                                                         return 0;
                                                      }
                                                      
                                                   }else{
                                                   cout<<"As you have opted to quit the game\n";
                                                   cout<<"The total amount you have won is $500,000\n";
                                                   cout<<"you can take that with you\n";
                                                   cout<<"Thanks for the your time in this game\n";
                                                   cout<<"Exiting the game\n";
                                                   return 0;
                                                   }
                                                   
                                                }
                                                

                                             }else{
                                                   cout<<"As you have opted to quit the game\n";
                                                   cout<<"Thanks for the your time in this game\n";
                                                   cout<<"Exiting the game\n";
                                                   return 0;
                                             }
                                             
                                       }else{
                                          cout<<"the answer was (b) 18th century\n";
                                          cout<<"better luck next time\n";
                                          cout<<"Exiting the game\n";
                                          return 0;
                                       }
                                       
                                    }else{
                                       cout<<"As you have opted to quit the game\n";
                                       cout<<"Thanks for the your time in this game\n";
                                       cout<<"Exiting the game\n";
                                       return 0;
                                    }
                                    
                                 }else{
                                       cout<<"the answer was (D) Pacific Ocean\n";
                                       cout<<"better luck next time\n";
                                       cout<<"Exiting the game\n";
                                       return 0;
                                 }
                                 
                              }else{
                                    cout<<"As you have opted to quit the game\n";
                                    cout<<"Thanks for the your time in this game\n";
                                    cout<<"Exiting the game\n";
                                    return 0;
                              }
                              
                           }else{
                                 cout<<"the answer was (B) Carbon dioxide\n";
                                 cout<<"better luck next time\n";
                                 cout<<"Exiting the game\n";
                                 return 0;
                           }
                        }else
                        {
                           cout<<"As you have opted to quit the game\n";
                           cout<<"Thanks for the your time in this game\n";
                           cout<<"Exiting the game\n";
                           return 0;
                        }
                        
                     }
                     
                     ff++;
                     break;

                  case 2:
                     cout<<"The answer a/c to your friend is \nD)Yuan\n";
                     pyf++;
                     break;
                  case 3:
                     cout<<"replacing the question\n";
                     SetConsoleTextAttribute(console_color, 18);
                     rq++;
                     cout<<"which fish does not lay eggs?\n";
                     cout<<"A)gold fish\n";
                     cout<<"B)dolphin\n";
                     cout<<"C)shark\n";
                     cout<<"D)tuna fish\n";
                     cout<<"choose your answer (A,B,C,D)\n";

                     char k;cin>>k;
                     if(k=='B' || k=='b'){
                        SetConsoleTextAttribute(console_color, 5);
                        cout<<"Correct you can go head"<<endl;
                        initial_amount = 5000;
                        cout<<"You have won "<<initial_amount<<endl;


                        cout<<"LEVEL 3"<<endl;
                        cout<<"Congrats once again"<<endl;
                        cout<<"So the next question is\n";
                        cout<<"Who was the famous queen of ancient Egypt known for her beauty and intelligence?\nA. Cleopatra\nB. Nefertiti\nC. Hatshepsut\nD. Isis\n";
                        char ans;cin>>ans;
                        if(ans=='A'||ans =='a'){
                           SetConsoleTextAttribute(console_color, 6);
                           cout<<"You are correct\n";
                           initial_amount = 1000;
                           cout<<"You have won "<<initial_amount<<endl;
                           cout<<"LEVEL 2"<<endl;
                           cout<<"Congrats once again\n";
                        }
                        //continue here
                        //add questions answer




                     }else{
                        cout<<"Oooo ! you are wrong !"<<endl;
                        cout<<"Your total amount is $0"<<endl;
                        cout<<"Exiting the game"<<endl;
                        return 0;
                     }
                     break;
                  
                     default:
                        cout<<"You have choosen the wrong option\n";
                        cout<<"Any such things could be appear to us as malpractise\n";
                        cout<<"Exiting the game\n";
                        return 0;
                        break;
                  }


            }else{
                  SetConsoleTextAttribute(console_color, 4);
                  cout<<"Oooo ! you are wrong !"<<endl;
                  cout<<"The correct option was D Yuan is the currency of china\n";
                  cout<<"Your total amount is $0"<<endl;
                  cout<<"Thanks for the game \nMeet you in the next game\n";
                  cout<<"Exiting the game"<<endl;
                  return 0;

            }
            

            
         }else if(qn1 == 'H' || qn1 == 'h'){
            SetConsoleTextAttribute(console_color, 3);
            cout<<"So you need help\n";
            cout<<"Alright! \n";
            cout<<"Choose\n1-> for 50:50\n2-> for phone your friend\n3->for question swap\n";
            int lifeline ;cin>>lifeline;
            switch (lifeline)
            {
            case 1:
               cout<<"The incorrect options are \nBill gates\nSam Altman\n";
               char firstlifelineanswer;cin>>firstlifelineanswer;
               if (firstlifelineanswer=='a' ||firstlifelineanswer=='A')
               {
                  cout<<"You are correct\n";
                  cout<<"You have won $1000\n";
                  cout<<"Level 2\n";


               }
               
               break;

            case 2:
               cout<<"The answer a/c to your friend is \nA)Dennis Ritchie\n";
               cout<<"Do you want to go with friend";
               cout<<"If yes press A or a else choose your option";
               char ansh1 ;cin>>ansh1;
               if (ansh1=='A' ||ansh1=='a')
               {
                  cout<<"You are correct\nYou have won";
                  cout<<"Congrats once again\n";
                  cout<<"So welcome to level 2";
               }
               


               break;
            case 3:
               cout<<"replacing the question\n";
               cout<<"who was the founder of window operating system ?\n";
               cout<<"A)Dennis Ritchie\n";
               cout<<"B)Bill gates\n";
               cout<<"C)Guido van Rossum\n";
               cout<<"D)Sam Altman\n";
               cout<<"choose your answer (A,B,C,D)\n";

               char k;cin>>k;
               if(k=='B' || k=='b'){
                  cout<<"Correct you can go head"<<endl;
                  initial_amount = 1000;
                  cout<<"You have won "<<initial_amount<<endl;


                  cout<<"LEVEL 2"<<endl;
                  cout<<"Congrats once again"<<endl;
                 

                  cout<<"So, here we go with round 2\n";
                  cout<<"What is the curreny of china?\n";
                  cout<<"A)Yen\n";
                  cout<<"B)Chinese dollar\n";
                  cout<<"C)Ruble\n";
                  cout<<"D)Yuan\n";
                  cout<<"choose your answer (A,B,C,D)\n";
                  cout<<"IF YOU WANT HELP PRESS H\n";

                  char ans12;cin>>ans12;
                  if(ans12=='d'||ans12=='D'){
                     cout<<"Hurray! you are correct";
                     initial_amount = 5000;
                     cout<<"You have won $ "<<initial_amount<<endl;
                     cout<<"LEVEL 3"<<endl;
                     cout<<"So the next question worth $20,000\n play with caution";
                     cout<<"So here is the next question\n";
                     cout<<"Which river is considered the holiest in Hinduism?\nA. Ganges\nB. Yamuna\nC. Brahmaputra \nD. Godavari ";
                     char anslevel3 ;cin>>anslevel3;
                     cout<<"I don't think you will require help for this questions";
                     cout<<"But still if you need help press h or H\n";
                     if (anslevel3=='A' || anslevel3=='a')
                     {
                        cout<<"Yes  you are correct\n the correct option is a";
                        cout<<"You have won $20,000";
                        cout<<"press Y or y to continue the games else any other key to exit the game\n";
                        char continuing1 ;cin>>continuing1;
                        if (continuing1=='Y' ||continuing1=='y')
                        {
                           cout<<"Procedding the game\n";
                           cout<<"LEVEL 4";
                           cout<<"So the next question worth $50,000 is here on your screen\n";
                           //continuing the game
                           cout<<"Which mountain range separates Europe from Asia?\nA. Rocky Mountains\nB. Himalayas\nC. Ural Mountains\nD. Alps\n";
                           char anslevel4;cin>>anslevel4;
                           if (anslevel4=='c' ||anslevel4=='C')
                           {
                              cout<<"Hurray! you are right\n";
                              cout<<"You have won $50,000\n";
                              cout<<"So,do you want to quite the game\nor continue\n";
                              cout<<"press y or Y to continue the game\n alse any other key to exit the game\n";
                              char exit6;cin>>exit6;
                              if (exit6=='Y' ||exit6=='y')
                              {
                                 cout<<"So you opted to continue the game\n";
                                 cout<<"LEVEL 5";
                                 cout<<"So the next question worth $100,000 is here on your screen\n";

                                 //continue the questions here
                                 cout<<"What does VPN stand for in the context of computer networks?\nA. Virtual Private Network\nB. Very Personal Network\nC. Visual Processing Node\nD. Voice and Phone Network";
                                 cout<<"press h or H"<<endl;
                                 char anslevel5;cin>>anslevel5;
                                 if (anslevel5=='A' ||anslevel5=='a')
                                 {
                                    cout<<"Yes , you are correct\n";
                                    cout<<"congrats! ";
                                    cout<<"You have won $100,000";
                                 }else if(anslevel5=='h' ||anslevel5=='H'){
                                    cout<<"You need help\n";
                                    cout<<"alright then\n";
                                    //continue here
                                 }else{
                                    cout<<"Oooo you are wrong\n";
                                    cout<<"The correct option was A> Virtual Private Network\n";
                                    cout<<"Better luck next time\n";
                                    cout<<"Exiting the game\n";
                                    return 0;
                                 }
                                 

                              }
                              else{
                                 cout<<"So you opted to exit the game\n";
                                 cout<<"See you soon in the next game\n";
                                 cout<<"Exiting the game\n";
                                 return 0;
                              }           
                           }
                           
                           







                        }else{
                           cout<<"Now so you want to exit the game";
                           cout<<"Meet you soon in the next game\n";
                           cout<<"Exiting the game\n";
                           return 0;
                        }
                        
                     }
                     else if (anslevel3=='H' ||anslevel3=='h')
                     {
                        cout<<"You want help alright";
                        cout<<"Since you have already used question swap help";
                        cout<<"The only option left are phone your friend and 50-50";
                        cout<<"press p or P for phone your friend helpline OR press f or F for 50-50 options\n";
                        char optionlevel3;cin>>optionlevel3;
                        
                        if(optionlevel3=='p' ||optionlevel3=='P'){
                           if (pyf>=1)
                           {
                              cout<<"sorry my friend, you have already used this option\n";
                              cout<<"You are not allowed to use this lifeline\n";
                              cout<<"Now you are left with no other option rather you have 50-50\n";
                              cout<<"press f or F for 50-50 options or else you can choose as your wish\n";
                              char ffo;cin>>ffo;
                              if (ffo=='f' ||ffo == 'F')
                              {
                                 cout<<"You want this 50-50 lifeline\n";
                                 cout<<"So the incorrect options are c and d\n";
                                 char newans1;cin>>newans1;
                                 if (newans1=='A' ||newans1=='a')
                                 {
                                    cout<<"Hurray! you got this right this time\n";
                                    cout<<"So do you really want to continue the game\n";
                                    cout<<"If yes press y or Y\n";
                                    cout<<"press any another key to exit\n";
                                    char stupidperson1;cin>>stupidperson1;
                                    if(stupidperson1=='Y'||stupidperson1=='y'){
                                       cout<<"You want to continue the game\n";
                                       cout<<"Alright then\n";
                                       cout<<"Level 3\n";
                                       cout<<"Which of the following is an example of a social media platform?\nA. Microsoft Excel\nB. Instagram\nC. Adobe Photoshop\nD. Google Chrome";
                                       cout<<"You have no lifeline left\n";
                                       cout<<"please play wisely\n";
                                       char stupidperson2;cin>>stupidperson2;
                                       if (stupidperson2=='B' ||stupidperson2=='b')
                                       {
                                         cout<<"Correct you are right\n";
                                         cout<<"You have won $20,000\n";
                                         cout<<"Do you want to quit the game\n";
                                         cout<<"press c or C to continue or any other key to exit\n";
                                         char stupidperson3;cin>>stupidperson3;
                                         if(stupidperson3=='c' ||stupidperson3=='C'){
                                          cout<<"You want to continue the game\n";
                                          cout<<"Alright then\n";
                                          cout<<"Level 4\n";
                                          cout<<"You have no lifeline left\n";
                                          cout<<"please play wisely\n";
                                          cout<<"Who was the famous playwright known for works like 'Romeo and Juliet' and 'Hamlet'?\nA. William Wordsworth\nB. William Shakespeare\nC. Jane Austen\nD. Charles Dickens\n";
                                          char stupidperson4;cin>>stupidperson4;
                                          if(stupidperson4=='B' ||stupidperson1=='b'){                                             
                                             cout<<"Correct you are right\n";
                                             cout<<"You have won $50,000\n";
                                             cout<<"Do you want to quit the game\n";
                                             cout<<"press c or C to continue or any other key to exit\n";
                                             char stupidperson5;cin>>stupidperson5;
                                             if(stupidperson5=='C' ||stupidperson5=='c'){
                                                cout<<"You want to continue the game\n";
                                                cout<<"Alright then\n";
                                                cout<<"Level 5\n";
                                                cout<<"You have no lifeline left\n";
                                                cout<<"please play wisely\n";
                                                cout<<"What does HTML stand for in web development?\nA. HyperText Markup Language\nB. High-Level Text Manipulation\nC. Hyperlink and Text Management Language\nD. Human Touch Manipulation Language\n";
                                                char stupidperson6;cin>>stupidperson6;
                                                if(stupidperson6=='A'||stupidperson6=='a'){
                                                   cout<<"Correct you are right\n";
                                                   cout<<"You have won $100,000\n";
                                                   cout<<"Do you want to quit the game\n";
                                                   cout<<"press c or C to continue or any other key to exit\n";
                                                   char stupidperson7;cin>>stupidperson7;
                                                   if (stupidperson7=='c' ||stupidperson1=='C')
                                                   {
                                                      cout<<"You want to continue the game\n";
                                                      cout<<"Alright then\n";
                                                      cout<<"Level 6\n";
                                                      cout<<"You have no lifeline left\n";
                                                      cout<<"please play wisely\n";
                                                      cout<<"Who was the first Prime Minister of India?\nA. Jawaharlal Nehru\nB. Indira Gandhi\nC. Rajiv Gandhi\nD. Narendra Modi\n";
                                                      char stupidperson8;cin>>stupidperson8;
                                                      if(stupidperson8=='A'||stupidperson8=='a'){
                                                         cout<<"Correct you are right\n";
                                                         cout<<"You have won $500,000\n";
                                                         cout<<"Do you want to quit the game\n";
                                                         cout<<"press c or C to continue or any other key to exit\n";
                                                         char stupidperson9;cin>>stupidperson9;
                                                         if(stupidperson9=='c' ||stupidperson9=='C'){
                                                            cout<<"You want to continue the game\n";
                                                            cout<<"Alright then\n";
                                                            cout<<"Level 7\n";
                                                            cout<<"and the final level\n";
                                                            cout<<"You have no lifeline left\n";
                                                            cout<<"please play wisely\n";
                                                            cout<<"Which continent is known as the 'Land Down Under'?\nA. Africa\nB. Europe\nC. Australia\nD. South America\n";
                                                            char stupidperson10;cin>>stupidperson10;
                                                            if (stupidperson10=='c' ||stupidperson10=='C')
                                                            {
                                                               cout<<"Correct you are right\n";
                                                               cout<<"You have won $1,000,000\n";
                                                               cout<<"See you in the next game\n";
                                                               cout<<"You have successfully completed the game\n";
                                                               return 0;
                                                            }else{
                                                               cout<<"Oooo the correct option was option c Australia\n";
                                                               cout<<"Better luck next time\n";
                                                               cout<<"Meet you soon in the next game\n";
                                                               return 0;
                                                            }
                                                            
                                                         }

                                                      }else{
                                                         cout<<"You are  wrong the correct option was A) Jawaharlal Nehru\n";
                                                         cout<<"Better luck next time\n";
                                                         cout<<"Exiting the game\n";
                                                         return 0;
                                                      }

                                                     
                                                   }else{
                                                      cout<<"So As you have wished\n";
                                                      cout<<"See you next time in the next game\n";
                                                      cout<<"Exiting the game\n";
                                                      return 0;
                                                   }
                                                   


                                                }else{
                                                   cout<<"You are  wrong the correct option was A) Hyper Text Markup language\n";
                                                   cout<<"Better luck next time\n";
                                                   cout<<"Exiting the game\n";
                                                   return 0;
                                                }


                                             }else{
                                                 cout<<"So As you have wished\n";
                                                cout<<"See you next time in the next game\n";
                                                cout<<"Exiting the game\n";
                                                return 0;
                                             }

                                          }else{
                                             cout<<"You are  wrong the correct option was b) william Shakespeare\n";
                                             cout<<"Better luck next time\n";
                                             cout<<"Exiting the game\n";
                                             return 0;
                                          }

                                         }else{
                                             cout<<"So As you have wished\n";
                                             cout<<"See you next time in the next game\n";
                                             cout<<"Exiting the game\n";
                                             return 0;
                                         }

                                       }
                                       

                                    }else{
                                       cout<<"So As you have wished\n";
                                       cout<<"See you next time in the next game\n";
                                       cout<<"Exiting the game\n";
                                       return 0;
                                    }
                                 }
                                 
                              }
                              

                           }else{
                              cout<<"According to your friend A is the answer\n";
                              char anspyf2;cin>>anspyf2;
                              cout<<"Press key A or a as your friend said\n";
                              cout<<"else any other answer you may want to give other than your friend one\n";
                              if(anspyf2=='A'||anspyf2=='a'){
                                 cout<<"Thats absolutely correct answer\n";
                                 cout<<"You have won this level worth $20,000\n";
                                 cout<<"press Y or y to continue the game\nelse any other to exit\n";
                                 char exit7;cin>>exit7;
                                 if(exit7=='Y'||exit7=='y'){
                                    cout<<"continuing the game as you have wished\n";
                                    cout<<"Level 4\n";
                                    cout<<"Here is the questions on your screen for $50,000\n";
                                    cout<<"Which festival is celebrated with the flying of kites in India?\nA. Holi\nB. Diwali\nC. Makar Sankranti\nD. Navratri\n";
                                    cout<<"press h or H for help\n";
                                    //continuing the game




                                 }else{
                                    cout<<"As you have wished to quit the game\n";
                                    cout<<"The total amount you have won is $20,000\n";
                                    cout<<"See you later!\n";
                                    cout<<"Exiting the game\n";
                                    return 0;
                                 }
                              }

                           }
                        }
                        


                     }else{
                           cout<<"Oooo you have choosen wrong option\n";
                           cout<<"the correct option was A> Ganges river";
                           cout<<"better luck next time";
                           cout<<"Exiting the game\n";
                           return 0;
                     }
                     
                  
                  }else if(ans12=='h' ||ans12=='H'){
                     cout<<"You need help Alright then";
                     cout<<"Choose\n1-> for 50:50\n2-> for phone your friend\n3->for question swap\n";
                     char option5 ;cin>>option5;
                     if (ff>=1)
                     {
                        cout<<"cannot use this lifeline you have already used it"<<endl;
                        //continuing code

                     }else if(pyf>=1){
                        cout<<"You cannot phone your friend as you have already used it"<<endl;
                           //continuing code
                     }else if(rq>=1){
                        cout<<"You cannot use this option as you have already used it"<<endl;
                           //continuing code
                     }

                     else if(ff==0){
                        if (option5=='1')
                        {
                        cout<<"You have choosen 50-50 options so incorrect options are";
                        cout<<"Chinese dollar and Ruble";
                        //continue code
                        cout<<"Now choose an option";
                        char option6;cin>>option6;
                        if (option6=='d' ||option6=='D')
                        {
                           cout<<"yupp you are correct";
                           cout<<"You have won $ 5000";

                           cout<<"Do you want to continue";
                           cout<<"press y or Y to continue or any other key to exit";
                           char exit5;
                           cin>>exit5;
                           if (exit5=='Y' ||exit5=='y')
                           {
                              cout<<"So,as you have wished \n continuing the game\n";
                              //continue code
                              // char 

                           }else{
                              cout<<"So,as you have wished exiting the game\n";
                           }
                           
                        }
                        
                        }
                        
                       
                     }else if(pyf==0){

                        if(option5=='2'){
                        cout<<"According to your friend the correct options is option D";
                        
                        //continue code 
                        }
                     }else{
                        cout<<"You have not choosen any correct code option";
                     }
                     

                  }else{
                     cout<<"You are wrong";
                     cout<<"The correct answer is "<<ans12<<"i.e Yuan"<<endl;
                     cout<<"See you sooner";
                     cout<<"goodbye";
                  }


               }else{
                  cout<<"Oooo ! you are wrong !"<<endl;
                  cout<<"Your total amount is $0"<<endl;
                  cout<<"Exiting the game"<<endl;
                  return 0;
               }
               break;
            
            default:
               cout<<"You have choosen the wrong option\n";
               cout<<"Any such things could be appear to us as malpractise\n";
               cout<<"Exiting the game\n";
               return 0;
               break;
            }
         }
        //code here

    }else{
         SetConsoleTextAttribute(console_color, 2); 
        cout<<"Thanks for you response\nExiting the game\n";
        return 1;
    }

    return 0;
}


/*

History:
Question 3:

Answer: A

Question 4:

Answer: C



Question 6:
What is the capital city of Japan?
A. Beijing
B. Seoul
C. Tokyo
D. Bangkok
Answer: C


*/