//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
// Buffer Definitions: 
//
// cbuffer cbPerFrame
// {
//
//   float4x4 g_mView;                  // Offset:    0 Size:    64
//   float4x4 g_mViewInv;               // Offset:   64 Size:    64 [unused]
//   float4x4 g_mProjection;            // Offset:  128 Size:    64 [unused]
//   float4x4 g_mProjectionInv;         // Offset:  192 Size:    64
//   float4x4 g_mProjectionInvViewport; // Offset:  256 Size:    64 [unused]
//   float4 g_f4AmbientColorUp;         // Offset:  320 Size:    16 [unused]
//   float4 g_f4AmbientColorDown;       // Offset:  336 Size:    16 [unused]
//   float3 g_f3CameraPos;              // Offset:  352 Size:    12 [unused]
//   float g_fAlphaTest;                // Offset:  364 Size:     4 [unused]
//   uint g_uNumLights;                 // Offset:  368 Size:     4
//   uint g_uNumSpotLights;             // Offset:  372 Size:     4
//   uint g_uWindowWidth;               // Offset:  376 Size:     4 [unused]
//   uint g_uWindowHeight;              // Offset:  380 Size:     4 [unused]
//   uint g_uMaxNumLightsPerTile;       // Offset:  384 Size:     4
//   uint g_uMaxNumElementsPerTile;     // Offset:  388 Size:     4
//   uint g_uNumTilesX;                 // Offset:  392 Size:     4
//   uint g_uNumTilesY;                 // Offset:  396 Size:     4
//   uint g_uMaxVPLs;                   // Offset:  400 Size:     4 [unused]
//   uint g_uMaxNumVPLsPerTile;         // Offset:  404 Size:     4 [unused]
//   uint g_uMaxNumVPLElementsPerTile;  // Offset:  408 Size:     4 [unused]
//   float g_fVPLSpotStrength;          // Offset:  412 Size:     4 [unused]
//   float g_fVPLSpotRadius;            // Offset:  416 Size:     4 [unused]
//   float g_fVPLPointStrength;         // Offset:  420 Size:     4 [unused]
//   float g_fVPLPointRadius;           // Offset:  424 Size:     4 [unused]
//   float g_fVPLRemoveBackFaceContrib; // Offset:  428 Size:     4 [unused]
//   float g_fVPLColorThreshold;        // Offset:  432 Size:     4 [unused]
//   float g_fVPLBrightnessThreshold;   // Offset:  436 Size:     4 [unused]
//   float g_fPerFramePad1;             // Offset:  440 Size:     4 [unused]
//   float g_fPerFramePad2;             // Offset:  444 Size:     4 [unused]
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_pointLightCenterAndRadiusBuffer    texture  float4         buf    0        1
// g_spotLightCenterAndRadiusBuffer    texture  float4         buf    1        1
// g_depthTexture                    texture   float          2d    3        1
// g_blendedDepthTexture             texture   float          2d    4        1
// g_perTilePointLightIndexBufferOut        UAV    uint         buf    0        1
// g_perTileSpotLightIndexBufferOut        UAV    uint         buf    1        1
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
dcl_constantbuffer cb2[25], immediateIndexed
dcl_resource_buffer (float,float,float,float) t0
dcl_resource_buffer (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t3
dcl_resource_texture2d (float,float,float,float) t4
dcl_uav_typed_buffer (uint,uint,uint,uint) u0
dcl_uav_typed_buffer (uint,uint,uint,uint) u1
dcl_input vThreadGroupID.xy
dcl_input vThreadIDInGroup.xy
dcl_input vThreadID.xy
dcl_temps 5
dcl_indexableTemp x8[4], 4
dcl_indexableTemp x9[4], 4
dcl_tgsm_raw g0, 4
dcl_tgsm_raw g1, 4
dcl_tgsm_raw g2, 4
dcl_tgsm_raw g3, 4
dcl_tgsm_structured g4, 4, 544
dcl_tgsm_raw g5, 4
dcl_tgsm_raw g6, 4
dcl_tgsm_structured g7, 4, 544
dcl_thread_group 32, 32, 1

#line 341 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\Source\tiling.hlsl"
imad r0.x, vThreadIDInGroup.y, l(32), vThreadIDInGroup.x  // uLocalIdxFlattened<0:[0u,1023u]>

#line 344
nop 
mov r1.xy, vThreadID.xyxx  // uGlobalIdx<0:[0u,2162654u],1:[0u,2162654u]>
mov r0.x, r0.x  // uLocalIdxFlattend<0:[0u,1023u]>
mov r0.yz, vThreadGroupID.xxyx  // uGroupIdx<0:[0u,65535u],1:[0u,65535u]>

#line 176
if_z r0.x
  store_raw g1.x, l(0), l(340282346638528860000000000000000000000.000000)  // ldsZMin<0>
  store_raw g0.x, l(0), l(0)  // ldsZMax<0>
  store_raw g2.x, l(0), l(0)  // ldsPointLightIdxCounterA<0>
  store_raw g3.x, l(0), l(272)  // ldsPointLightIdxCounterB<0>
  store_raw g5.x, l(0), l(0)  // ldsSpotLightIdxCounterA<0>
  store_raw g6.x, l(0), l(272)  // ldsSpotLightIdxCounterB<0>

#line 176
endif 

#line 193
imul null, r0.w, l(32), r0.y  // uPxm<0:[0u,2097120u]>
imul null, r2.x, l(32), r0.z  // uPym<0:[0u,2097120u]>
iadd r0.y, r0.y, l(1)
imul null, r0.y, l(32), r0.y  // uPxp<0:[32u,2097152u]>
iadd r0.z, r0.z, l(1)
imul null, r0.z, l(32), r0.z  // uPyp<0:[32u,2097152u]>
imul null, r2.y, l(32), cb2[24].z  // uWindowWitdthDivisibleByTileRes<0>
imul null, r2.z, l(32), cb2[24].w  // uWindowHeightDivisibkeByTileRes<0>

#line 203
nop 
utof r0.w, r0.w
utof r2.y, r2.y
div r0.w, r0.w, r2.y
mul r0.w, r0.w, l(2.000000)
add r3.x, r0.w, l(-1.000000)  // p<0:NaN:Inf>
imad r2.x, l(32), cb2[24].w, -r2.x
utof r2.x, r2.x
utof r2.z, r2.z
div r2.x, r2.x, r2.z
mul r2.x, r2.x, l(2.000000)
add r3.y, r2.x, l(-1.000000)  // p<1:NaN:Inf>

#line 97 "constant.h"
mov r3.zw, l(0,0,1.000000,1.000000)
dp4 r4.x, r3.xyww, cb2[12].xyzw  // p<0:NaN:Inf>
dp4 r4.y, r3.xyww, cb2[13].xyzw  // p<1:NaN:Inf>
dp4 r4.z, r3.xyww, cb2[14].xyzw  // p<2:NaN:Inf>
dp4 r2.w, r3.xyzw, cb2[15].xyzw  // p<3:NaN:Inf>
div r3.xyz, r4.xyzx, r2.wwww  // p<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
mov r3.xyz, r3.xyzx  // ConvertProjToView<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 203 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\Source\tiling.hlsl"
mov x9[0].xyz, r3.xyzx  // f4Frustum<0,1,2>

#line 206
nop 
utof r0.y, r0.y
div r0.y, r0.y, r2.y
mul r0.y, r0.y, l(2.000000)
add r3.x, r0.y, l(-1.000000)  // p<0:Inf:[-1f,1.#INFf]>
add r3.y, r2.x, l(-1.000000)  // p<1:NaN:Inf>

#line 97 "constant.h"
mov r3.zw, l(0,0,1.000000,1.000000)
dp4 r4.x, r3.xyww, cb2[12].xyzw  // p<0:NaN:Inf>
dp4 r4.y, r3.xyww, cb2[13].xyzw  // p<1:NaN:Inf>
dp4 r4.z, r3.xyww, cb2[14].xyzw  // p<2:NaN:Inf>
dp4 r2.x, r3.xyzw, cb2[15].xyzw  // p<3:NaN:Inf>
div r2.xyw, r4.xyxz, r2.xxxx  // p<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
mov r2.xyw, r2.xyxw  // ConvertProjToView<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 206 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\Source\tiling.hlsl"
mov x9[1].xyz, r2.xywx  // f4Frustum<4,5,6>

#line 209
nop 
add r3.x, r0.y, l(-1.000000)  // p<0:Inf:[-1f,1.#INFf]>
imad r0.y, l(32), cb2[24].w, -r0.z
utof r0.y, r0.y
div r0.y, r0.y, r2.z
mul r0.y, r0.y, l(2.000000)
add r3.y, r0.y, l(-1.000000)  // p<1:NaN:Inf>

#line 97 "constant.h"
mov r3.zw, l(0,0,1.000000,1.000000)
dp4 r2.x, r3.xyww, cb2[12].xyzw  // p<0:NaN:Inf>
dp4 r2.y, r3.xyww, cb2[13].xyzw  // p<1:NaN:Inf>
dp4 r2.z, r3.xyww, cb2[14].xyzw  // p<2:NaN:Inf>
dp4 r0.z, r3.xyzw, cb2[15].xyzw  // p<3:NaN:Inf>
div r2.xyz, r2.xyzx, r0.zzzz  // p<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
mov r2.xyz, r2.xyzx  // ConvertProjToView<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 209 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\Source\tiling.hlsl"
mov x9[2].xyz, r2.xyzx  // f4Frustum<8,9,10>

#line 212
nop 
add r2.x, r0.w, l(-1.000000)  // p<0:NaN:Inf>
add r2.y, r0.y, l(-1.000000)  // p<1:NaN:Inf>

#line 97 "constant.h"
mov r2.zw, l(0,0,1.000000,1.000000)
dp4 r3.x, r2.xyww, cb2[12].xyzw  // p<0:NaN:Inf>
dp4 r3.y, r2.xyww, cb2[13].xyzw  // p<1:NaN:Inf>
dp4 r3.z, r2.xyww, cb2[14].xyzw  // p<2:NaN:Inf>
dp4 r0.y, r2.xyzw, cb2[15].xyzw  // p<3:NaN:Inf>
div r0.yzw, r3.xxyz, r0.yyyy  // p<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
mov r0.yzw, r0.yyzw  // ConvertProjToView<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 212 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\Source\tiling.hlsl"
mov x9[3].xyz, r0.yzwy  // f4Frustum<12,13,14>

#line 217
mov r0.y, l(0)  // i<0: 0u>
mov r0.z, r0.y  // i<0>
loop 
  ult r0.w, r0.z, l(4)
  breakc_z r0.w
  nop 
  mov r2.xyz, x9[r0.z + 0].zxyz  // f4Frustum<2:NaN:Inf,0:NaN:Inf,1:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4b<2:NaN:Inf,0:NaN:Inf,1:NaN:Inf>
  iadd r0.w, r0.z, l(1)
  and r2.w, r0.w, l(3)
  mov r3.xyz, x9[r2.w + 0].yzxy  // f4Frustum<1:NaN:Inf,2:NaN:Inf,0:NaN:Inf>
  mov r3.xyz, r3.xyzx  // f4c<1:NaN:Inf,2:NaN:Inf,0:NaN:Inf>

#line 79
  mul r4.xyz, r2.zxyz, r3.yzxy
  mul r2.xyz, r2.xyzx, r3.xyzx
  mov r2.xyz, -r2.xyzx
  add r2.xyz, r2.xyzx, r4.xyzx
  dp3 r2.w, r2.xyzx, r2.xyzx
  rsq r2.w, r2.w
  mul r2.xyz, r2.wwww, r2.xyzx  // f4n<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  mov r2.xyz, r2.xyzx  // CreatePlaneEquation<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 219
  mov x8[r0.z + 0].xyz, r2.xyzx  // f4FrustumEqn[r0.z]<0:Inf,1:Inf,2:Inf>
  mov r0.z, r0.w  // i<0>
endloop 

#line 223
sync_g_t

#line 226
nop 
mov r1.xy, r1.xyxx  // uGlobalIdx<0:[0u,2162654u],1:[0u,2162654u]>

#line 93
mov r1.zw, l(0,0,0,0)
ld_indexable(texture2d)(float,float,float,float) r0.y, r1.xyzw, t3.yxzw
mov r0.y, r0.y  // fOpaqueDepth<0:Inf>
nop 
mov r0.y, r0.y  // z<0:Inf>

#line 105 "constant.h"
mul r0.y, r0.y, cb2[15].z
add r0.y, r0.y, cb2[15].w
div r0.y, l(1.000000), r0.y  // z<0:NaN:Inf>
mov r0.y, r0.y  // ConvertProjDepthToView<0:NaN:Inf>

#line 94 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\Source\tiling.hlsl"
mov r0.y, r0.y  // fOpaqueViewPosZ<0:NaN:Inf>
mov r0.y, r0.y  // uOpaqueZ<0>

#line 98
mov r1.zw, l(0,0,0,0)
ld_indexable(texture2d)(float,float,float,float) r0.z, r1.xyzw, t4.yzxw  // fBlendedDepth<0:Inf>
nop 
mov r0.z, r0.z  // z<0:Inf>

#line 105 "constant.h"
mul r0.w, r0.z, cb2[15].z
add r0.w, r0.w, cb2[15].w
div r0.w, l(1.000000), r0.w  // z<0:NaN:Inf>
mov r0.w, r0.w  // ConvertProjDepthToView<0:NaN:Inf>

#line 99 "\\?\C:\Projects\Vektoria_2015-05-22_V13withPatch4\Vektoria\trunk\VektoriaApp\shaders\Source\tiling.hlsl"
mov r0.w, r0.w  // fBlendedViewPosZ<0:NaN:Inf>
mov r0.w, r0.w  // uBlendedZ<0>
ne r0.z, r0.z, l(0.000000)
if_nz r0.z
  atomic_umax g0, l(0), r0.y  // ldsZMax<0>
  atomic_umin g1, l(0), r0.w  // ldsZMin<0>

#line 102
endif 

#line 233
sync_g_t
ld_raw r0.y, l(0), g0.xxxx  // ldsZMax<0>
mov r0.y, r0.y  // fMaxZ<0:NaN:Inf>
ld_raw r0.z, l(0), g1.xxxx  // ldsZMin<0>
mov r0.z, r0.z  // fMinZ<0:NaN:Inf>
add r0.w, r0.y, r0.z
div r0.w, r0.w, l(2.000000)  // fHalfZ<0:NaN:Inf>

#line 240
mov r1.x, r0.x  // i<0:[0u,1023u]>
mov r1.y, r1.x  // i<0>
loop 
  ult r1.z, r1.y, cb2[23].x
  breakc_z r1.z
  ld_indexable(buffer)(float,float,float,float) r2.xyzw, r1.yyyy, t0.xyzw  // f4Center<0:Inf,1:Inf,2:Inf>
  mov r1.z, r2.w  // f4Center<3:Inf>
  mov r1.z, r1.z  // fR<0:Inf>
  mov r2.w, l(1.000000)
  dp4 r3.x, r2.xyzw, cb2[0].xyzw  // f4Center<0:NaN:Inf>
  dp4 r3.y, r2.xyzw, cb2[1].xyzw  // f4Center<1:NaN:Inf>
  dp4 r3.z, r2.xyzw, cb2[2].xyzw  // f4Center<2:NaN:Inf>

#line 247
  nop 
  mov r3.xyz, r3.xyzx  // f4p<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  mov r2.xyz, x8[0].xyzx  // f4FrustumEqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r1.w, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 247
  lt r1.w, r1.w, r1.z
  nop 
  mov r2.xyz, x8[1].xyzx  // f4FrustumEqn<4:NaN:Inf,5:NaN:Inf,6:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r2.x, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 248
  lt r2.x, r2.x, r1.z
  and r1.w, r1.w, r2.x
  nop 
  mov r2.xyz, x8[2].xyzx  // f4FrustumEqn<8:NaN:Inf,9:NaN:Inf,10:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r2.x, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 249
  lt r2.x, r2.x, r1.z
  and r1.w, r1.w, r2.x
  nop 
  mov r2.xyz, x8[3].xyzx  // f4FrustumEqn<12:NaN:Inf,13:NaN:Inf,14:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r2.x, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 250
  lt r2.x, r2.x, r1.z
  and r1.w, r1.w, r2.x
  if_nz r1.w

#line 252
    mov r1.w, -r3.z
    add r2.x, r0.z, r1.w
    lt r2.x, r2.x, r1.z
    mov r2.y, -r0.w
    add r2.y, r2.y, r3.z
    lt r2.y, r2.y, r1.z
    and r2.x, r2.y, r2.x
    if_nz r2.x

#line 255
      imm_atomic_iadd r2.x, g2, l(0), l(1)  // uDstIdx<0>
      store_structured g4.x, r2.x, l(0), r1.y  // ldsPointLightIdx<0>

#line 252
    endif 

#line 258
    add r1.w, r0.w, r1.w
    lt r1.w, r1.w, r1.z
    mov r2.x, -r0.y
    add r2.x, r2.x, r3.z
    lt r1.z, r2.x, r1.z
    and r1.z, r1.z, r1.w
    if_nz r1.z

#line 261
      imm_atomic_iadd r2.x, g3, l(0), l(1)  // uDstIdx<0>
      store_structured g4.x, r2.x, l(0), r1.y  // ldsPointLightIdx<0>

#line 258
    endif 

#line 247
  endif 

#line 240
  iadd r1.y, r1.y, l(1024)  // i<0>
endloop 

#line 268
mov r1.y, r1.x  // j<0>
loop 
  ult r1.z, r1.y, cb2[23].y
  breakc_z r1.z
  ld_indexable(buffer)(float,float,float,float) r2.xyzw, r1.yyyy, t1.xyzw  // f4Center<0:Inf,1:Inf,2:Inf>
  mov r1.z, r2.w  // f4Center<3:Inf>
  mov r1.z, r1.z  // fR<0:Inf>
  mov r2.w, l(1.000000)
  dp4 r3.x, r2.xyzw, cb2[0].xyzw  // f4Center<0:NaN:Inf>
  dp4 r3.y, r2.xyzw, cb2[1].xyzw  // f4Center<1:NaN:Inf>
  dp4 r3.z, r2.xyzw, cb2[2].xyzw  // f4Center<2:NaN:Inf>

#line 275
  nop 
  mov r3.xyz, r3.xyzx  // f4p<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  mov r2.xyz, x8[0].xyzx  // f4FrustumEqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r1.w, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 275
  lt r1.w, r1.w, r1.z
  nop 
  mov r2.xyz, x8[1].xyzx  // f4FrustumEqn<4:NaN:Inf,5:NaN:Inf,6:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r2.x, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 276
  lt r2.x, r2.x, r1.z
  and r1.w, r1.w, r2.x
  nop 
  mov r2.xyz, x8[2].xyzx  // f4FrustumEqn<8:NaN:Inf,9:NaN:Inf,10:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r2.x, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 277
  lt r2.x, r2.x, r1.z
  and r1.w, r1.w, r2.x
  nop 
  mov r2.xyz, x8[3].xyzx  // f4FrustumEqn<12:NaN:Inf,13:NaN:Inf,14:NaN:Inf>
  mov r2.xyz, r2.xyzx  // f4eqn<0:NaN:Inf,1:NaN:Inf,2:NaN:Inf>

#line 87
  dp3 r2.x, r2.xyzx, r3.xyzx  // GetSignedDistanceFromPlane<0:NaN:Inf>

#line 278
  lt r2.x, r2.x, r1.z
  and r1.w, r1.w, r2.x
  if_nz r1.w

#line 280
    mov r1.w, -r3.z
    add r2.x, r0.z, r1.w
    lt r2.x, r2.x, r1.z
    mov r2.y, -r0.w
    add r2.y, r2.y, r3.z
    lt r2.y, r2.y, r1.z
    and r2.x, r2.y, r2.x
    if_nz r2.x

#line 283
      imm_atomic_iadd r2.x, g5, l(0), l(1)  // uDstIdx<0>
      store_structured g7.x, r2.x, l(0), r1.y  // ldsSpotLightIdx<0>

#line 280
    endif 

#line 286
    add r1.w, r0.w, r1.w
    lt r1.w, r1.w, r1.z
    mov r2.x, -r0.y
    add r2.x, r2.x, r3.z
    lt r1.z, r2.x, r1.z
    and r1.z, r1.z, r1.w
    if_nz r1.z

#line 289
      imm_atomic_iadd r2.x, g6, l(0), l(1)  // uDstIdx<0>
      store_structured g7.x, r2.x, l(0), r1.y  // ldsSpotLightIdx<0>

#line 286
    endif 

#line 275
  endif 

#line 268
  iadd r1.y, r1.y, l(1024)  // j<0>
endloop 

#line 344
mov r0.w, r0.w  // fHalfZ<0:NaN:Inf>

#line 348
imad r0.y, vThreadGroupID.y, cb2[24].z, vThreadGroupID.x  // uTileIdxFlattened<0>

#line 351
mov r0.z, r1.x  // i<0>
loop 
  ld_raw r1.y, l(0), g2.xxxx  // ldsPointLightIdxCounterA<0>
  ult r1.y, r0.z, r1.y
  breakc_z r1.y

#line 354
  imad r1.y, cb2[24].y, r0.y, r0.z
  iadd r1.y, r1.y, l(4)
  ld_structured r1.z, r0.z, l(0), g4.xxxx  // ldsPointLightIdx<0>
  store_uav_typed u0.xyzw, r1.yyyy, r1.zzzz  // g_perTilePointLightIndexBufferOut<0>

#line 351
  iadd r0.z, r0.z, l(1024)  // i<0>
endloop 

#line 357
mov r0.z, r1.x  // j<0>
loop 
  ld_raw r1.y, l(0), g3.xxxx  // ldsPointLightIdxCounterB<0>
  iadd r1.y, r1.y, l(-272)
  ult r1.y, r0.z, r1.y
  breakc_z r1.y

#line 360
  imad r1.y, cb2[24].y, r0.y, r0.z
  iadd r1.y, r1.y, l(4)
  iadd r1.y, r1.y, cb2[24].x
  iadd r1.z, r0.z, l(272)
  ld_structured r1.z, r1.z, l(0), g4.xxxx  // ldsPointLightIdx<0>
  store_uav_typed u0.xyzw, r1.yyyy, r1.zzzz  // g_perTilePointLightIndexBufferOut<0>

#line 357
  iadd r0.z, r0.z, l(1024)  // j<0>
endloop 

#line 363
if_z r0.x

#line 366
  mov r0.z, r0.w  // uHalfZBits<0>
  ushr r1.y, r0.z, l(16)  // uHalfZBitsHigh<0:[0u,65535u]>
  and r0.z, r0.z, l(0x0000ffff)  // uHalfZBitsLow<0:[0u,65535u]>
  imad r1.z, cb2[24].y, r0.y, l(0)
  store_uav_typed u0.xyzw, r1.zzzz, r1.yyyy  // g_perTilePointLightIndexBufferOut<0>
  imad r1.y, cb2[24].y, r0.y, l(1)
  store_uav_typed u0.xyzw, r1.yyyy, r0.zzzz  // g_perTilePointLightIndexBufferOut<0>

#line 373
  imad r0.z, cb2[24].y, r0.y, l(2)
  ld_raw r1.y, l(0), g2.xxxx  // ldsPointLightIdxCounterA<0>
  store_uav_typed u0.xyzw, r0.zzzz, r1.yyyy  // g_perTilePointLightIndexBufferOut<0>
  imad r0.z, cb2[24].y, r0.y, l(3)
  ld_raw r1.y, l(0), g3.xxxx  // ldsPointLightIdxCounterB<0>
  iadd r1.y, r1.y, l(-272)
  store_uav_typed u0.xyzw, r0.zzzz, r1.yyyy  // g_perTilePointLightIndexBufferOut<0>

#line 363
endif 

#line 384
mov r0.z, r1.x  // i<0>
loop 
  ld_raw r1.y, l(0), g5.xxxx  // ldsSpotLightIdxCounterA<0>
  ult r1.y, r0.z, r1.y
  breakc_z r1.y

#line 387
  imad r1.y, cb2[24].y, r0.y, r0.z
  iadd r1.y, r1.y, l(4)
  ld_structured r1.z, r0.z, l(0), g7.xxxx  // ldsSpotLightIdx<0>
  store_uav_typed u1.xyzw, r1.yyyy, r1.zzzz  // g_perTileSpotLightIndexBufferOut<0>

#line 384
  iadd r0.z, r0.z, l(1024)  // i<0>
endloop 

#line 390
mov r0.z, r1.x  // j<0>
loop 
  ld_raw r1.y, l(0), g6.xxxx  // ldsSpotLightIdxCounterB<0>
  iadd r1.y, r1.y, l(-272)
  ult r1.y, r0.z, r1.y
  breakc_z r1.y

#line 393
  imad r1.y, cb2[24].y, r0.y, r0.z
  iadd r1.y, r1.y, l(4)
  iadd r1.y, r1.y, cb2[24].x
  iadd r1.z, r0.z, l(272)
  ld_structured r1.z, r1.z, l(0), g7.xxxx  // ldsSpotLightIdx<0>
  store_uav_typed u1.xyzw, r1.yyyy, r1.zzzz  // g_perTileSpotLightIndexBufferOut<0>

#line 390
  iadd r0.z, r0.z, l(1024)  // j<0>
endloop 

#line 396
if_z r0.x

#line 399
  mov r0.w, r0.w  // uHalfZBits<0>
  ushr r0.x, r0.w, l(16)  // uHalfZBitsHigh<0:[0u,65535u]>
  and r0.z, r0.w, l(0x0000ffff)  // uHalfZBitsLow<0:[0u,65535u]>
  imad r0.w, cb2[24].y, r0.y, l(0)
  store_uav_typed u1.xyzw, r0.wwww, r0.xxxx  // g_perTileSpotLightIndexBufferOut<0>
  imad r0.x, cb2[24].y, r0.y, l(1)
  store_uav_typed u1.xyzw, r0.xxxx, r0.zzzz  // g_perTileSpotLightIndexBufferOut<0>

#line 406
  imad r0.x, cb2[24].y, r0.y, l(2)
  ld_raw r0.z, l(0), g5.xxxx  // ldsSpotLightIdxCounterA<0>
  store_uav_typed u1.xyzw, r0.xxxx, r0.zzzz  // g_perTileSpotLightIndexBufferOut<0>
  imad r0.x, cb2[24].y, r0.y, l(3)
  ld_raw r0.y, l(0), g6.xxxx  // ldsSpotLightIdxCounterB<0>
  iadd r0.y, r0.y, l(-272)
  store_uav_typed u1.xyzw, r0.xxxx, r0.yyyy  // g_perTileSpotLightIndexBufferOut<0>

#line 396
endif 

#line 339
ret 
// Approximately 346 instruction slots used
