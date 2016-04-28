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
//   float fTimeDelta;                  // Offset:   32 Size:     4
//   float fBloomBlurDistance;          // Offset:   36 Size:     4 [unused]
//   float fDoFFar;                     // Offset:   40 Size:     4 [unused]
//   float fDoFNear;                    // Offset:   44 Size:     4 [unused]
//   float fRcpFrameX;                  // Offset:   48 Size:     4 [unused]
//   float fRcpFrameY;                  // Offset:   52 Size:     4 [unused]
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
// pointSampler                      sampler      NA          NA    2        1
// lumTex                            texture  float4          2d   25        1
// lumTex1                           texture  float4          2d   26        1
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
dcl_constantbuffer cb7[3], immediateIndexed
dcl_sampler s2, mode_default
dcl_resource_texture2d (float,float,float,float) t25
dcl_resource_texture2d (float,float,float,float) t26
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 1

#line 139 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\source\BloomPost.hlsl"
sample_indexable(texture2d)(float,float,float,float) r0.x, v1.xyxx, t26.xyzw, s2
mul r0.x, r0.x, l(1.442695)
exp r0.x, r0.x  // fLastLum<0:Inf:[0f,1.#INFf]>
sample_indexable(texture2d)(float,float,float,float) r0.y, v1.xyxx, t25.yxzw, s2
mov r0.y, r0.y  // fCurrentLum<0:Inf>
mov r0.z, -r0.x
add r0.y, r0.z, r0.y
mov r0.z, -cb7[2].x
mul r0.z, r0.z, l(1.000000)
mul r0.z, r0.z, l(1.442695)
exp r0.z, r0.z
mov r0.z, -r0.z
add r0.z, r0.z, l(1.000000)
mul r0.y, r0.z, r0.y
add r0.x, r0.y, r0.x  // fAdaptedLum<0:NaN:Inf>
log r0.x, r0.x
mul o0.x, r0.x, l(0.693147)  // PS_ADAPT_LUMINANCE<0:NaN:Inf>
mov o0.yzw, l(0,1.000000,1.000000,1.000000)  // PS_ADAPT_LUMINANCE<1: 1f,2: 1f,3: 1f>
ret 
// Approximately 19 instruction slots used