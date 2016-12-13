/*
    PERIODE DE LA JOURNEE
 */

class Period 
{
public:
    typedef enum
    {
        Day,                    // jour
        Night                   // nuit (t'avais pas deviné hein)
    }
    Period_t;
    
    Period_t get();             // fonction qui renvoie Day ou Night en fonction de l'heure
};


