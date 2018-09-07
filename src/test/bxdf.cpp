/*
    This file is a part of SORT(Simple Open Ray Tracing), an open-source cross
    platform physically based renderer.
 
    Copyright (c) 2011-2018 by Cao Jiayin - All rights reserved.
 
    SORT is a free software written for educational purpose. Anyone can distribute
    or modify it under the the terms of the GNU General Public License Version 3 as
    published by the Free Software Foundation. However, there is NO warranty that
    all components are functional in a perfect manner. Without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.
 
    You should have received a copy of the GNU General Public License along with
    this program. If not, see <http://www.gnu.org/licenses/gpl-3.0.html>.
 */

#include "thirdparty/gtest/gtest.h"
#include "bsdf/bsdf.h"
#include "sampler/sample.h"
#include "spectrum/spectrum.h"
#include "bsdf/lambert.h"
#include "bsdf/orennayar.h"
#include "bsdf/phong.h"

void checkReciprocity(const Bxdf* bxdf) {
    static const int N = 8192;

    for (int i = 0; i < N; ++i) {
        Vector wi(sort_canonical(), sort_canonical(), sort_canonical());
        wi.Normalize();
        Vector wo(sort_canonical(), sort_canonical(), sort_canonical());
        wo.Normalize();

        const auto f0 = bxdf->F(wo, wi) * AbsCosTheta(wo);
        const auto f1 = bxdf->F(wi, wo) * AbsCosTheta(wi);
        EXPECT_NEAR(f0.GetR(), f1.GetR(), 0.001f);
        EXPECT_NEAR(f0.GetG(), f1.GetG(), 0.001f);
        EXPECT_NEAR(f0.GetB(), f1.GetB(), 0.001f);
    }
}

void checkEnergyConservation(Bxdf* bxdf) {
    static const int N = 8192;
    static const Vector wo(DIR_UP);

    Spectrum rho;
    for (int i = 0; i < N; ++i) {
        Vector wi;
        float pdf = 0.0f;
        Spectrum r = bxdf->Sample_F(wo, wi, BsdfSample(true), &pdf);
        rho += pdf > 0.0f ? r / pdf : 0.0f;
    }
    rho *= 1.0f / (float)N;
    EXPECT_LE(rho.GetR(), 1.0f);
    EXPECT_LE(rho.GetG(), 1.0f);
    EXPECT_LE(rho.GetB(), 1.0f);
}

TEST (BXDF, Labmert) { 
    static const Spectrum R(1.0f);
    Lambert lambert( R , R , DIR_UP );

    checkReciprocity(&lambert);
    checkEnergyConservation(&lambert);
}

TEST(BXDF, LabmertTransmittion) {
    static const Spectrum R(1.0f);
    LambertTransmission lambert(R, R, DIR_UP);

    checkReciprocity(&lambert);
    checkEnergyConservation(&lambert);
}

TEST(BXDF, OrenNayar) {
    static const Spectrum R(1.0f);
    OrenNayar orenNayar(R, sort_canonical(), R, DIR_UP);

    checkReciprocity(&orenNayar);
    checkEnergyConservation(&orenNayar);
}

TEST(BXDF, Phong) {
    static const Spectrum R(1.0f);
    const float ratio = sort_canonical();
    Phong phong( R * ratio , R * ( 1.0f - ratio ) , sort_canonical(), R, DIR_UP);

    checkReciprocity(&phong);
    checkEnergyConservation(&phong);
}