#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

//  Anggota Kelompok 9
//  Anggota Kelompok X
//  Muhammad Faiq Adhitya Faqih (672020017)
//  Marcelinus Vito Otniel (672020192)
//  Edwin Duta Ramadhan (672020272)
//  Felisitas Yohania Renya T. Puli (672020284)
//  Naweni Gracia Elshalom Riwu (672020318)

const int width = 1920;
const int height = 1080;
int i,posisi = 0,layer;
float sudut;
float red, green, blue;
double x_geser, y_geser, z_geser;
double sumbuX, sumbuZ,saklarLampu,lampuFTI;
float x, y, z;
float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 0.0, terbang = 25.0;
int sejajarSumbuX;

bool mulai = true, finish = false;
void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

void sisiAtasCamera(float x, float y, float z, float red, float green, float blue);
void sisiBawahCamera(float x, float y, float z, float red, float green, float blue);
void sisiKananCamera(float x, float y, float z, float red, float green, float blue);
void sisiDepanCamera(float x, float y, float z, float red, float green, float blue);
void sisiKiriCamera(float x, float y, float z, float red, float green, float blue);
void sisiBelakangCamera(float x, float y, float z, float red, float green, float blue);
void tanganTangga(float x, float y, float z, float red, float green, float blue);
void tangga(float x, float y, float z, float red, float green, float blue);
void samping(float x, float y, float z);
void balokTanganTangga(float x, float y, float z);
void cetakTangga();
void tiangPagar(float x, float z, float red, float green, float blue);
void tiangDepan(float x);
void tiangBelakang(float x);
void tiangKanan(float z);
void tiangKiri(float z);
void cetakTiang();
void pembatasPagarDepan(float x, float y, float z, float red, float green, float blue);
void pembatasPagarBelakang(float x, float y, float z, float red, float green, float blue);
void pembatasPagarSamping(float x, float y, float z, float red, float green, float blue);
void cetakPembatas();
void cetakPagar();
void batang(float x, float y, float z, float red, float green, float blue);
void daun(float x, float y, float z, float red, float green, float blue);
void pot(float x, float y, float z, float red, float green, float blue);
void pot2(float x, float y, float z, float red, float green, float blue);
void tanah(float x, float y, float z, float red, float green, float blue);
void cetakPohon();
void lantai(float x, float y, float z, float red, float green, float blue);
void balok(float x, float y, float z, float red, float green, float blue);
void lantai1(float x, float y, float z, float red, float green, float blue);
void lantai2(float x, float y, float z, float red, float green, float blue);
void lantai3(float x, float y, float z, float red, float green, float blue);
void cetakPalangY(float x, float y, float z, float tinggi);
void cetakPalangX(float x, float y, float z,float tinggi);
void cetakPintu(float x, float y, float z);
void cetakPalangEkseteriorLantai1();
void cetakPalangEkseteriorLantai2();
void cetakPalangEkseteriorLantai3();
void cetakPalangEkseteriorLantai4();
void cetakbalokHorizontalLantai1();
void cetakbalokHorizontalLantai2();
void cetakbalokHorizontalLantai3();
void cetakbalokHorizontalLantai4();
void jendela(int lantai);
void cetakJendelaFullSenyumEksteriorLantai1();
void cetakJendelaFullSedihEksteriorLantai2();
void cetakJendelaFullSempalEksteriorLantai3();
void cetakJendelaFullSempalEksteriorLantai4();
void cetakPintuKuil(int lantai);
void cetakBambuKecil(float x, float y, float z, float tinggiBambu);
void cetakAtapSeiganToJiLantai2();
void cetakAtapSeiganToJiLantai3();
void cetakAtapSeiganToJiLantai4();
void cetakKubahSeiganToJi();
void cetakBalokPenyangga();
void cetakPagarKayu();
void cetakTerasLantai3();
void cetakTerasLantai4();
void cetakUjungAtap(int lantai);
void cetakPenyanggaAtap(int lantai);
void cetakPintuLuar(int lantai);
void pintuLuar(float x, float y, float z);
void cetakPintuDalam(int lantai);
void cetakpetir();
void babiMinecraft();
void tampilBabiMinecraft();
void tampilEndermanMinecraft();
void cetakKursi();
void cetakLemari();
void cetakTempatsampah(float x, float y,float z);
void cetakMeja();
void tianglampu();
void cetakbintang();
void lampuFTI2022();
void cetakLampuGantung(float x, float y, float z);
void pagarKayuTerasLantai3();
void pagarKayuTerasLantai4();
void pinggiranAtap(float x, float y, float z);
void cetakPinggiranAtap();
void tampilPagarKayu();
void kotak(float x, float y, float red, float green, float blue);
void jendelaFullSenyum(float x1, float y1, float z1, int posisi);
void jendelaFullSedih(float x, float y, float z, int posisi);
void jendelaFullSempal(float x, float y, float z, int posisi);
void bambu(float x, float y, float z, float tinggiBambu);
void pot(float x, float y, float z);
void potDanBambu(float x, float y, float z, float tinggiBambu);
void balokHorizontalLantai1(float x, float y, float z, int sejajarSumbuX);
void balokHorizontalLantai2(float x, float y, float z, int sejajarSumbuX);
void balokHorizontalLantai3(float x, float y, float z, int sejajarSumbuX);
void balokHorizontalLantai4(float x, float y, float z, int sejajarSumbuX);
void balokPenyangga(float x, float y, float z);
void catPetiMinecraft(bool petiBesar);
void kunciPetiMinecraft(bool petiBesar, int posisi);
void petiMinecraft(float x, float y, float z, bool petiBesar, int posisi);
void karpet(float x, float y, float z);
void bambu(float x, float y, float z, float tinggiBambu);
void bambuKecil(float x, float y, float z, float tinggiBambu);
void potDanBambu(float x, float y, float z, float tinggiBambu);
void pot(float x, float y, float z);
void pintuKuil(float x, float y, float z);
void algoritmaAtapSeiganToJi(int lantai);
void balokVertikal(float x, float y, float z, float panjang);
void cetakBalokVertikal(int lantai);
void balokVertikalKecil(float x, float y, float z, float panjang);
void pagarKayuTebalVertikalPendek(float x, float y, float z);
void kubahSeiganToJi();
void matahari(float x, float y, float z);
void gentong(float x, float y, float z, int type);
void lantai1(float x, float y, float z, float red, float green, float blue);
void lantai2(float x, float y, float z, float red, float green, float blue);
void lantai3(float x, float y, float z, float red, float green, float blue);
void lantai4(float x, float y, float z, float red, float green, float blue);
void atapSeiganToJi(float x, float tinggi, float red, float green, float blue);
void pagarKayu(float x, float y, float z, float panjang);
void pagarKayuTebal(float x, float y, float z, float panjang);
void pagarKayuTebalVertikal(float x, float y, float z);
void ujungAtap(float x, float y, float  z);
void cetakBalokReplika();
void interiorLantai1();
void interiorLantai2();
void interiorLantai3();
void interiorLantai4();
void eksteriorLantai0();
void eksteriorLantai1();
void eksteriorLantai2();
void eksteriorLantai3();
void eksteriorLantai4();
void replikaSeigantoji(float x, float y, float z);
struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void init() {
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void ground() {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-1000.0, 0, -1000.0);

    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(1000.0, 0, -1000.0);

    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex3f(1000.0, 0, 1000.0);

    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-1000.0, 0, 1000.0);
    glEnd();
}

void draw() {
    //Key 1. OnLampu dalam kuil
    //key 2. OffLampu dalam kuil
    //key 3. OnLampu luar kuil
    //key 4. OffLampu luar kuil
    //key 5. TutupPintu kuil
    //key 6. BukaPintu kuil
    cetakPagar();
    cetakTangga();
    cetakPohon();
    eksteriorLantai0();
    lantai(700,200,700,0.7,0.7,0.7);//y:Tinggi
    //===lantai 1===//
    glPushMatrix();
    glTranslatef(0, 200, 0);
    lantai1(385,300,385,0.8,0.8,0.8);//tembokDalam
    lantai1(400, 300, 400,0.9,0.9,0.9);//tembokLuar
    eksteriorLantai1();
    interiorLantai1();
    glPopMatrix();   
    //===lantai 1===//
    //===lantai 2===//
    glPushMatrix();
    glTranslatef(0, 500, 0);
    lantai2(337, 300, 337, 0.8, 0.8, 0.8);//tembokDalam
    lantai2(350, 340, 350, 0.9, 0.9, 0.9);//tembokLuar
    eksteriorLantai2();
    interiorLantai2();
    glPopMatrix();
    //===lantai 2===//
    //===lantai 3===//
    glPushMatrix();
    glTranslatef(0, 800, 0);
    lantai3(285, 300, 285, 0.8, 0.8, 0.8);//tembokDalam
    lantai3(300, 340, 300, 0.9, 0.9, 0.9);//tembokLuar
    eksteriorLantai3();
    interiorLantai3();
    glPopMatrix();
    //===lantai 3===//
    //===lantai 4===//
    glPushMatrix();
    glTranslatef(0, 1100, 0);
    lantai4(235, 300, 235, 0.8, 0.8, 0.8);//tembokDalam
    lantai4(250, 340, 250, 0.9, 0.9, 0.9);//tembokLuar
    eksteriorLantai4();
    interiorLantai4();
    glPopMatrix();
    //===lantai 4===//
    //cout << "SumbuX = " << sumbuX << " SumbuZ = " << sumbuZ << " Mulai = " << mulai << endl;
    ground();
    matahari(500,3000,0);
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}
void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}
void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 7;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 5;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 7;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 7;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 7;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 7;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 7;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 7;
    }
    if (motion.Naik) {
        terbang -= 7.0;
    }
    if (motion.Turun) {
        terbang += 7.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '6':
        if (x_geser < 71.0)
        {
            x_geser += 2.0;
        }
        else if (x_geser > 71.0)
        {
            x_geser = 71.0;
        }
        
        break;
    case '5':
        if (x_geser > 0)
        {
            x_geser -= 2.0;
        }
        else if (x_geser < 0)
        {
            x_geser = 0;
        }
        
        break;
    case '3':
        y_geser = 0.12;
        break;
    case '4':
        y_geser = -0.12;
        break;
    case '1':
        saklarLampu = 5;
        break;
    case '2':
        saklarLampu = -5;
        break;
    case '7':
        lampuFTI = 0.05;
        break;
    case '8':
        lampuFTI = -0.05;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}
void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}
void ujungAtap(float x, float y, float  z) {
    glPushMatrix();glTranslatef(x,y,z);
    glBegin(GL_QUADS);
    glColor3f(0, 0.4, 0.2); glVertex3f(-50, 0, -50);
    glColor3f(0, 0.4, 0.2); glVertex3f(-50, 0, 50);
    glColor3f(0, 0.4, 0.2); glVertex3f(50, 0, 50);
    glColor3f(0, 0.4, 0.2); glVertex3f(-60, 20, 60);
    glEnd();glBegin(GL_TRIANGLES);
    glColor3f(0, 0.4, 0.2); glVertex3f(-50, 0, -50);
    glColor3f(0, 0.6, 0.3); glVertex3f(100, 30, -100);
    glColor3f(0, 0.6, 0.3); glVertex3f(-60, 20, 60);
    glEnd();glBegin(GL_TRIANGLES);
    glColor3f(0, 0.4, 0.2); glVertex3f(50, 0, 50);
    glColor3f(0, 0.6, 0.3); glVertex3f(100, 30, -100);
    glColor3f(0, 0.6, 0.3); glVertex3f(-60, 20, 60);
    glEnd();glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.3); glVertex3f(-50, 0, 50);
    glColor3f(0, 0.6, 0.3); glVertex3f(150, 71, -150);
    glColor3f(0, 0.4, 0.2); glVertex3f(500, 71, -150);
    glColor3f(0, 0.4, 0.2); glVertex3f(500, 0, 50);
    glEnd();glBegin(GL_QUADS);
    glColor3f(0, 0.6, 0.3); glVertex3f(-50, 0, 50);
    glColor3f(0, 0.6, 0.3); glVertex3f(150, 71, -150);
    glColor3f(0, 0.4, 0.2); glVertex3f(150, 71, -500);
    glColor3f(0, 0.4, 0.2); glVertex3f(-50, 0, -500);
    glEnd();glPopMatrix();
}
void pinggiranAtap(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);glBegin(GL_QUADS);
    glColor3f(0, 0.4, 0.2); glVertex3f(-50, 0, -50);
    glColor3f(0, 0.4, 0.2); glVertex3f(-50, 0, 50);
    glColor3f(0, 0.4, 0.2); glVertex3f(50, 0, 50);
    glColor3f(0, 0.4, 0.2); glVertex3f(-60, 20, 60);
    glEnd();glBegin(GL_TRIANGLES);
    glColor3f(0, 0.4, 0.2); glVertex3f(-50, 0, -50);
    glColor3f(0, 0.6, 0.3); glVertex3f(100, 50, -100);
    glColor3f(0, 0.6, 0.3); glVertex3f(-60, 20, 60);
    glEnd();glBegin(GL_TRIANGLES);
    glColor3f(0, 0.4, 0.2); glVertex3f(50, 0, 50);
    glColor3f(0, 0.6, 0.3); glVertex3f(100, 50, -100);
    glColor3f(0, 0.6, 0.3); glVertex3f(-60, 20, 60);
    glEnd();glPopMatrix();
}
void cetakPinggiranAtap() {
    pinggiranAtap(-400, 300, 400);
    glPushMatrix();glRotatef(180, 0.0, 1.0, 0.0);
    pinggiranAtap(-400, 300, 400);;
    glPopMatrix();
    glPushMatrix();glRotatef(90, 0.0, 1.0, 0.0);
    pinggiranAtap(-400, 300, 400);
    glPopMatrix();
    glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
    pinggiranAtap(-400, 300, 400);
    glPopMatrix();
}
void cetakUjungAtap(int lantai) {
    if (lantai == 3)
    {
        ujungAtap(-500, 0, 500);
        glPushMatrix();glRotatef(180,0.0,1.0,0.0);
        ujungAtap(-500,0,500);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, 1.0, 0.0);
        ujungAtap(-500, 0, 500);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
        ujungAtap(-500, 0, 500);
        glPopMatrix();
    }else if (lantai == 4) {
        glPushMatrix();glScalef(0.91,0.91,0.91);
        ujungAtap(-500, 0, 500);
        glPushMatrix();glRotatef(180, 0.0, 1.0, 0.0);
        ujungAtap(-500, 0, 500);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, 1.0, 0.0);
        ujungAtap(-500, 0, 500);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
        ujungAtap(-500, 0, 500);
        glPopMatrix();
        glPopMatrix();
    }
}
void sisiAtasCamera(float x, float y, float z, float red, float green, float blue) {
    glBegin(GL_QUADS);glColor3f(red, green, blue);
    glVertex3f(-x, y, -z);glColor3f(red, green, blue);
    glVertex3f(x, y, -z);glColor3f(red, green, blue);
    glVertex3f(x, y, z);glColor3f(red, green, blue);
    glVertex3f(-x, y, z);glEnd();
}
void sisiBawahCamera(float x, float y, float z, float red, float green, float blue) {
    glBegin(GL_QUADS);glColor3f(red, green, blue);
    glVertex3f(-x, 1, -z);glColor3f(red, green, blue);
    glVertex3f(x, 1, -z);glColor3f(red, green, blue);
    glVertex3f(x, 1, z);glColor3f(red, green, blue);
    glVertex3f(-x, 1, z);glEnd();
}
void sisiKananCamera(float x, float y, float z, float red, float green, float blue) {
    glBegin(GL_QUADS);glColor3f(red, green, blue);
    glVertex3f(x, 1, z);glColor3f(red, green, blue);
    glVertex3f(x, 1, -z);glColor3f(red, green, blue);
    glVertex3f(x, y, -z);glColor3f(red, green, blue);
    glVertex3f(x, y, z);glEnd();
}
void sisiDepanCamera(float x, float y, float z, float red, float green, float blue) {
    glBegin(GL_QUADS);glColor3f(red, green, blue);
    glVertex3f(x, 1, -z);glColor3f(red, green, blue);
    glVertex3f(-x, 1, -z);glColor3f(red, green, blue);
    glVertex3f(-x, y, -z);glColor3f(red, green, blue);
    glVertex3f(x, y, -z);glEnd();
}
void sisiKiriCamera(float x, float y, float z, float red, float green, float blue) {
    glBegin(GL_QUADS);glColor3f(red, green, blue);
    glVertex3f(-x, 1, -z);glColor3f(red, green, blue);
    glVertex3f(-x, 1, z);glColor3f(red, green, blue);
    glVertex3f(-x, y, z);glColor3f(red, green, blue);
    glVertex3f(-x, y, -z);glEnd();
}
void sisiBelakangCamera(float x, float y, float z, float red, float green, float blue) {
    glBegin(GL_QUADS);glColor3f(red, green, blue);
    glVertex3f(-x, 1, z);glColor3f(red, green, blue);
    glVertex3f(x, 1, z);glColor3f(red, green, blue);
    glVertex3f(x, y, z);glColor3f(red, green, blue);
    glVertex3f(-x, y, z);glEnd();
}
void lantai(float x, float y, float z, float red, float green, float blue) {
    sisiAtasCamera(x, y, z, 0.2, 0.2, 0.2);
    sisiBawahCamera(x, 1, z, 0, 0, 0);
    sisiKananCamera(x, y, z, red, green, blue);//kananCamera
    sisiDepanCamera(x, y, z, red, green, blue);//depanCamera
    sisiKiriCamera(x, y, z, red, green, blue);//kiriCamera
    sisiBelakangCamera(x, y, z, red, green, blue);//belakangCamera
}


