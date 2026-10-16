#include "tekken6_funcs.28.h"

DEFINE_REX_FUNC(sub_82171770) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v0,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	ctx.r11.s64 = 48;
	// lvx128 v13,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8217AE88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x8217AE90;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d18
	ctx.lr = 0x8217AE98;
	__savefpr_28(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x826a18d4
	ctx.lr = 0x8217AEA0;
	__savevmx_124(ctx, base);
	// stwu r1,-3648(r1)
	ea = -3648 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,31
	ctx.r11.u64 = ctx.r4.u32 & 0x1;
	// lhz r28,4(r4)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r4.u32 + 4);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217b578
	if (!ctx.cr6.eq) goto loc_8217B578;
	// lhz r11,6(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 6);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8217b578
	if (ctx.cr6.lt) goto loc_8217B578;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x826a0de8
	ctx.lr = 0x8217AEDC;
	sub_826A0DE8(ctx, base);
	// lhz r11,2(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 2);
	// rlwinm r10,r29,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0x1;
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// subfc r9,r11,r29
	ctx.xer.ca = ctx.r29.u32 >= ctx.r11.u32;
	ctx.r9.u64 = ctx.r29.u64 - ctx.r11.u64;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// frsp f31,f1
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// subfe r6,r10,r8
	temp.u8 = (~ctx.r10.u32 + ctx.r8.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r10.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// and r10,r6,r29
	ctx.r10.u64 = ctx.r6.u64 & ctx.r29.u64;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r3,r10,2
	ctx.r3.s64 = ctx.r10.s64 + 2;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,3084(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 3084);
	ctx.f0.f64 = double(temp.f32);
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f28,2884(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 2884);
	ctx.f28.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fsubs f29,f28,f31
	ctx.f29.f64 = double(float(ctx.f28.f64 - ctx.f31.f64));
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// rlwinm r11,r9,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bge cr6,0x8217b178
	if (!ctx.cr6.lt) goto loc_8217B178;
	// fctiwz f0,f30
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8217a470
	ctx.lr = 0x8217AF60;
	sub_8217A470(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8217b578
	if (!ctx.cr6.eq) goto loc_8217B578;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x8217b568
	if (!ctx.cr6.gt) goto loc_8217B568;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
	// addi r31,r1,404
	ctx.r31.s64 = ctx.r1.s64 + 404;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// li r27,16
	ctx.r27.s64 = 16;
	// lfs f31,4276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4276);
	ctx.f31.f64 = double(temp.f32);
	// li r28,32
	ctx.r28.s64 = 32;
	// li r29,48
	ctx.r29.s64 = 48;
loc_8217AF90:
	// lhz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8217b0fc
	if (ctx.cr6.lt) goto loc_8217B0FC;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x8217b0fc
	if (ctx.cr6.gt) goto loc_8217B0FC;
	// lhz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + -4);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// bl 0x82179868
	ctx.lr = 0x8217AFC8;
	sub_82179868(ctx, base);
	// lhz r8,-2(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + -2);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// std r3,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lfd f11,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lvx128 v127,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r7,r27
	ea = (ctx.r7.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r7,r28
	ea = (ctx.r7.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v124,r7,r29
	ea = (ctx.r7.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f9,f31
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// bl 0x82179900
	ctx.lr = 0x8217B020;
	sub_82179900(ctx, base);
	// vspltw128 v0,v127,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xFF));
	// lvx128 v3,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v126,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xFF));
	// lhz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// vspltw128 v12,v125,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xFF));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vspltw128 v4,v124,0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xFF));
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// vmulfp128 v10,v0,v3
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v11,v127,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xAA));
	// vmulfp128 v8,v13,v3
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v9,v126,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xAA));
	// vmulfp128 v6,v12,v3
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v7,v125,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xAA));
	// vmulfp128 v4,v4,v3
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v3.f32)));
	// lvx128 v0,r3,r27
	ea = (ctx.r3.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v5,v124,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xAA));
	// lvx128 v13,r3,r28
	ea = (ctx.r3.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v3,v127,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x55));
	// lvx128 v12,r3,r29
	ea = (ctx.r3.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v126,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x55));
	// std r4,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r4.u64);
	// vspltw128 v1,v125,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x55));
	// lfd f8,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// vspltw128 v31,v124,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x55));
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// vmaddfp v11,v11,v0,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v30,v127,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x0));
	// vmaddfp v10,v9,v0,v8
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vspltw128 v29,v126,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x0));
	// vmaddfp v9,v7,v0,v6
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vspltw128 v28,v125,3
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x0));
	// vmaddfp v0,v5,v0,v4
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vspltw128 v27,v124,3
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x0));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// frsp f6,f7
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// vmaddfp v11,v3,v13,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v10,v2,v13,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v9,v1,v13,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v0,v31,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v13,v30,v12,v11
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v11,v29,v12,v10
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v10,v28,v12,v9
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v0,v27,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// fmuls f1,f6,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f31.f64));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8217a090
	ctx.lr = 0x8217B0F8;
	sub_8217A090(ctx, base);
	// b 0x8217b154
	goto loc_8217B154;
loc_8217B0FC:
	// lhz r10,-2(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + -2);
	// stfs f28,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// lhz r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// lhz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + -4);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r3,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f0
	ctx.f9.f64 = double(ctx.f0.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// stfs f6,0(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// stfs f8,8(r30)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// stfs f7,4(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
loc_8217B154:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r31,r31,6
	ctx.r31.s64 = ctx.r31.s64 + 6;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r25,r25,2
	ctx.r25.s64 = ctx.r25.s64 + 2;
	// bne 0x8217af90
	if (!ctx.cr0.eq) goto loc_8217AF90;
	// subf r11,r24,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r24.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x8217b57c
	goto loc_8217B57C;
loc_8217B178:
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// bl 0x8217a470
	ctx.lr = 0x8217B180;
	sub_8217A470(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8217b578
	if (!ctx.cr6.eq) goto loc_8217B578;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// addi r3,r1,1936
	ctx.r3.s64 = ctx.r1.s64 + 1936;
	// bl 0x8217a470
	ctx.lr = 0x8217B198;
	sub_8217A470(ctx, base);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x8217b568
	if (!ctx.cr6.gt) goto loc_8217B568;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
	// addi r31,r1,1940
	ctx.r31.s64 = ctx.r1.s64 + 1940;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// li r27,16
	ctx.r27.s64 = 16;
	// lfs f30,4276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4276);
	ctx.f30.f64 = double(temp.f32);
	// li r28,32
	ctx.r28.s64 = 32;
	// li r29,48
	ctx.r29.s64 = 48;
loc_8217B1C0:
	// lhz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8217b49c
	if (ctx.cr6.lt) goto loc_8217B49C;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x8217b49c
	if (ctx.cr6.gt) goto loc_8217B49C;
	// lhz r11,-1540(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + -1540);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// std r9,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x82179868
	ctx.lr = 0x8217B1F8;
	sub_82179868(ctx, base);
	// lhz r8,-1538(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + -1538);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// std r3,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lvx128 v127,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r7,r27
	ea = (ctx.r7.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r7,r28
	ea = (ctx.r7.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v124,r7,r29
	ea = (ctx.r7.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f9,f30
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f30.f64));
	// bl 0x82179900
	ctx.lr = 0x8217B250;
	sub_82179900(ctx, base);
	// vspltw128 v0,v127,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xFF));
	// lvx128 v11,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v126,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xFF));
	// lhz r7,-1536(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + -1536);
	// vspltw128 v12,v125,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xFF));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vspltw128 v10,v124,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xFF));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v4,v0,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v5,v127,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xAA));
	// vmulfp128 v2,v13,v11
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v3,v126,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xAA));
	// vmulfp128 v31,v12,v11
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v1,v125,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xAA));
	// vmulfp128 v29,v10,v11
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v0,r3,r27
	ea = (ctx.r3.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v30,v124,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xAA));
	// lvx128 v13,r3,r28
	ea = (ctx.r3.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v28,v127,2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x55));
	// lvx128 v12,r3,r29
	ea = (ctx.r3.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v27,v126,2
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x55));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// vspltw128 v6,v125,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x55));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// vspltw128 v7,v124,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x55));
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// vspltw128 v8,v127,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x0));
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// vspltw128 v9,v126,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x0));
	// std r4,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// vspltw128 v10,v125,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x0));
	// lfd f8,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// vmaddfp v5,v5,v0,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vspltw128 v11,v124,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x0));
	// vmaddfp v4,v3,v0,v2
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// vmaddfp v3,v1,v0,v31
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v0,v30,v0,v29
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v2,v28,v13,v5
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v5,v27,v13,v4
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v6,v6,v13,v3
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v0,v7,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v8,v8,v12,v2
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v9,v9,v12,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v13,v10,v12,v6
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v11,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v8,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f7,f8
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f1,f6,f30
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f30.f64));
	// bl 0x8217a090
	ctx.lr = 0x8217B328;
	sub_8217A090(ctx, base);
	// lhz r10,-4(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + -4);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// std r8,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f5,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmuls f1,f3,f30
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f30.f64));
	// bl 0x82179868
	ctx.lr = 0x8217B34C;
	sub_82179868(ctx, base);
	// lhz r7,-2(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + -2);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lvx128 v127,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f2,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lvx128 v126,r6,r27
	ea = (ctx.r6.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r6,r28
	ea = (ctx.r6.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v124,r6,r29
	ea = (ctx.r6.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// bl 0x82179900
	ctx.lr = 0x8217B3A4;
	sub_82179900(ctx, base);
	// vspltw128 v9,v127,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xFF));
	// lvx128 v5,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v8,v126,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xFF));
	// lvx128 v0,r3,r27
	ea = (ctx.r3.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v125,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xFF));
	// lvx128 v13,r3,r28
	ea = (ctx.r3.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v6,v124,0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xFF));
	// lvx128 v12,r3,r29
	ea = (ctx.r3.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v28,v9,v5
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v27,v127,1
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0xAA));
	// vmulfp128 v30,v8,v5
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v29,v126,1
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0xAA));
	// vmulfp128 v1,v7,v5
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v31,v125,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0xAA));
	// vmulfp128 v3,v6,v5
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vspltw128 v2,v124,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0xAA));
	// vspltw128 v4,v127,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x55));
	// lhz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// vspltw128 v5,v126,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x55));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// vspltw128 v6,v125,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x55));
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// vspltw128 v7,v124,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x55));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// vspltw128 v8,v127,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v127.u32), 0x0));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// vspltw128 v9,v126,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v126.u32), 0x0));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// vspltw128 v10,v125,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v125.u32), 0x0));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// vspltw128 v11,v124,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v124.u32), 0x0));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// vmaddfp v28,v27,v0,v28
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v28.f32)));
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// vmaddfp v30,v29,v0,v30
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v1,v31,v0,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v0,v2,v0,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v4,v4,v13,v28
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v28.f32)));
	// vmaddfp v5,v5,v13,v30
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vmaddfp v6,v6,v13,v1
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v0,v7,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v8,v8,v12,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v9,v9,v12,v5
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v13,v10,v12,v6
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v11,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v8,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stvx128 v9,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f30
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// bl 0x8217a090
	ctx.lr = 0x8217B47C;
	sub_8217A090(ctx, base);
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82179f38
	ctx.lr = 0x8217B490;
	sub_82179F38(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8217a000
	ctx.lr = 0x8217B498;
	sub_8217A000(ctx, base);
	// b 0x8217b554
	goto loc_8217B554;
loc_8217B49C:
	// lhz r11,-2(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + -2);
	// stfs f28,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// lhz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lhz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + -4);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r10,-1538(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + -1538);
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// lhz r8,-1536(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + -1536);
	// std r6,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r6.u64);
	// lfd f9,200(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 200);
	// std r3,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r3.u64);
	// lfd f11,224(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// lhz r4,-1540(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + -1540);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// std r5,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r5.u64);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// extsh r5,r4
	ctx.r5.s64 = ctx.r4.s16;
	// std r10,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r10.u64);
	// std r9,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r9.u64);
	// lfd f13,208(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 208);
	// std r5,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r5.u64);
	// lfd f12,192(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// lfd f6,216(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 216);
	// lfd f0,232(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 232);
	// fcfid f8,f0
	ctx.f8.f64 = double(ctx.f0.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// fcfid f4,f13
	ctx.f4.f64 = double(ctx.f13.s64);
	// fcfid f3,f12
	ctx.f3.f64 = double(ctx.f12.s64);
	// frsp f1,f8
	ctx.f1.f64 = double(float(ctx.f8.f64));
	// frsp f2,f10
	ctx.f2.f64 = double(float(ctx.f10.f64));
	// frsp f0,f7
	ctx.f0.f64 = double(float(ctx.f7.f64));
	// frsp f13,f5
	ctx.f13.f64 = double(float(ctx.f5.f64));
	// frsp f12,f4
	ctx.f12.f64 = double(float(ctx.f4.f64));
	// frsp f11,f3
	ctx.f11.f64 = double(float(ctx.f3.f64));
	// fmuls f9,f1,f31
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// fmuls f10,f2,f31
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f31.f64));
	// fmuls f8,f0,f31
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmadds f6,f12,f29,f9
	ctx.f6.f64 = double(float(std::fma(ctx.f12.f64, ctx.f29.f64, ctx.f9.f64)));
	// stfs f6,4(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// fmadds f7,f13,f29,f10
	ctx.f7.f64 = double(float(std::fma(ctx.f13.f64, ctx.f29.f64, ctx.f10.f64)));
	// stfs f7,0(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fmadds f5,f11,f29,f8
	ctx.f5.f64 = double(float(std::fma(ctx.f11.f64, ctx.f29.f64, ctx.f8.f64)));
	// stfs f5,8(r30)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
loc_8217B554:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r31,r31,6
	ctx.r31.s64 = ctx.r31.s64 + 6;
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// addi r25,r25,2
	ctx.r25.s64 = ctx.r25.s64 + 2;
	// bne 0x8217b1c0
	if (!ctx.cr0.eq) goto loc_8217B1C0;
loc_8217B568:
	// subf r11,r24,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r24.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x8217b57c
	goto loc_8217B57C;
loc_8217B578:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8217B57C:
	// addi r1,r1,3648
	ctx.r1.s64 = ctx.r1.s64 + 3648;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x826a1b6c
	ctx.lr = 0x8217B588;
	__restvmx_124(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d64
	ctx.lr = 0x8217B590;
	__restfpr_28(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821B33E8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,176(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821b3408
	if (ctx.cr6.eq) goto loc_821B3408;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,180(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821b340c
	if (ctx.cr6.eq) goto loc_821B340C;
loc_821B3408:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821B340C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r9,30048(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 30048);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,176(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821b3458
	if (ctx.cr6.eq) goto loc_821B3458;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,180(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821b345c
	if (ctx.cr6.eq) goto loc_821B345C;
loc_821B3458:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821B345C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821b3478
	if (ctx.cr6.eq) goto loc_821B3478;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821b347c
	if (!ctx.cr6.eq) goto loc_821B347C;
loc_821B3478:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821B347C:
	// lwz r10,1280(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1280);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,1280(r11)
	REX_STORE_U32(ctx.r11.u32 + 1280, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821B5428) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x821B5430;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,132
	ctx.r31.s64 = ctx.r3.s64 + 132;
	// li r30,96
	ctx.r30.s64 = 96;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
loc_821B5440:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821b5460
	if (ctx.cr6.eq) goto loc_821B5460;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x821b5464
	if (ctx.cr6.eq) goto loc_821B5464;
loc_821B5460:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821B5464:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821b5490
	if (ctx.cr6.eq) goto loc_821B5490;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r10,30048(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// and r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821b5490
	if (ctx.cr6.eq) goto loc_821B5490;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821b5490
	if (ctx.cr6.eq) goto loc_821B5490;
	// bl 0x821b65a8
	ctx.lr = 0x821B5490;
	sub_821B65A8(ctx, base);
loc_821B5490:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// bne 0x821b5440
	if (!ctx.cr0.eq) goto loc_821B5440;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821B7850) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,132(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x821b7898
	if (!ctx.cr6.lt) goto loc_821B7898;
	// lwz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x82178c20
	ctx.lr = 0x821B7884;
	sub_82178C20(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x826a0da8
	ctx.lr = 0x821B788C;
	sub_826A0DA8(ctx, base);
	// divw r10,r3,r30
	ctx.r10.u64 = uint32_t((ctx.r30.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r30.s32 == -1)) ? ctx.r3.s32 / ctx.r30.s32 : 0);
	// mullw r9,r10,r30
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r30.s32);
	// subf r11,r9,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r9.u64;
loc_821B7898:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,140(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 140, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821BA3D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x821BA3D8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// bgt cr6,0x821ba84c
	if (ctx.cr6.gt) goto loc_821BA84C;
	// lis r12,-32228
	ctx.r12.s64 = -2112094208;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-23528
	ctx.r12.s64 = ctx.r12.s64 + -23528;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_821BA444;
	case 1:
		goto loc_821BA478;
	case 2:
		goto loc_821BA4A8;
	case 3:
		goto loc_821BA84C;
	case 4:
		goto loc_821BA84C;
	case 5:
		goto loc_821BA4D8;
	case 6:
		goto loc_821BA53C;
	case 7:
		goto loc_821BA590;
	case 8:
		goto loc_821BA5CC;
	case 9:
		goto loc_821BA604;
	case 10:
		goto loc_821BA814;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_821BA444:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,164(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,12688(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12688);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x821ba84c
	if (!ctx.cr6.lt) goto loc_821BA84C;
	// li r27,1
	ctx.r27.s64 = 1;
	// stb r27,352(r31)
	REX_STORE_U8(ctx.r31.u32 + 352, ctx.r27.u8);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA478:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,164(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,12688(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12688);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x821ba84c
	if (!ctx.cr6.gt) goto loc_821BA84C;
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA4A8:
	// lfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lhz r11,344(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 344);
	// fctidz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lhz r10,86(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 86);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x821ba84c
	if (ctx.cr6.lt) goto loc_821BA84C;
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA4D8:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x82178c20
	ctx.lr = 0x821BA4E4;
	sub_82178C20(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lfs f0,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,140(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fadds f9,f0,f13
	ctx.f9.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f9,f10
	ctx.cr6.compare(ctx.f9.f64, ctx.f10.f64);
	// blt cr6,0x821ba84c
	if (ctx.cr6.lt) goto loc_821BA84C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,16(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lfs f0,6420(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6420);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
	// cmpw cr6,r28,r8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r8.s32, ctx.xer);
	// b 0x821ba844
	goto loc_821BA844;
loc_821BA53C:
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// lwz r4,36(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// lwz r3,116(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// bl 0x821b48f8
	ctx.lr = 0x821BA54C;
	sub_821B48F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ba84c
	if (ctx.cr6.eq) goto loc_821BA84C;
	// lwz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ba84c
	if (ctx.cr6.eq) goto loc_821BA84C;
	// lfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lhz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x821ba84c
	if (!ctx.cr6.eq) goto loc_821BA84C;
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA590:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,132(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// bl 0x821ba220
	ctx.lr = 0x821BA59C;
	sub_821BA220(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12688(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12688);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f1,f12
	ctx.cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bge cr6,0x821ba84c
	if (!ctx.cr6.lt) goto loc_821BA84C;
	// li r27,1
	ctx.r27.s64 = 1;
	// stb r27,352(r31)
	REX_STORE_U8(ctx.r31.u32 + 352, ctx.r27.u8);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA5CC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,132(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// bl 0x821ba220
	ctx.lr = 0x821BA5D8;
	sub_821BA220(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12688(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12688);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f1,f12
	ctx.cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// ble cr6,0x821ba84c
	if (!ctx.cr6.gt) goto loc_821BA84C;
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA604:
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lbz r9,64(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 64);
	// lfs f31,2884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821ba6e4
	if (ctx.cr6.eq) goto loc_821BA6E4;
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8227d9b0
	ctx.lr = 0x821BA63C;
	sub_8227D9B0(ctx, base);
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r10,316(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,312
	ctx.r11.s64 = ctx.r31.s64 + 312;
	// lvx128 v12,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lvx128 v11,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw v10,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vmrglw v9,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw v8,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vmrglw v7,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vmrghw v6,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vmrglw v5,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), simde_mm_load_si128((simde__m128i*)ctx.v10.u32)));
	// vmrghw v4,v9,v7
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.u32), simde_mm_load_si128((simde__m128i*)ctx.v9.u32)));
	// vmrglw v3,v9,v7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.u32), simde_mm_load_si128((simde__m128i*)ctx.v9.u32)));
	// vmsum4fp128 v2,v0,v6
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32), 0xFF));
	// vmsum4fp128 v1,v0,v5
	simde_mm_store_ps(ctx.v1.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32), 0xFF));
	// vmsum4fp128 v31,v0,v4
	simde_mm_store_ps(ctx.v31.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32), 0xFF));
	// vmsum4fp128 v30,v0,v3
	simde_mm_store_ps(ctx.v30.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32), 0xFF));
	// vmrghw v29,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v31.u32), simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	// vmrghw v28,v1,v30
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v30.u32), simde_mm_load_si128((simde__m128i*)ctx.v1.u32)));
	// vmrghw v0,v29,v28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v28.u32), simde_mm_load_si128((simde__m128i*)ctx.v29.u32)));
	// stvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x821ba6cc
	if (ctx.cr6.eq) goto loc_821BA6CC;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vsubfp v12,v0,v13
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x821ba718
	goto loc_821BA718;
loc_821BA6CC:
	// li r10,0
	ctx.r10.s64 = 0;
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vsubfp v12,v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x821ba718
	goto loc_821BA718;
loc_821BA6E4:
	// lwz r9,316(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// addi r11,r31,312
	ctx.r11.s64 = ctx.r31.s64 + 312;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821ba6fc
	if (ctx.cr6.eq) goto loc_821BA6FC;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// b 0x821ba700
	goto loc_821BA700;
loc_821BA6FC:
	// li r9,0
	ctx.r9.s64 = 0;
loc_821BA700:
	// li r8,48
	ctx.r8.s64 = 48;
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp v12,v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821BA718:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vspltisw v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f12,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f11,20(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// vcfsx v10,v0,1
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v0.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// lfs f0,2880(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v8,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// vrsqrtefp v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v8.f32))));
	// lfs f13,12688(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12688);
	ctx.f13.f64 = double(temp.f32);
	// vcmpeqfp v9,v8,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)));
	// fmuls f0,f12,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// vmulfp128 v13,v8,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v10.f32)));
	// fmuls f13,f11,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// vmulfp128 v12,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v10,v13,v12,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v10,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v0,v8,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v0,v8,v9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// stvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x821ba7a4
	if (!ctx.cr6.lt) goto loc_821BA7A4;
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x821ba7a4
	if (!ctx.cr6.lt) goto loc_821BA7A4;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fdivs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fsubs f8,f31,f9
	ctx.f8.f64 = double(float(ctx.f31.f64 - ctx.f9.f64));
	// stfs f8,152(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
loc_821BA7A4:
	// fcmpu cr6,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x821ba84c
	if (ctx.cr6.gt) goto loc_821BA84C;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821ba7c0
	if (ctx.cr6.eq) goto loc_821BA7C0;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x821ba7c4
	goto loc_821BA7C4;
loc_821BA7C0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821BA7C4:
	// lwz r9,132(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// li r8,208
	ctx.r8.s64 = 208;
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ba7e8
	if (ctx.cr6.eq) goto loc_821BA7E8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x821ba7ec
	goto loc_821BA7EC;
loc_821BA7E8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821BA7EC:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r8,r10,16768
	ctx.r8.s64 = ctx.r10.s64 + 16768;
	// li r27,1
	ctx.r27.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA814:
	// bl 0x82170cb0
	ctx.lr = 0x821BA818;
	sub_82170CB0(ctx, base);
	// lwz r3,860(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 860);
	// bl 0x821c8060
	ctx.lr = 0x821BA820;
	sub_821C8060(ctx, base);
	// bl 0x821cdac8
	ctx.lr = 0x821BA824;
	sub_821CDAC8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ba84c
	if (ctx.cr6.eq) goto loc_821BA84C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821BA83C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,96(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
loc_821BA844:
	// bgt cr6,0x821ba84c
	if (ctx.cr6.gt) goto loc_821BA84C;
	// li r27,1
	ctx.r27.s64 = 1;
loc_821BA84C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821DBB28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821dbbc0
	if (ctx.cr6.eq) goto loc_821DBBC0;
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821dbbc0
	if (ctx.cr6.eq) goto loc_821DBBC0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,100(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821DBB6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// cmpw cr6,r30,r9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x821dbbc0
	if (!ctx.cr6.eq) goto loc_821DBBC0;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821dbb98
	if (ctx.cr6.eq) goto loc_821DBB98;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821dbb98
	if (ctx.cr6.eq) goto loc_821DBB98;
	// lwz r30,104(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// b 0x821dbb9c
	goto loc_821DBB9C;
loc_821DBB98:
	// li r30,-1
	ctx.r30.s64 = -1;
loc_821DBB9C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821DBBB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpw cr6,r30,r9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x821dbbc4
	if (ctx.cr6.eq) goto loc_821DBBC4;
loc_821DBBC0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821DBBC4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821DEF64) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821DEFD0) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821df014
	if (!ctx.cr6.eq) goto loc_821DF014;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821df014
	if (!ctx.cr6.eq) goto loc_821DF014;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821df014
	if (!ctx.cr6.eq) goto loc_821DF014;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x821df018
	if (ctx.cr6.eq) goto loc_821DF018;
loc_821DF014:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821DF018:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821E0148) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v13,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821E2390) {
	REX_FUNC_PROLOGUE();
	// lwz r11,316(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// ori r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 2;
	// bne cr6,0x821e23a4
	if (!ctx.cr6.eq) goto loc_821E23A4;
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_821E23A4:
	// stw r10,316(r3)
	REX_STORE_U32(ctx.r3.u32 + 316, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821E2800) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x821E2808;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x822cd6f8
	ctx.lr = 0x821E2818;
	sub_822CD6F8(ctx, base);
	// cmpwi cr6,r3,13
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 13, ctx.xer);
	// bne cr6,0x821e2844
	if (!ctx.cr6.eq) goto loc_821E2844;
	// lwz r11,112(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 112);
	// rlwinm r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821e2844
	if (ctx.cr6.eq) goto loc_821E2844;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821e0a18
	ctx.lr = 0x821E283C;
	sub_821E0A18(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_821E2844:
	// li r11,76
	ctx.r11.s64 = 76;
	// lwz r6,472(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 472);
	// li r9,48
	ctx.r9.s64 = 48;
	// vspltisw v11,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r4,r31,64
	ctx.r4.s64 = ctx.r31.s64 + 64;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r8,16
	ctx.r8.s64 = 16;
	// lvlx v10,r30,r11
	temp.u32 = ctx.r30.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r31,320
	ctx.r10.s64 = ctx.r31.s64 + 320;
	// vspltw v12,v10,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v10.u32), 0xFF));
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r6,r9
	ea = (ctx.r6.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,288
	ctx.r5.s64 = 288;
	// lvx128 v8,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r31,304
	ctx.r6.s64 = ctx.r31.s64 + 304;
	// lvx128 v7,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,336
	ctx.r3.s64 = 336;
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v6,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw v5,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.u32), simde_mm_load_si128((simde__m128i*)ctx.v8.u32)));
	// lvx128 v9,r31,r5
	ea = (ctx.r31.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw v3,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.u32), simde_mm_load_si128((simde__m128i*)ctx.v8.u32)));
	// vmrghw v2,v4,v6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v6.u32), simde_mm_load_si128((simde__m128i*)ctx.v4.u32)));
	// addi r11,r31,256
	ctx.r11.s64 = ctx.r31.s64 + 256;
	// vmrglw v1,v4,v6
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v6.u32), simde_mm_load_si128((simde__m128i*)ctx.v4.u32)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
	// vmrghw v31,v5,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), simde_mm_load_si128((simde__m128i*)ctx.v5.u32)));
	// vmrglw v30,v5,v2
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), simde_mm_load_si128((simde__m128i*)ctx.v5.u32)));
	// vmrghw v29,v3,v1
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), simde_mm_load_si128((simde__m128i*)ctx.v3.u32)));
	// vmrglw v28,v3,v1
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), simde_mm_load_si128((simde__m128i*)ctx.v3.u32)));
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,480(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 480);
	// lvx128 v25,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v24,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw v22,v26,v27
	simde_mm_store_si128((simde__m128i*)ctx.v22.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v27.u32), simde_mm_load_si128((simde__m128i*)ctx.v26.u32)));
	// vmrghw v23,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v23.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), simde_mm_load_si128((simde__m128i*)ctx.v24.u32)));
	// vmrglw v21,v26,v27
	simde_mm_store_si128((simde__m128i*)ctx.v21.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v27.u32), simde_mm_load_si128((simde__m128i*)ctx.v26.u32)));
	// vmrglw v20,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v20.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), simde_mm_load_si128((simde__m128i*)ctx.v24.u32)));
	// vmrghw v19,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v19.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vmrglw v18,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v18.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), simde_mm_load_si128((simde__m128i*)ctx.v22.u32)));
	// vmrghw v17,v21,v20
	simde_mm_store_si128((simde__m128i*)ctx.v17.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v20.u32), simde_mm_load_si128((simde__m128i*)ctx.v21.u32)));
	// vmrglw v16,v21,v20
	simde_mm_store_si128((simde__m128i*)ctx.v16.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v20.u32), simde_mm_load_si128((simde__m128i*)ctx.v21.u32)));
	// vmsum4fp128 v15,v0,v19
	simde_mm_store_ps(ctx.v15.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v19.f32), 0xFF));
	// vmsum4fp128 v14,v0,v18
	simde_mm_store_ps(ctx.v14.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v18.f32), 0xFF));
	// vmsum4fp128 v63,v0,v17
	simde_mm_store_ps(ctx.v63.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v17.f32), 0xFF));
	// vmsum4fp128 v62,v0,v16
	simde_mm_store_ps(ctx.v62.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v16.f32), 0xFF));
	// vmrghw128 v61,v15,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v15.u32)));
	// vmrghw128 v60,v14,v62
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v14.u32)));
	// vmrghw128 v59,v61,v60
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vor128 v50,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_load_si128((simde__m128i*)ctx.v59.u8));
	// stvx128 v59,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,480(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 480);
	// lvx128 v55,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v57,v58
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), simde_mm_load_si128((simde__m128i*)ctx.v57.u32)));
	// vmrglw128 v54,v57,v58
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), simde_mm_load_si128((simde__m128i*)ctx.v57.u32)));
	// stvx128 v50,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v52,v53,v55
	simde_mm_store_si128((simde__m128i*)ctx.v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), simde_mm_load_si128((simde__m128i*)ctx.v53.u32)));
	// vmrglw128 v51,v53,v55
	simde_mm_store_si128((simde__m128i*)ctx.v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), simde_mm_load_si128((simde__m128i*)ctx.v53.u32)));
	// vmrghw128 v49,v56,v52
	simde_mm_store_si128((simde__m128i*)ctx.v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vmrglw128 v48,v56,v52
	simde_mm_store_si128((simde__m128i*)ctx.v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), simde_mm_load_si128((simde__m128i*)ctx.v56.u32)));
	// vmrghw128 v46,v54,v51
	simde_mm_store_si128((simde__m128i*)ctx.v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v51.u32), simde_mm_load_si128((simde__m128i*)ctx.v54.u32)));
	// vmrglw128 v45,v54,v51
	simde_mm_store_si128((simde__m128i*)ctx.v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v51.u32), simde_mm_load_si128((simde__m128i*)ctx.v54.u32)));
	// vmsum4fp128 v47,v9,v49
	simde_mm_store_ps(ctx.v47.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v49.f32), 0xFF));
	// vmsum4fp128 v44,v9,v48
	simde_mm_store_ps(ctx.v44.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v48.f32), 0xFF));
	// vmsum4fp128 v43,v9,v46
	simde_mm_store_ps(ctx.v43.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v46.f32), 0xFF));
	// vmsum4fp128 v42,v9,v45
	simde_mm_store_ps(ctx.v42.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v45.f32), 0xFF));
	// vmrghw128 v41,v47,v43
	simde_mm_store_si128((simde__m128i*)ctx.v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v43.u32), simde_mm_load_si128((simde__m128i*)ctx.v47.u32)));
	// vmrghw128 v40,v44,v42
	simde_mm_store_si128((simde__m128i*)ctx.v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v42.u32), simde_mm_load_si128((simde__m128i*)ctx.v44.u32)));
	// vmrghw128 v39,v41,v40
	simde_mm_store_si128((simde__m128i*)ctx.v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v40.u32), simde_mm_load_si128((simde__m128i*)ctx.v41.u32)));
	// vsubfp128 v38,v50,v39
	simde_mm_store_ps(ctx.v38.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v50.f32), simde_mm_load_ps(ctx.v39.f32)));
	// stvx128 v39,r31,r3
	ea = (ctx.r31.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v37,v38,v31
	simde_mm_store_ps(ctx.v37.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v31.f32), 0xFF));
	// vmsum4fp128 v36,v38,v30
	simde_mm_store_ps(ctx.v36.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v30.f32), 0xFF));
	// vmsum4fp128 v35,v38,v29
	simde_mm_store_ps(ctx.v35.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v29.f32), 0xFF));
	// vmsum4fp128 v34,v38,v28
	simde_mm_store_ps(ctx.v34.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v28.f32), 0xFF));
	// vmrghw128 v33,v37,v35
	simde_mm_store_si128((simde__m128i*)ctx.v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v35.u32), simde_mm_load_si128((simde__m128i*)ctx.v37.u32)));
	// vcfsx v10,v11,1
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v11.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltisw v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_set1_epi32(int(0x0)));
	// vmrghw128 v32,v36,v34
	simde_mm_store_si128((simde__m128i*)ctx.v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v34.u32), simde_mm_load_si128((simde__m128i*)ctx.v36.u32)));
	// vmrghw128 v0,v33,v32
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v32.u32), simde_mm_load_si128((simde__m128i*)ctx.v33.u32)));
	// vor v7,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v6,v7,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v7.f32), 0xEF));
	// vrsqrtefp v0,v6
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v6.f32))));
	// vmulfp128 v13,v6,v10
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vcmpeqfp v9,v6,v8
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v12,v0,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v10,v13,v12,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v10,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v0,v6,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v0,v6,v9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vspltw v5,v13,0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0xFF));
	// stvewx v5,r0,r5
	ea = (ctx.r5.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v5.u32[3 - ((ea & 0xF) >> 2)]);
	// lfs f0,3084(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3084);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x821e29f0
	if (!ctx.cr6.lt) goto loc_821E29F0;
	// stvx128 v8,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x821e2a44
	goto loc_821E2A44;
loc_821E29F0:
	// vrefp v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v13.f32)));
	// vupkd3d128 v11,v8,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v8.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v8.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v11 = vTemp;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// vspltw v6,v11,3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x0));
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// lvx128 v4,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v5,v13,v0,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v10,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vmaddfp v0,v0,v5,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v11,v13,v0,v6
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v0,v11,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v10,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v0,v7,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v13,v0,v8,v4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821E2A44:
	// addi r11,r30,48
	ctx.r11.s64 = ctx.r30.s64 + 48;
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stvx128 v0,r30,r8
	ea = (ctx.r30.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821FCBE0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FCBF8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x821fcc18
	if (ctx.cr6.lt) goto loc_821FCC18;
	// beq cr6,0x821fcc10
	if (ctx.cr6.eq) goto loc_821FCC10;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821FCC10:
	// li r3,100
	ctx.r3.s64 = 100;
	// blr 
	return;
loc_821FCC18:
	// li r3,84
	ctx.r3.s64 = 84;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FCE50) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x821fce68
	if (ctx.cr6.gt) goto loc_821FCE68;
loc_821FCE60:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821FCE68:
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// ble cr6,0x821fce60
	if (!ctx.cr6.gt) goto loc_821FCE60;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x821fce90
	if (ctx.cr6.lt) goto loc_821FCE90;
	// beq cr6,0x821fce88
	if (ctx.cr6.eq) goto loc_821FCE88;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x821fce94
	goto loc_821FCE94;
loc_821FCE88:
	// li r10,100
	ctx.r10.s64 = 100;
	// b 0x821fce94
	goto loc_821FCE94;
loc_821FCE90:
	// li r10,84
	ctx.r10.s64 = 84;
loc_821FCE94:
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
loc_821FCEB0:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821fcec4
	if (!ctx.cr6.eq) goto loc_821FCEC4;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x821fcec8
	goto loc_821FCEC8;
loc_821FCEC4:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_821FCEC8:
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// bdnz 0x821fceb0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821FCEB0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FE978) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x821fe9b4
	if (ctx.cr6.eq) goto loc_821FE9B4;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stw r6,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// stw r8,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// blr 
	return;
loc_821FE9B4:
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,-1
	ctx.r10.s64 = -1;
	// add r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 + ctx.r9.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,-1
	ctx.r3.s64 = -1;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82200728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82200730;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lfs f13,25292(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25292);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82200764
	if (!ctx.cr6.lt) goto loc_82200764;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82200764:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,24496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24496);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8220078c
	if (ctx.cr6.lt) goto loc_8220078C;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82200048
	ctx.lr = 0x82200784;
	sub_82200048(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_8220078C:
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8220082c
	if (!ctx.cr6.gt) goto loc_8220082C;
	// lwz r6,0(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r3,48
	ctx.r3.s64 = 48;
	// ld r11,32(r25)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r25.u32 + 32);
	// addi r10,r25,32
	ctx.r10.s64 = ctx.r25.s64 + 32;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// std r11,0(r6)
	REX_STORE_U64(ctx.r6.u32 + 0, ctx.r11.u64);
	// ld r8,40(r25)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r25.u32 + 40);
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r8,8(r6)
	REX_STORE_U64(ctx.r6.u32 + 8, ctx.r8.u64);
	// ble cr6,0x82200834
	if (!ctx.cr6.gt) goto loc_82200834;
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// addi r11,r25,56
	ctx.r11.s64 = ctx.r25.s64 + 56;
	// li r5,16
	ctx.r5.s64 = 16;
loc_822007D8:
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r30,-8(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// addi r31,r31,64
	ctx.r31.s64 = ctx.r31.s64 + 64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r8,r8,384
	ctx.r8.s64 = ctx.r8.s64 + 384;
	// addi r9,r10,16
	ctx.r9.s64 = ctx.r10.s64 + 16;
	// stw r30,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r30.u32);
	// lwz r30,-4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// stw r30,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r30.u32);
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r9,r5
	ea = (ctx.r9.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// stvx128 v12,r9,r3
	ea = (ctx.r9.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x822007d8
	if (ctx.cr6.lt) goto loc_822007D8;
	// b 0x82200834
	goto loc_82200834;
loc_8220082C:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r24,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
loc_82200834:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x822008ac
	if (!ctx.cr6.gt) goto loc_822008AC;
	// add r11,r31,r25
	ctx.r11.u64 = ctx.r31.u64 + ctx.r25.u64;
	// lwz r26,4(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// ld r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// std r10,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.r10.u64);
	// lwz r8,0(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ld r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// std r9,8(r26)
	REX_STORE_U64(ctx.r26.u32 + 8, ctx.r9.u64);
	// ble cr6,0x822008b4
	if (!ctx.cr6.gt) goto loc_822008B4;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// add r30,r31,r25
	ctx.r30.u64 = ctx.r31.u64 + ctx.r25.u64;
loc_82200874:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x826a1130
	ctx.lr = 0x8220088C;
	rexcrt_memcpy(ctx, base);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,64
	ctx.r31.s64 = ctx.r31.s64 + 64;
	// addi r30,r30,64
	ctx.r30.s64 = ctx.r30.s64 + 64;
	// addi r29,r29,64
	ctx.r29.s64 = ctx.r29.s64 + 64;
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82200874
	if (ctx.cr6.lt) goto loc_82200874;
	// b 0x822008b4
	goto loc_822008B4;
loc_822008AC:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// stw r24,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r24.u32);
loc_822008B4:
	// lwz r4,4(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82200934
	if (!ctx.cr6.gt) goto loc_82200934;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
loc_822008D0:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r10,32(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lwz r8,8(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8220091c
	if (!ctx.cr6.gt) goto loc_8220091C;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
loc_82200900:
	// lwzx r11,r31,r25
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r25.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// stwu r11,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r8.u32 = ea;
	// lwz r11,48(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 48);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82200900
	if (ctx.cr6.lt) goto loc_82200900;
loc_8220091C:
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r6,r6,64
	ctx.r6.s64 = ctx.r6.s64 + 64;
	// cmpw cr6,r7,r10
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x822008d0
	if (ctx.cr6.lt) goto loc_822008D0;
loc_82200934:
	// lwz r30,4(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// clrlwi r11,r5,30
	ctx.r11.u64 = ctx.r5.u32 & 0x3;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// subfic r10,r11,4
	ctx.xer.ca = ctx.r11.u32 <= 4;
	ctx.r10.u64 = static_cast<uint64_t>(4) - ctx.r11.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x82200a20
	if (!ctx.cr6.gt) goto loc_82200A20;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// lfs f12,25300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25300);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,25296(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 25296);
	ctx.f13.f64 = double(temp.f32);
loc_8220096C:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,36(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lwz r9,12(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// mullw r10,r10,r3
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// addi r5,r11,16
	ctx.r5.s64 = ctx.r11.s64 + 16;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// ble cr6,0x822009a0
	if (!ctx.cr6.gt) goto loc_822009A0;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x822009a0
	if (!ctx.cr6.lt) goto loc_822009A0;
	// stw r24,52(r5)
	REX_STORE_U32(ctx.r5.u32 + 52, ctx.r24.u32);
loc_822009A0:
	// lwz r9,52(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 52);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82200a0c
	if (ctx.cr6.eq) goto loc_82200A0C;
	// lwz r11,36(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// rlwinm r11,r11,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x822009c0
	if (!ctx.cr6.gt) goto loc_822009C0;
	// stw r11,52(r5)
	REX_STORE_U32(ctx.r5.u32 + 52, ctx.r11.u32);
loc_822009C0:
	// lwz r11,52(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 52);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82200a0c
	if (!ctx.cr6.gt) goto loc_82200A0C;
	// add r11,r4,r25
	ctx.r11.u64 = ctx.r4.u64 + ctx.r25.u64;
loc_822009D4:
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_822009E4:
	// lwzu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x822009e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822009E4;
	// lwz r9,52(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 52);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmplw cr6,r6,r9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x822009d4
	if (ctx.cr6.lt) goto loc_822009D4;
loc_82200A0C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,64
	ctx.r31.s64 = ctx.r31.s64 + 64;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8220096c
	if (ctx.cr6.lt) goto loc_8220096C;
loc_82200A20:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82218610) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822188C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// dcbt r0,r11
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822188F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// bgt cr6,0x82218948
	if (ctx.cr6.gt) goto loc_82218948;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82218948
	if (ctx.cr6.eq) goto loc_82218948;
	// bdz 0x82218920
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82218920;
	// bdnz 0x82218934
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82218934;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
loc_82218920:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r10,r11,8
	ctx.r10.u64 = ctx.r11.u64 | 8;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// b 0x82218988
	goto loc_82218988;
loc_82218934:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82218944;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82218988
	goto loc_82218988;
loc_82218948:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// clrlwi r9,r30,24
	ctx.r9.u64 = ctx.r30.u32 & 0xFF;
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r8,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// beq cr6,0x82218984
	if (ctx.cr6.eq) goto loc_82218984;
	// rlwinm r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82218984
	if (ctx.cr6.eq) goto loc_82218984;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82219788
	ctx.lr = 0x82218980;
	sub_82219788(ctx, base);
	// b 0x82218988
	goto loc_82218988;
loc_82218984:
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
loc_82218988:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8221EC70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,30772
	ctx.r9.s64 = ctx.r11.s64 + 30772;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8221eca4
	if (ctx.cr6.eq) goto loc_8221ECA4;
	// bl 0x82573808
	ctx.lr = 0x8221ECA0;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8221ECA4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82220250) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-84
	ctx.r3.s64 = ctx.r3.s64 + -84;
	// b 0x822202c8
	sub_822202C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82220558) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82220560;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r3,352
	ctx.r3.s64 = ctx.r3.s64 + 352;
	// addi r10,r11,31704
	ctx.r10.s64 = ctx.r11.s64 + 31704;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// bl 0x82415da8
	ctx.lr = 0x8222057C;
	sub_82415DA8(ctx, base);
	// addi r11,r29,344
	ctx.r11.s64 = ctx.r29.s64 + 344;
	// li r30,10
	ctx.r30.s64 = 10;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
loc_82220588:
	// addi r31,r31,-28
	ctx.r31.s64 = ctx.r31.s64 + -28;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823fe3a0
	ctx.lr = 0x82220594;
	sub_823FE3A0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82220588
	if (!ctx.cr0.lt) goto loc_82220588;
	// addi r3,r29,12
	ctx.r3.s64 = ctx.r29.s64 + 12;
	// bl 0x823fe3a0
	ctx.lr = 0x822205A4;
	sub_823FE3A0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r10,r11,15728
	ctx.r10.s64 = ctx.r11.s64 + 15728;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// bl 0x823f94c0
	ctx.lr = 0x822205B8;
	sub_823F94C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822219E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32125
	ctx.r11.s64 = -2105344000;
	// stw r3,-25044(r11)
	REX_STORE_U32(ctx.r11.u32 + -25044, ctx.r3.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82221A50) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82221A88) {
	REX_FUNC_PROLOGUE();
	// lbz r11,189(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 189);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82221a9c
	if (!ctx.cr6.eq) goto loc_82221A9C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,189(r3)
	REX_STORE_U8(ctx.r3.u32 + 189, ctx.r11.u8);
loc_82221A9C:
	// lbz r11,189(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 189);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82221ae0
	if (ctx.cr6.eq) goto loc_82221AE0;
	// lbz r11,190(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 190);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82221ae0
	if (ctx.cr6.eq) goto loc_82221AE0;
	// lis r11,-32125
	ctx.r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,-29600(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -29600);
	// lwz r10,30012(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 30012);
	// lwz r9,30008(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30008);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// lwz r7,100(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// andc r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 & ~ctx.r8.u64;
	// stw r6,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r6.u32);
	// blr 
	return;
loc_82221AE0:
	// lis r11,-32125
	ctx.r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,-29600(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -29600);
	// lwz r10,30012(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 30012);
	// lwz r9,30008(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30008);
	// lwz r8,100(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r6,100(r11)
	REX_STORE_U32(ctx.r11.u32 + 100, ctx.r6.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82224B00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32222
	ctx.r10.s64 = -2111700992;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,18832
	ctx.r9.s64 = ctx.r10.s64 + 18832;
	// addi r3,r3,96
	ctx.r3.s64 = ctx.r3.s64 + 96;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82341280
	ctx.lr = 0x82224B38;
	sub_82341280(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82225F78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8223fb58
	ctx.lr = 0x82225F90;
	sub_8223FB58(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,-32252
	ctx.r9.s64 = ctx.r11.s64 + -32252;
	// addi r8,r10,-32260
	ctx.r8.s64 = ctx.r10.s64 + -32260;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r8.u32);
	// bl 0x8223f7c0
	ctx.lr = 0x82225FB0;
	sub_8223F7C0(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// addi r5,r7,-25252
	ctx.r5.s64 = ctx.r7.s64 + -25252;
	// addi r4,r6,-25260
	ctx.r4.s64 = ctx.r6.s64 + -25260;
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r4.u32);
	// bl 0x823a9738
	ctx.lr = 0x82225FD0;
	sub_823A9738(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82227920) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82227928;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r31,r11,23664
	ctx.r31.s64 = ctx.r11.s64 + 23664;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8222795c
	if (ctx.cr6.eq) goto loc_8222795C;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82227960
	if (ctx.cr6.eq) goto loc_82227960;
loc_8222795C:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_82227960:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82227984
	if (ctx.cr6.eq) goto loc_82227984;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82227988
	if (!ctx.cr6.eq) goto loc_82227988;
loc_82227984:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82227988:
	// lwz r3,856(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 856);
	// bl 0x82228d60
	ctx.lr = 0x82227990;
	sub_82228D60(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82227a28
	if (ctx.cr6.eq) goto loc_82227A28;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822279b8
	if (ctx.cr6.eq) goto loc_822279B8;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822279bc
	if (ctx.cr6.eq) goto loc_822279BC;
loc_822279B8:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_822279BC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822279dc
	if (ctx.cr6.eq) goto loc_822279DC;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x822279e0
	if (!ctx.cr6.eq) goto loc_822279E0;
loc_822279DC:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_822279E0:
	// lwz r11,892(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 892);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82227a00
	if (ctx.cr6.eq) goto loc_82227A00;
	// bl 0x82170cb0
	ctx.lr = 0x822279F0;
	sub_82170CB0(ctx, base);
	// lwz r3,892(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 892);
	// bl 0x82353830
	ctx.lr = 0x822279F8;
	sub_82353830(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82227a28
	if (ctx.cr6.eq) goto loc_82227A28;
loc_82227A00:
	// lis r11,-32107
	ctx.r11.s64 = -2104164352;
	// lwz r3,-24248(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -24248);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82227a28
	if (ctx.cr6.eq) goto loc_82227A28;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82227A20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82227a34
	if (!ctx.cr6.eq) goto loc_82227A34;
loc_82227A28:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_82227A34:
	// bl 0x822ed0d8
	ctx.lr = 0x82227A38;
	sub_822ED0D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82227a4c
	if (ctx.cr6.eq) goto loc_82227A4C;
	// bl 0x822ed0d8
	ctx.lr = 0x82227A44;
	sub_822ED0D8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_82227A4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82226798
	ctx.lr = 0x82227A54;
	sub_82226798(ctx, base);
	// lis r11,-32219
	ctx.r11.s64 = -2111504384;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r9,r11,20616
	ctx.r9.s64 = ctx.r11.s64 + 20616;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r6,r10,-16825
	ctx.r6.s64 = ctx.r10.s64 + -16825;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r3,r28,96
	ctx.r3.s64 = ctx.r28.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x82227A84;
	sub_822518D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82231698) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,200(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// addi r31,r3,184
	ctx.r31.s64 = ctx.r3.s64 + 184;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822316cc
	if (ctx.cr6.eq) goto loc_822316CC;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822316d0
	if (ctx.cr6.eq) goto loc_822316D0;
loc_822316CC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822316D0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822316f4
	if (ctx.cr6.eq) goto loc_822316F4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x822316f8
	if (!ctx.cr6.eq) goto loc_822316F8;
loc_822316F4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822316F8:
	// lwz r11,1892(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1892);
	// cmpwi cr6,r11,83
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 83, ctx.xer);
	// beq cr6,0x8223171c
	if (ctx.cr6.eq) goto loc_8223171C;
loc_82231704:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8223171C:
	// bl 0x82230a58
	ctx.lr = 0x82231720;
	sub_82230A58(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82231704
	if (ctx.cr6.eq) goto loc_82231704;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243fa70
	ctx.lr = 0x82231730;
	sub_8243FA70(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,1936(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 1936);
	// srawi r9,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 31;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// subfc r7,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r7.u64 = ctx.r11.u64 - ctx.r10.u64;
	// adde r3,r8,r9
	temp.u8 = (ctx.r8.u32 + ctx.r9.u32 < ctx.r8.u32) | (ctx.r8.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82237288) {
	REX_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r3
	ctx.r10.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r11,152(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822372b8
	if (ctx.cr6.eq) goto loc_822372B8;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,156(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq cr6,0x822372bc
	if (ctx.cr6.eq) goto loc_822372BC;
loc_822372B8:
	// li r9,0
	ctx.r9.s64 = 0;
loc_822372BC:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r9,30048(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30048);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,152(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82237308
	if (ctx.cr6.eq) goto loc_82237308;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,156(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 156);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8223730c
	if (ctx.cr6.eq) goto loc_8223730C;
loc_82237308:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8223730C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82237328
	if (ctx.cr6.eq) goto loc_82237328;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8223732c
	if (!ctx.cr6.eq) goto loc_8223732C;
loc_82237328:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8223732C:
	// b 0x8220f5e8
	sub_8220F5E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8223B450) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8223b3e8
	ctx.lr = 0x8223B468;
	sub_8223B3E8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8223B7C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,4(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// stw r9,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// stw r8,8(r4)
	REX_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8223E1C0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32117
	ctx.r11.s64 = -2104819712;
	// lwz r11,14864(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 14864);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8223e1dc
	if (ctx.cr6.eq) goto loc_8223E1DC;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x8223d128
	sub_8223D128(ctx, base);
	return;
loc_8223E1DC:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x824b2a38
	sub_824B2A38(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8223F3E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8223F3E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,102
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 102, ctx.xer);
	// bne cr6,0x8223f40c
	if (!ctx.cr6.eq) goto loc_8223F40C;
	// bl 0x8223edd0
	ctx.lr = 0x8223F404;
	sub_8223EDD0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_8223F40C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822f39f8
	ctx.lr = 0x8223F414;
	sub_822F39F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8223f340
	ctx.lr = 0x8223F428;
	sub_8223F340(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822407F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,88
	ctx.r3.s64 = ctx.r3.s64 + 88;
	// bl 0x82475350
	ctx.lr = 0x82240814;
	sub_82475350(ctx, base);
	// lwz r3,124(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82242768) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82242770;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// addi r9,r11,-12664
	ctx.r9.s64 = ctx.r11.s64 + -12664;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r31,r10,23664
	ctx.r31.s64 = ctx.r10.s64 + 23664;
	// lwz r11,-12664(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12664);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r29,640(r11)
	REX_STORE_U32(ctx.r11.u32 + 640, ctx.r29.u32);
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// stw r29,640(r11)
	REX_STORE_U32(ctx.r11.u32 + 640, ctx.r29.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822427bc
	if (ctx.cr6.eq) goto loc_822427BC;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822427c0
	if (ctx.cr6.eq) goto loc_822427C0;
loc_822427BC:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_822427C0:
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r9,30048(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// beq cr6,0x822427e4
	if (ctx.cr6.eq) goto loc_822427E4;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x822427e8
	if (!ctx.cr6.eq) goto loc_822427E8;
loc_822427E4:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_822427E8:
	// lwz r11,856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 856);
	// lwz r10,428(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 428);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8224280c
	if (ctx.cr6.eq) goto loc_8224280C;
	// lwz r7,432(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 432);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x82242810
	if (ctx.cr6.eq) goto loc_82242810;
loc_8224280C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82242810:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224282c
	if (ctx.cr6.eq) goto loc_8224282C;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82242830
	if (!ctx.cr6.eq) goto loc_82242830;
loc_8224282C:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_82242830:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82230a58
	ctx.lr = 0x82242838;
	sub_82230A58(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82242988
	if (ctx.cr6.eq) goto loc_82242988;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82242860
	if (ctx.cr6.eq) goto loc_82242860;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82242864
	if (ctx.cr6.eq) goto loc_82242864;
loc_82242860:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_82242864:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,30048(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82242884
	if (ctx.cr6.eq) goto loc_82242884;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82242888
	if (!ctx.cr6.eq) goto loc_82242888;
loc_82242884:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82242888:
	// lwz r11,856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 856);
	// lwz r10,452(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 452);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822428ac
	if (ctx.cr6.eq) goto loc_822428AC;
	// lwz r7,456(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 456);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x822428b0
	if (ctx.cr6.eq) goto loc_822428B0;
loc_822428AC:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_822428B0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822428cc
	if (ctx.cr6.eq) goto loc_822428CC;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x822428d0
	if (!ctx.cr6.eq) goto loc_822428D0;
loc_822428CC:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_822428D0:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82230a58
	ctx.lr = 0x822428D8;
	sub_82230A58(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82242988
	if (ctx.cr6.eq) goto loc_82242988;
	// bl 0x8238e4f8
	ctx.lr = 0x822428E4;
	sub_8238E4F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8224294c
	if (ctx.cr6.eq) goto loc_8224294C;
	// bl 0x82170cb0
	ctx.lr = 0x822428F0;
	sub_82170CB0(ctx, base);
	// lwz r11,856(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 856);
	// addi r3,r11,460
	ctx.r3.s64 = ctx.r11.s64 + 460;
	// bl 0x8243fa70
	ctx.lr = 0x822428FC;
	sub_8243FA70(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,21888
	ctx.r30.s64 = ctx.r11.s64 + 21888;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8222a880
	ctx.lr = 0x82242910;
	sub_8222A880(ctx, base);
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,101
	ctx.r4.s64 = 101;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82231158
	ctx.lr = 0x82242940;
	sub_82231158(ctx, base);
	// lwz r7,152(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// stw r29,640(r7)
	REX_STORE_U32(ctx.r7.u32 + 640, ctx.r29.u32);
	// stw r31,3120(r30)
	REX_STORE_U32(ctx.r30.u32 + 3120, ctx.r31.u32);
loc_8224294C:
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// stw r29,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// addi r9,r11,536
	ctx.r9.s64 = ctx.r11.s64 + 536;
	// stw r29,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// addi r6,r10,-15624
	ctx.r6.s64 = ctx.r10.s64 + -15624;
	// ld r5,104(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// addi r3,r28,96
	ctx.r3.s64 = ctx.r28.s64 + 96;
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// ld r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x822518d8
	ctx.lr = 0x8224297C;
	sub_822518D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_82242988:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8224E6E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0284
	ctx.lr = 0x8224E6F0;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// addi r10,r11,7568
	ctx.r10.s64 = ctx.r11.s64 + 7568;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// bl 0x8223b838
	ctx.lr = 0x8224E72C;
	sub_8223B838(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r4,20(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r6,r9,5796
	ctx.r6.s64 = ctx.r9.s64 + 5796;
	// addi r5,r8,12400
	ctx.r5.s64 = ctx.r8.s64 + 12400;
	// stw r31,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// addi r11,r7,12392
	ctx.r11.s64 = ctx.r7.s64 + 12392;
	// stw r6,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r5,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// addi r3,r1,132
	ctx.r3.s64 = ctx.r1.s64 + 132;
	// stw r11,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// stw r31,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r31.u32);
	// stw r31,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// stw r31,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// stw r31,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r31.u32);
	// bl 0x8226bf28
	ctx.lr = 0x8224E774;
	sub_8226BF28(ctx, base);
	// lwz r5,324(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// stw r23,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r23.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r5,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8224dc58
	ctx.lr = 0x8224E7AC;
	sub_8224DC58(ctx, base);
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// bl 0x82218850
	ctx.lr = 0x8224E7B4;
	sub_82218850(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8223cdb0
	ctx.lr = 0x8224E7BC;
	sub_8223CDB0(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82253850) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82253894
	if (!ctx.cr6.eq) goto loc_82253894;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82253894
	if (!ctx.cr6.eq) goto loc_82253894;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82253894
	if (!ctx.cr6.eq) goto loc_82253894;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82253898
	if (ctx.cr6.eq) goto loc_82253898;
loc_82253894:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82253898:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82254B88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82254B90;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,120
	ctx.r30.s64 = ctx.r3.s64 + 120;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82282b18
	ctx.lr = 0x82254BA4;
	sub_82282B18(ctx, base);
	// ld r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 120);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bl 0x82282b68
	ctx.lr = 0x82254BBC;
	sub_82282B68(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824b5d38
	ctx.lr = 0x82254BC4;
	sub_824B5D38(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lhz r11,140(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 140);
	// li r29,-1
	ctx.r29.s64 = -1;
	// addi r30,r10,-12796
	ctx.r30.s64 = ctx.r10.s64 + -12796;
	// lhz r9,136(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 136);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lhz r8,134(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 134);
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r6,r30,20
	ctx.r6.s64 = ctx.r30.s64 + 20;
	// addi r3,r31,128
	ctx.r3.s64 = ctx.r31.s64 + 128;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lhz r27,130(r1)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r1.u32 + 130);
	// lhz r10,138(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 138);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// bl 0x826a2720
	ctx.lr = 0x82254C00;
	sub_826A2720(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82282b18
	ctx.lr = 0x82254C08;
	sub_82282B18(ctx, base);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// bl 0x82282b68
	ctx.lr = 0x82254C20;
	sub_82282B68(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824b5d38
	ctx.lr = 0x82254C28;
	sub_824B5D38(ctx, base);
	// lhz r11,140(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 140);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lhz r10,138(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 138);
	// addi r6,r30,-28
	ctx.r6.s64 = ctx.r30.s64 + -28;
	// lhz r9,136(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 136);
	// li r4,64
	ctx.r4.s64 = 64;
	// lhz r8,134(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 134);
	// addi r3,r31,192
	ctx.r3.s64 = ctx.r31.s64 + 192;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lhz r27,130(r1)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r1.u32 + 130);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// bl 0x826a2720
	ctx.lr = 0x82254C58;
	sub_826A2720(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lhz r9,134(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 134);
	// li r4,64
	ctx.r4.s64 = 64;
	// lhz r8,130(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 130);
	// addi r3,r31,256
	ctx.r3.s64 = ctx.r31.s64 + 256;
	// lhz r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r1.u32 + 128);
	// bl 0x826a2720
	ctx.lr = 0x82254C78;
	sub_826A2720(ctx, base);
	// lis r6,-32219
	ctx.r6.s64 = -2111504384;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r6,19328
	ctx.r5.s64 = ctx.r6.s64 + 19328;
	// addi r6,r30,-89
	ctx.r6.s64 = ctx.r30.s64 + -89;
	// stw r11,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r5,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// stw r11,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// ld r4,128(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// ld r5,136(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// bl 0x822518d8
	ctx.lr = 0x82254CA8;
	sub_822518D8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r4,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r4.u32);
	// bl 0x826a2890
	ctx.lr = 0x82254CB8;
	sub_826A2890(ctx, base);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x826a0d78
	ctx.lr = 0x82254CC0;
	sub_826A0D78(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8225BA08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x826a0d18
	ctx.lr = 0x8225BA20;
	__savefpr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82513bb8
	ctx.lr = 0x8225BA30;
	sub_82513BB8(ctx, base);
	// bl 0x82513308
	ctx.lr = 0x8225BA34;
	sub_82513308(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f31,4280(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4280);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,4268(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4268);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfs f29,4272(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4272);
	ctx.f29.f64 = double(temp.f32);
	// fsel f12,f0,f30,f29
	ctx.f12.f64 = ctx.f0.f64 >= 0.0 ? ctx.f30.f64 : ctx.f29.f64;
	// lfs f28,4260(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4260);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f11,f13,f28,f12
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f28.f64, ctx.f12.f64)));
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825135b0
	ctx.lr = 0x8225BA74;
	sub_825135B0(ctx, base);
	// lfs f9,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// fsel f7,f9,f30,f29
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f30.f64 : ctx.f29.f64;
	// fmadds f6,f8,f28,f7
	ctx.f6.f64 = double(float(std::fma(ctx.f8.f64, ctx.f28.f64, ctx.f7.f64)));
	// fctiwz f5,f6
	ctx.f5.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82513530
	ctx.lr = 0x8225BA94;
	sub_82513530(ctx, base);
	// lfs f4,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f31.f64));
	// fsel f2,f4,f30,f29
	ctx.f2.f64 = ctx.f4.f64 >= 0.0 ? ctx.f30.f64 : ctx.f29.f64;
	// fmadds f1,f3,f28,f2
	ctx.f1.f64 = double(float(std::fma(ctx.f3.f64, ctx.f28.f64, ctx.f2.f64)));
	// fctiwz f0,f1
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825134b0
	ctx.lr = 0x8225BAB4;
	sub_825134B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82513bc0
	ctx.lr = 0x8225BABC;
	sub_82513BC0(ctx, base);
	// bl 0x82524b40
	ctx.lr = 0x8225BAC0;
	sub_82524B40(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x826a0d64
	ctx.lr = 0x8225BACC;
	__restfpr_28(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822618B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x822618C0;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x822d1688
	ctx.lr = 0x822618D4;
	sub_822D1688(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82261900
	if (ctx.cr6.eq) goto loc_82261900;
	// cmpwi cr6,r28,21
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 21, ctx.xer);
	// bne cr6,0x82261900
	if (!ctx.cr6.eq) goto loc_82261900;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,21
	ctx.r3.s64 = 21;
	// bl 0x82260e60
	ctx.lr = 0x822618F8;
	sub_82260E60(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82261900:
	// bl 0x82260bc8
	ctx.lr = 0x82261904;
	sub_82260BC8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82261cc0
	ctx.lr = 0x82261910;
	sub_82261CC0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82261d30
	ctx.lr = 0x82261920;
	sub_82261D30(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f12,8(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,2884(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lfs f11,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f9,88(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x82261994
	if (ctx.cr6.eq) goto loc_82261994;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,108(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82261998
	if (ctx.cr6.eq) goto loc_82261998;
loc_82261994:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82261998:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82261adc
	if (ctx.cr6.eq) goto loc_82261ADC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 30048);
	// and r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82261adc
	if (ctx.cr6.eq) goto loc_82261ADC;
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82261adc
	if (ctx.cr6.eq) goto loc_82261ADC;
	// lwz r11,24772(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24772);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82261adc
	if (ctx.cr6.eq) goto loc_82261ADC;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82261adc
	if (!ctx.cr6.eq) goto loc_82261ADC;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// blt cr6,0x82261adc
	if (ctx.cr6.lt) goto loc_82261ADC;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82261a7c
	if (ctx.cr6.lt) goto loc_82261A7C;
	// beq cr6,0x82261a38
	if (ctx.cr6.eq) goto loc_82261A38;
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// bne cr6,0x82261adc
	if (!ctx.cr6.eq) goto loc_82261ADC;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,116
	ctx.r8.s64 = ctx.r1.s64 + 116;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v13,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xFF));
	// vspltw v12,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xAA));
	// vspltw v11,v0,2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x55));
	// stvewx v13,r0,r10
	ea = (ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v13.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v12,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v12.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v11,r0,r7
	ea = (ctx.r7.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v11.u32[3 - ((ea & 0xF) >> 2)]);
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// b 0x82261abc
	goto loc_82261ABC;
loc_82261A38:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r6,r1,132
	ctx.r6.s64 = ctx.r1.s64 + 132;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// vspltw v13,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xFF));
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// vspltw v12,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xAA));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vspltw v11,v0,2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x55));
	// stvewx v13,r0,r10
	ea = (ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v13.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v12,r0,r9
	ea = (ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v12.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v11,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v11.u32[3 - ((ea & 0xF) >> 2)]);
	// bl 0x82270130
	ctx.lr = 0x82261A78;
	sub_82270130(ctx, base);
	// b 0x82261abc
	goto loc_82261ABC;
loc_82261A7C:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r6,r1,132
	ctx.r6.s64 = ctx.r1.s64 + 132;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// vspltw v13,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xFF));
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// vspltw v12,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0xAA));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vspltw v11,v0,2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x55));
	// stvewx v13,r0,r10
	ea = (ctx.r10.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v13.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v12,r0,r9
	ea = (ctx.r9.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v12.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v11,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v11.u32[3 - ((ea & 0xF) >> 2)]);
	// bl 0x822700b0
	ctx.lr = 0x82261ABC;
	sub_822700B0(ctx, base);
loc_82261ABC:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82276bb0
	ctx.lr = 0x82261ADC;
	sub_82276BB0(ctx, base);
loc_82261ADC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82271118) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82271078
	ctx.lr = 0x82271128;
	sub_82271078(ctx, base);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82271BF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82271C00;
	__savegprlr_27(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x82271358
	ctx.lr = 0x82271C0C;
	sub_82271358(ctx, base);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82271c3c
	if (ctx.cr6.eq) goto loc_82271C3C;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82271c40
	if (ctx.cr6.eq) goto loc_82271C40;
loc_82271C3C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82271C40:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lis r27,-32256
	ctx.r27.s64 = -2113929216;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82271c64
	if (ctx.cr6.eq) goto loc_82271C64;
	// lwz r9,60(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r11,30048(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82271c68
	if (!ctx.cr6.eq) goto loc_82271C68;
loc_82271C64:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82271C68:
	// lwz r3,864(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 864);
	// bl 0x82268cf8
	ctx.lr = 0x82271C70;
	sub_82268CF8(ctx, base);
	// stw r30,152(r28)
	REX_STORE_U32(ctx.r28.u32 + 152, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82271880
	ctx.lr = 0x82271C7C;
	sub_82271880(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82270f90
	ctx.lr = 0x82271C84;
	sub_82270F90(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82271c98
	if (!ctx.cr6.eq) goto loc_82271C98;
loc_82271C8C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82271C98:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// add. r9,r11,r3
	ctx.r9.u64 = ctx.r11.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82271c8c
	if (ctx.cr0.eq) goto loc_82271C8C;
	// lwz r11,40(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82271eb8
	if (ctx.cr6.eq) goto loc_82271EB8;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r10,r28,80
	ctx.r10.s64 = ctx.r28.s64 + 80;
	// lfs f13,13920(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 13920);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,2884(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
loc_82271CC8:
	// lwz r4,40(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// addi r8,r11,-2
	ctx.r8.s64 = ctx.r11.s64 + -2;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// extsw r5,r8
	ctx.r5.s64 = ctx.r8.s32;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// std r8,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// frsp f4,f9
	ctx.f4.f64 = double(float(ctx.f9.f64));
	// lfd f6,104(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r3,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f8,96(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f8
	ctx.f9.f64 = double(ctx.f8.s64);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r6,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f5,112(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r4,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r4.u64);
	// lfd f3,120(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// addi r5,r11,3
	ctx.r5.s64 = ctx.r11.s64 + 3;
	// fsubs f2,f7,f4
	ctx.f2.f64 = double(float(ctx.f7.f64 - ctx.f4.f64));
	// frsp f4,f9
	ctx.f4.f64 = double(float(ctx.f9.f64));
	// fcfid f7,f6
	ctx.f7.f64 = double(ctx.f6.s64);
	// fsubs f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f0.f64));
	// fmuls f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lwz r8,40(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// std r8,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// lfd f11,128(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fcfid f6,f5
	ctx.f6.f64 = double(ctx.f5.s64);
	// fcfid f5,f3
	ctx.f5.f64 = double(ctx.f3.s64);
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// fsubs f12,f8,f4
	ctx.f12.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f10,8(r10)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r6,40(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// std r6,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r6.u64);
	// lfd f9,136(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fsubs f6,f7,f3
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f3.f64));
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f0.f64));
	// fmuls f4,f5,f13
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// stfs f4,12(r10)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lwz r4,40(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// std r4,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r4.u64);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// lfd f3,144(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f12,f3
	ctx.f12.f64 = double(ctx.f3.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f11,f2
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f2.f64));
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f8,16(r10)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lwz r8,40(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// std r8,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r8.u64);
	// lfd f7,152(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fsubs f4,f5,f1
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f1.f64));
	// fsubs f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f0.f64));
	// fmuls f2,f3,f13
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// stfs f2,20(r10)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// lwz r6,40(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// std r6,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r6.u64);
	// lfd f1,160(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f12,f1
	ctx.f12.f64 = double(ctx.f1.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// std r4,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r4.u64);
	// lfd f10,168(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// std r8,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r8.u64);
	// lfd f4,184(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + 184);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// std r6,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r6.u64);
	// lfd f7,176(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// addi r5,r11,-2
	ctx.r5.s64 = ctx.r11.s64 + -2;
	// cmpwi cr6,r5,16
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 16, ctx.xer);
	// fsubs f6,f11,f8
	ctx.f6.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f0.f64));
	// fmuls f2,f5,f13
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// stfs f2,24(r10)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lwz r3,40(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// std r3,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r3.u64);
	// lfd f1,192(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// fcfid f12,f1
	ctx.f12.f64 = double(ctx.f1.s64);
	// fcfid f9,f7
	ctx.f9.f64 = double(ctx.f7.s64);
	// frsp f11,f3
	ctx.f11.f64 = double(float(ctx.f3.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fsubs f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsubs f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f0.f64));
	// fmuls f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// stfs f5,28(r10)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// lwz r7,40(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// std r7,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r7.u64);
	// lfd f4,200(r1)
	ctx.f4.u64 = REX_LOAD_U64(ctx.r1.u32 + 200);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fsubs f1,f2,f7
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f7.f64));
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfsu f11,32(r10)
	ea = 32 + ctx.r10.u32;
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// blt cr6,0x82271cc8
	if (ctx.cr6.lt) goto loc_82271CC8;
	// b 0x82271edc
	goto loc_82271EDC;
loc_82271EB8:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// addi r29,r28,80
	ctx.r29.s64 = ctx.r28.s64 + 80;
loc_82271EC0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82271808
	ctx.lr = 0x82271ECC;
	sub_82271808(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stfsu f1,4(r29)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r29.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r29.u32 = ea;
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// blt cr6,0x82271ec0
	if (ctx.cr6.lt) goto loc_82271EC0;
loc_82271EDC:
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// stw r30,148(r28)
	REX_STORE_U32(ctx.r28.u32 + 148, ctx.r30.u32);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_82271EE8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82271078
	ctx.lr = 0x82271EF4;
	sub_82271078(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82271f4c
	if (ctx.cr6.eq) goto loc_82271F4C;
	// lwz r9,32(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x82271c8c
	if (!ctx.cr6.gt) goto loc_82271C8C;
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// lwzx r11,r11,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// ble cr6,0x82271f4c
	if (!ctx.cr6.gt) goto loc_82271F4C;
loc_82271F20:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r8,40(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwinm r7,r8,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82271f48
	if (!ctx.cr6.eq) goto loc_82271F48;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82271f20
	if (ctx.cr6.lt) goto loc_82271F20;
	// b 0x82271f4c
	goto loc_82271F4C;
loc_82271F48:
	// li r29,1
	ctx.r29.s64 = 1;
loc_82271F4C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// ble cr6,0x82271ee8
	if (!ctx.cr6.gt) goto loc_82271EE8;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82271ff0
	if (ctx.cr6.eq) goto loc_82271FF0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82219630
	ctx.lr = 0x82271F7C;
	sub_82219630(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82271f9c
	if (ctx.cr6.eq) goto loc_82271F9C;
	// bl 0x82218220
	ctx.lr = 0x82271F8C;
	sub_82218220(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// addi r10,r11,-8732
	ctx.r10.s64 = ctx.r11.s64 + -8732;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_82271F9C:
	// addi r31,r28,156
	ctx.r31.s64 = ctx.r28.s64 + 156;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822187e8
	ctx.lr = 0x82271FA8;
	sub_822187E8(ctx, base);
	// lwz r11,156(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 156);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82271FBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82271ff0
	if (ctx.cr6.eq) goto loc_82271FF0;
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// lwz r11,30048(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82271ff0
	if (ctx.cr6.eq) goto loc_82271FF0;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x822187a0
	ctx.lr = 0x82271FF0;
	sub_822187A0(ctx, base);
loc_82271FF0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8228A6E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,4264(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4264);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4256(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4256);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// ble cr6,0x8228a704
	if (!ctx.cr6.gt) goto loc_8228A704;
	// fsubs f0,f1,f12
	ctx.f0.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// b 0x8228a718
	goto loc_8228A718;
loc_8228A704:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,7656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7656);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x8228a718
	if (!ctx.cr6.lt) goto loc_8228A718;
	// fadds f0,f1,f12
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
loc_8228A718:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8228a72c
	if (!ctx.cr6.lt) goto loc_8228A72C;
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
loc_8228A72C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,21088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21088);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctidz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lhz r3,-10(r1)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r1.u32 + -10);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82292190) {
	REX_FUNC_PROLOGUE();
	// addi r5,r3,1972
	ctx.r5.s64 = ctx.r3.s64 + 1972;
	// addi r4,r3,1984
	ctx.r4.s64 = ctx.r3.s64 + 1984;
	// addi r3,r3,2744
	ctx.r3.s64 = ctx.r3.s64 + 2744;
	// b 0x82515460
	sub_82515460(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822922E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x822922E8;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x826a0d14
	ctx.lr = 0x822922F0;
	__savefpr_27(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r24,r3,268
	ctx.r24.s64 = ctx.r3.s64 + 268;
	// addi r25,r3,168
	ctx.r25.s64 = ctx.r3.s64 + 168;
	// addi r17,r3,744
	ctx.r17.s64 = ctx.r3.s64 + 744;
	// addi r20,r3,1652
	ctx.r20.s64 = ctx.r3.s64 + 1652;
	// bl 0x82170670
	ctx.lr = 0x8229230C;
	sub_82170670(ctx, base);
	// lwz r11,908(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 908);
	// addi r27,r3,48
	ctx.r27.s64 = ctx.r3.s64 + 48;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// rlwinm r10,r11,0,20,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// rlwinm r10,r10,0,16,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFCFFFF;
	// stw r10,908(r28)
	REX_STORE_U32(ctx.r28.u32 + 908, ctx.r10.u32);
	// lhz r9,174(r28)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r28.u32 + 174);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// stw r8,1904(r28)
	REX_STORE_U32(ctx.r28.u32 + 1904, ctx.r8.u32);
	// bl 0x822d4778
	ctx.lr = 0x82292334;
	sub_822D4778(ctx, base);
	// lbz r11,578(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 578);
	// lis r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ori r26,r7,32768
	ctx.r26.u64 = ctx.r7.u64 | 32768;
	// lwz r16,144(r28)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r28.u32 + 144);
	// bne cr6,0x8229235c
	if (!ctx.cr6.eq) goto loc_8229235C;
	// lhz r10,174(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 174);
	// subf r9,r26,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r26.u64;
	// sth r9,176(r28)
	REX_STORE_U16(ctx.r28.u32 + 176, ctx.r9.u16);
	// b 0x8229237c
	goto loc_8229237C;
loc_8229235C:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82292374
	if (!ctx.cr6.eq) goto loc_82292374;
	// lfs f1,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82291a10
	ctx.lr = 0x8229236C;
	sub_82291A10(ctx, base);
	// sth r3,176(r28)
	REX_STORE_U16(ctx.r28.u32 + 176, ctx.r3.u16);
	// b 0x8229237c
	goto loc_8229237C;
loc_82292374:
	// lhz r11,174(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 174);
	// sth r11,176(r28)
	REX_STORE_U16(ctx.r28.u32 + 176, ctx.r11.u16);
loc_8229237C:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x82292394
	if (ctx.cr6.eq) goto loc_82292394;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822a4ae0
	ctx.lr = 0x82292394;
	sub_822A4AE0(ctx, base);
loc_82292394:
	// lhz r11,6(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsh r7,r11
	ctx.r7.s64 = ctx.r11.s16;
	// std r7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,12900(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12900);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f13,4264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4264);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// ble cr6,0x822923d8
	if (!ctx.cr6.gt) goto loc_822923D8;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,4256(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4256);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// b 0x822923f4
	goto loc_822923F4;
loc_822923D8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,7656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7656);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x822923f4
	if (!ctx.cr6.lt) goto loc_822923F4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,4256(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4256);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
loc_822923F4:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82179900
	ctx.lr = 0x822923FC;
	sub_82179900(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,-4848
	ctx.r10.s64 = ctx.r11.s64 + -4848;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r18,16
	ctx.r18.s64 = 16;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lvx128 v8,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r15,r28,2768
	ctx.r15.s64 = ctx.r28.s64 + 2768;
	// vspltw v10,v8,2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0x55));
	// lvx128 v12,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v9,v8,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xAA));
	// lvx128 v11,r3,r18
	ea = (ctx.r3.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v8,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xFF));
	// lfs f27,2880(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 2880);
	ctx.f27.f64 = double(temp.f32);
	// vmaddfp v13,v13,v10,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v13,v9,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v8,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,2776(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 2776, temp.u32);
	// stfs f12,2772(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r28.u32 + 2772, temp.u32);
	// stfs f13,2768(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 2768, temp.u32);
	// lwz r11,120(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82292484
	if (ctx.cr6.eq) goto loc_82292484;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x82292484
	if (ctx.cr6.eq) goto loc_82292484;
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// bne cr6,0x822924dc
	if (!ctx.cr6.eq) goto loc_822924DC;
loc_82292484:
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// ble cr6,0x822924bc
	if (!ctx.cr6.gt) goto loc_822924BC;
	// lbz r11,311(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 311);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822924bc
	if (!ctx.cr6.eq) goto loc_822924BC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,56(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24632(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24632);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f12,56(r24)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r24.u32 + 56, temp.u32);
	// lfs f11,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f10,4(r28)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
loc_822924BC:
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bgt cr6,0x822924dc
	if (ctx.cr6.gt) goto loc_822924DC;
	// li r29,0
	ctx.r29.s64 = 0;
	// stfs f27,56(r24)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r24.u32 + 56, temp.u32);
	// stfs f27,4(r28)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// stb r29,311(r24)
	REX_STORE_U8(ctx.r24.u32 + 311, ctx.r29.u8);
	// b 0x822924e0
	goto loc_822924E0;
loc_822924DC:
	// li r29,0
	ctx.r29.s64 = 0;
loc_822924E0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r11,284(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 284);
	// li r14,1
	ctx.r14.s64 = 1;
	// li r19,2
	ctx.r19.s64 = 2;
	// lis r30,1
	ctx.r30.s64 = 65536;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lfs f30,4276(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4276);
	ctx.f30.f64 = double(temp.f32);
	// beq cr6,0x82292584
	if (ctx.cr6.eq) goto loc_82292584;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82292680
	if (!ctx.cr6.eq) goto loc_82292680;
	// lwz r11,20(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 20);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,260(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 260);
	// lfs f13,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lwz r8,196(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,0(r28)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lwz r7,24(r24)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r24.u32 + 24);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fadds f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f13.f64));
	// stfs f5,8(r28)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// lwz r5,44(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// cmpw cr6,r8,r5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x82292680
	if (ctx.cr6.lt) goto loc_82292680;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lfs f13,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// stb r29,284(r24)
	REX_STORE_U8(ctx.r24.u32 + 284, ctx.r29.u8);
	// stw r29,20(r24)
	REX_STORE_U32(ctx.r24.u32 + 20, ctx.r29.u32);
	// stw r29,24(r24)
	REX_STORE_U32(ctx.r24.u32 + 24, ctx.r29.u32);
	// b 0x82292680
	goto loc_82292680;
loc_82292584:
	// lwz r11,260(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 260);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82292680
	if (ctx.cr6.lt) goto loc_82292680;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// subf. r31,r10,r11
	ctx.r31.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x822925a8
	if (!ctx.cr0.eq) goto loc_822925A8;
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_822925A8:
	// stb r19,284(r24)
	REX_STORE_U8(ctx.r24.u32 + 284, ctx.r19.u8);
	// bl 0x8238e3b8
	ctx.lr = 0x822925B0;
	sub_8238E3B8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,324(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-4808(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4808);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822925cc
	if (!ctx.cr6.gt) goto loc_822925CC;
	// li r11,3072
	ctx.r11.s64 = 3072;
	// b 0x822925e0
	goto loc_822925E0;
loc_822925CC:
	// bl 0x8238e3b8
	ctx.lr = 0x822925D0;
	sub_8238E3B8(ctx, base);
	// lfs f0,324(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_822925E0:
	// addi r10,r11,-500
	ctx.r10.s64 = ctx.r11.s64 + -500;
	// lhz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// divw r10,r10,r31
	ctx.r10.u64 = uint32_t((ctx.r31.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r31.s32 == -1)) ? ctx.r10.s32 / ctx.r31.s32 : 0);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x822925f8
	if (ctx.cr6.lt) goto loc_822925F8;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_822925F8:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f10,f30
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f30.f64));
	// bl 0x826a1b90
	ctx.lr = 0x82292628;
	sub_826A1B90(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// li r9,20
	ctx.r9.s64 = 20;
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,r24,r9
	REX_STORE_U32(ctx.r24.u32 + ctx.r9.u32, ctx.f7.u32);
	// lhz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// blt cr6,0x8229264c
	if (ctx.cr6.lt) goto loc_8229264C;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_8229264C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1c70
	ctx.lr = 0x82292668;
	sub_826A1C70(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// li r10,24
	ctx.r10.s64 = 24;
	// stb r19,302(r24)
	REX_STORE_U8(ctx.r24.u32 + 302, ctx.r19.u8);
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r24,r10
	REX_STORE_U32(ctx.r24.u32 + ctx.r10.u32, ctx.f9.u32);
loc_82292680:
	// lfs f0,68(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// beq cr6,0x822927a0
	if (ctx.cr6.eq) goto loc_822927A0;
	// lfs f0,52(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,0(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lfs f11,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,60(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 60);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfs f9,8(r28)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// lfs f8,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,52(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 52);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fadds f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// stfs f5,0(r27)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// lfs f4,60(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 60);
	ctx.f4.f64 = double(temp.f32);
	// fadds f3,f4,f8
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f8.f64));
	// stfs f3,8(r27)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r27.u32 + 8, temp.u32);
	// lfs f2,56(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 56);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f2,f27
	ctx.cr6.compare(ctx.f2.f64, ctx.f27.f64);
	// bgt cr6,0x822927a0
	if (ctx.cr6.gt) goto loc_822927A0;
	// lfs f0,64(r24)
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x822927a0
	if (ctx.cr6.gt) goto loc_822927A0;
	// stfs f27,4(r28)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lfs f13,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// lwz r10,164(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// oris r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 65536;
	// stw r9,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r9.u32);
	// stfs f27,56(r24)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r24.u32 + 56, temp.u32);
	// stfs f27,68(r24)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r24.u32 + 68, temp.u32);
	// stb r19,302(r24)
	REX_STORE_U8(ctx.r24.u32 + 302, ctx.r19.u8);
	// stfs f27,52(r24)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r24.u32 + 52, temp.u32);
	// stw r11,140(r24)
	REX_STORE_U32(ctx.r24.u32 + 140, ctx.r11.u32);
	// stfs f27,60(r24)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r24.u32 + 60, temp.u32);
	// lwz r8,264(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r11,48(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822927a0
	if (ctx.cr6.eq) goto loc_822927A0;
	// stw r11,196(r28)
	REX_STORE_U32(ctx.r28.u32 + 196, ctx.r11.u32);
	// rlwinm r11,r11,12,0,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFFFF000;
	// lwz r8,204(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 204);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,908(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 908);
	// stw r11,240(r28)
	REX_STORE_U32(ctx.r28.u32 + 240, ctx.r11.u32);
	// rlwinm r9,r10,0,13,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFF7FFFF;
	// stw r9,908(r28)
	REX_STORE_U32(ctx.r28.u32 + 908, ctx.r9.u32);
	// lwz r7,196(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// subf r11,r8,r7
	ctx.r11.u64 = ctx.r7.u64 - ctx.r8.u64;
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// stw r7,224(r28)
	REX_STORE_U32(ctx.r28.u32 + 224, ctx.r7.u32);
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// subfe r9,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,236(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r28.u32 + 236, temp.u32);
	// stfs f12,232(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r28.u32 + 232, temp.u32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// lwz r8,164(r17)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwimi r8,r9,13,18,18
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x2000) | (ctx.r8.u64 & 0xFFFFFFFFFFFFDFFF);
	// stw r8,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r8.u32);
	// bl 0x822915d0
	ctx.lr = 0x822927A0;
	sub_822915D0(ctx, base);
loc_822927A0:
	// lwz r11,524(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 524);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x822927b4
	if (!ctx.cr6.gt) goto loc_822927B4;
	// stw r29,444(r28)
	REX_STORE_U32(ctx.r28.u32 + 444, ctx.r29.u32);
loc_822927B4:
	// lwz r9,264(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lhz r10,86(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 86);
	// lfs f28,-4812(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4812);
	ctx.f28.f64 = double(temp.f32);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8229288c
	if (ctx.cr6.eq) goto loc_8229288C;
	// lwz r10,40(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 40);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8229288c
	if (ctx.cr6.eq) goto loc_8229288C;
	// lwz r11,196(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8229288c
	if (ctx.cr6.gt) goto loc_8229288C;
	// lwz r10,44(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 44);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8229288c
	if (ctx.cr6.lt) goto loc_8229288C;
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// lhz r11,14(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
	// blt cr6,0x8229281c
	if (ctx.cr6.lt) goto loc_8229281C;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_8229281C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1b90
	ctx.lr = 0x82292838;
	sub_826A1B90(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lhz r11,14(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// fmuls f29,f11,f31
	ctx.f29.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// blt cr6,0x82292850
	if (ctx.cr6.lt) goto loc_82292850;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_82292850:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1c70
	ctx.lr = 0x8229286C;
	sub_826A1C70(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fnmsubs f8,f29,f28,f10
	ctx.f8.f64 = double(float(-std::fma(ctx.f29.f64, ctx.f28.f64, -ctx.f10.f64)));
	// stfs f8,0(r28)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// fmuls f7,f11,f31
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fnmsubs f6,f7,f28,f9
	ctx.f6.f64 = double(float(-std::fma(ctx.f7.f64, ctx.f28.f64, -ctx.f9.f64)));
	// stfs f6,8(r28)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
loc_8229288C:
	// lfs f0,44(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// beq cr6,0x822929bc
	if (ctx.cr6.eq) goto loc_822929BC;
	// lwz r11,328(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 328);
	// fmuls f31,f0,f28
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// lwz r11,192(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 192);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82292908
	if (ctx.cr6.eq) goto loc_82292908;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x822928c0
	if (ctx.cr6.lt) goto loc_822928C0;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_822928C0:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1b90
	ctx.lr = 0x822928DC;
	sub_826A1B90(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lwz r10,192(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 192);
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// fmuls f29,f11,f31
	ctx.f29.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// blt cr6,0x822928f8
	if (ctx.cr6.lt) goto loc_822928F8;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_822928F8:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x82292974
	goto loc_82292974;
loc_82292908:
	// lhz r10,14(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x82292924
	if (ctx.cr6.lt) goto loc_82292924;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_82292924:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1b90
	ctx.lr = 0x82292940;
	sub_826A1B90(ctx, base);
	// lhz r10,14(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lwz r11,192(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 192);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// fmuls f29,f11,f31
	ctx.f29.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// blt cr6,0x82292968
	if (ctx.cr6.lt) goto loc_82292968;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_82292968:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_82292974:
	// fcfid f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1c70
	ctx.lr = 0x82292984;
	sub_826A1C70(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f11,f31
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fsubs f11,f13,f29
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f29.f64));
	// stfs f11,0(r27)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f10,8(r27)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r27.u32 + 8, temp.u32);
	// lfs f8,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f6,f8,f29
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f29.f64));
	// lfs f9,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// stfs f6,0(r28)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// stfs f7,8(r28)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
loc_822929BC:
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82292a14
	if (ctx.cr6.eq) goto loc_82292A14;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,204(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 204);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,0(r27)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// lfs f11,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,208(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 208);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfs f9,8(r27)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r27.u32 + 8, temp.u32);
	// lfs f6,204(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 204);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fadds f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// lfs f8,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// stfs f5,0(r28)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// lfs f4,208(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 208);
	ctx.f4.f64 = double(temp.f32);
	// fadds f3,f4,f8
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f8.f64));
	// stfs f3,8(r28)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// lwz r11,20(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 20);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,20(r20)
	REX_STORE_U32(ctx.r20.u32 + 20, ctx.r11.u32);
loc_82292A14:
	// lwz r11,24(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82292a38
	if (ctx.cr6.eq) goto loc_82292A38;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lhz r10,212(r20)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r20.u32 + 212);
	// stw r11,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r11.u32);
	// lhz r11,6(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r8,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r8.u16);
loc_82292A38:
	// lwz r11,4(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 4);
	// fmr f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f27.f64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82292a54
	if (!ctx.cr6.gt) goto loc_82292A54;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// lfs f31,192(r20)
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + 192);
	ctx.f31.f64 = double(temp.f32);
	// stw r11,4(r20)
	REX_STORE_U32(ctx.r20.u32 + 4, ctx.r11.u32);
loc_82292A54:
	// lwz r11,8(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82292ad0
	if (!ctx.cr6.gt) goto loc_82292AD0;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// lwz r10,188(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 188);
	// lwz r11,52(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 52);
	// stw r9,8(r20)
	REX_STORE_U32(ctx.r20.u32 + 8, ctx.r9.u32);
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// lhz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// stw r8,188(r20)
	REX_STORE_U32(ctx.r20.u32 + 188, ctx.r8.u32);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f31,f12,f31
	ctx.f31.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
	// ble cr6,0x82292ad0
	if (!ctx.cr6.gt) goto loc_82292AD0;
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r11,r9,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r9.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// std r6,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f31,f12,f31
	ctx.f31.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
loc_82292AD0:
	// fcmpu cr6,f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f27.f64);
	// beq cr6,0x82292b78
	if (ctx.cr6.eq) goto loc_82292B78;
	// lwz r11,12(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 12);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x82292aec
	if (ctx.cr6.lt) goto loc_82292AEC;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_82292AEC:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1b90
	ctx.lr = 0x82292B08;
	sub_826A1B90(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lwz r10,12(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 12);
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// fmuls f29,f11,f31
	ctx.f29.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// blt cr6,0x82292b24
	if (ctx.cr6.lt) goto loc_82292B24;
	// subf r11,r30,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r30.u64;
loc_82292B24:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f30
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// bl 0x826a1c70
	ctx.lr = 0x82292B40;
	sub_826A1C70(ctx, base);
	// lfs f10,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// frsp f11,f1
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// fadds f8,f10,f29
	ctx.f8.f64 = double(float(ctx.f10.f64 + ctx.f29.f64));
	// stfs f8,0(r27)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// lfs f9,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f7,f11,f31
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fadds f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// stfs f6,8(r27)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r27.u32 + 8, temp.u32);
	// lfs f4,8(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lfs f5,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fadds f2,f5,f29
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f29.f64));
	// fadds f3,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f4.f64));
	// stfs f2,0(r28)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// stfs f3,8(r28)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
loc_82292B78:
	// lwz r11,120(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82292b8c
	if (ctx.cr6.eq) goto loc_82292B8C;
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// bne cr6,0x82292cb4
	if (!ctx.cr6.eq) goto loc_82292CB4;
loc_82292B8C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f27.f64;
	// bl 0x822a83e0
	ctx.lr = 0x82292B98;
	sub_822A83E0(ctx, base);
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82292bc8
	if (!ctx.cr6.gt) goto loc_82292BC8;
	// lwz r10,236(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 236);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// stw r9,228(r3)
	REX_STORE_U32(ctx.r3.u32 + 228, ctx.r9.u32);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
loc_82292BC8:
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82292c04
	if (!ctx.cr6.gt) goto loc_82292C04;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// stw r10,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r10.u32);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// std r6,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// stw r9,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r9.u32);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f31,f12,f31
	ctx.f31.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
loc_82292C04:
	// fcmpu cr6,f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f27.f64);
	// ble cr6,0x82292c2c
	if (!ctx.cr6.gt) goto loc_82292C2C;
	// fctiwz f0,f31
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f13,248(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f31,f13
	ctx.f12.f64 = double(float(ctx.f31.f64 + ctx.f13.f64));
	// stfs f12,248(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// stw r10,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r10.u32);
loc_82292C2C:
	// lfs f0,248(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bgt cr6,0x82292cb4
	if (ctx.cr6.gt) goto loc_82292CB4;
	// lwz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82292cb4
	if (!ctx.cr6.gt) goto loc_82292CB4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r30,r31,212
	ctx.r30.s64 = ctx.r31.s64 + 212;
	// stw r11,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// addi r29,r31,200
	ctx.r29.s64 = ctx.r31.s64 + 200;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82515460
	ctx.lr = 0x82292C64;
	sub_82515460(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x825154a8
	ctx.lr = 0x82292C70;
	sub_825154A8(ctx, base);
	// lwz r10,244(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 244);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// bl 0x82515728
	ctx.lr = 0x82292C94;
	sub_82515728(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82515418
	ctx.lr = 0x82292CA4;
	sub_82515418(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82515418
	ctx.lr = 0x82292CB4;
	sub_82515418(ctx, base);
loc_82292CB4:
	// lwz r11,608(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 608);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82292ccc
	if (ctx.cr6.eq) goto loc_82292CCC;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822d4c90
	ctx.lr = 0x82292CCC;
	sub_822D4C90(ctx, base);
loc_82292CCC:
	// lbz r29,303(r24)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r24.u32 + 303);
	// li r23,10
	ctx.r23.s64 = 10;
	// li r22,5
	ctx.r22.s64 = 5;
	// li r21,8
	ctx.r21.s64 = 8;
	// cmplwi cr6,r29,50
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 50, ctx.xer);
	// bgt cr6,0x82293cc0
	if (ctx.cr6.gt) goto loc_82293CC0;
	// lis r12,-32215
	ctx.r12.s64 = -2111242240;
	// rlwinm r0,r29,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,11516
	ctx.r12.s64 = ctx.r12.s64 + 11516;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r29.u32) {
	case 0:
		goto loc_82292DC8;
	case 1:
		goto loc_82292DD4;
	case 2:
		goto loc_82292DD4;
	case 3:
		goto loc_82292F08;
	case 4:
		goto loc_82292F08;
	case 5:
		goto loc_82292F08;
	case 6:
		goto loc_82292F08;
	case 7:
		goto loc_82293330;
	case 8:
		goto loc_82292F08;
	case 9:
		goto loc_82292F08;
	case 10:
		goto loc_82293468;
	case 11:
		goto loc_822935B8;
	case 12:
		goto loc_82293664;
	case 13:
		goto loc_822936F4;
	case 14:
		goto loc_8229376C;
	case 15:
		goto loc_822938A8;
	case 16:
		goto loc_82293CC0;
	case 17:
		goto loc_82293CC0;
	case 18:
		goto loc_82293978;
	case 19:
		goto loc_822939A8;
	case 20:
		goto loc_822939D8;
	case 21:
		goto loc_82293A08;
	case 22:
		goto loc_82293A38;
	case 23:
		goto loc_82293A68;
	case 24:
		goto loc_82293AC0;
	case 25:
		goto loc_82293AF8;
	case 26:
		goto loc_82293B30;
	case 27:
		goto loc_82293B68;
	case 28:
		goto loc_82293BA0;
	case 29:
		goto loc_82293BD8;
	case 30:
		goto loc_82293178;
	case 31:
		goto loc_822931A4;
	case 32:
		goto loc_822931D0;
	case 33:
		goto loc_822931FC;
	case 34:
		goto loc_82293228;
	case 35:
		goto loc_8229318C;
	case 36:
		goto loc_822931B8;
	case 37:
		goto loc_822931E4;
	case 38:
		goto loc_82293210;
	case 39:
		goto loc_8229323C;
	case 40:
		goto loc_82293254;
	case 41:
		goto loc_82293280;
	case 42:
		goto loc_822932AC;
	case 43:
		goto loc_822932D8;
	case 44:
		goto loc_82293304;
	case 45:
		goto loc_82293268;
	case 46:
		goto loc_82293294;
	case 47:
		goto loc_822932C0;
	case 48:
		goto loc_822932EC;
	case 49:
		goto loc_82293318;
	case 50:
		goto loc_82293C38;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82292DC8:
	// lhz r11,14(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// sth r11,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r11.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82292DD4:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// subf r11,r10,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82292df8
	if (ctx.cr6.gt) goto loc_82292DF8;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
loc_82292DF8:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// beq cr6,0x82292e34
	if (ctx.cr6.eq) goto loc_82292E34;
	// lwz r10,608(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 608);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82292e18
	if (ctx.cr6.eq) goto loc_82292E18;
	// lhz r10,22(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 22);
	// b 0x82292e1c
	goto loc_82292E1C;
loc_82292E18:
	// lhz r10,18(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 18);
loc_82292E1C:
	// lhz r6,6(r25)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsh r7,r11
	ctx.r7.s64 = ctx.r11.s16;
	// subf r5,r6,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r6.u64;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// divw r11,r3,r7
	ctx.r11.u64 = uint32_t((ctx.r7.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r3.s32 / ctx.r7.s32 : 0);
	// b 0x82292e4c
	goto loc_82292E4C;
loc_82292E34:
	// lhz r7,4(r25)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lhz r6,6(r25)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// divw r11,r3,r9
	ctx.r11.u64 = uint32_t((ctx.r9.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r3.s32 / ctx.r9.s32 : 0);
loc_82292E4C:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82292e6c
	if (!ctx.cr6.lt) goto loc_82292E6C;
	// cmpwi cr6,r11,-5461
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -5461, ctx.xer);
	// bge cr6,0x82292e78
	if (!ctx.cr6.lt) goto loc_82292E78;
	// li r11,-5461
	ctx.r11.s64 = -5461;
	// b 0x82292e78
	goto loc_82292E78;
loc_82292E6C:
	// cmpwi cr6,r11,5461
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5461, ctx.xer);
	// ble cr6,0x82292e78
	if (!ctx.cr6.gt) goto loc_82292E78;
	// li r11,5461
	ctx.r11.s64 = 5461;
loc_82292E78:
	// lhz r30,280(r24)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r24.u32 + 280);
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// li r5,32767
	ctx.r5.s64 = 32767;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82291b50
	ctx.lr = 0x82292E90;
	sub_82291B50(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82292eb4
	if (ctx.cr6.eq) goto loc_82292EB4;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// bne cr6,0x82292eac
	if (!ctx.cr6.eq) goto loc_82292EAC;
	// li r11,17
	ctx.r11.s64 = 17;
loc_82292EAC:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r11,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r11.u8);
loc_82292EB4:
	// extsh r11,r31
	ctx.r11.s64 = ctx.r31.s16;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// sth r10,280(r24)
	REX_STORE_U16(ctx.r24.u32 + 280, ctx.r10.u16);
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// sth r11,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r11.u16);
	// beq cr6,0x82292edc
	if (ctx.cr6.eq) goto loc_82292EDC;
	// sth r11,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r11.u16);
loc_82292EDC:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82293cc0
	if (ctx.cr6.lt) goto loc_82293CC0;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// bne cr6,0x82292f00
	if (!ctx.cr6.eq) goto loc_82292F00;
	// li r11,17
	ctx.r11.s64 = 17;
loc_82292F00:
	// stb r11,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r11.u8);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82292F08:
	// cmplwi cr6,r29,8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 8, ctx.xer);
	// beq cr6,0x82292f1c
	if (ctx.cr6.eq) goto loc_82292F1C;
	// cmplwi cr6,r29,9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 9, ctx.xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// bne cr6,0x82292f20
	if (!ctx.cr6.eq) goto loc_82292F20;
loc_82292F1C:
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
loc_82292F20:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x82293004
	if (ctx.cr6.eq) goto loc_82293004;
	// lwz r11,1688(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 1688);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82293004
	if (ctx.cr6.eq) goto loc_82293004;
	// lbz r11,298(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 298);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293004
	if (ctx.cr6.eq) goto loc_82293004;
	// lwz r11,208(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 208);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bgt cr6,0x82293004
	if (ctx.cr6.gt) goto loc_82293004;
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// subf. r7,r10,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r7,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r7.u32);
	// bgt 0x82292f68
	if (ctx.cr0.gt) goto loc_82292F68;
	// stw r14,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r14.u32);
loc_82292F68:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r8,24(r20)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r20.u32 + 24);
	// beq cr6,0x82292f9c
	if (ctx.cr6.eq) goto loc_82292F9C;
	// lhz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// subf r6,r7,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r7.u64;
	// subf r5,r26,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r26.u64;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// divw r11,r3,r8
	ctx.r11.u64 = uint32_t((ctx.r8.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r3.s32 / ctx.r8.s32 : 0);
	// sth r11,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r11.u16);
	// b 0x82292fb4
	goto loc_82292FB4;
loc_82292F9C:
	// lhz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r7,6(r25)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// subf r6,r7,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r7.u64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// divw r3,r4,r8
	ctx.r3.u64 = uint32_t((ctx.r8.s32 && !(ctx.r4.s32 == INT32_MIN && ctx.r8.s32 == -1)) ? ctx.r4.s32 / ctx.r8.s32 : 0);
	// sth r3,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r3.u16);
loc_82292FB4:
	// lhz r11,212(r20)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r20.u32 + 212);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82292fe4
	if (!ctx.cr6.lt) goto loc_82292FE4;
	// cmpwi cr6,r11,-2548
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2548, ctx.xer);
	// bge cr6,0x82292ff0
	if (!ctx.cr6.lt) goto loc_82292FF0;
	// li r11,-2548
	ctx.r11.s64 = -2548;
	// li r10,17
	ctx.r10.s64 = 17;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// sth r11,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r11.u16);
	// stb r10,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r10.u8);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82292FE4:
	// cmpwi cr6,r11,2548
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2548, ctx.xer);
	// ble cr6,0x82292ff0
	if (!ctx.cr6.gt) goto loc_82292FF0;
	// li r11,2548
	ctx.r11.s64 = 2548;
loc_82292FF0:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// li r10,17
	ctx.r10.s64 = 17;
	// sth r11,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r11.u16);
	// stb r10,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r10.u8);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293004:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// subf r11,r10,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r10.u64;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x82293028
	if (ctx.cr6.gt) goto loc_82293028;
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
loc_82293028:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r9,r11,0,13,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82293040
	if (ctx.cr6.eq) goto loc_82293040;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x82293054
	goto loc_82293054;
loc_82293040:
	// lwz r11,208(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 208);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// li r11,14
	ctx.r11.s64 = 14;
	// bge cr6,0x82293054
	if (!ctx.cr6.lt) goto loc_82293054;
	// li r11,3
	ctx.r11.s64 = 3;
loc_82293054:
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// rlwinm r7,r11,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// li r6,360
	ctx.r6.s64 = 360;
	// subf r5,r9,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r9.u64;
	// cmplwi cr6,r29,5
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 5, ctx.xer);
	// divw r4,r5,r6
	ctx.r4.u64 = uint32_t((ctx.r6.s32 && !(ctx.r5.s32 == INT32_MIN && ctx.r6.s32 == -1)) ? ctx.r5.s32 / ctx.r6.s32 : 0);
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// beq cr6,0x8229307c
	if (ctx.cr6.eq) goto loc_8229307C;
	// cmplwi cr6,r29,9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 9, ctx.xer);
	// bne cr6,0x82293084
	if (!ctx.cr6.eq) goto loc_82293084;
loc_8229307C:
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
loc_82293084:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// beq cr6,0x822930b8
	if (ctx.cr6.eq) goto loc_822930B8;
	// lhz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r8,6(r25)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsh r7,r11
	ctx.r7.s64 = ctx.r11.s16;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r4,r26,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r26.u64;
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// divw r10,r11,r10
	ctx.r10.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// b 0x822930d0
	goto loc_822930D0;
loc_822930B8:
	// lhz r7,4(r25)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r6,6(r25)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// divw r11,r3,r10
	ctx.r11.u64 = uint32_t((ctx.r10.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r3.s32 / ctx.r10.s32 : 0);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
loc_822930D0:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x822930f0
	if (!ctx.cr6.lt) goto loc_822930F0;
	// neg r10,r10
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x822930fc
	if (!ctx.cr6.lt) goto loc_822930FC;
	// b 0x822930f8
	goto loc_822930F8;
loc_822930F0:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x822930fc
	if (!ctx.cr6.gt) goto loc_822930FC;
loc_822930F8:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_822930FC:
	// lhz r30,280(r24)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r24.u32 + 280);
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// cmplwi cr6,r29,5
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 5, ctx.xer);
	// bl 0x82291b50
	ctx.lr = 0x82293118;
	sub_82291B50(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8229312c
	if (ctx.cr6.eq) goto loc_8229312C;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r23,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r23.u8);
loc_8229312C:
	// extsh r11,r31
	ctx.r11.s64 = ctx.r31.s16;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// sth r10,280(r24)
	REX_STORE_U16(ctx.r24.u32 + 280, ctx.r10.u16);
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// sth r11,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r11.u16);
	// beq cr6,0x82293158
	if (ctx.cr6.eq) goto loc_82293158;
	// cmpwi cr6,r29,6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 6, ctx.xer);
	// bne cr6,0x8229315c
	if (!ctx.cr6.eq) goto loc_8229315C;
loc_82293158:
	// sth r11,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r11.u16);
loc_8229315C:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82293cc0
	if (ctx.cr6.lt) goto loc_82293CC0;
	// stb r23,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r23.u8);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293178:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x82293184;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_8229318C:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,546
	ctx.r4.s64 = 546;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x822931A0;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822931A4:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x822931B0;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_822931B8:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,728
	ctx.r4.s64 = 728;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x822931CC;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822931D0:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x822931DC;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_822931E4:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,1274
	ctx.r4.s64 = 1274;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x822931F8;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822931FC:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x82293208;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_82293210:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,2548
	ctx.r4.s64 = 2548;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x82293224;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293228:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x82293234;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_8229323C:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,32767
	ctx.r5.s64 = 32767;
	// li r4,4186
	ctx.r4.s64 = 4186;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x82293250;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293254:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x82293260;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_82293268:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,546
	ctx.r4.s64 = 546;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x8229327C;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293280:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x8229328C;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_82293294:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,728
	ctx.r4.s64 = 728;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x822932A8;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822932AC:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x822932B8;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_822932C0:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,1274
	ctx.r4.s64 = 1274;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x822932D4;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822932D8:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x822932E4;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_822932EC:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,21845
	ctx.r5.s64 = 21845;
	// li r4,2548
	ctx.r4.s64 = 2548;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x82293300;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293304:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291d00
	ctx.lr = 0x82293310;
	sub_82291D00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_82293318:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,32767
	ctx.r5.s64 = 32767;
	// li r4,4186
	ctx.r4.s64 = 4186;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82291db0
	ctx.lr = 0x8229332C;
	sub_82291DB0(ctx, base);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293330:
	// lwz r11,24(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x82293cc0
	if (ctx.cr6.eq) goto loc_82293CC0;
	// lwz r11,1688(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 1688);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8229335c
	if (ctx.cr6.eq) goto loc_8229335C;
	// lbz r11,298(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 298);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
loc_8229335C:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// subf r11,r10,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82293380
	if (ctx.cr6.gt) goto loc_82293380;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
loc_82293380:
	// lhz r7,4(r25)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lhz r5,6(r25)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// lwz r6,164(r17)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// subf r3,r5,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r5.u64;
	// rlwinm r4,r6,0,13,13
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x40000;
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// divw r9,r10,r9
	ctx.r9.u64 = uint32_t((ctx.r9.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r10.s32 / ctx.r9.s32 : 0);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// beq cr6,0x822933b4
	if (ctx.cr6.eq) goto loc_822933B4;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x822933c8
	goto loc_822933C8;
loc_822933B4:
	// lwz r11,208(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 208);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// li r11,3
	ctx.r11.s64 = 3;
	// bge cr6,0x822933c8
	if (!ctx.cr6.lt) goto loc_822933C8;
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
loc_822933C8:
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// li r7,360
	ctx.r7.s64 = 360;
	// subf r6,r9,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r9.u64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// divw r5,r6,r7
	ctx.r5.u64 = uint32_t((ctx.r7.s32 && !(ctx.r6.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r6.s32 / ctx.r7.s32 : 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// bge cr6,0x822933fc
	if (!ctx.cr6.lt) goto loc_822933FC;
	// neg r10,r10
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82293408
	if (!ctx.cr6.lt) goto loc_82293408;
	// b 0x82293404
	goto loc_82293404;
loc_822933FC:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x82293408
	if (!ctx.cr6.gt) goto loc_82293408;
loc_82293404:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82293408:
	// lhz r30,280(r24)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r24.u32 + 280);
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// li r5,3640
	ctx.r5.s64 = 3640;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82291b50
	ctx.lr = 0x82293420;
	sub_82291B50(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82293434
	if (ctx.cr6.eq) goto loc_82293434;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r23,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r23.u8);
loc_82293434:
	// extsh r11,r31
	ctx.r11.s64 = ctx.r31.s16;
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// sth r10,280(r24)
	REX_STORE_U16(ctx.r24.u32 + 280, ctx.r10.u16);
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r7,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r7.u16);
	// lwz r5,264(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r4,196(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r3,76(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 76);
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x82293cc0
	if (ctx.cr6.lt) goto loc_82293CC0;
	// stb r23,303(r24)
	REX_STORE_U8(ctx.r24.u32 + 303, ctx.r23.u8);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293468:
	// lwz r11,160(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822934a4
	if (ctx.cr6.eq) goto loc_822934A4;
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x822934a4
	if (ctx.cr6.eq) goto loc_822934A4;
	// lwz r10,164(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r9,r10,0,13,13
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x822934a4
	if (!ctx.cr6.eq) goto loc_822934A4;
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,80(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x822934b4
	if (!ctx.cr6.lt) goto loc_822934B4;
loc_822934A4:
	// lwz r11,340(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 340);
	// rlwinm r10,r11,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822934c4
	if (ctx.cr6.eq) goto loc_822934C4;
loc_822934B4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r11.u32);
	// sth r11,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r11.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822934C4:
	// lwz r8,264(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r11,76(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 76);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82293cc0
	if (!ctx.cr6.gt) goto loc_82293CC0;
	// lis r9,26214
	ctx.r9.s64 = 1717960704;
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// ori r6,r9,26215
	ctx.r6.u64 = ctx.r9.u64 | 26215;
	// mulhw r5,r7,r6
	ctx.r5.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32)) >> 32;
	// srawi r11,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf. r3,r4,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82293cc0
	if (!ctx.cr0.eq) goto loc_82293CC0;
	// lhz r11,12(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 12);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// cmpwi cr6,r9,21845
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 21845, ctx.xer);
	// bgt cr6,0x82293cc0
	if (ctx.cr6.gt) goto loc_82293CC0;
	// lwz r11,36(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// ble cr6,0x8229352c
	if (!ctx.cr6.gt) goto loc_8229352C;
	// stw r11,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r11.u32);
	// b 0x82293530
	goto loc_82293530;
loc_8229352C:
	// stw r22,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r22.u32);
loc_82293530:
	// lwz r10,24(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x82293548
	if (!ctx.cr6.lt) goto loc_82293548;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,24(r20)
	REX_STORE_U32(ctx.r20.u32 + 24, ctx.r11.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293548:
	// lwz r11,608(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 608);
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82293560
	if (ctx.cr6.eq) goto loc_82293560;
	// lhz r11,22(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 22);
	// b 0x82293564
	goto loc_82293564;
loc_82293560:
	// lhz r11,18(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 18);
loc_82293564:
	// lhz r7,6(r25)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// subf r6,r7,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r7.u64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// divw r3,r4,r10
	ctx.r3.u64 = uint32_t((ctx.r10.s32 && !(ctx.r4.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r4.s32 / ctx.r10.s32 : 0);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// sth r10,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r10.u16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x822935a0
	if (!ctx.cr6.lt) goto loc_822935A0;
	// cmpwi cr6,r10,-546
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -546, ctx.xer);
	// bge cr6,0x822935ac
	if (!ctx.cr6.lt) goto loc_822935AC;
	// li r11,-546
	ctx.r11.s64 = -546;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// sth r11,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r11.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822935A0:
	// cmpwi cr6,r11,546
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 546, ctx.xer);
	// ble cr6,0x822935ac
	if (!ctx.cr6.gt) goto loc_822935AC;
	// li r11,546
	ctx.r11.s64 = 546;
loc_822935AC:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// sth r11,212(r20)
	REX_STORE_U16(ctx.r20.u32 + 212, ctx.r11.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822935B8:
	// lwz r10,264(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r11,44(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822935cc
	if (!ctx.cr6.eq) goto loc_822935CC;
	// lwz r11,36(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
loc_822935CC:
	// lwz r9,196(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x82293cc0
	if (ctx.cr6.gt) goto loc_82293CC0;
	// lwz r10,608(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 608);
	// rlwinm r8,r10,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822935f0
	if (ctx.cr6.eq) goto loc_822935F0;
	// lhz r10,22(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 22);
	// b 0x822935f4
	goto loc_822935F4;
loc_822935F0:
	// lhz r10,18(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 18);
loc_822935F4:
	// lhz r6,6(r25)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r5,r6,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r6.u64;
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// bne cr6,0x8229360c
	if (!ctx.cr6.eq) goto loc_8229360C;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
loc_8229360C:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// mullw r9,r10,r9
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// divw r8,r9,r11
	ctx.r8.u64 = uint32_t((ctx.r11.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r9.s32 / ctx.r11.s32 : 0);
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82293644
	if (!ctx.cr6.lt) goto loc_82293644;
	// cmpwi cr6,r11,-910
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -910, ctx.xer);
	// bge cr6,0x82293650
	if (!ctx.cr6.lt) goto loc_82293650;
	// li r11,-910
	ctx.r11.s64 = -910;
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r9.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293644:
	// cmpwi cr6,r11,910
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 910, ctx.xer);
	// ble cr6,0x82293650
	if (!ctx.cr6.gt) goto loc_82293650;
	// li r11,910
	ctx.r11.s64 = 910;
loc_82293650:
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r9.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293664:
	// lwz r10,208(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 208);
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// ble cr6,0x82293674
	if (!ctx.cr6.gt) goto loc_82293674;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
loc_82293674:
	// lwz r11,608(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 608);
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8229368c
	if (ctx.cr6.eq) goto loc_8229368C;
	// lhz r11,22(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 22);
	// b 0x82293690
	goto loc_82293690;
loc_8229368C:
	// lhz r11,18(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 18);
loc_82293690:
	// lhz r7,6(r25)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// subf r6,r7,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r7.u64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// mullw r3,r4,r10
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// srawi r11,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 3;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x822936d4
	if (!ctx.cr6.lt) goto loc_822936D4;
	// cmpwi cr6,r11,-1820
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1820, ctx.xer);
	// bge cr6,0x822936e0
	if (!ctx.cr6.lt) goto loc_822936E0;
	// li r11,-1820
	ctx.r11.s64 = -1820;
	// clrlwi r10,r7,16
	ctx.r10.u64 = ctx.r7.u32 & 0xFFFF;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r9.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822936D4:
	// cmpwi cr6,r11,1820
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1820, ctx.xer);
	// ble cr6,0x822936e0
	if (!ctx.cr6.gt) goto loc_822936E0;
	// li r11,1820
	ctx.r11.s64 = 1820;
loc_822936E0:
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r9.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822936F4:
	// lwz r11,208(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 208);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// ble cr6,0x82293704
	if (!ctx.cr6.gt) goto loc_82293704;
	// mr r11,r18
	ctx.r11.u64 = ctx.r18.u64;
loc_82293704:
	// lhz r8,4(r25)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r7,6(r25)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// subf r6,r7,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r7.u64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// mullw r3,r4,r11
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r11.s32);
	// srawi r11,r3,4
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 4;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8229374c
	if (!ctx.cr6.lt) goto loc_8229374C;
	// cmpwi cr6,r11,-2184
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2184, ctx.xer);
	// bge cr6,0x82293758
	if (!ctx.cr6.lt) goto loc_82293758;
	// li r11,-2184
	ctx.r11.s64 = -2184;
	// clrlwi r10,r7,16
	ctx.r10.u64 = ctx.r7.u32 & 0xFFFF;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r9.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_8229374C:
	// cmpwi cr6,r11,2184
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2184, ctx.xer);
	// ble cr6,0x82293758
	if (!ctx.cr6.gt) goto loc_82293758;
	// li r11,2184
	ctx.r11.s64 = 2184;
loc_82293758:
	// lhz r10,6(r25)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r9.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_8229376C:
	// bl 0x8238e3b8
	ctx.lr = 0x82293770;
	sub_8238E3B8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,324(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,21280(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21280);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82293cc0
	if (ctx.cr6.lt) goto loc_82293CC0;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,36(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 36);
	// fctiwz f11,f13
	ctx.f11.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lfs f0,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,40(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 40);
	// fctiwz f12,f0
	ctx.f12.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subf r6,r8,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r8.u64;
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r5,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// lfd f9,80(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f2,f8
	ctx.f2.f64 = double(float(ctx.f8.f64));
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f1,f7
	ctx.f1.f64 = double(float(ctx.f7.f64));
	// bl 0x826a1000
	ctx.lr = 0x822937E0;
	sub_826A1000(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lhz r8,14(r28)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// lfs f0,8160(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8160);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// subf r6,r9,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r9.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r5,32768
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 32768, ctx.xer);
	// blt cr6,0x8229382c
	if (ctx.cr6.lt) goto loc_8229382C;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// subfic r6,r11,-1
	ctx.xer.ca = ctx.r11.u32 <= 4294967295;
	ctx.r6.u64 = static_cast<uint64_t>(-1) - ctx.r11.u64;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
loc_8229382C:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,16384
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16384, ctx.xer);
	// blt cr6,0x82293840
	if (ctx.cr6.lt) goto loc_82293840;
	// subf r11,r26,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r26.u64;
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
loc_82293840:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// lwz r10,264(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// lwz r8,196(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// subf r6,r9,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r9.u64;
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// lwz r4,36(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// mullw r11,r3,r8
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// divw r10,r11,r4
	ctx.r10.u64 = uint32_t((ctx.r4.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r4.s32 == -1)) ? ctx.r11.s32 / ctx.r4.s32 : 0);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82293880
	if (!ctx.cr6.lt) goto loc_82293880;
	// cmpwi cr6,r11,-1456
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1456, ctx.xer);
	// bge cr6,0x8229388c
	if (!ctx.cr6.lt) goto loc_8229388C;
	// li r11,-1456
	ctx.r11.s64 = -1456;
	// b 0x8229388c
	goto loc_8229388C;
loc_82293880:
	// cmpwi cr6,r11,1456
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1456, ctx.xer);
	// ble cr6,0x8229388c
	if (!ctx.cr6.gt) goto loc_8229388C;
	// li r11,1456
	ctx.r11.s64 = 1456;
loc_8229388C:
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// sth r10,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r10.u16);
	// sth r10,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r10.u16);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822938A8:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r31,196(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// cmpw cr6,r31,r10
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x82293cc0
	if (ctx.cr6.gt) goto loc_82293CC0;
	// lfs f1,60(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 60);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,68(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x826a1000
	ctx.lr = 0x822938C8;
	sub_826A1000(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,88(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 88);
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// lfs f0,8160(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8160);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// bne cr6,0x82293904
	if (!ctx.cr6.eq) goto loc_82293904;
	// lwz r11,0(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 0);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// li r11,-1820
	ctx.r11.s64 = -1820;
	// beq cr6,0x82293908
	if (ctx.cr6.eq) goto loc_82293908;
loc_82293904:
	// li r11,4551
	ctx.r11.s64 = 4551;
loc_82293908:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x82293920
	if (!ctx.cr6.lt) goto loc_82293920;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// neg r10,r11
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// extsh r11,r10
	ctx.r11.s64 = ctx.r10.s16;
loc_82293920:
	// lwz r10,264(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lwz r8,608(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 608);
	// mullw r7,r9,r31
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r31.s32);
	// lwz r6,36(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// divw r5,r7,r6
	ctx.r5.u64 = uint32_t((ctx.r6.s32 && !(ctx.r7.s32 == INT32_MIN && ctx.r6.s32 == -1)) ? ctx.r7.s32 / ctx.r6.s32 : 0);
	// rlwinm r4,r8,0,27,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82293950
	if (ctx.cr6.eq) goto loc_82293950;
	// lhz r11,22(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 22);
	// b 0x82293954
	goto loc_82293954;
loc_82293950:
	// lhz r11,18(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 18);
loc_82293954:
	// subf r8,r10,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r10.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lhz r4,6(r25)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r25.u32 + 6);
	// bl 0x82291c20
	ctx.lr = 0x8229396C;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293978:
	// li r5,40
	ctx.r5.s64 = 40;
	// lhz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r4,14(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291c20
	ctx.lr = 0x82293988;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822939A8:
	// li r5,30
	ctx.r5.s64 = 30;
	// lhz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r4,14(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291c20
	ctx.lr = 0x822939B8;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_822939D8:
	// li r5,20
	ctx.r5.s64 = 20;
	// lhz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r4,14(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291c20
	ctx.lr = 0x822939E8;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293A08:
	// li r5,10
	ctx.r5.s64 = 10;
	// lhz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r4,14(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291c20
	ctx.lr = 0x82293A18;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293A38:
	// li r5,5
	ctx.r5.s64 = 5;
	// lhz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r4,14(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291c20
	ctx.lr = 0x82293A48;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293A68:
	// bl 0x8238e3b8
	ctx.lr = 0x82293A6C;
	sub_8238E3B8(ctx, base);
	// addi r11,r3,324
	ctx.r11.s64 = ctx.r3.s64 + 324;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lhz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r25.u32 + 4);
	// lhz r4,14(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// ori r9,r10,50000
	ctx.r9.u64 = ctx.r10.u64 | 50000;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r8,r11,5000
	ctx.r8.s64 = ctx.r11.s64 + 5000;
	// divwu r7,r9,r8
	ctx.r7.u64 = uint32_t(ctx.r8.u32 ? ctx.r9.u32 / ctx.r8.u32 : 0);
	// clrlwi r5,r7,16
	ctx.r5.u64 = ctx.r7.u32 & 0xFFFF;
	// bl 0x82291c20
	ctx.lr = 0x82293AA0;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r6,164(r17)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r5,r6,0,11,11
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293AC0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhz r31,14(r28)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291ba8
	ctx.lr = 0x82293ACC;
	sub_82291BA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// bl 0x82291c20
	ctx.lr = 0x82293AD8;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293AF8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhz r31,14(r28)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291ba8
	ctx.lr = 0x82293B04;
	sub_82291BA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,30
	ctx.r5.s64 = 30;
	// bl 0x82291c20
	ctx.lr = 0x82293B10;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293B30:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhz r31,14(r28)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291ba8
	ctx.lr = 0x82293B3C;
	sub_82291BA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x82291c20
	ctx.lr = 0x82293B48;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293B68:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhz r31,14(r28)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291ba8
	ctx.lr = 0x82293B74;
	sub_82291BA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,10
	ctx.r5.s64 = 10;
	// bl 0x82291c20
	ctx.lr = 0x82293B80;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293BA0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhz r31,14(r28)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// bl 0x82291ba8
	ctx.lr = 0x82293BAC;
	sub_82291BA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// bl 0x82291c20
	ctx.lr = 0x82293BB8;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,11,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293BD8:
	// bl 0x8238e3b8
	ctx.lr = 0x82293BDC;
	sub_8238E3B8(ctx, base);
	// addi r11,r3,324
	ctx.r11.s64 = ctx.r3.s64 + 324;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lhz r31,14(r28)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// bl 0x82291ba8
	ctx.lr = 0x82293BF8;
	sub_82291BA8(ctx, base);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,5000
	ctx.r9.s64 = ctx.r11.s64 + 5000;
	// ori r8,r10,50000
	ctx.r8.u64 = ctx.r10.u64 | 50000;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// divwu r7,r8,r9
	ctx.r7.u64 = uint32_t(ctx.r9.u32 ? ctx.r8.u32 / ctx.r9.u32 : 0);
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// bl 0x82291c20
	ctx.lr = 0x82293C18;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
	// lwz r6,164(r17)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r5,r6,0,11,11
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82293cc0
	if (!ctx.cr6.eq) goto loc_82293CC0;
	// stw r14,620(r28)
	REX_STORE_U32(ctx.r28.u32 + 620, ctx.r14.u32);
	// b 0x82293cc0
	goto loc_82293CC0;
loc_82293C38:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fctiwz f10,f12
	ctx.f10.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f10.u64);
	// fctiwz f9,f11
	ctx.f9.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f8,96(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfd f7,80(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// fcfid f5,f7
	ctx.f5.f64 = double(ctx.f7.s64);
	// frsp f1,f6
	ctx.f1.f64 = double(float(ctx.f6.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// bl 0x826a1000
	ctx.lr = 0x82293C8C;
	sub_826A1000(ctx, base);
	// frsp f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r5,5
	ctx.r5.s64 = 5;
	// lhz r4,14(r28)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// lfs f0,8160(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8160);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f2.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// bl 0x82291c20
	ctx.lr = 0x82293CB8;
	sub_82291C20(ctx, base);
	// sth r3,6(r25)
	REX_STORE_U16(ctx.r25.u32 + 6, ctx.r3.u16);
	// sth r3,14(r28)
	REX_STORE_U16(ctx.r28.u32 + 14, ctx.r3.u16);
loc_82293CC0:
	// lwz r11,60(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 60);
	// li r9,0
	ctx.r9.s64 = 0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,60(r20)
	REX_STORE_U32(ctx.r20.u32 + 60, ctx.r11.u32);
	// bge 0x82293cd8
	if (!ctx.cr0.lt) goto loc_82293CD8;
	// stw r9,60(r20)
	REX_STORE_U32(ctx.r20.u32 + 60, ctx.r9.u32);
loc_82293CD8:
	// lwz r11,40(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r20)
	REX_STORE_U32(ctx.r20.u32 + 40, ctx.r11.u32);
	// bge 0x82293cec
	if (!ctx.cr0.lt) goto loc_82293CEC;
	// stw r9,40(r20)
	REX_STORE_U32(ctx.r20.u32 + 40, ctx.r9.u32);
loc_82293CEC:
	// lwz r11,36(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82293d00
	if (!ctx.cr6.gt) goto loc_82293D00;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,36(r20)
	REX_STORE_U32(ctx.r20.u32 + 36, ctx.r11.u32);
loc_82293D00:
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82293d14
	if (!ctx.cr6.gt) goto loc_82293D14;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_82293D14:
	// lwz r11,68(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 68);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// stw r8,68(r20)
	REX_STORE_U32(ctx.r20.u32 + 68, ctx.r8.u32);
	// blt cr6,0x82293d34
	if (ctx.cr6.lt) goto loc_82293D34;
	// stw r10,68(r20)
	REX_STORE_U32(ctx.r20.u32 + 68, ctx.r10.u32);
loc_82293D34:
	// lwz r11,100(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 100);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// stw r8,100(r20)
	REX_STORE_U32(ctx.r20.u32 + 100, ctx.r8.u32);
	// blt cr6,0x82293d4c
	if (ctx.cr6.lt) goto loc_82293D4C;
	// stw r10,100(r20)
	REX_STORE_U32(ctx.r20.u32 + 100, ctx.r10.u32);
loc_82293D4C:
	// lwz r10,144(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 144);
	// li r11,-1
	ctx.r11.s64 = -1;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r8,144(r20)
	REX_STORE_U32(ctx.r20.u32 + 144, ctx.r8.u32);
	// blt cr6,0x82293d68
	if (ctx.cr6.lt) goto loc_82293D68;
	// stw r11,100(r20)
	REX_STORE_U32(ctx.r20.u32 + 100, ctx.r11.u32);
loc_82293D68:
	// lwz r11,72(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 72);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,72(r20)
	REX_STORE_U32(ctx.r20.u32 + 72, ctx.r10.u32);
	// bne cr6,0x82293d80
	if (!ctx.cr6.eq) goto loc_82293D80;
	// stw r9,72(r20)
	REX_STORE_U32(ctx.r20.u32 + 72, ctx.r9.u32);
loc_82293D80:
	// lwz r11,76(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 76);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,76(r20)
	REX_STORE_U32(ctx.r20.u32 + 76, ctx.r10.u32);
	// bne cr6,0x82293d98
	if (!ctx.cr6.eq) goto loc_82293D98;
	// stw r9,76(r20)
	REX_STORE_U32(ctx.r20.u32 + 76, ctx.r9.u32);
loc_82293D98:
	// lwz r11,160(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 160);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,160(r20)
	REX_STORE_U32(ctx.r20.u32 + 160, ctx.r11.u32);
	// bge 0x82293dac
	if (!ctx.cr0.lt) goto loc_82293DAC;
	// stw r9,160(r20)
	REX_STORE_U32(ctx.r20.u32 + 160, ctx.r9.u32);
loc_82293DAC:
	// bl 0x822d17f8
	ctx.lr = 0x82293DB0;
	sub_822D17F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82293e58
	if (!ctx.cr6.eq) goto loc_82293E58;
	// lwz r11,108(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293dcc
	if (ctx.cr6.eq) goto loc_82293DCC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,108(r20)
	REX_STORE_U32(ctx.r20.u32 + 108, ctx.r11.u32);
loc_82293DCC:
	// lwz r11,112(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293de0
	if (ctx.cr6.eq) goto loc_82293DE0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,112(r20)
	REX_STORE_U32(ctx.r20.u32 + 112, ctx.r11.u32);
loc_82293DE0:
	// lwz r11,116(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293df4
	if (ctx.cr6.eq) goto loc_82293DF4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,116(r20)
	REX_STORE_U32(ctx.r20.u32 + 116, ctx.r11.u32);
loc_82293DF4:
	// lwz r11,120(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293e08
	if (ctx.cr6.eq) goto loc_82293E08;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,120(r20)
	REX_STORE_U32(ctx.r20.u32 + 120, ctx.r11.u32);
loc_82293E08:
	// lwz r11,124(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293e1c
	if (ctx.cr6.eq) goto loc_82293E1C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,124(r20)
	REX_STORE_U32(ctx.r20.u32 + 124, ctx.r11.u32);
loc_82293E1C:
	// lwz r11,128(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293e30
	if (ctx.cr6.eq) goto loc_82293E30;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,128(r20)
	REX_STORE_U32(ctx.r20.u32 + 128, ctx.r11.u32);
loc_82293E30:
	// lwz r11,132(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 132);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293e44
	if (ctx.cr6.eq) goto loc_82293E44;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,132(r20)
	REX_STORE_U32(ctx.r20.u32 + 132, ctx.r11.u32);
loc_82293E44:
	// lwz r11,136(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293e58
	if (ctx.cr6.eq) goto loc_82293E58;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,136(r20)
	REX_STORE_U32(ctx.r20.u32 + 136, ctx.r11.u32);
loc_82293E58:
	// bl 0x822d1688
	ctx.lr = 0x82293E5C;
	sub_822D1688(ctx, base);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lis r26,-32256
	ctx.r26.s64 = -2113929216;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r27,r11,23664
	ctx.r27.s64 = ctx.r11.s64 + 23664;
	// beq cr6,0x82293f40
	if (ctx.cr6.eq) goto loc_82293F40;
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r31,128(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293e9c
	if (ctx.cr6.eq) goto loc_82293E9C;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,20(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82293e9c
	if (!ctx.cr6.eq) goto loc_82293E9C;
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82293ea4
	goto loc_82293EA4;
loc_82293E9C:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82293EA4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82293ec4
	if (ctx.cr6.eq) goto loc_82293EC4;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82293ec8
	if (!ctx.cr6.eq) goto loc_82293EC8;
loc_82293EC4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82293EC8:
	// lwz r3,860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// bl 0x821c8060
	ctx.lr = 0x82293ED0;
	sub_821C8060(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x821cd868
	ctx.lr = 0x82293ED8;
	sub_821CD868(ctx, base);
	// lhz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 164);
	// lhz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 140);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82293f30
	if (!ctx.cr6.eq) goto loc_82293F30;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82293f30
	if (ctx.cr6.eq) goto loc_82293F30;
	// lwz r11,4640(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4640);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293f30
	if (ctx.cr6.eq) goto loc_82293F30;
	// lwz r11,256(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 256);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82293f44
	if (!ctx.cr6.eq) goto loc_82293F44;
	// lis r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// ori r4,r4,32826
	ctx.r4.u64 = ctx.r4.u64 | 32826;
	// bl 0x82170288
	ctx.lr = 0x82293F18;
	sub_82170288(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82293f44
	if (ctx.cr6.eq) goto loc_82293F44;
	// lwz r11,216(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 216);
	// oris r10,r11,2048
	ctx.r10.u64 = ctx.r11.u64 | 134217728;
	// stw r10,216(r20)
	REX_STORE_U32(ctx.r20.u32 + 216, ctx.r10.u32);
	// b 0x82293f44
	goto loc_82293F44;
loc_82293F30:
	// lwz r11,216(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 216);
	// rlwinm r10,r11,0,5,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r10,216(r20)
	REX_STORE_U32(ctx.r20.u32 + 216, ctx.r10.u32);
	// b 0x82293f44
	goto loc_82293F44;
loc_82293F40:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82293F44:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82293f80
	if (ctx.cr6.lt) goto loc_82293F80;
	// lwz r9,80(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x82293f80
	if (ctx.cr6.gt) goto loc_82293F80;
	// lbz r11,74(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 74);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82293f78
	if (ctx.cr6.eq) goto loc_82293F78;
	// stb r19,168(r17)
	REX_STORE_U8(ctx.r17.u32 + 168, ctx.r19.u8);
	// b 0x82293f84
	goto loc_82293F84;
loc_82293F78:
	// stb r14,168(r17)
	REX_STORE_U8(ctx.r17.u32 + 168, ctx.r14.u8);
	// b 0x82293f84
	goto loc_82293F84;
loc_82293F80:
	// stb r30,168(r17)
	REX_STORE_U8(ctx.r17.u32 + 168, ctx.r30.u8);
loc_82293F84:
	// lwz r11,176(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 176);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82293fac
	if (ctx.cr6.eq) goto loc_82293FAC;
	// lbz r11,283(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 283);
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// beq cr6,0x82293fac
	if (ctx.cr6.eq) goto loc_82293FAC;
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// beq cr6,0x82293fac
	if (ctx.cr6.eq) goto loc_82293FAC;
	// cmplwi cr6,r11,31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 31, ctx.xer);
	// bne cr6,0x82293fcc
	if (!ctx.cr6.eq) goto loc_82293FCC;
loc_82293FAC:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,40(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x82293fd8
	if (ctx.cr6.gt) goto loc_82293FD8;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x82293fd8
	if (ctx.cr6.lt) goto loc_82293FD8;
loc_82293FCC:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// oris r10,r11,4
	ctx.r10.u64 = ctx.r11.u64 | 262144;
	// b 0x82293fe0
	goto loc_82293FE0;
loc_82293FD8:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,14,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFBFFFF;
loc_82293FE0:
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
	// lwz r10,264(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r11,196(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,44(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x82294070
	if (!ctx.cr6.eq) goto loc_82294070;
	// lwz r10,140(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 140);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x82294070
	if (!ctx.cr6.eq) goto loc_82294070;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82294070
	if (ctx.cr6.eq) goto loc_82294070;
	// lbz r11,302(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 302);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82294070
	if (ctx.cr6.eq) goto loc_82294070;
	// lbz r11,285(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 285);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82294064
	if (ctx.cr6.eq) goto loc_82294064;
	// lbz r11,283(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 283);
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// beq cr6,0x82294058
	if (ctx.cr6.eq) goto loc_82294058;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// beq cr6,0x82294058
	if (ctx.cr6.eq) goto loc_82294058;
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// beq cr6,0x82294058
	if (ctx.cr6.eq) goto loc_82294058;
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// beq cr6,0x82294058
	if (ctx.cr6.eq) goto loc_82294058;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82294064
	if (ctx.cr6.eq) goto loc_82294064;
loc_82294058:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// oris r10,r11,1
	ctx.r10.u64 = ctx.r11.u64 | 65536;
	// b 0x8229406c
	goto loc_8229406C;
loc_82294064:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// oris r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 131072;
loc_8229406C:
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
loc_82294070:
	// lwz r11,32(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822940a0
	if (ctx.cr6.eq) goto loc_822940A0;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,32(r20)
	REX_STORE_U32(ctx.r20.u32 + 32, ctx.r11.u32);
	// bge 0x8229408c
	if (!ctx.cr0.lt) goto loc_8229408C;
	// stw r30,32(r20)
	REX_STORE_U32(ctx.r20.u32 + 32, ctx.r30.u32);
loc_8229408C:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822940a0
	if (ctx.cr6.eq) goto loc_822940A0;
	// stw r30,32(r20)
	REX_STORE_U32(ctx.r20.u32 + 32, ctx.r30.u32);
loc_822940A0:
	// lwz r11,32(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 32);
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bgt cr6,0x822940c8
	if (ctx.cr6.gt) goto loc_822940C8;
	// lwz r11,28(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822940c8
	if (ctx.cr6.eq) goto loc_822940C8;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r20)
	REX_STORE_U32(ctx.r20.u32 + 28, ctx.r11.u32);
	// bge 0x822940c8
	if (!ctx.cr0.lt) goto loc_822940C8;
	// stw r30,28(r20)
	REX_STORE_U32(ctx.r20.u32 + 28, ctx.r30.u32);
loc_822940C8:
	// lwz r11,328(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 328);
	// rlwinm r10,r11,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822940e4
	if (ctx.cr6.eq) goto loc_822940E4;
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// ori r10,r11,4096
	ctx.r10.u64 = ctx.r11.u64 | 4096;
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
loc_822940E4:
	// lbz r11,299(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 299);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8229419c
	if (!ctx.cr6.eq) goto loc_8229419C;
	// lbz r10,300(r24)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r24.u32 + 300);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8229419c
	if (!ctx.cr6.eq) goto loc_8229419C;
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// rlwinm r9,r10,0,22,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x822942b0
	if (ctx.cr6.eq) goto loc_822942B0;
	// lwz r10,656(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 656);
	// lwz r11,1940(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1940);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// beq cr6,0x82294164
	if (ctx.cr6.eq) goto loc_82294164;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8229416c
	if (!ctx.cr6.eq) goto loc_8229416C;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8229416c
	if (!ctx.cr6.eq) goto loc_8229416C;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82294150
	if (!ctx.cr6.eq) goto loc_82294150;
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822942b0
	if (ctx.cr6.eq) goto loc_822942B0;
loc_82294150:
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r21,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r21.u32);
	// li r11,12329
	ctx.r11.s64 = 12329;
	// stb r10,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r10.u8);
	// b 0x822942ac
	goto loc_822942AC;
loc_82294164:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8229417c
	if (ctx.cr6.eq) goto loc_8229417C;
loc_8229416C:
	// li r11,4178
	ctx.r11.s64 = 4178;
	// stb r19,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r19.u8);
	// stw r18,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r18.u32);
	// b 0x822942ac
	goto loc_822942AC;
loc_8229417C:
	// rlwinm r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822942b0
	if (ctx.cr6.eq) goto loc_822942B0;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r21,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r21.u32);
	// li r11,12329
	ctx.r11.s64 = 12329;
	// stb r10,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r10.u8);
	// b 0x822942ac
	goto loc_822942AC;
loc_8229419C:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82294274
	if (ctx.cr6.eq) goto loc_82294274;
	// lbz r11,300(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 300);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82294274
	if (ctx.cr6.eq) goto loc_82294274;
	// lwz r11,1940(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1940);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822941d0
	if (ctx.cr6.eq) goto loc_822941D0;
	// li r11,16498
	ctx.r11.s64 = 16498;
	// stb r21,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r21.u8);
	// stw r18,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r18.u32);
	// b 0x822942ac
	goto loc_822942AC;
loc_822941D0:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82294214
	if (ctx.cr6.eq) goto loc_82294214;
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x82294200
	if (ctx.cr6.eq) goto loc_82294200;
	// lbz r11,550(r16)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r16.u32 + 550);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82294200
	if (!ctx.cr6.eq) goto loc_82294200;
	// li r11,20521
	ctx.r11.s64 = 20521;
	// stb r23,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r23.u8);
	// stw r21,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r21.u32);
	// b 0x822942ac
	goto loc_822942AC;
loc_82294200:
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r21,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r21.u32);
	// li r11,18474
	ctx.r11.s64 = 18474;
	// stb r10,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r10.u8);
	// b 0x822942ac
	goto loc_822942AC;
loc_82294214:
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82294264
	if (!ctx.cr6.eq) goto loc_82294264;
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82294264
	if (!ctx.cr6.eq) goto loc_82294264;
	// lwz r11,4(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// rlwinm r10,r11,0,27,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x18;
	// rlwinm r9,r11,0,23,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// stw r10,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r10.u32);
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x822942b0
	if (ctx.cr6.eq) goto loc_822942B0;
	// lwz r9,656(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 656);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x822942b0
	if (!ctx.cr6.eq) goto loc_822942B0;
	// rlwinm r10,r10,0,29,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFE7;
	// rlwinm r11,r11,0,29,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFE7;
	// stw r10,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r10.u32);
	// b 0x822942ac
	goto loc_822942AC;
loc_82294264:
	// li r10,11
	ctx.r10.s64 = 11;
	// li r11,22562
	ctx.r11.s64 = 22562;
	// stb r10,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r10.u8);
	// b 0x822942a8
	goto loc_822942A8;
loc_82294274:
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x822942a0
	if (ctx.cr6.eq) goto loc_822942A0;
	// lbz r11,550(r16)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r16.u32 + 550);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// blt cr6,0x822942a0
	if (ctx.cr6.lt) goto loc_822942A0;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x822942a0
	if (ctx.cr6.gt) goto loc_822942A0;
	// li r11,4178
	ctx.r11.s64 = 4178;
	// stb r19,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r19.u8);
	// stw r18,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r18.u32);
	// b 0x822942ac
	goto loc_822942AC;
loc_822942A0:
	// stb r22,283(r24)
	REX_STORE_U8(ctx.r24.u32 + 283, ctx.r22.u8);
	// li r11,10273
	ctx.r11.s64 = 10273;
loc_822942A8:
	// stw r30,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r30.u32);
loc_822942AC:
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
loc_822942B0:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822942d4
	if (ctx.cr6.eq) goto loc_822942D4;
	// lbz r11,283(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 283);
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// beq cr6,0x822942d4
	if (ctx.cr6.eq) goto loc_822942D4;
	// cmplwi cr6,r11,28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 28, ctx.xer);
	// bne cr6,0x822942e4
	if (!ctx.cr6.eq) goto loc_822942E4;
loc_822942D4:
	// lhz r11,12(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 12);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,16384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16384, ctx.xer);
	// blt cr6,0x822942ec
	if (ctx.cr6.lt) goto loc_822942EC;
loc_822942E4:
	// stw r30,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r30.u32);
	// b 0x822942f8
	goto loc_822942F8;
loc_822942EC:
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// rlwinm r10,r11,0,27,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x18;
	// stw r10,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r10.u32);
loc_822942F8:
	// lbz r11,551(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 551);
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// blt cr6,0x82294330
	if (ctx.cr6.lt) goto loc_82294330;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// bgt cr6,0x82294330
	if (ctx.cr6.gt) goto loc_82294330;
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// rlwinm r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82294330
	if (ctx.cr6.eq) goto loc_82294330;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// ori r10,r11,4
	ctx.r10.u64 = ctx.r11.u64 | 4;
	// stw r10,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r10.u32);
	// stw r10,272(r28)
	REX_STORE_U32(ctx.r28.u32 + 272, ctx.r10.u32);
loc_82294330:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82294350
	if (ctx.cr6.eq) goto loc_82294350;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822ab380
	ctx.lr = 0x8229434C;
	sub_822AB380(ctx, base);
	// b 0x822943f0
	goto loc_822943F0;
loc_82294350:
	// lwz r10,340(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 340);
	// rlwinm r9,r10,0,5,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x822943f0
	if (!ctx.cr6.eq) goto loc_822943F0;
	// rlwinm r11,r11,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822943b0
	if (ctx.cr6.eq) goto loc_822943B0;
	// lwz r11,160(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822943b0
	if (!ctx.cr6.eq) goto loc_822943B0;
	// lbz r11,289(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 289);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822943b0
	if (!ctx.cr6.eq) goto loc_822943B0;
	// bl 0x822cd3c8
	ctx.lr = 0x82294388;
	sub_822CD3C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822943b0
	if (ctx.cr6.eq) goto loc_822943B0;
	// lwz r11,148(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 148);
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x822943ac
	if (!ctx.cr6.lt) goto loc_822943AC;
	// bl 0x822ab380
	ctx.lr = 0x822943A8;
	sub_822AB380(ctx, base);
	// b 0x822943b0
	goto loc_822943B0;
loc_822943AC:
	// bl 0x822ab2a8
	ctx.lr = 0x822943B0;
	sub_822AB2A8(ctx, base);
loc_822943B0:
	// lwz r11,160(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822943f0
	if (ctx.cr6.eq) goto loc_822943F0;
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,196(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r9,76(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// cmpwi cr6,r8,8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 8, ctx.xer);
	// ble cr6,0x822943f0
	if (!ctx.cr6.gt) goto loc_822943F0;
	// lbz r3,72(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 72);
	// bl 0x82193f58
	ctx.lr = 0x822943DC;
	sub_82193F58(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x822943f0
	if (!ctx.cr6.eq) goto loc_822943F0;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822ab310
	ctx.lr = 0x822943F0;
	sub_822AB310(ctx, base);
loc_822943F0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822ab490
	ctx.lr = 0x822943F8;
	sub_822AB490(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822ab9a8
	ctx.lr = 0x82294400;
	sub_822AB9A8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822abf00
	ctx.lr = 0x82294408;
	sub_822ABF00(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822ab840
	ctx.lr = 0x82294410;
	sub_822AB840(ctx, base);
	// addi r3,r28,3088
	ctx.r3.s64 = ctx.r28.s64 + 3088;
	// bl 0x8242b700
	ctx.lr = 0x82294418;
	sub_8242B700(ctx, base);
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82294468
	if (!ctx.cr6.eq) goto loc_82294468;
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// beq cr6,0x82294440
	if (ctx.cr6.eq) goto loc_82294440;
	// lwz r11,908(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 908);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82294468
	if (!ctx.cr6.eq) goto loc_82294468;
loc_82294440:
	// lwz r11,44(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 44);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8229446c
	if (ctx.cr6.eq) goto loc_8229446C;
	// lwz r11,168(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 168);
	// rlwinm r10,r11,0,29,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFE7;
	// stw r10,168(r24)
	REX_STORE_U32(ctx.r24.u32 + 168, ctx.r10.u32);
	// lwz r9,44(r20)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r20.u32 + 44);
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r20)
	REX_STORE_U32(ctx.r20.u32 + 44, ctx.r11.u32);
	// bge 0x8229446c
	if (!ctx.cr0.lt) goto loc_8229446C;
loc_82294468:
	// stw r30,44(r20)
	REX_STORE_U32(ctx.r20.u32 + 44, ctx.r30.u32);
loc_8229446C:
	// lwz r11,48(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82294488
	if (ctx.cr6.eq) goto loc_82294488;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,48(r20)
	REX_STORE_U32(ctx.r20.u32 + 48, ctx.r11.u32);
	// bge 0x82294488
	if (!ctx.cr0.lt) goto loc_82294488;
	// stw r30,48(r20)
	REX_STORE_U32(ctx.r20.u32 + 48, ctx.r30.u32);
loc_82294488:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8229449c
	if (ctx.cr6.eq) goto loc_8229449C;
	// stw r30,56(r20)
	REX_STORE_U32(ctx.r20.u32 + 56, ctx.r30.u32);
loc_8229449C:
	// lwz r11,56(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x822944b4
	if (!ctx.cr6.gt) goto loc_822944B4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,56(r20)
	REX_STORE_U32(ctx.r20.u32 + 56, ctx.r11.u32);
	// b 0x822944b8
	goto loc_822944B8;
loc_822944B4:
	// stw r30,56(r20)
	REX_STORE_U32(ctx.r20.u32 + 56, ctx.r30.u32);
loc_822944B8:
	// lwz r11,56(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822944c8
	if (!ctx.cr6.eq) goto loc_822944C8;
	// stw r30,52(r20)
	REX_STORE_U32(ctx.r20.u32 + 52, ctx.r30.u32);
loc_822944C8:
	// lwz r11,640(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 640);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82294564
	if (ctx.cr6.eq) goto loc_82294564;
	// lhz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r17.u32 + 164);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82294564
	if (ctx.cr6.eq) goto loc_82294564;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82170670
	ctx.lr = 0x822944EC;
	sub_82170670(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,72(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x82170670
	ctx.lr = 0x82294504;
	sub_82170670(ctx, base);
	// lfs f12,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r15
	ctx.r4.u64 = ctx.r15.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,1808(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 1808);
	// bl 0x82261270
	ctx.lr = 0x8229451C;
	sub_82261270(ctx, base);
	// mr r5,r15
	ctx.r5.u64 = ctx.r15.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x822618b8
	ctx.lr = 0x8229452C;
	sub_822618B8(ctx, base);
	// bl 0x82170cb0
	ctx.lr = 0x82294530;
	sub_82170CB0(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,884(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 884);
	// bl 0x822753d8
	ctx.lr = 0x8229453C;
	sub_822753D8(ctx, base);
	// lwz r11,204(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 204);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82294564
	if (ctx.cr6.eq) goto loc_82294564;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82294554
	if (!ctx.cr6.eq) goto loc_82294554;
	// li r11,40
	ctx.r11.s64 = 40;
loc_82294554:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822c7d68
	ctx.lr = 0x82294564;
	sub_822C7D68(ctx, base);
loc_82294564:
	// lwz r11,120(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82294584
	if (!ctx.cr6.eq) goto loc_82294584;
	// addi r3,r28,2800
	ctx.r3.s64 = ctx.r28.s64 + 2800;
	// lfs f3,28(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,24(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 24);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,20(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b71b8
	ctx.lr = 0x82294584;
	sub_822B71B8(ctx, base);
loc_82294584:
	// lwz r10,264(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x822945c0
	if (ctx.cr6.eq) goto loc_822945C0;
	// lwz r11,196(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r8,220(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 220);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x822945b8
	if (ctx.cr6.lt) goto loc_822945B8;
	// lhz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 24);
	// cmplwi cr6,r11,32769
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32769, ctx.xer);
	// beq cr6,0x82294654
	if (ctx.cr6.eq) goto loc_82294654;
	// cmplwi cr6,r11,32770
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32770, ctx.xer);
	// beq cr6,0x82294654
	if (ctx.cr6.eq) goto loc_82294654;
loc_822945B8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8229465c
	if (!ctx.cr6.eq) goto loc_8229465C;
loc_822945C0:
	// lbz r11,285(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 285);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822945f0
	if (!ctx.cr6.eq) goto loc_822945F0;
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r8,r11,0,13,13
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x822945f0
	if (!ctx.cr6.eq) goto loc_822945F0;
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// rlwinm r8,r11,0,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FC;
	// rlwinm r8,r8,0,29,21
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFC07;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82294654
	if (ctx.cr6.eq) goto loc_82294654;
loc_822945F0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8229465c
	if (!ctx.cr6.eq) goto loc_8229465C;
	// lbz r11,285(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 285);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82294628
	if (ctx.cr6.eq) goto loc_82294628;
	// lwz r11,196(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 196);
	// lwz r8,220(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 220);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x82294628
	if (ctx.cr6.lt) goto loc_82294628;
	// lhz r11,24(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 24);
	// cmplwi cr6,r11,32769
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32769, ctx.xer);
	// beq cr6,0x82294654
	if (ctx.cr6.eq) goto loc_82294654;
	// cmplwi cr6,r11,32770
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32770, ctx.xer);
	// beq cr6,0x82294654
	if (ctx.cr6.eq) goto loc_82294654;
loc_82294628:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8229465c
	if (!ctx.cr6.eq) goto loc_8229465C;
	// lbz r11,285(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 285);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229465c
	if (ctx.cr6.eq) goto loc_8229465C;
	// lbz r11,299(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 299);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82294654
	if (!ctx.cr6.eq) goto loc_82294654;
	// lbz r11,300(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 300);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229465c
	if (ctx.cr6.eq) goto loc_8229465C;
loc_82294654:
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// b 0x82294660
	goto loc_82294660;
loc_8229465C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82294660:
	// lwz r10,164(r17)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwimi r10,r11,7,24,24
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0x80) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF7F);
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
	// lwz r11,252(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 252);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x822946ac
	if (ctx.cr6.eq) goto loc_822946AC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82294688
	if (!ctx.cr6.eq) goto loc_82294688;
	// stw r14,640(r28)
	REX_STORE_U32(ctx.r28.u32 + 640, ctx.r14.u32);
	// b 0x822946ac
	goto loc_822946AC;
loc_82294688:
	// bl 0x8238e3b8
	ctx.lr = 0x8229468C;
	sub_8238E3B8(ctx, base);
	// lwz r11,252(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 252);
	// lwz r10,320(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 320);
	// divwu r9,r10,r11
	ctx.r9.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// subf r7,r8,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addic r6,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r6.s64 = ctx.r7.s64 + -1;
	// subfe r5,r6,r7
	temp.u8 = (~ctx.r6.u32 + ctx.r7.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,640(r28)
	REX_STORE_U32(ctx.r28.u32 + 640, ctx.r5.u32);
loc_822946AC:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// lis r31,20
	ctx.r31.s64 = 1310720;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwimi r10,r11,31,21,21
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x400) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFBFF);
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r29,96(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 96);
	// lwz r30,100(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822946f0
	if (ctx.cr6.eq) goto loc_822946F0;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,20(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822946f0
	if (!ctx.cr6.eq) goto loc_822946F0;
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x822946f8
	goto loc_822946F8;
loc_822946F0:
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_822946F8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82294718
	if (ctx.cr6.eq) goto loc_82294718;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8229471c
	if (!ctx.cr6.eq) goto loc_8229471C;
loc_82294718:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8229471C:
	// lwz r3,860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// lwz r4,76(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 76);
	// bl 0x821c8480
	ctx.lr = 0x82294728;
	sub_821C8480(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8229474c
	if (ctx.cr6.eq) goto loc_8229474C;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8229474c
	if (!ctx.cr6.gt) goto loc_8229474C;
	// li r10,100
	ctx.r10.s64 = 100;
	// addi r9,r11,11
	ctx.r9.s64 = ctx.r11.s64 + 11;
	// divwu r8,r30,r10
	ctx.r8.u64 = uint32_t(ctx.r10.u32 ? ctx.r30.u32 / ctx.r10.u32 : 0);
	// mullw r31,r8,r9
	ctx.r31.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
loc_8229474C:
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x8229475c
	if (ctx.cr6.gt) goto loc_8229475C;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82294784
	if (!ctx.cr6.eq) goto loc_82294784;
loc_8229475C:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82294784
	if (!ctx.cr6.eq) goto loc_82294784;
	// lwz r10,108(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82294784
	if (!ctx.cr6.eq) goto loc_82294784;
	// rlwinm r11,r11,0,21,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// stw r11,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r11.u32);
	// b 0x82294790
	goto loc_82294790;
loc_82294784:
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// ori r10,r11,2048
	ctx.r10.u64 = ctx.r11.u64 | 2048;
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
loc_82294790:
	// lwz r11,88(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 88);
	// cmplwi cr6,r11,39
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 39, ctx.xer);
	// bne cr6,0x822947a8
	if (!ctx.cr6.eq) goto loc_822947A8;
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,21,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
loc_822947A8:
	// lwz r11,120(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 120);
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// bne cr6,0x82294824
	if (!ctx.cr6.eq) goto loc_82294824;
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822947d4
	if (ctx.cr6.eq) goto loc_822947D4;
	// lwz r10,20(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// beq cr6,0x822947d8
	if (ctx.cr6.eq) goto loc_822947D8;
loc_822947D4:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_822947D8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822947f8
	if (ctx.cr6.eq) goto loc_822947F8;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x822947fc
	if (!ctx.cr6.eq) goto loc_822947FC;
loc_822947F8:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_822947FC:
	// lwz r3,860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// bl 0x821c8060
	ctx.lr = 0x82294804;
	sub_821C8060(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x821cd868
	ctx.lr = 0x8229480C;
	sub_821CD868(ctx, base);
	// lbz r11,4608(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4608);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82294824
	if (!ctx.cr6.eq) goto loc_82294824;
	// lwz r11,164(r17)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r17.u32 + 164);
	// rlwinm r10,r11,0,21,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF7FF;
	// stw r10,164(r17)
	REX_STORE_U32(ctx.r17.u32 + 164, ctx.r10.u32);
loc_82294824:
	// lwz r11,96(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82294880
	if (ctx.cr6.gt) goto loc_82294880;
	// lwz r11,1824(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1824);
	// lwz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r10,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// stw r9,1824(r28)
	REX_STORE_U32(ctx.r28.u32 + 1824, ctx.r9.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82294890
	if (ctx.cr6.eq) goto loc_82294890;
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwz r10,448(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 448);
	// lhz r9,24(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 24);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82294890
	if (!ctx.cr6.eq) goto loc_82294890;
	// lwz r11,596(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 596);
	// rlwinm r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82294890
	if (!ctx.cr6.eq) goto loc_82294890;
	// lwz r11,1828(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 1828);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,1828(r28)
	REX_STORE_U32(ctx.r28.u32 + 1828, ctx.r11.u32);
	// b 0x82294894
	goto loc_82294894;
loc_82294880:
	// bl 0x822d1688
	ctx.lr = 0x82294884;
	sub_822D1688(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82294894
	if (ctx.cr6.eq) goto loc_82294894;
	// stw r25,1824(r28)
	REX_STORE_U32(ctx.r28.u32 + 1824, ctx.r25.u32);
loc_82294890:
	// stw r25,1828(r28)
	REX_STORE_U32(ctx.r28.u32 + 1828, ctx.r25.u32);
loc_82294894:
	// lwz r11,2924(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 2924);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822948a8
	if (ctx.cr6.eq) goto loc_822948A8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822b3998
	ctx.lr = 0x822948A8;
	sub_822B3998(ctx, base);
loc_822948A8:
	// lwz r3,156(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 156);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x822948b8
	if (ctx.cr6.eq) goto loc_822948B8;
	// bl 0x822922e0
	ctx.lr = 0x822948B8;
	sub_822922E0(ctx, base);
loc_822948B8:
	// lwz r3,160(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 160);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x822948d4
	if (ctx.cr6.eq) goto loc_822948D4;
	// lwz r11,164(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822948d4
	if (ctx.cr6.eq) goto loc_822948D4;
	// bl 0x822922e0
	ctx.lr = 0x822948D4;
	sub_822922E0(ctx, base);
loc_822948D4:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x826a0d60
	ctx.lr = 0x822948E0;
	__restfpr_27(ctx, base);
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8238FE18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x8238FE20;
	__savegprlr_28(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,20
	ctx.r11.s64 = 20;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r10,r1,72
	ctx.r10.s64 = ctx.r1.s64 + 72;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8238FE38:
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x8238fe38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238FE38;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x8238fe68
	if (!ctx.cr6.gt) goto loc_8238FE68;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// addi r11,r6,-4
	ctx.r11.s64 = ctx.r6.s64 + -4;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8238FE58:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r7.u32);
	// bdnz 0x8238fe58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238FE58;
loc_8238FE68:
	// cmpwi cr6,r8,40
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 40, ctx.xer);
	// beq cr6,0x8238fe7c
	if (ctx.cr6.eq) goto loc_8238FE7C;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stwx r28,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u32);
loc_8238FE7C:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x8238fef8
	if (!ctx.cr6.gt) goto loc_8238FEF8;
	// addi r29,r4,-4
	ctx.r29.s64 = ctx.r4.s64 + -4;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
loc_8238FE8C:
	// li r10,40
	ctx.r10.s64 = 40;
	// addi r9,r1,236
	ctx.r9.s64 = ctx.r1.s64 + 236;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8238FEA4:
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8238feb8
	if (ctx.cr6.eq) goto loc_8238FEB8;
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
loc_8238FEB8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bdnz 0x8238fea4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238FEA4;
	// bl 0x826a0da8
	ctx.lr = 0x8238FEC8;
	sub_826A0DA8(ctx, base);
	// divw r10,r3,r31
	ctx.r10.u64 = uint32_t((ctx.r31.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r31.s32 == -1)) ? ctx.r3.s32 / ctx.r31.s32 : 0);
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// mullw r8,r10,r31
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// subf r7,r8,r3
	ctx.r7.u64 = ctx.r3.u64 - ctx.r8.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwzx r5,r6,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwu r5,4(r29)
	ea = 4 + ctx.r29.u32;
	REX_STORE_U32(ea, ctx.r5.u32);
	ctx.r29.u32 = ea;
	// stwx r28,r4,r9
	REX_STORE_U32(ctx.r4.u32 + ctx.r9.u32, ctx.r28.u32);
	// bne 0x8238fe8c
	if (!ctx.cr0.eq) goto loc_8238FE8C;
loc_8238FEF8:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823949C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x823949C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r11,23664
	ctx.r31.s64 = ctx.r11.s64 + 23664;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823949f8
	if (ctx.cr6.eq) goto loc_823949F8;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823949fc
	if (ctx.cr6.eq) goto loc_823949FC;
loc_823949F8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823949FC:
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r8,30048(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// beq cr6,0x82394a24
	if (ctx.cr6.eq) goto loc_82394A24;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 & ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82394a28
	if (!ctx.cr6.eq) goto loc_82394A28;
loc_82394A24:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82394A28:
	// lwz r3,896(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82394a44
	if (ctx.cr6.eq) goto loc_82394A44;
	// bl 0x82364538
	ctx.lr = 0x82394A38;
	sub_82364538(ctx, base);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,30048(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
loc_82394A44:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82394a5c
	if (ctx.cr6.eq) goto loc_82394A5C;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82394a60
	if (ctx.cr6.eq) goto loc_82394A60;
loc_82394A5C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82394A60:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82394a7c
	if (ctx.cr6.eq) goto loc_82394A7C;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 & ctx.r8.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82394a80
	if (!ctx.cr6.eq) goto loc_82394A80;
loc_82394A7C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82394A80:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,908(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 908);
	// bl 0x8238d6f8
	ctx.lr = 0x82394A8C;
	sub_8238D6F8(ctx, base);
	// lwz r5,616(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 616);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82394b78
	if (ctx.cr6.eq) goto loc_82394B78;
	// lwz r4,484(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 484);
	// bl 0x82223780
	ctx.lr = 0x82394AA4;
	sub_82223780(ctx, base);
	// addi r3,r30,464
	ctx.r3.s64 = ctx.r30.s64 + 464;
	// bl 0x82432268
	ctx.lr = 0x82394AAC;
	sub_82432268(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82394acc
	if (ctx.cr6.eq) goto loc_82394ACC;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82394ad0
	if (ctx.cr6.eq) goto loc_82394AD0;
loc_82394ACC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82394AD0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82394af0
	if (ctx.cr6.eq) goto loc_82394AF0;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82394af4
	if (!ctx.cr6.eq) goto loc_82394AF4;
loc_82394AF0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82394AF4:
	// lwz r3,900(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 900);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82394b04
	if (ctx.cr6.eq) goto loc_82394B04;
	// bl 0x8236f330
	ctx.lr = 0x82394B04;
	sub_8236F330(ctx, base);
loc_82394B04:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x822f3710
	ctx.lr = 0x82394B0C;
	sub_822F3710(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82394b2c
	if (ctx.cr6.eq) goto loc_82394B2C;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82394b30
	if (ctx.cr6.eq) goto loc_82394B30;
loc_82394B2C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82394B30:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82394b84
	if (ctx.cr6.eq) goto loc_82394B84;
	// lwz r10,60(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r11,30048(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82394b84
	if (ctx.cr6.eq) goto loc_82394B84;
	// bl 0x82170cb0
	ctx.lr = 0x82394B54;
	sub_82170CB0(ctx, base);
	// lwz r11,1032(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1032);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82394b84
	if (ctx.cr6.eq) goto loc_82394B84;
	// bl 0x82170cb0
	ctx.lr = 0x82394B64;
	sub_82170CB0(ctx, base);
	// lwz r3,1032(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 1032);
	// bl 0x82301d88
	ctx.lr = 0x82394B6C;
	sub_82301D88(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82394B78:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,34
	ctx.r4.s64 = 34;
	// bl 0x82223780
	ctx.lr = 0x82394B84;
	sub_82223780(ctx, base);
loc_82394B84:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8239D790) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r4,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// addi r30,r3,32
	ctx.r30.s64 = ctx.r3.s64 + 32;
	// addi r10,r11,-9592
	ctx.r10.s64 = ctx.r11.s64 + -9592;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x8236bd28
	ctx.lr = 0x8239D7C4;
	sub_8236BD28(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// addi r7,r9,-9788
	ctx.r7.s64 = ctx.r9.s64 + -9788;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r8,-9536
	ctx.r5.s64 = ctx.r8.s64 + -9536;
	// stw r7,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r7.u32);
	// stw r6,2128(r31)
	REX_STORE_U32(ctx.r31.u32 + 2128, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mulli r10,r11,28
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(28));
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,255
	ctx.r6.s64 = 255;
	// li r4,0
	ctx.r4.s64 = 0;
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// bl 0x8236b2a0
	ctx.lr = 0x8239D808;
	sub_8236B2A0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82228870
	ctx.lr = 0x8239D810;
	sub_82228870(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r6,r9,-9880
	ctx.r6.s64 = ctx.r9.s64 + -9880;
	// li r5,100
	ctx.r5.s64 = 100;
	// bl 0x823689e0
	ctx.lr = 0x8239D828;
	sub_823689E0(ctx, base);
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,116(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 116);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8239D840;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,255
	ctx.r7.s64 = 255;
	// li r6,128
	ctx.r6.s64 = 128;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8239D868;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823A1320) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32171
	ctx.r10.s64 = -2108358656;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,472
	ctx.r8.s64 = ctx.r10.s64 + 472;
	// addi r6,r9,-9169
	ctx.r6.s64 = ctx.r9.s64 + -9169;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r3,96
	ctx.r3.s64 = ctx.r3.s64 + 96;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x823A1360;
	sub_822518D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823A3828) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x823a386c
	if (!ctx.cr6.eq) goto loc_823A386C;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x823a386c
	if (!ctx.cr6.eq) goto loc_823A386C;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x823a386c
	if (!ctx.cr6.eq) goto loc_823A386C;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823a3870
	if (ctx.cr6.eq) goto loc_823A3870;
loc_823A386C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823A3870:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823A57F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a5870
	if (ctx.cr6.eq) goto loc_823A5870;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268170
	ctx.lr = 0x823A5820;
	sub_82268170(ctx, base);
	// rlwinm r11,r3,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a5834
	if (ctx.cr6.eq) goto loc_823A5834;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823a586c
	goto loc_823A586C;
loc_823A5834:
	// rlwinm r11,r3,0,8,8
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x800000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a5848
	if (ctx.cr6.eq) goto loc_823A5848;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x823a586c
	goto loc_823A586C;
loc_823A5848:
	// rlwinm r11,r3,0,10,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a585c
	if (ctx.cr6.eq) goto loc_823A585C;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x823a586c
	goto loc_823A586C;
loc_823A585C:
	// rlwinm r11,r3,0,9,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a5870
	if (ctx.cr6.eq) goto loc_823A5870;
	// li r11,3
	ctx.r11.s64 = 3;
loc_823A586C:
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_823A5870:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823A8640) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x823A8648;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x823a8480
	ctx.lr = 0x823A8658;
	sub_823A8480(ctx, base);
	// bl 0x8248b028
	ctx.lr = 0x823A865C;
	sub_8248B028(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x8238d810
	ctx.lr = 0x823A8664;
	sub_8238D810(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,26488
	ctx.r4.s64 = ctx.r11.s64 + 26488;
	// bl 0x8249f680
	ctx.lr = 0x823A8674;
	sub_8249F680(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8249f408
	ctx.lr = 0x823A8680;
	sub_8249F408(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8249f700
	ctx.lr = 0x823A868C;
	sub_8249F700(ctx, base);
	// mulli r11,r30,30
	ctx.r11.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(30));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,201
	ctx.r11.s64 = ctx.r11.s64 + 201;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823AA3B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x822237e0
	ctx.lr = 0x823AA3D4;
	sub_822237E0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x822680f8
	ctx.lr = 0x823AA3DC;
	sub_822680F8(ctx, base);
	// rlwinm r11,r3,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823aa430
	if (ctx.cr6.eq) goto loc_823AA430;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x822680f8
	ctx.lr = 0x823AA3F0;
	sub_822680F8(ctx, base);
	// rlwinm r11,r3,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823aa430
	if (ctx.cr6.eq) goto loc_823AA430;
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,-30472
	ctx.r8.s64 = ctx.r10.s64 + -30472;
	// addi r6,r9,-5924
	ctx.r6.s64 = ctx.r9.s64 + -5924;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r31,96
	ctx.r3.s64 = ctx.r31.s64 + 96;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x823AA430;
	sub_822518D8(ctx, base);
loc_823AA430:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823B13B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x823B13B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,152
	ctx.r30.s64 = ctx.r3.s64 + 152;
	// li r31,1
	ctx.r31.s64 = 1;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
loc_823B13C8:
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823b13e8
	if (ctx.cr6.eq) goto loc_823B13E8;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823b13ec
	if (ctx.cr6.eq) goto loc_823B13EC;
loc_823B13E8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823B13EC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823b140c
	if (ctx.cr6.eq) goto loc_823B140C;
	// lwz r10,60(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r11,30048(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x823b1410
	if (!ctx.cr6.eq) goto loc_823B1410;
loc_823B140C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823B1410:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x822e88f8
	ctx.lr = 0x823B141C;
	sub_822E88F8(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,25
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 25, ctx.xer);
	// blt cr6,0x823b13c8
	if (ctx.cr6.lt) goto loc_823B13C8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823B43B8) {
	REX_FUNC_PROLOGUE();
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823B4450) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,356(r3)
	REX_STORE_U32(ctx.r3.u32 + 356, ctx.r11.u32);
	// stw r10,360(r3)
	REX_STORE_U32(ctx.r3.u32 + 360, ctx.r10.u32);
	// stw r11,352(r3)
	REX_STORE_U32(ctx.r3.u32 + 352, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823B4870) {
	REX_FUNC_PROLOGUE();
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823B4A80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,280(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 280);
	// lbz r10,276(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 276);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823b4b1c
	if (ctx.cr6.eq) goto loc_823B4B1C;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823b4ac4
	if (ctx.cr6.eq) goto loc_823B4AC4;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823b4ac8
	if (ctx.cr6.eq) goto loc_823B4AC8;
loc_823B4AC4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823B4AC8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823b4aec
	if (ctx.cr6.eq) goto loc_823B4AEC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r9,60(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r11,30048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x823b4af0
	if (!ctx.cr6.eq) goto loc_823B4AF0;
loc_823B4AEC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823B4AF0:
	// lwz r3,848(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 848);
	// bl 0x82223748
	ctx.lr = 0x823B4AF8;
	sub_82223748(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823b4b1c
	if (ctx.cr6.eq) goto loc_823B4B1C;
	// bl 0x82170cb0
	ctx.lr = 0x823B4B04;
	sub_82170CB0(ctx, base);
	// lwz r3,848(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 848);
	// bl 0x82222380
	ctx.lr = 0x823B4B0C;
	sub_82222380(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,588(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 588);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B4B1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823B4B1C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823B8C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r4,255
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 255, ctx.xer);
	// bge cr6,0x823b8d24
	if (!ctx.cr6.lt) goto loc_823B8D24;
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823b8cc0
	if (ctx.cr6.eq) goto loc_823B8CC0;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823b8cc4
	if (ctx.cr6.eq) goto loc_823B8CC4;
loc_823B8CC0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823B8CC4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823b8d24
	if (ctx.cr6.eq) goto loc_823B8D24;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x823b8d24
	if (ctx.cr6.eq) goto loc_823B8D24;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823b8d24
	if (ctx.cr6.eq) goto loc_823B8D24;
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8243fa70
	ctx.lr = 0x823B8CFC;
	sub_8243FA70(ctx, base);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,92(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// lfs f0,-4812(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4812);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// bl 0x8254acc0
	ctx.lr = 0x823B8D24;
	sub_8254ACC0(ctx, base);
loc_823B8D24:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823BBEE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x823BBEF0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8128(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8128);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r3,8128
	ctx.r30.s64 = ctx.r3.s64 + 8128;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x823bbfc4
	if (ctx.cr6.eq) goto loc_823BBFC4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x824bd630
	ctx.lr = 0x823BBF10;
	sub_824BD630(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// std r29,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r29.u64);
	// std r29,8(r30)
	REX_STORE_U64(ctx.r30.u32 + 8, ctx.r29.u64);
	// std r29,16(r30)
	REX_STORE_U64(ctx.r30.u32 + 16, ctx.r29.u64);
	// stw r29,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r29.u32);
	// lwz r11,8392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8392);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x823bbfc4
	if (ctx.cr6.gt) goto loc_823BBFC4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x823bbfd0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823BBFD0;
	// bdzf 4*cr6+eq,0x823bc014
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823BC014;
	// bdzf 4*cr6+eq,0x823bc050
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823BC050;
	// bdzf 4*cr6+eq,0x823bc0c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823BC0C0;
	// bdzf 4*cr6+eq,0x823bc0e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823BC0E0;
	// bdzf 4*cr6+eq,0x823bc108
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823BC108;
	// bne cr6,0x823bc128
	if (!ctx.cr6.eq) goto loc_823BC128;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8312(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8312);
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r4,r4,32778
	ctx.r4.u64 = ctx.r4.u64 | 32778;
	// bl 0x824bd800
	ctx.lr = 0x823BBF6C;
	sub_824BD800(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r8,r31,8328
	ctx.r8.s64 = ctx.r31.s64 + 8328;
	// std r29,8320(r31)
	REX_STORE_U64(ctx.r31.u32 + 8320, ctx.r29.u64);
	// addi r7,r31,8320
	ctx.r7.s64 = ctx.r31.s64 + 8320;
	// addi r11,r8,-8
	ctx.r11.s64 = ctx.r8.s64 + -8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_823BBF84:
	// stdu r29,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r29.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x823bbf84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823BBF84;
	// stw r29,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// addi r10,r31,8316
	ctx.r10.s64 = ctx.r31.s64 + 8316;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lwz r4,8312(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8312);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82581458
	ctx.lr = 0x823BBFAC;
	sub_82581458(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823bbfbc
	if (ctx.cr6.eq) goto loc_823BBFBC;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x823bc114
	if (!ctx.cr6.eq) goto loc_823BC114;
loc_823BBFBC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r11.u32);
loc_823BBFC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_823BBFD0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823bc114
	if (!ctx.cr6.eq) goto loc_823BC114;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r3,8316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8316);
	// addi r6,r31,8388
	ctx.r6.s64 = ctx.r31.s64 + 8388;
	// addi r5,r31,8312
	ctx.r5.s64 = ctx.r31.s64 + 8312;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x825816b8
	ctx.lr = 0x823BBFF0;
	sub_825816B8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823bc000
	if (ctx.cr6.eq) goto loc_823BC000;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x823bc0f4
	if (!ctx.cr6.eq) goto loc_823BC0F4;
loc_823BC000:
	// li r11,3
	ctx.r11.s64 = 3;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_823BC014:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823bc0f4
	if (!ctx.cr6.eq) goto loc_823BC0F4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,8316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8316);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82581a48
	ctx.lr = 0x823BC02C;
	sub_82581A48(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823bc03c
	if (ctx.cr6.eq) goto loc_823BC03C;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x823bc0cc
	if (!ctx.cr6.eq) goto loc_823BC0CC;
loc_823BC03C:
	// li r11,4
	ctx.r11.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_823BC050:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823bc0cc
	if (!ctx.cr6.eq) goto loc_823BC0CC;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lwz r9,8296(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8296);
	// addi r8,r31,8292
	ctx.r8.s64 = ctx.r31.s64 + 8292;
	// lwz r4,8300(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8300);
	// addi r7,r31,8156
	ctx.r7.s64 = ctx.r31.s64 + 8156;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,7320
	ctx.r5.s64 = ctx.r31.s64 + 7320;
	// bl 0x824bd940
	ctx.lr = 0x823BC078;
	sub_824BD940(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// stw r11,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r11.u32);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// addi r11,r10,-1232
	ctx.r11.s64 = ctx.r10.s64 + -1232;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r8,r9,-16000
	ctx.r8.s64 = ctx.r9.s64 + -16000;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x823BC0B4;
	sub_822518D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_823BC0C0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,8316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8316);
	// bl 0x82581ae8
	ctx.lr = 0x823BC0CC;
	sub_82581AE8(ctx, base);
loc_823BC0CC:
	// li r11,6
	ctx.r11.s64 = 6;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_823BC0E0:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r3,8316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8316);
	// addi r5,r31,8312
	ctx.r5.s64 = ctx.r31.s64 + 8312;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82581818
	ctx.lr = 0x823BC0F4;
	sub_82581818(ctx, base);
loc_823BC0F4:
	// li r11,7
	ctx.r11.s64 = 7;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_823BC108:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,8316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8316);
	// bl 0x82581608
	ctx.lr = 0x823BC114;
	sub_82581608(ctx, base);
loc_823BC114:
	// li r11,8
	ctx.r11.s64 = 8;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_823BC128:
	// lwz r3,8316(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8316);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x823bc140
	if (ctx.cr6.eq) goto loc_823BC140;
	// bl 0x824bd270
	ctx.lr = 0x823BC138;
	sub_824BD270(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,8316(r31)
	REX_STORE_U32(ctx.r31.u32 + 8316, ctx.r11.u32);
loc_823BC140:
	// stw r29,8392(r31)
	REX_STORE_U32(ctx.r31.u32 + 8392, ctx.r29.u32);
	// lis r11,-32196
	ctx.r11.s64 = -2109997056;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r9,r11,-17272
	ctx.r9.s64 = ctx.r11.s64 + -17272;
	// stw r29,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r6,r10,-1232
	ctx.r6.s64 = ctx.r10.s64 + -1232;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x823BC174;
	sub_822518D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CAC60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r3,88
	ctx.r3.s64 = ctx.r3.s64 + 88;
	// bl 0x82475350
	ctx.lr = 0x823CAC74;
	sub_82475350(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823CBB50) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,160(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823cbb74
	if (ctx.cr6.eq) goto loc_823CBB74;
	// lwz r9,164(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x823cbb78
	if (ctx.cr6.eq) goto loc_823CBB78;
loc_823CBB74:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823CBB78:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823cbb9c
	if (ctx.cr6.eq) goto loc_823CBB9C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,60(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r11,30048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_823CBB9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823CD358) {
	REX_FUNC_PROLOGUE();
	// lwz r11,260(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 260);
	// li r5,176
	ctx.r5.s64 = 176;
	// lwz r10,256(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 256);
	// addi r8,r3,244
	ctx.r8.s64 = ctx.r3.s64 + 244;
	// li r7,0
	ctx.r7.s64 = 0;
	// subf r9,r10,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw. r6,r9,r5
	ctx.r6.u64 = uint32_t((ctx.r5.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r5.s32 == -1)) ? ctx.r9.s32 / ctx.r5.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x823cd3fc
	if (ctx.cr0.eq) goto loc_823CD3FC;
	// li r6,0
	ctx.r6.s64 = 0;
loc_823CD37C:
	// lwz r11,12(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r10,16(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r3,r9,r5
	ctx.r3.u64 = uint32_t((ctx.r5.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r5.s32 == -1)) ? ctx.r9.s32 / ctx.r5.s32 : 0);
	// cmplw cr6,r7,r3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x823cd398
	if (ctx.cr6.lt) goto loc_823CD398;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823CD398:
	// add r10,r6,r11
	ctx.r10.u64 = ctx.r6.u64 + ctx.r11.u64;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_823CD3A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r3,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r3.u64;
	// beq cr6,0x823cd3c4
	if (ctx.cr6.eq) goto loc_823CD3C4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x823cd3a0
	if (ctx.cr6.eq) goto loc_823CD3A0;
loc_823CD3C4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x823cd3f4
	if (ctx.cr6.eq) goto loc_823CD3F4;
	// lwz r11,16(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r10,12(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// addi r6,r6,176
	ctx.r6.s64 = ctx.r6.s64 + 176;
	// subf r9,r10,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r3,r9,r5
	ctx.r3.u64 = uint32_t((ctx.r5.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r5.s32 == -1)) ? ctx.r9.s32 / ctx.r5.s32 : 0);
	// cmplw cr6,r7,r3
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x823cd37c
	if (ctx.cr6.lt) goto loc_823CD37C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823CD3F4:
	// cmpwi cr6,r7,-1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -1, ctx.xer);
	// bne cr6,0x823cd404
	if (!ctx.cr6.eq) goto loc_823CD404;
loc_823CD3FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823CD404:
	// lwz r11,12(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r10,16(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r8,r9,r5
	ctx.r8.u64 = uint32_t((ctx.r5.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r5.s32 == -1)) ? ctx.r9.s32 / ctx.r5.s32 : 0);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x823cd420
	if (ctx.cr6.lt) goto loc_823CD420;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823CD420:
	// mulli r10,r7,176
	ctx.r10.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(176));
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823D3A58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,16288
	ctx.r10.s64 = ctx.r11.s64 + 16288;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823D3A9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d3aac
	if (ctx.cr6.eq) goto loc_823D3AAC;
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// b 0x823d3ab0
	goto loc_823D3AB0;
loc_823D3AAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D3AB0:
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,1676
	ctx.r10.s64 = ctx.r11.s64 + 1676;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823D70C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0284
	ctx.lr = 0x823D70C8;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x823d7188
	if (ctx.cr6.eq) goto loc_823D7188;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r24,80(r1)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// addi r31,r3,140
	ctx.r31.s64 = ctx.r3.s64 + 140;
	// li r23,76
	ctx.r23.s64 = 76;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r27,r10,16248
	ctx.r27.s64 = ctx.r10.s64 + 16248;
	// addi r26,r11,1636
	ctx.r26.s64 = ctx.r11.s64 + 1636;
loc_823D70FC:
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x823d4a28
	ctx.lr = 0x823D7104;
	sub_823D4A28(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d7148
	if (ctx.cr6.eq) goto loc_823D7148;
	// addi r30,r31,-4
	ctx.r30.s64 = ctx.r31.s64 + -4;
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x823d69d8
	ctx.lr = 0x823D7124;
	sub_823D69D8(ctx, base);
	// lwz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r9,r4,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r4.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// divw r5,r9,r23
	ctx.r5.u64 = uint32_t((ctx.r23.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r23.s32 == -1)) ? ctx.r9.s32 / ctx.r23.s32 : 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823D7148;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823D7148:
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r3,r31,-8
	ctx.r3.s64 = ctx.r31.s64 + -8;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r26,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r26.u32);
	// lwz r11,-8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -8);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r4,-12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + -12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D7174;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r28,r28,176
	ctx.r28.s64 = ctx.r28.s64 + 176;
	// stw r27,-8(r31)
	REX_STORE_U32(ctx.r31.u32 + -8, ctx.r27.u32);
	// addi r31,r31,176
	ctx.r31.s64 = ctx.r31.s64 + 176;
	// cmplw cr6,r28,r25
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x823d70fc
	if (!ctx.cr6.eq) goto loc_823D70FC;
loc_823D7188:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E3838) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x823e36e8
	ctx.lr = 0x823E3850;
	sub_823E36E8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823E49D0) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x823e49ec
	if (ctx.cr6.lt) goto loc_823E49EC;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r4,16
	ctx.r10.s64 = ctx.r4.s64 + 16;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
loc_823E49EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823E5580) {
	REX_FUNC_PROLOGUE();
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823e55c4
	if (ctx.cr6.eq) goto loc_823E55C4;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,64(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmpw cr6,r4,r8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x823e55c4
	if (!ctx.cr6.lt) goto loc_823E55C4;
	// rlwinm r9,r4,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// stw r11,8(r5)
	REX_STORE_U32(ctx.r5.u32 + 8, ctx.r11.u32);
	// blr 
	return;
loc_823E55C4:
	// lis r3,-32683
	ctx.r3.s64 = -2141913088;
	// ori r3,r3,8
	ctx.r3.u64 = ctx.r3.u64 | 8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823E6F20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// stw r4,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// srawi r10,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 4;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// li r9,0
	ctx.r9.s64 = 0;
	// subf. r10,r8,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823e6f50
	if (ctx.cr0.eq) goto loc_823E6F50;
	// subfic r9,r10,16
	ctx.xer.ca = ctx.r10.u32 <= 16;
	ctx.r9.u64 = static_cast<uint64_t>(16) - ctx.r10.u64;
loc_823E6F50:
	// lwz r10,56(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x823e6f7c
	if (!ctx.cr6.gt) goto loc_823E6F7C;
	// lis r3,-32683
	ctx.r3.s64 = -2141913088;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_823E6F7C:
	// lis r11,-32194
	ctx.r11.s64 = -2109865984;
	// addi r5,r1,124
	ctx.r5.s64 = ctx.r1.s64 + 124;
	// addi r4,r11,18616
	ctx.r4.s64 = ctx.r11.s64 + 18616;
	// bl 0x823e6b28
	ctx.lr = 0x823E6F8C;
	sub_823E6B28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823E9998) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r11,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x823e99cc
	if (!ctx.cr6.gt) goto loc_823E99CC;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823E99CC:
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x823e99e4
	if (!ctx.cr6.gt) goto loc_823E99E4;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823E99E4:
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x823d4118
	ctx.lr = 0x823E99FC;
	sub_823D4118(ctx, base);
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// addi r4,r31,28
	ctx.r4.s64 = ctx.r31.s64 + 28;
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x823e9a14
	if (!ctx.cr6.gt) goto loc_823E9A14;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823E9A14:
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x823e9a2c
	if (!ctx.cr6.gt) goto loc_823E9A2C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823E9A2C:
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823d41d8
	ctx.lr = 0x823E9A44;
	sub_823D41D8(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// addi r4,r31,52
	ctx.r4.s64 = ctx.r31.s64 + 52;
	// lwz r10,64(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x823e9a5c
	if (!ctx.cr6.gt) goto loc_823E9A5C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823E9A5C:
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x823e9a74
	if (!ctx.cr6.gt) goto loc_823E9A74;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823E9A74:
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823d41d8
	ctx.lr = 0x823E9A8C;
	sub_823D41D8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823EFDA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x823EFDA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r4,32(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r5,36(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,28(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// bl 0x823ee018
	ctx.lr = 0x823EFDC8;
	sub_823EE018(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r31,36(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823efe08
	if (ctx.cr6.eq) goto loc_823EFE08;
loc_823EFDDC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EFDFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,16(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x823efddc
	if (!ctx.cr6.eq) goto loc_823EFDDC;
loc_823EFE08:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ee1d0
	ctx.lr = 0x823EFE10;
	sub_823EE1D0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F1FC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r3,r3,152
	ctx.r3.s64 = ctx.r3.s64 + 152;
	// stw r30,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r30.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stw r30,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// lwz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823f2030
	if (ctx.cr6.eq) goto loc_823F2030;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823f2030
	if (ctx.cr6.eq) goto loc_823F2030;
	// stw r30,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// stw r30,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// stw r30,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
	// stw r30,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// bl 0x8223cdd8
	ctx.lr = 0x823F202C;
	sub_8223CDD8(ctx, base);
	// stw r30,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r30.u32);
loc_823F2030:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823F6100) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32133
	ctx.r11.s64 = -2105868288;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r7,r11,-18136
	ctx.r7.s64 = ctx.r11.s64 + -18136;
	// li r3,41
	ctx.r3.s64 = 41;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_823F6118:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_823F6120:
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// beq cr6,0x823f6140
	if (ctx.cr6.eq) goto loc_823F6140;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// blt cr6,0x823f6120
	if (ctx.cr6.lt) goto loc_823F6120;
	// b 0x823f6144
	goto loc_823F6144;
loc_823F6140:
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
loc_823F6144:
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// addi r11,r7,492
	ctx.r11.s64 = ctx.r7.s64 + 492;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x823f6118
	if (ctx.cr6.lt) goto loc_823F6118;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823F68B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x823F68C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,102
	ctx.r10.s64 = 102;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// lwz r3,3120(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 3120);
	// bl 0x8222dcd8
	ctx.lr = 0x823F68F4;
	sub_8222DCD8(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// lwz r3,3120(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 3120);
	// lhz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 4);
	// extsh r4,r9
	ctx.r4.s64 = ctx.r9.s16;
	// bl 0x8222c360
	ctx.lr = 0x823F6908;
	sub_8222C360(ctx, base);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F94A8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-14980
	ctx.r9.s64 = ctx.r11.s64 + -14980;
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823F9720) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,9920
	ctx.r9.s64 = ctx.r11.s64 + 9920;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823f9754
	if (ctx.cr6.eq) goto loc_823F9754;
	// bl 0x82573808
	ctx.lr = 0x823F9750;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_823F9754:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823FA9A8) {
	REX_FUNC_PROLOGUE();
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,72(r10)
	REX_STORE_U32(ctx.r10.u32 + 72, ctx.r11.u32);
	// stw r11,76(r10)
	REX_STORE_U32(ctx.r10.u32 + 76, ctx.r11.u32);
	// stw r11,80(r10)
	REX_STORE_U32(ctx.r10.u32 + 80, ctx.r11.u32);
	// stw r11,132(r10)
	REX_STORE_U32(ctx.r10.u32 + 132, ctx.r11.u32);
	// stw r11,136(r10)
	REX_STORE_U32(ctx.r10.u32 + 136, ctx.r11.u32);
	// stw r11,140(r10)
	REX_STORE_U32(ctx.r10.u32 + 140, ctx.r11.u32);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823FC548) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// subf r10,r3,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r3.u64;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// srawi r9,r10,6
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 6;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// rlwinm r8,r9,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// subf r3,r8,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r8.u64;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// subf r7,r4,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r4.u64;
loc_823FC56C:
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// li r8,8
	ctx.r8.s64 = 8;
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + ctx.r11.u64;
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// addi r9,r9,-8
	ctx.r9.s64 = ctx.r9.s64 + -8;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_823FC584:
	// ldu r8,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdu r8,8(r9)
	ea = 8 + ctx.r9.u32;
	REX_STORE_U64(ea, ctx.r8.u64);
	ctx.r9.u32 = ea;
	// bdnz 0x823fc584
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823FC584;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x823fc56c
	if (!ctx.cr6.eq) goto loc_823FC56C;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823FDE50) {
	REX_FUNC_PROLOGUE();
	// lhz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823fde68
	if (!ctx.cr6.eq) goto loc_823FDE68;
	// lis r3,-128
	ctx.r3.s64 = -8388608;
	// ori r3,r3,32896
	ctx.r3.u64 = ctx.r3.u64 | 32896;
	// blr 
	return;
loc_823FDE68:
	// lbz r11,6(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 6);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bne cr6,0x823fde7c
	if (!ctx.cr6.eq) goto loc_823FDE7C;
	// lis r3,-1
	ctx.r3.s64 = -65536;
	// blr 
	return;
loc_823FDE7C:
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// li r3,-256
	ctx.r3.s64 = -256;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823FE6C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x823fe618
	ctx.lr = 0x823FE6D0;
	sub_823FE618(ctx, base);
	// bl 0x82413a98
	ctx.lr = 0x823FE6D4;
	sub_82413A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823FEE68) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// lwz r11,-17576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -17576);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823fee80
	if (!ctx.cr6.eq) goto loc_823FEE80;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823FEE80:
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// lwz r11,-17572(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -17572);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823FFB50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x823FFB58;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,16(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r31,56
	ctx.r29.s64 = ctx.r31.s64 + 56;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// bl 0x826ccc44
	ctx.lr = 0x823FFB78;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x824bd0f0
	ctx.lr = 0x823FFB80;
	sub_824BD0F0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826ccc54
	ctx.lr = 0x823FFB88;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r31,68(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823ffbb8
	if (ctx.cr6.eq) goto loc_823FFBB8;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823FFBB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
loc_823FFBB8:
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823ffbec
	if (ctx.cr6.eq) goto loc_823FFBEC;
	// addi r31,r30,20
	ctx.r31.s64 = ctx.r30.s64 + 20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ba440
	ctx.lr = 0x823FFBD0;
	sub_823BA440(ctx, base);
	// addi r29,r30,72
	ctx.r29.s64 = ctx.r30.s64 + 72;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ba440
	ctx.lr = 0x823FFBDC;
	sub_823BA440(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ba438
	ctx.lr = 0x823FFBE4;
	sub_823BA438(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ba438
	ctx.lr = 0x823FFBEC;
	sub_823BA438(ctx, base);
loc_823FFBEC:
	// lwz r3,8(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x823ff468
	ctx.lr = 0x823FFBF4;
	sub_823FF468(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,132(r30)
	REX_STORE_U32(ctx.r30.u32 + 132, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824052E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// addi r3,r11,-17560
	ctx.r3.s64 = ctx.r11.s64 + -17560;
	// b 0x82404d70
	sub_82404D70(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82405368) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// addi r3,r11,-17560
	ctx.r3.s64 = ctx.r11.s64 + -17560;
	// b 0x82404b58
	sub_82404B58(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824053D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// addi r11,r11,-17560
	ctx.r11.s64 = ctx.r11.s64 + -17560;
	// addi r3,r11,144
	ctx.r3.s64 = ctx.r11.s64 + 144;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824055E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// lwz r11,-17176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -17176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,172(r11)
	REX_STORE_U32(ctx.r11.u32 + 172, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82405E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82405e54
	if (ctx.cr6.eq) goto loc_82405E54;
	// lis r10,-32192
	ctx.r10.s64 = -2109734912;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,23792
	ctx.r8.s64 = ctx.r10.s64 + 23792;
	// addi r6,r9,21712
	ctx.r6.s64 = ctx.r9.s64 + 21712;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r3,88
	ctx.r3.s64 = ctx.r3.s64 + 88;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x82405E54;
	sub_822518D8(ctx, base);
loc_82405E54:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82406FB8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82406fcc
	if (ctx.cr6.eq) goto loc_82406FCC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82406FCC:
	// addi r3,r3,496
	ctx.r3.s64 = ctx.r3.s64 + 496;
	// b 0x82414f20
	sub_82414F20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82408838) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8240887c
	if (!ctx.cr6.eq) goto loc_8240887C;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8240887c
	if (!ctx.cr6.eq) goto loc_8240887C;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8240887c
	if (!ctx.cr6.eq) goto loc_8240887C;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82408880
	if (ctx.cr6.eq) goto loc_82408880;
loc_8240887C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82408880:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8240A410) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// b 0x8240bd48
	sub_8240BD48(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240A888) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a027c
	ctx.lr = 0x8240A890;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r21,r3,680
	ctx.r21.s64 = ctx.r3.s64 + 680;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r27,r21,-4
	ctx.r27.s64 = ctx.r21.s64 + -4;
	// addi r28,r3,56
	ctx.r28.s64 = ctx.r3.s64 + 56;
	// li r23,4
	ctx.r23.s64 = 4;
loc_8240A8B4:
	// subfc r11,r23,r29
	ctx.xer.ca = ctx.r29.u32 >= ctx.r23.u32;
	ctx.r11.u64 = ctx.r29.u64 - ctx.r23.u64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 & ctx.r28.u64;
	// lwz r31,0(r8)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8240a8e8
	if (ctx.cr6.eq) goto loc_8240A8E8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8240c1b8
	ctx.lr = 0x8240A8D8;
	sub_8240C1B8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8240a8e8
	if (!ctx.cr6.eq) goto loc_8240A8E8;
	// stwu r31,4(r27)
	ea = 4 + ctx.r27.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r27.u32 = ea;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_8240A8E8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,36
	ctx.r28.s64 = ctx.r28.s64 + 36;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8240a8b4
	if (ctx.cr6.lt) goto loc_8240A8B4;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// bge cr6,0x8240a92c
	if (!ctx.cr6.lt) goto loc_8240A92C;
	// addi r10,r30,170
	ctx.r10.s64 = ctx.r30.s64 + 170;
	// subfic r11,r30,4
	ctx.xer.ca = ctx.r30.u32 <= 4;
	ctx.r11.u64 = static_cast<uint64_t>(4) - ctx.r30.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// beq cr6,0x8240a92c
	if (ctx.cr6.eq) goto loc_8240A92C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8240A924:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8240a924
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8240A924;
loc_8240A92C:
	// addi r22,r25,696
	ctx.r22.s64 = ctx.r25.s64 + 696;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r26,r22,-4
	ctx.r26.s64 = ctx.r22.s64 + -4;
	// addi r27,r24,8
	ctx.r27.s64 = ctx.r24.s64 + 8;
loc_8240A940:
	// subfc r11,r23,r29
	ctx.xer.ca = ctx.r29.u32 >= ctx.r23.u32;
	ctx.r11.u64 = ctx.r29.u64 - ctx.r23.u64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r9,r27
	ctx.r31.u64 = ctx.r9.u64 & ctx.r27.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240a9ac
	if (ctx.cr6.eq) goto loc_8240A9AC;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r3,r25,48
	ctx.r3.s64 = ctx.r25.s64 + 48;
	// and r4,r9,r30
	ctx.r4.u64 = ctx.r9.u64 & ctx.r30.u64;
	// bl 0x8240bd48
	ctx.lr = 0x8240A970;
	sub_8240BD48(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8240a9ac
	if (!ctx.cr6.eq) goto loc_8240A9AC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r8,r30
	ctx.r7.u64 = ctx.r8.u64 & ctx.r30.u64;
	// stwu r7,4(r26)
	ea = 4 + ctx.r26.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r26.u32 = ea;
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// subfic r5,r6,0
	ctx.xer.ca = ctx.r6.u32 <= 0;
	ctx.r5.u64 = static_cast<uint64_t>(0) - ctx.r6.u64;
	// subfe r31,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r31.u64 = ~ctx.r4.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// bl 0x823c7898
	ctx.lr = 0x8240A9A0;
	sub_823C7898(ctx, base);
	// and r4,r31,r30
	ctx.r4.u64 = ctx.r31.u64 & ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x823c6e98
	ctx.lr = 0x8240A9AC;
	sub_823C6E98(ctx, base);
loc_8240A9AC:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r27,r27,128
	ctx.r27.s64 = ctx.r27.s64 + 128;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x8240a940
	if (ctx.cr6.lt) goto loc_8240A940;
	// cmplwi cr6,r28,4
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 4, ctx.xer);
	// bge cr6,0x8240a9f0
	if (!ctx.cr6.lt) goto loc_8240A9F0;
	// addi r10,r28,174
	ctx.r10.s64 = ctx.r28.s64 + 174;
	// subfic r11,r28,4
	ctx.xer.ca = ctx.r28.u32 <= 4;
	ctx.r11.u64 = static_cast<uint64_t>(4) - ctx.r28.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 + ctx.r25.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// beq cr6,0x8240a9f0
	if (ctx.cr6.eq) goto loc_8240A9F0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8240A9E8:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8240a9e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8240A9E8;
loc_8240A9F0:
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8240aa18
	if (ctx.cr6.eq) goto loc_8240AA18;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8240aa1c
	if (ctx.cr6.eq) goto loc_8240AA1C;
loc_8240AA18:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8240AA1C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r9,30048(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30048);
	// beq cr6,0x8240aa40
	if (ctx.cr6.eq) goto loc_8240AA40;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8240aa44
	if (!ctx.cr6.eq) goto loc_8240AA44;
loc_8240AA40:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8240AA44:
	// lwz r11,1020(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 1020);
	// lwz r3,160(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240aa68
	if (ctx.cr6.eq) goto loc_8240AA68;
	// lwz r8,164(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8240aa6c
	if (ctx.cr6.eq) goto loc_8240AA6C;
loc_8240AA68:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8240AA6C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240aa88
	if (ctx.cr6.eq) goto loc_8240AA88;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8240aa8c
	if (!ctx.cr6.eq) goto loc_8240AA8C;
loc_8240AA88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8240AA8C:
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// bl 0x824068d8
	ctx.lr = 0x8240AA98;
	sub_824068D8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02cc
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82418E58) {
	REX_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82418EC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x823cbda0
	ctx.lr = 0x82418EDC;
	sub_823CBDA0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x82418f4c
	if (!ctx.cr6.eq) goto loc_82418F4C;
	// lwz r11,696(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 696);
	// addi r3,r31,680
	ctx.r3.s64 = ctx.r31.s64 + 680;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82418f0c
	if (ctx.cr6.eq) goto loc_82418F0C;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82418f10
	if (ctx.cr6.eq) goto loc_82418F10;
loc_82418F0C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82418F10:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82418f4c
	if (ctx.cr6.eq) goto loc_82418F4C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82418f4c
	if (ctx.cr6.eq) goto loc_82418F4C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82418f4c
	if (ctx.cr6.eq) goto loc_82418F4C;
	// bl 0x8243fa70
	ctx.lr = 0x82418F40;
	sub_8243FA70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822182a8
	ctx.lr = 0x82418F4C;
	sub_822182A8(ctx, base);
loc_82418F4C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8241F1D8) {
	REX_FUNC_PROLOGUE();
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mulli r9,r4,29
	ctx.r9.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(29));
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// addi r11,r11,768
	ctx.r11.s64 = ctx.r11.s64 + 768;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r3
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// b 0x8241d978
	sub_8241D978(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824217F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0280
	ctx.lr = 0x82421800;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r6,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// stw r7,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r7.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r4,260(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// bl 0x8241edf0
	ctx.lr = 0x82421834;
	sub_8241EDF0(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82421850
	if (!ctx.cr6.eq) goto loc_82421850;
	// stw r30,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r30.u32);
	// stw r29,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r29.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d0
	__restgprlr_22(ctx, base);
	return;
loc_82421850:
	// li r22,0
	ctx.r22.s64 = 0;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// cmpwi cr6,r28,-1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, -1, ctx.xer);
	// beq cr6,0x82421878
	if (ctx.cr6.eq) goto loc_82421878;
	// stw r28,3072(r31)
	REX_STORE_U32(ctx.r31.u32 + 3072, ctx.r28.u32);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// stw r11,3984(r31)
	REX_STORE_U32(ctx.r31.u32 + 3984, ctx.r11.u32);
loc_82421878:
	// cmpwi cr6,r27,-1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -1, ctx.xer);
	// beq cr6,0x8242188c
	if (ctx.cr6.eq) goto loc_8242188C;
	// stw r27,3188(r31)
	REX_STORE_U32(ctx.r31.u32 + 3188, ctx.r27.u32);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// stw r11,4100(r31)
	REX_STORE_U32(ctx.r31.u32 + 4100, ctx.r11.u32);
loc_8242188C:
	// clrlwi r11,r26,31
	ctx.r11.u64 = ctx.r26.u32 & 0x1;
	// lwz r30,268(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824218b4
	if (ctx.cr6.eq) goto loc_824218B4;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8241dd30
	ctx.lr = 0x824218B4;
	sub_8241DD30(ctx, base);
loc_824218B4:
	// rlwinm r11,r26,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824218e0
	if (ctx.cr6.eq) goto loc_824218E0;
	// lwz r11,3552(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3552);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824218e0
	if (ctx.cr6.eq) goto loc_824218E0;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82420c58
	ctx.lr = 0x824218E0;
	sub_82420C58(ctx, base);
loc_824218E0:
	// rlwinm r11,r26,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82421908
	if (ctx.cr6.eq) goto loc_82421908;
	// lwz r11,3548(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3548);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82421908
	if (ctx.cr6.eq) goto loc_82421908;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8241e128
	ctx.lr = 0x82421908;
	sub_8241E128(ctx, base);
loc_82421908:
	// rlwinm r11,r26,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82421934
	if (ctx.cr6.eq) goto loc_82421934;
	// lwz r11,3556(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3556);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82421934
	if (ctx.cr6.eq) goto loc_82421934;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82421110
	ctx.lr = 0x82421934;
	sub_82421110(ctx, base);
loc_82421934:
	// rlwinm r11,r26,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82421950
	if (ctx.cr6.eq) goto loc_82421950;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82421558
	ctx.lr = 0x82421950;
	sub_82421558(ctx, base);
loc_82421950:
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8241d270
	ctx.lr = 0x82421968;
	sub_8241D270(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// stw r10,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r10.u32);
	// beq cr6,0x824219b0
	if (ctx.cr6.eq) goto loc_824219B0;
	// lwz r11,3304(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3304);
	// lwz r10,3312(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3312);
	// lwz r9,3420(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3420);
	// lwz r8,3428(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3428);
	// stw r11,3072(r31)
	REX_STORE_U32(ctx.r31.u32 + 3072, ctx.r11.u32);
	// stw r10,3080(r31)
	REX_STORE_U32(ctx.r31.u32 + 3080, ctx.r10.u32);
	// stw r9,3188(r31)
	REX_STORE_U32(ctx.r31.u32 + 3188, ctx.r9.u32);
	// stw r8,3196(r31)
	REX_STORE_U32(ctx.r31.u32 + 3196, ctx.r8.u32);
	// stw r22,3984(r31)
	REX_STORE_U32(ctx.r31.u32 + 3984, ctx.r22.u32);
	// stw r22,3992(r31)
	REX_STORE_U32(ctx.r31.u32 + 3992, ctx.r22.u32);
	// stw r22,4100(r31)
	REX_STORE_U32(ctx.r31.u32 + 4100, ctx.r22.u32);
	// stw r22,4108(r31)
	REX_STORE_U32(ctx.r31.u32 + 4108, ctx.r22.u32);
loc_824219B0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82427EA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f1,2952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2952);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82428290) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r11,16748
	ctx.r4.s64 = ctx.r11.s64 + 16748;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82423798
	ctx.lr = 0x824282B8;
	sub_82423798(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x824282d0
	if (ctx.cr6.eq) goto loc_824282D0;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x824282d0
	if (ctx.cr6.eq) goto loc_824282D0;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x824282e4
	if (!ctx.cr6.eq) goto loc_824282E4;
loc_824282D0:
	// ld r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// addi r10,r31,80
	ctx.r10.s64 = ctx.r31.s64 + 80;
	// std r11,80(r31)
	REX_STORE_U64(ctx.r31.u32 + 80, ctx.r11.u64);
	// ld r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r30.u32 + 8);
	// std r9,88(r31)
	REX_STORE_U64(ctx.r31.u32 + 88, ctx.r9.u64);
loc_824282E4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8242ADD0) {
	REX_FUNC_PROLOGUE();
	// cntlzw r11,r4
	ctx.r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8242B0A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r4,r11,16852
	ctx.r4.s64 = ctx.r11.s64 + 16852;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82423798
	ctx.lr = 0x8242B0C8;
	sub_82423798(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8242b0e0
	if (ctx.cr6.eq) goto loc_8242B0E0;
	// addi r11,r31,-6
	ctx.r11.s64 = ctx.r31.s64 + -6;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x8242b0ec
	goto loc_8242B0EC;
loc_8242B0E0:
	// addi r11,r31,9
	ctx.r11.s64 = ctx.r31.s64 + 9;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
loc_8242B0EC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82431228) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82486e50
	ctx.lr = 0x82431238;
	sub_82486E50(ctx, base);
	// bl 0x82486ee8
	ctx.lr = 0x8243123C;
	sub_82486EE8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82434580) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824347E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82434808
	if (ctx.cr6.eq) goto loc_82434808;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8243480c
	if (ctx.cr6.eq) goto loc_8243480C;
loc_82434808:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243480C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82434830
	if (ctx.cr6.eq) goto loc_82434830;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r9,60(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r11,30048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82434834
	if (!ctx.cr6.eq) goto loc_82434834;
loc_82434830:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82434834:
	// lwz r3,904(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 904);
	// b 0x8245e008
	sub_8245E008(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82435B90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82435bb8
	if (ctx.cr6.eq) goto loc_82435BB8;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82435bbc
	if (ctx.cr6.eq) goto loc_82435BBC;
loc_82435BB8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82435BBC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82435be0
	if (ctx.cr6.eq) goto loc_82435BE0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r9,60(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r11,30048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82435be4
	if (!ctx.cr6.eq) goto loc_82435BE4;
loc_82435BE0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82435BE4:
	// lwz r3,900(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 900);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-7132
	ctx.r4.s64 = ctx.r11.s64 + -7132;
	// li r5,11
	ctx.r5.s64 = 11;
	// b 0x823719c8
	sub_823719C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82438538) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82438550) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82438650) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82438780) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8249e168
	ctx.lr = 0x82438790;
	sub_8249E168(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824393B0) {
	REX_FUNC_PROLOGUE();
	// b 0x82439a90
	sub_82439A90(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82439400) {
	REX_FUNC_PROLOGUE();
	// b 0x82439890
	sub_82439890(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824395F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82438d38
	ctx.lr = 0x82439618;
	sub_82438D38(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82439630
	if (ctx.cr6.eq) goto loc_82439630;
	// bl 0x82573808
	ctx.lr = 0x8243962C;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82439630:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8243C040) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r11,r11,-18500
	ctx.r11.s64 = ctx.r11.s64 + -18500;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243c06c
	if (ctx.cr6.eq) goto loc_8243C06C;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8243c070
	if (ctx.cr6.eq) goto loc_8243C070;
loc_8243C06C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243C070:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r9,30048(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30048);
	// beq cr6,0x8243c094
	if (ctx.cr6.eq) goto loc_8243C094;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8243c098
	if (!ctx.cr6.eq) goto loc_8243C098;
loc_8243C094:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8243C098:
	// lwz r11,192(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8243c0b8
	if (ctx.cr6.eq) goto loc_8243C0B8;
	// lwz r7,196(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 196);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8243c0bc
	if (ctx.cr6.eq) goto loc_8243C0BC;
loc_8243C0B8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8243C0BC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243c0d8
	if (ctx.cr6.eq) goto loc_8243C0D8;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8243c0dc
	if (!ctx.cr6.eq) goto loc_8243C0DC;
loc_8243C0D8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243C0DC:
	// lwz r10,136(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243c0fc
	if (ctx.cr6.eq) goto loc_8243C0FC;
	// lwz r7,140(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8243c100
	if (ctx.cr6.eq) goto loc_8243C100;
loc_8243C0FC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243C100:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8243c120
	if (ctx.cr6.eq) goto loc_8243C120;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8243c124
	if (!ctx.cr6.eq) goto loc_8243C124;
loc_8243C120:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243C124:
	// addi r3,r11,120
	ctx.r3.s64 = ctx.r11.s64 + 120;
	// b 0x8243a8c8
	sub_8243A8C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82442858) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82442888
	if (!ctx.cr6.eq) goto loc_82442888;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82442888:
	// bl 0x826a0da8
	ctx.lr = 0x8244288C;
	sub_826A0DA8(ctx, base);
	// divw r11,r3,r31
	ctx.r11.u64 = uint32_t((ctx.r31.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r31.s32 == -1)) ? ctx.r3.s32 / ctx.r31.s32 : 0);
	// mullw r10,r11,r31
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// subf r3,r10,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r10.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82445000) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82445008;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r11,7344(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 7344);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r9,r10,10236
	ctx.r9.u64 = ctx.r10.u64 | 10236;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwzx r25,r3,r9
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// beq cr6,0x8244503c
	if (ctx.cr6.eq) goto loc_8244503C;
	// lwz r11,7392(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 7392);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x82445050
	goto loc_82445050;
loc_8244503C:
	// rlwinm r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82445070
	if (ctx.cr6.eq) goto loc_82445070;
	// lwz r11,7392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82445050:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// stw r11,7392(r31)
	REX_STORE_U32(ctx.r31.u32 + 7392, ctx.r11.u32);
	// bge cr6,0x82445064
	if (!ctx.cr6.lt) goto loc_82445064;
	// stw r25,7392(r31)
	REX_STORE_U32(ctx.r31.u32 + 7392, ctx.r25.u32);
	// b 0x82445070
	goto loc_82445070;
loc_82445064:
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// ble cr6,0x82445070
	if (!ctx.cr6.gt) goto loc_82445070;
	// stw r29,7392(r31)
	REX_STORE_U32(ctx.r31.u32 + 7392, ctx.r29.u32);
loc_82445070:
	// lwz r11,7344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7344);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82445238
	if (ctx.cr6.eq) goto loc_82445238;
	// lwz r11,7392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r27,r25,1
	ctx.r27.s64 = ctx.r25.s64 + 1;
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// bne cr6,0x8244515c
	if (!ctx.cr6.eq) goto loc_8244515C;
	// li r30,2
	ctx.r30.s64 = 2;
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// ble cr6,0x8244512c
	if (!ctx.cr6.gt) goto loc_8244512C;
loc_8244509C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8245b738
	ctx.lr = 0x824450AC;
	sub_8245B738(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824450C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r26,100(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r24,0(r26)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r9,140(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 140);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824450E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,0(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,136(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 136);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82445100;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,68(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 68);
	// addi r10,r28,-30
	ctx.r10.s64 = ctx.r28.s64 + -30;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// li r6,0
	ctx.r6.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82445120;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x8244509c
	if (ctx.cr6.lt) goto loc_8244509C;
loc_8244512C:
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82445138;
	sub_8245B6A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,7428(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7428);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// bl 0x82367ba8
	ctx.lr = 0x82445150;
	sub_82367BA8(ctx, base);
	// mulli r11,r25,30
	ctx.r11.s64 = static_cast<int64_t>(ctx.r25.u64 * static_cast<uint64_t>(30));
	// subfic r5,r11,30
	ctx.xer.ca = ctx.r11.u32 <= 30;
	ctx.r5.u64 = static_cast<uint64_t>(30) - ctx.r11.u64;
	// b 0x824453fc
	goto loc_824453FC;
loc_8244515C:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// ble cr6,0x82445208
	if (!ctx.cr6.gt) goto loc_82445208;
loc_82445168:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8245b738
	ctx.lr = 0x82445178;
	sub_8245B738(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82445194;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,7392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r30,r9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x824451fc
	if (!ctx.cr6.eq) goto loc_824451FC;
	// lwz r26,100(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r24,0(r26)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,140(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824451C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,136(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 136);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824451DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,68(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 68);
	// addi r7,r28,30
	ctx.r7.s64 = ctx.r28.s64 + 30;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// li r6,0
	ctx.r6.s64 = 0;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824451FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824451FC:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x82445168
	if (ctx.cr6.lt) goto loc_82445168;
loc_82445208:
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82445214;
	sub_8245B6A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,7428(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7428);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// bl 0x82367ba8
	ctx.lr = 0x8244522C;
	sub_82367BA8(ctx, base);
	// lwz r11,7428(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7428);
	// addi r5,r11,30
	ctx.r5.s64 = ctx.r11.s64 + 30;
	// b 0x824453fc
	goto loc_824453FC;
loc_82445238:
	// rlwinm r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82445410
	if (ctx.cr6.eq) goto loc_82445410;
	// lwz r11,7392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r27,r25,1
	ctx.r27.s64 = ctx.r25.s64 + 1;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8244532c
	if (!ctx.cr6.eq) goto loc_8244532C;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// ble cr6,0x824452f8
	if (!ctx.cr6.gt) goto loc_824452F8;
loc_82445260:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8245b738
	ctx.lr = 0x82445270;
	sub_8245B738(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8244528C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// ble cr6,0x824452ec
	if (!ctx.cr6.gt) goto loc_824452EC;
	// lwz r26,100(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r24,0(r26)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,140(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824452B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,136(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 136);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824452CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,68(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 68);
	// addi r7,r28,30
	ctx.r7.s64 = ctx.r28.s64 + 30;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// li r6,0
	ctx.r6.s64 = 0;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824452EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824452EC:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x82445260
	if (ctx.cr6.lt) goto loc_82445260;
loc_824452F8:
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82445304;
	sub_8245B6A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,7428(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7428);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// bl 0x82367ba8
	ctx.lr = 0x8244531C;
	sub_82367BA8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,7428(r31)
	REX_STORE_U32(ctx.r31.u32 + 7428, ctx.r11.u32);
	// b 0x82445400
	goto loc_82445400;
loc_8244532C:
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// ble cr6,0x824453d0
	if (!ctx.cr6.gt) goto loc_824453D0;
loc_82445334:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8245b738
	ctx.lr = 0x82445344;
	sub_8245B738(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82445360;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,7392(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// cmpw cr6,r30,r9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x824453c4
	if (!ctx.cr6.eq) goto loc_824453C4;
	// lwz r26,100(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r24,0(r26)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,140(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82445388;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,136(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 136);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824453A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,68(r24)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r24.u32 + 68);
	// addi r7,r28,-30
	ctx.r7.s64 = ctx.r28.s64 + -30;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// li r6,0
	ctx.r6.s64 = 0;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824453C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824453C4:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x82445334
	if (ctx.cr6.lt) goto loc_82445334;
loc_824453D0:
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x824453DC;
	sub_8245B6A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,7428(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7428);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// bl 0x82367ba8
	ctx.lr = 0x824453F4;
	sub_82367BA8(ctx, base);
	// lwz r11,7428(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7428);
	// addi r5,r11,-30
	ctx.r5.s64 = ctx.r11.s64 + -30;
loc_824453FC:
	// stw r5,7428(r31)
	REX_STORE_U32(ctx.r31.u32 + 7428, ctx.r5.u32);
loc_82445400:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,96(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82367ba8
	ctx.lr = 0x82445410;
	sub_82367BA8(ctx, base);
loc_82445410:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_82445414:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8245b738
	ctx.lr = 0x82445424;
	sub_8245B738(ctx, base);
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8244543C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,41
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 41, ctx.xer);
	// blt cr6,0x82445414
	if (ctx.cr6.lt) goto loc_82445414;
	// addi r26,r25,1
	ctx.r26.s64 = ctx.r25.s64 + 1;
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// ble cr6,0x824454f4
	if (!ctx.cr6.gt) goto loc_824454F4;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// li r27,-1
	ctx.r27.s64 = -1;
	// addi r28,r28,10248
	ctx.r28.s64 = ctx.r28.s64 + 10248;
loc_82445460:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8245b738
	ctx.lr = 0x82445470;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82445490;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,96(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824454A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x824454e8
	if (!ctx.cr6.eq) goto loc_824454E8;
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x824454e8
	if (!ctx.cr6.eq) goto loc_824454E8;
	// cmpw cr6,r29,r25
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r25.s32, ctx.xer);
	// bne cr6,0x824454e8
	if (!ctx.cr6.eq) goto loc_824454E8;
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r4,r4,65408
	ctx.r4.u64 = ctx.r4.u64 | 65408;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824454E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824454E8:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r26
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x82445460
	if (ctx.cr6.lt) goto loc_82445460;
loc_824454F4:
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r5,7392(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b738
	ctx.lr = 0x82445504;
	sub_8245B738(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8244552c
	if (ctx.cr6.eq) goto loc_8244552C;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// lis r4,-1
	ctx.r4.s64 = -65536;
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r4,r4,13824
	ctx.r4.u64 = ctx.r4.u64 | 13824;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8244552C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8244552C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82444cc0
	ctx.lr = 0x82445534;
	sub_82444CC0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82469CB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// blt cr6,0x82469d40
	if (ctx.cr6.lt) goto loc_82469D40;
	// beq cr6,0x82469d10
	if (ctx.cr6.eq) goto loc_82469D10;
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// bge cr6,0x82469d88
	if (!ctx.cr6.lt) goto loc_82469D88;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,124
	ctx.r3.s64 = 124;
	// bl 0x82219630
	ctx.lr = 0x82469CFC;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82469d84
	if (ctx.cr6.eq) goto loc_82469D84;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8246c510
	ctx.lr = 0x82469D0C;
	sub_8246C510(ctx, base);
	// b 0x82469d88
	goto loc_82469D88;
loc_82469D10:
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82219630
	ctx.lr = 0x82469D2C;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82469d84
	if (ctx.cr6.eq) goto loc_82469D84;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8246c268
	ctx.lr = 0x82469D3C;
	sub_8246C268(ctx, base);
	// b 0x82469d88
	goto loc_82469D88;
loc_82469D40:
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,124
	ctx.r3.s64 = 124;
	// bl 0x82219630
	ctx.lr = 0x82469D5C;
	sub_82219630(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82469d84
	if (ctx.cr6.eq) goto loc_82469D84;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82469b60
	ctx.lr = 0x82469D70;
	sub_82469B60(ctx, base);
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,-15152
	ctx.r10.s64 = ctx.r11.s64 + -15152;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82469d88
	goto loc_82469D88;
loc_82469D84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82469D88:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8246D338) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82469fd8
	ctx.lr = 0x8246D358;
	sub_82469FD8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246d370
	if (ctx.cr6.eq) goto loc_8246D370;
	// bl 0x82573808
	ctx.lr = 0x8246D36C;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8246D370:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8246EE78) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,136(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// addi r30,r3,120
	ctx.r30.s64 = ctx.r3.s64 + 120;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246eeb0
	if (ctx.cr6.eq) goto loc_8246EEB0;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8246eeb4
	if (ctx.cr6.eq) goto loc_8246EEB4;
loc_8246EEB0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8246EEB4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8246ef6c
	if (ctx.cr6.eq) goto loc_8246EF6C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r9,30048(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 30048);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8246ef6c
	if (ctx.cr6.eq) goto loc_8246EF6C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246ef6c
	if (ctx.cr6.eq) goto loc_8246EF6C;
	// lwz r11,160(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// addi r31,r3,144
	ctx.r31.s64 = ctx.r3.s64 + 144;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246ef04
	if (ctx.cr6.eq) goto loc_8246EF04;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8246ef08
	if (ctx.cr6.eq) goto loc_8246EF08;
loc_8246EF04:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8246EF08:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8246ef6c
	if (ctx.cr6.eq) goto loc_8246EF6C;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8246ef6c
	if (ctx.cr6.eq) goto loc_8246EF6C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246ef6c
	if (ctx.cr6.eq) goto loc_8246EF6C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8243fa70
	ctx.lr = 0x8246EF34;
	sub_8243FA70(ctx, base);
	// bl 0x824712d0
	ctx.lr = 0x8246EF38;
	sub_824712D0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246ef4c
	if (ctx.cr6.eq) goto loc_8246EF4C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8243fa70
	ctx.lr = 0x8246EF48;
	sub_8243FA70(ctx, base);
	// bl 0x82471380
	ctx.lr = 0x8246EF4C;
	sub_82471380(ctx, base);
loc_8246EF4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243fa70
	ctx.lr = 0x8246EF54;
	sub_8243FA70(ctx, base);
	// bl 0x82473820
	ctx.lr = 0x8246EF58;
	sub_82473820(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246ef6c
	if (ctx.cr6.eq) goto loc_8246EF6C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243fa70
	ctx.lr = 0x8246EF68;
	sub_8243FA70(ctx, base);
	// bl 0x824738d0
	ctx.lr = 0x8246EF6C;
	sub_824738D0(ctx, base);
loc_8246EF6C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82473980) {
	REX_FUNC_PROLOGUE();
	// lwz r11,120(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824739ac
	if (ctx.cr6.eq) goto loc_824739AC;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,148(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x824739b0
	if (ctx.cr6.eq) goto loc_824739B0;
loc_824739AC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824739B0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,60(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r9,30048(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 30048);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,144(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824739fc
	if (ctx.cr6.eq) goto loc_824739FC;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r8,148(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82473a00
	if (ctx.cr6.eq) goto loc_82473A00;
loc_824739FC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82473A00:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82473a20
	if (ctx.cr6.eq) goto loc_82473A20;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82473a24
	if (!ctx.cr6.eq) goto loc_82473A24;
loc_82473A20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82473A24:
	// b 0x82470878
	sub_82470878(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82478AC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82478AC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,28
	ctx.r11.s64 = 28;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x824426e8
	ctx.lr = 0x82478AE8;
	sub_824426E8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x824426e8
	ctx.lr = 0x82478AF0;
	sub_824426E8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// addi r29,r31,40
	ctx.r29.s64 = ctx.r31.s64 + 40;
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r10,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// bl 0x8243f9a8
	ctx.lr = 0x82478B10;
	sub_8243F9A8(ctx, base);
	// addi r30,r31,384
	ctx.r30.s64 = ctx.r31.s64 + 384;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8243f9a8
	ctx.lr = 0x82478B1C;
	sub_8243F9A8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82440eb8
	ctx.lr = 0x82478B24;
	sub_82440EB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82440eb8
	ctx.lr = 0x82478B2C;
	sub_82440EB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8247B548) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8247B550;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82218220
	ctx.lr = 0x8247B55C;
	sub_82218220(ctx, base);
	// lis r10,-32184
	ctx.r10.s64 = -2109210624;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,-19424
	ctx.r8.s64 = ctx.r10.s64 + -19424;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r7,r7,-12568
	ctx.r7.s64 = ctx.r7.s64 + -12568;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r6,r6,21712
	ctx.r6.s64 = ctx.r6.s64 + 21712;
	// lwz r3,8(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lwz r30,0(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lis r29,-32247
	ctx.r29.s64 = -2113339392;
	// stw r7,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r7.u32);
	// addi r5,r5,-12516
	ctx.r5.s64 = ctx.r5.s64 + -12516;
	// stw r6,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r6.u32);
	// addi r4,r4,-12524
	ctx.r4.s64 = ctx.r4.s64 + -12524;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// stw r3,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r3.u32);
	// addi r6,r10,-12560
	ctx.r6.s64 = ctx.r10.s64 + -12560;
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// addi r7,r7,-12536
	ctx.r7.s64 = ctx.r7.s64 + -12536;
	// stw r9,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// addi r9,r29,-12548
	ctx.r9.s64 = ctx.r29.s64 + -12548;
	// stw r8,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r8.u32);
	// addi r30,r31,228
	ctx.r30.s64 = ctx.r31.s64 + 228;
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// addi r10,r31,88
	ctx.r10.s64 = ctx.r31.s64 + 88;
	// stw r4,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// addi r5,r10,8
	ctx.r5.s64 = ctx.r10.s64 + 8;
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// stw r6,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r6.u32);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r11,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// stw r9,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r9.u32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r11,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// stw r7,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r7.u32);
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// stw r11,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// stw r11,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// stw r11,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// stw r11,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// stw r11,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// stw r11,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// bl 0x8247a390
	ctx.lr = 0x8247B668;
	sub_8247A390(ctx, base);
	// addi r29,r31,244
	ctx.r29.s64 = ctx.r31.s64 + 244;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8247a390
	ctx.lr = 0x8247B674;
	sub_8247A390(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,60(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r11,30044(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 30044);
	// or r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 | ctx.r8.u64;
	// stw r7,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r7.u32);
	// lwz r6,30044(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 30044);
	// bl 0x822189c8
	ctx.lr = 0x8247B6A4;
	sub_822189C8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8247a3e0
	ctx.lr = 0x8247B6B0;
	sub_8247A3E0(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8247a3e0
	ctx.lr = 0x8247B6BC;
	sub_8247A3E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824817B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,152
	ctx.r3.s64 = ctx.r3.s64 + 152;
	// bl 0x82218850
	ctx.lr = 0x824817CC;
	sub_82218850(ctx, base);
	// addi r3,r31,128
	ctx.r3.s64 = ctx.r31.s64 + 128;
	// bl 0x82218850
	ctx.lr = 0x824817D4;
	sub_82218850(ctx, base);
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-11344
	ctx.r9.s64 = ctx.r11.s64 + -11344;
	// addi r8,r10,3000
	ctx.r8.s64 = ctx.r10.s64 + 3000;
	// stw r9,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82483828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0278
	ctx.lr = 0x82483830;
	__savegprlr_20(ctx, base);
	// stfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f30.u64);
	// stfd f31,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82483b50
	if (!ctx.cr6.eq) goto loc_82483B50;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x822e8b30
	ctx.lr = 0x82483854;
	sub_822E8B30(ctx, base);
	// addi r11,r3,-14
	ctx.r11.s64 = ctx.r3.s64 + -14;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82483b50
	if (ctx.cr6.eq) goto loc_82483B50;
	// bl 0x822ec160
	ctx.lr = 0x8248386C;
	sub_822EC160(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// li r27,11
	ctx.r27.s64 = 11;
	// addi r31,r29,152
	ctx.r31.s64 = ctx.r29.s64 + 152;
	// lfs f31,2880(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
	// li r26,10
	ctx.r26.s64 = 10;
	// lfs f30,2884(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2884);
	ctx.f30.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r24,-1
	ctx.r24.s64 = -1;
	// li r28,1
	ctx.r28.s64 = 1;
	// addi r25,r11,-10372
	ctx.r25.s64 = ctx.r11.s64 + -10372;
loc_8248389C:
	// lwz r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82483a14
	if (ctx.cr6.eq) goto loc_82483A14;
	// stw r30,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r30.u32);
	// addi r5,r27,10
	ctx.r5.s64 = ctx.r27.s64 + 10;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822e8680
	ctx.lr = 0x824838BC;
	sub_822E8680(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82483958
	if (!ctx.cr6.eq) goto loc_82483958;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824427d0
	ctx.lr = 0x824838CC;
	sub_824427D0(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82442798
	ctx.lr = 0x824838D8;
	sub_82442798(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82442760
	ctx.lr = 0x824838E4;
	sub_82442760(ctx, base);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82442728
	ctx.lr = 0x824838F0;
	sub_82442728(ctx, base);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824426f0
	ctx.lr = 0x824838FC;
	sub_824426F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
	// bl 0x82486668
	ctx.lr = 0x8248391C;
	sub_82486668(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82228870
	ctx.lr = 0x82483924;
	sub_82228870(ctx, base);
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lwz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r4,r25,-60
	ctx.r4.s64 = ctx.r25.s64 + -60;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r6,99
	ctx.r6.s64 = 99;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x823612d0
	ctx.lr = 0x82483958;
	sub_823612D0(ctx, base);
loc_82483958:
	// stw r30,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822e8680
	ctx.lr = 0x8248396C;
	sub_822E8680(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82483a14
	if (!ctx.cr6.eq) goto loc_82483A14;
	// lwz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// addi r7,r9,-30
	ctx.r7.s64 = ctx.r9.s64 + -30;
	// lbz r23,349(r31)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r31.u32 + 349);
	// addi r8,r11,-8
	ctx.r8.s64 = ctx.r11.s64 + -8;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// std r30,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r30.u64);
	// std r5,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r5.u64);
	// lfd f13,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r6,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// std r30,8(r10)
	REX_STORE_U64(ctx.r10.u32 + 8, ctx.r30.u64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,164(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stw r28,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r28.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,160(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bl 0x824865e8
	ctx.lr = 0x824839CC;
	sub_824865E8(ctx, base);
	// subfic r4,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r4.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// subfe r22,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r22.u64 = ~ctx.r4.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// bl 0x822ed0d8
	ctx.lr = 0x824839D8;
	sub_822ED0D8(ctx, base);
	// rlwinm r11,r22,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0xFFFFFFF8;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// li r4,212
	ctx.r4.s64 = 212;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// rlwinm r11,r11,0,25,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r11,r11,219
	ctx.r11.s64 = ctx.r11.s64 + 219;
	// stw r28,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r28.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// add r5,r11,r23
	ctx.r5.u64 = ctx.r11.u64 + ctx.r23.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x822ed700
	ctx.lr = 0x82483A14;
	sub_822ED700(ctx, base);
loc_82483A14:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,384
	ctx.r31.s64 = ctx.r31.s64 + 384;
	// bne 0x8248389c
	if (!ctx.cr0.eq) goto loc_8248389C;
	// lwz r11,4008(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4008);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82483a88
	if (ctx.cr6.eq) goto loc_82483A88;
	// stw r30,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// li r5,45
	ctx.r5.s64 = 45;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822e8680
	ctx.lr = 0x82483A44;
	sub_822E8680(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82483a88
	if (!ctx.cr6.eq) goto loc_82483A88;
	// li r3,4
	ctx.r3.s64 = 4;
	// lwz r31,4008(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4008);
	// bl 0x82228870
	ctx.lr = 0x82483A58;
	sub_82228870(ctx, base);
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lwz r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// addi r4,r25,-40
	ctx.r4.s64 = ctx.r25.s64 + -40;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r6,100
	ctx.r6.s64 = 100;
	// lis r7,-1
	ctx.r7.s64 = -65536;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x823612d0
	ctx.lr = 0x82483A88;
	sub_823612D0(ctx, base);
loc_82483A88:
	// stw r28,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r28.u32);
	// li r5,42
	ctx.r5.s64 = 42;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822e8680
	ctx.lr = 0x82483A9C;
	sub_822E8680(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82483af0
	if (!ctx.cr6.eq) goto loc_82483AF0;
	// li r11,250
	ctx.r11.s64 = 250;
	// lwz r31,3988(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 3988);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,3984(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 3984);
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// bl 0x82228870
	ctx.lr = 0x82483ABC;
	sub_82228870(ctx, base);
	// lwz r10,148(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r4,r25,-20
	ctx.r4.s64 = ctx.r25.s64 + -20;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r6,100
	ctx.r6.s64 = 100;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,250
	ctx.r10.s64 = 250;
	// bl 0x823612d0
	ctx.lr = 0x82483AF0;
	sub_823612D0(ctx, base);
loc_82483AF0:
	// stw r28,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r28.u32);
	// li r5,43
	ctx.r5.s64 = 43;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822e8680
	ctx.lr = 0x82483B04;
	sub_822E8680(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82483b50
	if (!ctx.cr6.eq) goto loc_82483B50;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,3996(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 3996);
	// lwz r30,3992(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 3992);
	// bl 0x82228870
	ctx.lr = 0x82483B1C;
	sub_82228870(ctx, base);
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// li r6,100
	ctx.r6.s64 = 100;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x823612d0
	ctx.lr = 0x82483B50;
	sub_823612D0(ctx, base);
loc_82483B50:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x826a02c8
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82498A60) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-120
	ctx.r3.s64 = ctx.r3.s64 + -120;
	// b 0x82498bc8
	sub_82498BC8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82499448) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,-28384
	ctx.r8.s64 = ctx.r10.s64 + -28384;
	// addi r6,r9,21712
	ctx.r6.s64 = ctx.r9.s64 + 21712;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r3,120
	ctx.r3.s64 = ctx.r3.s64 + 120;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x82499488;
	sub_822518D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8249B910) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mullw r5,r10,r9
	ctx.r5.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// b 0x826a03b0
	rexcrt_memset(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249C088) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x8249C090;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stw r4,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r4.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// bl 0x826a03b0
	ctx.lr = 0x8249C0C4;
	rexcrt_memset(ctx, base);
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r29,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r29.u32);
	// addi r11,r11,324
	ctx.r11.s64 = ctx.r11.s64 + 324;
	// stw r30,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r9,42(r31)
	REX_STORE_U8(ctx.r31.u32 + 42, ctx.r9.u8);
	// addi r8,r11,-28
	ctx.r8.s64 = ctx.r11.s64 + -28;
	// stw r9,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
	// addi r7,r11,-12
	ctx.r7.s64 = ctx.r11.s64 + -12;
	// stw r29,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r29.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r27,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r27.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r8,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r8.u32);
	// stw r10,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// stw r7,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// stw r10,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// stw r28,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// stw r27,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r27.u32);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// stw r10,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r10.u32);
	// stw r25,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r25.u32);
	// stw r26,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r26.u32);
	// stw r25,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// stw r6,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// stb r10,41(r31)
	REX_STORE_U8(ctx.r31.u32 + 41, ctx.r10.u8);
	// beq cr6,0x8249c148
	if (ctx.cr6.eq) goto loc_8249C148;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C148;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8249C148:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8249c164
	if (ctx.cr6.eq) goto loc_8249C164;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249C164;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8249C164:
	// lwsync 
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// stw r31,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r31.u32);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// addi r9,r10,-19632
	ctx.r9.s64 = ctx.r10.s64 + -19632;
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r5,r5,-25432
	ctx.r5.s64 = ctx.r5.s64 + -25432;
	// li r4,16384
	ctx.r4.s64 = 16384;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x824bd5f8
	ctx.lr = 0x8249C19C;
	sub_824BD5F8(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824bd278
	ctx.lr = 0x8249C1A8;
	sub_824BD278(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x824bd448
	ctx.lr = 0x8249C1B4;
	sub_824BD448(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x824bd5b8
	ctx.lr = 0x8249C1BC;
	sub_824BD5B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824A1FA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,7584
	ctx.r9.s64 = ctx.r10.s64 + 7584;
	// addi r3,r3,88
	ctx.r3.s64 = ctx.r3.s64 + 88;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82341280
	ctx.lr = 0x824A1FE0;
	sub_82341280(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824A4850) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824a4894
	if (ctx.cr6.eq) goto loc_824A4894;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x824a4898
	if (ctx.cr6.eq) goto loc_824A4898;
loc_824A4894:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_824A4898:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a48bc
	if (ctx.cr6.eq) goto loc_824A48BC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r9,60(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r11,30048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x824a48c0
	if (!ctx.cr6.eq) goto loc_824A48C0;
loc_824A48BC:
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
loc_824A48C0:
	// lwz r3,1020(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 1020);
	// bl 0x823c86d0
	ctx.lr = 0x824A48C8;
	sub_823C86D0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824a492c
	if (ctx.cr6.eq) goto loc_824A492C;
	// bl 0x823c4db8
	ctx.lr = 0x824A48D4;
	sub_823C4DB8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x824a48f4
	if (!ctx.cr6.eq) goto loc_824A48F4;
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r11,r11,1989
	ctx.r11.s64 = ctx.r11.s64 + 1989;
	// addi r9,r10,17528
	ctx.r9.s64 = ctx.r10.s64 + 17528;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// b 0x824a490c
	goto loc_824A490C;
loc_824A48F4:
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x824a492c
	if (!ctx.cr6.eq) goto loc_824A492C;
	// lis r11,-32182
	ctx.r11.s64 = -2109079552;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r11,20584
	ctx.r9.s64 = ctx.r11.s64 + 20584;
	// addi r6,r10,1989
	ctx.r6.s64 = ctx.r10.s64 + 1989;
loc_824A490C:
	// addi r3,r30,88
	ctx.r3.s64 = ctx.r30.s64 + 88;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x824A492C;
	sub_822518D8(ctx, base);
loc_824A492C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824A9378) {
	REX_FUNC_PROLOGUE();
	// li r3,16
	ctx.r3.s64 = 16;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824A95B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x824a9560
	ctx.lr = 0x824A95D8;
	sub_824A9560(ctx, base);
	// cmplw cr6,r3,r31
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824a9604
	if (ctx.cr6.eq) goto loc_824A9604;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x824a94f8
	ctx.lr = 0x824A9604;
	sub_824A94F8(ctx, base);
loc_824A9604:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824ABC20) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r10,r11,3000
	ctx.r10.s64 = ctx.r11.s64 + 3000;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824AC650) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-96
	ctx.r3.s64 = ctx.r3.s64 + -96;
	// b 0x824ac658
	sub_824AC658(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824ACA38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821dee18
	ctx.lr = 0x824ACA50;
	sub_821DEE18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x824aca70
	if (!ctx.cr6.eq) goto loc_824ACA70;
loc_824ACA58:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824ACA70:
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x82306d48
	ctx.lr = 0x824ACA78;
	sub_82306D48(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824aca58
	if (ctx.cr6.eq) goto loc_824ACA58;
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// lbz r10,-5264(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -5264);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x824aca58
	if (!ctx.cr6.eq) goto loc_824ACA58;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bge cr6,0x824acaf8
	if (!ctx.cr6.lt) goto loc_824ACAF8;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82219630
	ctx.lr = 0x824ACABC;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824acad4
	if (ctx.cr6.eq) goto loc_824ACAD4;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,100(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r4,96(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// bl 0x824aeb38
	ctx.lr = 0x824ACAD4;
	sub_824AEB38(ctx, base);
loc_824ACAD4:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824ACAF8:
	// bl 0x824955d8
	ctx.lr = 0x824ACAFC;
	sub_824955D8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824acb24
	if (ctx.cr6.eq) goto loc_824ACB24;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,58
	ctx.r4.s64 = 58;
	// bl 0x82495478
	ctx.lr = 0x824ACB14;
	sub_82495478(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,57
	ctx.r4.s64 = 57;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82495478
	ctx.lr = 0x824ACB24;
	sub_82495478(ctx, base);
loc_824ACB24:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824B6400) {
	REX_FUNC_PROLOGUE();
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x824b6458
	if (ctx.cr6.eq) goto loc_824B6458;
	// lwz r8,48(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r9,16(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r8,16(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x824b6458
	if (!ctx.cr6.gt) goto loc_824B6458;
loc_824B6424:
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x824b6440
	if (!ctx.cr6.gt) goto loc_824B6440;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x824b6424
	if (!ctx.cr6.eq) goto loc_824B6424;
	// blr 
	return;
loc_824B6440:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// stw r4,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r4,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r4.u32);
	// blr 
	return;
loc_824B6458:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r4,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824B99C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0278
	ctx.lr = 0x824B99D0;
	__savegprlr_20(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r23,r11,-4172
	ctx.r23.s64 = ctx.r11.s64 + -4172;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r11,r23,4
	ctx.r11.s64 = ctx.r23.s64 + 4;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// bl 0x826ccc44
	ctx.lr = 0x824B99FC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ccc44
	ctx.lr = 0x824B9A04;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x824b60b0
	ctx.lr = 0x824B9A10;
	sub_824B60B0(ctx, base);
	// rlwinm r21,r3,2,30,31
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// lis r24,-32131
	ctx.r24.s64 = -2105737216;
	// cmplwi cr6,r21,3
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 3, ctx.xer);
	// beq cr6,0x824b9d48
	if (ctx.cr6.eq) goto loc_824B9D48;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// li r20,1
	ctx.r20.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x824b9b54
	if (!ctx.cr6.eq) goto loc_824B9B54;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// lwz r4,26508(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 26508);
	// bl 0x824c64b8
	ctx.lr = 0x824B9A40;
	sub_824C64B8(ctx, base);
	// mr. r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq 0x824b9c94
	if (ctx.cr0.eq) goto loc_824B9C94;
	// stw r26,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// li r9,4096
	ctx.r9.s64 = 4096;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B9A84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,259
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 259, ctx.xer);
	// bne cr6,0x824b9aac
	if (!ctx.cr6.eq) goto loc_824B9AAC;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826ccdc4
	ctx.lr = 0x824B9AA0;
	__imp__NtWaitForSingleObjectEx(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x824b9aac
	if (ctx.cr0.lt) goto loc_824B9AAC;
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_824B9AAC:
	// rlwinm r11,r3,2,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r21,r11
	ctx.r21.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x824b9d28
	if (ctx.cr6.eq) goto loc_824B9D28;
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x824b9c9c
	if (!ctx.cr6.eq) goto loc_824B9C9C;
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x824b9c9c
	if (!ctx.cr6.eq) goto loc_824B9C9C;
	// lis r11,-1314
	ctx.r11.s64 = -86114304;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// ori r11,r11,47812
	ctx.r11.u64 = ctx.r11.u64 | 47812;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824b9c9c
	if (!ctx.cr6.eq) goto loc_824B9C9C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2280(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2280);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b9b30
	if (ctx.cr6.eq) goto loc_824B9B30;
	// lis r4,4
	ctx.r4.s64 = 262144;
	// lwz r3,88(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// ori r4,r4,6
	ctx.r4.u64 = ctx.r4.u64 | 6;
	// bl 0x826cce14
	ctx.lr = 0x824B9B10;
	__imp__RtlImageXexHeaderField(ctx, base);
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// addic r10,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// ori r11,r11,549
	ctx.r11.u64 = ctx.r11.u64 | 549;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x824b9b30
	if (ctx.cr0.lt) goto loc_824B9B30;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x824b9b34
	goto loc_824B9B34;
loc_824B9B30:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_824B9B34:
	// lwz r10,12(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824b9c9c
	if (!ctx.cr6.eq) goto loc_824B9C9C;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r4,26508(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 26508);
	// bl 0x824c6550
	ctx.lr = 0x824B9B4C;
	sub_824C6550(ctx, base);
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// stw r20,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r20.u32);
loc_824B9B54:
	// stw r26,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r26.u32);
	// b 0x824b9c80
	goto loc_824B9C80;
loc_824B9B5C:
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r26,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r9,4096
	ctx.r9.s64 = 4096;
	// rlwinm r6,r7,12,0,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 12) & 0xFFFFF000;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B9BA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,259
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 259, ctx.xer);
	// bne cr6,0x824b9bcc
	if (!ctx.cr6.eq) goto loc_824B9BCC;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826ccdc4
	ctx.lr = 0x824B9BC0;
	__imp__NtWaitForSingleObjectEx(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x824b9bcc
	if (ctx.cr0.lt) goto loc_824B9BCC;
	// lwz r3,104(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_824B9BCC:
	// rlwinm r11,r3,2,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r21,r11
	ctx.r21.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x824b9ca4
	if (ctx.cr6.eq) goto loc_824B9CA4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x824b6fe0
	ctx.lr = 0x824B9BF4;
	sub_824B6FE0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x824b9c9c
	if (ctx.cr0.eq) goto loc_824B9C9C;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824b9c54
	if (!ctx.cr6.eq) goto loc_824B9C54;
	// lhz r29,2(r28)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r28.u32 + 2);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x824b9c54
	if (!ctx.cr6.lt) goto loc_824B9C54;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,26508(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 26508);
	// bl 0x824c64b8
	ctx.lr = 0x824B9C24;
	sub_824C64B8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824b9c94
	if (ctx.cr0.eq) goto loc_824B9C94;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x824b25e8
	ctx.lr = 0x824B9C40;
	sub_824B25E8(ctx, base);
	// lwz r4,26508(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 26508);
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x824c6550
	ctx.lr = 0x824B9C4C;
	sub_824C6550(ctx, base);
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r29,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r29.u32);
loc_824B9C54:
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r28.u32);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// lhz r10,2(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x824b9ca4
	if (!ctx.cr6.lt) goto loc_824B9CA4;
loc_824B9C80:
	// li r3,4096
	ctx.r3.s64 = 4096;
	// lwz r4,26508(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 26508);
	// bl 0x824c64b8
	ctx.lr = 0x824B9C8C;
	sub_824C64B8(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x824b9b5c
	if (!ctx.cr0.eq) goto loc_824B9B5C;
loc_824B9C94:
	// li r26,8
	ctx.r26.s64 = 8;
	// b 0x824b9d28
	goto loc_824B9D28;
loc_824B9C9C:
	// li r26,11
	ctx.r26.s64 = 11;
	// b 0x824b9d28
	goto loc_824B9D28;
loc_824B9CA4:
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// li r30,-1
	ctx.r30.s64 = -1;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// b 0x824b9ccc
	goto loc_824B9CCC;
loc_824B9CC0:
	// bl 0x824b6400
	ctx.lr = 0x824B9CC4;
	sub_824B6400(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824b7cd8
	ctx.lr = 0x824B9CCC;
	sub_824B7CD8(ctx, base);
loc_824B9CCC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824b7e30
	ctx.lr = 0x824B9CD8;
	sub_824B7E30(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne 0x824b9cc0
	if (!ctx.cr0.eq) goto loc_824B9CC0;
	// bl 0x826ccc44
	ctx.lr = 0x824B9CE8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// b 0x824b9d08
	goto loc_824B9D08;
loc_824B9CF4:
	// lwz r11,28(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// stb r20,26(r4)
	REX_STORE_U8(ctx.r4.u32 + 26, ctx.r20.u8);
	// andi. r11,r11,209
	ctx.r11.u64 = ctx.r11.u64 & 209;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,28(r4)
	REX_STORE_U32(ctx.r4.u32 + 28, ctx.r11.u32);
	// bl 0x824b7cd8
	ctx.lr = 0x824B9D08;
	sub_824B7CD8(ctx, base);
loc_824B9D08:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824b7e30
	ctx.lr = 0x824B9D14;
	sub_824B7E30(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne 0x824b9cf4
	if (!ctx.cr0.eq) goto loc_824B9CF4;
	// bl 0x826ccc54
	ctx.lr = 0x824B9D24;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r26,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r26.u32);
loc_824B9D28:
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B9D40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_824B9D48:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ccc54
	ctx.lr = 0x824B9D50;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r11,r23,4
	ctx.r11.s64 = ctx.r23.s64 + 4;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x826ccc54
	ctx.lr = 0x824B9D5C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x824b9d70
	if (ctx.cr6.eq) goto loc_824B9D70;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r4,26508(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 26508);
	// bl 0x824c6550
	ctx.lr = 0x824B9D70;
	sub_824C6550(ctx, base);
loc_824B9D70:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x824b9d84
	if (ctx.cr6.eq) goto loc_824B9D84;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,26508(r24)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r24.u32 + 26508);
	// bl 0x824c6550
	ctx.lr = 0x824B9D84;
	sub_824C6550(ctx, base);
loc_824B9D84:
	// cmplwi cr6,r21,3
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 3, ctx.xer);
	// bne cr6,0x824b9d98
	if (!ctx.cr6.eq) goto loc_824B9D98;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x826cce64
	ctx.lr = 0x824B9D94;
	__imp__RtlNtStatusToDosError(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_824B9D98:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x826a02c8
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D03D8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwinm r3,r11,29,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D0688) {
	REX_FUNC_PROLOGUE();
	// lwz r11,11856(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 11856);
	// rlwinm r3,r11,11,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 11) & 0x7;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D0870) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r4,r11,0,0,28
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8) | (ctx.r4.u64 & 0xFFFFFFFF00000007);
	// stw r4,10556(r3)
	REX_STORE_U32(ctx.r3.u32 + 10556, ctx.r4.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D0C28) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,15,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0x7;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D0D50) {
	REX_FUNC_PROLOGUE();
	// lbz r3,10499(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 10499);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D0DD0) {
	REX_FUNC_PROLOGUE();
	// lbz r3,10494(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 10494);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D0FF8) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// stw r11,10752(r3)
	REX_STORE_U32(ctx.r3.u32 + 10752, ctx.r11.u32);
	// ld r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 32);
	// oris r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 524288;
	// std r11,32(r3)
	REX_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D1480) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10540);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D1540) {
	REX_FUNC_PROLOGUE();
	// lhz r11,10544(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 10544);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D1828) {
	REX_FUNC_PROLOGUE();
	// lwz r3,12048(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12048);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D1A40) {
	REX_FUNC_PROLOGUE();
	// lwz r3,10704(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 10704);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D1BF0) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x824D1BF8;
	__savegprlr_29(ctx, base);
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// lbz r9,11932(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 11932);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r8,10872
	ctx.r8.s64 = ctx.r8.s64 + 10872;
	// rlwinm r7,r5,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// lwz r31,12(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// rlwinm r6,r6,22,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 22) & 0x1;
	// lwzx r8,r9,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r29,r7,11,20,20
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 11) & 0x800) | (ctx.r29.u64 & 0xFFFFFFFFFFFFF7FF);
	// or r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r29,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r29.u32);
	// rldicr r6,r30,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// srd r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r8.u8 & 0x7F));
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r31,r9,21,9,10
	ctx.r31.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0x600000) | (ctx.r31.u64 & 0xFFFFFFFFFF9FFFFF);
	// rlwimi r31,r9,21,4,6
	ctx.r31.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0xE000000) | (ctx.r31.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r31,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r31.u32);
	// lbz r9,12010(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 12010);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r31.u32, 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// rlwinm r10,r9,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwimi r6,r7,31,13,31
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFF) | (ctx.r6.u64 & 0xFFFFFFFFFFF80000);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwimi r6,r7,31,1,11
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FF00000) | (ctx.r6.u64 & 0xFFFFFFFF800FFFFF);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// rlwinm r7,r6,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFF;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r10,r29,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824D9C50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x824D9C58;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x826ccd04
	ctx.lr = 0x824D9C64;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x824d9c78
	if (!ctx.cr6.eq) goto loc_824D9C78;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1984(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1984);
	// b 0x824d9c80
	goto loc_824D9C80;
loc_824D9C78:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,1980(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1980);
loc_824D9C80:
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r26,r31,16712
	ctx.r26.s64 = ctx.r31.s64 + 16712;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826cd0a4
	ctx.lr = 0x824D9C90;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r10,16564(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16564);
	// lwz r11,21556(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21556);
	// rlwinm r29,r30,24,28,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r27,r30,24
	ctx.r27.u64 = ctx.r30.u32 & 0xFF;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// stw r10,16564(r31)
	REX_STORE_U32(ctx.r31.u32 + 16564, ctx.r10.u32);
	// rlwinm r30,r30,0,0,19
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFF000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// bne cr6,0x824d9cc0
	if (!ctx.cr6.eq) goto loc_824D9CC0;
	// li r28,60
	ctx.r28.s64 = 60;
loc_824D9CC0:
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// lwz r10,16552(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16552);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// subf r24,r10,r11
	ctx.r24.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x826cd344
	ctx.lr = 0x824D9CD4;
	__imp__KeQueryPerformanceFrequency(ctx, base);
	// rotlwi r11,r3,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// mulli r10,r24,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(100));
	// divwu r11,r11,r28
	ctx.r11.u64 = uint32_t(ctx.r28.u32 ? ctx.r11.u32 / ctx.r28.u32 : 0);
	// twllei r28,0
	if (ctx.r28.s32 == 0 || ctx.r28.u32 < 0u) ppc_trap(ctx, base, 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r10,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r7,100
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 100, ctx.xer);
	// ble cr6,0x824d9cfc
	if (!ctx.cr6.gt) goto loc_824D9CFC;
	// li r7,100
	ctx.r7.s64 = 100;
loc_824D9CFC:
	// lwz r8,16556(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 16556);
	// lwz r10,16548(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16548);
	// add r11,r8,r29
	ctx.r11.u64 = ctx.r8.u64 + ctx.r29.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x824d9d28
	if (ctx.cr6.gt) goto loc_824D9D28;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x824d9d28
	if (ctx.cr6.eq) goto loc_824D9D28;
	// cmplw cr6,r7,r27
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r27.u32, ctx.xer);
	// ble cr6,0x824d9d28
	if (!ctx.cr6.gt) goto loc_824D9D28;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_824D9D28:
	// lwz r9,16540(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16540);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824d9d68
	if (ctx.cr6.eq) goto loc_824D9D68;
	// lwz r6,16564(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 16564);
	// addic r5,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r5.s64 = ctx.r30.s64 + -1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subfe r11,r5,r30
	temp.u8 = (~ctx.r5.u32 + ctx.r30.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r5.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x824D9D64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_824D9D68:
	// lwz r10,16548(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16548);
	// stw r11,16556(r31)
	REX_STORE_U32(ctx.r31.u32 + 16556, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x824d9dac
	if (ctx.cr6.eq) goto loc_824D9DAC;
	// lwz r10,16564(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16564);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x824d9dac
	if (ctx.cr6.eq) goto loc_824D9DAC;
	// lwz r10,16704(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16704);
	// rlwinm r10,r10,3,25,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x78;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r9,r10,16572
	ctx.r9.s64 = ctx.r10.s64 + 16572;
	// stw r11,16576(r10)
	REX_STORE_U32(ctx.r10.u32 + 16576, ctx.r11.u32);
	// stw r30,16572(r10)
	REX_STORE_U32(ctx.r10.u32 + 16572, ctx.r30.u32);
	// lwz r11,16704(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16704);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16704(r31)
	REX_STORE_U32(ctx.r31.u32 + 16704, ctx.r11.u32);
	// b 0x824d9de8
	goto loc_824D9DE8;
loc_824D9DAC:
	// lwz r11,16568(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16568);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,16568(r31)
	REX_STORE_U32(ctx.r31.u32 + 16568, ctx.r11.u32);
	// beq cr6,0x824d9dd4
	if (ctx.cr6.eq) goto loc_824D9DD4;
	// lis r11,32712
	ctx.r11.s64 = 2143813632;
	// stw r30,24848(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 24848, ctx.r30.u32);
	// eieio 
	// sync 
	// b 0x824d9de0
	goto loc_824D9DE0;
loc_824D9DD4:
	// lwz r11,10900(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10900);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_824D9DE0:
	// mftb r11
	ctx.r11.u64 = REX_QUERY_TIMEBASE();
	// stw r11,23376(r31)
	REX_STORE_U32(ctx.r31.u32 + 23376, ctx.r11.u32);
loc_824D9DE8:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826cd094
	ctx.lr = 0x824D9DF4;
	__imp__KfReleaseSpinLock(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824E4B98) {
	REX_FUNC_PROLOGUE();
	// cmpdi cr6,r3,0
	ctx.cr6.compare<int64_t>(ctx.r3.s64, 0, ctx.xer);
	// bge cr6,0x824e4ba8
	if (!ctx.cr6.lt) goto loc_824E4BA8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_824E4BA8:
	// cmpdi cr6,r4,0
	ctx.cr6.compare<int64_t>(ctx.r4.s64, 0, ctx.xer);
	// bne cr6,0x824e4bbc
	if (!ctx.cr6.eq) goto loc_824E4BBC;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// blr 
	return;
loc_824E4BBC:
	// cmpd cr6,r3,r4
	ctx.cr6.compare<int64_t>(ctx.r3.s64, ctx.r4.s64, ctx.xer);
	// blt cr6,0x824e4bd0
	if (ctx.cr6.lt) goto loc_824E4BD0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65534
	ctx.r3.u64 = ctx.r3.u64 | 65534;
	// blr 
	return;
loc_824E4BD0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// tdllei r4,0
	if (ctx.r4.s64 == 0ll || ctx.r4.u64 < 0ull) ppc_trap(ctx, base, 0);
	// ori r11,r11,65534
	ctx.r11.u64 = ctx.r11.u64 | 65534;
	// mulld r10,r3,r11
	ctx.r10.s64 = static_cast<int64_t>(ctx.r3.u64 * ctx.r11.u64);
	// rotldi r11,r10,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 1);
	// divd r10,r10,r4
	ctx.r10.s64 = (ctx.r4.s64 && !(ctx.r10.s64 == INT64_MIN && ctx.r4.s64 == -1)) ? ctx.r10.s64 / ctx.r4.s64 : 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// andc r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 & ~ctx.r11.u64;
	// tdlgei r11,-1
	if (ctx.r11.s64 == -1ll || ctx.r11.u64 > 18446744073709551615ull) ppc_trap(ctx, base, 0);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824E8AC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f29.u64);
	// stfd f30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f30.u64);
	// stfd f31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fabs f13,f1
	ctx.f13.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lfs f0,2884(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x824e8b3c
	if (!ctx.cr6.lt) goto loc_824E8B3C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fabs f1,f1
	ctx.f1.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lfs f2,14300(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14300);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x824e80c8
	ctx.lr = 0x824E8B00;
	sub_824E80C8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f2,6380(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6380);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x824e80c8
	ctx.lr = 0x824E8B14;
	sub_824E80C8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,12904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12904);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f0,-3148(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24632(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24632);
	ctx.f13.f64 = double(temp.f32);
	// fmsubs f0,f30,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f30.f64, ctx.f0.f64, -ctx.f12.f64)));
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// b 0x824e8ba8
	goto loc_824E8BA8;
loc_824E8B3C:
	// fabs f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f2,6380(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6380);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// bge cr6,0x824e8ba0
	if (!ctx.cr6.lt) goto loc_824E8BA0;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x824e80c8
	ctx.lr = 0x824E8B58;
	sub_824E80C8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// fabs f1,f31
	ctx.f1.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lfs f30,14300(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14300);
	ctx.f30.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// bl 0x824e80c8
	ctx.lr = 0x824E8B70;
	sub_824E80C8(ctx, base);
	// fmuls f11,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fabs f10,f31
	ctx.f10.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,12904(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,19212(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 19212);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4832(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4832);
	ctx.f12.f64 = double(temp.f32);
	// fmsubs f0,f29,f0,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f11.f64)));
	// fnmsubs f0,f10,f13,f0
	ctx.f0.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f13.f64, -ctx.f0.f64)));
	// fadds f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// b 0x824e8ba8
	goto loc_824E8BA8;
loc_824E8BA0:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f1,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f1.f64 = double(temp.f32);
loc_824E8BA8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f30,-24(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824F0DC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x824F0DD0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x824f0e28
	if (!ctx.cr6.gt) goto loc_824F0E28;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_824F0DF0:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r3,64(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824f0e14
	if (ctx.cr6.eq) goto loc_824F0E14;
	// bl 0x826cd704
	ctx.lr = 0x824F0E08;
	__imp__XMAReleaseContext(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stw r28,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r28.u32);
loc_824F0E14:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,96
	ctx.r31.s64 = ctx.r31.s64 + 96;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x824f0df0
	if (ctx.cr6.lt) goto loc_824F0DF0;
loc_824F0E28:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,0,14,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFBFFFF;
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F2700) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r3,84
	ctx.r3.s64 = ctx.r3.s64 + 84;
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x826a1130
	ctx.lr = 0x824F2728;
	rexcrt_memcpy(ctx, base);
	// lbz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,144(r30)
	REX_STORE_U8(ctx.r30.u32 + 144, ctx.r11.u8);
	// bl 0x824f2560
	ctx.lr = 0x824F273C;
	sub_824F2560(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x824f4a78
	ctx.lr = 0x824F2748;
	sub_824F4A78(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x824f27c0
	if (ctx.cr6.lt) goto loc_824F27C0;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r1,104
	ctx.r11.s64 = ctx.r1.s64 + 104;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_824F2760:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x824f2760
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F2760;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// li r5,56
	ctx.r5.s64 = 56;
	// stb r9,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r9.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// bl 0x826a1130
	ctx.lr = 0x824F2784;
	rexcrt_memcpy(ctx, base);
	// lbz r10,59(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 59);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,64(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 64);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// li r6,255
	ctx.r6.s64 = 255;
	// lwz r7,84(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r30,76
	ctx.r4.s64 = ctx.r30.s64 + 76;
	// stb r10,180(r1)
	REX_STORE_U8(ctx.r1.u32 + 180, ctx.r10.u8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r9,181(r1)
	REX_STORE_U8(ctx.r1.u32 + 181, ctx.r9.u8);
	// stw r8,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// stw r7,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
	// bl 0x824f5510
	ctx.lr = 0x824F27C0;
	sub_824F5510(ctx, base);
loc_824F27C0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824F66B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a026c
	ctx.lr = 0x824F66B8;
	__savegprlr_17(ctx, base);
	// stfd f30,-144(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.f30.u64);
	// stfd f31,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.f31.u64);
	// lwz r6,12(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lfs f0,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stfs f0,0(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// addi r22,r3,20
	ctx.r22.s64 = ctx.r3.s64 + 20;
	// subf r25,r6,r7
	ctx.r25.u64 = ctx.r7.u64 - ctx.r6.u64;
	// cmplwi cr6,r25,4
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 4, ctx.xer);
	// bgt cr6,0x824f66f0
	if (ctx.cr6.gt) goto loc_824F66F0;
	// subf r11,r7,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r7.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// ble cr6,0x824f66f4
	if (!ctx.cr6.gt) goto loc_824F66F4;
loc_824F66F0:
	// li r31,1
	ctx.r31.s64 = 1;
loc_824F66F4:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r24,r3,4
	ctx.r24.s64 = ctx.r3.s64 + 4;
	// addi r23,r3,24
	ctx.r23.s64 = ctx.r3.s64 + 24;
	// lfs f0,23432(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23432);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-160(r1)
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.f13.u64);
	// lwz r9,-156(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -156);
	// rlwinm r8,r9,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r8,256
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 256, ctx.xer);
	// bge cr6,0x824f6af8
	if (!ctx.cr6.lt) goto loc_824F6AF8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r31,-32246
	ctx.r31.s64 = -2113273856;
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// lfs f10,2884(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2884);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,-25448(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -25448);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f10,f12
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// blt cr6,0x824f6868
	if (ctx.cr6.lt) goto loc_824F6868;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r30,r8,30,2,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r29,r7,r10
	ctx.r29.u64 = ctx.r10.u64 - ctx.r7.u64;
	// rlwinm r28,r8,0,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r7,r6,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r6.u64;
	// addi r31,r9,-4
	ctx.r31.s64 = ctx.r9.s64 + -4;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// add r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 + ctx.r10.u64;
	// addi r27,r28,1
	ctx.r27.s64 = ctx.r28.s64 + 1;
	// addi r6,r29,2
	ctx.r6.s64 = ctx.r29.s64 + 2;
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// addi r30,r4,-8
	ctx.r30.s64 = ctx.r4.s64 + -8;
	// addi r9,r5,12
	ctx.r9.s64 = ctx.r5.s64 + 12;
	// subf r26,r5,r4
	ctx.r26.u64 = ctx.r4.u64 - ctx.r5.u64;
	// rlwinm r28,r29,2,16,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFC;
loc_824F678C:
	// fsubs f9,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// add r21,r29,r25
	ctx.r21.u64 = ctx.r29.u64 + ctx.r25.u64;
	// addi r20,r7,-1
	ctx.r20.s64 = ctx.r7.s64 + -1;
	// lfsx f7,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r19,r6,-1
	ctx.r19.s64 = ctx.r6.s64 + -1;
	// fadds f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// rlwinm r28,r21,2,16,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFC;
	// lfs f6,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// rlwinm r21,r20,2,16,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFC;
	// fmuls f4,f7,f13
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// rlwinm r20,r19,2,16,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFC;
	// lfs f5,12(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// addi r19,r7,1
	ctx.r19.s64 = ctx.r7.s64 + 1;
	// lfsu f11,16(r30)
	ea = 16 + ctx.r30.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f11.f64 = double(temp.f32);
	ctx.r30.u32 = ea;
	// rlwinm r18,r7,2,16,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFC;
	// lfsx f3,r26,r9
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + ctx.r9.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfsx f2,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r17,r6,2,16,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFC;
	// stfs f6,4(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// rlwinm r28,r19,2,16,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFC;
	// fsubs f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// lfsx f13,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f6,r20,r11
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// stfs f5,8(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// fmuls f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lfsx f9,r18,r11
	temp.u32 = REX_LOAD_U32(ctx.r18.u32 + ctx.r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fadds f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f0.f64));
	// lfsx f31,r17,r11
	temp.u32 = REX_LOAD_U32(ctx.r17.u32 + ctx.r11.u32);
	ctx.f31.f64 = double(temp.f32);
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// fmuls f1,f9,f1
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f1.f64));
	// lfsx f11,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fadds f30,f7,f0
	ctx.f30.f64 = double(float(ctx.f7.f64 + ctx.f0.f64));
	// addi r28,r6,1
	ctx.r28.s64 = ctx.r6.s64 + 1;
	// fmadds f4,f2,f12,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f2.f64, ctx.f12.f64, ctx.f4.f64)));
	// stfs f4,-8(r9)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// rlwinm r21,r28,2,16,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFC;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fmadds f2,f6,f8,f5
	ctx.f2.f64 = double(float(std::fma(ctx.f6.f64, ctx.f8.f64, ctx.f5.f64)));
	// stfs f2,-4(r9)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// fmadds f1,f31,f7,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f31.f64, ctx.f7.f64, ctx.f1.f64)));
	// stfs f1,0(r9)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lfsx f13,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r28,r29,2,16,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFC;
	// stfsu f3,16(r31)
	ea = 16 + ctx.r31.u32;
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r31.u32 = ea;
	// fmadds f11,f13,f30,f9
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f30.f64, ctx.f9.f64)));
	// stfs f11,4(r9)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bdnz 0x824f678c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F678C;
	// stfs f12,0(r24)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
loc_824F6868:
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x824f68f0
	if (ctx.cr6.gt) goto loc_824F68F0;
	// subf r7,r27,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r27.u64;
	// lwz r28,8(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r26,12(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r9,r27,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r29,r9,r4
	ctx.r29.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r30,r9,r5
	ctx.r30.u64 = ctx.r9.u64 + ctx.r5.u64;
	// addi r31,r6,-4
	ctx.r31.s64 = ctx.r6.s64 + -4;
	// subf r9,r28,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r28.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// addi r6,r29,-8
	ctx.r6.s64 = ctx.r29.s64 + -8;
	// addi r30,r30,-4
	ctx.r30.s64 = ctx.r30.s64 + -4;
	// subf r29,r26,r28
	ctx.r29.u64 = ctx.r28.u64 - ctx.r26.u64;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
loc_824F68B4:
	// rlwinm r7,r9,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFC;
	// lfsu f11,4(r6)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r6.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f11.f64 = double(temp.f32);
	ctx.r6.u32 = ea;
	// add r28,r29,r9
	ctx.r28.u64 = ctx.r29.u64 + ctx.r9.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r28,r28,2,16,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFC;
	// lfsx f9,r7,r11
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfsx f7,r28,r11
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// stfsu f11,4(r31)
	ea = 4 + ctx.r31.u32;
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r31.u32 = ea;
	// fmadds f6,f7,f12,f8
	ctx.f6.f64 = double(float(std::fma(ctx.f7.f64, ctx.f12.f64, ctx.f8.f64)));
	// stfsu f6,4(r30)
	ea = 4 + ctx.r30.u32;
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r30.u32 = ea;
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// bdnz 0x824f68b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F68B4;
	// stfs f12,0(r24)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
loc_824F68F0:
	// lwz r27,16(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r27,r9
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x824f6908
	if (ctx.cr6.eq) goto loc_824F6908;
	// fmr f12,f10
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f10.f64;
	// b 0x824f6910
	goto loc_824F6910;
loc_824F6908:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,2880(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2880);
	ctx.f12.f64 = double(temp.f32);
loc_824F6910:
	// subfic r7,r8,256
	ctx.xer.ca = ctx.r8.u32 <= 256;
	ctx.r7.u64 = static_cast<uint64_t>(256) - ctx.r8.u64;
	// stfs f12,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
	// fsubs f13,f10,f12
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// stw r9,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r27,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r27.u32);
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// cmpwi cr6,r7,4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 4, ctx.xer);
	// blt cr6,0x824f6a6c
	if (ctx.cr6.lt) goto loc_824F6A6C;
	// subfic r9,r8,252
	ctx.xer.ca = ctx.r8.u32 <= 252;
	ctx.r9.u64 = static_cast<uint64_t>(252) - ctx.r8.u64;
	// lwz r25,12(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// subf r29,r25,r10
	ctx.r29.u64 = ctx.r10.u64 - ctx.r25.u64;
	// addi r31,r8,2
	ctx.r31.s64 = ctx.r8.s64 + 2;
	// rlwinm r28,r9,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// add r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 + ctx.r11.u64;
	// rlwinm r26,r31,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r29,2
	ctx.r6.s64 = ctx.r29.s64 + 2;
	// subf r30,r27,r10
	ctx.r30.u64 = ctx.r10.u64 - ctx.r27.u64;
	// addi r29,r7,-4
	ctx.r29.s64 = ctx.r7.s64 + -4;
	// addi r7,r9,-4
	ctx.r7.s64 = ctx.r9.s64 + -4;
	// add r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 + ctx.r10.u64;
	// add r9,r26,r5
	ctx.r9.u64 = ctx.r26.u64 + ctx.r5.u64;
	// add r28,r28,r8
	ctx.r28.u64 = ctx.r28.u64 + ctx.r8.u64;
	// addi r31,r30,2
	ctx.r31.s64 = ctx.r30.s64 + 2;
	// subf r26,r5,r4
	ctx.r26.u64 = ctx.r4.u64 - ctx.r5.u64;
	// subf r27,r25,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r25.u64;
	// rlwinm r8,r30,2,16,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFC;
loc_824F6990:
	// fadds f11,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// add r25,r27,r30
	ctx.r25.u64 = ctx.r27.u64 + ctx.r30.u64;
	// lfsx f10,r8,r11
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r8,r31,-1
	ctx.r8.s64 = ctx.r31.s64 + -1;
	// rlwinm r25,r25,2,16,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFC;
	// lfs f9,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r8,r8,2,16,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFC;
	// fsubs f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// addi r21,r6,-1
	ctx.r21.s64 = ctx.r6.s64 + -1;
	// fmuls f5,f10,f13
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f8,8(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// addi r20,r31,1
	ctx.r20.s64 = ctx.r31.s64 + 1;
	// rlwinm r21,r21,2,16,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFC;
	// lfsx f6,r9,r26
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r26.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f4,r25,r11
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r25,r31,2,16,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFC;
	// stfs f9,4(r7)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// rlwinm r19,r6,2,16,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFC;
	// lfsx f1,r8,r11
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r20,r20,2,16,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFC;
	// fadds f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// addi r8,r6,1
	ctx.r8.s64 = ctx.r6.s64 + 1;
	// fmuls f11,f1,f11
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// lfsx f3,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f10,f7,f0
	ctx.f10.f64 = double(float(ctx.f7.f64 - ctx.f0.f64));
	// stfs f8,8(r7)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// fmadds f7,f3,f7,f11
	ctx.f7.f64 = double(float(std::fma(ctx.f3.f64, ctx.f7.f64, ctx.f11.f64)));
	// lfsx f3,r25,r11
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + ctx.r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// fadds f9,f2,f0
	ctx.f9.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// rlwinm r21,r8,2,16,29
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFC;
	// fmuls f2,f3,f2
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// stfs f7,0(r9)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fmadds f8,f4,f12,f5
	ctx.f8.f64 = double(float(std::fma(ctx.f4.f64, ctx.f12.f64, ctx.f5.f64)));
	// lfsx f4,r19,r11
	temp.u32 = REX_LOAD_U32(ctx.r19.u32 + ctx.r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// stfs f6,12(r7)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// fsubs f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// lfsx f11,r20,r11
	temp.u32 = REX_LOAD_U32(ctx.r20.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f1,f4,f10,f2
	ctx.f1.f64 = double(float(std::fma(ctx.f4.f64, ctx.f10.f64, ctx.f2.f64)));
	// fmuls f10,f11,f9
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// stfs f8,-4(r9)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// lfsx f8,r21,r11
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + ctx.r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lfsu f13,16(r29)
	ea = 16 + ctx.r29.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r29.u32 = ea;
	// fmadds f7,f8,f5,f10
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f5.f64, ctx.f10.f64)));
	// stfs f1,4(r9)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// stfsu f13,16(r7)
	ea = 16 + ctx.r7.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r7.u32 = ea;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// stfs f7,8(r9)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// rlwinm r8,r30,2,16,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFC;
	// fsubs f12,f5,f0
	ctx.f12.f64 = double(float(ctx.f5.f64 - ctx.f0.f64));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fadds f13,f9,f0
	ctx.f13.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// bdnz 0x824f6990
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F6990;
	// stfs f12,0(r24)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
loc_824F6A6C:
	// cmplwi cr6,r28,256
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 256, ctx.xer);
	// bge cr6,0x824f6aec
	if (!ctx.cr6.lt) goto loc_824F6AEC;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r7,r28,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r30,12(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subfic r8,r28,256
	ctx.xer.ca = ctx.r28.u32 <= 256;
	ctx.r8.u64 = static_cast<uint64_t>(256) - ctx.r28.u64;
	// lfs f12,0(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r3,r7,r4
	ctx.r3.u64 = ctx.r7.u64 + ctx.r4.u64;
	// addi r4,r6,-4
	ctx.r4.s64 = ctx.r6.s64 + -4;
	// subf r9,r31,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r31.u64;
	// addi r6,r3,-4
	ctx.r6.s64 = ctx.r3.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// subf r3,r30,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r30.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
loc_824F6AB0:
	// rlwinm r8,r9,2,16,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFC;
	// lfsu f11,4(r6)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r6.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f11.f64 = double(temp.f32);
	ctx.r6.u32 = ea;
	// add r31,r3,r9
	ctx.r31.u64 = ctx.r3.u64 + ctx.r9.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r31,r31,2,16,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFC;
	// lfsx f10,r8,r11
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfsx f8,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfsu f11,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r4.u32 = ea;
	// fmadds f7,f8,f12,f9
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f12.f64, ctx.f9.f64)));
	// stfsu f7,4(r7)
	ea = 4 + ctx.r7.u32;
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r7.u32 = ea;
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// bdnz 0x824f6ab0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F6AB0;
	// stfs f12,0(r24)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
loc_824F6AEC:
	// clrlwi r11,r10,18
	ctx.r11.u64 = ctx.r10.u32 & 0x3FFF;
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// b 0x824f6ccc
	goto loc_824F6CCC;
loc_824F6AF8:
	// addi r30,r10,256
	ctx.r30.s64 = ctx.r10.s64 + 256;
	// cmplwi cr6,r30,16384
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 16384, ctx.xer);
	// bge cr6,0x824f6c4c
	if (!ctx.cr6.lt) goto loc_824F6C4C;
	// subf r9,r6,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r6.u64;
	// addi r11,r9,256
	ctx.r11.s64 = ctx.r9.s64 + 256;
	// cmplwi cr6,r11,16384
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16384, ctx.xer);
	// bge cr6,0x824f6c4c
	if (!ctx.cr6.lt) goto loc_824F6C4C;
	// subf r11,r7,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r7.u64;
	// addi r8,r11,256
	ctx.r8.s64 = ctx.r11.s64 + 256;
	// cmplwi cr6,r8,16384
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16384, ctx.xer);
	// bge cr6,0x824f6c4c
	if (!ctx.cr6.lt) goto loc_824F6C4C;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blt cr6,0x824f6c4c
	if (ctx.cr6.lt) goto loc_824F6C4C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x824f6c4c
	if (ctx.cr6.lt) goto loc_824F6C4C;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// bne cr6,0x824f6bc8
	if (!ctx.cr6.eq) goto loc_824F6BC8;
	// li r7,65
	ctx.r7.s64 = 65;
	// li r8,16
	ctx.r8.s64 = 16;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r5,4
	ctx.r9.s64 = ctx.r5.s64 + 4;
	// subf r10,r10,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
loc_824F6B64:
	// lvrx128 v63,r8,r4
	temp.u32 = ctx.r8.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// lvrx128 v61,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvlx128 v59,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vor128 v58,v59,v61
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// stvlx128 v60,r0,r11
	ea = ctx.r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v60.u8[15 - i]);
	// stvrx128 v60,r11,r8
	ea = ctx.r11.u32 + ctx.r8.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v60.u8[i]);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stvlx128 v58,r0,r9
	ea = ctx.r9.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v58.u8[15 - i]);
	// stvrx128 v58,r9,r8
	ea = ctx.r9.u32 + ctx.r8.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v58.u8[i]);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bdnz 0x824f6b64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F6B64;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// stw r30,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r30.u32);
	// lfs f0,-25452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25452);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f0,0(r24)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
	// lfs f0,1024(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 1024);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r22)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r22.u32 + 0, temp.u32);
	// lfd f30,-144(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x826a02bc
	__restgprlr_17(ctx, base);
	return;
loc_824F6BC8:
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r9,256
	ctx.r9.s64 = 256;
	// subf r10,r7,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r7.u64;
	// subf r7,r6,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r6.u64;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lfs f13,2884(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2884);
	ctx.f13.f64 = double(temp.f32);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// addi r11,r4,-4
	ctx.r11.s64 = ctx.r4.s64 + -4;
	// lfs f12,-25448(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -25448);
	ctx.f12.f64 = double(temp.f32);
loc_824F6C04:
	// lfs f11,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfsx f9,r7,r10
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsu f11,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f11.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfsu f11,4(r9)
	ea = 4 + ctx.r9.u32;
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmadds f8,f9,f0,f10
	ctx.f8.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f10.f64)));
	// stfsu f8,4(r8)
	ea = 4 + ctx.r8.u32;
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r8.u32 = ea;
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// bdnz 0x824f6c04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F6C04;
	// stfs f0,0(r24)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
	// stw r30,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r30.u32);
	// lfs f0,1024(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 1024);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r22)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r22.u32 + 0, temp.u32);
	// lfd f30,-144(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x826a02bc
	__restgprlr_17(ctx, base);
	return;
loc_824F6C4C:
	// li r8,256
	ctx.r8.s64 = 256;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
	// lis r31,-32256
	ctx.r31.s64 = -2113929216;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r3,32
	ctx.r9.s64 = ctx.r3.s64 + 32;
	// subf r11,r7,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r7.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// addi r8,r4,-4
	ctx.r8.s64 = ctx.r4.s64 + -4;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lfs f13,2884(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2884);
	ctx.f13.f64 = double(temp.f32);
	// add r7,r6,r9
	ctx.r7.u64 = ctx.r6.u64 + ctx.r9.u64;
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r6,r7,-4
	ctx.r6.s64 = ctx.r7.s64 + -4;
	// addi r10,r10,256
	ctx.r10.s64 = ctx.r10.s64 + 256;
	// lfs f12,-25448(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -25448);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r7,r11,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFC;
loc_824F6C90:
	// lfsx f11,r7,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	ctx.f11.f64 = double(temp.f32);
	// add r7,r11,r25
	ctx.r7.u64 = ctx.r11.u64 + ctx.r25.u64;
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r4,r7,2,16,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFC;
	// lfsu f11,4(r8)
	ea = 4 + ctx.r8.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f11.f64 = double(temp.f32);
	ctx.r8.u32 = ea;
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// rlwinm r7,r11,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFC;
	// lfsx f9,r4,r9
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	ctx.f9.f64 = double(temp.f32);
	// stfsu f11,4(r6)
	ea = 4 + ctx.r6.u32;
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r6.u32 = ea;
	// fmadds f8,f9,f0,f10
	ctx.f8.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f10.f64)));
	// stfsu f8,4(r3)
	ea = 4 + ctx.r3.u32;
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r3.u32 = ea;
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// bdnz 0x824f6c90
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824F6C90;
	// stfs f0,0(r24)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r24.u32 + 0, temp.u32);
loc_824F6CCC:
	// clrlwi r11,r10,18
	ctx.r11.u64 = ctx.r10.u32 & 0x3FFF;
	// lfs f0,1024(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 1024);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r22)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r22.u32 + 0, temp.u32);
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// lfd f30,-144(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x826a02bc
	__restgprlr_17(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82520698) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x825206A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32128
	ctx.r11.s64 = -2105540608;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r11,5696
	ctx.r3.s64 = ctx.r11.s64 + 5696;
	// bl 0x82515280
	ctx.lr = 0x825206B4;
	sub_82515280(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32099
	ctx.r9.s64 = -2103640064;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r31,-14
	ctx.r31.s64 = -14;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r9,-26240
	ctx.r3.s64 = ctx.r9.s64 + -26240;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// bl 0x825194a0
	ctx.lr = 0x825206DC;
	sub_825194A0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825206F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r6,-14180
	ctx.r4.s64 = ctx.r6.s64 + -14180;
	// stw r5,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r5.u32);
	// bl 0x82514280
	ctx.lr = 0x82520710;
	sub_82514280(ctx, base);
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82522410) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82522438
	if (!ctx.cr6.eq) goto loc_82522438;
	// lis r11,2560
	ctx.r11.s64 = 167772160;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_82522438:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8252244c
	if (!ctx.cr6.eq) goto loc_8252244C;
	// lis r11,3584
	ctx.r11.s64 = 234881024;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8252244C:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82522460
	if (!ctx.cr6.eq) goto loc_82522460;
	// lis r11,240
	ctx.r11.s64 = 15728640;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82522460:
	// addi r5,r31,20
	ctx.r5.s64 = ctx.r31.s64 + 20;
	// addi r4,r31,16
	ctx.r4.s64 = ctx.r31.s64 + 16;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x82524b58
	ctx.lr = 0x82522470;
	sub_82524B58(ctx, base);
	// lis r11,-32051
	ctx.r11.s64 = -2100494336;
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r10,r11,-5608
	ctx.r10.s64 = ctx.r11.s64 + -5608;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82522488:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82522488
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82522488;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825258D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r4,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82525914
	if (ctx.cr6.eq) goto loc_82525914;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82525914;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82525914:
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ccc44
	ctx.lr = 0x82525920;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// addi r3,r30,10800
	ctx.r3.s64 = ctx.r30.s64 + 10800;
	// bl 0x825255b0
	ctx.lr = 0x8252592C;
	sub_825255B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ccc54
	ctx.lr = 0x82525934;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825277D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x825277E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,260
	ctx.r11.s64 = 260;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// bl 0x82526248
	ctx.lr = 0x82527808;
	sub_82526248(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825278a0
	if (ctx.cr6.eq) goto loc_825278A0;
	// lwz r29,84(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// lwz r28,96(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r5,r11,-13504
	ctx.r5.s64 = ctx.r11.s64 + -13504;
	// lwz r6,148(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8252783C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r8,-257
	ctx.r8.s64 = -16842752;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r7,r8,65534
	ctx.r7.u64 = ctx.r8.u64 | 65534;
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// beq cr6,0x82527860
	if (ctx.cr6.eq) goto loc_82527860;
	// lis r11,-257
	ctx.r11.s64 = -16842752;
	// ori r10,r11,65521
	ctx.r10.u64 = ctx.r11.u64 | 65521;
	// cmpw cr6,r3,r10
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x825278a4
	if (!ctx.cr6.eq) goto loc_825278A4;
loc_82527860:
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825355a8
	ctx.lr = 0x82527878;
	sub_825355A8(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r6,148(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82527898;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x825278a4
	goto loc_825278A4;
loc_825278A0:
	// lwz r30,88(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
loc_825278A4:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825278dc
	if (ctx.cr6.eq) goto loc_825278DC;
	// extsw r4,r30
	ctx.r4.s64 = ctx.r30.s32;
	// lwz r5,16(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825278C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge cr6,0x825278dc
	if (!ctx.cr6.lt) goto loc_825278DC;
	// cmpdi cr6,r11,1
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 1, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x825278e0
	if (ctx.cr6.eq) goto loc_825278E0;
loc_825278DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825278E0:
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8252C088) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,320
	ctx.r4.s64 = 320;
	// addi r3,r3,40
	ctx.r3.s64 = ctx.r3.s64 + 40;
	// bl 0x82536bd0
	ctx.lr = 0x8252C0B0;
	sub_82536BD0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8252DDE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x8252DDE8;
	__savegprlr_24(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,62
	ctx.r11.s64 = 62;
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r24,-1
	ctx.r24.s64 = -1;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_8252DE20:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8252de20
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8252DE20;
	// clrlwi r6,r26,16
	ctx.r6.u64 = ctx.r26.u32 & 0xFFFF;
	// stw r28,508(r31)
	REX_STORE_U32(ctx.r31.u32 + 508, ctx.r28.u32);
	// lis r11,-32058
	ctx.r11.s64 = -2100953088;
	// stw r27,1012(r31)
	REX_STORE_U32(ctx.r31.u32 + 1012, ctx.r27.u32);
	// stw r28,760(r31)
	REX_STORE_U32(ctx.r31.u32 + 760, ctx.r28.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r27,1264(r31)
	REX_STORE_U32(ctx.r31.u32 + 1264, ctx.r27.u32);
	// addi r25,r11,27008
	ctx.r25.s64 = ctx.r11.s64 + 27008;
	// beq cr6,0x8252df68
	if (ctx.cr6.eq) goto loc_8252DF68;
	// lwz r11,504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// li r10,3
	ctx.r10.s64 = 3;
	// not r9,r29
	ctx.r9.u64 = ~ctx.r29.u64;
	// rlwimi r11,r10,27,0,5
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0xFC000000) | (ctx.r11.u64 & 0xFFFFFFFF03FFFFFF);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,504(r31)
	REX_STORE_U32(ctx.r31.u32 + 504, ctx.r11.u32);
	// rlwinm r8,r9,28,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x1;
	// bl 0x8252d3e8
	ctx.lr = 0x8252DE70;
	sub_8252D3E8(ctx, base);
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// addi r11,r31,1812
	ctx.r11.s64 = ctx.r31.s64 + 1812;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8252DE84:
	// addi r9,r11,-292
	ctx.r9.s64 = ctx.r11.s64 + -292;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// addi r11,r11,304
	ctx.r11.s64 = ctx.r11.s64 + 304;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8252de84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8252DE84;
	// addi r11,r6,-1
	ctx.r11.s64 = ctx.r6.s64 + -1;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8252df2c
	if (ctx.cr6.gt) goto loc_8252DF2C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8252ded8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8252DED8;
	// bdzf 4*cr6+eq,0x8252dee4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8252DEE4;
	// bdzf 4*cr6+eq,0x8252def0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8252DEF0;
	// bdzf 4*cr6+eq,0x8252defc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8252DEFC;
	// bdzf 4*cr6+eq,0x8252df08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8252DF08;
	// bdzf 4*cr6+eq,0x8252df14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8252DF14;
	// bne cr6,0x8252df20
	if (!ctx.cr6.eq) goto loc_8252DF20;
	// lis r9,6184
	ctx.r9.s64 = 405274624;
	// ori r9,r9,390
	ctx.r9.u64 = ctx.r9.u64 | 390;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DED8:
	// lis r9,10280
	ctx.r9.s64 = 673710080;
	// ori r9,r9,390
	ctx.r9.u64 = ctx.r9.u64 | 390;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DEE4:
	// lis r9,6690
	ctx.r9.s64 = 438435840;
	// ori r9,r9,43869
	ctx.r9.u64 = ctx.r9.u64 | 43869;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DEF0:
	// lis r9,11682
	ctx.r9.s64 = 765591552;
	// ori r9,r9,43940
	ctx.r9.u64 = ctx.r9.u64 | 43940;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DEFC:
	// lis r9,11554
	ctx.r9.s64 = 757202944;
	// ori r9,r9,43941
	ctx.r9.u64 = ctx.r9.u64 | 43941;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DF08:
	// lis r9,11554
	ctx.r9.s64 = 757202944;
	// ori r9,r9,43935
	ctx.r9.u64 = ctx.r9.u64 | 43935;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DF14:
	// lis r9,10280
	ctx.r9.s64 = 673710080;
	// ori r9,r9,324
	ctx.r9.u64 = ctx.r9.u64 | 324;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DF20:
	// lis r9,6184
	ctx.r9.s64 = 405274624;
	// ori r9,r9,323
	ctx.r9.u64 = ctx.r9.u64 | 323;
	// b 0x8252df30
	goto loc_8252DF30;
loc_8252DF2C:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8252DF30:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x8252f9b0
	ctx.lr = 0x8252DF54;
	sub_8252F9B0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8252df68
	if (ctx.cr6.eq) goto loc_8252DF68;
loc_8252DF5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_8252DF68:
	// rlwinm r11,r26,0,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xFFFF0000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8252e090
	if (ctx.cr6.eq) goto loc_8252E090;
	// lwz r9,504(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// rlwimi r9,r8,20,6,11
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 20) & 0x3F00000) | (ctx.r9.u64 & 0xFFFFFFFFFC0FFFFF);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r9,504(r31)
	REX_STORE_U32(ctx.r31.u32 + 504, ctx.r9.u32);
	// bgt cr6,0x8252dfd0
	if (ctx.cr6.gt) goto loc_8252DFD0;
	// beq cr6,0x8252dfc4
	if (ctx.cr6.eq) goto loc_8252DFC4;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8252dfb8
	if (ctx.cr6.eq) goto loc_8252DFB8;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8252dfdc
	if (!ctx.cr6.eq) goto loc_8252DFDC;
	// lis r8,11680
	ctx.r8.s64 = 765460480;
	// ori r8,r8,406
	ctx.r8.u64 = ctx.r8.u64 | 406;
	// b 0x8252dfec
	goto loc_8252DFEC;
loc_8252DFB8:
	// lis r8,11552
	ctx.r8.s64 = 757071872;
	// ori r8,r8,406
	ctx.r8.u64 = ctx.r8.u64 | 406;
	// b 0x8252dfec
	goto loc_8252DFEC;
loc_8252DFC4:
	// lis r8,6690
	ctx.r8.s64 = 438435840;
	// ori r8,r8,407
	ctx.r8.u64 = ctx.r8.u64 | 407;
	// b 0x8252dfec
	goto loc_8252DFEC;
loc_8252DFD0:
	// lis r10,4
	ctx.r10.s64 = 262144;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8252dfe4
	if (ctx.cr6.eq) goto loc_8252DFE4;
loc_8252DFDC:
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8252dfec
	goto loc_8252DFEC;
loc_8252DFE4:
	// lis r8,6690
	ctx.r8.s64 = 438435840;
	// ori r8,r8,344
	ctx.r8.u64 = ctx.r8.u64 | 344;
loc_8252DFEC:
	// addi r30,r31,20672
	ctx.r30.s64 = ctx.r31.s64 + 20672;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8252fb68
	ctx.lr = 0x8252E010;
	sub_8252FB68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8252df5c
	if (!ctx.cr6.eq) goto loc_8252DF5C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8253b4d8
	ctx.lr = 0x8252E024;
	sub_8253B4D8(ctx, base);
	// not r10,r29
	ctx.r10.u64 = ~ctx.r29.u64;
	// clrlwi r11,r29,28
	ctx.r11.u64 = ctx.r29.u32 & 0xF;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// stw r9,20956(r31)
	REX_STORE_U32(ctx.r31.u32 + 20956, ctx.r9.u32);
	// bne cr6,0x8252e070
	if (!ctx.cr6.eq) goto loc_8252E070;
	// rlwinm r11,r29,0,20,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xF00;
	// cmplwi cr6,r11,512
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 512, ctx.xer);
	// beq cr6,0x8252e068
	if (ctx.cr6.eq) goto loc_8252E068;
	// cmplwi cr6,r11,768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 768, ctx.xer);
	// beq cr6,0x8252e060
	if (ctx.cr6.eq) goto loc_8252E060;
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bne cr6,0x8252e088
	if (!ctx.cr6.eq) goto loc_8252E088;
	// li r11,64
	ctx.r11.s64 = 64;
	// b 0x8252e08c
	goto loc_8252E08C;
loc_8252E060:
	// li r11,48
	ctx.r11.s64 = 48;
	// b 0x8252e08c
	goto loc_8252E08C;
loc_8252E068:
	// li r11,32
	ctx.r11.s64 = 32;
	// b 0x8252e08c
	goto loc_8252E08C;
loc_8252E070:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8252e088
	if (!ctx.cr6.eq) goto loc_8252E088;
	// rlwinm r11,r29,0,20,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xF00;
	// cmplwi cr6,r11,512
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 512, ctx.xer);
	// li r11,32
	ctx.r11.s64 = 32;
	// beq cr6,0x8252e08c
	if (ctx.cr6.eq) goto loc_8252E08C;
loc_8252E088:
	// li r11,16
	ctx.r11.s64 = 16;
loc_8252E08C:
	// stw r11,20960(r31)
	REX_STORE_U32(ctx.r31.u32 + 20960, ctx.r11.u32);
loc_8252E090:
	// lwz r11,504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r10,r11,0,13,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFF7FFFF;
	// stw r10,504(r31)
	REX_STORE_U32(ctx.r31.u32 + 504, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8253E1F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x8253E1F8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x8253e264
	if (ctx.cr6.lt) goto loc_8253E264;
	// cmpwi cr6,r4,15
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 15, ctx.xer);
	// bge cr6,0x8253e264
	if (!ctx.cr6.lt) goto loc_8253E264;
	// addi r11,r4,198
	ctx.r11.s64 = ctx.r4.s64 + 198;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r28,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r3.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8253e264
	if (ctx.cr6.eq) goto loc_8253E264;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x8253e234
	if (!ctx.cr6.lt) goto loc_8253E234;
	// li r11,-1
	ctx.r11.s64 = -1;
loc_8253E234:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x824bd0a8
	ctx.lr = 0x8253E23C;
	sub_824BD0A8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x824be070
	ctx.lr = 0x8253E244;
	sub_824BE070(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r3,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r3.u32);
	// blt cr6,0x8253e25c
	if (ctx.cr6.lt) goto loc_8253E25C;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stwx r11,r28,r30
	REX_STORE_U32(ctx.r28.u32 + ctx.r30.u32, ctx.r11.u32);
loc_8253E25C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8253e274
	if (!ctx.cr6.eq) goto loc_8253E274;
loc_8253E264:
	// lis r3,-257
	ctx.r3.s64 = -16842752;
	// ori r3,r3,65518
	ctx.r3.u64 = ctx.r3.u64 | 65518;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_8253E274:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82542C20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// li r9,32
	ctx.r9.s64 = 32;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,64
	ctx.r6.s64 = 64;
	// lvx128 v0,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,80
	ctx.r5.s64 = 80;
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r11,64
	ctx.r31.s64 = ctx.r11.s64 + 64;
	// lvx128 v13,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// stvx128 v13,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r8,r6
	ea = (ctx.r8.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r8,r5
	ea = (ctx.r8.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254A668) {
	REX_FUNC_PROLOGUE();
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8254A7B8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8254AA00) {
	REX_FUNC_PROLOGUE();
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8254ADC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8256b208
	ctx.lr = 0x8254ADD0;
	sub_8256B208(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8254adec
	if (!ctx.cr6.eq) goto loc_8254ADEC;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8254ADEC:
	// lbz r11,215(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 215);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254BD30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8254bd78
	if (ctx.cr6.eq) goto loc_8254BD78;
loc_8254BD54:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8254BD6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r31,r31,44
	ctx.r31.s64 = ctx.r31.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8254bd54
	if (!ctx.cr6.eq) goto loc_8254BD54;
loc_8254BD78:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254DB60) {
	REX_FUNC_PROLOGUE();
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254DC20) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r10,r5,-4
	ctx.r10.s64 = ctx.r5.s64 + -4;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
loc_8254DC38:
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r9,r9,44
	ctx.r9.s64 = ctx.r9.s64 + 44;
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// stw r8,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r7,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// lwz r6,16(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stw r6,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r6.u32);
	// lwz r5,20(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// stw r5,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r5.u32);
	// lwz r8,24(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stw r8,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// lwz r7,28(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// stw r7,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r7.u32);
	// lwz r6,32(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r6,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r6.u32);
	// lwz r5,36(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// stw r5,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r5.u32);
	// lwz r8,40(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// stw r8,40(r10)
	REX_STORE_U32(ctx.r10.u32 + 40, ctx.r8.u32);
	// lwzu r8,44(r11)
	ea = 44 + ctx.r11.u32;
	ctx.r8.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r8,44(r10)
	ea = 44 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// bne cr6,0x8254dc38
	if (!ctx.cr6.eq) goto loc_8254DC38;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82550608) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82550630;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stb r7,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r7.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82551380) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x825513cc
	if (ctx.cr6.eq) goto loc_825513CC;
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x825513a8
	if (ctx.cr6.eq) goto loc_825513A8;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
loc_825513A8:
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x825513cc
	if (ctx.cr6.eq) goto loc_825513CC;
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x825513c4
	if (!ctx.cr6.eq) goto loc_825513C4;
loc_825513BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_825513C4:
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x825513d8
	if (!ctx.cr6.eq) goto loc_825513D8;
loc_825513CC:
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x825513bc
	if (!ctx.cr6.eq) goto loc_825513BC;
loc_825513D8:
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82554A58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82554A60;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// lwz r10,28(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// lwz r11,5996(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5996);
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82554aec
	if (ctx.cr6.gt) goto loc_82554AEC;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-9252
	ctx.r4.s64 = ctx.r11.s64 + -9252;
	// bl 0x821cb5b0
	ctx.lr = 0x82554AA4;
	sub_821CB5B0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821cb4a0
	ctx.lr = 0x82554AB0;
	sub_821CB4A0(ctx, base);
	// bl 0x821c6d10
	ctx.lr = 0x82554AB4;
	sub_821C6D10(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r9,r10,16324
	ctx.r9.s64 = ctx.r10.s64 + 16324;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// bl 0x821caf40
	ctx.lr = 0x82554AC8;
	sub_821CAF40(ctx, base);
	// lwz r8,104(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x82554adc
	if (ctx.cr6.lt) goto loc_82554ADC;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82573808
	ctx.lr = 0x82554ADC;
	sub_82573808(ctx, base);
loc_82554ADC:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r25,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// stb r25,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r25.u8);
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
loc_82554AEC:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,24(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x8254be00
	ctx.lr = 0x82554AFC;
	sub_8254BE00(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82554b2c
	if (ctx.cr6.eq) goto loc_82554B2C;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r31,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r30,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stb r25,20(r3)
	REX_STORE_U8(ctx.r3.u32 + 20, ctx.r25.u8);
	// stb r25,21(r3)
	REX_STORE_U8(ctx.r3.u32 + 21, ctx.r25.u8);
loc_82554B2C:
	// lwz r10,28(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// stw r10,28(r27)
	REX_STORE_U32(ctx.r27.u32 + 28, ctx.r10.u32);
	// bne cr6,0x82554b5c
	if (!ctx.cr6.eq) goto loc_82554B5C;
	// stw r26,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// lwz r10,24(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// stw r26,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r26.u32);
	// b 0x82554b9c
	goto loc_82554B9C;
loc_82554B5C:
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82554b84
	if (ctx.cr6.eq) goto loc_82554B84;
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82554b9c
	if (!ctx.cr6.eq) goto loc_82554B9C;
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// b 0x82554b9c
	goto loc_82554B9C;
loc_82554B84:
	// stw r26,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r26.u32);
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82554b9c
	if (!ctx.cr6.eq) goto loc_82554B9C;
	// stw r26,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
loc_82554B9C:
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// lbz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82554d80
	if (!ctx.cr6.eq) goto loc_82554D80;
loc_82554BB8:
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82554ca0
	if (!ctx.cr6.eq) goto loc_82554CA0;
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82554c00
	if (!ctx.cr6.eq) goto loc_82554C00;
	// rotlwi r9,r4,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stb r30,20(r9)
	REX_STORE_U8(ctx.r9.u32 + 20, ctx.r30.u8);
	// stb r30,20(r10)
	REX_STORE_U8(ctx.r10.u32 + 20, ctx.r30.u8);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stb r25,20(r7)
	REX_STORE_U8(ctx.r7.u32 + 20, ctx.r25.u8);
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,4(r6)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// b 0x82554d6c
	goto loc_82554D6C;
loc_82554C00:
	// lwz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82554c18
	if (!ctx.cr6.eq) goto loc_82554C18;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82550fc8
	ctx.lr = 0x82554C18;
	sub_82550FC8(ctx, base);
loc_82554C18:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stb r30,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r30.u8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stb r25,20(r9)
	REX_STORE_U8(ctx.r9.u32 + 20, ctx.r25.u8);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,8(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r6,21(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 21);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82554c54
	if (!ctx.cr6.eq) goto loc_82554C54;
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
loc_82554C54:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,24(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82554c78
	if (!ctx.cr6.eq) goto loc_82554C78;
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// b 0x82554d68
	goto loc_82554D68;
loc_82554C78:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82554c94
	if (!ctx.cr6.eq) goto loc_82554C94;
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// b 0x82554d68
	goto loc_82554D68;
loc_82554C94:
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r11,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// b 0x82554d68
	goto loc_82554D68;
loc_82554CA0:
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82554cd4
	if (!ctx.cr6.eq) goto loc_82554CD4;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stb r30,20(r9)
	REX_STORE_U8(ctx.r9.u32 + 20, ctx.r30.u8);
	// stb r30,20(r10)
	REX_STORE_U8(ctx.r10.u32 + 20, ctx.r30.u8);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stb r25,20(r7)
	REX_STORE_U8(ctx.r7.u32 + 20, ctx.r25.u8);
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,4(r6)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// b 0x82554d6c
	goto loc_82554D6C;
loc_82554CD4:
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82554cec
	if (!ctx.cr6.eq) goto loc_82554CEC;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x8254fd58
	ctx.lr = 0x82554CEC;
	sub_8254FD58(ctx, base);
loc_82554CEC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stb r30,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r30.u8);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stb r25,20(r9)
	REX_STORE_U8(ctx.r9.u32 + 20, ctx.r25.u8);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r6,21(r9)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r9.u32 + 21);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x82554d28
	if (!ctx.cr6.eq) goto loc_82554D28;
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
loc_82554D28:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,24(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82554d48
	if (!ctx.cr6.eq) goto loc_82554D48;
	// stw r10,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// b 0x82554d64
	goto loc_82554D64;
loc_82554D48:
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82554d60
	if (!ctx.cr6.eq) goto loc_82554D60;
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// b 0x82554d64
	goto loc_82554D64;
loc_82554D60:
	// stw r10,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
loc_82554D64:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82554D68:
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82554D6C:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lbz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82554bb8
	if (ctx.cr6.eq) goto loc_82554BB8;
loc_82554D80:
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r26,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r26.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stb r30,20(r10)
	REX_STORE_U8(ctx.r10.u32 + 20, ctx.r30.u8);
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// stw r9,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82567628) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82567630;
	__savegprlr_24(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,92(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 92);
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82567660
	if (!ctx.cr6.eq) goto loc_82567660;
	// lwz r11,96(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 96);
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// b 0x8256766c
	goto loc_8256766C;
loc_82567660:
	// li r29,1
	ctx.r29.s64 = 1;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
loc_8256766C:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r26,4(r11)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r25,0(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8256768C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,0(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r7,92(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 92);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825676AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,0(r25)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,92(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 92);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825676CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// bl 0x82565dd0
	ctx.lr = 0x825676E8;
	sub_82565DD0(ctx, base);
	// clrlwi r10,r29,31
	ctx.r10.u64 = ctx.r29.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825676fc
	if (ctx.cr6.eq) goto loc_825676FC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x825676FC;
	sub_8254B160(ctx, base);
loc_825676FC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r27,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r27.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8256D3D0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8256D760) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8256d4b8
	ctx.lr = 0x8256D780;
	sub_8256D4B8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8256d798
	if (ctx.cr6.eq) goto loc_8256D798;
	// bl 0x82573808
	ctx.lr = 0x8256D794;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8256D798:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8256EA50) {
	REX_FUNC_PROLOGUE();
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8256EEE0) {
	REX_FUNC_PROLOGUE();
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r3,20
	ctx.r9.s64 = ctx.r3.s64 + 20;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lwz r4,20(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// add r8,r4,r10
	ctx.r8.u64 = ctx.r4.u64 + ctx.r10.u64;
	// lwz r6,8(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r8,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// b 0x8256b270
	sub_8256B270(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82570A00) {
	REX_FUNC_PROLOGUE();
	// li r11,16
	ctx.r11.s64 = 16;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82570E38) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,11080
	ctx.r9.s64 = ctx.r11.s64 + 11080;
	// lwzx r8,r10,r9
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r3,0(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82571828) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82571830;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82570b28
	ctx.lr = 0x82571840;
	sub_82570B28(ctx, base);
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r11,15688
	ctx.r30.s64 = ctx.r11.s64 + 15688;
	// lwz r11,15688(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 15688);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82571958
	if (!ctx.cr6.eq) goto loc_82571958;
	// lis r28,-32128
	ctx.r28.s64 = -2105540608;
	// lis r3,2
	ctx.r3.s64 = 131072;
	// ori r3,r3,12328
	ctx.r3.u64 = ctx.r3.u64 | 12328;
	// lwz r11,12880(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 12880);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82571870;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82571894
	if (ctx.cr6.eq) goto loc_82571894;
	// bl 0x82573a68
	ctx.lr = 0x8257187C;
	sub_82573A68(ctx, base);
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825718a8
	if (!ctx.cr6.eq) goto loc_825718A8;
loc_82571888:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82571894:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_825718A8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82573ad8
	ctx.lr = 0x825718B0;
	sub_82573AD8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82571888
	if (!ctx.cr6.eq) goto loc_82571888;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x825718ec
	if (!ctx.cr6.eq) goto loc_825718EC;
	// lwz r11,12880(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 12880);
	// li r3,7260
	ctx.r3.s64 = 7260;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825718D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825718e4
	if (ctx.cr6.eq) goto loc_825718E4;
	// bl 0x82573ed0
	ctx.lr = 0x825718E0;
	sub_82573ED0(ctx, base);
	// b 0x825718e8
	goto loc_825718E8;
loc_825718E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825718E8:
	// stw r3,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r3.u32);
loc_825718EC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// bl 0x825763a8
	ctx.lr = 0x82571900;
	sub_825763A8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82571960
	if (!ctx.cr6.eq) goto loc_82571960;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82573ce0
	ctx.lr = 0x82571914;
	sub_82573CE0(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8257194c
	if (!ctx.cr6.gt) goto loc_8257194C;
loc_82571920:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825747c8
	ctx.lr = 0x8257192C;
	sub_825747C8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82573c10
	ctx.lr = 0x82571940;
	sub_82573C10(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82571920
	if (ctx.cr6.lt) goto loc_82571920;
loc_8257194C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82571958:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,40
	ctx.r3.u64 = ctx.r3.u64 | 40;
loc_82571960:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82578DD8) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82578de8
	if (ctx.cr6.eq) goto loc_82578DE8;
	// lwz r3,16(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// blr 
	return;
loc_82578DE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82579488) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82579490;
	__savegprlr_29(ctx, base);
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x826a0d14
	ctx.lr = 0x82579498;
	__savefpr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lfs f30,3684(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3684);
	ctx.f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x825794B0;
	sub_8257ECC0(ctx, base);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f29,26840(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26840);
	ctx.f29.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x825794C4;
	sub_8257ECC0(ctx, base);
	// stfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f31,2880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x825794D8;
	sub_8257ECC0(ctx, base);
	// stfs f1,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x825794E4;
	sub_8257ECC0(ctx, base);
	// stfs f1,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lfs f28,-13524(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -13524);
	ctx.f28.f64 = double(temp.f32);
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x825794F8;
	sub_8257ECC0(ctx, base);
	// stfs f1,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f27,23584(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 23584);
	ctx.f27.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x8257950C;
	sub_8257ECC0(ctx, base);
	// stfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82579308
	ctx.lr = 0x82579518;
	sub_82579308(ctx, base);
	// addi r31,r30,68
	ctx.r31.s64 = ctx.r30.s64 + 68;
	// li r29,10
	ctx.r29.s64 = 10;
loc_82579520:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x82579528;
	sub_8257ECC0(ctx, base);
	// stfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x82579534;
	sub_8257ECC0(ctx, base);
	// stfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x82579540;
	sub_8257ECC0(ctx, base);
	// stfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x8257954C;
	sub_8257ECC0(ctx, base);
	// stfs f1,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x82579558;
	sub_8257ECC0(ctx, base);
	// stfs f1,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x8257ecc0
	ctx.lr = 0x82579564;
	sub_8257ECC0(ctx, base);
	// stfsu f1,24(r31)
	ctx.fpscr.disableFlushMode();
	ea = 24 + ctx.r31.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r31.u32 = ea;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x82579520
	if (!ctx.cr0.eq) goto loc_82579520;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r30,308
	ctx.r11.s64 = ctx.r30.s64 + 308;
	// li r6,-30
	ctx.r6.s64 = -30;
	// li r7,30
	ctx.r7.s64 = 30;
	// li r8,-110
	ctx.r8.s64 = -110;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,110
	ctx.r9.s64 = 110;
loc_82579590:
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r8,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stwu r9,24(r11)
	ea = 24 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82579590
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82579590;
	// stw r10,552(r30)
	REX_STORE_U32(ctx.r30.u32 + 552, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x826a0d60
	ctx.lr = 0x825795BC;
	__restfpr_27(ctx, base);
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82583C98) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82584B88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,9
	ctx.r11.s64 = 9;
	// addi r10,r1,72
	ctx.r10.s64 = ctx.r1.s64 + 72;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82584BA8:
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x82584ba8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82584BA8;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r4,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// std r8,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// std r6,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r6.u64);
	// bl 0x82584490
	ctx.lr = 0x82584BD0;
	sub_82584490(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82586218) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,368(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 368);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258624c
	if (ctx.cr6.eq) goto loc_8258624C;
loc_82586238:
	// li r3,50
	ctx.r3.s64 = 50;
	// bl 0x824be068
	ctx.lr = 0x82586240;
	sub_824BE068(ctx, base);
	// lwz r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82586238
	if (!ctx.cr6.eq) goto loc_82586238;
loc_8258624C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82588574) {
	REX_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82588BD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8258b430
	ctx.lr = 0x82588BE8;
	sub_8258B430(ctx, base);
	// addi r3,r31,56
	ctx.r3.s64 = ctx.r31.s64 + 56;
	// bl 0x8258b6c0
	ctx.lr = 0x82588BF0;
	sub_8258B6C0(ctx, base);
	// addi r3,r31,124
	ctx.r3.s64 = ctx.r31.s64 + 124;
	// bl 0x825857b0
	ctx.lr = 0x82588BF8;
	sub_825857B0(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = ctx.r31.s64 + 208;
	// bl 0x82590b50
	ctx.lr = 0x82588C00;
	sub_82590B50(ctx, base);
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,3480
	ctx.r10.s64 = ctx.r11.s64 + 3480;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x8258e9d0
	ctx.lr = 0x82588C14;
	sub_8258E9D0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,672(r31)
	REX_STORE_U32(ctx.r31.u32 + 672, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,660(r31)
	REX_STORE_U32(ctx.r31.u32 + 660, ctx.r9.u32);
	// stw r11,676(r31)
	REX_STORE_U32(ctx.r31.u32 + 676, ctx.r11.u32);
	// stw r11,664(r31)
	REX_STORE_U32(ctx.r31.u32 + 664, ctx.r11.u32);
	// stw r11,668(r31)
	REX_STORE_U32(ctx.r31.u32 + 668, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8258B338) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8258b430
	ctx.lr = 0x8258B350;
	sub_8258B430(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r8,r10,4248
	ctx.r8.s64 = ctx.r10.s64 + 4248;
	// std r11,56(r31)
	REX_STORE_U64(ctx.r31.u32 + 56, ctx.r11.u64);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// std r11,64(r31)
	REX_STORE_U64(ctx.r31.u32 + 64, ctx.r11.u64);
	// std r11,72(r31)
	REX_STORE_U64(ctx.r31.u32 + 72, ctx.r11.u64);
	// std r11,80(r31)
	REX_STORE_U64(ctx.r31.u32 + 80, ctx.r11.u64);
	// std r11,88(r31)
	REX_STORE_U64(ctx.r31.u32 + 88, ctx.r11.u64);
	// std r11,96(r31)
	REX_STORE_U64(ctx.r31.u32 + 96, ctx.r11.u64);
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r11,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8258F2D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x8258F2D8;
	__savegprlr_14(ctx, base);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r19,0
	ctx.r19.s64 = 0;
	// sth r5,550(r1)
	REX_STORE_U16(ctx.r1.u32 + 550, ctx.r5.u16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r6,556(r1)
	REX_STORE_U32(ctx.r1.u32 + 556, ctx.r6.u32);
	// mr r17,r4
	ctx.r17.u64 = ctx.r4.u64;
	// stw r19,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r19.u32);
	// mr r16,r7
	ctx.r16.u64 = ctx.r7.u64;
	// stw r19,248(r1)
	REX_STORE_U32(ctx.r1.u32 + 248, ctx.r19.u32);
	// mr r14,r8
	ctx.r14.u64 = ctx.r8.u64;
	// stw r19,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r19.u32);
	// mr r18,r9
	ctx.r18.u64 = ctx.r9.u64;
	// stw r19,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r19.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// mr r15,r19
	ctx.r15.u64 = ctx.r19.u64;
	// beq cr6,0x8258fc30
	if (ctx.cr6.eq) goto loc_8258FC30;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258fc30
	if (ctx.cr6.eq) goto loc_8258FC30;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8258fc30
	if (ctx.cr6.eq) goto loc_8258FC30;
	// sth r10,236(r3)
	REX_STORE_U16(ctx.r3.u32 + 236, ctx.r10.u16);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8259aac8
	ctx.lr = 0x8258F338;
	sub_8259AAC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8258f34c
	if (ctx.cr6.eq) goto loc_8258F34C;
loc_8258F340:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8258F34C:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f340
	if (ctx.cr6.eq) goto loc_8258F340;
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f340
	if (ctx.cr6.eq) goto loc_8258F340;
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f340
	if (ctx.cr6.eq) goto loc_8258F340;
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f340
	if (ctx.cr6.eq) goto loc_8258F340;
	// lwz r20,232(r31)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x8258f7c0
	if (ctx.cr6.eq) goto loc_8258F7C0;
	// li r11,101
	ctx.r11.s64 = 101;
	// stb r19,198(r1)
	REX_STORE_U8(ctx.r1.u32 + 198, ctx.r19.u8);
	// li r9,87
	ctx.r9.s64 = 87;
	// stb r19,131(r1)
	REX_STORE_U8(ctx.r1.u32 + 131, ctx.r19.u8);
	// li r10,77
	ctx.r10.s64 = 77;
	// stb r11,186(r1)
	REX_STORE_U8(ctx.r1.u32 + 186, ctx.r11.u8);
	// li r6,82
	ctx.r6.s64 = 82;
	// stb r9,176(r1)
	REX_STORE_U8(ctx.r1.u32 + 176, ctx.r9.u8);
	// li r5,65
	ctx.r5.s64 = 65;
	// stb r10,177(r1)
	REX_STORE_U8(ctx.r1.u32 + 177, ctx.r10.u8);
	// li r8,97
	ctx.r8.s64 = 97;
	// stb r9,179(r1)
	REX_STORE_U8(ctx.r1.u32 + 179, ctx.r9.u8);
	// li r28,47
	ctx.r28.s64 = 47;
	// stb r10,180(r1)
	REX_STORE_U8(ctx.r1.u32 + 180, ctx.r10.u8);
	// li r29,68
	ctx.r29.s64 = 68;
	// stb r5,181(r1)
	REX_STORE_U8(ctx.r1.u32 + 181, ctx.r5.u8);
	// li r4,67
	ctx.r4.s64 = 67;
	// stb r28,178(r1)
	REX_STORE_U8(ctx.r1.u32 + 178, ctx.r28.u8);
	// li r7,114
	ctx.r7.s64 = 114;
	// stb r29,182(r1)
	REX_STORE_U8(ctx.r1.u32 + 182, ctx.r29.u8);
	// li r23,80
	ctx.r23.s64 = 80;
	// stb r6,183(r1)
	REX_STORE_U8(ctx.r1.u32 + 183, ctx.r6.u8);
	// li r24,107
	ctx.r24.s64 = 107;
	// stb r4,184(r1)
	REX_STORE_U8(ctx.r1.u32 + 184, ctx.r4.u8);
	// li r3,103
	ctx.r3.s64 = 103;
	// stb r23,185(r1)
	REX_STORE_U8(ctx.r1.u32 + 185, ctx.r23.u8);
	// li r25,102
	ctx.r25.s64 = 102;
	// stb r8,187(r1)
	REX_STORE_U8(ctx.r1.u32 + 187, ctx.r8.u8);
	// li r30,110
	ctx.r30.s64 = 110;
	// stb r24,188(r1)
	REX_STORE_U8(ctx.r1.u32 + 188, ctx.r24.u8);
	// li r27,99
	ctx.r27.s64 = 99;
	// stb r6,189(r1)
	REX_STORE_U8(ctx.r1.u32 + 189, ctx.r6.u8);
	// li r26,84
	ctx.r26.s64 = 84;
	// stb r11,190(r1)
	REX_STORE_U8(ctx.r1.u32 + 190, ctx.r11.u8);
	// li r21,116
	ctx.r21.s64 = 116;
	// stb r25,191(r1)
	REX_STORE_U8(ctx.r1.u32 + 191, ctx.r25.u8);
	// li r22,118
	ctx.r22.s64 = 118;
	// stb r11,192(r1)
	REX_STORE_U8(ctx.r1.u32 + 192, ctx.r11.u8);
	// stb r7,193(r1)
	REX_STORE_U8(ctx.r1.u32 + 193, ctx.r7.u8);
	// stb r11,194(r1)
	REX_STORE_U8(ctx.r1.u32 + 194, ctx.r11.u8);
	// stb r30,195(r1)
	REX_STORE_U8(ctx.r1.u32 + 195, ctx.r30.u8);
	// stb r27,196(r1)
	REX_STORE_U8(ctx.r1.u32 + 196, ctx.r27.u8);
	// stb r11,197(r1)
	REX_STORE_U8(ctx.r1.u32 + 197, ctx.r11.u8);
	// stb r9,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r9.u8);
	// stb r10,113(r1)
	REX_STORE_U8(ctx.r1.u32 + 113, ctx.r10.u8);
	// stb r28,114(r1)
	REX_STORE_U8(ctx.r1.u32 + 114, ctx.r28.u8);
	// stb r9,115(r1)
	REX_STORE_U8(ctx.r1.u32 + 115, ctx.r9.u8);
	// stb r10,116(r1)
	REX_STORE_U8(ctx.r1.u32 + 116, ctx.r10.u8);
	// stb r5,117(r1)
	REX_STORE_U8(ctx.r1.u32 + 117, ctx.r5.u8);
	// stb r29,118(r1)
	REX_STORE_U8(ctx.r1.u32 + 118, ctx.r29.u8);
	// stb r6,119(r1)
	REX_STORE_U8(ctx.r1.u32 + 119, ctx.r6.u8);
	// stb r4,120(r1)
	REX_STORE_U8(ctx.r1.u32 + 120, ctx.r4.u8);
	// stb r23,121(r1)
	REX_STORE_U8(ctx.r1.u32 + 121, ctx.r23.u8);
	// stb r11,122(r1)
	REX_STORE_U8(ctx.r1.u32 + 122, ctx.r11.u8);
	// stb r8,123(r1)
	REX_STORE_U8(ctx.r1.u32 + 123, ctx.r8.u8);
	// stb r24,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r24.u8);
	// stb r26,125(r1)
	REX_STORE_U8(ctx.r1.u32 + 125, ctx.r26.u8);
	// stb r8,126(r1)
	REX_STORE_U8(ctx.r1.u32 + 126, ctx.r8.u8);
	// stb r7,127(r1)
	REX_STORE_U8(ctx.r1.u32 + 127, ctx.r7.u8);
	// stb r3,128(r1)
	REX_STORE_U8(ctx.r1.u32 + 128, ctx.r3.u8);
	// stb r11,129(r1)
	REX_STORE_U8(ctx.r1.u32 + 129, ctx.r11.u8);
	// stb r21,130(r1)
	REX_STORE_U8(ctx.r1.u32 + 130, ctx.r21.u8);
	// stb r9,208(r1)
	REX_STORE_U8(ctx.r1.u32 + 208, ctx.r9.u8);
	// stb r10,209(r1)
	REX_STORE_U8(ctx.r1.u32 + 209, ctx.r10.u8);
	// stb r28,210(r1)
	REX_STORE_U8(ctx.r1.u32 + 210, ctx.r28.u8);
	// stb r9,211(r1)
	REX_STORE_U8(ctx.r1.u32 + 211, ctx.r9.u8);
	// stb r10,212(r1)
	REX_STORE_U8(ctx.r1.u32 + 212, ctx.r10.u8);
	// stb r5,213(r1)
	REX_STORE_U8(ctx.r1.u32 + 213, ctx.r5.u8);
	// stb r29,214(r1)
	REX_STORE_U8(ctx.r1.u32 + 214, ctx.r29.u8);
	// stb r6,215(r1)
	REX_STORE_U8(ctx.r1.u32 + 215, ctx.r6.u8);
	// stb r4,216(r1)
	REX_STORE_U8(ctx.r1.u32 + 216, ctx.r4.u8);
	// stb r5,217(r1)
	REX_STORE_U8(ctx.r1.u32 + 217, ctx.r5.u8);
	// stb r22,218(r1)
	REX_STORE_U8(ctx.r1.u32 + 218, ctx.r22.u8);
	// stb r11,219(r1)
	REX_STORE_U8(ctx.r1.u32 + 219, ctx.r11.u8);
	// stb r7,220(r1)
	REX_STORE_U8(ctx.r1.u32 + 220, ctx.r7.u8);
	// stb r8,221(r1)
	REX_STORE_U8(ctx.r1.u32 + 221, ctx.r8.u8);
	// stb r3,222(r1)
	REX_STORE_U8(ctx.r1.u32 + 222, ctx.r3.u8);
	// stb r11,223(r1)
	REX_STORE_U8(ctx.r1.u32 + 223, ctx.r11.u8);
	// stb r6,224(r1)
	REX_STORE_U8(ctx.r1.u32 + 224, ctx.r6.u8);
	// stb r11,225(r1)
	REX_STORE_U8(ctx.r1.u32 + 225, ctx.r11.u8);
	// stb r25,226(r1)
	REX_STORE_U8(ctx.r1.u32 + 226, ctx.r25.u8);
	// std r31,344(r1)
	REX_STORE_U64(ctx.r1.u32 + 344, ctx.r31.u64);
	// li r31,70
	ctx.r31.s64 = 70;
	// std r20,336(r1)
	REX_STORE_U64(ctx.r1.u32 + 336, ctx.r20.u64);
	// li r23,111
	ctx.r23.s64 = 111;
	// std r18,352(r1)
	REX_STORE_U64(ctx.r1.u32 + 352, ctx.r18.u64);
	// li r18,104
	ctx.r18.s64 = 104;
	// std r17,328(r1)
	REX_STORE_U64(ctx.r1.u32 + 328, ctx.r17.u64);
	// li r17,115
	ctx.r17.s64 = 115;
	// lhz r25,0(r20)
	ctx.r25.u64 = REX_LOAD_U16(ctx.r20.u32 + 0);
	// li r20,100
	ctx.r20.s64 = 100;
	// stb r27,231(r1)
	REX_STORE_U8(ctx.r1.u32 + 231, ctx.r27.u8);
	// li r27,37
	ctx.r27.s64 = 37;
	// li r24,108
	ctx.r24.s64 = 108;
	// stb r31,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r31.u8);
	// stb r20,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r20.u8);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// stb r18,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r18.u8);
	// stb r17,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r17.u8);
	// stb r11,227(r1)
	REX_STORE_U8(ctx.r1.u32 + 227, ctx.r11.u8);
	// stb r7,228(r1)
	REX_STORE_U8(ctx.r1.u32 + 228, ctx.r7.u8);
	// stb r11,229(r1)
	REX_STORE_U8(ctx.r1.u32 + 229, ctx.r11.u8);
	// stb r30,230(r1)
	REX_STORE_U8(ctx.r1.u32 + 230, ctx.r30.u8);
	// stb r11,232(r1)
	REX_STORE_U8(ctx.r1.u32 + 232, ctx.r11.u8);
	// stb r19,233(r1)
	REX_STORE_U8(ctx.r1.u32 + 233, ctx.r19.u8);
	// stb r9,144(r1)
	REX_STORE_U8(ctx.r1.u32 + 144, ctx.r9.u8);
	// stb r10,145(r1)
	REX_STORE_U8(ctx.r1.u32 + 145, ctx.r10.u8);
	// stb r28,146(r1)
	REX_STORE_U8(ctx.r1.u32 + 146, ctx.r28.u8);
	// stb r9,147(r1)
	REX_STORE_U8(ctx.r1.u32 + 147, ctx.r9.u8);
	// ld r31,344(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 344);
	// ld r20,336(r1)
	ctx.r20.u64 = REX_LOAD_U64(ctx.r1.u32 + 336);
	// ld r18,352(r1)
	ctx.r18.u64 = REX_LOAD_U64(ctx.r1.u32 + 352);
	// ld r17,328(r1)
	ctx.r17.u64 = REX_LOAD_U64(ctx.r1.u32 + 328);
	// stb r10,148(r1)
	REX_STORE_U8(ctx.r1.u32 + 148, ctx.r10.u8);
	// stb r5,149(r1)
	REX_STORE_U8(ctx.r1.u32 + 149, ctx.r5.u8);
	// stb r29,150(r1)
	REX_STORE_U8(ctx.r1.u32 + 150, ctx.r29.u8);
	// stb r6,151(r1)
	REX_STORE_U8(ctx.r1.u32 + 151, ctx.r6.u8);
	// stb r4,152(r1)
	REX_STORE_U8(ctx.r1.u32 + 152, ctx.r4.u8);
	// stb r5,153(r1)
	REX_STORE_U8(ctx.r1.u32 + 153, ctx.r5.u8);
	// stb r22,154(r1)
	REX_STORE_U8(ctx.r1.u32 + 154, ctx.r22.u8);
	// stb r11,155(r1)
	REX_STORE_U8(ctx.r1.u32 + 155, ctx.r11.u8);
	// stb r7,156(r1)
	REX_STORE_U8(ctx.r1.u32 + 156, ctx.r7.u8);
	// stb r8,157(r1)
	REX_STORE_U8(ctx.r1.u32 + 157, ctx.r8.u8);
	// stb r3,158(r1)
	REX_STORE_U8(ctx.r1.u32 + 158, ctx.r3.u8);
	// stb r11,159(r1)
	REX_STORE_U8(ctx.r1.u32 + 159, ctx.r11.u8);
	// stb r26,160(r1)
	REX_STORE_U8(ctx.r1.u32 + 160, ctx.r26.u8);
	// stb r8,161(r1)
	REX_STORE_U8(ctx.r1.u32 + 161, ctx.r8.u8);
	// stb r7,162(r1)
	REX_STORE_U8(ctx.r1.u32 + 162, ctx.r7.u8);
	// stb r3,163(r1)
	REX_STORE_U8(ctx.r1.u32 + 163, ctx.r3.u8);
	// stb r11,164(r1)
	REX_STORE_U8(ctx.r1.u32 + 164, ctx.r11.u8);
	// stb r21,165(r1)
	REX_STORE_U8(ctx.r1.u32 + 165, ctx.r21.u8);
	// stb r19,166(r1)
	REX_STORE_U8(ctx.r1.u32 + 166, ctx.r19.u8);
	// stb r23,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r23.u8);
	// stb r24,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r24.u8);
	// stb r27,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r27.u8);
	// stb r26,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r26.u8);
	// stb r23,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r23.u8);
	// stb r27,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r27.u8);
	// stb r4,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r4.u8);
	// stb r8,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r8.u8);
	// stb r30,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r30.u8);
	// stb r30,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r30.u8);
	// stb r11,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r11.u8);
	// stb r24,94(r1)
	REX_STORE_U8(ctx.r1.u32 + 94, ctx.r24.u8);
	// stb r27,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r27.u8);
	// stb r19,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r19.u8);
	// stw r19,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r19.u32);
	// stw r19,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r19.u32);
	// stw r19,296(r1)
	REX_STORE_U32(ctx.r1.u32 + 296, ctx.r19.u32);
	// beq cr6,0x8258f7c0
	if (ctx.cr6.eq) goto loc_8258F7C0;
	// lwz r11,4(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f7c0
	if (ctx.cr6.eq) goto loc_8258F7C0;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8258f7c0
	if (ctx.cr6.eq) goto loc_8258F7C0;
	// lis r11,9356
	ctx.r11.s64 = 613154816;
	// lwz r28,236(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r27,244(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
	// lwz r26,248(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 248);
	// ori r24,r11,32768
	ctx.r24.u64 = ctx.r11.u64 | 32768;
	// lwz r25,240(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 240);
loc_8258F610:
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,232(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// add r9,r30,r11
	ctx.r9.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lhz r11,2(r9)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r9.u32 + 2);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f640
	if (ctx.cr6.eq) goto loc_8258F640;
	// lhz r9,228(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 228);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8258f7a0
	if (!ctx.cr6.eq) goto loc_8258F7A0;
loc_8258F640:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lhz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x8258eab8
	ctx.lr = 0x8258F65C;
	sub_8258EAB8(ctx, base);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bne cr6,0x8258f67c
	if (!ctx.cr6.eq) goto loc_8258F67C;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r25,0(r9)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8258f7a0
	goto loc_8258F7A0;
loc_8258F67C:
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lhz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x8258eab8
	ctx.lr = 0x8258F694;
	sub_8258EAB8(ctx, base);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bne cr6,0x8258f6b4
	if (!ctx.cr6.eq) goto loc_8258F6B4;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r26,0(r9)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8258f7a0
	goto loc_8258F7A0;
loc_8258F6B4:
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lhz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x8258eab8
	ctx.lr = 0x8258F6CC;
	sub_8258EAB8(ctx, base);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bne cr6,0x8258f6ec
	if (!ctx.cr6.eq) goto loc_8258F6EC;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r27,0(r9)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8258f7a0
	goto loc_8258F7A0;
loc_8258F6EC:
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lhz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x8258eab8
	ctx.lr = 0x8258F704;
	sub_8258EAB8(ctx, base);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bne cr6,0x8258f724
	if (!ctx.cr6.eq) goto loc_8258F724;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r28,0(r9)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8258f7a0
	goto loc_8258F7A0;
loc_8258F724:
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lhz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// lwz r4,12(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x8258eab8
	ctx.lr = 0x8258F73C;
	sub_8258EAB8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8258f7a0
	if (!ctx.cr6.eq) goto loc_8258F7A0;
	// lwz r11,288(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 288);
	// lhz r9,76(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r8,292(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8258f79c
	if (!ctx.cr6.eq) goto loc_8258F79C;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mullw r23,r10,r11
	ctx.r23.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// rlwinm r3,r23,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x824c64b8
	ctx.lr = 0x8258F774;
	sub_824C64B8(ctx, base);
	// lwz r9,232(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// clrlwi r6,r23,16
	ctx.r6.u64 = ctx.r23.u32 & 0xFFFF;
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x8258ebb0
	ctx.lr = 0x8258F798;
	sub_8258EBB0(ctx, base);
	// b 0x8258f7a0
	goto loc_8258F7A0;
loc_8258F79C:
	// mr r15,r19
	ctx.r15.u64 = ctx.r19.u64;
loc_8258F7A0:
	// lwz r10,232(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// addi r9,r29,1
	ctx.r9.s64 = ctx.r29.s64 + 1;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8258f610
	if (ctx.cr6.lt) goto loc_8258F610;
	// b 0x8258f7d8
	goto loc_8258F7D8;
loc_8258F7C0:
	// lis r11,9356
	ctx.r11.s64 = 613154816;
	// lwz r28,236(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r27,244(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// lwz r26,248(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 248);
	// ori r24,r11,32768
	ctx.r24.u64 = ctx.r11.u64 | 32768;
	// lwz r25,240(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 240);
loc_8258F7D8:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8259bf38
	ctx.lr = 0x8258F7E4;
	sub_8259BF38(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r3.u32);
	// bne cr6,0x8258f7fc
	if (!ctx.cr6.eq) goto loc_8258F7FC;
loc_8258F7F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8258F7FC:
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// lhz r10,90(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 90);
	// lwz r5,72(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// rlwinm r8,r10,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// lhz r7,62(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r6,76(r31)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// lwz r10,64(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r9,68(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// lhz r30,92(r31)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// lwz r29,96(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lhz r23,84(r31)
	ctx.r23.u64 = REX_LOAD_U16(ctx.r31.u32 + 84);
	// lhz r22,86(r31)
	ctx.r22.u64 = REX_LOAD_U16(ctx.r31.u32 + 86);
	// std r19,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r19.u64);
	// std r19,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r19.u64);
	// stw r8,16(r18)
	REX_STORE_U32(ctx.r18.u32 + 16, ctx.r8.u32);
	// lwz r8,64(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// std r19,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r19.u64);
	// stw r8,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r8.u32);
	// lhz r8,92(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 92);
	// stw r19,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r19.u32);
	// sth r7,304(r1)
	REX_STORE_U16(ctx.r1.u32 + 304, ctx.r7.u16);
	// sth r6,306(r1)
	REX_STORE_U16(ctx.r1.u32 + 306, ctx.r6.u16);
	// stw r10,308(r1)
	REX_STORE_U32(ctx.r1.u32 + 308, ctx.r10.u32);
	// stw r9,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r9.u32);
	// sth r30,318(r1)
	REX_STORE_U16(ctx.r1.u32 + 318, ctx.r30.u16);
	// stw r29,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r29.u32);
	// sth r23,324(r1)
	REX_STORE_U16(ctx.r1.u32 + 324, ctx.r23.u16);
	// sth r5,316(r1)
	REX_STORE_U16(ctx.r1.u32 + 316, ctx.r5.u16);
	// sth r22,326(r1)
	REX_STORE_U16(ctx.r1.u32 + 326, ctx.r22.u16);
	// sth r19,256(r1)
	REX_STORE_U16(ctx.r1.u32 + 256, ctx.r19.u16);
	// stw r8,12(r18)
	REX_STORE_U32(ctx.r18.u32 + 12, ctx.r8.u32);
	// bl 0x825a3808
	ctx.lr = 0x8258F884;
	sub_825A3808(ctx, base);
	// clrlwi r7,r17,31
	ctx.r7.u64 = ctx.r17.u32 & 0x1;
	// clrlwi r8,r17,16
	ctx.r8.u64 = ctx.r17.u32 & 0xFFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8258f8c4
	if (ctx.cr6.eq) goto loc_8258F8C4;
	// stw r16,8(r18)
	REX_STORE_U32(ctx.r18.u32 + 8, ctx.r16.u32);
	// mr r11,r16
	ctx.r11.u64 = ctx.r16.u64;
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// stw r19,4(r18)
	REX_STORE_U32(ctx.r18.u32 + 4, ctx.r19.u32);
	// beq cr6,0x8258f8c4
	if (ctx.cr6.eq) goto loc_8258F8C4;
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
loc_8258F8AC:
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8258f8ac
	if (!ctx.cr6.eq) goto loc_8258F8AC;
	// stw r10,4(r18)
	REX_STORE_U32(ctx.r18.u32 + 4, ctx.r10.u32);
loc_8258F8C4:
	// rlwinm r11,r8,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x100;
	// li r29,3
	ctx.r29.s64 = 3;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f904
	if (ctx.cr6.eq) goto loc_8258F904;
	// lhz r9,256(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 256);
	// lwz r11,4(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 4);
	// ori r10,r9,256
	ctx.r10.u64 = ctx.r9.u64 | 256;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// sth r10,256(r1)
	REX_STORE_U16(ctx.r1.u32 + 256, ctx.r10.u16);
	// ble cr6,0x8258f8f0
	if (!ctx.cr6.gt) goto loc_8258F8F0;
	// li r11,2
	ctx.r11.s64 = 2;
loc_8258F8F0:
	// stw r11,4(r18)
	REX_STORE_U32(ctx.r18.u32 + 4, ctx.r11.u32);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x8258f908
	if (!ctx.cr6.eq) goto loc_8258F908;
	// stw r29,8(r18)
	REX_STORE_U32(ctx.r18.u32 + 8, ctx.r29.u32);
	// b 0x8258f908
	goto loc_8258F908;
loc_8258F904:
	// lhz r10,256(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 256);
loc_8258F908:
	// rlwinm r9,r8,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// li r7,4
	ctx.r7.s64 = 4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8258f92c
	if (ctx.cr6.eq) goto loc_8258F92C;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r11,12(r18)
	REX_STORE_U32(ctx.r18.u32 + 12, ctx.r11.u32);
	// stw r6,16(r18)
	REX_STORE_U32(ctx.r18.u32 + 16, ctx.r6.u32);
	// b 0x8258f950
	goto loc_8258F950;
loc_8258F92C:
	// rlwinm r11,r8,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f940
	if (ctx.cr6.eq) goto loc_8258F940;
	// stw r29,16(r18)
	REX_STORE_U32(ctx.r18.u32 + 16, ctx.r29.u32);
	// b 0x8258f950
	goto loc_8258F950;
loc_8258F940:
	// rlwinm r11,r8,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f950
	if (ctx.cr6.eq) goto loc_8258F950;
	// stw r7,16(r18)
	REX_STORE_U32(ctx.r18.u32 + 16, ctx.r7.u32);
loc_8258F950:
	// rlwinm r11,r8,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// sth r19,280(r1)
	REX_STORE_U16(ctx.r1.u32 + 280, ctx.r19.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f974
	if (ctx.cr6.eq) goto loc_8258F974;
	// lhz r11,550(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 550);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// sth r10,256(r1)
	REX_STORE_U16(ctx.r1.u32 + 256, ctx.r10.u16);
	// sth r11,280(r1)
	REX_STORE_U16(ctx.r1.u32 + 280, ctx.r11.u16);
loc_8258F974:
	// rlwinm r11,r8,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f9a8
	if (ctx.cr6.eq) goto loc_8258F9A8;
	// lwz r11,308(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,32000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32000, ctx.xer);
	// bne cr6,0x8258f99c
	if (!ctx.cr6.eq) goto loc_8258F99C;
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// bne cr6,0x8258f9a4
	if (!ctx.cr6.eq) goto loc_8258F9A4;
	// li r14,22050
	ctx.r14.s64 = 22050;
	// b 0x8258f9a4
	goto loc_8258F9A4;
loc_8258F99C:
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x8258f9a8
	if (ctx.cr6.eq) goto loc_8258F9A8;
loc_8258F9A4:
	// stw r14,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r14.u32);
loc_8258F9A8:
	// rlwinm r11,r8,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f9c4
	if (ctx.cr6.eq) goto loc_8258F9C4;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// ori r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 2;
	// sth r10,256(r1)
	REX_STORE_U16(ctx.r1.u32 + 256, ctx.r10.u16);
	// b 0x8258fa04
	goto loc_8258FA04;
loc_8258F9C4:
	// rlwinm r11,r8,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258f9ec
	if (ctx.cr6.eq) goto loc_8258F9EC;
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// rlwinm r6,r11,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// ori r5,r10,2
	ctx.r5.u64 = ctx.r10.u64 | 2;
	// stw r6,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r6.u32);
	// sth r5,256(r1)
	REX_STORE_U16(ctx.r1.u32 + 256, ctx.r5.u16);
	// b 0x8258fa04
	goto loc_8258FA04;
loc_8258F9EC:
	// rlwinm r11,r8,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258fa04
	if (ctx.cr6.eq) goto loc_8258FA04;
	// lwz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r10.u32);
loc_8258FA04:
	// rlwinm r11,r8,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258fa68
	if (ctx.cr6.eq) goto loc_8258FA68;
	// lis r11,-16841
	ctx.r11.s64 = -1103691776;
	// lwz r10,0(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r5,r11,50747
	ctx.r5.u64 = ctx.r11.u64 | 50747;
	// ori r11,r6,44100
	ctx.r11.u64 = ctx.r6.u64 | 44100;
	// mulhwu r4,r10,r5
	ctx.r4.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r3,r4,17,15,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 17) & 0x1FFFF;
	// mullw r6,r3,r11
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// subf. r5,r6,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x8258fa3c
	if (!ctx.cr0.eq) goto loc_8258FA3C;
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
loc_8258FA3C:
	// lis r11,1398
	ctx.r11.s64 = 91619328;
	// lwz r10,0(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r5,r11,6641
	ctx.r5.u64 = ctx.r11.u64 | 6641;
	// ori r11,r6,48000
	ctx.r11.u64 = ctx.r6.u64 | 48000;
	// mulhwu r4,r10,r5
	ctx.r4.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r3,r4,22,10,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 22) & 0x3FFFFF;
	// mullw r6,r3,r11
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// subf. r5,r6,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x8258fa68
	if (!ctx.cr0.eq) goto loc_8258FA68;
	// stw r11,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r11.u32);
loc_8258FA68:
	// rlwinm r11,r8,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x200;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8258faa8
	if (ctx.cr6.eq) goto loc_8258FAA8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8258f7f0
	if (!ctx.cr6.eq) goto loc_8258F7F0;
	// rlwinm r11,r8,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8258f7f0
	if (!ctx.cr6.eq) goto loc_8258F7F0;
	// rlwinm r11,r8,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8258f7f0
	if (!ctx.cr6.eq) goto loc_8258F7F0;
	// li r11,32
	ctx.r11.s64 = 32;
	// stw r30,20(r18)
	REX_STORE_U32(ctx.r18.u32 + 20, ctx.r30.u32);
	// stw r7,16(r18)
	REX_STORE_U32(ctx.r18.u32 + 16, ctx.r7.u32);
	// stw r11,12(r18)
	REX_STORE_U32(ctx.r18.u32 + 12, ctx.r11.u32);
loc_8258FAA8:
	// stw r25,264(r1)
	REX_STORE_U32(ctx.r1.u32 + 264, ctx.r25.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r26,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r26.u32);
	// addi r7,r31,588
	ctx.r7.s64 = ctx.r31.s64 + 588;
	// stw r27,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r27.u32);
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// stw r28,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r28.u32);
	// mr r5,r18
	ctx.r5.u64 = ctx.r18.u64;
	// stw r15,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r15.u32);
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// lwz r3,584(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// bl 0x825a2ea0
	ctx.lr = 0x8258FAD8;
	sub_825A2EA0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8258fc34
	if (ctx.cr6.lt) goto loc_8258FC34;
	// bne cr6,0x8258f7f0
	if (!ctx.cr6.eq) goto loc_8258F7F0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x824c64b8
	ctx.lr = 0x8258FAF0;
	sub_824C64B8(ctx, base);
	// stw r3,616(r31)
	REX_STORE_U32(ctx.r31.u32 + 616, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8258fb08
	if (ctx.cr6.eq) goto loc_8258FB08;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// li r5,28
	ctx.r5.s64 = 28;
	// bl 0x826a1130
	ctx.lr = 0x8258FB08;
	rexcrt_memcpy(ctx, base);
loc_8258FB08:
	// lwz r9,552(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// stw r19,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r19.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8258fb60
	if (!ctx.cr6.eq) goto loc_8258FB60;
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8258fb58
	if (!ctx.cr6.gt) goto loc_8258FB58;
	// lbz r11,156(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 156);
	// cmplwi cr6,r11,68
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 68, ctx.xer);
	// bne cr6,0x8258fb78
	if (!ctx.cr6.eq) goto loc_8258FB78;
	// lbz r11,157(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 157);
	// cmplwi cr6,r11,82
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 82, ctx.xer);
	// bne cr6,0x8258fb78
	if (!ctx.cr6.eq) goto loc_8258FB78;
	// lbz r11,158(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 158);
	// cmplwi cr6,r11,77
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 77, ctx.xer);
	// bne cr6,0x8258fb78
	if (!ctx.cr6.eq) goto loc_8258FB78;
	// lbz r11,159(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 159);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8258fb78
	if (!ctx.cr6.eq) goto loc_8258FB78;
	// stw r30,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r30.u32);
loc_8258FB58:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8258fb84
	if (ctx.cr6.eq) goto loc_8258FB84;
loc_8258FB60:
	// lwz r11,152(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8258fb84
	if (!ctx.cr6.eq) goto loc_8258FB84;
	// li r3,13
	ctx.r3.s64 = 13;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8258FB78:
	// li r3,12
	ctx.r3.s64 = 12;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8258FB84:
	// ld r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// std r10,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r10.u64);
	// beq cr6,0x8258fbc4
	if (ctx.cr6.eq) goto loc_8258FBC4;
	// lwz r8,556(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 556);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8258fbac
	if (ctx.cr6.eq) goto loc_8258FBAC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_8258FBAC:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r8,20(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// mulld r11,r7,r8
	ctx.r11.s64 = static_cast<int64_t>(ctx.r7.u64 * ctx.r8.u64);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r6,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r6.u64);
loc_8258FBC4:
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8258fbe0
	if (ctx.cr6.eq) goto loc_8258FBE0;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// subfic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 <= 4294967295;
	ctx.r10.u64 = static_cast<uint64_t>(-1) - ctx.r11.u64;
	// std r10,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r10.u64);
loc_8258FBE0:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r29,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r29.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// std r11,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r11.u64);
	// beq cr6,0x8258fc04
	if (ctx.cr6.eq) goto loc_8258FC04;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// b 0x8258fc08
	goto loc_8258FC08;
loc_8258FC04:
	// li r3,256
	ctx.r3.s64 = 256;
loc_8258FC08:
	// bl 0x824c64b8
	ctx.lr = 0x8258FC0C;
	sub_824C64B8(ctx, base);
	// rotlwi r11,r3,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// li r10,17
	ctx.r10.s64 = 17;
	// stw r3,612(r31)
	REX_STORE_U32(ctx.r31.u32 + 612, ctx.r3.u32);
	// addi r9,r11,0
	ctx.r9.s64 = ctx.r11.s64 + 0;
	// addic r8,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r6,r10
	ctx.r3.u64 = ctx.r6.u64 & ctx.r10.u64;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8258FC30:
	// li r3,2
	ctx.r3.s64 = 2;
loc_8258FC34:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D7010) {
	REX_FUNC_PROLOGUE();
	// lwz r11,188(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 188);
	// lwz r10,180(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// lwz r9,3684(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 3684);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// cmpwi cr6,r9,300
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 300, ctx.xer);
	// bgt cr6,0x825d7060
	if (ctx.cr6.gt) goto loc_825D7060;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,11264
	ctx.r9.u64 = ctx.r10.u64 | 11264;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x825d7060
	if (ctx.cr6.gt) goto loc_825D7060;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,42240
	ctx.r9.u64 = ctx.r10.u64 | 42240;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x825d7054
	if (!ctx.cr6.gt) goto loc_825D7054;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,15564(r3)
	REX_STORE_U32(ctx.r3.u32 + 15564, ctx.r11.u32);
	// blr 
	return;
loc_825D7054:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,15564(r3)
	REX_STORE_U32(ctx.r3.u32 + 15564, ctx.r11.u32);
	// blr 
	return;
loc_825D7060:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,15552(r3)
	REX_STORE_U32(ctx.r3.u32 + 15552, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825DB418) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x825DB420;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,84(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r30,11
	ctx.r30.s64 = 11;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bge cr6,0x825db4a0
	if (!ctx.cr6.lt) goto loc_825DB4A0;
loc_825DB448:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825db4a0
	if (ctx.cr6.eq) goto loc_825DB4A0;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x825db490
	if (!ctx.cr0.lt) goto loc_825DB490;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB490;
	sub_825F8B58(ctx, base);
loc_825DB490:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x825db448
	if (ctx.cr6.gt) goto loc_825DB448;
loc_825DB4A0:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r28,r11,r29
	ctx.r28.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x825db4dc
	if (!ctx.cr0.lt) goto loc_825DB4DC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB4DC;
	sub_825F8B58(ctx, base);
loc_825DB4DC:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r30,11
	ctx.r30.s64 = 11;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bge cr6,0x825db550
	if (!ctx.cr6.lt) goto loc_825DB550;
loc_825DB4F8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825db550
	if (ctx.cr6.eq) goto loc_825DB550;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x825db540
	if (!ctx.cr0.lt) goto loc_825DB540;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB540;
	sub_825F8B58(ctx, base);
loc_825DB540:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x825db4f8
	if (ctx.cr6.gt) goto loc_825DB4F8;
loc_825DB550:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x825db58c
	if (!ctx.cr0.lt) goto loc_825DB58C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB58C;
	sub_825F8B58(ctx, base);
loc_825DB58C:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x825db860
	if (ctx.cr6.eq) goto loc_825DB860;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x825db860
	if (ctx.cr6.eq) goto loc_825DB860;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r30,5
	ctx.r30.s64 = 5;
	// stw r28,156(r27)
	REX_STORE_U32(ctx.r27.u32 + 156, ctx.r28.u32);
	// stw r29,160(r27)
	REX_STORE_U32(ctx.r27.u32 + 160, ctx.r29.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x825db5fc
	if (!ctx.cr6.lt) goto loc_825DB5FC;
loc_825DB5BC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825db5fc
	if (ctx.cr6.eq) goto loc_825DB5FC;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// sld r6,r9,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r8.u8 & 0x7F));
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// std r6,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r6.u64);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge 0x825db5ec
	if (!ctx.cr0.lt) goto loc_825DB5EC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB5EC;
	sub_825F8B58(ctx, base);
loc_825DB5EC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x825db5bc
	if (ctx.cr6.gt) goto loc_825DB5BC;
loc_825DB5FC:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r10,r30,32
	ctx.r10.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// sld r8,r11,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r10.u8 & 0x7F));
	// subf. r7,r30,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge 0x825db624
	if (!ctx.cr0.lt) goto loc_825DB624;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB624;
	sub_825F8B58(ctx, base);
loc_825DB624:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r26,436(r27)
	REX_STORE_U32(ctx.r27.u32 + 436, ctx.r26.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r11,3924(r27)
	REX_STORE_U32(ctx.r27.u32 + 3924, ctx.r11.u32);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// stw r26,3912(r27)
	REX_STORE_U32(ctx.r27.u32 + 3912, ctx.r26.u32);
	// stw r26,3916(r27)
	REX_STORE_U32(ctx.r27.u32 + 3916, ctx.r26.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x825db6ac
	if (!ctx.cr6.lt) goto loc_825DB6AC;
loc_825DB654:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825db6ac
	if (ctx.cr6.eq) goto loc_825DB6AC;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x825db69c
	if (!ctx.cr0.lt) goto loc_825DB69C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB69C;
	sub_825F8B58(ctx, base);
loc_825DB69C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x825db654
	if (ctx.cr6.gt) goto loc_825DB654;
loc_825DB6AC:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x825db6e8
	if (!ctx.cr0.lt) goto loc_825DB6E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB6E8;
	sub_825F8B58(ctx, base);
loc_825DB6E8:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r29,3908(r27)
	REX_STORE_U32(ctx.r27.u32 + 3908, ctx.r29.u32);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x825db760
	if (!ctx.cr6.lt) goto loc_825DB760;
loc_825DB708:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825db760
	if (ctx.cr6.eq) goto loc_825DB760;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x825db750
	if (!ctx.cr0.lt) goto loc_825DB750;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB750;
	sub_825F8B58(ctx, base);
loc_825DB750:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x825db708
	if (ctx.cr6.gt) goto loc_825DB708;
loc_825DB760:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x825db79c
	if (!ctx.cr0.lt) goto loc_825DB79C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB79C;
	sub_825F8B58(ctx, base);
loc_825DB79C:
	// stw r30,396(r27)
	REX_STORE_U32(ctx.r27.u32 + 396, ctx.r30.u32);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r30,3
	ctx.r30.s64 = 3;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x825db814
	if (!ctx.cr6.lt) goto loc_825DB814;
loc_825DB7BC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825db814
	if (ctx.cr6.eq) goto loc_825DB814;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x825db804
	if (!ctx.cr0.lt) goto loc_825DB804;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB804;
	sub_825F8B58(ctx, base);
loc_825DB804:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x825db7bc
	if (ctx.cr6.gt) goto loc_825DB7BC;
loc_825DB814:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x825db850
	if (!ctx.cr0.lt) goto loc_825DB850;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b58
	ctx.lr = 0x825DB850;
	sub_825F8B58(ctx, base);
loc_825DB850:
	// stw r30,15496(r27)
	REX_STORE_U32(ctx.r27.u32 + 15496, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_825DB860:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82603D38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82603D40;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d14
	ctx.lr = 0x82603D48;
	__savefpr_27(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82603d70
	if (!ctx.cr6.eq) goto loc_82603D70;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x82603D6C;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82603D70:
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// addi r9,r1,156
	ctx.r9.s64 = ctx.r1.s64 + 156;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,172
	ctx.r7.s64 = ctx.r1.s64 + 172;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,168
	ctx.r5.s64 = ctx.r1.s64 + 168;
	// addi r4,r1,164
	ctx.r4.s64 = ctx.r1.s64 + 164;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825d0800
	ctx.lr = 0x82603D94;
	sub_825D0800(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82604670
	if (!ctx.cr6.eq) goto loc_82604670;
	// lwz r11,15336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15336);
	// lwz r27,15396(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 15396);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82603dd8
	if (!ctx.cr6.eq) goto loc_82603DD8;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,148
	ctx.r9.s64 = ctx.r1.s64 + 148;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,188
	ctx.r7.s64 = ctx.r1.s64 + 188;
	// addi r6,r1,180
	ctx.r6.s64 = ctx.r1.s64 + 180;
	// addi r5,r1,184
	ctx.r5.s64 = ctx.r1.s64 + 184;
	// addi r4,r1,196
	ctx.r4.s64 = ctx.r1.s64 + 196;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825d0800
	ctx.lr = 0x82603DD0;
	sub_825D0800(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82604670
	if (!ctx.cr6.eq) goto loc_82604670;
loc_82603DD8:
	// addi r24,r31,15420
	ctx.r24.s64 = ctx.r31.s64 + 15420;
	// lwz r8,15424(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 15424);
	// addi r30,r31,15412
	ctx.r30.s64 = ctx.r31.s64 + 15412;
	// lwz r6,15416(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 15416);
	// addi r26,r31,15408
	ctx.r26.s64 = ctx.r31.s64 + 15408;
	// addi r9,r31,15428
	ctx.r9.s64 = ctx.r31.s64 + 15428;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82603598
	ctx.lr = 0x82603E04;
	sub_82603598(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82604670
	if (!ctx.cr6.eq) goto loc_82604670;
	// lwz r10,0(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82603f3c
	if (!ctx.cr6.gt) goto loc_82603F3C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82603f18
	if (ctx.cr6.eq) goto loc_82603F18;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x82603ecc
	if (ctx.cr6.eq) goto loc_82603ECC;
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// beq cr6,0x82603e48
	if (ctx.cr6.eq) goto loc_82603E48;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x82603E44;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82603E48:
	// lwz r11,15416(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15416);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r27,15436(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 15436);
	// stw r9,15336(r31)
	REX_STORE_U32(ctx.r31.u32 + 15336, ctx.r9.u32);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,164(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lfs f3,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,160(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f13,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f12,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lfs f6,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,156(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f0,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lfs f11,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,196(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lfs f10,32(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,184(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lfs f9,36(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,180(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lfs f8,40(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,188(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lfs f7,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,192(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lfs f5,48(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 48);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,148(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f7,52(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,144(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// b 0x82603f50
	goto loc_82603F50;
loc_82603ECC:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,15416(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 15416);
	// lwz r27,15432(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 15432);
	// stw r11,15336(r31)
	REX_STORE_U32(ctx.r31.u32 + 15336, ctx.r11.u32);
	// lfs f1,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,164(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f0,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lfs f3,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,160(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f13,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lfs f6,20(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,156(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f0,24(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// b 0x82603f4c
	goto loc_82603F4C;
loc_82603F18:
	// lwz r11,15416(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15416);
	// lfs f6,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lfs f7,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,144(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// b 0x82603f50
	goto loc_82603F50;
loc_82603F3C:
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f6,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f1.f64 = double(temp.f32);
loc_82603F4C:
	// lfs f7,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f7.f64 = double(temp.f32);
loc_82603F50:
	// lwz r11,15336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15336);
	// lwz r30,3800(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// lwz r29,3804(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lwz r28,3808(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// bne cr6,0x82603f74
	if (!ctx.cr6.eq) goto loc_82603F74;
	// lwz r30,3768(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3768);
	// lwz r29,3772(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3772);
	// lwz r28,3776(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 3776);
loc_82603F74:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,15440(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15440);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfd f31,14704(r9)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r9.u32 + 14704);
	// lfd f30,-2368(r8)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r8.u32 + -2368);
	// lfs f29,2884(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2884);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,11368(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,2880(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 2880);
	ctx.f27.f64 = double(temp.f32);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// lfs f13,15444(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// lfs f13,15448(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15448);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f3,f13
	ctx.cr6.compare(ctx.f3.f64, ctx.f13.f64);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// lfs f13,15452(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15452);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,172(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// lfs f13,15456(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15456);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// lfs f13,15460(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15460);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f6,f13
	ctx.cr6.compare(ctx.f6.f64, ctx.f13.f64);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// lfs f13,15464(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15464);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// lwz r9,288(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82604018
	if (ctx.cr6.eq) goto loc_82604018;
	// cmpw cr6,r25,r11
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x82604018
	if (!ctx.cr6.eq) goto loc_82604018;
	// cmpwi cr6,r10,18
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 18, ctx.xer);
	// bne cr6,0x826040d0
	if (!ctx.cr6.eq) goto loc_826040D0;
loc_82604018:
	// cmpwi cr6,r10,18
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 18, ctx.xer);
	// bne cr6,0x82604050
	if (!ctx.cr6.eq) goto loc_82604050;
	// lwz r11,15424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15424);
	// lfs f13,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f27
	ctx.cr6.compare(ctx.f13.f64, ctx.f27.f64);
	// bne cr6,0x8260403c
	if (!ctx.cr6.eq) goto loc_8260403C;
	// lfs f12,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f28
	ctx.cr6.compare(ctx.f12.f64, ctx.f28.f64);
	// ble cr6,0x826040d0
	if (!ctx.cr6.gt) goto loc_826040D0;
loc_8260403C:
	// fcmpu cr6,f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f29.f64);
	// bne cr6,0x82604050
	if (!ctx.cr6.eq) goto loc_82604050;
	// lfs f13,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f28
	ctx.cr6.compare(ctx.f13.f64, ctx.f28.f64);
	// bgt cr6,0x826040d0
	if (ctx.cr6.gt) goto loc_826040D0;
loc_82604050:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x8260406c
	if (!ctx.cr6.eq) goto loc_8260406C;
	// fmr f5,f30
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f30.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// b 0x82604090
	goto loc_82604090;
loc_8260406C:
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// bne cr6,0x82604084
	if (!ctx.cr6.eq) goto loc_82604084;
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f5,f1
	ctx.f5.f64 = ctx.f1.f64;
	// b 0x82604090
	goto loc_82604090;
loc_82604084:
	// lfs f5,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,172(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f2.f64 = double(temp.f32);
loc_82604090:
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// lwz r6,3752(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// lwz r5,3748(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lwz r4,3744(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f7,f0
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = ctx.f0.f64;
	// bl 0x825fe810
	ctx.lr = 0x826040B4;
	sub_825FE810(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82604670
	if (!ctx.cr6.eq) goto loc_82604670;
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f6,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f1.f64 = double(temp.f32);
	// lfs f7,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f7.f64 = double(temp.f32);
loc_826040D0:
	// lwz r11,15336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15336);
	// lfs f13,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,172(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// stfs f1,15440(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 15440, temp.u32);
	// stfs f13,15444(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 15444, temp.u32);
	// stfs f3,15448(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r31.u32 + 15448, temp.u32);
	// stfs f12,15452(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 15452, temp.u32);
	// stfs f11,15456(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 15456, temp.u32);
	// stfs f6,15460(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 15460, temp.u32);
	// stfs f0,15464(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 15464, temp.u32);
	// bne cr6,0x82604274
	if (!ctx.cr6.eq) goto loc_82604274;
	// lfs f0,15468(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f1,196(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,180(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f3.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lfs f0,15472(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,184(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lfs f0,15476(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15476);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f3,f0
	ctx.cr6.compare(ctx.f3.f64, ctx.f0.f64);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lfs f0,15480(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lfs f0,15484(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15484);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lfs f0,15488(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lfs f0,15492(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 15492);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f7,f0
	ctx.cr6.compare(ctx.f7.f64, ctx.f0.f64);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82604190
	if (ctx.cr6.eq) goto loc_82604190;
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// bne cr6,0x82604190
	if (!ctx.cr6.eq) goto loc_82604190;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// bne cr6,0x82604240
	if (!ctx.cr6.eq) goto loc_82604240;
loc_82604190:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,18
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 18, ctx.xer);
	// bne cr6,0x826041cc
	if (!ctx.cr6.eq) goto loc_826041CC;
	// lwz r11,15424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15424);
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bne cr6,0x826041b8
	if (!ctx.cr6.eq) goto loc_826041B8;
	// lfs f13,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f28
	ctx.cr6.compare(ctx.f13.f64, ctx.f28.f64);
	// bgt cr6,0x82604240
	if (ctx.cr6.gt) goto loc_82604240;
loc_826041B8:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bne cr6,0x826041cc
	if (!ctx.cr6.eq) goto loc_826041CC;
	// lfs f0,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x82604240
	if (!ctx.cr6.gt) goto loc_82604240;
loc_826041CC:
	// lwz r11,15396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826041ec
	if (!ctx.cr6.eq) goto loc_826041EC;
	// fmr f5,f30
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f30.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// b 0x82604210
	goto loc_82604210;
loc_826041EC:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82604204
	if (!ctx.cr6.eq) goto loc_82604204;
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f5,f1
	ctx.f5.f64 = ctx.f1.f64;
	// b 0x82604210
	goto loc_82604210;
loc_82604204:
	// lfs f5,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,184(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f2.f64 = double(temp.f32);
loc_82604210:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,3756(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3756);
	// lwz r5,3760(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3760);
	// lfs f6,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f6.f64 = double(temp.f32);
	// lwz r6,3764(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3764);
	// lwz r7,3812(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3812);
	// lwz r8,3816(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3816);
	// lwz r9,3820(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3820);
	// bl 0x825fe810
	ctx.lr = 0x82604234;
	sub_825FE810(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82604670
	if (!ctx.cr6.eq) goto loc_82604670;
	// lfs f7,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f7.f64 = double(temp.f32);
loc_82604240:
	// lfs f0,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,184(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,180(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,188(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,192(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f9.f64 = double(temp.f32);
	// stfs f0,15468(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 15468, temp.u32);
	// stfs f13,15472(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 15472, temp.u32);
	// stfs f12,15476(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 15476, temp.u32);
	// stfs f11,15480(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 15480, temp.u32);
	// stfs f10,15484(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 15484, temp.u32);
	// stfs f9,15488(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 15488, temp.u32);
	// stfs f7,15492(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 15492, temp.u32);
loc_82604274:
	// lwz r6,0(r26)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r11,r6,-11
	ctx.r11.s64 = ctx.r6.s64 + -11;
	// cmplwi cr6,r11,20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 20, ctx.xer);
	// bgt cr6,0x82604614
	if (ctx.cr6.gt) goto loc_82604614;
	// lis r12,-32160
	ctx.r12.s64 = -2107637760;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,17052
	ctx.r12.s64 = ctx.r12.s64 + 17052;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_826042F0;
	case 1:
		goto loc_826042F0;
	case 2:
		goto loc_82604614;
	case 3:
		goto loc_826042F0;
	case 4:
		goto loc_826042F0;
	case 5:
		goto loc_826042F0;
	case 6:
		goto loc_826042F0;
	case 7:
		goto loc_826042F0;
	case 8:
		goto loc_826042F0;
	case 9:
		goto loc_826042F0;
	case 10:
		goto loc_82604360;
	case 11:
		goto loc_82604614;
	case 12:
		goto loc_826042F0;
	case 13:
		goto loc_826042F0;
	case 14:
		goto loc_82604614;
	case 15:
		goto loc_82604614;
	case 16:
		goto loc_826042F0;
	case 17:
		goto loc_82604614;
	case 18:
		goto loc_826042F0;
	case 19:
		goto loc_826042F0;
	case 20:
		goto loc_826042F0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_826042F0:
	// lwz r11,3776(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3776);
	// lwz r27,3772(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 3772);
	// lwz r26,3768(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 3768);
	// lwz r30,3808(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r29,3804(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// lwz r11,3820(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3820);
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// lwz r28,3800(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// lwz r10,3816(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3816);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lwz r9,3812(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3812);
	// lwz r8,15424(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 15424);
	// lwz r7,0(r24)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// lwz r5,15344(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r4,15340(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// lwz r3,15404(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15404);
	// stw r30,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// stw r29,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// stw r28,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// bl 0x82602f38
	ctx.lr = 0x82604348;
	sub_82602F38(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8260466c
	if (ctx.cr6.eq) goto loc_8260466C;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x8260435C;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82604360:
	// lwz r11,15424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15424);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f12,f0
	ctx.f12.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f12,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.f12.u64);
	// lwz r4,204(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// lfs f11,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fctiwz f10,f13
	ctx.f10.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f9,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// fctiwz f8,f11
	ctx.f8.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.f10.u64);
	// lwz r11,204(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// stfd f8,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.f8.u64);
	// fcmpu cr6,f9,f27
	ctx.cr6.compare(ctx.f9.f64, ctx.f27.f64);
	// lwz r30,204(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// bne cr6,0x826043bc
	if (!ctx.cr6.eq) goto loc_826043BC;
	// lwz r5,3812(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3812);
	// lwz r6,3816(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3816);
	// lwz r7,3820(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3820);
	// lwz r8,3768(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3768);
	// lwz r9,3772(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3772);
	// lwz r10,3776(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3776);
	// b 0x826043d4
	goto loc_826043D4;
loc_826043BC:
	// lwz r5,3768(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3768);
	// lwz r6,3772(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3772);
	// lwz r7,3776(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3776);
	// lwz r8,3812(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3812);
	// lwz r9,3816(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3816);
	// lwz r10,3820(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3820);
loc_826043D4:
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x8260441c
	if (!ctx.cr6.eq) goto loc_8260441C;
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// lwz r3,3800(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// lwz r30,3808(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// lwz r29,3804(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// bl 0x8264f3c0
	ctx.lr = 0x82604408;
	sub_8264F3C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x82604418;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_8260441C:
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// bne cr6,0x82604464
	if (!ctx.cr6.eq) goto loc_82604464;
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// lwz r4,3800(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// lwz r3,3808(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r11,3804(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// stw r3,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// bl 0x82650110
	ctx.lr = 0x82604450;
	sub_82650110(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x82604460;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82604464:
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// bne cr6,0x826044ac
	if (!ctx.cr6.eq) goto loc_826044AC;
	// lwz r4,3808(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r3,3804(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// lwz r29,3800(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// bl 0x8264fa98
	ctx.lr = 0x82604498;
	sub_8264FA98(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x826044A8;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_826044AC:
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bne cr6,0x826044f4
	if (!ctx.cr6.eq) goto loc_826044F4;
	// lwz r4,3808(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r3,3804(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r29,3800(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// bl 0x8264ed08
	ctx.lr = 0x826044E0;
	sub_8264ED08(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x826044F0;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_826044F4:
	// cmpwi cr6,r4,5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 5, ctx.xer);
	// bne cr6,0x8260453c
	if (!ctx.cr6.eq) goto loc_8260453C;
	// lwz r4,3808(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r3,3804(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r29,3800(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// bl 0x8264e6c8
	ctx.lr = 0x82604528;
	sub_8264E6C8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x82604538;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_8260453C:
	// cmpwi cr6,r4,6
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 6, ctx.xer);
	// bne cr6,0x82604584
	if (!ctx.cr6.eq) goto loc_82604584;
	// lwz r4,3808(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r3,3804(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r29,3800(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// bl 0x8264e480
	ctx.lr = 0x82604570;
	sub_8264E480(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x82604580;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82604584:
	// cmpwi cr6,r4,7
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 7, ctx.xer);
	// bne cr6,0x826045cc
	if (!ctx.cr6.eq) goto loc_826045CC;
	// lwz r4,3808(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r3,3804(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r29,3800(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// bl 0x8264e0c8
	ctx.lr = 0x826045B8;
	sub_8264E0C8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x826045C8;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_826045CC:
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// bne cr6,0x8260466c
	if (!ctx.cr6.eq) goto loc_8260466C;
	// lwz r4,3808(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r3,3804(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// lwz r29,3800(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r4,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r3,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r4,15344(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 15344);
	// lwz r3,15340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15340);
	// bl 0x8264dd00
	ctx.lr = 0x82604600;
	sub_8264DD00(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x82604610;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82604614:
	// lwz r11,15336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15336);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8260466c
	if (!ctx.cr6.eq) goto loc_8260466C;
	// lwz r11,15364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15364);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,15360(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 15360);
	// lwz r5,3800(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3800);
	// mullw r30,r11,r10
	ctx.r30.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,3812(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3812);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x825fde90
	ctx.lr = 0x82604640;
	sub_825FDE90(ctx, base);
	// srawi r30,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 2;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,3804(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3804);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r4,3816(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3816);
	// bl 0x825fdfc0
	ctx.lr = 0x82604658;
	sub_825FDFC0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,3808(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3808);
	// lwz r4,3820(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 3820);
	// bl 0x825fdfc0
	ctx.lr = 0x8260466C;
	sub_825FDFC0(ctx, base);
loc_8260466C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82604670:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x826a0d60
	ctx.lr = 0x8260467C;
	__restfpr_27(ctx, base);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263A3A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8263A3B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8263a40c
	if (ctx.cr6.eq) goto loc_8263A40C;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8263a3e0
	if (ctx.cr6.eq) goto loc_8263A3E0;
loc_8263A3CC:
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825eeda8
	ctx.lr = 0x8263A3D4;
	sub_825EEDA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8263a3cc
	if (!ctx.cr6.eq) goto loc_8263A3CC;
loc_8263A3E0:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r29.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8263a408
	if (ctx.cr6.eq) goto loc_8263A408;
loc_8263A3F4:
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825eeda8
	ctx.lr = 0x8263A3FC;
	sub_825EEDA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8263a3f4
	if (!ctx.cr6.eq) goto loc_8263A3F4;
loc_8263A408:
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
loc_8263A40C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8263C4E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x8263C4E8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// rlwinm r25,r11,26,6,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x3FFFFFF;
	// slw r31,r10,r6
	ctx.r31.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r6.u8 & 0x3F));
	// rlwinm r11,r25,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// add r30,r11,r31
	ctx.r30.u64 = ctx.r11.u64 + ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r5,r30,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x826a03b0
	ctx.lr = 0x8263C520;
	rexcrt_memset(ctx, base);
	// cmplwi cr6,r27,16
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 16, ctx.xer);
	// blt cr6,0x8263c534
	if (ctx.cr6.lt) goto loc_8263C534;
loc_8263C528:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
loc_8263C534:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r6,r11,32768
	ctx.r6.u64 = ctx.r11.u64 | 32768;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// subf r5,r6,r31
	ctx.r5.u64 = ctx.r31.u64 - ctx.r6.u64;
	// subf r30,r6,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r6.u64;
	// ble cr6,0x8263c698
	if (!ctx.cr6.gt) goto loc_8263C698;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r31,r29,4
	ctx.r31.s64 = ctx.r29.s64 + 4;
loc_8263C558:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r10,r11,26
	ctx.r10.u64 = ctx.r11.u32 & 0x3F;
	// rlwinm r8,r11,26,6,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x3FFFFFF;
	// cmplwi cr6,r10,26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 26, ctx.xer);
	// bgt cr6,0x8263c528
	if (ctx.cr6.gt) goto loc_8263C528;
	// srw. r11,r8,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8263c528
	if (!ctx.cr0.eq) goto loc_8263C528;
	// cmplw cr6,r10,r27
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r27.u32, ctx.xer);
	// bgt cr6,0x8263c5e8
	if (ctx.cr6.gt) goto loc_8263C5E8;
	// subf r9,r10,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r10.u64;
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// slw r11,r8,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// slw r7,r7,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// beq cr6,0x8263c59c
	if (ctx.cr6.eq) goto loc_8263C59C;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
loc_8263C59C:
	// cmplwi cr6,r9,2048
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2048, ctx.xer);
	// bge cr6,0x8263c528
	if (!ctx.cr6.lt) goto loc_8263C528;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// beq cr6,0x8263c5b4
	if (ctx.cr6.eq) goto loc_8263C5B4;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
loc_8263C5B4:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r8,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 + ctx.r28.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r10,r9,-2
	ctx.r10.s64 = ctx.r9.s64 + -2;
loc_8263C5C8:
	// lhz r9,2(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8263c528
	if (!ctx.cr6.eq) goto loc_8263C528;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sthu r8,2(r10)
	ea = 2 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r8.u16);
	ctx.r10.u32 = ea;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bne cr6,0x8263c5c8
	if (!ctx.cr6.eq) goto loc_8263C5C8;
	// b 0x8263c684
	goto loc_8263C684;
loc_8263C5E8:
	// subf r10,r27,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r27.u64;
	// srw r11,r8,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
loc_8263C5F0:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r11,r28
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bgt cr6,0x8263c528
	if (ctx.cr6.gt) goto loc_8263C528;
	// bne cr6,0x8263c61c
	if (!ctx.cr6.eq) goto loc_8263C61C;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// addi r5,r5,2
	ctx.r5.s64 = ctx.r5.s64 + 2;
	// sthx r9,r11,r28
	REX_STORE_U16(ctx.r11.u32 + ctx.r28.u32, ctx.r9.u16);
	// cmpw cr6,r5,r30
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x8263c528
	if (ctx.cr6.gt) goto loc_8263C528;
loc_8263C61C:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lhzx r11,r11,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// srw r9,r8,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
	// extsh r7,r11
	ctx.r7.s64 = ctx.r11.s16;
	// clrlwi r9,r9,31
	ctx.r9.u64 = ctx.r9.u32 & 0x1;
	// add r11,r7,r6
	ctx.r11.u64 = ctx.r7.u64 + ctx.r6.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8263c640
	if (ctx.cr6.eq) goto loc_8263C640;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_8263C640:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8263c5f0
	if (!ctx.cr6.eq) goto loc_8263C5F0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r10,r28
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r28.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8263c528
	if (!ctx.cr6.eq) goto loc_8263C528;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// beq cr6,0x8263c668
	if (ctx.cr6.eq) goto loc_8263C668;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
loc_8263C668:
	// cmplwi cr6,r11,32768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32768, ctx.xer);
	// bge cr6,0x8263c528
	if (!ctx.cr6.lt) goto loc_8263C528;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// beq cr6,0x8263c680
	if (ctx.cr6.eq) goto loc_8263C680;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
loc_8263C680:
	// sthx r11,r10,r28
	REX_STORE_U16(ctx.r10.u32 + ctx.r28.u32, ctx.r11.u16);
loc_8263C684:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// cmpw cr6,r4,r25
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x8263c558
	if (ctx.cr6.lt) goto loc_8263C558;
loc_8263C698:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82641FB8) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// ble cr6,0x82641fdc
	if (!ctx.cr6.gt) goto loc_82641FDC;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// ble cr6,0x82641fe8
	if (!ctx.cr6.gt) goto loc_82641FE8;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -1);
	// clrlwi r3,r10,30
	ctx.r3.u64 = ctx.r10.u32 & 0x3;
	// blr 
	return;
loc_82641FDC:
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bgtlr cr6
	if (ctx.cr6.gt) return;
loc_82641FE8:
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82642748) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82642750;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,24(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r29,32
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// ble cr6,0x8264277c
	if (!ctx.cr6.gt) goto loc_8264277C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8264282c
	goto loc_8264282C;
loc_8264277C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8264278c
	if (!ctx.cr6.eq) goto loc_8264278C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8264282c
	goto loc_8264282C;
loc_8264278C:
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x826427ec
	if (!ctx.cr6.gt) goto loc_826427EC;
loc_82642794:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826427ec
	if (ctx.cr6.eq) goto loc_826427EC;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r29,r11,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r29
	ctx.r11.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r29.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r3.u32);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r10,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r10.u64);
	// bge 0x826427dc
	if (!ctx.cr0.lt) goto loc_826427DC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b58
	ctx.lr = 0x826427DC;
	sub_825F8B58(ctx, base);
loc_826427DC:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82642794
	if (ctx.cr6.gt) goto loc_82642794;
loc_826427EC:
	// subfic r11,r29,64
	ctx.xer.ca = ctx.r29.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r29.u64;
	// ld r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrldi r8,r29,32
	ctx.r8.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r29,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r29,r11,r28
	ctx.r29.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r4,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r4.u64);
	// bge 0x82642828
	if (!ctx.cr0.lt) goto loc_82642828;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b58
	ctx.lr = 0x82642828;
	sub_825F8B58(ctx, base);
loc_82642828:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8264282C:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lwz r7,32(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// mullw r11,r6,r11
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8264285c
	if (!ctx.cr6.eq) goto loc_8264285C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_8264285C:
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x826428d0
	if (!ctx.cr6.gt) goto loc_826428D0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
loc_82642874:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// lbzu r8,1(r7)
	ea = 1 + ctx.r7.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r7.u32 = ea;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r6,r8,28
	ctx.r6.u64 = ctx.r8.u32 & 0xF;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 1;
	// rlwinm r6,r8,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0xFFFFFFF;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// addi r3,r6,1
	ctx.r3.s64 = ctx.r6.s64 + 1;
	// rlwimi r5,r4,0,0,25
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFC0) | (ctx.r5.u64 & 0xFFFFFFFF0000003F);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwimi r3,r8,0,0,25
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFC0) | (ctx.r3.u64 & 0xFFFFFFFF0000003F);
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x82642874
	if (ctx.cr6.lt) goto loc_82642874;
loc_826428D0:
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x826420f8
	ctx.lr = 0x826428DC;
	sub_826420F8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r6,6
	ctx.r6.s64 = 6;
	// lwz r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8263c7d8
	ctx.lr = 0x826428F4;
	sub_8263C7D8(ctx, base);
	// subfic r10,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// li r8,2
	ctx.r8.s64 = 2;
	// subfe r7,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r7,r8
	ctx.r3.u64 = ctx.r7.u64 & ctx.r8.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826553B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x826553B8;
	__savegprlr_14(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r28,r10,3
	ctx.r28.s64 = ctx.r10.s64 + 3;
	// lis r30,-32245
	ctx.r30.s64 = -2113208320;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// li r31,1
	ctx.r31.s64 = 1;
	// rlwinm r29,r11,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r11,r30,11784
	ctx.r11.s64 = ctx.r30.s64 + 11784;
	// and r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 & ctx.r10.u64;
	// rlwinm r30,r7,3,0,28
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// rlwinm r29,r8,3,0,28
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// slw r15,r31,r28
	ctx.r15.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r28.u8 & 0x3F));
	// slw r28,r31,r10
	ctx.r28.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r10.u8 & 0x3F));
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// add r24,r30,r11
	ctx.r24.u64 = ctx.r30.u64 + ctx.r11.u64;
	// add r21,r29,r11
	ctx.r21.u64 = ctx.r29.u64 + ctx.r11.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x82655420
	if (!ctx.cr6.eq) goto loc_82655420;
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// li r23,4
	ctx.r23.s64 = 4;
	// beq cr6,0x82655410
	if (ctx.cr6.eq) goto loc_82655410;
	// li r23,6
	ctx.r23.s64 = 6;
loc_82655410:
	// li r20,0
	ctx.r20.s64 = 0;
	// li r19,0
	ctx.r19.s64 = 0;
	// addi r17,r15,1
	ctx.r17.s64 = ctx.r15.s64 + 1;
	// b 0x82655488
	goto loc_82655488;
loc_82655420:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x82655454
	if (!ctx.cr6.eq) goto loc_82655454;
	// li r23,0
	ctx.r23.s64 = 0;
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// li r20,4
	ctx.r20.s64 = 4;
	// beq cr6,0x8265543c
	if (ctx.cr6.eq) goto loc_8265543C;
	// li r20,6
	ctx.r20.s64 = 6;
loc_8265543C:
	// addi r11,r20,-1
	ctx.r11.s64 = ctx.r20.s64 + -1;
	// li r22,0
	ctx.r22.s64 = 0;
	// slw r9,r31,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r11.u8 & 0x3F));
	// subf r19,r10,r9
	ctx.r19.u64 = ctx.r9.u64 - ctx.r10.u64;
	// addi r17,r15,3
	ctx.r17.s64 = ctx.r15.s64 + 3;
	// b 0x82655498
	goto loc_82655498;
loc_82655454:
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// li r9,4
	ctx.r9.s64 = 4;
	// beq cr6,0x82655464
	if (ctx.cr6.eq) goto loc_82655464;
	// li r9,6
	ctx.r9.s64 = 6;
loc_82655464:
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// li r11,4
	ctx.r11.s64 = 4;
	// beq cr6,0x82655474
	if (ctx.cr6.eq) goto loc_82655474;
	// li r11,6
	ctx.r11.s64 = 6;
loc_82655474:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r20,7
	ctx.r20.s64 = 7;
	// addi r23,r11,-7
	ctx.r23.s64 = ctx.r11.s64 + -7;
	// subfic r19,r10,64
	ctx.xer.ca = ctx.r10.u32 <= 64;
	ctx.r19.u64 = static_cast<uint64_t>(64) - ctx.r10.u64;
	// addi r17,r15,3
	ctx.r17.s64 = ctx.r15.s64 + 3;
loc_82655488:
	// addi r11,r23,-1
	ctx.r11.s64 = ctx.r23.s64 + -1;
	// slw r11,r31,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r31.u32 << (ctx.r11.u8 & 0x3F));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r22,r11,-1
	ctx.r22.s64 = ctx.r11.s64 + -1;
loc_82655498:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x826555f8
	if (!ctx.cr6.gt) goto loc_826555F8;
	// subf r11,r4,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r4.u64;
	// mr r16,r28
	ctx.r16.u64 = ctx.r28.u64;
	// addi r18,r11,-1
	ctx.r18.s64 = ctx.r11.s64 + -1;
loc_826554AC:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// ble cr6,0x82655544
	if (!ctx.cr6.gt) goto loc_82655544;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r7,6(r21)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r21.u32 + 6);
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r31,4(r21)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r21.u32 + 4);
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// lhz r28,2(r21)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r21.u32 + 2);
	// lhz r27,0(r21)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r21.u32 + 0);
	// add r26,r4,r10
	ctx.r26.u64 = ctx.r4.u64 + ctx.r10.u64;
	// addi r9,r1,-226
	ctx.r9.s64 = ctx.r1.s64 + -226;
	// mtctr r17
	ctx.ctr.u64 = ctx.r17.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// extsh r29,r31
	ctx.r29.s64 = ctx.r31.s16;
	// extsh r28,r28
	ctx.r28.s64 = ctx.r28.s16;
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// addi r10,r18,-1
	ctx.r10.s64 = ctx.r18.s64 + -1;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subf r26,r8,r26
	ctx.r26.u64 = ctx.r26.u64 - ctx.r8.u64;
	// subf r25,r8,r4
	ctx.r25.u64 = ctx.r4.u64 - ctx.r8.u64;
loc_82655500:
	// lbzx r8,r25,r11
	ctx.r8.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r11.u32);
	// lbzx r31,r26,r11
	ctx.r31.u64 = REX_LOAD_U8(ctx.r26.u32 + ctx.r11.u32);
	// mullw r7,r8,r28
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r28.s32);
	// lbz r14,0(r11)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbzu r8,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// mullw r31,r31,r30
	ctx.r31.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r30.s32);
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + ctx.r31.u64;
	// mullw r31,r14,r29
	ctx.r31.s64 = int64_t(ctx.r14.s32) * int64_t(ctx.r29.s32);
	// mr r14,r8
	ctx.r14.u64 = ctx.r8.u64;
	// add r8,r7,r31
	ctx.r8.u64 = ctx.r7.u64 + ctx.r31.u64;
	// mullw r7,r14,r27
	ctx.r7.s64 = int64_t(ctx.r14.s32) * int64_t(ctx.r27.s32);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r7,r8,r22
	ctx.r7.u64 = ctx.r8.u64 + ctx.r22.u64;
	// sraw r8,r7,r23
	temp.u32 = ctx.r23.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r7.s32 < 0) & (((ctx.r7.s32 >> temp.u32) << temp.u32) != ctx.r7.s32);
	ctx.r8.s64 = ctx.r7.s32 >> temp.u32;
	// sthu r8,2(r9)
	ea = 2 + ctx.r9.u32;
	REX_STORE_U16(ea, ctx.r8.u16);
	ctx.r9.u32 = ea;
	// bdnz 0x82655500
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82655500;
loc_82655544:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r15,0
	ctx.cr6.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// ble cr6,0x826555e4
	if (!ctx.cr6.gt) goto loc_826555E4;
	// mtctr r15
	ctx.ctr.u64 = ctx.r15.u64;
	// addi r11,r1,-220
	ctx.r11.s64 = ctx.r1.s64 + -220;
loc_82655558:
	// lhz r9,-4(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + -4);
	// lhz r31,0(r24)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lhz r7,6(r24)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r24.u32 + 6);
	// extsh r31,r31
	ctx.r31.s64 = ctx.r31.s16;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// lhz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// lhz r29,4(r24)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r24.u32 + 4);
	// mullw r9,r9,r31
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r31.s32);
	// lhz r28,2(r24)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r24.u32 + 2);
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lhz r7,-2(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// extsh r31,r30
	ctx.r31.s64 = ctx.r30.s16;
	// extsh r30,r29
	ctx.r30.s64 = ctx.r29.s16;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r31,r30
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r30.s32);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// extsh r31,r28
	ctx.r31.s64 = ctx.r28.s16;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r7,r31
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r31.s32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r10,r19
	ctx.r10.u64 = ctx.r10.u64 + ctx.r19.u64;
	// sraw. r10,r10,r20
	temp.u32 = ctx.r20.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge 0x826555c8
	if (!ctx.cr0.lt) goto loc_826555C8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x826555d4
	goto loc_826555D4;
loc_826555C8:
	// cmpwi cr6,r10,255
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 255, ctx.xer);
	// ble cr6,0x826555d4
	if (!ctx.cr6.gt) goto loc_826555D4;
	// li r10,255
	ctx.r10.s64 = 255;
loc_826555D4:
	// stbx r10,r8,r5
	REX_STORE_U8(ctx.r8.u32 + ctx.r5.u32, ctx.r10.u8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bdnz 0x82655558
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82655558;
loc_826555E4:
	// addic. r16,r16,-1
	ctx.xer.ca = ctx.r16.u32 > 0;
	ctx.r16.s64 = ctx.r16.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// add r3,r3,r4
	ctx.r3.u64 = ctx.r3.u64 + ctx.r4.u64;
	// add r18,r18,r4
	ctx.r18.u64 = ctx.r18.u64 + ctx.r4.u64;
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// bne 0x826554ac
	if (!ctx.cr0.eq) goto loc_826554AC;
loc_826555F8:
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265DFE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265e008
	if (!ctx.cr6.eq) goto loc_8265E008;
	// lwz r11,56(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 56);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r11,20(r5)
	REX_STORE_U32(ctx.r5.u32 + 20, ctx.r11.u32);
	// b 0x8265e054
	goto loc_8265E054;
loc_8265E008:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8265e054
	if (!ctx.cr6.eq) goto loc_8265E054;
	// lwz r11,60(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 60);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r11,24(r5)
	REX_STORE_U32(ctx.r5.u32 + 24, ctx.r11.u32);
	// beq cr6,0x8265e02c
	if (ctx.cr6.eq) goto loc_8265E02C;
	// stw r6,28(r5)
	REX_STORE_U32(ctx.r5.u32 + 28, ctx.r6.u32);
	// b 0x8265e038
	goto loc_8265E038;
loc_8265E02C:
	// lwz r11,64(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 64);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r11,28(r5)
	REX_STORE_U32(ctx.r5.u32 + 28, ctx.r11.u32);
loc_8265E038:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8265e048
	if (ctx.cr6.eq) goto loc_8265E048;
	// stw r7,32(r5)
	REX_STORE_U32(ctx.r5.u32 + 32, ctx.r7.u32);
	// b 0x8265e054
	goto loc_8265E054;
loc_8265E048:
	// lwz r11,68(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 68);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r11,32(r5)
	REX_STORE_U32(ctx.r5.u32 + 32, ctx.r11.u32);
loc_8265E054:
	// lwz r11,16(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8265e070
	if (!ctx.cr6.eq) goto loc_8265E070;
	// lwz r11,72(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 72);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r11,36(r5)
	REX_STORE_U32(ctx.r5.u32 + 36, ctx.r11.u32);
	// b 0x8265e0a0
	goto loc_8265E0A0;
loc_8265E070:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8265e0a0
	if (!ctx.cr6.eq) goto loc_8265E0A0;
	// lwz r11,52(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 52);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8265e0a0
	if (ctx.cr6.eq) goto loc_8265E0A0;
	// lwz r10,76(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 76);
	// lwz r11,80(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 80);
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// stw r4,40(r5)
	REX_STORE_U32(ctx.r5.u32 + 40, ctx.r4.u32);
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r10,44(r5)
	REX_STORE_U32(ctx.r5.u32 + 44, ctx.r10.u32);
	// stw r9,48(r5)
	REX_STORE_U32(ctx.r5.u32 + 48, ctx.r9.u32);
loc_8265E0A0:
	// lwz r11,14560(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 14560);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8265e0b4
	if (!ctx.cr6.eq) goto loc_8265E0B4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x8265d070
	ctx.lr = 0x8265E0B4;
	sub_8265D070(ctx, base);
loc_8265E0B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82664C50) {
	REX_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82664bb0
	sub_82664BB0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82664D30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82664D38;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,52(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r3,52
	ctx.r30.s64 = ctx.r3.s64 + 52;
	// li r28,0
	ctx.r28.s64 = 0;
loc_82664D4C:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82664d9c
	if (ctx.cr6.eq) goto loc_82664D9C;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// beq cr6,0x82664d9c
	if (ctx.cr6.eq) goto loc_82664D9C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82664d8c
	if (ctx.cr6.eq) goto loc_82664D8C;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82664d80
	if (!ctx.cr6.eq) goto loc_82664D80;
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
loc_82664D80:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r28,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
loc_82664D8C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82664c90
	ctx.lr = 0x82664D94;
	sub_82664C90(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x82664d4c
	goto loc_82664D4C;
loc_82664D9C:
	// lwz r4,44(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
loc_82664DA4:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82664ee0
	if (ctx.cr6.eq) goto loc_82664EE0;
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r11,259
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 259, ctx.xer);
	// beq cr6,0x82664ee0
	if (ctx.cr6.eq) goto loc_82664EE0;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82664de8
	if (ctx.cr6.eq) goto loc_82664DE8;
	// lwz r8,4(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82664ddc
	if (!ctx.cr6.eq) goto loc_82664DDC;
	// stw r28,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r28.u32);
loc_82664DDC:
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// stw r28,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
loc_82664DE8:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82664ed0
	if (!ctx.cr6.eq) goto loc_82664ED0;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 60);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r10,140(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 140);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82664e14
	if (ctx.cr6.eq) goto loc_82664E14;
	// stb r10,60(r31)
	REX_STORE_U8(ctx.r31.u32 + 60, ctx.r10.u8);
loc_82664E14:
	// lhz r10,62(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// blt cr6,0x82664e24
	if (ctx.cr6.lt) goto loc_82664E24;
	// sth r28,62(r31)
	REX_STORE_U16(ctx.r31.u32 + 62, ctx.r28.u16);
loc_82664E24:
	// lhz r10,-2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lbz r8,60(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 60);
	// li r7,259
	ctx.r7.s64 = 259;
	// rlwimi r10,r8,12,0,19
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFFFF000) | (ctx.r10.u64 & 0xFFFFFFFF00000FFF);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// sth r10,-2(r11)
	REX_STORE_U16(ctx.r11.u32 + -2, ctx.r10.u16);
	// lhz r10,62(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// rlwimi r8,r10,1,20,30
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFE) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF001);
	// sth r8,-2(r11)
	REX_STORE_U16(ctx.r11.u32 + -2, ctx.r8.u16);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lhz r10,62(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 62);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,62(r31)
	REX_STORE_U16(ctx.r31.u32 + 62, ctx.r10.u16);
	// lhz r10,-2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// lwz r8,204(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 204);
	// rlwinm r8,r8,0,12,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xF0000;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwimi r10,r9,27,31,31
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// sth r10,-2(r11)
	REX_STORE_U16(ctx.r11.u32 + -2, ctx.r10.u16);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r28,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r28.u32);
	// stw r28,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r28.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82664ea4
	if (ctx.cr6.eq) goto loc_82664EA4;
	// stw r4,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r4.u32);
	// b 0x82664ea8
	goto loc_82664EA8;
loc_82664EA4:
	// stw r4,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r4.u32);
loc_82664EA8:
	// stw r4,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,244(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 244);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stw r10,244(r11)
	REX_STORE_U32(ctx.r11.u32 + 244, ctx.r10.u32);
	// b 0x82664ed8
	goto loc_82664ED8;
loc_82664ED0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82664c90
	ctx.lr = 0x82664ED8;
	sub_82664C90(ctx, base);
loc_82664ED8:
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x82664da4
	goto loc_82664DA4;
loc_82664EE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82668960) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82668968;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// bl 0x82667d28
	ctx.lr = 0x82668984;
	sub_82667D28(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x826689ac
	if (ctx.cr0.eq) goto loc_826689AC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826689A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_826689AC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826699C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x826699C8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82669a60
	if (ctx.cr6.eq) goto loc_82669A60;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82669890
	ctx.lr = 0x826699E8;
	sub_82669890(ctx, base);
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82669a14
	if (ctx.cr6.eq) goto loc_82669A14;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82669a10
	if (ctx.cr6.eq) goto loc_82669A10;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82669A10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82669A10:
	// stw r28,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r28.u32);
loc_82669A14:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82669a28
	if (ctx.cr6.eq) goto loc_82669A28;
	// bl 0x82669c90
	ctx.lr = 0x82669A24;
	sub_82669C90(ctx, base);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
loc_82669A28:
	// addi r31,r30,8
	ctx.r31.s64 = ctx.r30.s64 + 8;
	// li r29,2
	ctx.r29.s64 = 2;
loc_82669A30:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82669a44
	if (ctx.cr6.eq) goto loc_82669A44;
	// bl 0x82669c90
	ctx.lr = 0x82669A40;
	sub_82669C90(ctx, base);
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_82669A44:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82669a30
	if (!ctx.cr0.eq) goto loc_82669A30;
	// lis r4,25738
	ctx.r4.s64 = 1686765568;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// bl 0x824c6550
	ctx.lr = 0x82669A60;
	sub_824C6550(ctx, base);
loc_82669A60:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266B578) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x8266B580;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r28,r28,87
	ctx.r28.u64 = ctx.r28.u64 | 87;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8266b5e0
	if (ctx.cr6.eq) goto loc_8266B5E0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
loc_8266B5A4:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8266ad98
	ctx.lr = 0x8266B5B0;
	sub_8266AD98(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8266b5e0
	if (ctx.cr0.eq) goto loc_8266B5E0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266B5C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt 0x8266b5e0
	if (ctx.cr0.lt) goto loc_8266B5E0;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8266b5a4
	if (ctx.cr6.lt) goto loc_8266B5A4;
loc_8266B5E0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266E0B8) {
	REX_FUNC_PROLOGUE();
	// b 0x8266dff8
	sub_8266DFF8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266E3F8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 92);
	// stb r11,0(r4)
	REX_STORE_U8(ctx.r4.u32 + 0, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8266E618) {
	REX_FUNC_PROLOGUE();
	// b 0x8266e4d0
	sub_8266E4D0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266E650) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32049
	ctx.r10.s64 = -2100363264;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,24464(r10)
	REX_STORE_U32(ctx.r10.u32 + 24464, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8266E820) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8266E828;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// stw r5,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r6,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// clrlwi r9,r8,16
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFF;
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r30,r11,13812
	ctx.r30.s64 = ctx.r11.s64 + 13812;
	// stw r10,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// stw r9,64(r3)
	REX_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
	// addi r29,r3,-4
	ctx.r29.s64 = ctx.r3.s64 + -4;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// sth r7,84(r1)
	REX_STORE_U16(ctx.r1.u32 + 84, ctx.r7.u16);
loc_8266E85C:
	// lwzu r11,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lha r5,0(r31)
	ctx.r5.s64 = int16_t(REX_LOAD_U16(ctx.r31.u32 + 0));
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x8266fb88
	ctx.lr = 0x8266E870;
	sub_8266FB88(ctx, base);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// addi r11,r30,34
	ctx.r11.s64 = ctx.r30.s64 + 34;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8266e85c
	if (ctx.cr6.lt) goto loc_8266E85C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266FF88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0268
	ctx.lr = 0x8266FF90;
	__savegprlr_16(ctx, base);
	// stfd f31,-144(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// addi r23,r10,-15632
	ctx.r23.s64 = ctx.r10.s64 + -15632;
	// lfs f0,2952(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2952);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// addi r11,r11,14832
	ctx.r11.s64 = ctx.r11.s64 + 14832;
	// ble cr6,0x8266ffd0
	if (!ctx.cr6.gt) goto loc_8266FFD0;
	// addi r9,r11,1644
	ctx.r9.s64 = ctx.r11.s64 + 1644;
	// mr r21,r11
	ctx.r21.u64 = ctx.r11.u64;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// b 0x8266ffdc
	goto loc_8266FFDC;
loc_8266FFD0:
	// addi r9,r11,2744
	ctx.r9.s64 = ctx.r11.s64 + 2744;
	// addi r21,r11,48
	ctx.r21.s64 = ctx.r11.s64 + 48;
	// addi r10,r23,24
	ctx.r10.s64 = ctx.r23.s64 + 24;
loc_8266FFDC:
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// addi r9,r11,3600
	ctx.r9.s64 = ctx.r11.s64 + 3600;
	// addi r8,r11,4324
	ctx.r8.s64 = ctx.r11.s64 + 4324;
	// addi r11,r11,4984
	ctx.r11.s64 = ctx.r11.s64 + 4984;
	// stw r9,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// stw r8,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// stw r11,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// ble cr6,0x8267002c
	if (!ctx.cr6.gt) goto loc_8267002C;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// mtctr r20
	ctx.ctr.u64 = ctx.r20.u64;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// subf r9,r21,r19
	ctx.r9.u64 = ctx.r19.u64 - ctx.r21.u64;
	// subf r8,r21,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r21.u64;
loc_82670014:
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfsx f0,r8,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82670014
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82670014;
loc_8267002C:
	// addi r11,r23,48
	ctx.r11.s64 = ctx.r23.s64 + 48;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r29,r11,-16
	ctx.r29.s64 = ctx.r11.s64 + -16;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r31,r1,144
	ctx.r31.s64 = ctx.r1.s64 + 144;
	// lfs f31,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r28,r1,128
	ctx.r28.s64 = ctx.r1.s64 + 128;
	// addi r26,r1,148
	ctx.r26.s64 = ctx.r1.s64 + 148;
	// subf r22,r9,r10
	ctx.r22.u64 = ctx.r10.u64 - ctx.r9.u64;
loc_82670060:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lwzx r10,r22,r28
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r28.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// li r11,2
	ctx.r11.s64 = 2;
loc_82670078:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x826700a0
	if (!ctx.cr6.gt) goto loc_826700A0;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
loc_8267008C:
	// lfsx f13,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fmadds f0,f13,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f0.f64)));
	// bdnz 0x8267008c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267008C;
loc_826700A0:
	// stfsu f0,4(r8)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r8.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r8.u32 = ea;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// add r10,r27,r10
	ctx.r10.u64 = ctx.r27.u64 + ctx.r10.u64;
	// bne 0x82670078
	if (!ctx.cr0.eq) goto loc_82670078;
	// lfs f0,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// lfs f13,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f0,f2
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f2.f64));
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// bge cr6,0x8267011c
	if (!ctx.cr6.lt) goto loc_8267011C;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r18,28(r11)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r17,24(r11)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r16,20(r11)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r18,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r18.u32);
	// stw r17,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r17.u32);
	// stw r16,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r16.u32);
	// bl 0x8266fd10
	ctx.lr = 0x82670118;
	sub_8266FD10(ctx, base);
	// b 0x8267016c
	goto loc_8267016C;
loc_8267011C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8266fca0
	ctx.lr = 0x82670130;
	sub_8266FCA0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// subfc r9,r9,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r9.u32;
	ctx.r9.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lfsux f0,r11,r10
	ctx.fpscr.disableFlushMode();
	ea = ctx.r11.u32 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_8267016C:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r23,48
	ctx.r11.s64 = ctx.r23.s64 + 48;
	// fadds f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfsu f0,4(r31)
	ea = 4 + ctx.r31.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r31.u32 = ea;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// addi r25,r25,2
	ctx.r25.s64 = ctx.r25.s64 + 2;
	// addi r27,r27,8
	ctx.r27.s64 = ctx.r27.s64 + 8;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82670060
	if (ctx.cr6.lt) goto loc_82670060;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x826701ec
	if (!ctx.cr6.gt) goto loc_826701EC;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// mtctr r20
	ctx.ctr.u64 = ctx.r20.u64;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// subf r10,r10,r21
	ctx.r10.u64 = ctx.r21.u64 - ctx.r10.u64;
	// subf r9,r9,r19
	ctx.r9.u64 = ctx.r19.u64 - ctx.r9.u64;
loc_826701D4:
	// lfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfsx f0,r9,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x826701d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826701D4;
loc_826701EC:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x826a02b8
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8267AE58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lis r12,-3856
	ctx.r12.s64 = -252706816;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// and r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 & ctx.r10.u64;
	// ori r12,r12,61680
	ctx.r12.u64 = ctx.r12.u64 | 61680;
	// rlwinm r6,r8,0,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF0000;
	// rlwinm r5,r8,0,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF00;
	// addic r4,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r4.s64 = ctx.r6.s64 + -1;
	// rlwinm r5,r5,0,16,7
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFF00FFFF;
	// subfe r6,r4,r6
	temp.u8 = (~ctx.r4.u32 + ctx.r6.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r4.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r4,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r4.s64 = ctx.r5.s64 + -1;
	// and r3,r8,r12
	ctx.r3.u64 = ctx.r8.u64 & ctx.r12.u64;
	// lis r12,-13108
	ctx.r12.s64 = -859045888;
	// subfe r5,r4,r5
	temp.u8 = (~ctx.r4.u32 + ctx.r5.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r4.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addic r4,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r4.s64 = ctx.r3.s64 + -1;
	// ori r12,r12,52428
	ctx.r12.u64 = ctx.r12.u64 | 52428;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// subfe r5,r4,r3
	temp.u8 = (~ctx.r4.u32 + ctx.r3.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r4.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r8,r12
	ctx.r4.u64 = ctx.r8.u64 & ctx.r12.u64;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r12,-21846
	ctx.r12.s64 = -1431699456;
	// addic r3,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r3.s64 = ctx.r4.s64 + -1;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// ori r12,r12,43690
	ctx.r12.u64 = ctx.r12.u64 | 43690;
	// subfe r5,r3,r4
	temp.u8 = (~ctx.r3.u32 + ctx.r4.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r3.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r8,r12
	ctx.r4.u64 = ctx.r8.u64 & ctx.r12.u64;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addic r3,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r3.s64 = ctx.r4.s64 + -1;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// subfe r5,r3,r4
	temp.u8 = (~ctx.r3.u32 + ctx.r4.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r3.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// xor r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// or r8,r6,r5
	ctx.r8.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// mullw r11,r8,r7
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8267D068) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8267d090
	goto loc_8267D090;
loc_8267D084:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8267d090
	if (ctx.cr6.eq) goto loc_8267D090;
	// bl 0x826888c0
	ctx.lr = 0x8267D090;
	sub_826888C0(ctx, base);
loc_8267D090:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8267c200
	ctx.lr = 0x8267D098;
	sub_8267C200(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8267d084
	if (!ctx.cr0.eq) goto loc_8267D084;
	// addi r30,r31,124
	ctx.r30.s64 = ctx.r31.s64 + 124;
	// b 0x8267d0b4
	goto loc_8267D0B4;
loc_8267D0A8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8267d0b4
	if (ctx.cr6.eq) goto loc_8267D0B4;
	// bl 0x826888c0
	ctx.lr = 0x8267D0B4;
	sub_826888C0(ctx, base);
loc_8267D0B4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8267c200
	ctx.lr = 0x8267D0BC;
	sub_8267C200(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8267d0a8
	if (!ctx.cr0.eq) goto loc_8267D0A8;
	// lwz r3,252(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8267d0d8
	if (ctx.cr6.eq) goto loc_8267D0D8;
	// lwz r4,248(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// bl 0x824c6550
	ctx.lr = 0x8267D0D8;
	sub_824C6550(ctx, base);
loc_8267D0D8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8267c7b0
	ctx.lr = 0x8267D0E0;
	sub_8267C7B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8267c7b0
	ctx.lr = 0x8267D0E8;
	sub_8267C7B0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8267F868) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_8267F908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8267f98c
	if (ctx.cr6.eq) goto loc_8267F98C;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
loc_8267F920:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8267f97c
	if (ctx.cr6.eq) goto loc_8267F97C;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_8267F930:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,12(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r4,24(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lfsx f13,r8,r6
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r6.u32);
	ctx.f13.f64 = double(temp.f32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r6,r7
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsx f0,r10,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r4.u32, temp.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8267f930
	if (ctx.cr6.lt) goto loc_8267F930;
loc_8267F97C:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8267f920
	if (ctx.cr6.lt) goto loc_8267F920;
loc_8267F98C:
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,24(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_826829C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,36(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x826829fc
	if (!ctx.cr6.lt) goto loc_826829FC;
	// bl 0x826ccd04
	ctx.lr = 0x826829F0;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x826829fc
	if (ctx.cr6.eq) goto loc_826829FC;
	// li r30,1
	ctx.r30.s64 = 1;
loc_826829FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82682a10
	if (ctx.cr6.eq) goto loc_82682A10;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82682a7c
	if (ctx.cr6.eq) goto loc_82682A7C;
loc_82682A10:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bgt cr6,0x82682a6c
	if (ctx.cr6.gt) goto loc_82682A6C;
	// lis r11,-32049
	ctx.r11.s64 = -2100363264;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,24480
	ctx.r3.s64 = ctx.r11.s64 + 24480;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8267b598
	ctx.lr = 0x82682A38;
	sub_8267B598(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82682a7c
	if (ctx.cr0.eq) goto loc_82682A7C;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// b 0x82682a7c
	goto loc_82682A7C;
loc_82682A6C:
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// addi r3,r11,-32464
	ctx.r3.s64 = ctx.r11.s64 + -32464;
	// bl 0x826b6500
	ctx.lr = 0x82682A78;
	sub_826B6500(ctx, base);
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82682A7C:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82682a94
	if (ctx.cr6.eq) goto loc_82682A94;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82682a98
	goto loc_82682A98;
loc_82682A94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82682A98:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82685EF8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,136(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82686070) {
	REX_FUNC_PROLOGUE();
	// lwz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82686708) {
	REX_FUNC_PROLOGUE();
	// lwz r10,204(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8268675c
	if (ctx.cr6.eq) goto loc_8268675C;
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,204(r11)
	REX_STORE_U32(ctx.r11.u32 + 204, ctx.r9.u32);
	// beq cr6,0x82686738
	if (ctx.cr6.eq) goto loc_82686738;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,8(r9)
	REX_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// b 0x82686740
	goto loc_82686740;
loc_82686738:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,208(r11)
	REX_STORE_U32(ctx.r11.u32 + 208, ctx.r9.u32);
loc_82686740:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r9,212(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 212);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// stw r10,212(r11)
	REX_STORE_U32(ctx.r11.u32 + 212, ctx.r10.u32);
	// blr 
	return;
loc_8268675C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82688100) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,-30888
	ctx.r10.s64 = ctx.r11.s64 + -30888;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// addi r9,r4,16
	ctx.r9.s64 = ctx.r4.s64 + 16;
loc_82688124:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x82688144
	if (!ctx.cr0.eq) goto loc_82688144;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x82688124
	if (!ctx.cr6.eq) goto loc_82688124;
loc_82688144:
	// cmpwi r8,0
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x82688154
	if (!ctx.cr0.eq) goto loc_82688154;
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// b 0x82688190
	goto loc_82688190;
loc_82688154:
	// lis r10,-32241
	ctx.r10.s64 = -2112946176;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// addi r10,r10,-30904
	ctx.r10.s64 = ctx.r10.s64 + -30904;
	// addi r8,r4,16
	ctx.r8.s64 = ctx.r4.s64 + 16;
loc_82688164:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82688184
	if (!ctx.cr0.eq) goto loc_82688184;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82688164
	if (!ctx.cr6.eq) goto loc_82688164;
loc_82688184:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x826881b4
	if (!ctx.cr0.eq) goto loc_826881B4;
	// addi r11,r3,36
	ctx.r11.s64 = ctx.r3.s64 + 36;
loc_82688190:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8268819c
	if (!ctx.cr6.eq) goto loc_8268819C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8268819C:
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826881B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x826881bc
	goto loc_826881BC;
loc_826881B4:
	// bl 0x82665ea8
	ctx.lr = 0x826881B8;
	sub_82665EA8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_826881BC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8268C1D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// lis r10,4919
	ctx.r10.s64 = 322371584;
	// stw r6,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// addi r9,r1,164
	ctx.r9.s64 = ctx.r1.s64 + 164;
	// stw r7,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r7.u32);
	// ori r10,r10,61441
	ctx.r10.u64 = ctx.r10.u64 | 61441;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r1,156
	ctx.r7.s64 = ctx.r1.s64 + 156;
	// lwz r3,176(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8268C220;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8267b898
	ctx.lr = 0x8268C22C;
	sub_8267B898(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8268E900) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x8268E908;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lhz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x825c4490
	ctx.lr = 0x8268E91C;
	sub_825C4490(ctx, base);
	// lwz r26,0(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r30,4(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lhz r7,2(r28)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r28.u32 + 2);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r6,4(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8268dbf8
	ctx.lr = 0x8268E93C;
	sub_8268DBF8(ctx, base);
	// li r27,1
	ctx.r27.s64 = 1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x8268e964
	if (ctx.cr6.eq) goto loc_8268E964;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8268e964
	if (!ctx.cr6.eq) goto loc_8268E964;
	// lwz r5,20(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// b 0x8268e970
	goto loc_8268E970;
loc_8268E964:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
loc_8268E970:
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// beq cr6,0x8268e98c
	if (ctx.cr6.eq) goto loc_8268E98C;
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// bne cr6,0x8268e990
	if (!ctx.cr6.eq) goto loc_8268E990;
	// li r31,16
	ctx.r31.s64 = 16;
	// b 0x8268e990
	goto loc_8268E990;
loc_8268E98C:
	// li r31,8
	ctx.r31.s64 = 8;
loc_8268E990:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8268e9a4
	if (!ctx.cr6.eq) goto loc_8268E9A4;
loc_8268E998:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8268E9A4:
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8268e998
	if (ctx.cr6.eq) goto loc_8268E998;
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
loc_8268E9BC:
	// lwz r11,21(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 21);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rlwimi r10,r27,0,31,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD) | (ctx.r10.u64 & 0x2);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8268ea34
	if (ctx.cr6.eq) goto loc_8268EA34;
	// and r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 & ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8268ea34
	if (ctx.cr6.eq) goto loc_8268EA34;
	// lbz r11,20(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 20);
	// lhz r10,14(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 14);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8268ea34
	if (!ctx.cr6.eq) goto loc_8268EA34;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8268e9fc
	if (ctx.cr6.eq) goto loc_8268E9FC;
	// lwz r10,16(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// b 0x8268ea00
	goto loc_8268EA00;
loc_8268E9FC:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
loc_8268EA00:
	// subf r11,r10,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r10.u64;
	// srawi r29,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r11.s32 >> 31;
	// xor r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 ^ ctx.r29.u64;
	// subf. r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8268ea48
	if (ctx.cr0.eq) goto loc_8268EA48;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8268ea34
	if (!ctx.cr6.gt) goto loc_8268EA34;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8268ea2c
	if (ctx.cr6.eq) goto loc_8268EA2C;
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8268ea34
	if (ctx.cr6.gt) goto loc_8268EA34;
loc_8268EA2C:
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_8268EA34:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,25
	ctx.r9.s64 = ctx.r9.s64 + 25;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8268e9bc
	if (ctx.cr6.lt) goto loc_8268E9BC;
	// b 0x8268ea4c
	goto loc_8268EA4C;
loc_8268EA48:
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_8268EA4C:
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x8268e998
	if (ctx.cr6.eq) goto loc_8268E998;
	// mulli r11,r4,25
	ctx.r11.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(25));
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82695BB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lbz r9,1(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lfs f0,20388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20388);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// srawi r11,r3,12
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 12;
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82697D80) {
	REX_FUNC_PROLOGUE();
	// lwz r11,116(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82698258) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,120(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-26744
	ctx.r11.s64 = ctx.r11.s64 + -26744;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82698294
	if (ctx.cr6.eq) goto loc_82698294;
	// bl 0x826888c0
	ctx.lr = 0x82698290;
	sub_826888C0(ctx, base);
	// stw r30,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
loc_82698294:
	// lwz r3,124(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826982a8
	if (ctx.cr6.eq) goto loc_826982A8;
	// bl 0x826888c0
	ctx.lr = 0x826982A4;
	sub_826888C0(ctx, base);
	// stw r30,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
loc_826982A8:
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269e348
	ctx.lr = 0x826982B4;
	sub_8269E348(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8269A108) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x8269A110;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a130
	if (ctx.cr6.eq) goto loc_8269A130;
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8269a134
	goto loc_8269A134;
loc_8269A130:
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
loc_8269A134:
	// lwz r11,44(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r10,52(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 52);
	// lwz r9,252(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lhz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// divwu r4,r10,r11
	ctx.r4.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// beq cr6,0x8269a178
	if (ctx.cr6.eq) goto loc_8269A178;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8269A170;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8269A178:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a1a0
	if (ctx.cr6.eq) goto loc_8269A1A0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8269A19C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8269A1A0:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a1c4
	if (ctx.cr6.eq) goto loc_8269A1C4;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269a1c4
	if (!ctx.cr6.eq) goto loc_8269A1C4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82698e08
	ctx.lr = 0x8269A1C4;
	sub_82698E08(ctx, base);
loc_8269A1C4:
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8269A1DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8269a22c
	if (ctx.cr0.eq) goto loc_8269A22C;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8269a22c
	if (!ctx.cr6.eq) goto loc_8269A22C;
	// lwz r11,184(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8269a208
	if (!ctx.cr6.eq) goto loc_8269A208;
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a22c
	if (ctx.cr6.eq) goto loc_8269A22C;
loc_8269A208:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lhz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// mullw r4,r11,r30
	ctx.r4.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// bl 0x82699f18
	ctx.lr = 0x8269A21C;
	sub_82699F18(ctx, base);
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// b 0x8269a234
	goto loc_8269A234;
loc_8269A22C:
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// stw r27,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
loc_8269A234:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r28,r28,56
	ctx.r28.s64 = ctx.r28.s64 + 56;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a26c
	if (ctx.cr6.eq) goto loc_8269A26C;
	// lwz r10,252(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8269a26c
	if (ctx.cr6.eq) goto loc_8269A26C;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// lwz r10,544(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 544);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// b 0x8269a280
	goto loc_8269A280;
loc_8269A26C:
	// lwz r10,252(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8269a280
	if (!ctx.cr6.eq) goto loc_8269A280;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_8269A280:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a2b0
	if (ctx.cr6.eq) goto loc_8269A2B0;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r8,96(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8269A2B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8269A2B0:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a2e4
	if (ctx.cr6.eq) goto loc_8269A2E4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r8,260(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8269A2E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8269A2E4:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8269a304
	if (ctx.cr6.eq) goto loc_8269A304;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8269A304;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8269A304:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(__savevmx_82) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v82.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v83.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v84.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v85.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v86.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v87.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v88.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v89.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v90.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v91.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v92.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v93.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v94.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v95.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v96.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v97.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v98.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v99.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v100.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v101.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v102.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v103.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v104.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v105.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v106.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v107.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v108.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v109.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v110.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v111.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v112.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v113.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v114.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v115.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v116.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v117.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v118.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v119.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v120.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v121.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(__restvmx_120) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v120.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v121.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826A2520) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mr. r0,r5
	ctx.r0.u64 = ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// ble 0x826a2564
	if (!ctx.cr0.gt) goto loc_826A2564;
	// lbz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmpwi cr1,r8,0
	ctx.cr1.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// subfc. r3,r7,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r7.u32;
	ctx.r3.u64 = ctx.r8.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bdnzf 4*cr1+eq,0x826a2548
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr1.eq) goto loc_826A2548;
	// blr 
	return;
loc_826A2548:
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lbzu r8,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// cmpwi cr1,r8,0
	ctx.cr1.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// subfc. r3,r7,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r7.u32;
	ctx.r3.u64 = ctx.r8.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bdnzf 4*cr1+eq,0x826a2548
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr1.eq) goto loc_826A2548;
	// blr 
	return;
loc_826A2564:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826A39A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-112
	ctx.r31.s64 = ctx.r12.s64 + -112;
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,132(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// b 0x826a39e0
	goto loc_826A39E0;
loc_826A39E0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826a5630
	ctx.lr = 0x826A39E8;
	sub_826A5630(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826A45A8) {
	REX_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x826a44b0
	sub_826A44B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A4788) {
	REX_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x826a46d0
	sub_826A46D0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A5210) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x826A5218;
	__savegprlr_28(ctx, base);
	// std r5,32(r1)
	REX_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	REX_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	REX_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	REX_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	REX_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	REX_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// li r28,0
	ctx.r28.s64 = 0;
	// subfe. r11,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
	// bne 0x826a5280
	if (!ctx.cr0.eq) goto loc_826A5280;
loc_826A5254:
	// bl 0x826a9e30
	ctx.lr = 0x826A5258;
	sub_826A9E30(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x826a9cf0
	ctx.lr = 0x826A5278;
	sub_826A9CF0(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x826a53c0
	goto loc_826A53C0;
loc_826A5280:
	// addic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// subfe. r11,r11,r29
	temp.u8 = (~ctx.r11.u32 + ctx.r29.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826a5254
	if (ctx.cr0.eq) goto loc_826A5254;
	// addi r11,r31,84
	ctx.r11.s64 = ctx.r31.s64 + 84;
	// stw r30,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// addi r10,r31,176
	ctx.r10.s64 = ctx.r31.s64 + 176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bl 0x826a5570
	ctx.lr = 0x826A52A4;
	sub_826A5570(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x826a5378
	if (!ctx.cr0.eq) goto loc_826A5378;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826ab1a8
	ctx.lr = 0x826A52BC;
	sub_826AB1A8(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x826a52f8
	if (ctx.cr6.eq) goto loc_826A52F8;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x826a52f8
	if (ctx.cr6.eq) goto loc_826A52F8;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// lis r11,-32048
	ctx.r11.s64 = -2100297728;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,17600
	ctx.r11.s64 = ctx.r11.s64 + 17600;
	// clrlwi r10,r3,27
	ctx.r10.u64 = ctx.r3.u32 & 0x1F;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// mulli r10,r10,72
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(72));
	// lwzx r9,r9,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r8,-4592
	ctx.r10.s64 = ctx.r8.s64 + -4592;
	// b 0x826a530c
	goto loc_826A530C;
loc_826A52F8:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r11,-32048
	ctx.r11.s64 = -2100297728;
	// addi r10,r10,-4592
	ctx.r10.s64 = ctx.r10.s64 + -4592;
	// addi r11,r11,17600
	ctx.r11.s64 = ctx.r11.s64 + 17600;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_826A530C:
	// lbz r9,40(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 40);
	// rlwinm. r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x826a534c
	if (!ctx.cr0.eq) goto loc_826A534C;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x826a5340
	if (ctx.cr6.eq) goto loc_826A5340;
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// beq cr6,0x826a5340
	if (ctx.cr6.eq) goto loc_826A5340;
	// srawi r10,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 5;
	// clrlwi r9,r3,27
	ctx.r9.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r9,72
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(72));
	// lwzx r11,r8,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_826A5340:
	// lbz r11,40(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 40);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826a5378
	if (ctx.cr0.eq) goto loc_826A5378;
loc_826A534C:
	// bl 0x826a9e30
	ctx.lr = 0x826A5350;
	sub_826A9E30(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x826a9cf0
	ctx.lr = 0x826A5370;
	sub_826A9CF0(ctx, base);
	// li r28,-1
	ctx.r28.s64 = -1;
	// stw r28,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
loc_826A5378:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x826a53b0
	if (!ctx.cr6.eq) goto loc_826A53B0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826af268
	ctx.lr = 0x826A5388;
	sub_826AF268(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,84(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826aa0e8
	ctx.lr = 0x826A53A0;
	sub_826AA0E8(ctx, base);
	// stw r3,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x826af340
	ctx.lr = 0x826A53B0;
	sub_826AF340(ctx, base);
loc_826A53B0:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	ctx.r12.s64 = ctx.r31.s64 + 144;
	// bl 0x826a53c8
	ctx.lr = 0x826A53BC;
	sub_826A53C8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
loc_826A53C0:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826B1F08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r4,-8
	ctx.r4.s64 = -524288;
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r4,r4,1792
	ctx.r4.u64 = ctx.r4.u64 | 1792;
	// bl 0x826a9b60
	ctx.lr = 0x826B1F24;
	sub_826A9B60(ctx, base);
	// bl 0x826b1e88
	ctx.lr = 0x826B1F28;
	sub_826B1E88(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826B30C0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x826b2f28
	sub_826B2F28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826B44FC) {
	REX_FUNC_PROLOGUE();
	// lfd f14,408(r4)
	ctx.fpscr.disableFlushMode();
	ctx.f14.u64 = REX_LOAD_U64(ctx.r4.u32 + 408);
	// lfd f15,416(r4)
	ctx.f15.u64 = REX_LOAD_U64(ctx.r4.u32 + 416);
	// lfd f16,424(r4)
	ctx.f16.u64 = REX_LOAD_U64(ctx.r4.u32 + 424);
	// lfd f17,432(r4)
	ctx.f17.u64 = REX_LOAD_U64(ctx.r4.u32 + 432);
	// lfd f18,440(r4)
	ctx.f18.u64 = REX_LOAD_U64(ctx.r4.u32 + 440);
	// lfd f19,448(r4)
	ctx.f19.u64 = REX_LOAD_U64(ctx.r4.u32 + 448);
	// lfd f20,456(r4)
	ctx.f20.u64 = REX_LOAD_U64(ctx.r4.u32 + 456);
	// lfd f21,464(r4)
	ctx.f21.u64 = REX_LOAD_U64(ctx.r4.u32 + 464);
	// lfd f22,472(r4)
	ctx.f22.u64 = REX_LOAD_U64(ctx.r4.u32 + 472);
	// lfd f23,480(r4)
	ctx.f23.u64 = REX_LOAD_U64(ctx.r4.u32 + 480);
	// lfd f24,488(r4)
	ctx.f24.u64 = REX_LOAD_U64(ctx.r4.u32 + 488);
	// lfd f25,496(r4)
	ctx.f25.u64 = REX_LOAD_U64(ctx.r4.u32 + 496);
	// lfd f26,504(r4)
	ctx.f26.u64 = REX_LOAD_U64(ctx.r4.u32 + 504);
	// lfd f27,512(r4)
	ctx.f27.u64 = REX_LOAD_U64(ctx.r4.u32 + 512);
	// lfd f28,520(r4)
	ctx.f28.u64 = REX_LOAD_U64(ctx.r4.u32 + 520);
	// lfd f29,528(r4)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r4.u32 + 528);
	// lfd f30,536(r4)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r4.u32 + 536);
	// lfd f31,544(r4)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r4.u32 + 544);
	// ld r14,136(r4)
	ctx.r14.u64 = REX_LOAD_U64(ctx.r4.u32 + 136);
	// ld r15,144(r4)
	ctx.r15.u64 = REX_LOAD_U64(ctx.r4.u32 + 144);
	// ld r16,152(r4)
	ctx.r16.u64 = REX_LOAD_U64(ctx.r4.u32 + 152);
	// ld r17,160(r4)
	ctx.r17.u64 = REX_LOAD_U64(ctx.r4.u32 + 160);
	// ld r18,168(r4)
	ctx.r18.u64 = REX_LOAD_U64(ctx.r4.u32 + 168);
	// ld r19,176(r4)
	ctx.r19.u64 = REX_LOAD_U64(ctx.r4.u32 + 176);
	// ld r20,184(r4)
	ctx.r20.u64 = REX_LOAD_U64(ctx.r4.u32 + 184);
	// ld r21,192(r4)
	ctx.r21.u64 = REX_LOAD_U64(ctx.r4.u32 + 192);
	// ld r22,200(r4)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r4.u32 + 200);
	// ld r23,208(r4)
	ctx.r23.u64 = REX_LOAD_U64(ctx.r4.u32 + 208);
	// ld r24,216(r4)
	ctx.r24.u64 = REX_LOAD_U64(ctx.r4.u32 + 216);
	// ld r25,224(r4)
	ctx.r25.u64 = REX_LOAD_U64(ctx.r4.u32 + 224);
	// ld r26,232(r4)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r4.u32 + 232);
	// ld r27,240(r4)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r4.u32 + 240);
	// ld r28,248(r4)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r4.u32 + 248);
	// ld r29,256(r4)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r4.u32 + 256);
	// ld r30,264(r4)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r4.u32 + 264);
	// ld r31,272(r4)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r4.u32 + 272);
	// lfd f0,288(r4)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r4.u32 + 288);
	// lwz r5,280(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 280);
	// lwz r6,284(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 284);
	// ld r7,16(r4)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r4.u32 + 16);
	// mtfsf 255,f0
	ctx.fpscr.storeFromGuest(ctx.f0.u32);
	// mtlr r3
	ctx.lr = ctx.r3.u64;
	// mtcr r5
	ctx.cr0.lt = (ctx.r5.u32 & 0x80000000) != 0;
	ctx.cr0.gt = (ctx.r5.u32 & 0x40000000) != 0;
	ctx.cr0.eq = (ctx.r5.u32 & 0x20000000) != 0;
	ctx.cr0.so = (ctx.r5.u32 & 0x10000000) != 0;
	ctx.cr1.lt = (ctx.r5.u32 & 0x8000000) != 0;
	ctx.cr1.gt = (ctx.r5.u32 & 0x4000000) != 0;
	ctx.cr1.eq = (ctx.r5.u32 & 0x2000000) != 0;
	ctx.cr1.so = (ctx.r5.u32 & 0x1000000) != 0;
	ctx.cr2.lt = (ctx.r5.u32 & 0x800000) != 0;
	ctx.cr2.gt = (ctx.r5.u32 & 0x400000) != 0;
	ctx.cr2.eq = (ctx.r5.u32 & 0x200000) != 0;
	ctx.cr2.so = (ctx.r5.u32 & 0x100000) != 0;
	ctx.cr3.lt = (ctx.r5.u32 & 0x80000) != 0;
	ctx.cr3.gt = (ctx.r5.u32 & 0x40000) != 0;
	ctx.cr3.eq = (ctx.r5.u32 & 0x20000) != 0;
	ctx.cr3.so = (ctx.r5.u32 & 0x10000) != 0;
	ctx.cr4.lt = (ctx.r5.u32 & 0x8000) != 0;
	ctx.cr4.gt = (ctx.r5.u32 & 0x4000) != 0;
	ctx.cr4.eq = (ctx.r5.u32 & 0x2000) != 0;
	ctx.cr4.so = (ctx.r5.u32 & 0x1000) != 0;
	ctx.cr5.lt = (ctx.r5.u32 & 0x800) != 0;
	ctx.cr5.gt = (ctx.r5.u32 & 0x400) != 0;
	ctx.cr5.eq = (ctx.r5.u32 & 0x200) != 0;
	ctx.cr5.so = (ctx.r5.u32 & 0x100) != 0;
	ctx.cr6.lt = (ctx.r5.u32 & 0x80) != 0;
	ctx.cr6.gt = (ctx.r5.u32 & 0x40) != 0;
	ctx.cr6.eq = (ctx.r5.u32 & 0x20) != 0;
	ctx.cr6.so = (ctx.r5.u32 & 0x10) != 0;
	ctx.cr7.lt = (ctx.r5.u32 & 0x8) != 0;
	ctx.cr7.gt = (ctx.r5.u32 & 0x4) != 0;
	ctx.cr7.eq = (ctx.r5.u32 & 0x2) != 0;
	ctx.cr7.so = (ctx.r5.u32 & 0x1) != 0;
	// mtxer r6
	ctx.xer.so = (ctx.r6.u64 & 0x80000000) != 0;
	ctx.xer.ov = (ctx.r6.u64 & 0x40000000) != 0;
	ctx.xer.ca = (ctx.r6.u64 & 0x20000000) != 0;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// ld r2,40(r4)
	ctx.r2.u64 = REX_LOAD_U64(ctx.r4.u32 + 40);
	// ld r1,32(r4)
	ctx.r1.u64 = REX_LOAD_U64(ctx.r4.u32 + 32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826BC0E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x826BC0F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x826bc114
	if (!ctx.cr6.eq) goto loc_826BC114;
	// lis r3,-30602
	ctx.r3.s64 = -2005532672;
	// ori r3,r3,2156
	ctx.r3.u64 = ctx.r3.u64 | 2156;
	// b 0x826bc1f4
	goto loc_826BC1F4;
loc_826BC114:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,4138
	ctx.r10.s64 = 271187968;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,4352
	ctx.r10.u64 = ctx.r10.u64 | 4352;
	// rlwinm r11,r11,0,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF00;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x826bc1fc
	if (!ctx.cr6.eq) goto loc_826BC1FC;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826bc224
	if (ctx.cr6.eq) goto loc_826BC224;
	// add r10,r11,r3
	ctx.r10.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// li r29,1
	ctx.r29.s64 = 1;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwzx r11,r11,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_826BC160:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x826bbbf8
	ctx.lr = 0x826BC174;
	sub_826BBBF8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x826bc1f4
	if (ctx.cr0.lt) goto loc_826BC1F4;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x826bc1f0
	if (ctx.cr6.eq) goto loc_826BC1F0;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,24(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ble cr6,0x826bc1dc
	if (!ctx.cr6.gt) goto loc_826BC1DC;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826BC1B0:
	// lhz r10,-4(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + -4);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x826bc1d4
	if (!ctx.cr6.eq) goto loc_826BC1D4;
	// lhz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r7,-2(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + -2);
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x826bc1d4
	if (!ctx.cr6.lt) goto loc_826BC1D4;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_826BC1D4:
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// bdnz 0x826bc1b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826BC1B0;
loc_826BC1DC:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rlwinm r3,r9,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x826b73f8
	ctx.lr = 0x826BC1E8;
	sub_826B73F8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x826bc1f4
	if (ctx.cr0.lt) goto loc_826BC1F4;
loc_826BC1F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BC1F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_826BC1FC:
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// lis r4,16961
	ctx.r4.s64 = 1111556096;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// ori r4,r4,21571
	ctx.r4.u64 = ctx.r4.u64 | 21571;
	// bl 0x826b7400
	ctx.lr = 0x826BC214;
	sub_826B7400(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x826bc1f4
	if (ctx.cr0.lt) goto loc_826BC1F4;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x826bc160
	if (!ctx.cr6.eq) goto loc_826BC160;
loc_826BC224:
	// lis r3,-30602
	ctx.r3.s64 = -2005532672;
	// ori r3,r3,2905
	ctx.r3.u64 = ctx.r3.u64 | 2905;
	// b 0x826bc1f4
	goto loc_826BC1F4;
}

DEFINE_REX_FUNC(sub_826C1860) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x826C1868;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826c18a4
	if (!ctx.cr6.eq) goto loc_826C18A4;
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// lis r10,-32238
	ctx.r10.s64 = -2112749568;
	// lis r9,-32238
	ctx.r9.s64 = -2112749568;
	// addi r6,r11,2216
	ctx.r6.s64 = ctx.r11.s64 + 2216;
	// addi r5,r10,-18440
	ctx.r5.s64 = ctx.r10.s64 + -18440;
	// addi r4,r9,-18528
	ctx.r4.s64 = ctx.r9.s64 + -18528;
	// li r7,4163
	ctx.r7.s64 = 4163;
	// bl 0x826bd5c0
	ctx.lr = 0x826C18A4;
	sub_826BD5C0(ctx, base);
loc_826C18A4:
	// li r4,166
	ctx.r4.s64 = 166;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826bde60
	ctx.lr = 0x826C18B0;
	sub_826BDE60(ctx, base);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x826c18f4
	if (ctx.cr6.eq) goto loc_826C18F4;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x826c18f4
	if (ctx.cr6.eq) goto loc_826C18F4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x826be250
	ctx.lr = 0x826C18CC;
	sub_826BE250(ctx, base);
	// lis r11,-32126
	ctx.r11.s64 = -2105409536;
	// lis r10,-32238
	ctx.r10.s64 = -2112749568;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// addi r11,r11,-3112
	ctx.r11.s64 = ctx.r11.s64 + -3112;
	// addi r4,r10,2332
	ctx.r4.s64 = ctx.r10.s64 + 2332;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,24
	ctx.r6.s64 = 24;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,96(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// bctrl 
	ctx.lr = 0x826C18F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826C18F4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C57C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x826C57C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x826c4fb0
	ctx.lr = 0x826C57DC;
	sub_826C4FB0(ctx, base);
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r11,r11,16388
	ctx.r11.s64 = ctx.r11.s64 + 16388;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r3,2736(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2736);
	// bl 0x826c4678
	ctx.lr = 0x826C57F4;
	sub_826C4678(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stb r11,29(r31)
	REX_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// stb r11,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C6CF8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// addi r3,r11,19128
	ctx.r3.s64 = ctx.r11.s64 + 19128;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826C6DF8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// addi r3,r11,19704
	ctx.r3.s64 = ctx.r11.s64 + 19704;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826C70C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x826c69c8
	ctx.lr = 0x826C70E0;
	sub_826C69C8(ctx, base);
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r11,20408
	ctx.r11.s64 = ctx.r11.s64 + 20408;
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r10,168(r3)
	REX_STORE_U32(ctx.r3.u32 + 168, ctx.r10.u32);
	// lwz r11,228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 228);
	// ori r11,r11,24
	ctx.r11.u64 = ctx.r11.u64 | 24;
	// stw r11,228(r3)
	REX_STORE_U32(ctx.r3.u32 + 228, ctx.r11.u32);
	// lwz r3,2736(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2736);
	// bl 0x826c2718
	ctx.lr = 0x826C711C;
	sub_826C2718(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826C8980) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32147
	ctx.r11.s64 = -2106785792;
	// addi r3,r11,-17528
	ctx.r3.s64 = ctx.r11.s64 + -17528;
	// b 0x826a2360
	sub_826A2360(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C8E18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// addi r3,r11,23792
	ctx.r3.s64 = ctx.r11.s64 + 23792;
	// bl 0x823b9a08
	ctx.lr = 0x826C8E30;
	sub_823B9A08(ctx, base);
	// lis r10,-32147
	ctx.r10.s64 = -2106785792;
	// addi r3,r10,-17104
	ctx.r3.s64 = ctx.r10.s64 + -17104;
	// bl 0x826a2360
	ctx.lr = 0x826C8E3C;
	sub_826A2360(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826CAC28) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32147
	ctx.r11.s64 = -2106785792;
	// addi r3,r11,-15520
	ctx.r3.s64 = ctx.r11.s64 + -15520;
	// b 0x826a2360
	sub_826A2360(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826CAE90) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32147
	ctx.r11.s64 = -2106785792;
	// addi r3,r11,-14720
	ctx.r3.s64 = ctx.r11.s64 + -14720;
	// b 0x826a2360
	sub_826A2360(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826CB728) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32127
	ctx.r11.s64 = -2105475072;
	// li r5,502
	ctx.r5.s64 = 502;
	// addi r31,r11,-14336
	ctx.r31.s64 = ctx.r11.s64 + -14336;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,26
	ctx.r3.s64 = ctx.r31.s64 + 26;
	// bl 0x826a03b0
	ctx.lr = 0x826CB750;
	rexcrt_memset(ctx, base);
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,13624
	ctx.r4.s64 = ctx.r11.s64 + 13624;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x826a1130
	ctx.lr = 0x826CB764;
	rexcrt_memcpy(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x826a03b0
	ctx.lr = 0x826CB774;
	rexcrt_memset(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,1040(r31)
	REX_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,1044(r31)
	REX_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// stw r11,1052(r31)
	REX_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	REX_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	REX_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826E7B00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x826E7B08;
	__savegprlr_14(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,616(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 616);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lhz r10,52(r4)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + 52);
	// lhz r9,50(r4)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r4.u32 + 50);
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r5,1312(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 1312);
	// rlwinm r4,r10,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r14,r9,31,1,31
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r8,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, ctx.r8.u32);
	// stw r11,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// lwz r10,428(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 428);
	// mullw r11,r4,r14
	ctx.r11.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r14.s32);
	// stw r10,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r10.u32);
	// lwz r9,1164(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 1164);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r9.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lhz r4,74(r29)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r29.u32 + 74);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lhz r31,76(r29)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r29.u32 + 76);
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// stw r14,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r14.u32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r31,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stw r4,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// bne cr6,0x826e7bc4
	if (!ctx.cr6.eq) goto loc_826E7BC4;
	// lwz r9,1368(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 1368);
	// lwz r10,22488(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 22488);
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r22,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r22.u32);
	// stw r22,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r22.u32);
	// rlwinm r9,r6,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r10.u32);
	// lwz r9,1368(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 1368);
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,22500(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 22500);
	// stw r22,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r22.u32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r22,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// sth r22,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r22.u16);
	// stw r3,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// b 0x826e7c34
	goto loc_826E7C34;
loc_826E7BC4:
	// addi r11,r6,92
	ctx.r11.s64 = ctx.r6.s64 + 92;
	// mullw r10,r14,r7
	ctx.r10.s64 = int64_t(ctx.r14.s32) * int64_t(ctx.r7.s32);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r4,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r29
	ctx.r6.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r27,r31,3,0,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r14,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r26,r11,r29
	ctx.r26.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// stw r26,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r26.u32);
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// rlwinm r11,r7,1,16,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFE;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// mullw r5,r3,r7
	ctx.r5.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// mullw r3,r27,r7
	ctx.r3.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r7.s32);
	// lwz r5,4(r6)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r5,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r5.u32);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,8(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r3,28(r30)
	REX_STORE_U32(ctx.r30.u32 + 28, ctx.r3.u32);
	// lwz r6,12(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// stw r6,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r6.u32);
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r10,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// sth r11,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r11.u16);
loc_826E7C34:
	// sth r22,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r22.u16);
	// cmplw cr6,r7,r28
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r28.u32, ctx.xer);
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bge cr6,0x826e8054
	if (!ctx.cr6.lt) goto loc_826E8054;
	// li r15,16
	ctx.r15.s64 = 16;
	// li r16,32
	ctx.r16.s64 = 32;
	// li r17,48
	ctx.r17.s64 = 48;
	// li r18,64
	ctx.r18.s64 = 64;
	// li r19,80
	ctx.r19.s64 = 80;
	// li r20,96
	ctx.r20.s64 = 96;
	// li r21,112
	ctx.r21.s64 = 112;
loc_826E7C60:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r22,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r22.u32);
	// sth r22,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r22.u16);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r10,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r10.u32);
	// beq cr6,0x826e7ff8
	if (ctx.cr6.eq) goto loc_826E7FF8;
loc_826E7C80:
	// ld r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r5.u32 + 0);
	// addi r11,r5,8
	ctx.r11.s64 = ctx.r5.s64 + 8;
	// rldicl r9,r10,16,48
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 16) & 0xFFFF;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// clrlwi r11,r9,26
	ctx.r11.u64 = ctx.r9.u32 & 0x3F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826e7f98
	if (ctx.cr6.eq) goto loc_826E7F98;
	// rldicl r8,r10,8,56
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFF;
	// lwz r9,388(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 388);
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// clrlwi r11,r8,26
	ctx.r11.u64 = ctx.r8.u32 & 0x3F;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r7,-32049
	ctx.r7.s64 = -2100363264;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,-24400(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + -24400);
	// add r28,r9,r11
	ctx.r28.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmplwi cr6,r8,9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 9, ctx.xer);
	// bgt cr6,0x826e7d94
	if (ctx.cr6.gt) goto loc_826E7D94;
	// lis r12,-32146
	ctx.r12.s64 = -2106720256;
	// rlwinm r0,r8,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,31976
	ctx.r12.s64 = ctx.r12.s64 + 31976;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r8.u32) {
	case 0:
		goto loc_826E7D10;
	case 1:
		goto loc_826E7D20;
	case 2:
		goto loc_826E7D2C;
	case 3:
		goto loc_826E7D34;
	case 4:
		goto loc_826E7D94;
	case 5:
		goto loc_826E7D94;
	case 6:
		goto loc_826E7D94;
	case 7:
		goto loc_826E7D94;
	case 8:
		goto loc_826E7D10;
	case 9:
		goto loc_826E7D20;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_826E7D10:
	// lwz r10,560(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 560);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x826e7d40
	goto loc_826E7D40;
loc_826E7D20:
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,568(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 568);
	// b 0x826e7d3c
	goto loc_826E7D3C;
loc_826E7D2C:
	// lwz r11,576(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 576);
	// b 0x826e7d38
	goto loc_826E7D38;
loc_826E7D34:
	// lwz r11,580(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 580);
loc_826E7D38:
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
loc_826E7D3C:
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_826E7D40:
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// dcbt r0,r10
	// lhz r11,90(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 90);
	// dcbt r11,r10
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// dcbt r9,r10
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// dcbt r6,r10
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// dcbt r5,r10
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// dcbt r4,r10
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r9,r10
	// rotlwi r6,r11,3
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 3);
	// subf r5,r11,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r11.u64;
	// dcbt r5,r10
loc_826E7D94:
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// srawi r10,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 4;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// stw r11,-24400(r7)
	REX_STORE_U32(ctx.r7.u32 + -24400, ctx.r11.u32);
loc_826E7DB0:
	// srawi r26,r27,2
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3) != 0);
	ctx.r26.s64 = ctx.r27.s32 >> 2;
	// addi r11,r27,140
	ctx.r11.s64 = ctx.r27.s64 + 140;
	// addi r10,r26,2
	ctx.r10.s64 = ctx.r26.s64 + 2;
	// rldicl r9,r25,20,44
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u64, 20) & 0xFFFFF;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r9,28
	ctx.r11.u64 = ctx.r9.u32 & 0xF;
	// clrlwi r8,r23,31
	ctx.r8.u64 = ctx.r23.u32 & 0x1;
	// rlwinm r5,r11,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// lwzx r10,r7,r29
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r29.u32);
	// lwzx r9,r6,r30
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r30.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// add r24,r10,r9
	ctx.r24.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bne cr6,0x826e7f84
	if (!ctx.cr6.eq) goto loc_826E7F84;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x826e7f84
	if (ctx.cr6.eq) goto loc_826E7F84;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826e7f28
	if (!ctx.cr6.eq) goto loc_826E7F28;
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// addi r5,r29,168
	ctx.r5.s64 = ctx.r29.s64 + 168;
	// lwz r4,444(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 444);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,4(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// lwz r31,40(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r3,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// dcbzl r0,r31
	ea = (ctx.r31.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x826e7e4c
	if (ctx.cr6.lt) goto loc_826E7E4C;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82604718
	ctx.lr = 0x826E7E44;
	sub_82604718(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x826e7eac
	goto loc_826E7EAC;
loc_826E7E4C:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x826e7ea8
	if (!ctx.cr6.gt) goto loc_826E7EA8;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826E7E58:
	// lhz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r15,r3,24,8,31
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r15,r7
	ctx.r8.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r7.s32);
	// lbzx r15,r10,r4
	ctx.r15.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r14,r15,r5
	ctx.r14.u64 = REX_LOAD_U8(ctx.r15.u32 + ctx.r5.u32);
	// rlwinm r3,r3,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r3,r3
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// rotlwi r15,r15,1
	ctx.r15.u64 = __builtin_rotateleft32(ctx.r15.u32, 1);
	// xor r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// or r9,r14,r9
	ctx.r9.u64 = ctx.r14.u64 | ctx.r9.u64;
	// subf r3,r3,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r3.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r3,r15,r31
	REX_STORE_U16(ctx.r15.u32 + ctx.r31.u32, ctx.r3.u16);
	// bdnz 0x826e7e58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E7E58;
	// lwz r14,100(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r15,16
	ctx.r15.s64 = 16;
loc_826E7EA8:
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
loc_826E7EAC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826e7f18
	if (!ctx.cr6.eq) goto loc_826E7F18;
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// srawi r10,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r6,r11,16
	ctx.r6.s64 = ctx.r11.s64 + 16;
	// srawi r5,r6,5
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 5;
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// stw r4,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsplth v0,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r15
	ea = (ctx.r31.u32 + ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r16
	ea = (ctx.r31.u32 + ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r17
	ea = (ctx.r31.u32 + ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r18
	ea = (ctx.r31.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r19
	ea = (ctx.r31.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r20
	ea = (ctx.r31.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r21
	ea = (ctx.r31.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826e7f6c
	goto loc_826E7F6C;
loc_826E7F18:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e8060
	ctx.lr = 0x826E7F24;
	sub_826E8060(ctx, base);
	// b 0x826e7f6c
	goto loc_826E7F6C;
loc_826E7F28:
	// rldicl r10,r25,24,40
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u64, 24) & 0xFFFFFF;
	// lwz r7,36(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// rlwinm r11,r11,0,29,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x6;
	// clrlwi r5,r10,28
	ctx.r5.u64 = ctx.r10.u32 & 0xF;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// add r9,r5,r29
	ctx.r9.u64 = ctx.r5.u64 + ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// lbz r10,320(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 320);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r8,r11,159
	ctx.r8.s64 = ctx.r11.s64 + 159;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826E7F6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826E7F6C:
	// addi r11,r26,45
	ctx.r11.s64 = ctx.r26.s64 + 45;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lhzx r5,r10,r29
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r29.u32);
	// bl 0x826f4d00
	ctx.lr = 0x826E7F84;
	sub_826F4D00(ctx, base);
loc_826E7F84:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// rlwinm r23,r23,31,1,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 31) & 0x7FFFFFFF;
	// rldicr r25,r25,8,55
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmpwi cr6,r27,6
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 6, ctx.xer);
	// blt cr6,0x826e7db0
	if (ctx.cr6.lt) goto loc_826E7DB0;
loc_826E7F98:
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// lhz r8,18(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 18);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// cmplw cr6,r10,r14
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r14.u32, ctx.xer);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r6,r8,2
	ctx.r6.s64 = ctx.r8.s64 + 2;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// stw r5,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r5.u32);
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r7,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r7.u32);
	// stw r4,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r4.u32);
	// stw r3,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// sth r6,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r6.u16);
	// blt cr6,0x826e7c80
	if (ctx.cr6.lt) goto loc_826E7C80;
	// lwz r28,348(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r31,108(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
loc_826E7FF8:
	// lwz r7,84(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r8,16(r30)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r30.u32 + 16);
	// rlwinm r9,r4,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r6,88(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// sth r8,16(r30)
	REX_STORE_U16(ctx.r30.u32 + 16, ctx.r8.u16);
	// lhz r11,50(r29)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + 50);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// add r3,r9,r6
	ctx.r3.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stw r7,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// cmplw cr6,r7,r28
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r28.u32, ctx.xer);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// blt cr6,0x826e7c60
	if (ctx.cr6.lt) goto loc_826E7C60;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_826E8054:
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82702518) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x82702520;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// lwz r11,24(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// subfic r27,r5,2
	ctx.xer.ca = ctx.r5.u32 <= 2;
	ctx.r27.u64 = static_cast<uint64_t>(2) - ctx.r5.u64;
	// lwz r4,620(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 620);
	// addi r5,r3,232
	ctx.r5.s64 = ctx.r3.s64 + 232;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r30,4(r8)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r31,40(r6)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 20);
	// stw r26,24(r6)
	REX_STORE_U32(ctx.r6.u32 + 24, ctx.r26.u32);
	// dcbzl r0,r31
	ea = (ctx.r31.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r29,128
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 128, ctx.xer);
	// blt cr6,0x82702584
	if (ctx.cr6.lt) goto loc_82702584;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// bl 0x82604718
	ctx.lr = 0x8270257C;
	sub_82604718(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x827025dc
	goto loc_827025DC;
loc_82702584:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x827025d8
	if (!ctx.cr6.gt) goto loc_827025D8;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_82702590:
	// lhz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r29,r3,24,8,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r29,r7
	ctx.r8.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r7.s32);
	// lbzx r29,r10,r4
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r26,r29,r5
	ctx.r26.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r5.u32);
	// rlwinm r3,r3,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// neg r3,r3
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// rotlwi r29,r29,1
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r29.u32, 1);
	// xor r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// or r9,r26,r9
	ctx.r9.u64 = ctx.r26.u64 | ctx.r9.u64;
	// subf r3,r3,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r3.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r3,r29,r31
	REX_STORE_U16(ctx.r29.u32 + ctx.r31.u32, ctx.r3.u16);
	// bdnz 0x82702590
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82702590;
loc_827025D8:
	// stw r11,20(r6)
	REX_STORE_U32(ctx.r6.u32 + 20, ctx.r11.u32);
loc_827025DC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r11,r27,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 6) & 0xFFFFFFC0;
	// bne cr6,0x82702648
	if (!ctx.cr6.eq) goto loc_82702648;
	// lhz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// li r5,32
	ctx.r5.s64 = 32;
	// srawi r9,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 1;
	// li r4,48
	ctx.r4.s64 = 48;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// srawi r10,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 3;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsplth v13,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_82702648:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x826e86c8
	ctx.lr = 0x82702654;
	sub_826E86C8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8270AE50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x8270AE58;
	__savegprlr_28(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,15952
	ctx.r30.s64 = ctx.r3.s64 + 15952;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x826d2d88
	ctx.lr = 0x8270AE6C;
	sub_826D2D88(ctx, base);
	// lis r11,-32048
	ctx.r11.s64 = -2100297728;
	// addi r28,r31,22640
	ctx.r28.s64 = ctx.r31.s64 + 22640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,16168(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16168);
	// bl 0x8270b528
	ctx.lr = 0x8270AE80;
	sub_8270B528(ctx, base);
	// addi r29,r30,1408
	ctx.r29.s64 = ctx.r30.s64 + 1408;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826d8458
	ctx.lr = 0x8270AE94;
	sub_826D8458(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270af88
	if (!ctx.cr6.eq) goto loc_8270AF88;
	// lhz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 52);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82704348
	ctx.lr = 0x8270AEBC;
	sub_82704348(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270af88
	if (!ctx.cr6.eq) goto loc_8270AF88;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8270fb08
	ctx.lr = 0x8270AED4;
	sub_8270FB08(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270af88
	if (!ctx.cr6.eq) goto loc_8270AF88;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e75b0
	ctx.lr = 0x8270AEEC;
	sub_826E75B0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270af88
	if (!ctx.cr6.eq) goto loc_8270AF88;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8270af64
	if (ctx.cr6.eq) goto loc_8270AF64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,268(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// bl 0x8270c288
	ctx.lr = 0x8270AF0C;
	sub_8270C288(ctx, base);
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r9,3752(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r8,3748(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r9,220(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bl 0x8270c3a8
	ctx.lr = 0x8270AF38;
	sub_8270C3A8(ctx, base);
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r9,3752(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r8,3748(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r9,220(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bl 0x8270c3a8
	ctx.lr = 0x8270AF64;
	sub_8270C3A8(ctx, base);
loc_8270AF64:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8270b870
	ctx.lr = 0x8270AF70;
	sub_8270B870(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,15592(r31)
	REX_STORE_U32(ctx.r31.u32 + 15592, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r10.u32);
	// stw r11,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r11.u32);
loc_8270AF88:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

