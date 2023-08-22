#ifndef UTILS_HEADER
#define UTILS_HEADER

void swapInt(int (&tab)[], int one, int two);
bool verify(int(&tab)[]);
void sleep();
void initSizes(int (&rectSizes)[]);
void shuffle(int (&rectSizes)[]);
constexpr unsigned int str2int(const char* str, int h = 0); //Took from stackoverflow : https://stackoverflow.com/a/16388610
int parser(int argc, char **argv);

#endif