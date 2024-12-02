#include<iostream> // ใช้สำหรับ Input/Output
#include<string>   // ใช้สำหรับจัดการ string
using namespace std;

// struct declaration
struct anime {
    string full_name;        // ชื่อเต็มของอนิเมะ
    string author;           // ชื่อผู้แต่ง
    int total_episode;       // จำนวนตอนทั้งหมด
    int length_per_episode;  // ความยาวของแต่ละตอน (หน่วยเป็นวินาที)

    int playing_episode;     // ตอนที่กำลังดูอยู่
    int playing_sec;         // เวลาที่ดูล่าสุดในตอนที่กำลังดู
};

// function declaration
void play(anime*, int); // ฟังก์ชันสำหรับเล่นอนิเมะ รับพอยน์เตอร์ของอนิเมะและระยะเวลาเล่น (วินาที)

int main() {
    // variable declaration
    anime a1, a2; // สร้างตัวแปรสำหรับอนิเมะ 2 เรื่อง

    // ตั้งค่าคุณสมบัติของ The Melancholy of Haruhi Suzumiya
    a1.full_name = "The Melancholy of Haruhi Suzumiya"; 
    a1.author = "Nagaru Tanigawa";
    a1.total_episode = 24; // มีทั้งหมด 24 ตอน
    a1.length_per_episode = 1200; // ความยาวแต่ละตอน 1200 วินาที
    a1.playing_episode = 1; // เริ่มดูตอนที่ 1
    a1.playing_sec = 0; // ยังไม่ได้เริ่มดู (0 วินาที)

    // ตั้งค่าคุณสมบัติของ Spy x Family Part 1
    a2.full_name = "Spy x Family Part 1";
    a2.author = "Tatsuya Endo";
    a2.total_episode = 12; // มีทั้งหมด 12 ตอน
    a2.length_per_episode = 1440; // ความยาวแต่ละตอน 1440 วินาที
    a2.playing_episode = 1; // เริ่มดูตอนที่ 1
    a2.playing_sec = 0; // ยังไม่ได้เริ่มดู (0 วินาที)

    // เรียกฟังก์ชัน play เพื่อเล่นแต่ละอนิเมะ
    play(&a1, 500);      // เล่น The Melancholy of Haruhi Suzumiya ตอนที่ 1 [500 วินาที]
    play(&a1, 99999);    // เล่นจนจบตอนที่ 1 และไปต่อในตอนที่ 2 [700 วินาที]
    play(&a1, 99999);    // เล่นจนจบตอนที่ 2 และไปต่อในตอนที่ 3 [1200 วินาที]
    play(&a2, 100);      // เล่น Spy x Family Part 1 ตอนที่ 1 [100 วินาที]
    play(&a2, 100);      // เล่น Spy x Family Part 1 ตอนที่ 1 [อีก 100 วินาที]
    play(&a2, 100);      // เล่น Spy x Family Part 1 ตอนที่ 1 [เพิ่มอีก 100 วินาที]
    play(&a2, 99999);    // เล่นจนจบตอนที่ 1 และไปต่อในตอนที่ 2 [1140 วินาที]
    play(&a1, 500);      // เล่น The Melancholy of Haruhi Suzumiya ตอนที่ 3 [500 วินาที]
    play(&a1, 99999);    // เล่นจนจบตอนที่ 3 และไปต่อในตอนที่ 4 [700 วินาที]

    return 0; // สิ้นสุดโปรแกรม
}

// function definition
void play(anime *a, int time) {
    int remaining_time = a->length_per_episode - a->playing_sec; // คำนวณเวลาที่เหลือในตอนปัจจุบัน

    if (time > remaining_time) { // หากเวลาเล่นเกินเวลาที่เหลือของตอนปัจจุบัน
        cout << "playing " << a->full_name << " EP." << a->playing_episode 
             << " [" << remaining_time << " sec]" << endl; // แสดงข้อความว่าเล่นจนจบตอน
        a->playing_episode++; // เปลี่ยนไปดูตอนถัดไป

        if (a->playing_episode > a->total_episode) { // หากเล่นจบทุกตอน
            a->playing_episode = 1; // วนกลับไปตอนที่ 1
        }

        a->playing_sec = 0; // เริ่มตอนใหม่ที่วินาที 0
    } else { // หากเวลาเล่นยังไม่เกินตอนปัจจุบัน
        cout << "playing " << a->full_name << " EP." << a->playing_episode 
             << " [" << time << " sec]" << endl; // แสดงข้อความว่าเล่นในตอนนี้
        a->playing_sec += time; // เพิ่มเวลาเล่นในตอนปัจจุบัน
    }
}
