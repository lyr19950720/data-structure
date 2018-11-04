/*#include <iostream>
#include <string>
#include <stack>
 using namespace std; 
 int main()
 {    
	 stack<string> fs, bs;    
	 string commond, url;  
	 fs.push("http://www.acm.org/");     
	 while(cin >> commond) {  
		 
		 if(commond[0] == 'Q') // QUIT                       
			 break;        
		 else if(commond[0] == 'V') // VISIT 
		 {                
			 cin >> url;            
			 fs.push(url);            
			 cout << url << endl;             
			 // 清空：一旦输入一个新的URL，就不能再做FORWARD了            
			 while(!bs.empty())               
				 bs.pop();       
		 } else if(commond[0] == 'B') // BACK 
		 {            
			 if(fs.size() > 1) 
			 {                
				 bs.push(fs.top());                
				 fs.pop();               
				 cout << fs.top() << endl;           
			 } else                
				 cout << "Ignored" << endl;       
		 } else if(commond[0] == 'F') 
		 {  // FORWARD            
			 if(!bs.empty()) 
			 {                
				 fs.push(bs.top());                
				 cout << bs.top() << endl;                
				 bs.pop();            
			 } else                
				 cout << "Ignored" << endl;       
		 }    
		 }    
		 return 0;

}*/
#include <iostream>
#include <string>
#include <stack>
using namespace std; 
stack<string> fs, bs;    
string commond, url; 
void V()
{
        cin >> url;            
	    fs.push(url);            
		cout << url << endl;             
		// 清空：一旦输入一个新的URL，就不能再做FORWARD了            
		while(!bs.empty())               
		    bs.pop();
	
}
void B()
{
 if(fs.size() > 1) 
	 {                
		bs.push(fs.top());                
		fs.pop();               
		cout << fs.top() << endl;           
	 } else                
		 cout << "Ignored" << endl;
}
void F()
{
	if(!bs.empty()) 
	 {                
		fs.push(bs.top());                
		cout << bs.top() << endl;                
		bs.pop();            
	} else                
		cout << "Ignored" << endl; 
}
 int main()
 {    
	  
	 fs.push("http://www.acm.org/");     
	 while(cin >> commond) {  
		 switch(commond[0])
		 {
		    case 'Q': break;
			case 'V': V();break;
			case 'B': B();break;
			case 'F': F();break;
			default:break;
		 }  
		 
	 }    
		 return 0;

}
 

 
