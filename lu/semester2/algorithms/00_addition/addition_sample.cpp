#include "stdio.h"
#include "stdlib.h"
int main(void)
{
    FILE* inFile;
    FILE* outFile;
    int aFirst;  // pirmais skaitlis
    int aSecond; // otrais skaitlis
    int aResult; // Rezultats
    char aString[101]; // vieta simbolu virknes ielas��anai

// Atveram failus
    inFile = fopen("addition.in", "r");  // v�rt tikai las��anas re��m�, cit�di APTS ne�aus atv�rt
    outFile = fopen("addition.out", "w+");

    fscanf(inFile, "%s", aString);  // ielas�m simbolu virkni l�dz pirmajam tuk�umam
    fscanf(inFile, "%d %d", &aFirst, &aSecond); // ielas�m divus skait�us, starp kuriem ir tuk�ums

    aResult = aFirst + aSecond;

// --- piem�rs izdrukai uz ekr�na, �os rezult�tus var redz�t APTS atbildes lap�
// --- gala variant� t�das izdrukas nedr�kst atst�t !!!
    fprintf(stdout, "%s\n", aString);
    fprintf(stdout, "Skaitlis1: %d\n", aFirst);
    fprintf(stdout, "Skaitlis2: %d\n", aSecond);
    fprintf(stdout, "Rezultats: %d\n", aResult);
// --- beigas piem�ram izdruk��anai uz ekr�na

// Re�la druk��ana fail�
    fprintf(outFile, "%s%s", aString, ": ");
    fprintf(outFile, "%d\n", aResult);


// Aizveram failus
    fclose(inFile);
    fclose(outFile);

    return 0;
}