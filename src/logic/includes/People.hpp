#ifndef ED22-01-GALLARDO_PEOPLE_H
#define ED22-01-GALLARDO_PEOPLE_H

class People
{
    private:
        int xComienzo;
        int yComienzo;
        int xFin;
        int yFin;
        int xCentro;
        int yCentro;
        int entry;
        int leave;
    public:
        People();
        int getXComienzo();
        int getYComienzo();
        int getXFin();
        int getYFin();
        int getXCentro();
        int getYCentro();
        int getEntry();
        int getLeave();
        void sumEntry();
        void sumLeave();
        ~People();


};

#endif // ED22-01-GALLARDO_PEOPLE_H