//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Buffer Definitions: 
//
// cbuffer TexInfo
// {
//
//   float fBloomOriginalIntensity;     // Offset:    0 Size:     4 [unused]
//   float fBloomIntensity;             // Offset:    4 Size:     4 [unused]
//   float fBloomOriginalSaturation;    // Offset:    8 Size:     4 [unused]
//   float fBloomSaturation;            // Offset:   12 Size:     4 [unused]
//   float fRayExposure;                // Offset:   16 Size:     4 [unused]
//   float fRayDecay;                   // Offset:   20 Size:     4 [unused]
//   float fRayDensity;                 // Offset:   24 Size:     4 [unused]
//   float fRayWeight;                  // Offset:   28 Size:     4 [unused]
//   float fTimeDelta;                  // Offset:   32 Size:     4 [unused]
//   float fBloomBlurDistance;          // Offset:   36 Size:     4 [unused]
//   float fDoFFar;                     // Offset:   40 Size:     4 [unused]
//   float fDoFNear;                    // Offset:   44 Size:     4 [unused]
//   float fRcpFrameX;                  // Offset:   48 Size:     4
//   float fRcpFrameY;                  // Offset:   52 Size:     4
//   uint uPad5;                        // Offset:   56 Size:     4 [unused]
//   uint uPad6;                        // Offset:   60 Size:     4 [unused]
//   float4 f4GodRayPos;                // Offset:   64 Size:    16 [unused]
//   float4 f4rcpFrameOpt;              // Offset:   80 Size:    16 [unused]
//   float4 f4DoFParams;                // Offset:   96 Size:    16 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// linearSampler                     sampler      NA          NA    1        1
// pointSampler                      sampler      NA          NA    2        1
// tex2D[7]                          texture  float4          2d   22        1
// depthblurTex                      texture  float4          2d   24        1
// TexInfo                           cbuffer      NA          NA    7        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 2   xyzw        2     NONE  float       
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_TARGET                0   xyzw        0   TARGET  float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb7[4], immediateIndexed
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_resource_texture2d (float,float,float,float) t22
dcl_resource_texture2d (float,float,float,float) t24
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 6

#line 100 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\source\depthoffield.hlsl"
mov r0.xy, v1.xyxx  // f2CenterCoord<0,1>
mov r0.zw, cb7[3].xxxy  // f2rcpFrame<0,1>
mov r0.zw, r0.zzzw  // f2OffsetConversion<0,1>
sample_indexable(texture2d)(float,float,float,float) r1.xyz, v1.xyxx, t22.xyzw, s1  // f3CenterColor<0:Inf,1:Inf,2:Inf>
mov r1.xyz, r1.xyzx  // f3ColorSum<0:Inf,1:Inf,2:Inf>

#line 108
sample_indexable(texture2d)(float,float,float,float) r2.xy, v1.xyxx, t24.xyzw, s2  // f2CenterDepthBlur<1:Inf>
mov r2.xy, r2.xyxx  // f2CenterDepthBlur<0:Inf,1:Inf>
mov r2.x, r2.x  // fCenterDepth<0:Inf>
mov r2.y, r2.y  // fCenterBlur<0:Inf>

#line 114
lt r1.w, l(0.000000), r2.y
if_nz r1.w

#line 117
  mul r1.w, r2.y, l(0.003500)  // fCoCSize<0:Inf:[0f,1.#INFf]>

#line 122
  mul r2.z, r1.w, l(0.206984)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r3.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r3.xyz, r3.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r3.xyz, r2.zzzz, r3.xyzx
  add r3.xyz, r1.xyzx, r3.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, l(1.000000, 1.000000, 1.000000, 0.000000)  // f3TotalContribution<0:Inf,1:Inf,2:Inf>

#line 122
  mul r2.z, r1.w, l(0.525808)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(0.138394)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(0.663301)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(-0.400279)  // fOffset<0:Inf:[-1.#INFf,0f]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(0.079128)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(-0.772607)  // fOffset<0:Inf:[-1.#INFf,0f]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(-0.384319)  // fOffset<0:Inf:[-1.#INFf,0f]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(-0.910778)  // fOffset<0:Inf:[-1.#INFf,0f]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(0.694015)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(-0.196467)  // fOffset<0:Inf:[-1.#INFf,0f]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(-0.476929)  // fOffset<0:Inf:[-1.#INFf,0f]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(-0.247328)  // fOffset<0:Inf:[-1.#INFf,0f]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(0.420654)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r2.z, r1.w, l(0.582935)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r2.zw, r0.xxxy, r2.zzzz
  add r2.zw, r0.zzzw, r2.zzzw  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r5.xyz, r2.zwzz, t22.xyzw, s1, r2.y
  mov r5.xyz, r5.xyzx  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.zw, r2.zwzz, t24.zwxy, s2, l(0.000000)
  mov r2.zw, r2.zzzw  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r2.z, r2.x, r2.z
  movc r2.z, r2.z, l(1.000000), r2.w  // fTabContribution<0:Inf>
  mul r5.xyz, r2.zzzz, r5.xyzx
  add r3.xyz, r3.xyzx, r5.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r4.xyz, r2.zzzz, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 122
  mul r1.w, r1.w, l(0.369184)  // fOffset<0:Inf:[0f,1.#INFf]>
  add r0.xy, r0.xyxx, r1.wwww
  add r0.xy, r0.zwzz, r0.xyxx  // f2TapCoord<0:Inf,1:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r2.yzw, r0.xyxx, t22.wxyz, s1, r2.y  // f3TapColor<0:Inf,1:Inf,2:Inf>
  sample_l_indexable(texture2d)(float,float,float,float) r0.xy, r0.xyxx, t24.xyzw, s2, l(0.000000)  // f2TapDepthBlur<0:Inf,1:Inf>

#line 132
  lt r0.x, r2.x, r0.x
  movc r0.x, r0.x, l(1.000000), r0.y  // fTabContribution<0:Inf>
  mul r0.yzw, r0.xxxx, r2.yyzw
  add r1.xyz, r0.yzwy, r3.xyzx  // f3ColorSum<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  add r0.xyz, r0.xxxx, r4.xyzx  // f3TotalContribution<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 114
else 
  mov r0.xyz, l(1.000000,1.000000,1.000000,0)  // f3TotalContribution<0: 1f,1: 1f,2: 1f>
endif 

#line 139
div r0.xyz, r1.xyzx, r0.xyzx  // f3FinalColor<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
mov o0.w, l(1.000000)  // PS_DepthofField<3: 1f>
mov o0.xyz, r0.xyzx  // PS_DepthofField<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
ret 
// Approximately 209 instruction slots used