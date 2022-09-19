class Rectagle
{
    int height;
    int width;
    int S;
public:
    Rectagle();

    Rectagle(int height, int width);

    bool operator ==(Rectagle& other);

    bool operator>(Rectagle& other);

    bool operator<(Rectagle& other);

    void printInfo();
};