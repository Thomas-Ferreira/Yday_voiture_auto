#ifndef DEF_MOTOR
#define DEF_MOTOR

class motor 
{
    private:

        int in1; 
        int in2; 
        int in3; 
        int in4; 
        int enb; 
        int ena;

    public:

        motor(int in1, int in2, int in3, int in4, int enb, int ena);

        ~motor();

        void avancer();
        void reculer();
        void droite();
        void gauche();
        void arret();


};

#endif
