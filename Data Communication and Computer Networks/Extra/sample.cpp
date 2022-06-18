#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
class time 
{
    private :
        int seconds;
    public :
        void setSeconds(int temp)
        {
            seconds = temp;
        }
        int getSeconds()
        {
            return seconds;
        }
    
};
//7277 sec
class time_h_m : public time 
{
    public :
      
        int add(int sec1, int sec2)
        {
            return sec1+sec2;
        }   

        void absTime(int SEC)
        {
            int hrs, min, sec=0;
            if(SEC/3600!=0)
            {
                hrs = SEC/3600;
            }
            if(SEC/60!=0)
            {
                for(int i=0;i<2;i++)
                {
                    sec = sec + (SEC%10)*pow(10,i);
                    SEC=SEC/10;
                }
                min = sec/60;
            }
            sec = sec - (min*60);
            cout<<"Time (hrs:min:sec) : "<<hrs<<":"<<min<<":"<<sec<<endl;

        }
};

int main()
{
    time_h_m *obj = new time_h_m();
    obj->setSeconds(3670);
    // obj->absTime(obj->getSeconds());


    time_h_m *obj2 = new time_h_m();
    obj2->setSeconds(3600);
    obj->setSeconds(obj->add(obj->getSeconds(),obj2->getSeconds()));
    obj->absTime(obj->getSeconds());
    
}