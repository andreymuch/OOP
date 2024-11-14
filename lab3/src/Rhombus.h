#pragma once
#include "Figure.h"

class Rhombus : public Figure {
private:
    double d1, d2;

public:
    Rhombus(double d1 = 1.0, double d2 = 1.0);
    virtual ~Rhombus() = default;

    Rhombus(const Rhombus&);
    Rhombus(Rhombus&& other) noexcept;

    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

    Rhombus& operator=(const Rhombus& other) ;
    Rhombus& operator=(Rhombus&& other) noexcept;
    bool operator==(const Rhombus& other) const;
    void printVertices(std::ostream& os) const;

};
std::ostream& operator<<(std::ostream& os, const Rhombus& fig);
