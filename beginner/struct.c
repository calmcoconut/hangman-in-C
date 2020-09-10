
struct id
{
    char first[15];
    char last[15];
};

struct date
{
    int month;
    int day;
    int year;
};

struct human {
    struct id name;
    struct date birthday;
};