#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;
mutex mtx;
int counter =0;
void foo(int a) {
 sleep(5);
 mtx.lock();
 counter++;
 cout << counter << endl;
 mtx.unlock();
}


int main() {

thread threads[20];
for (int i = 0; i < 20; i++){
threads[i] = thread(foo, i);}
 for (int i = 0; i < 20; i++){
 threads[i].join();
 }
}





// int main() {
//     thread threads[20]; // מערך של תהליכונים

//     // יצירת התהליכונים עם מנעול
//     for (int i = 0; i < 20; i++) {
//         mtx.lock();  // נעילת המנעול כדי למנוע יצירה חפופה של תהליכונים
//         threads[i] = thread(foo, i); // יצירת תהליכון חדש
//         mtx.unlock();  // שחרור המנעול אחרי יצירת התהליכון
//     }

//     // המתנה שכל התהליכונים יסתיימו
//     for (int i = 0; i < 20; i++) {
//         threads[i].join(); // המתן לסיום התהליכון
//     }

//     return 0;
// }
