#include <assert.h>
#include <stdint.h>
#include <stdio.h>

// todo: move to math.h
#define M_PI        3.14159265358979323846264338327950288   /* pi             */
#define M_PI_2      1.57079632679489661923132169163975144   /* pi/2           */
#define M_PI_4      0.785398163397448309615660845819875721  /* pi/4           */

// sin(0) = 0
// sin(pi/2) = 1
// sin(pi) = 0
// sin(-pi/2) = -1

float test_sinf(float x) {
    float sum = x;
    float div = x;
    const float xsq = x * x;
    unsigned int fact_cur = 2;
    uint64_t factorial = 1;

    for (int i = 0; i < 12; i++) {
        div = div * xsq;
        factorial *= (fact_cur) * (fact_cur + 1);
        fact_cur += 2;
        float result = div / factorial;
        if (i & 1) sum += result;
        else sum -= result;
    }
    return sum;
}

double test_sind(double x) {
    double sum = x;
    double div = x;
    const double xsq = x * x;
    unsigned int fact_cur = 2;
    uint64_t factorial = 1;

    for (int i = 0; i < 12; i++) {
        div = div * xsq;
        factorial *= (fact_cur) * (fact_cur + 1);
        fact_cur += 2;
        double result = div / factorial;
        if (i & 1) sum += result;
        else sum -= result;
    }
    return sum;
}

#define ERROR_RANGE 1.0e-5

int compare(float v, float expected) {
    float a = test_sinf(v);
    if ((a <= (expected + ERROR_RANGE)) && (a >= (expected - ERROR_RANGE))) return 0;
    double b = test_sind(v);
    if ((b <= (expected + ERROR_RANGE)) && (b >= (expected - ERROR_RANGE))) return 0;
    return -1;
}

static const float expected_result[] = {
    0,          // 0.00
    0.109778,   // 0.11
    0.21823,    // 0.22
    0.324043,   // 0.33
    0.42594,    // 0.44
    0.522687,   // 0.55
    0.613117,   // 0.66
    0.696135,   // 0.77
    0.770739,   // 0.88
    0.836026,   // 0.99
    0.891207,   // 1.10
    0.935616,   // 1.21
    0.968715,   // 1.32
    0.990105,   // 1.43
    0.999526,   // 1.54
    0.996865,   // 1.65
    0.982154,   // 1.76
    0.955571,   // 1.87
    0.917438,   // 1.98
    0.868214,   // 2.09
    0.808496,   // 2.20
    0.739005,   // 2.31
    0.660581,   // 2.42
    0.574172,   // 2.53
    0.480823,   // 2.64
    0.381661,   // 2.75
    0.277886,   // 2.86
    0.170753,   // 2.97
    0.0615545,  // 3.08
    -0.0483875, // 3.19
    -0.157745,  // 3.30
};

int main(void) {
    assert(compare(0, 0.0) == 0);
    assert(compare(M_PI_2, 1.0) == 0);
    assert(compare(M_PI, 0.0) == 0);
    printf("success\n");
    float f = 0.0;
    for (int i = 0; i < sizeof(expected_result) / sizeof(expected_result[0]); i++) {
        assert(compare(f, expected_result[i]) == 0);
        f += 0.11;
    }
    return 0;
}
