#ifndef PUNT_H
#define PUNT_H

const int MAX_DIMENSIONS = 10;

class Punt
{
public:
    Punt() : m_nDimensions(2) { m_coordenades[0] = 0; m_coordenades[1] = 0; }
    Punt(int nDimensions);
    Punt(int nDimensions, float coordenades[MAX_DIMENSIONS]);
    void setX(float x) { m_coordenades[0] = x; }
    void setY(float x) { m_coordenades[1] = x; }
    float getX() { return m_coordenades[0]; }
    float getY() { return m_coordenades[1]; }
    void llegeix();
    void mostra();
    float distancia(Punt &p);
private:
    float m_coordenades[MAX_DIMENSIONS];
    int m_nDimensions = 2;
};

#endif