void balok(float x, float y, float z, float red, float green, float blue) {
    sisiAtasCamera(x, y - 1, z, red, green, blue);
    sisiBawahCamera(x, y - 1, z, red, green, blue);
    sisiKananCamera(x, y - 1, z, red, green, blue);//kananCamera
    sisiDepanCamera(x, y - 1, z, red, green, blue);//depanCamera
    sisiKiriCamera(x, y - 1, z, red, green, blue);//kiriCamera
    sisiBelakangCamera(x, y - 1, z, red, green, blue);//belakangCamera
}
void lantai1(float x, float y, float z, float red, float green, float blue) {
    sisiAtasCamera(x + 300, y, z + 300, 0.6, 0.6, 0.6);
    sisiBawahCamera(x, 1, z, 0.3, 0.3, 0.3);
    sisiKananCamera(x, y, z, red, green, blue);;//kananCamera
    sisiDepanCamera(x, y, z, red, green, blue);//depanCamera
    sisiKiriCamera(x, y, z, red, green, blue);//kiriCamera
    glPushMatrix();glTranslatef(-250, 0, 0);
    sisiBelakangCamera(150, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(250, 0, 0);
    sisiBelakangCamera(150, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 220, 0);
    sisiBelakangCamera(100, 80, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 221, 392);
    sisiAtasCamera(100,0,8,0.8,0.8,0.8);
    glPopMatrix();

}
void lantai2(float x, float y, float z, float red, float green, float blue) {
    sisiAtasCamera(x , y, z , 0.6, 0.6, 0.6);
    sisiBawahCamera(x, 1, z, 0.3, 0.3, 0.3);
    sisiKananCamera(x, y, z, red, green, blue);;//kananCamera
    sisiDepanCamera(x, y, z, red, green, blue);//depanCamera
    sisiKiriCamera(x, y, z, red, green, blue);//kiriCamera
    glPushMatrix();glTranslatef(-225, 0, 0);
    sisiBelakangCamera(125, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(225, 0, 0);
    sisiBelakangCamera(125, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 220, 0);
    sisiBelakangCamera(100, 90, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 221, 344);
    sisiAtasCamera(100, 0, 6, 0.8, 0.8, 0.8);
    glPopMatrix();

}
void lantai3(float x, float y, float z, float red, float green, float blue) {
    sisiAtasCamera(x, y, z, 0.6, 0.6, 0.6);
    sisiBawahCamera(x, 0, z, 0.3, 0.3, 0.3);
    sisiKananCamera(x, y, z, red, green, blue);;//kananCamera
    sisiDepanCamera(x, y, z, red, green, blue);//depanCamera
    sisiKiriCamera(x, y, z, red, green, blue);//kiriCamera
    glPushMatrix();glTranslatef(-200, 0, 0);
    sisiBelakangCamera(100, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(200, 0, 0);
    sisiBelakangCamera(100, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 220, 0);
    sisiBelakangCamera(100, 90, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 221, 294);
    sisiAtasCamera(100, 0, 6, 0.8, 0.8, 0.8);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 1, -349);
    sisiDepanCamera(350, 100, 0, 0.9, 0.9, 0.9);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 1, 349);
    sisiBelakangCamera(350, 100, 0, 0.9, 0.9, 0.9);
    glPopMatrix();
    glPushMatrix();glTranslatef(-349, 1, 0);
    sisiKiriCamera(0, 100, 350, 0.9, 0.9, 0.9);
    glPopMatrix();
    glPushMatrix();glTranslatef(349, 1, 0);
    sisiKananCamera(0, 100, 350, 0.9, 0.9, 0.9);
    glPopMatrix();
}
void lantai4(float x, float y, float z, float red, float green, float blue) {
    sisiAtasCamera(x, y, z, 0, 0.3, 0.2);
    sisiBawahCamera(x, 1, z, 0.3, 0.3, 0.3);
    sisiKananCamera(x, y, z, red, green, blue);;//kananCamera
    sisiDepanCamera(x, y, z, red, green, blue);//depanCamera
    sisiKiriCamera(x, y, z, red, green, blue);//kiriCamera
    glPushMatrix();glTranslatef(-165, 0, 0);
    sisiBelakangCamera(85, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(165, 0, 0);
    sisiBelakangCamera(85, y, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 220, 0);
    sisiBelakangCamera(100, 120, z, red, green, blue);//belakangCamera
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 221, 244);
    sisiAtasCamera(100, 0, 6, 0.8, 0.8, 0.8);
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 1, -301);
    sisiDepanCamera(301, 80, 0, 0.9, 0.9, 0.9);
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 1, 301);
    sisiBelakangCamera(301, 80, 0, 0.9, 0.9, 0.9);
    glPopMatrix();
    glPushMatrix(); glTranslatef(-301, 1, 0);
    sisiKiriCamera(0, 80, 301, 0.9, 0.9, 0.9);
    glPopMatrix();
    glPushMatrix(); glTranslatef(301, 1, 0);
    sisiKananCamera(0, 80, 301, 0.9, 0.9, 0.9);
    glPopMatrix();
}

void cetakPalangY(float x, float y, float z, float tinggi) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(20, tinggi, 10, 1.0f, 0.21f, 0.0f);
    glPopMatrix();
}
void cetakPalangX(float x, float y, float z, float tinggi) {
    //Cetak Palang Pada Sumbu X
    glPushMatrix();glTranslatef(x, y, z);
    balok(10, tinggi, 20, 1.0f, 0.21f, 0.0f);
    glPopMatrix();
}
void cetakPintu(float x, float y, float z) {
    //Cetak Pintu
    glPushMatrix();glTranslatef(x, y, z);
    balok(5, 220, 70, 1, 0.5, 0);
    glPopMatrix();
}
void kotak(float x, float y, float red, float green, float blue) {
    glBegin(GL_QUADS);glColor3f(red, green, blue);
    glVertex3f(0, 0, 0);
    glVertex3f(x, 0, 0);
    glVertex3f(x, y, 0);
    glVertex3f(0, y, 0);
    glEnd();
}
void cetakPalangEkseteriorLantai1() {
    //palangDepan
    cetakPalangY(401, 0, 401,300); cetakPalangY(257, 0, 400, 300);
    cetakPalangY(-401, 0, 401, 300); cetakPalangY(-257, 0, 400, 300);
    cetakPalangY(115, 0, 400, 300); cetakPalangY(-115, 0, 400, 300);
    //palangBelakang
    cetakPalangY(401, 0, -401, 300); cetakPalangY(250, 0, -400, 300);
    cetakPalangY(-401, 0, -401, 300); cetakPalangY(-250, 0, -400, 300);
    cetakPalangY(100, 0, -400, 300); cetakPalangY(-100, 0, -400, 300);
    //palangKanan
    cetakPalangX(401, 0, 401, 300); cetakPalangX(400, 0, 250, 300);
    cetakPalangX(401, 0, -401, 300); cetakPalangX(400, 0, -250, 300);
    cetakPalangX(400, 0, 100, 300); cetakPalangX(400, 0, -100, 300);
    //palangKiri
    cetakPalangX(-401, 0, 401, 300); cetakPalangX(-400, 0, 250, 300);
    cetakPalangX(-401, 0, -401, 300); cetakPalangX(-400, 0, -250, 300);
    cetakPalangX(-400, 0, 100, 300); cetakPalangX(-400, 0, -100, 300);
}
void cetakPalangEkseteriorLantai2() {
    //palangDepan
    cetakPalangY(351, 0, 351, 240); cetakPalangY(107, 0, 350, 240);
    cetakPalangY(-351, 0, 351, 240); cetakPalangY(-107, 0, 350, 240);
    //palangBelakang
    cetakPalangY(351, 0, -351, 240); cetakPalangY(90, 0, -350, 240);
    cetakPalangY(-351, 0, -351, 240); cetakPalangY(-90, 0, -350, 240);
    //palangKanan
    cetakPalangX(351, 0, 351, 240); cetakPalangX(350, 0, 90, 240);
    cetakPalangX(351, 0, -351, 240); cetakPalangX(350, 0,-90, 240);
    //palangKiri
    cetakPalangX(-351, 0, 351, 240); cetakPalangX(-350, 0, 90, 240);
    cetakPalangX(-351, 0, -351, 240); cetakPalangX(-350, 0, -90, 240);
}
void cetakPalangEkseteriorLantai3() {
    //palangDepan
    cetakPalangY(301, 0, 301, 240); cetakPalangY(100, 0, 300, 240);
    cetakPalangY(-301, 0, 301,240); cetakPalangY(-100, 0, 300,240);
    //palangBelakang
    cetakPalangY(301, 0, -301, 240); cetakPalangY(80, 0, -300, 240);
    cetakPalangY(-301, 0, -301, 240); cetakPalangY(-80, 0, -300, 240);
    //palangKanan
    cetakPalangX(301, 0, 301, 240); cetakPalangX(300, 0, 80, 240);
    cetakPalangX(301, 0, -301, 240); cetakPalangX(300, 0, -80, 240);
    //palangKiri
    cetakPalangX(-301, 0, 301, 240); cetakPalangX(-300, 0, 80, 240);
    cetakPalangX(-301, 0, -301, 240); cetakPalangX(-300, 0, -80, 240);
}
void cetakPalangEkseteriorLantai4() {
    //palangDepan
    cetakPalangY(251, 0, 251, 240); cetakPalangY(80, 0, 250, 240);
    cetakPalangY(-251, 0, 251, 240); cetakPalangY(-80, 0, 250, 240);
    //palangBelakang
    cetakPalangY(251, 0, -251, 240); cetakPalangY(80, 0, -250, 240);
    cetakPalangY(-251, 0, -251, 240); cetakPalangY(-80, 0, -250, 240);
    //palangKanan
    cetakPalangX(251, 0, 251, 240); cetakPalangX(250, 0, 80, 240);
    cetakPalangX(251, 0, -251, 240); cetakPalangX(250, 0, -80, 240);
    //palangKiri
    cetakPalangX(-251, 0, 251, 240); cetakPalangX(-250, 0, 80, 240);
    cetakPalangX(-251, 0, -251, 240); cetakPalangX(-250, 0, -80, 240);
}

