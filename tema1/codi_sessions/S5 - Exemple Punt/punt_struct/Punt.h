#ifndef _PUNT_H
#define _PUNT_H

class Punt
{
public:
	float m_x;
	float m_y;

	void llegeix();
	void mostra();
	float distancia(Punt& p);
};

#endif