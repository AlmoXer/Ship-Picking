//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// linearSampler                     sampler      NA          NA    1        1
// tex2D[7]                          texture  float4          2d   22        1
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
dcl_sampler s1, mode_default
dcl_resource_texture2d (float,float,float,float) t22
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 1

#line 64 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\source\BloomPost.hlsl"
sample_indexable(texture2d)(float,float,float,float) r0.xyzw, v1.xyxx, t22.xyzw, s1  // f4ColorOut<0:Inf,1:Inf,2:Inf,3:Inf>

#line 67
add r0.xyzw, r0.xyzw, l(-0.900000, -0.900000, -0.900000, -0.900000)
div r0.xyzw, r0.xyzw, l(0.100000, 0.100000, 0.100000, 0.100000)
max r0.xyzw, r0.xyzw, l(0.000000, 0.000000, 0.000000, 0.000000)
min o0.xyzw, r0.xyzw, l(1.000000, 1.000000, 1.000000, 1.000000)  // PS_BLOOMTEXTURE<0:[0f,1f],1:[0f,1f],2:[0f,1f],3:[0f,1f]>
ret 
// Approximately 6 instruction slots used