void cetakJendelaFullSenyumEksteriorLantai1() {
    //belakangCamera
    jendelaFullSenyum(136, 100, 401, 1); jendelaFullSenyum(278, 100, 401, 1);
    jendelaFullSenyum(-236, 100, 401, 1); jendelaFullSenyum(-379, 100, 401, 1);
    //kananCamera
    jendelaFullSenyum(401, 100, 125, 2); jendelaFullSenyum(401, 100, 275, 2);
    jendelaFullSenyum(401, 100, -225, 2); jendelaFullSenyum(401, 100, -375, 2);
    //depanCamera
    jendelaFullSenyum(125, 100, -401, 3); jendelaFullSenyum(275, 100, -401, 3);
    jendelaFullSenyum(-225, 100, -401, 3); jendelaFullSenyum(-375, 100, -401, 3);
    //kiriCamera
    jendelaFullSenyum(-401, 100, -125, 4); jendelaFullSenyum(-401, 100, -275, 4);
    jendelaFullSenyum(-401, 100, 225, 4); jendelaFullSenyum(-401, 100, 375, 4);
}
void cetakJendelaFullSedihEksteriorLantai2() {
    //depanCamera
    jendelaFullSedih(228, 100, 351,1); jendelaFullSedih(-228, 100, 351, 1);
    //kananCamera
    jendelaFullSedih(351, 100, 228, 2); jendelaFullSedih(351, 100, -228, 2);

    //belakangCamera
    jendelaFullSedih(228, 100, -351, 3); jendelaFullSedih(-228, 100, -351, 3);
    //kiriCamera
    jendelaFullSedih(-351, 100, 228, 4); jendelaFullSedih(-351, 100, -228, 4);
    
}
void cetakJendelaFullSempalEksteriorLantai3() {
    //depanCamera
    jendelaFullSempal(198, 130, 301, 1); jendelaFullSempal(-198, 130, 301, 1);
    //kananCamera
    jendelaFullSempal(301, 130, 188, 2); jendelaFullSempal(301, 130, -188, 2);
    //belakangCamera
    jendelaFullSempal(188, 130, -301, 3); jendelaFullSempal(-188, 130, -301, 3);
    //kiriCamera
    jendelaFullSempal(-301, 130, 188, 4); jendelaFullSempal(-301, 130, -188, 4);
}
void cetakJendelaFullSempalEksteriorLantai4() {
    //depanCamera
    jendelaFullSempal(165, 130, 251, 1); jendelaFullSempal(-165, 130, 251, 1);
    //kananCamera
    jendelaFullSempal(251, 130, 165, 2); jendelaFullSempal(251, 130, -165, 2);
    //belakangCamera
    jendelaFullSempal(165, 130, -251, 3); jendelaFullSempal(-165, 130, -251, 3);
    //kiriCamera
    jendelaFullSempal(-251, 130, 165, 4); jendelaFullSempal(-251, 130, -165, 4);
}

