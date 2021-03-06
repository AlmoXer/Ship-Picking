//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Buffer Definitions: 
//
// cbuffer cbPerFrame
// {
//
//   float4x4 g_mView;                  // Offset:    0 Size:    64 [unused]
//   float4x4 g_mViewInv;               // Offset:   64 Size:    64 [unused]
//   float4x4 g_mProjection;            // Offset:  128 Size:    64 [unused]
//   float4x4 g_mProjectionInv;         // Offset:  192 Size:    64 [unused]
//   float4x4 g_mProjectionInvViewport; // Offset:  256 Size:    64 [unused]
//   float4 g_f4AmbientColorUp;         // Offset:  320 Size:    16 [unused]
//   float4 g_f4AmbientColorDown;       // Offset:  336 Size:    16 [unused]
//   float3 g_f3CameraPos;              // Offset:  352 Size:    12 [unused]
//   float g_fAlphaTest;                // Offset:  364 Size:     4 [unused]
//   uint g_uNumLights;                 // Offset:  368 Size:     4 [unused]
//   uint g_uNumSpotLights;             // Offset:  372 Size:     4 [unused]
//   uint g_uWindowWidth;               // Offset:  376 Size:     4 [unused]
//   uint g_uWindowHeight;              // Offset:  380 Size:     4 [unused]
//   uint g_uMaxNumLightsPerTile;       // Offset:  384 Size:     4 [unused]
//   uint g_uMaxNumElementsPerTile;     // Offset:  388 Size:     4 [unused]
//   uint g_uNumTilesX;                 // Offset:  392 Size:     4 [unused]
//   uint g_uNumTilesY;                 // Offset:  396 Size:     4 [unused]
//   uint g_uMaxVPLs;                   // Offset:  400 Size:     4 [unused]
//   uint g_uMaxNumVPLsPerTile;         // Offset:  404 Size:     4 [unused]
//   uint g_uMaxNumVPLElementsPerTile;  // Offset:  408 Size:     4 [unused]
//   float g_fVPLSpotStrength;          // Offset:  412 Size:     4 [unused]
//   float g_fVPLSpotRadius;            // Offset:  416 Size:     4 [unused]
//   float g_fVPLPointStrength;         // Offset:  420 Size:     4
//   float g_fVPLPointRadius;           // Offset:  424 Size:     4
//   float g_fVPLRemoveBackFaceContrib; // Offset:  428 Size:     4 [unused]
//   float g_fVPLColorThreshold;        // Offset:  432 Size:     4
//   float g_fVPLBrightnessThreshold;   // Offset:  436 Size:     4
//   float g_fPerFramePad1;             // Offset:  440 Size:     4 [unused]
//   float g_fPerFramePad2;             // Offset:  444 Size:     4 [unused]
//
// }
//
// Resource bind info for g_invViewProjMatrices
// {
//
//   float4x4 $Element;                 // Offset:    0 Size:    64
//
// }
//
// Resource bind info for g_vplPositionBuffer
// {
//
//   float4 $Element;                   // Offset:    0 Size:    16
//
// }
//
// Resource bind info for g_VPLData
// {
//
//   struct SVPLData
//   {
//       
//       float4 f4Direction;            // Offset:    0
//       float4 f4Color;                // Offset:   16
//       float4 f4SourceLightDirection; // Offset:   32
//
//   } $Element;                        // Offset:    0 Size:    48
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_RSMDepthAtlas                   texture  float4          2d    0        1
// g_RSMNormalAtlas                  texture  float4          2d    1        1
// g_RSMDiffuseAtlas                 texture  float4          2d    2        1
// g_invViewProjMatrices             texture  struct         r/o    3        1
// g_pointLightCenterAndRadiusBuffer    texture  float4         buf    4        1
// g_pointLightColorBuffer           texture  float4         buf    5        1
// g_vplPositionBuffer                   UAV  struct     r/w+cnt    0        1
// g_VPLData                             UAV  struct         r/w    1        1
// cbPerFrame                        cbuffer      NA          NA    2        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb2[28], immediateIndexed
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_resource_structured t3, 64 
dcl_resource_buffer (float,float,float,float) t4
dcl_resource_buffer (float,float,float,float) t5
dcl_uav_structured_opc u0, 16
dcl_uav_structured u1, 48
dcl_input vThreadID.xy
dcl_temps 8
dcl_thread_group 16, 16, 1

