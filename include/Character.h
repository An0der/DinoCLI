#include "Rect.h"
#include "Image.h"


class Character : public Rect, Image
{
private:

public:
    Character();
    ~Character = default;
    void interact(const Character& object);
};