void balokHorizontalLantai1(float x, float y, float z, int sejajarSumbuX) {
    if (sejajarSumbuX == 0) {
        //Sejajar sumbu X
        glPushMatrix();glTranslatef(x, y, z);
        balok(150, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 1) {
        //Sejajar sumbu Z
        glPushMatrix();glTranslatef(x, y, z);
        balok(5, 20, 150, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 2) {
        //Sejajar sumbu X Depan
        glPushMatrix();glTranslatef(x, y, z);
        balok(140, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
}
void balokHorizontalLantai2(float x, float y, float z, int sejajarSumbuX) {
    if (sejajarSumbuX == 0) {
        //Sejajar sumbu X
        glPushMatrix();glTranslatef(x, y, z);
        balok(120, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 1) {
        //Sejajar sumbu Z
        glPushMatrix();glTranslatef(x, y, z);
        balok(5, 20, 120, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 2) {
        //Sejajar sumbu X Depan
        glPushMatrix();glTranslatef(x, y, z);
        balok(110, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
}
void balokHorizontalLantai3(float x, float y, float z, int sejajarSumbuX) {
    if (sejajarSumbuX == 0) {
        //Sejajar sumbu X
        glPushMatrix();glTranslatef(x, y, z);
        balok(100, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 1) {
        //Sejajar sumbu Z
        glPushMatrix();glTranslatef(x, y, z);
        balok(5, 20, 100, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 2) {
        //Sejajar sumbu X Depan
        glPushMatrix();glTranslatef(x, y, z);
        balok(90, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
}
void balokHorizontalLantai4(float x, float y, float z, int sejajarSumbuX) {
    if (sejajarSumbuX == 0) {
        //Sejajar sumbu X
        glPushMatrix();glTranslatef(x, y, z);
        balok(80, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 1) {
        //Sejajar sumbu Z
        glPushMatrix();glTranslatef(x, y, z);
        balok(5, 20, 80, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
    else if (sejajarSumbuX == 2) {
        //Sejajar sumbu X Depan
        glPushMatrix();glTranslatef(x, y, z);
        balok(80, 20, 5, 0.97f, 0.64f, 0.0f);
        glPopMatrix();
    }
}

void cetakbalokHorizontalLantai1() {
    //balokHorizontalLantai1Belakang
    balokHorizontalLantai1(231, 85, -404, 0); balokHorizontalLantai1(-231, 85, -404, 0);
    balokHorizontalLantai1(231, 205, -404, 0); balokHorizontalLantai1(-231, 205, -404, 0);
    //balokHorizontalLantai1Kiri
    balokHorizontalLantai1(-404, 85, 231, 1); balokHorizontalLantai1(-404, 85, -231, 1);
    balokHorizontalLantai1(-404, 205, 231, 1); balokHorizontalLantai1(-404, 205, -231, 1);
    //balokHorizontalLantai1Kanan
    balokHorizontalLantai1(404, 85, 231, 1); balokHorizontalLantai1(404, 85, -231, 1);
    balokHorizontalLantai1(404, 205, 231, 1); balokHorizontalLantai1(404, 205, -231, 1);
    //balokHorizontalLantai1Depan
    balokHorizontalLantai1(240, 85, 404, 2); balokHorizontalLantai1(-240, 85, 404, 2);
    balokHorizontalLantai1(240, 205, 404, 2); balokHorizontalLantai1(-240, 205, 404, 2);
}
void cetakbalokHorizontalLantai2() {
    //balokHorizontalLantai1Belakang
    balokHorizontalLantai2(221, 85, -354, 0); balokHorizontalLantai2(-221, 85, -354, 0);
    balokHorizontalLantai2(221, 205, -354, 0); balokHorizontalLantai2(-221, 205, -354, 0);
    //balokHorizontalLantai1Kiri
    balokHorizontalLantai2(-354, 85, 221, 1); balokHorizontalLantai2(-354, 85, -221, 1);
    balokHorizontalLantai2(-354, 205, 221, 1); balokHorizontalLantai2(-354, 205, -221, 1);
    //balokHorizontalLantai1Kanan
    balokHorizontalLantai2(354, 85, 221, 1); balokHorizontalLantai2(354, 85, -221, 1);
    balokHorizontalLantai2(354, 205, 221, 1); balokHorizontalLantai2(354, 205, -221, 1);
    //balokHorizontalLantai1Depan
    balokHorizontalLantai2(230, 85, 354, 2); balokHorizontalLantai2(-230, 85, 354, 2);
    balokHorizontalLantai2(230, 205, 354, 2); balokHorizontalLantai2(-230, 205, 354, 2);
}
void cetakbalokHorizontalLantai3() {
    //balokHorizontalLantai3Belakang
    balokHorizontalLantai3(181, 115, -304, 0); balokHorizontalLantai3(-181, 115, -304, 0);
    balokHorizontalLantai3(181, 205, -304, 0); balokHorizontalLantai3(-181, 205, -304, 0);
    //balokHorizontalLantai3Kiri
    balokHorizontalLantai3(-304, 115, 181, 1); balokHorizontalLantai3(-304, 115, -181, 1);
    balokHorizontalLantai3(-304, 205, 181, 1); balokHorizontalLantai3(-304, 205, -181, 1);
    //balokHorizontalLantai3Kanan
    balokHorizontalLantai3(304, 115, 181, 1); balokHorizontalLantai3(304, 115, -181, 1);
    balokHorizontalLantai3(304, 205, 181, 1); balokHorizontalLantai3(304, 205, -181, 1);
    //balokHorizontalLantai3Depan
    balokHorizontalLantai3(190, 115, 304, 2); balokHorizontalLantai3(-190, 115, 304, 2);
    balokHorizontalLantai3(190, 205, 304, 2); balokHorizontalLantai3(-190, 205, 304, 2);
}
void cetakbalokHorizontalLantai4() {
    //balokHorizontalLantai4Belakang
    balokHorizontalLantai4(151, 115, -254, 0); balokHorizontalLantai4(-151, 115, -254, 0);
    balokHorizontalLantai4(151, 205, -254, 0); balokHorizontalLantai4(-151, 205, -254, 0);
    //balokHorizontalLantai4Kiri
    balokHorizontalLantai4(-254, 115, 181, 1); balokHorizontalLantai4(-254, 115, -151, 1);
    balokHorizontalLantai4(-254, 205, 181, 1); balokHorizontalLantai4(-254, 205, -151, 1);
    //balokHorizontalLantai4Kanan
    balokHorizontalLantai4(254, 115, 151, 1); balokHorizontalLantai4(254, 115, -151, 1);
    balokHorizontalLantai4(254, 205, 151, 1); balokHorizontalLantai4(254, 205, -151, 1);
    //balokHorizontalLantai4Depan
    balokHorizontalLantai4(151, 115, 254, 2); balokHorizontalLantai4(-151, 115, 254, 2);
    balokHorizontalLantai4(151, 205, 254, 2); balokHorizontalLantai4(-151, 205, 254, 2);
}

void catPetiMinecraft(bool petiBesar) {
    float red = 0.97f, green = 0.56f, blue = 0.0f;
    if (petiBesar == true) {
        glPushMatrix(); glTranslatef(0, 4, 0);
        //catKuningBawah
        sisiAtasCamera(76, 76, 36, red, green, blue);
        sisiKananCamera(81, 48, 36, red, green, blue);
        sisiDepanCamera(76, 48, 41, red, green, blue);
        sisiKiriCamera(81, 48, 36, red, green, blue);
        sisiBelakangCamera(76, 48, 41, red, green, blue);
        glPopMatrix();
        glPushMatrix(); glTranslatef(0, 56, 0);
        //catKuningAtas
        sisiKananCamera(81, 20, 36, red, green, blue);
        sisiDepanCamera(76, 20, 41, red, green, blue);
        sisiKiriCamera(81, 20, 36, red, green, blue);
        sisiBelakangCamera(76, 20, 41, red, green, blue);
        glPopMatrix();
    }
    else {
        glPushMatrix(); glTranslatef(0, 4, 0);
        //catKuningBawah
        sisiAtasCamera(36, 76, 36, red, green, blue);
        sisiKananCamera(41, 48, 36, red, green, blue);
        sisiDepanCamera(36, 48, 41, red, green, blue);
        sisiKiriCamera(41, 48, 36, red, green, blue);
        sisiBelakangCamera(36, 48, 41, red, green, blue);
        glPopMatrix();
        glPushMatrix(); glTranslatef(0, 56, 0);
        //catKuningAtas
        sisiKananCamera(41, 20, 36, red, green, blue);
        sisiDepanCamera(36, 20, 41, red, green, blue);
        sisiKiriCamera(41, 20, 36, red, green, blue);
        sisiBelakangCamera(36, 20, 41, red, green, blue);
        glPopMatrix();
    }
}
void kunciPetiMinecraft(bool petiBesar, int posisi) {
    if (petiBesar == true) {
        switch (posisi)
        {
        case 1://belakangCamera
            glPushMatrix();glTranslatef(0, 45, -42);
            balok(5, 18, -4, 0.9, 0.9, 0.9);
            glPopMatrix();
            break;
        case 2://depanCamera
            glPushMatrix();glTranslatef(0, 45, 42);
            balok(5, 18, 4, 0.9, 0.9, 0.9);
            glPopMatrix();
            break;
        }
    }
    else if (petiBesar == false) {
        switch (posisi)
        {
        case 1://kananCamera
            glPushMatrix();glTranslatef(42, 45, 0);
            balok(4, 18, 5, 0.9, 0.9, 0.9);
            glPopMatrix();
            break;
        case 2://belakangCamera
            glPushMatrix();glTranslatef(0, 45, -42);
            balok(5, 18, -4, 0.9, 0.9, 0.9);
            glPopMatrix();
            break;
        case 3://kiriCamera
            glPushMatrix();glTranslatef(-42, 45, 0);
            balok(-5, 18, 4, 0.9, 0.9, 0.9);
            glPopMatrix();
            break;
        case 4://belakangCamera
            glPushMatrix();glTranslatef(0, 45, 42);
            balok(5, 18, 4, 0.9, 0.9, 0.9);
            glPopMatrix();
            break;
        }
    }
}
void petiMinecraft(float x, float y, float z, bool petiBesar, int posisi) {
    if (petiBesar == true) {
        glPushMatrix();glTranslatef(x, y, z);
        balok(80, 80, 40, 0.1, 0.1, 0.1);
        catPetiMinecraft(true);kunciPetiMinecraft(petiBesar, posisi);
        glPopMatrix();
    }
    else if (petiBesar == false) {
        glPushMatrix();glTranslatef(x, y, z);
        balok(40, 80, 40, 0.15, 0.15, 0.15);
        catPetiMinecraft(false);kunciPetiMinecraft(petiBesar, posisi);
        glPopMatrix();
    }
}
void karpet(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(300, 3, 200, 0.6, 0.6, 0.6);
    glPushMatrix();glTranslatef(0, 2, 0);
    balok(290, 1, 190, 0.7, 0.7, 0.7);
    glPopMatrix();glPopMatrix();
}
void bambu(float x, float y, float z, float tinggiBambu) {
    int tinggi = 0, i = 0, j = 0;
    glPushMatrix();glTranslatef(x, y, z);
    while (i < tinggiBambu)
    {
        glPushMatrix();glTranslatef(0, tinggi, 0);
        glPushMatrix();glTranslatef(0, 0, 0);
        balok(8, 36, 8, 0.4, 0.6, 0);
        glPopMatrix();
        glPushMatrix();glTranslatef(0, 34, 0);
        balok(8, 4, 8, 0.4, 0.7, 0);
        glPopMatrix();glPopMatrix();
        tinggi = tinggi + 36;
        i++;
    }
    glPopMatrix();
}
void bambuKecil(float x, float y, float z, float tinggiBambu) {
    int tinggi = 0, i = 0, j = 0;
    glPushMatrix();glTranslatef(x, y, z);
    while (i < tinggiBambu)
    {
        glPushMatrix();glTranslatef(0, tinggi, 0);
        glPushMatrix();glTranslatef(0, 0, 0);
        balok(4, 18, 4, 0.4, 0.6, 0);
        glPopMatrix();
        glPushMatrix();glTranslatef(0, 16, 0);
        balok(4, 4, 4, 0.4, 0.7, 0);
        glPopMatrix();glPopMatrix();
        tinggi = tinggi + 18;
        i++;
    }
    glPopMatrix();
}
void cetakBambuKecil(float x, float y, float z, float tinggiBambu) {
    glPushMatrix();glTranslatef(x, y, z);
    bambuKecil(-15,0,-15,tinggiBambu);
    bambuKecil(15, 0, -15,tinggiBambu-1);
    bambuKecil(15, 0, 15,tinggiBambu-2);
    bambuKecil(-15, 0, 15,tinggiBambu-3);
    glPopMatrix();
}
void pot(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(40, 20, 40, 0.6, 0.3, 0);
    glPushMatrix();glTranslatef(0, 17, 0);
    balok(35, 5, 35, 0.4, 0.2, 0);
    glPopMatrix();glPopMatrix();
}
void potDanBambu(float x, float y, float z, float tinggiBambu) {
    pot(x, y, z);
    bambu(x, y, z, tinggiBambu);
    cetakBambuKecil(x, y, z, tinggiBambu);
}

void pintuKuil(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(5, 220, 70, 1, 0.5, 0);
    glPushMatrix();glTranslatef(-2, 180, 0);
    balok(4, 10, 69, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();glTranslatef(-2, 130, 0);
    balok(4, 10, 69, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();glTranslatef(-2, 80, 0);
    balok(4, 10, 69, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();glTranslatef(-2, 30, 0);
    balok(4, 10, 69, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();glTranslatef(-3, 0, 4);
    balok(4, 221, 10, 1, 0.6, 0.2);
    glPopMatrix();glPopMatrix();
}
void cetakPintuKuil(int lantai) {
    if (lantai == 1) {
        pintuKuil(-399.0 , 0, 0);
        glPushMatrix();glRotatef(180, 0.0, -1.0, 0.0);
        pintuKuil(-399.0 , 0, 0);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
        pintuKuil(-399.0 , 0, 0);
        glPopMatrix();
    }else if (lantai == 2) {
        pintuKuil(-349, 0, 0);
        glPushMatrix();glRotatef(180, 0.0, -1.0, 0.0);
        pintuKuil(-349, 0, 0);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
        pintuKuil(-349, 0, 0);
        glPopMatrix();
    }
    else if (lantai == 3) {
        pintuKuil(-299, 0, 0);
        glPushMatrix();glRotatef(180, 0.0, -1.0, 0.0);
        pintuKuil(-299, 0, 0);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
        pintuKuil(-299, 0, 0);
        glPopMatrix();
    }
    else if (lantai == 4) {
        pintuKuil(-249, 0, 0);
        glPushMatrix();glRotatef(180, 0.0, -1.0, 0.0);
        pintuKuil(-249, 0, 0);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
        pintuKuil(-249, 0, 0);
        glPopMatrix();
    } 
}
void jendela(int lantai) {
    if (lantai == 2)
    {
        int pergeseran = -45, i = 0;
        balok(60, 120, 2, 1, 0.5, 0.2);
        balok(50, 100, 3, 1, 1, 0.2);
        while (i < 10)
        {
            glPushMatrix();glTranslatef(pergeseran, 0, 0);
            balok(2, 101, 4, 0.1, 0.1, 0.1);
            glPopMatrix();
            pergeseran = pergeseran + 10;
            i++;
        }

    }
    else if (lantai == 3) {
        int pergeseran = -28, i = 0;
        balok(40, 80, 2, 1, 0.5, 0.2);
        balok(35, 70, 3, 1, 1, 0.2);
        while (i < 8)
        {
            glPushMatrix();glTranslatef(pergeseran, 0, 0);
            balok(2, 70, 4, 0.1, 0.1, 0.1);
            glPopMatrix();
            pergeseran = pergeseran + 8;
            i++;
        }
    }
}
void jendelaFullSenyum(float x1, float y1, float z1, int posisi) {
    layer = 0;
    if (posisi == 1) {//belakangCamera
        glPushMatrix(); glTranslatef(x1, y1, z1);//kanvasJendela
        kotak(100, 100, 0, 0, 0);
        glPopMatrix();
        layer++;
        glPushMatrix(); glTranslatef(x1 + 2, y1 + 2, z1 + layer);//layer1Jendela
        kotak(95, 95, 1, 1, 0.8);
        glPopMatrix();
        layer++;
        glPushMatrix(); glTranslatef(x1 + 2, y1 + 60, z1 + layer);//layer2Jendela
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        glPushMatrix(); glTranslatef(x1 + 2, y1 + 30, z1 + layer);//layer2Jendela
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        layer++;
        glPushMatrix(); glTranslatef(x1 + 45, y1 + 2, z1 + layer);//layer3Jendela
        kotak(10, 95, 0, 0, 0);
        glPopMatrix();
    }
    else if (posisi == 2) {//kananCamera
        glPushMatrix(); glTranslatef(x1, y1, z1);//kanvasJendela
        glRotatef(90.0, 0, -1.0, 0);
        kotak(100, 100, 0, 0, 0);
        glPopMatrix();
        layer++;
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 2, z1 + 2);//layer1Jendela
        glRotatef(90.0, 0, -1.0, 0);
        kotak(95, 95, 1, 1, 0.8);
        glPopMatrix();
        layer++;
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 60, z1 + 2);//layer2Jendela
        glRotatef(90.0, 0, -1.0, 0);
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 30, z1 + 2);//layer2Jendela
        glRotatef(90.0, 0, -1.0, 0);
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        layer++;
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 2, z1 + 45);//layer3Jendela
        glRotatef(90.0, 0, -1.0, 0);
        kotak(10, 95, 0, 0, 0);
        glPopMatrix();
    }
    else if (posisi == 3) {//depanCamera
        glPushMatrix(); glTranslatef(x1, y1, z1);//kanvasJendela
        kotak(100, 100, 0, 0, 0);
        glPopMatrix();
        layer--;
        glPushMatrix(); glTranslatef(x1 + 2, y1 + 2, z1 + layer);//layer1Jendela
        kotak(95, 95, 1, 1, 0.8);
        glPopMatrix();
        layer--;
        glPushMatrix(); glTranslatef(x1 + 2, y1 + 60, z1 + layer);//layer2Jendela
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        glPushMatrix(); glTranslatef(x1 + 2, y1 + 30, z1 + layer);//layer2Jendela
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        layer--;
        glPushMatrix(); glTranslatef(x1 + 45, y1 + 2, z1 + layer);//layer3Jendela
        kotak(10, 95, 0, 0, 0);
        glPopMatrix();
    }
    else if (posisi == 4) {
        glPushMatrix(); glTranslatef(x1, y1, z1);//kanvasJendela
        glRotatef(90.0, 0, 1.0, 0);
        kotak(100, 100, 0, 0, 0);
        glPopMatrix();
        layer--;
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 2, z1 - 2);//layer1Jendela
        glRotatef(90.0, 0, 1.0, 0);
        kotak(95, 95, 1, 1, 0.8);
        glPopMatrix();
        layer--;
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 60, z1 - 2);//layer2Jendela
        glRotatef(90.0, 0, 1.0, 0);
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 30, z1 - 2);//layer2Jendela
        glRotatef(90.0, 0, 1.0, 0);
        kotak(95, 5, 0.9, 0.9, 0.9);
        glPopMatrix();
        layer--;
        glPushMatrix(); glTranslatef(x1 + layer, y1 + 2, z1 - 45);//layer3Jendela
        glRotatef(90.0, 0, 1.0, 0);
        kotak(10, 95, 0, 0, 0);
        glPopMatrix();
    }
    else {
        printf("value posisi tidak sesuai");
    }
}
void jendelaFullSedih(float x, float y, float z,int posisi) {
    glPushMatrix();
    glTranslatef(x,y,z);
    if (posisi == 1){
        jendela(2);
    }
    else if (posisi == 2) {
        glPushMatrix(); glRotatef(90, 0.0, 1.0, 0.0);
        jendela(2); glPopMatrix();
    }
    else if (posisi == 3) {
        glPushMatrix();glRotatef(180,0.0,1.0,0.0);
        jendela(2);glPopMatrix();
    }
    else if (posisi == 4) {
        glPushMatrix(); glRotatef(90, 0.0, -1.0, 0.0);
        jendela(2); glPopMatrix();
    }
    else {

    }
    glPopMatrix();
}
void jendelaFullSempal(float x, float y, float z, int posisi) {
    glPushMatrix();
    glTranslatef(x, y, z);
    if (posisi == 1) {
        jendela(3);
    }
    else if (posisi == 2) {
        glPushMatrix(); glRotatef(90, 0.0, 1.0, 0.0);
        jendela(3); glPopMatrix();
    }
    else if (posisi == 3) {
        glPushMatrix(); glRotatef(180, 0.0, 1.0, 0.0);
        jendela(3); glPopMatrix();
    }
    else if (posisi == 4) {
        glPushMatrix(); glRotatef(90, 0.0, -1.0, 0.0);
        jendela(3); glPopMatrix();
    }
    else {

    }
    glPopMatrix();
}

void potBambuLantai0() {
    potDanBambu(-760, 0, 640, 10);
    potDanBambu(-760, 0, 540, 8);
    potDanBambu(-760, 0, 440, 6);
    petiMinecraft(-760, 0, 340, false, 3);
    potDanBambu(-760, 0, -640, 10);
    potDanBambu(-760, 0, -540, 8);
    potDanBambu(-760, 0, -440, 6);
    petiMinecraft(-760, 0, -340, false, 3);
}
void eksteriorLantai0() {
    potBambuLantai0();
    glPushMatrix(); glRotatef(90, 0.0, -1.0, 0.0);
    potBambuLantai0();
    glPopMatrix();
    glPushMatrix(); glRotatef(180, 0.0, -1.0, 0.0);
    potBambuLantai0();
    glPopMatrix();
    gentong(750, 0, 750, 1);
    gentong(750, 0, -750, 1);
    gentong(-750, 0, 750, 1);
    gentong(-750, 0, -750, 1);
    gentong(-365, 0, 760, 2);
    gentong(365, 0, 760, 2);
    tianglampu();
}
void interiorLantai1() {
    glPushMatrix();
    glRotatef(90,0.0,-1.0,0.0);
    petiMinecraft(0, 0, -340, true, 2);
    glPopMatrix();
    karpet(0, 0, -190);
    petiMinecraft(330, 0, 330, false, 3);
    petiMinecraft(-330, 0, 330, false, 1);
    potDanBambu(-340, 0, -340, 6);
    potDanBambu(340, 0, -340, 6);
    cetakKursi();
    cetakLemari();
    glPushMatrix();
    glTranslatef(0,0,-180);
    cetakLemari();
    glPopMatrix();
    cetakLampuGantung(-150,120,-360);
    cetakLampuGantung(150, 120, -360);
    cetakMeja();
    tampilBabiMinecraft();
    tampilEndermanMinecraft();
    gentong(-640, 0, 640, 2);
    gentong(-190, 0, 450, 1);
    gentong(190, 0, 450, 1);
    cetakTempatsampah(0, 0, 0);
    potDanBambu(-640, -200, 760, 10);
    potDanBambu(-540, -200, 760, 8);
    potDanBambu(-440, -200, 760, 6);
    potDanBambu(640, -200, 760, 10);
    potDanBambu(540, -200, 760, 8);
    potDanBambu(440, -200, 760, 6);
    replikaSeigantoji(0,40,-240);
    cetakBalokReplika();
    lampuFTI2022();
}
void eksteriorLantai1() {
    cetakPalangEkseteriorLantai1();
    cetakPintuLuar(1);
    cetakPintuDalam(1);
    cetakJendelaFullSenyumEksteriorLantai1();
    cetakbalokHorizontalLantai1();
    cetakPintuKuil(1);
    cetakBalokVertikal(1);
    cetakBalokPenyangga();  
}
void interiorLantai2() {
    petiMinecraft(0, 0, -280, true, 2);
    petiMinecraft(200, 0, -280, false, 4);
    petiMinecraft(-200, 0, -280, false, 4);
}
void eksteriorLantai2() {
    cetakPalangEkseteriorLantai2();
    cetakbalokHorizontalLantai2();
    cetakJendelaFullSedihEksteriorLantai2();
    cetakPintuKuil(2);
    cetakAtapSeiganToJiLantai2();
    cetakBalokVertikal(2);
    tampilPagarKayu();
    cetakPenyanggaAtap(2);
    cetakPintuLuar(2);
    cetakPintuDalam(2);
}
void interiorLantai3() {
    petiMinecraft(0, 40, -250, true, 2);
    petiMinecraft(200, 40, -250, false, 4);
    petiMinecraft(-200, 40, -250, false, 4);
}
void eksteriorLantai3() {
    cetakPalangEkseteriorLantai3();
    cetakJendelaFullSempalEksteriorLantai3();
    cetakbalokHorizontalLantai3();
    cetakPintuKuil(3);
    cetakAtapSeiganToJiLantai3();
    cetakBalokVertikal(3);
    cetakTerasLantai3();
    pagarKayuTerasLantai3();
    cetakUjungAtap(3);
    cetakPenyanggaAtap(3);
    cetakPintuDalam(3);
}
void interiorLantai4() {
    petiMinecraft(0, 40, -200, true, 2);
    petiMinecraft(180, 40, -200, false, 4);
    petiMinecraft(-180, 40, -200, false, 4);
    cetakbintang();
}
void eksteriorLantai4() {
    cetakPalangEkseteriorLantai4();
    cetakbalokHorizontalLantai4();
    cetakJendelaFullSempalEksteriorLantai4();
    cetakPintuKuil(4);
    cetakKubahSeiganToJi();
    cetakBalokVertikal(4);
    cetakTerasLantai4();
    pagarKayuTerasLantai4();
    cetakUjungAtap(4);
    cetakPinggiranAtap();
    cetakAtapSeiganToJiLantai4();
    cetakPenyanggaAtap(4);
    cetakPintuDalam(4);
    cetakpetir();
}

void atapSeiganToJi(float x,float tinggi,  float red, float green, float blue) {
    glBegin(GL_QUADS);//bawah
    glColor3f(red, green, blue);glVertex3f(x, 40, 0);
    glColor3f(red, green, blue);glVertex3f(-x, 40, 0);
    glColor3f(red, green, blue);glVertex3f(-x-200, 0, 200);
    glColor3f(red, green, blue);glVertex3f(x+200, 0, 200);
    glEnd();
    glBegin(GL_QUADS);//atas
    glColor3f(red, green, blue); glVertex3f(x, 0 + tinggi, 0);
    glColor3f(red, green, blue); glVertex3f(-x, 0 + tinggi, 0);
    glColor3f(red, green, blue); glVertex3f(-x - 200, 0, 200);
    glColor3f(red, green, blue); glVertex3f(x + 200, 0, 200);
    glEnd();
    glBegin(GL_QUADS);//tepi
    glColor3f(red, green, blue); glVertex3f(x, 40, 0);
    glColor3f(red, green, blue); glVertex3f(-x, 40, 0);
    glColor3f(red, green, blue); glVertex3f(-x , 0 + tinggi, 0);
    glColor3f(red, green, blue); glVertex3f(x , 0 + tinggi, 0);
    glEnd();
}
void kubahSeiganToJi() {
    glBegin(GL_QUADS);//bawah
    glColor3f(0, 0.4, 0.2); glVertex3f(40, 300, 40);
    glColor3f(0, 0.4, 0.2); glVertex3f(-40, 300, 40);
    glColor3f(0, 0.6, 0.3); glVertex3f(-450, 0, 450);
    glColor3f(0, 0.6, 0.3); glVertex3f(450, 0, 450);
    glEnd();
}
void algoritmaAtapSeiganToJi(int lantai) {
    if (lantai == 2)
    {
        glPushMatrix();//bawah
        glTranslatef(0, 300, 350);
        atapSeiganToJi(350, 70, 0, 0.4, 0.2);
        glPopMatrix();
    }else if (lantai == 3)
    {
        glPushMatrix();//bawah
        glTranslatef(0, 300, 300);
        atapSeiganToJi(300, 50, 0, 0.4, 0.2);
        glPopMatrix();
    }
    else if (lantai == 4) {
        glPushMatrix();//bawah
        glTranslatef(0, 300, 250);
        atapSeiganToJi(250, 50, 0, 0.4, 0.2);
        glPopMatrix();
    }
}
void cetakAtapSeiganToJiLantai2() {
    algoritmaAtapSeiganToJi(2);//depan
    glPushMatrix();//belakang
    glRotatef(180,0.0,1.0,0.0);
    algoritmaAtapSeiganToJi(2);
    glPopMatrix();
    glPushMatrix();//kanan
    glRotatef(90, 0.0, 1.0, 0.0);
    algoritmaAtapSeiganToJi(2);
    glPopMatrix();
    glPushMatrix();//kiri
    glRotatef(90, 0.0, -1.0, 0.0);
    algoritmaAtapSeiganToJi(2);
    glPopMatrix();
}
void cetakAtapSeiganToJiLantai3() {
    algoritmaAtapSeiganToJi(3);//depan
    glPushMatrix();//belakang
    glRotatef(180, 0.0, 1.0, 0.0);
    algoritmaAtapSeiganToJi(3);
    glPopMatrix();
    glPushMatrix();//kanan
    glRotatef(90, 0.0, 1.0, 0.0);
    algoritmaAtapSeiganToJi(3);
    glPopMatrix();
    glPushMatrix();//kiri
    glRotatef(90, 0.0, -1.0, 0.0);
    algoritmaAtapSeiganToJi(3);
    glPopMatrix();
}
void cetakAtapSeiganToJiLantai4() {
    algoritmaAtapSeiganToJi(4);//depan
    glPushMatrix();//belakang
    glRotatef(180, 0.0, 1.0, 0.0);
    algoritmaAtapSeiganToJi(4);
    glPopMatrix();
    glPushMatrix();//kanan
    glRotatef(90, 0.0, 1.0, 0.0);
    algoritmaAtapSeiganToJi(4);
    glPopMatrix();
    glPushMatrix();//kiri
    glRotatef(90, 0.0, -1.0, 0.0);
    algoritmaAtapSeiganToJi(4);
    glPopMatrix();
}

void terasLantai3() {
    glBegin(GL_QUADS);//bawah
    glColor3f(0.9, 0.9, 0.9); glVertex3f(300, 100, 300);
    glColor3f(0.9, 0.9, 0.9); glVertex3f(-300, 100, 300);
    glColor3f(0.9, 0.9, 0.9); glVertex3f(-400, 100, 400);
    glColor3f(0.9, 0.9, 0.9); glVertex3f(400, 100, 400);
    glEnd();
}
void cetakTerasLantai3() {
    terasLantai3();
    glPushMatrix();glRotatef(180.0,0.0,1.0,0.0);
    terasLantai3();
    glPopMatrix();
    glPushMatrix();glRotatef(90.0, 0.0, 1.0, 0.0);
    terasLantai3();
    glPopMatrix();
    glPushMatrix();glRotatef(90.0, 0.0, -1.0, 0.0);
    terasLantai3();
    glPopMatrix();
}
void terasLantai4() {
    glBegin(GL_QUADS);//bawah
    glColor3f(0.9, 0.9, 0.9); glVertex3f(259, 80, 259);
    glColor3f(0.9, 0.9, 0.9); glVertex3f(-259, 80, 259);
    glColor3f(0.9, 0.9, 0.9); glVertex3f(-370, 80, 370);
    glColor3f(0.9, 0.9, 0.9); glVertex3f(370, 80, 370);
    glEnd();
}
void cetakTerasLantai4() {
    terasLantai4();
    glPushMatrix();glRotatef(180.0, 0.0, 1.0, 0.0);
    terasLantai4();
    glPopMatrix();
    glPushMatrix();glRotatef(90.0, 0.0, 1.0, 0.0);
    terasLantai4();
    glPopMatrix();
    glPushMatrix();glRotatef(90.0, 0.0, -1.0, 0.0);
    terasLantai4();
    glPopMatrix();
}
void cetakKubahSeiganToJi() {
    glPushMatrix();glTranslatef(0,300,0);
    kubahSeiganToJi();glPopMatrix();
    glPushMatrix();glTranslatef(0, 300, 0);
    glRotatef(180,0.0,1.0,0.0);kubahSeiganToJi();
    glPopMatrix();glPushMatrix();
    glTranslatef(0, 300, 0);glRotatef(90, 0.0, 1.0, 0.0);
    kubahSeiganToJi();glPopMatrix();
    glPushMatrix();glTranslatef(0, 300, 0);
    glRotatef(90, 0.0, -1.0, 0.0); kubahSeiganToJi();
    glPopMatrix();
}
void balokVertikal(float x, float y, float z, float panjang) {
    glPushMatrix(); glTranslatef(x, y, z);
    balok(panjang, 30, 15, 1, 0.5, 0);
    glPopMatrix();
}
void balokVertikalKecil(float x, float y, float z, float panjang) {
    glPushMatrix(); glTranslatef(x, y, z);
    balok(panjang, 15, 8, 1, 0.5, 0);
    glPopMatrix();
}
void cetakBalokVertikal(int lantai) {
    if (lantai == 1)
    {
        balokVertikal(0,270,401,400);
        glPushMatrix();glRotatef(180,0.0,1.0,0.0);
        balokVertikal(0, 270, 401, 400);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, 1.0, 0.0);
        balokVertikal(0, 270, 401, 400);
        glPopMatrix();
        glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
        balokVertikal(0, 270, 401, 400);
        glPopMatrix();
    }else if (lantai == 2) {
        balokVertikalKecil(0, 230, 355, 370);
        balokVertikalKecil(0, 250, 355, 370);
        glPushMatrix(); glRotatef(180, 0.0, 1.0, 0.0);
        balokVertikalKecil(0, 230, 355, 370);
        balokVertikalKecil(0, 250, 355, 370);
        glPopMatrix();
        glPushMatrix(); glRotatef(90, 0.0, 1.0, 0.0);
        balokVertikalKecil(0, 230, 355, 370);
        balokVertikalKecil(0, 250, 355, 370);
        glPopMatrix();
        glPushMatrix(); glRotatef(90, 0.0, -1.0, 0.0);
        balokVertikalKecil(0, 230, 355, 370);
        balokVertikalKecil(0, 250, 355, 370);
        glPopMatrix();
    }
    else if (lantai == 3) {
        balokVertikalKecil(0, 230, 305, 320);
        balokVertikalKecil(0, 250, 305, 320);
        glPushMatrix(); glRotatef(180, 0.0, 1.0, 0.0);
        balokVertikalKecil(0, 230, 305, 320);
        balokVertikalKecil(0, 250, 305, 320);
        glPopMatrix();
        glPushMatrix(); glRotatef(90, 0.0, 1.0, 0.0);
        balokVertikalKecil(0, 230, 305, 320);
        balokVertikalKecil(0, 250, 305, 320);
        glPopMatrix();
        glPushMatrix(); glRotatef(90, 0.0, -1.0, 0.0);
        balokVertikalKecil(0, 230, 305, 320);
        balokVertikalKecil(0, 250, 305, 320);
        glPopMatrix();
    }
    else if (lantai == 4) {
        balokVertikalKecil(0, 230, 255, 270);
        balokVertikalKecil(0, 250, 255, 270);
        glPushMatrix(); glRotatef(180, 0.0, 1.0, 0.0);
        balokVertikalKecil(0, 230, 255, 270);
        balokVertikalKecil(0, 250, 255, 270);
        glPopMatrix();
        glPushMatrix(); glRotatef(90, 0.0, 1.0, 0.0);
        balokVertikalKecil(0, 230, 255, 270);
        balokVertikalKecil(0, 250, 255, 270);
        glPopMatrix();
        glPushMatrix(); glRotatef(90, 0.0, -1.0, 0.0);
        balokVertikalKecil(0, 230, 255, 270);
        balokVertikalKecil(0, 250, 255, 270);
        glPopMatrix();
    }
    
}
void balokPenyangga(float x, float y, float z) {
    glPushMatrix();glTranslatef(x,y,z);
    balok(15,8,150,1,0.5,0);
        glPushMatrix();glTranslatef(0, -12,-50);
        balok(15, 16, 100, 1, 0.5, 0);
        glPopMatrix();
        glPushMatrix();glTranslatef(0, -16, -100);
        balok(15, 24, 50, 1, 0.5, 0);
        glPopMatrix();
    glPopMatrix();
}
void cetakBalokPenyangga() {
    balokPenyangga(-115, 292,550); balokPenyangga(115, 292, 550);//depan
    balokPenyangga(-257, 292, 550); balokPenyangga(257, 292, 550);
    balokPenyangga(-400, 292, 550); balokPenyangga(400, 292, 550);
    glPushMatrix();glRotatef(180,0.0,1.0,0.0);
    balokPenyangga(-100, 292, 550); balokPenyangga(100, 292, 550);//belakang
    balokPenyangga(-250, 292, 550); balokPenyangga(250, 292, 550);
    balokPenyangga(-400, 292, 550); balokPenyangga(400, 292, 550);
    glPopMatrix();
    glPushMatrix();glRotatef(90, 0.0, 1.0, 0.0);
    balokPenyangga(-100, 292, 550); balokPenyangga(100, 292, 550);//belakang
    balokPenyangga(-250, 292, 550); balokPenyangga(250, 292, 550);
    balokPenyangga(-400, 292, 550); balokPenyangga(400, 292, 550);
    glPopMatrix();
    glPushMatrix();glRotatef(90, 0.0, -1.0, 0.0);
    balokPenyangga(-100, 292, 550); balokPenyangga(100, 292, 550);//belakang
    balokPenyangga(-250, 292, 550); balokPenyangga(250, 292, 550);
    balokPenyangga(-400, 292, 550); balokPenyangga(400, 292, 550);
    glPopMatrix();
}

void pagarKayu(float x, float y, float z, float panjang) {
    glPushMatrix();glTranslatef(x,y,z);
    balok(panjang,4,5,1.0,0.6,0.2);
    glPopMatrix();
}
void pagarKayuTebal(float x, float y, float z, float panjang) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(panjang, 8, 6, 1.0, 0.5, 0.0);
    glPopMatrix();
}
void pagarKayuTebalVertikal(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(6, 47, 6, 1.0, 0.5, 0.0);
    glPopMatrix();
}
void pagarKayuTebalVertikalPendek(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(6, 29, 6, 1.0, 0.5, 0.0);
    glPopMatrix();
}
void cetakPagarKayu() {
    glPushMatrix();glTranslatef(694,0,694);
    balok(6, 55, 6, 1.0, 0.5, 0.0);
    glPopMatrix();
    glPushMatrix();glTranslatef(-694, 0, 694);
    balok(6, 55, 6, 1.0, 0.5, 0.0);
    glPopMatrix();
    pagarKayu(0,0,692,699);
    pagarKayuTebal(0,8,692,700);
    pagarKayu(0, 18, 692, 699);
    pagarKayu(0, 27, 692, 699);
    pagarKayuTebal(0, 37, 692, 700);
    pagarKayuTebal(0, 55, 692, 700);
}
void cetakPagarKayuVertikal() {
    pagarKayuTebalVertikal(0, 10, 692);
    pagarKayuTebalVertikalPendek(70, 10, 692);
    pagarKayuTebalVertikal(140, 10, 692);
    pagarKayuTebalVertikalPendek(210, 10, 692);
    pagarKayuTebalVertikal(280, 10, 692);
    pagarKayuTebalVertikalPendek(350, 10, 692);
    pagarKayuTebalVertikal(420, 10, 692);
    pagarKayuTebalVertikalPendek(490, 10, 692);
    pagarKayuTebalVertikal(560, 10, 692);
    pagarKayuTebalVertikalPendek(630, 10, 692);
    pagarKayuTebalVertikal(694, 10, 692);
    pagarKayuTebalVertikalPendek(-70, 10, 692);
    pagarKayuTebalVertikal(-140, 10, 692);
    pagarKayuTebalVertikalPendek(-210, 10, 692);
    pagarKayuTebalVertikal(-280, 10, 692);
    pagarKayuTebalVertikalPendek(-350, 10, 692);
    pagarKayuTebalVertikal(-420, 10, 692);
    pagarKayuTebalVertikalPendek(-490, 10, 692);
    pagarKayuTebalVertikal(-560, 10, 692);
    pagarKayuTebalVertikalPendek(-630, 10, 692);
    pagarKayuTebalVertikal(-694, 10, 692);
}
void tampilPagarKayu() {
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPushMatrix(); glRotatef(180, 0.0, 1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix(); glRotatef(90, 0.0, 1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix(); glRotatef(90, 0.0, -1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
}
void pagarKayuTerasLantai3() {
    glPushMatrix();glTranslatef(0,100,0);
    glScalef(0.57,0.65,0.57);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 100, 0);
    glScalef(0.57, 0.65, 0.57); glRotatef(180, 0.0, 1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 100, 0);
    glScalef(0.57, 0.65, 0.57); glRotatef(90, 0.0, 1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 100, 0);
    glScalef(0.57, 0.65, 0.57); glRotatef(90, 0.0, -1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
}
void pagarKayuTerasLantai4() {
    glPushMatrix(); glTranslatef(0, 80, 0);
    glScalef(0.53, 0.90, 0.53);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 80, 0);
    glScalef(0.53, 0.90, 0.53); glRotatef(180, 0.0, 1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 80, 0);
    glScalef(0.53, 0.90, 0.53); glRotatef(90, 0.0, 1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 80, 0);
    glScalef(0.53, 0.90, 0.53); glRotatef(90, 0.0,-1.0, 0.0);
    cetakPagarKayu();
    cetakPagarKayuVertikal();
    glPopMatrix();
}

void algoritmaPenyanggaAtap(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(15, 75, 15, 0.55f, 0.27f, 0.07f);
    glPushMatrix();glTranslatef(0, 0, 20);
    balok(15, 15, 15, 0.55f, 0.27f, 0.07f);
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 13, 40);
    balok(15, 15, 15, 0.55f, 0.27f, 0.07f);
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 26, 60);
    balok(15, 15, 15, 0.55f, 0.27f, 0.07f);
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 39, 80);
    balok(15, 15, 15, 0.55f, 0.27f, 0.07f);
    glPopMatrix();
    glPushMatrix(); glTranslatef(0, 52, 40);
    balok(15, 15, 50, 0.55f, 0.27f, 0.07f);
    glPopMatrix();glPopMatrix();
}
void penyanggaAtap() {
    algoritmaPenyanggaAtap(70, 266, 355); algoritmaPenyanggaAtap(-70, 266, 355);
    algoritmaPenyanggaAtap(210, 266, 355); algoritmaPenyanggaAtap(-210, 266, 355);
    algoritmaPenyanggaAtap(340, 266, 355); algoritmaPenyanggaAtap(-340, 266, 355);
}
void cetakPenyanggaAtap(int lantai) {
    if (lantai == 2)
    {
        penyanggaAtap();
        glPushMatrix();glRotatef(180.0, 0.0, 1.0, 0.0);
        penyanggaAtap();
        glPopMatrix();
        glPushMatrix();glRotatef(90.0, 0.0, 1.0, 0.0);
        penyanggaAtap();
        glPopMatrix();
        glPushMatrix();glRotatef(90.0, 0.0, -1.0, 0.0);
        penyanggaAtap();
        glPopMatrix();
    }
    else if (lantai == 3)
    {
        glPushMatrix();
        glScalef(0.88,1,0.88);
        cetakPenyanggaAtap(2);
        glPopMatrix();
    }
    else if (lantai == 4)
    {
        glPushMatrix();
        glScalef(0.73, 1, 0.73);
        cetakPenyanggaAtap(2);
        glPopMatrix();
    }
}
void tanganTangga(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(40.0, 230, 30.0, red, green, blue);
    glPopMatrix();
    glPushMatrix();glTranslatef(x, y, z + 140);
    balok(40.0, 31.0, 140.0, red, green, blue);
    glPopMatrix();
}
void tangga(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(250.0, 198.0, 30.0, red, green, blue);
    balok(250.0, 200.0, 29.0, 0.85, 0.85, 0.85);
    glPopMatrix();
    glPushMatrix();glTranslatef(x, y, z + 50);
    balok(250.0, 160.0, 30.0, red, green, blue);
    balok(250.0, 161.0, 29.0, 0.85, 0.85, 0.85);
    glPopMatrix();
    glPushMatrix();glTranslatef(x, y, z + 100);
    balok(250.0, 120.0, 30.0, red, green, blue);
    balok(250.0, 121.0, 29.0, 0.85, 0.85, 0.85);
    glPopMatrix();
}
void tangga2(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z + 150);
    balok(250.0, 80.0, 30.0, red, green, blue);
    balok(250.0, 81.0, 29.0, 0.85, 0.85, 0.85);
    glPopMatrix();
    glPushMatrix();glTranslatef(x, y, z + 200);
    balok(250.0, 40.0, 30.0, red, green, blue);
    balok(250.0, 41.0, 29.0, 0.85, 0.85, 0.85);
    glPopMatrix();
    glPushMatrix();glTranslatef(x, y, z + 250);
    balok(250.0, 0.0, 30.0, red, green, blue);
    balok(250.0, 5.0, 29.0, 0.85, 0.85, 0.85);
    glPopMatrix();
    
}
void samping(float x, float y, float z) {
    //samping
    glPushMatrix();glTranslatef(x, y, z);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 229.0, 0.0);
    glVertex3f(0.0, 30.0, 200.0);
    glEnd();glPopMatrix();
}
void balokTanganTangga(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    glRotatef(45, 1, 0, 0);
    balok(40, 30, 140, 0.6, 0.6, 0.6);
    glPopMatrix();
}
void cetakTangga() {
    //anak tangga
    tangga(0.0, 0.0, 720.0, 0.8, 0.8, 0.8);
    tangga2(0.0, 0.0, 720.0, 0.8, 0.8, 0.8);
    tanganTangga(-290.0, 0, 720, 0.6, 0.6, 0.6);
    tanganTangga(290.0, 0, 720, 0.6, 0.6, 0.6);
    //batas kanan
    balokTanganTangga(290, 95, 842);
    samping(330, 0, 750);samping(250, 0, 750);
    //batas kiri
    balokTanganTangga(-290, 95, 842);
    samping(-330, 0, 750);samping(-250, 0, 750);
}
void tiangPagar(float x, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, 199.0, z);
    balok(10.0, 100.0, 10.0, red, green, blue);
    glPopMatrix();
    glPushMatrix();glColor3f(0.8, 0.8, 0.8);glTranslatef(x, 307.0, z);
    glutSolidSphere(10.0, 64, 64);
    glPopMatrix();
    glPushMatrix();glColor3f(1.0f, 1.0f, 0.25f);glTranslatef(x, 307.0, z);
    glutSolidSphere(9.91 + y_geser, 64, 64);
    glPopMatrix();
}
void tiangDepan(float x) {
    tiangPagar(x, 691.0, 0.3, 0.3, 0.3);
}
void tiangBelakang(float x) {
    tiangPagar(x, -691.0, 0.3, 0.3, 0.3);
}
void tiangKanan(float z) {
    tiangPagar(690.0, z, 0.3, 0.3, 0.3);
}
void tiangKiri(float z) {
    tiangPagar(-690.0, z, 0.3, 0.3, 0.3);
}
void cetakPagarVertikal(int posisi) {
    if (posisi == 1)//depan
    {
        tiangDepan(690.0);
        tiangDepan(510.0);
        tiangDepan(330.0);
        tiangDepan(-690.0);
        tiangDepan(-510.0);
        tiangDepan(-330.0);
    }
    else if (posisi == 2)//kanan
    {
        tiangKanan(690.0);
        tiangKanan(517.0);
        tiangKanan(345.0);
        tiangKanan(172.0);
        tiangKanan(0.0);
        tiangKanan(-172.0);
        tiangKanan(-345.0);
        tiangKanan(-517.0);
        tiangKanan(-690.0);
    }
    else if (posisi == 3)//kiri
    {
        tiangKiri(690.0);
        tiangKiri(517.0);
        tiangKiri(345.0);
        tiangKiri(172.0);
        tiangKiri(0.0);
        tiangKiri(-172.0);
        tiangKiri(-345.0);
        tiangKiri(-517.0);
        tiangKiri(-690.0);
    }
    else if (posisi == 4) {//belakang
        tiangBelakang(690.0);
        tiangBelakang(517.0);
        tiangBelakang(345.0);
        tiangBelakang(172.0);
        tiangBelakang(0.0);
        tiangBelakang(-172.0);
        tiangBelakang(-345.0);
        tiangBelakang(-517.0);
        tiangBelakang(-690.0);
    }
}
void cetakTiang() {
    //depan
    cetakPagarVertikal(1);
    //belakang
    cetakPagarVertikal(4);
    //kanan
    cetakPagarVertikal(2);
    //kiri
    cetakPagarVertikal(3);
}
void pembatasPagarDepan(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(180.0, 20.0, 8.0, red, green, blue);
    glPopMatrix();
}
void pembatasPagarBelakang(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(690.0, 20.0, 8.0, red, green, blue);
    glPopMatrix();
}
void pembatasPagarSamping(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(8.0, 20.0, 690.0, red, green, blue);
    glPopMatrix();
}
void pembatas(int posisi) {
    if (posisi == 1)
    {
        pembatasPagarDepan(505.0, 221.0, 691.0, 0.45, 0.45, 0.45);
        pembatasPagarDepan(-505.0, 221.0, 691.0, 0.45, 0.45, 0.45);
    }
    else if (posisi == 2)
    {
        pembatasPagarDepan(505.0, 263.0, 691.0, 0.45, 0.45, 0.45);
        pembatasPagarDepan(-505.0, 263.0, 691.0, 0.45, 0.45, 0.45);
    }
    else if (posisi == 3)
    {
        pembatasPagarBelakang(0.0, 221.0, -691.0, 0.45, 0.45, 0.45);
        pembatasPagarBelakang(0.0, 263.0, -691.0, 0.45, 0.45, 0.45);
    }
    else if (posisi == 4)
    {
        pembatasPagarSamping(691.0, 263.0, 0.0, 0.45, 0.45, 0.45);
        pembatasPagarSamping(691.0, 221.0, 0.0, 0.45, 0.45, 0.45);
    }
    else if (posisi == 5) {
        pembatasPagarSamping(-691.0, 263.0, 0.0, 0.45, 0.45, 0.45);
        pembatasPagarSamping(-691.0, 221.0, 0.0, 0.45, 0.45, 0.45);
    }
}
void cetakPembatas() {
    //depan bawah
    pembatas(1);
    //depan atas
    pembatas(2);
    //belakang
    pembatas(3);
    //samping kanan
    pembatas(4);
    //samping kiri
    pembatas(5);
}
void cetakPagar() {
    cetakTiang();
    cetakPembatas();
}

void batang(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(30.0, 350, 30.0, red, green, blue);
    glPopMatrix();
}
void daun(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    glColor3f(red, green, blue);
    glutSolidSphere(100.0, 30, 30);
    glPopMatrix();
}
void pot(float x, float y, float z, float red, float green, float blue) {
    //samping
    glPushMatrix();glTranslatef(x - 25, y, z);
    glColor3f(red, green, blue);
    balok(5.0, 8.0, 75.0, red, green, blue);
    glPopMatrix();
}
void pot2(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    glColor3f(red, green, blue);
    balok(75.0, 8.0, 5.0, red, green, blue);
    glPopMatrix();
}
void tanah(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    glColor3f(red, green, blue);
    balok(75.0, 2.0, 75.0, red, green, blue);
    glPopMatrix();
}
void cetakPohon() {
    //batang
    batang(-825, 0.0, -800.0, 0.59, 0.29, 0.0);
    batang(825, 0.0, -800.0, 0.59, 0.29, 0.0);
    //daun
    daun(-830.0, 270, -882.0, 0.3, 1.0, 0.0);
    daun(-830, 270, -730.0, 0.5, 1.0, 0.0);
    daun(-900, 270, -800.0, 0.0, 1.0, 0.4);
    daun(-750, 270, -800.0, 0.4, 1.0, 0.0);
    daun(-830, 370, -800.0, 0.0, 1.0, 0.2);
    daun(830.0, 270, -882.0, 0.3, 1.0, 0.0);
    daun(830, 270, -730.0, 0.5, 1.0, 0.0);
    daun(900, 270, -800.0, 0.0, 1.0, 0.4);
    daun(750, 270, -800.0, 0.4, 1.0, 0.0);
    daun(830, 370, -800.0, 0.0, 1.0, 0.2);
    //pot
    tanah(824, 0, -800, 0.63, 0.32, 0.18);
    pot(778, 0, -800, 0.76, 0.76, 0.74);
    pot(920, 0, -800, 0.76, 0.76, 0.74);
    pot2(823, 0, -870, 0.76, 0.76, 0.74);
    pot2(823, 0, -730, 0.76, 0.76, 0.74);

    tanah(-824, 0, -800, 0.63, 0.32, 0.18);
    pot(-728, 0, -800, 0.76, 0.76, 0.74);
    pot(-870, 0, -800, 0.76, 0.76, 0.74);
    pot2(-823, 0, -870, 0.76, 0.76, 0.74);
    pot2(-823, 0, -730, 0.76, 0.76, 0.74);

}
void pintuLuar(float x, float y, float z) {
    balok(5,220,70,1.0f,0.45f,0.0f);
    glPushMatrix();glTranslatef(0,160,22);
    balok(8, 40, 18, 1.0f, 0.55f, 0.05f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 160, -22);
    balok(8, 40, 18, 1.0f, 0.55f, 0.05f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 115, 22);
    balok(8, 40, 18, 1.0f, 0.55f, 0.05f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 115, -22);
    balok(8, 40, 18, 1.0f, 0.55f, 0.05f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 20, 0);
    balok(8, 80, 40, 1.0f, 0.55f, 0.05f);
    glPopMatrix();
}
void kacaPintu() {
    glPushMatrix();glTranslatef(0, 190, -17);
    balok(6, 20, 10, 0.16f, 0.16f, 0.16f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 190, 17);
    balok(6, 20, 10, 0.16f, 0.16f, 0.16f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 190, -50);
    balok(6, 20, 10, 0.16f, 0.16f, 0.16f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 190, 50);
    balok(6, 20, 10, 0.16f, 0.16f, 0.16f);
    glPopMatrix();
}
void pintuDalam(float x,float y, float z) {
    glPushMatrix();glTranslatef(x,y,z);
    balok(5, 225, 70, 0.82f, 0.82f, 0.82f);
    kacaPintu();
        glPushMatrix();glTranslatef(0, -30, 0);
        kacaPintu();
        glPopMatrix();
        glPushMatrix();glTranslatef(0, -60, 0);
        kacaPintu();
        glPopMatrix();
    glPopMatrix();
}
void cetakPintuLuar(int lantai) {
    if (lantai == 1)
    {
        glPushMatrix();glTranslatef(-120,0,460);
        glPushMatrix();glRotatef(30.0,0.0,-1.0,0.0);
        pintuLuar(0,0,0);
        glPopMatrix();
        glPopMatrix();
        glPushMatrix();glTranslatef(120, 0, 460);
        glPushMatrix();glRotatef(30.0, 0.0, 1.0, 0.0);
        pintuLuar(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
    }
    else if (lantai == 2)
    {
        glPushMatrix();glTranslatef(-110, 0, 410);
        glPushMatrix();glRotatef(30.0, 0.0, -1.0, 0.0);
        pintuLuar(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
        glPushMatrix();glTranslatef(110, 0, 410);
        glPushMatrix();glRotatef(30.0, 0.0, 1.0, 0.0);
        pintuLuar(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
    }
}
void cetakPintuDalam(int lantai) {
    if (lantai == 1)
    {
        glPushMatrix();glTranslatef(-70 - x_geser,0,393);
        glPushMatrix();glRotatef(90,0, 1.0, 0);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
        glPushMatrix();glTranslatef(70 + x_geser, 0, 393);
        glPushMatrix();glRotatef(90, 0, 1.0, 0);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
    }
    else if (lantai == 2)
    {
        glPushMatrix();glTranslatef(-70, 0, 343);
        glPushMatrix();glRotatef(90, 0, 1.0, 0);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
        glPushMatrix();glTranslatef(70, 0, 343);
        glPushMatrix();glRotatef(90, 0, 1.0, 0);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
    }
    else if (lantai == 3)
    {
        glPushMatrix();glTranslatef(-62, 0, 293);
        glPushMatrix();glRotatef(90, 0, 1.0, 0);
        glScalef(1, 1, 0.9);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();glPushMatrix();
        glTranslatef(62, 0, 293);
        glPushMatrix();glRotatef(90, 0, 1.0, 0);
        glScalef(1, 1, 0.9);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
    }
    else if (lantai == 4)
    {
        glPushMatrix();glTranslatef(-55, 0, 243);
        glPushMatrix();glRotatef(90, 0, 1.0, 0);
        glScalef(1, 1, 0.8);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
        glPushMatrix();glTranslatef(55, 0, 243);
        glPushMatrix();glRotatef(90, 0, 1.0, 0);
        glScalef(1, 1, 0.8);
        pintuDalam(0, 0, 0);
        glPopMatrix();
        glPopMatrix();
    }
}
//=============TOMBAK MOSKOV=============
void dasarTiang(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(40.0, 40, 40.0, red, green, blue);
    glPopMatrix();
}
void tabung(float dasar, float atas, float tinggi, float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    glColor3f(red, green, blue);glRotatef(-90, 1, 0, 0);
    gluCylinder(gluNewQuadric(), dasar, atas, tinggi, 32, 32);
    glPopMatrix();
}
void kerucut(float x, float y, float z, float red, float green, float blue) {
    glPushMatrix();glTranslatef(x, y, z);
    glColor3f(red, green, blue);glRotatef(-90, 1, 0, 0);
    glutSolidCone(8.0, 40.0, 20, 20);
    glPopMatrix();
}
void cetakpetir() {
    glPushMatrix();glTranslatef(0,100,0);
    dasarTiang(0, 500, 0, 1.0f, 0.84f, 0.0f);
    tabung(8, 8, 400, 0, 500, 0, 0, 0, 0);
    kerucut(0, 900, 0, 0, 0, 0);
    tabung(20, 20, 15, 0, 550, 0, 1.0, 0.84, 0);
    tabung(20, 20, 15, 0, 600, 0, 1.0, 0.84, 0);
    tabung(20, 20, 15, 0, 650, 0, 1.0, 0.84, 0.);
    tabung(20, 20, 15, 0, 700, 0, 1.0, 0.84, 0.);
    tabung(20, 20, 15, 0, 750, 0, 1, 0.84, 0.);
    tabung(20, 20, 15, 0, 800, 0, 1, 0.84, 0.);
    tabung(20, 20, 15, 0, 850, 0, 1, 0.84, 0.);
    glPopMatrix();
}
//=============BABI MINECRAFT=============
void badanBabi(float x, float y, float z) {
    glPushMatrix();glTranslatef(x,y,z);
    balok(20,30,15,0.91f, 0.61f, 0.58f);
    glPopMatrix();
}
void kakiBabi(float x, float y, float z) {
    glPushMatrix();glTranslatef(x,y,z);
    balok(5,20,5, 0.91f, 0.61f, 0.58f);
    glPushMatrix();glTranslatef(3.1, 0, 2.99);
    balok(2, 4, 1.5, 0.4f, 0.21f, 0.2f);
    glPopMatrix();
    glPushMatrix();glTranslatef(3.1, 0, -2.99);
    balok(2, 4, 1.5, 0.4f, 0.21f, 0.2f);
    glPopMatrix();glPopMatrix();
}
void hidungBabi(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(2, 9, 6, 0.98f, 0.61f, 0.58f);
    glPushMatrix();glTranslatef(0.05, 3, 0);
    balok(2, 4, 6, 0.99f, 0.60f, 0.61f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0.06, 2.5, 3.99);
    balok(2, 4, 2, 0.53f, 0.26f, 0.26f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0.06, 2.5, -3.99);
    balok(2, 4, 2, 0.53f, 0.26f, 0.26f);
    glPopMatrix();glPopMatrix();
}
void kepalaBabi(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(12, 24, 12, 0.91f, 0.61f, 0.58f);
    glPopMatrix();
}
void mataBabi(float x, float y, float z,bool mataKanan) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(1, 5, 2.9, 1, 1, 1);
    if (mataKanan == true)
    {
        glPushMatrix();glTranslatef(0.1, 0, 1.45);
        balok(1, 5, 1.45,0, 0, 0);
        glPopMatrix();
    }else{
            glPushMatrix();glTranslatef(0.1, 0, -1.45);
            balok(1, 5, 1.45, 0, 0, 0);
            glPopMatrix();
    }
    glPopMatrix();
}
void catBadanBabi(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(18, 5, 1, 0.96f, 0.49f, 0.50f);
    glPushMatrix();glTranslatef(8, -7, 0);
    balok(8, 5, 1, 0.96f, 0.49f, 0.50f);
    glPopMatrix();
    glPushMatrix();glTranslatef(6, -14, 0);
    balok(12, 5, 1, 0.96f, 0.49f, 0.50f);
    glPopMatrix();glPopMatrix();
}
void babiMinecraft() {
    badanBabi(0, 17, 0);
    hidungBabi(37, 30, 0);
    kakiBabi(15, 0, 7);//depanKanan
    kakiBabi(15, 0, -7);//depanKiri
    kakiBabi(-17, 0, 7);//belakangKanan
    kakiBabi(-17, 0, -7);//belakangKiri
    kepalaBabi(25, 25, 0);
    mataBabi(36.1, 37, -9, false);
    mataBabi(36.1, 37, 9, true);
    catBadanBabi(1, 38, 14.1);
    glPushMatrix();glTranslatef(0, 45.1, -5);glRotatef(90.0, -1.0, 0.0, 0.0);
    catBadanBabi(0, 0, 0);
    glPopMatrix();
    catBadanBabi(1, 38, -14.1);
}
void tampilBabiMinecraft() {
    glPushMatrix();glTranslatef(620,0,650);
    glPushMatrix();glRotatef(180, 0.0, 1.0, 0.0);
    babiMinecraft();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();glTranslatef(620, 0, 620);
    glPushMatrix();glRotatef(180, 0.0, 1.0, 0.0);glScalef(0.5,0.5,0.5);
    babiMinecraft();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();glTranslatef(590, 48, 650);
    glPushMatrix();glRotatef(150, 0.0, 1.0, 0.0);glScalef(0.2, 0.2, 0.2);
    babiMinecraft();
    glPopMatrix();glPopMatrix();
}
//=============ENDERMAN=============
void badanEnderman(float x, float y, float z) {
    glPushMatrix();glTranslatef(x,y,z);
    balok(4,40,12,0.06f,0.07f,0.09f);
    glPopMatrix();
}
void kepalaEnderman(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(15, 30, 15, 0.06f, 0.07f, 0.09f);
    glPushMatrix();glTranslatef(12.01, 15, -8);
    balok(3, 5, 4, 0.86f, 0.52f, 0.95f);
    glPushMatrix();glTranslatef(0.1, 0.02, 0);
    balok(3.1, 4.95, 2, 0.78f, 0.16f, 0.95f);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();glTranslatef(12.01, 15, 8);
    balok(3, 5, 4, 0.86f, 0.52f, 0.95f);
    glPushMatrix();glTranslatef(0.1, 0.02, 0);
    balok(3.1, 4.95, 2, 0.78f, 0.16f, 0.95f);
    glPopMatrix();glPopMatrix();
    glPopMatrix();
}
void tanganEnderman(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(2.7, 110, 2.7, 0.06f, 0.07f, 0.09f);
    glPopMatrix();
}
void endermanMinecraft() {
    badanEnderman(0,100,0);
    kepalaEnderman(0,138,0);
    tanganEnderman(0,0,7);
    tanganEnderman(0, 0, -7);
    glPushMatrix();glTranslatef(55,40,15);
    glPushMatrix();glRotatef(30.0,0.0,0.0,1.0);
    tanganEnderman(0, 0, 0);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();glTranslatef(55, 40, -15);
    glPushMatrix();glRotatef(30.0, 0.0, 0.0, 1.0);
    tanganEnderman(0, 0, 0);
    glPopMatrix();glPopMatrix();
    glPushMatrix();glTranslatef(42,42,0);
    glPushMatrix();glScalef(0.3,0.3,0.3);glRotatef(60.0,0.0,0.0,-1.0);
    petiMinecraft(0,0,0,false,1);
    glPopMatrix();glPopMatrix();
}
void tampilEndermanMinecraft() {
    int speed = 4;
    glPushMatrix();glTranslatef(-600 + sumbuX, 0, 600 + sumbuZ);
    if (mulai == true && sumbuX < 1200 && sumbuZ == 0)
    {
        sumbuX += speed;
    }
    else if (sumbuX == 1200 && sumbuZ > -1200) {
        glRotatef(90.0,0.0,1.0,0.0);
        sumbuZ -= speed;
        mulai = false;
    }
    else if (sumbuX >= speed && sumbuX <= 1200 && sumbuZ == -1200) {
        glRotatef(180.0, 0.0, 1.0, 0.0);
        sumbuX -= speed;
        mulai = false;
    }
    else if (sumbuX == 0 && sumbuZ >= -1200 && sumbuZ <= speed ) {
        glRotatef(90.0, 0.0, -1.0, 0.0);
        sumbuZ += speed;
        if (sumbuZ == 0)
        {
            mulai = true;
        }
    }
    endermanMinecraft();
    glPopMatrix();
}
//=============KURSI=============
void cetakPalangY1(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(3, 150, 6, 0, 0, 0);
    glPopMatrix();
}
void cetakPalangY2(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(3, 80, 6, 0, 0, 0);
    glPopMatrix();
}
void cetakPalangY3(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(40, 10, 5, 0, 0, 0);
    glPopMatrix();
}
void cetakPalangX1(float x, float y, float z) {
    //Cetak Palang Pada Sumbu X
    glPushMatrix();glTranslatef(x, y, z);
    balok(1.5, 18, 120, 0.5, 0.19, 0.02);
    glPopMatrix();
}
void cetakPalangX2(float x, float y, float z) {
    //Cetak Palang Pada Sumbu X
    glPushMatrix();glTranslatef(x, y, z);
    balok(8, 5, 120, 0.5, 0.19, 0.02);
    glPopMatrix();
}
//============LEMARI============
void cetakPalangL1(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(40, 10, 70, 0.5, 0.19, 0.02);
    glPopMatrix();
}
void cetakPalangL2(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(38, 200, 68, 0.6, 0.24, 0.04);
    glPopMatrix();
}
void cetakPalangL3(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(3, 200, 1, 0.38, 0.21, 0.12);
    glPopMatrix();
}
void cetakPalangL4(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(1, 20, 3, 1, 0.71, 0.2);
    glPopMatrix();
}
void cetakPalangL5(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(1, 150, 20, 0.88, 1, 1);
    glPopMatrix();
}
//=================================================================
void cetakKursi() {
    glPushMatrix();glTranslatef(0,0,-450);
    //palangBelakang
    cetakPalangY1(-750, -200, 557); cetakPalangY1(-750, -200, 343);
    //palangDepan
    cetakPalangY2(-827, -200, 557); cetakPalangY2(-827, -200, 343);
    //palangTengah
    cetakPalangY3(-789, -130, 557); cetakPalangY3(-789, -130, 343);
    //sandaran
    cetakPalangX1(-754.5, -66, 450); cetakPalangX1(-754.5, -92, 450);
    cetakPalangX1(-754.5, -118, 450);
    //dudukan
    cetakPalangX2(-770, -122, 450); cetakPalangX2(-796, -122, 450);
    cetakPalangX2(-822, -122, 450);
    glPopMatrix();
}
void cetakLemari() {
    cetakPalangL1(-337.5, 0, 145);//alas
    cetakPalangL1(-337.5, 206, 145);//atas
    cetakPalangL2(-337.5, 8, 145);
    cetakPalangL3(-300, 8, 145);//tengah
    cetakPalangL4(-299, 108, 145);//gagang
    cetakPalangL5(-298, 33, 178);//cermin1
    cetakPalangL5(-298, 33, 110);//cermin2
}
void gentong(float x, float y, float z, int type) {
    if (type == 1)
    {
        glPushMatrix(); //bawah
        glTranslatef(x, y, z);glRotatef(-90.0, 1, 0, 0.0);
        glColor3f(0.84f, 0.64f, 0.08f);
        gluCylinder(gluNewQuadric(), 20.0f, 50.0f, 50.0f, 32, 40);
        glPopMatrix();
        glPushMatrix(); //atas
        glTranslatef(x, y + 100, z);glRotatef(90.0, 1, 0, 0.0);
        glColor3f(0.84f, 0.60f, 0.08f);
        gluCylinder(gluNewQuadric(), 20.0f, 50.0f, 50.0f, 32, 40);
        glPopMatrix();
        glPushMatrix(); //bibir
        glTranslatef(x, y + 100 + y_geser, z);glRotatef(90.0, 1, 0, 0.0);
        glColor3f(0.84f, 0.4f, 0.08f);
        glutSolidTorus(2.0, 20.0, 40, 40);
        glPopMatrix();
    }
    else if (type == 2)
    {
        glPushMatrix(); //bawah
        glTranslatef(x, y, z);glRotatef(-90.0, 1, 0, 0.0);
        glColor3f(0.84f, 0.64f, 0.08f);
        gluCylinder(gluNewQuadric(), 10.0f, 30.0f, 60.0f, 32, 40);
        glPopMatrix();
        glPushMatrix(); //atas
        glTranslatef(x, y + 120, z);glRotatef(90.0, 1, 0, 0.0);
        glColor3f(0.84f, 0.60f, 0.08f);
        gluCylinder(gluNewQuadric(), 10.0f, 30.0f, 60.0f, 32, 40);
        glPopMatrix();
        glPushMatrix(); //bibir
        glTranslatef(x, y + 120 + y_geser, z);glRotatef(90.0, 1, 0, 0.0);
        glColor3f(0.84f, 0.4f, 0.08f);
        glutSolidTorus(2.0, 10.0, 40, 40);
        glPopMatrix();
    }

}
void tempatsampah(float x, float y, float z, int  col) {
    if (col == 1)
    {
        glPushMatrix();glTranslatef(x, y, z);
        balok(25.0, 80, 10.0, 0.82, 0.12, 0.13);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 78, z);
        balok(29.0, 10, 14.0, 0.82, 0.2, 0.13);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 85, z);
        balok(27.0, 20, 12.0, 0.82, 0.12, 0.13);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 87, z + 9);
        balok(25.0, 16, 4.0, 0.34, 0.34, 0.34);
        glPopMatrix();
    }
    else if (col == 2)
    {
        glPushMatrix();glTranslatef(x, y, z);
        balok(25.0, 80, 10.0, 0.97, 0.84, 0.08);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 78, z);
        balok(29.0, 10, 14.0, 0.97, 0.9, 0.08);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 85, z);
        balok(27.0, 20, 12.0, 0.97, 0.84, 0.08);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 87, z + 9);
        balok(25.0, 16, 4.0, 0.34, 0.34, 0.34);
        glPopMatrix();
    }
    else if (col == 3)
    {
        glPushMatrix();glTranslatef(x, y, z);
        balok(25.0, 80, 10.0, 0.22, 0.69, 0.3);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 78, z);
        balok(29.0, 10, 14.0, 0.3, 0.69, 0.3);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 85, z);
        balok(27.0, 20, 12.0, 0.22, 0.69, 0.3);
        glPopMatrix();
        glPushMatrix();glTranslatef(x, y + 87, z + 9);
        balok(25.0, 16, 4.0, 0.34, 0.34, 0.34);
        glPopMatrix();
    }
}
void tiangSampah(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(100.0, 8.0, 3.0, 1, 1, 1);
    glPopMatrix();
}
void tiangSampah2(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(5.0, 80.0, 3.0, 1, 1, 1);
    glPopMatrix();
}
void dasarSampah(float x, float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    balok(5.1, 8.0, 15.0, 0, 0, 0);
    glPopMatrix();
}
void cetakTempatsampah(float x, float y, float z) {
    glPushMatrix();glTranslatef(740,-200,0);
    glPushMatrix();glRotatef(90.0, 0, 1, 0.0);
    //tempat sampah
    tempatsampah(x + 80, y, z, 1);
    tempatsampah(x, y, z, 2);
    tempatsampah(x - 80, y, z, 3);
    //tiang
    tiangSampah(x, y + 62, z - 13);
    tiangSampah(x, y + 27, z - 13);
    tiangSampah2(x + 40, y, z - 13);
    tiangSampah2(x - 40, y, z - 13);
    dasarSampah(x - 40, y, z);
    dasarSampah(x + 40, y, z);
    glPopMatrix();glPopMatrix();
}
void lampuGantung() {
    balok(10,4,10,0.26f,0.3f,0.41f);
    glPushMatrix();glTranslatef(0, 2, 0);//lampuOff
    balok(10, 20, 10, 0.86f, 0.75f, 0.28f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 2, 0);//lampuOn
    balok(5.1 + saklarLampu, 20, 5.1 + saklarLampu, 0.96f, 0.96f, 0.52f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 20, 0);
    balok(10, 4, 10, 0.26f, 0.3f, 0.41f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 22, 0);
    balok(8, 4, 8, 0.55f, 0.31f, 0.15f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 24, 0);
    balok(8, 4, 8, 0.71f, 0.27f, 0.0f);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 26, 0);
    balok(2, 10, 2, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 30, -10);
    balok(2, 4, 10, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();glTranslatef(0, 20, -20);
    balok(10, 30, 2, 0.78f, 0.77f, 0.8f);
    glPopMatrix();
}
void cetakLampuGantung(float x,float y, float z) {
    glPushMatrix();glTranslatef(x, y, z);
    lampuGantung();
    glPopMatrix();
}
//=============MEJA==============
void cetakPalangM1(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(6, 50, 6, 0, 0, 0);
    glPopMatrix();
}
void cetakPalangM2(float x, float y, float z) {
    //Cetak Palang Pada Sumbu Y
    glPushMatrix();glTranslatef(x, y, z);
    balok(50, 5, 60, 0.6, 0.24, 0.04);
    glPopMatrix();
}
void cetakMeja() {
    //palangBelakang
    cetakPalangM1(337.5, 0, 213); cetakPalangM1(337.5, 0, 114);
    //palangDepan
    cetakPalangM1(280, 0, 213); cetakPalangM1(280, 0, 114);
    //alasMeja
    cetakPalangM2(310, 47.5, 165);
}
void matahari(float x, float y, float z) {
    //matahari
    glPushMatrix();glTranslatef(x, y, z);
    glColor3f(1, 0.64, 0);
    glutSolidSphere(90.0, 300, 300);
    glPopMatrix();
}
void balokReplika(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x,y,z);
    balok(100,40,100,0.41f,0.41f,0.41f);
    balok(100.1, 39.99, 99.99, 0.66f, 0.66f, 0.66f);
    balok(99.99, 39.99, 100.1, 0.55f, 0.55f, 0.55f);
    glPopMatrix();
}
void cetakBalokReplika() {
    balokReplika(0,0,-240);
}
void tianglampu() {
    dasarTiang(400, 0, 900, 0.29f, 0.29f, 0.29f);
    tabung(8, 8, 380, 400, 20, 900, 0.53, 0.53, 0.53);
    glPushMatrix();
    glTranslatef(400, 380, 900);
    balok(15, 50, 15, 1.0f, 0.92f, 0.02f);
    glPushMatrix();
    glTranslatef(0,48,0);
    balok(15, 8, 15, 0.55f, 0.55f, 0.55f);
    glPopMatrix();
    glPopMatrix();
}
void replikaSeigantoji(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.1, 0.1, 0.1);
    //cetakPagar();
    //cetakTangga();
    //cetakPohon();
    //eksteriorLantai0();
    lantai(700, 200, 700, 0.7, 0.7, 0.7);//y:Tinggi
    //===lantai 1===//
    glPushMatrix();
    glTranslatef(0, 200, 0);
    lantai1(385, 300, 385, 0.8, 0.8, 0.8);//tembokDalam
    lantai1(400, 300, 400, 0.9, 0.9, 0.9);//tembokLuar
    eksteriorLantai1();
    //interiorLantai1();
    glPopMatrix();
    //===lantai 1===//
    //===lantai 2===//
    glPushMatrix();
    glTranslatef(0, 500, 0);
    lantai2(337, 300, 337, 0.8, 0.8, 0.8);//tembokDalam
    lantai2(350, 340, 350, 0.9, 0.9, 0.9);//tembokLuar
    eksteriorLantai2();
    //interiorLantai2();
    glPopMatrix();
    //===lantai 2===//
    //===lantai 3===//
    glPushMatrix();
    glTranslatef(0, 800, 0);
    lantai3(285, 300, 285, 0.8, 0.8, 0.8);//tembokDalam
    lantai3(300, 340, 300, 0.9, 0.9, 0.9);//tembokLuar
    eksteriorLantai3();
    //interiorLantai3();
    glPopMatrix();
    //===lantai 3===//
    //===lantai 4===//
    glPushMatrix();
    glTranslatef(0, 1100, 0);
    lantai4(235, 300, 235, 0.8, 0.8, 0.8);//tembokDalam
    lantai4(250, 340, 250, 0.9, 0.9, 0.9);//tembokLuar
    eksteriorLantai4();
    //interiorLantai4();
    glPopMatrix();
    //===lantai 4===//
    //ground();
    glPopMatrix();
}
void cetakbintang() {
    glPushMatrix();
    glRotatef(90, -1, 0, 0);
    kerucut(900, 1000, 1000, 0, 0.5, 1);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    kerucut(900, -1000, -1000, 0, 0.5, 1);
    glPopMatrix();
    glPushMatrix();
    kerucut(900, 1000, -1000, 0, 0.5, 1);
    glPopMatrix();
    glPushMatrix();
    glRotatef(180, 1, 0, 0);
    kerucut(900, -1000, 1000, 0, 0.5, 1);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    kerucut(1000, -900, -1000, 0, 0.5, 1);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0, 0, -1);
    kerucut(-1000, 900, -1000, 0, 0.5, 1);
    glPopMatrix();
}
void hurufF(float x, float y, float z) {
    glPushMatrix(); glTranslatef(x,y,z);

    balok(2, 30, 2, 0.86f, 0.86f, 0.86f);//LampuOFF0.96f, 0.96f, 0.52f
    balok(1.96 + lampuFTI, 29.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);//lampuON
    glPushMatrix(); glTranslatef(7, 24, 0);
    balok(7.5, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(7.46 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix();glPushMatrix(); glTranslatef(7, 14, 0);
    balok(7.5, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(7.46 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix();
    glPopMatrix();
}
void hurufT(float x, float y, float z) {
    glPushMatrix(); glTranslatef(x, y, z);
    balok(2, 30, 2, 0.86f, 0.86f, 0.86f);//LampuOFF
    balok(1.96 + lampuFTI, 29.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPushMatrix(); glTranslatef(0, 24, 0);
    balok(10, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(9.96 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix();
    glPopMatrix();
}
void hurufI(float x, float y, float z) {
    glPushMatrix(); glTranslatef(x, y, z);
    balok(2, 30, 2, 0.86f, 0.86f, 0.86f);//lampuOFF
    balok(1.96 + lampuFTI, 29.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix();
}
void angka2(float x, float y, float z) {
    glPushMatrix(); glTranslatef(x, y, z);

    balok(2, 15, 2, 0.86f, 0.86f, 0.86f);//lampuOFF
    balok(1.96 + lampuFTI, 14.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPushMatrix(); glTranslatef(5.5, 24, 0);
    balok(7.5, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(7.46 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix(); glPushMatrix(); glTranslatef(5.5, 12, 0);
    balok(7.5, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(7.46 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix(); glPushMatrix(); glTranslatef(5.5, 0, 0);
    balok(7.5, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(7.46 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix(); glPushMatrix(); glTranslatef(11, 12, 0);
    balok(2, 15, 2, 0.86f, 0.86f, 0.86f);
    balok(1.96 + lampuFTI, 14.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix();glPopMatrix();
}
void angka0(float x, float y, float z) {
    glPushMatrix(); glTranslatef(x, y, z);

    balok(2, 30, 2, 0.86f, 0.86f, 0.86f);
    balok(1.96 + lampuFTI, 29.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPushMatrix(); glTranslatef(7, 24, 0);
    balok(5.5, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(5.46 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix(); glPushMatrix(); glTranslatef(7, 0, 0);
    balok(5.5, 6, 2, 0.86f, 0.86f, 0.86f);
    balok(5.46 + lampuFTI, 5.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix(); glPushMatrix(); glTranslatef(11, 0, 0);
    balok(2, 30, 2, 0.86f, 0.86f, 0.86f);
    balok(1.96 + lampuFTI, 29.96 + lampuFTI, 1.96 + lampuFTI, 0.96f, 0.96f, 0.52f);
    glPopMatrix();
    glPopMatrix();
}
void lampuFTI2022() {
    hurufF(-70,7,-140);
    hurufT(-40, 7, -140);
    hurufI(-20, 7, -140);
    angka2(10,7,-140);
    angka0(30, 7, -140);
    angka2(50, 7, -140);
    angka0(70, 7, -140);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("TR GRAFKOM KELOMPOK 9");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutMainLoop();
    return 0;
}