#line 35 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\source\generatevpls.hlsl"
imul null, r0.xy, l(2, 2, 0, 0), vThreadID.xyxx  // uv00<0:[0u,2228188u],1:[0u,2228188u]>

#line 40
imul null, r1.x, l(2), vThreadID.y
udiv r1.x, null, r1.x, l(32)  // uiLightIndex<0:[0u,69630u]>
imul null, r1.y, l(2), vThreadID.x
udiv r1.y, null, r1.y, l(32)  // uiFaceIndex<0:[0u,69630u]>

#line 46
mov r0.xy, r0.xyxx  // uv<0:[0u,2228188u],1:[0u,2228188u]>
mov r0.zw, l(0,0,0,0)
ld_indexable(texture2d)(float,float,float,float) r2.xyz, r0.xyww, t2.xyzw
mov r2.xyz, r2.xyzx  // f3Color<0:Inf,1:Inf,2:Inf>
ld_indexable(texture2d)(float,float,float,float) r3.xyz, r0.xyww, t1.xyzw
mul r3.xyz, r3.xyzx, l(2.000000, 2.000000, 2.000000, 0.000000)
add r3.xyz, r3.xyzx, l(-1.000000, -1.000000, -1.000000, 0.000000)  // f3Normal<0:Inf,1:Inf,2:Inf>
utof r1.zw, r0.xxxy  // f2ViewportUV<0:[0f,2.22819e+006f],1:[0f,2.22819e+006f]>
mul r1.zw, r1.zzzw, l(0.000000, 0.000000, 0.031250, 0.031250)
frc r1.zw, r1.zzzw
mul r1.zw, r1.zzzw, l(0.000000, 0.000000, 32.000000, 32.000000)  // f2ViewportUV<0:NaN,1:NaN>
ld_indexable(texture2d)(float,float,float,float) r0.z, r0.xyzw, t0.yzxw  // fDepth<0:Inf>
add r1.z, r1.z, l(0.500000)
div r1.z, r1.z, l(32.000000)
mul r1.z, r1.z, l(2.000000)
add r0.x, r1.z, l(-1.000000)  // fx<0:NaN>

#line 57
add r1.z, r1.w, l(0.500000)
div r1.z, r1.z, l(32.000000)
mov r1.z, -r1.z
mul r1.z, r1.z, l(2.000000)
add r0.y, r1.z, l(1.000000)  // fy<0:NaN>

#line 64
imad r1.y, l(6), r1.x, r1.y  // uiMatrixIndex<0:[0u,487410u]>

#line 67
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r4.x, r1.y, l(0), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r5.x, r1.y, l(16), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r6.x, r1.y, l(32), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r7.x, r1.y, l(48), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r4.y, r1.y, l(4), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r5.y, r1.y, l(20), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r6.y, r1.y, l(36), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r7.y, r1.y, l(52), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r4.z, r1.y, l(8), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r5.z, r1.y, l(24), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r6.z, r1.y, l(40), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r7.z, r1.y, l(56), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r4.w, r1.y, l(12), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r5.w, r1.y, l(28), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r6.w, r1.y, l(44), t3.xxxx  // g_invViewProjMatrices<0>
ld_structured_indexable(structured_buffer, stride=64)(mixed,mixed,mixed,mixed) r7.w, r1.y, l(60), t3.xxxx  // g_invViewProjMatrices<0>
mov r0.w, l(1.000000)
dp4 r4.x, r0.xyzw, r4.xyzw  // f4Position<0:NaN:Inf>
dp4 r4.y, r0.xyzw, r5.xyzw  // f4Position<1:NaN:Inf>
dp4 r4.z, r0.xyzw, r6.xyzw  // f4Position<2:NaN:Inf>
dp4 r0.x, r0.xyzw, r7.xyzw  // f4Position<3:NaN:Inf>
div r0.xyz, r4.xyzx, r0.xxxx  // f4Position<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 80
ld_indexable(buffer)(float,float,float,float) r4.xyzw, r1.xxxx, t4.xyzw  // f4SourceLightCenterAndRadius<0:Inf,1:Inf,2:Inf,3:Inf>
mov r4.xyz, r4.xyzx  // f3LightPos<0:Inf,1:Inf,2:Inf>

#line 84
mov r1.yzw, -r4.xxyz
add r1.yzw, r0.xxyz, r1.yyzw  // f3SourceLightDir<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
dp3 r0.w, r1.yzwy, r1.yzwy
sqrt r0.w, r0.w  // fLightDistance<0:NaN:Inf>

