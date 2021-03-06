//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /T vs_5_0 /Zi /Od /Gfp /E OCC_VS /Fo
//    \\?\C:\Projects\Vektoria_2015-06-03\Vektoria\trunk\VektoriaApp\Shaders\Cache\Object\Debug\OCC_VS.obj
//    /Fe
//    \\?\C:\Projects\Vektoria_2015-06-03\Vektoria\trunk\VektoriaApp\Shaders\Cache\Error\OCC_VS.txt
//    /Fc
//    \\?\C:\Projects\Vektoria_2015-06-03\Vektoria\trunk\VektoriaApp\Shaders\Cache\Assembly\a7414bb9.asm
//    \\?\C:\Projects\Vektoria_2015-06-03\Vektoria\trunk\VektoriaApp\shaders\Source\occulus.hlsl
//
//
// Buffer Definitions: 
//
// cbuffer $Globals
// {
//
//   float2 EyeToSourceUVScale;         // Offset:    0 Size:     8
//   float2 EyeToSourceUVOffset;        // Offset:    8 Size:     8
//   float4x4 EyeRotationStart;         // Offset:   16 Size:    64
//   float4x4 EyeRotationEnd;           // Offset:   80 Size:    64
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// $Globals                          cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xy          0     NONE  float   xy  
// POSITION                 1   x           1     NONE  float   x   
// POSITION                 2   x           2     NONE  float   x   
// TEXCOORD                 0   xy          3     NONE  float   xy  
// TEXCOORD                 1   xy          4     NONE  float   xy  
// TEXCOORD                 2   xy          5     NONE  float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Position              0   xyzw        0      POS  float   xyzw
// TEXCOORD                 0   xy          1     NONE  float   xy  
// TEXCOORD                 1     zw        1     NONE  float     zw
// TEXCOORD                 2   xy          2     NONE  float   xy  
// TEXCOORD                 3     z         2     NONE  float     z 
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[9], immediateIndexed
dcl_input v0.xy
dcl_input v1.x
dcl_input v2.x
dcl_input v3.xy
dcl_input v4.xy
dcl_input v5.xy
dcl_output_siv o0.xyzw, position
dcl_output o1.xy
dcl_output o1.zw
dcl_output o2.xy
dcl_output o2.z
dcl_temps 6

#line 24 "\\?\C:\Projects\Vektoria_2015-06-03\Vektoria\trunk\VektoriaApp\shaders\Source\occulus.hlsl"
mov r0.xy, -cb0[1].xyxx
mov r0.zw, -cb0[2].xxxy
mov r1.xy, -cb0[3].xyxx
mov r1.zw, -cb0[4].xxxy
mov r2.x, cb0[1].z
mov r2.y, cb0[2].z
mov r2.z, cb0[3].z
mov r2.w, cb0[4].z
mov r3.xyzw, -r2.xyzw
add r4.x, r0.x, cb0[5].x
add r4.y, r0.z, cb0[6].x
add r4.z, r1.x, cb0[7].x
add r4.w, r1.z, cb0[8].x
add r5.x, r0.y, cb0[5].y
add r5.y, r0.w, cb0[6].y
add r5.z, r1.y, cb0[7].y
add r5.w, r1.w, cb0[8].y
add r0.x, r3.x, cb0[5].z
add r0.y, r3.y, cb0[6].z
add r0.z, r3.z, cb0[7].z
add r0.w, r3.w, cb0[8].z
mul r1.xyzw, r4.xyzw, v1.xxxx
mul r3.xyzw, r5.xyzw, v1.xxxx
mul r0.xyzw, r0.xyzw, v1.xxxx
add r4.x, r1.x, cb0[1].x  // lerpedEyeRot<0:NaN:Inf>
add r4.y, r1.y, cb0[2].x  // lerpedEyeRot<1:NaN:Inf>
add r4.z, r1.z, cb0[3].x  // lerpedEyeRot<2:NaN:Inf>
add r4.w, r1.w, cb0[4].x  // lerpedEyeRot<3:NaN:Inf>
add r1.x, r3.x, cb0[1].y  // lerpedEyeRot<4:NaN:Inf>
add r1.y, r3.y, cb0[2].y  // lerpedEyeRot<5:NaN:Inf>
add r1.z, r3.z, cb0[3].y  // lerpedEyeRot<6:NaN:Inf>
add r1.w, r3.w, cb0[4].y  // lerpedEyeRot<7:NaN:Inf>
add r0.xyzw, r0.xyzw, r2.xyzw  // lerpedEyeRot<8:NaN:Inf,9:NaN:Inf,10:NaN:Inf,11:NaN:Inf>
nop 

#line 10
mov r2.zw, l(0,0,1.000000,1.000000)
mov r2.xy, v3.xyxx
dp4 r3.x, r4.xyzw, r2.xyzw  // transformed<0:NaN:Inf>
dp4 r3.y, r1.xyzw, r2.xyzw  // transformed<1:NaN:Inf>
dp4 r2.x, r0.xyzw, r2.xyzw  // transformed<2:NaN:Inf>
div r2.xy, r3.xyxx, r2.xxxx  // flattened<0:NaN:Inf,1:NaN:Inf>
mul r2.xy, r2.xyxx, cb0[0].xyxx
add r2.xy, r2.xyxx, cb0[0].zwzz  // TimewarpTexCoord<0:NaN:Inf,1:NaN:Inf>

#line 25
mov o1.xy, r2.xyxx  // oTexCoord0<0:NaN:Inf,1:NaN:Inf>
nop 

#line 10
mov r2.zw, l(0,0,1.000000,1.000000)
mov r2.xy, v4.xyxx
dp4 r3.z, r4.xyzw, r2.xyzw  // transformed<0:NaN:Inf>
dp4 r3.w, r1.xyzw, r2.xyzw  // transformed<1:NaN:Inf>
dp4 r2.x, r0.xyzw, r2.xyzw  // transformed<2:NaN:Inf>
div r2.xy, r3.zwzz, r2.xxxx  // flattened<0:NaN:Inf,1:NaN:Inf>
mul r2.xy, r2.xyxx, cb0[0].xyxx
add r2.xy, r2.xyxx, cb0[0].zwzz  // TimewarpTexCoord<0:NaN:Inf,1:NaN:Inf>

#line 26
mov o1.zw, r2.xxxy  // oTexCoord1<0:NaN:Inf,1:NaN:Inf>
nop 

#line 10
mov r2.zw, l(0,0,1.000000,1.000000)
mov r2.xy, v5.xyxx
dp4 r3.x, r4.xyzw, r2.xyzw  // transformed<0:NaN:Inf>
dp4 r3.y, r1.xyzw, r2.xyzw  // transformed<1:NaN:Inf>
dp4 r0.x, r0.xyzw, r2.xyzw  // transformed<2:NaN:Inf>
div r0.xy, r3.xyxx, r0.xxxx  // flattened<0:NaN:Inf,1:NaN:Inf>
mul r0.xy, r0.xyxx, cb0[0].xyxx
add r0.xy, r0.xyxx, cb0[0].zwzz  // TimewarpTexCoord<0:NaN:Inf,1:NaN:Inf>

#line 27
mov o2.xy, r0.xyxx  // oTexCoord2<0:NaN:Inf,1:NaN:Inf>
mov o0.xy, v0.xyxx  // oPosition<0,1>
mov o0.zw, l(0,0,0.500000,1.000000)  // oPosition<2: 0.5f,3: 1f>
mov o2.z, v2.x  // oVignette<0>

#line 17
ret 
// Approximately 67 instruction slots used
