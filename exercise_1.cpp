#include <iostream>
#include <cstdio>
#include <string>
int main()
{
  char c;            // c represents cube in the system
  char b;            // b represents ball in the system
  char p;            // p represents peg in the system
  char input1;        // let's call the input 1 as the input for choosing the part to be picked
  char input2 ;       // let's call the input 2 as the input for choosing the gripper to be used
  char input3  ;      // let's call the input 3 as the input for choosing the table to be used
  char input4;        // let's call the input 4 as the input for choosing the yes 'y '
  std::string su;
  std::string cu;
  std::string tu;
  
   char s;          // s represents suction gripper in the system
   char f;          // f represents finger gripper in the system
  while (1)
  {
    while (1)
    {

      do
      {
        std::cout << "Which part to pickup (cube(c), ball(b), peg(p)): \n";  //prints Which part to pickup (cube(c), ball(b), peg(p)):
        std::cin >> input1;
      } while (input1 != 'c' && input1 != 'b' && input1 != 'p'); 

      
      do                                                                  
      {
        std::cout << "Which gripper to chose(suction (s) or finger(f)): \n";  //prints "Which gripper to chose(suction (s) or finger(f))
        std::cin >> input2;
      } while (input2 != 's' && input2 != 'f');  

      if ((input1 == 'c' && input2 == 'f') || (input1 == 'p' && input2 == 'f') || (input1 == 'b' && input2 == 's'))
      {

        do
        {
          std::cout << "Please choose a table onto which you would like to place the part (g, d or r): \n";
          std::cin >> input3;
        } while (input3 != 'r' && input3 != 'd' && input3 != 'g');

        if ((input3 == 'r' && input1 == 'c') || (input3 == 'd' && input1 == 'p') || (input3 == 'g' && input1 == 'b'))
        {
          std::cout << "Success : its a win!!! \n";
          return 0;
        }
        else
        {
          switch (input1)
        {
          case 'c':
            {cu= "cube";        //cu represents cube
             break;}

          case 'b':
            {cu="ball";          //cu represents ball
            break;}

          case 'p':
            {cu="peg";           //cu represents peg
            break;}

          default:
            break;
        }
        switch (input3)
        {

          case 'r':
            {tu= "red" ;        //tu represents red color table
              break;}

          case 'd':
            {tu= "blue";        //tu represents blue color table
            break;}

          case 'g':
            {tu= "green";        //tu represents blue color table
            break;}
            
          default:
          break;
        }
      
        std::cout <<"Failure: "<< cu << " cannot be placed on " << tu <<"table"<< '\n';
          std::cout << "Would you like to try again?? If yes type 'y': \n";
          std::cin >> input4;
          if (input4 != 'y')
            {
          return 0;
          }}
  
        }
      
      else
      {{
        switch (input1)
        {
          case 'c':
            {cu= "cube";
             break;}

          case 'b':
            {cu="ball";
            break;}

          case 'p':
            {cu="peg";
            break;}

          default:
            break;
        }
        switch (input2)
        {

          case 's':
            {su= "suction" ;
              break;}

          case 'f':
            {su= "finger";
            break;}
          default:
          break;
        }
      
        std::cout <<"Failure: "<< cu << " cannot be picked up by " << su << " gripper"<<'\n';
      }
        std::cout << "Would you like to try again?? If yes type 'y': \n";
        std::cin >> input4;
        if (input4 != 'y')
        {
         return 0;
       }
      }
  }   
}
}