#line 88
div r0.w, r0.w, r4.w
mov r0.w, -r0.w
add r0.w, r0.w, l(1.000000)
max r0.w, r0.w, l(0.000000)
min r0.w, r0.w, l(1.000000)  // fFallOff<0:[0f,1f]>
mul r2.xyz, r0.wwww, r2.xyzx  // f3Color<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
dp3 r0.w, r2.xyzx, r2.xyzx
rsq r0.w, r0.w
mul r4.xyz, r0.wwww, r2.xyzx  // f3NormalizeColor<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
dp3 r0.w, r4.xyzx, l(1.000000, 0.000000, 0.000000, 0.000000)  // fDotR<0:NaN:Inf>
dp3 r2.w, r4.yxzy, l(1.000000, 0.000000, 0.000000, 0.000000)  // fDotG<0:NaN:Inf>
dp3 r3.w, r4.zyxz, l(1.000000, 0.000000, 0.000000, 0.000000)  // fDotB<0:NaN:Inf>
mov r4.x, cb2[27].x  // fThreashold<0>
lt r0.w, r4.x, r0.w
lt r2.w, r4.x, r2.w
or r0.w, r0.w, r2.w
lt r2.w, r4.x, r3.w
or r0.w, r0.w, r2.w  // bIsInterestingColor<0>

#line 99
if_nz r0.w

#line 107
  mov r0.w, cb2[26].z  // f4PosAndRadius<3>
  mul r2.w, l(1.000000), cb2[26].y  // fLightStrength<0>
  mov r0.xyz, r0.xyzx  // f4PosAndRadius<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 115
  ld_indexable(buffer)(float,float,float,float) r4.xyz, r1.xxxx, t5.xyzw
  mul r2.xyz, r2.xyzx, r4.xyzx
  mul r2.xyz, r2.wwww, r2.xyzx  // f3Color<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  dp3 r1.x, r2.xyzx, r2.xyzx
  sqrt r1.x, r1.x  // fColorStrength<0:NaN:Inf>
  lt r1.x, cb2[27].y, r1.x
  if_nz r1.x

#line 121
    mov r2.xyz, r2.xyzx  // data<4:NaN:Inf,5:NaN:Inf,6:NaN:Inf>
    mov r3.xyz, r3.xyzx  // data<0:Inf,1:Inf,2:Inf>

#line 127
    mov r1.xyz, -r1.yzwy
    dp3 r1.w, r1.xyzx, r1.xyzx
    rsq r1.w, r1.w
    mul r1.xyz, r1.wwww, r1.xyzx  // data<8:NaN:Inf,9:NaN:Inf,10:NaN:Inf>

#line 130
    imm_atomic_alloc r4.x, u0  // uiIndex<0>
    store_structured u0.x, r4.x, l(0), r0.x  // g_vplPositionBuffer<0>
    store_structured u0.x, r4.x, l(4), r0.y  // g_vplPositionBuffer<0>
    store_structured u0.x, r4.x, l(8), r0.z  // g_vplPositionBuffer<0>
    store_structured u0.x, r4.x, l(12), r0.w  // g_vplPositionBuffer<0>
    store_structured u1.x, r4.x, l(0), r3.x  // g_VPLData<0>
    store_structured u1.x, r4.x, l(4), r3.y  // g_VPLData<0>
    store_structured u1.x, r4.x, l(8), r3.z  // g_VPLData<0>
    store_structured u1.x, r4.x, l(12), l(0)  // g_VPLData<0>
    store_structured u1.x, r4.x, l(16), r2.x  // g_VPLData<0>
    store_structured u1.x, r4.x, l(20), r2.y  // g_VPLData<0>
    store_structured u1.x, r4.x, l(24), r2.z  // g_VPLData<0>
    store_structured u1.x, r4.x, l(28), l(1.000000)  // g_VPLData<0>
    store_structured u1.x, r4.x, l(32), r1.x  // g_VPLData<0>
    store_structured u1.x, r4.x, l(36), r1.y  // g_VPLData<0>
    store_structured u1.x, r4.x, l(40), r1.z  // g_VPLData<0>
    store_structured u1.x, r4.x, l(44), l(0)  // g_VPLData<0>

#line 118
  endif 

#line 99
endif 

#line 33
ret 
// Approximately 110 instruction slots used
