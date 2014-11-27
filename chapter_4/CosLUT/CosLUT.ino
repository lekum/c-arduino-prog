const float cosinePrecision = 0.5;
const int cosinePeriod = (int) (360.0 * 1 / cosinePrecision);
float cosLUT[cosinePeriod];
const float DEG2RAD = 180 / PI;


void setup()
{
    initCosineLUT();
}

void loop()
{
    // nothing for now
}

void initCosineLUT() 
{
    for (int i = 0; i < cosinePeriod; i++)
    {
        cosLUT[i] = (float) cos(i * DEG2RAD * cosinePrecision);
    }
}
