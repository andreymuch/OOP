#pragma once
#include "Figure.h"

class Pentagon : public Figure {
private:
    double side;
    double R = side / (2 * sin(atan(1)*4 / 5)); 

public:
    Pentagon(double side = 1.0);
    virtual ~Pentagon() = default;
    Pentagon(const Pentagon&);
    Pentagon(Pentagon&& other) noexcept;

    std::pair<double, double> center()const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;

    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept ;
    bool operator==(const Pentagon& other) const;
    void printVertices(std::ostream& os) const override;
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& fig);
};