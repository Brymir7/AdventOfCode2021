#include <stdlib.h>
#include <stdio.h>
int fuelcost(int a, int *b, int length_b)
{
    int fuelcost1 = 0;
    for (int i = 0; i < length_b; ++i)
    {
        fuelcost1 = fuelcost1 + abs(a - b[i]);
    }
    return fuelcost1;
}
int max_value(int *a, int length_a)
{
    int value = a[0];
    for (int i = 0; i < length_a; ++i)
    {
        if (a[i] > value)
        {
            value = a[i];
        }
    }
    return value;
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_integer_array(int *a, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}
void bubblesort(int *a, int length)
{

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a + j, a + j + 1);  // Swap addresses not actual values
            }
        }
    }
}
int binary_search(int min, int max, int *a, int length_a)
{
    int middle = (min + max) / 2;
    int fuelcost1 = fuelcost(middle,  a, length_a);
    int fuelcost2 = fuelcost(middle+1, a, length_a);
    printf("Fuelcost 1: %i, Fuelcost 2: %i Middle: %i\n", fuelcost1, fuelcost2, middle);
    printf("min: %i max: %i \n", min, max);
    if ((max - min == 1)||(max-min == 0))
    {
        return middle;
    }
    if (fuelcost1 < fuelcost2)
    {
        return binary_search(min, middle, a, length_a);
    }
    else if (fuelcost2 < fuelcost1)
    {
        return binary_search(middle+1, max, a, length_a);
    }
    
}
int main(int argc, char **argv)
{
    int input[] = {1101,1,29,67,1102,0,1,65,1008,65,35,66,1005,66,28,1,67,65,20,4,0,1001,65,1,65,1106,0,8,99,35,67,101,99,105,32,110,39,101,115,116,32,112,97,115,32,117,110,101,32,105,110,116,99,111,100,101,32,112,114,111,103,114,97,109,10,1133,1029,1446,1005,596,277,439,544,201,317,237,33,252,774,482,291,57,1434,153,134,385,993,677,1189,99,1082,351,80,1563,195,581,693,5,633,184,552,11,606,462,48,134,1451,850,221,336,661,276,156,932,23,98,76,327,212,489,230,819,998,1037,1561,206,159,757,207,1203,224,1459,294,39,1108,96,89,1664,353,41,83,942,771,362,193,900,676,851,277,558,368,1054,316,143,464,85,896,558,52,669,163,696,140,340,542,817,783,1436,786,81,21,669,184,430,312,1500,797,698,611,314,145,125,391,785,867,488,144,9,967,560,245,116,96,1769,314,533,25,0,1375,1307,1273,1178,332,59,26,234,487,480,615,313,629,28,707,96,637,30,350,1286,900,777,115,56,79,809,1101,13,150,741,940,20,403,384,479,622,108,325,276,609,654,535,539,62,187,414,535,140,222,845,357,55,17,8,1430,853,759,331,673,202,482,1280,714,911,409,429,604,278,478,301,408,590,329,1482,110,423,488,7,628,66,196,399,86,241,1058,501,1284,594,710,799,34,60,668,457,0,1209,20,50,1134,288,415,399,86,540,1356,285,1541,172,3,634,1387,146,669,195,403,601,758,160,970,760,43,213,68,805,50,350,292,78,252,54,1021,882,241,808,601,892,878,1401,48,191,74,1429,94,520,505,679,1133,120,485,183,362,684,520,1366,301,123,290,1248,140,44,230,572,57,1101,217,906,1012,668,85,230,32,100,472,275,78,91,19,61,732,518,189,85,1531,1255,134,489,637,792,42,36,392,603,976,651,127,486,340,534,185,890,346,906,1295,319,321,597,252,183,554,124,44,426,131,408,582,429,645,1227,574,14,1828,359,184,1830,10,288,194,949,1578,492,502,149,609,77,92,320,233,1026,123,26,188,1123,4,665,1793,331,858,481,197,424,133,933,338,7,163,1269,665,19,1,538,126,895,1751,345,895,203,175,66,305,1479,239,718,386,8,1148,203,636,1211,635,149,489,1156,1828,61,328,331,287,262,8,3,522,1427,931,1103,199,329,930,779,124,446,391,903,696,1764,16,595,522,143,296,19,872,29,546,566,256,63,1195,862,516,267,452,1287,11,547,760,77,117,988,185,293,421,118,767,70,169,456,600,755,740,1799,97,507,1165,265,1126,376,1250,408,22,674,774,361,54,558,1021,529,29,871,527,474,218,47,309,61,188,1365,725,267,235,359,1004,1771,765,8,17,103,89,967,65,302,759,1688,882,709,1469,123,548,834,355,646,404,76,257,101,627,2,66,1328,137,42,23,127,110,632,683,1163,843,1119,16,497,1756,347,958,981,57,185,204,1403,530,536,104,68,1152,95,320,959,144,281,350,622,717,112,631,150,19,938,296,1272,825,37,192,350,847,306,824,1042,320,480,857,589,137,687,93,21,1601,547,550,491,161,49,124,292,396,34,24,95,932,56,968,197,109,1300,1326,605,357,412,14,179,450,991,173,120,1402,478,77,933,88,96,49,95,596,1885,841,441,659,309,418,87,134,34,815,759,631,209,728,7,232,1304,698,140,304,1448,101,1,239,1321,362,1367,1411,279,111,633,1347,110,18,710,443,1676,64,531,386,64,518,619,893,140,301,426,1451,261,1083,115,61,943,60,891,217,475,48,436,586,31,287,196,430,357,78,161,1533,745,198,715,8,307,225,604,263,992,371,749,700,1573,573,546,480,425,47,88,66,799,388,60,736,111,81,856,29,695,141,4,271,143,939,423,3,1260,265,24,903,292,23,80,196,1245,399,123,3,532,283,366,1175,187,15,450,487,117,1041,669,59,579,159,461,598,915,666,1231,999,253,185,1016,135,1317,253,111,1261,833,26,851,120,11,63,718,682,233,76,0,50,1678,777,286,279,90,47,158,71,35,475,245,550,4,942,1816,1646,102,175,343,12,446,12,623,44,157,10,555,1173,651,361,745,1870,97,237,1628,90,233,126,1596,1146,746,383,209,55,209,318,904,144,90,21,86,4,970,262,8,210,249,871,1216,1003,172,405,821,225,2,143,915,129,598,397,583,1400,315,113,33,75,426,2,611,293,196,419,125,176,496,4,607,1425,27,48,172,972,626,227,184,1257,514,209,524,22,58,927,4,931,3,6,104,716,961,17,4,154,249,558,203,180,180,1194,935,263,535,380,1439,274,1566,873,1763,2,89,636,407,667,438,966,757,245,730,328,915,167,245,126,52,652,938,1183,320,1298,10,844,36,263,382,37,142
};
    int length_input = sizeof(input) / sizeof(*input);
    int *temporary_array = malloc(length_input * sizeof(int));
    for (int i = 0; i < length_input; ++i)
    {
        temporary_array[i] = input[i];
       
    }
    printf("\n");
    
    print_integer_array(temporary_array, length_input);
    int max_value1 = max_value(temporary_array, length_input);
    printf("%i \n", max_value1);
    int best_position = binary_search(0, 1885, temporary_array, length_input);
    printf("%i \n", best_position);
    int output_fuelcost = fuelcost(best_position, temporary_array, length_input);
    printf("%i", output_fuelcost);
    return 0;
}