#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main(){
  //Ask for extension
  string extension;
  cout<<"Please select extension: "<<endl;
  cin>>extension;

  //Ask how many solutions
  int solutions;
  cout<<"How many solutions do you have: "<<endl;
  cin>>solutions;

  while(!cin.good()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    cout<<"How many solutions do you have: "<<endl;
    cin>>solutions;
  };

  //Ask if REAMDE is required
  bool readme;
  bool readmeError=true;
  char readmeAnswer;
  
  while(readmeError){
    cout<<"Do you need a README file (y/n): "<<endl;
    cin>>readmeAnswer;
  
    if(readmeAnswer=='y'){
      readme=true;
      readmeError=false;
    }else if(readmeAnswer=='n'){
      readme=false;
      readmeError=false;
    }else{
      cout<<"Please only enter either 'y' or 'n'!!!"<<endl;
    };
  };
  
  //Create the solution file(s)
  int tempSolutions=solutions;

  if(tempSolutions<2){
    ofstream solution("solution."+extension);
    solution.close();
  }else{
    while(tempSolutions>0){
      string fileName="solution"+to_string(tempSolutions)+"."+extension;
      ofstream solution(fileName);
      solution.close();
      tempSolutions--;
    };
  };

  //Fills README file
  if(readme){
    string title;
    string source;
    string url;
    string difficulty;

    cin.ignore();
    cout<<"Please enter the title: "<<endl;
    getline(cin, title);

    cout<<"Please enter the source: "<<endl;
    getline(cin, source);

    cout<<"Please enter the source url: "<<endl;
    cin>>url;

    cin.ignore();
    cout<<"Please enter the difficulty level: "<<endl;
    getline(cin, difficulty);

    //create and open REAMDE.md file
    ofstream readmeFile("README.md");
    readmeFile
    <<"## "+title+"   \n"
    <<"**Source**: ["+source+"]("+url+")   \n"
    <<"**Difficulty**: "+difficulty+"   \n"
    <<"**Brief**:    \n\n"
    <<"### Example   \n"
    <<"**Input**: `` ``   \n"
    <<"**Output**: `` ``   \n"
    <<"**Explanation**:   \n"
    <<endl;
    
    if(solutions<2){
      readmeFile
      <<"### Solution   \n"
      <<"**Runtime**: `` ``   \n"
      <<"**Memory**: `` ``   \n"
      <<"```"
      <<endl
      <<endl
      <<"``` \n"
      <<endl;
    }else{
      int i=1;

      while(solutions>0){
      readmeFile
       <<"### Solution "+to_string(i)+"   \n"
       <<"**Runtime**: `` ``   \n"
       <<"**Memory**: `` ``   \n"
       <<"```"
       <<endl
       <<endl
       <<"```   \n"
       <<endl;

       i++;
       solutions--;
      }
    }
    readmeFile.close();
  };

  cout<<"Process complete :-)"<<endl;
}
