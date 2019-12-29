# SORT
<!--
Hide them until I am sure Github Action is reliable.
[![Build status](https://travis-ci.org/JiayinCao/SORT.svg?branch=master)](https://travis-ci.org/JiayinCao/SORT)
[![Build status](https://ci.appveyor.com/api/projects/status/la6ixha9tqe52qyr?svg=true)](https://ci.appveyor.com/project/JiayinCao/sort)
-->
[![Action status](https://github.com/JiayinCao/SORT/workflows/Build%20SORT/badge.svg)](https://actions-badge.atrox.dev/Jiayincao/SORT/goto)
[![License](https://img.shields.io/badge/License-GPL3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0.en.html)

## Introduction
SORT, short for Simple Open-source Ray Tracing, is my personal cross platform ray tracing renderer. It is a standalone ray tracing program, while works well in Blender as a renderer plugin. Simliar to other open source ray tracer, like PBRT, luxrenderer, SORT is also a physically based renderer. However, since it is a solo project that I worked on in my spare time, it is way simpler comparing with its peers.

This is just a brief introduction of SORT. For further detail, please check out [SORT main page](https://sort-renderer.com).

## Features

Here are the features implemented so far:
  - Integrator. (Whitted ray tracing, direct lighting, path tracing, light tracing, bidirectional path tracing, instant radiosity, ambient occlusion)
  - Spatial acceleration structure. (OBVH, QBVH, BVH, KD-Tree, Uniform grid, OcTree)
  - BXDF. (Disney BRDF, Lambert, LambertTransmission, Oran Nayar, MicroFacet Reflection, Microfacet Transmission, MERL, Fourier, AshikhmanShirley, Modified Phong, Coat, Blend, Double-Sided, DistributionBRDF, DreamWorks Fabric BRDF)
  - Subsurface Scattering
  - Fur, Hair
  - Support Open Shading Language.
  - Depth of Field.
  - Multi-thread rendering, SIMD(SSE,AVX) optimized.
  - Blender 2.8 plugin.

## Images
Following are some examples of images generated by SORT
![Image](http://sort-renderer.com/old/assets/main_page/human.png)
![Image](http://sort-renderer.com/old/assets/main_page/curly%20hair.png)
Thanks to [rico cilliers](https://www.artstation.com/ricocilliers) for his open source assets(both assets in the above images).
![Image](http://sort-renderer.com/old/assets/main_page/car.png)
Thanks to [Christophe Desse](https://www.artstation.com/christophe-desse) for offering the assets.
![Image](http://sort-renderer.com/old/assets/main_page/stormtrooper.png)
Thanks to [ScottGraham](https://www.blendswap.com/blend/13953) for the free downloadable asset. The above rendered image is not used for any commercial purposes. 
![Image](http://sort-renderer.com/old/assets/main_page/sss_dragon.png)
![Image](http://sort-renderer.com/old/assets/main_page/dinning%20room.png)
![Image](http://sort-renderer.com/old/assets/main_page/living%20room.png)
![Image](http://sort-renderer.com/old/assets/main_page/table.png)
