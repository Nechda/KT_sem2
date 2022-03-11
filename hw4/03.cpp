//Компьютерные технологии ФРКТ, Нечитаев Дмитрий, Б01-909.
#include <iostream>
#include <cmath>

using namespace std;

class Material {
public:
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial : public Material {
public:
    ElasticMaterial(float elasticModulus) : E(elasticModulus) {}
    virtual ~ElasticMaterial() {}
    virtual float getStress(float strain) {
        return std::abs(strain * E);
    }
private:
    float E = 0;
};

class PlasticMaterial : public Material {
public:
    PlasticMaterial(float elasticModulus, float strainLimit)
        : E(elasticModulus),
          limit(strainLimit)
    {}
    virtual ~PlasticMaterial() {}
    virtual float getStress(float strain) {
        return std::abs(std::min(strain, limit) * E);
    }
private:
    float E = 0;
    float limit = 0;
};

int main() {
    Material* m;
    m = new ElasticMaterial(100);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    m = new PlasticMaterial(100, 0.01);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    return 0;
}