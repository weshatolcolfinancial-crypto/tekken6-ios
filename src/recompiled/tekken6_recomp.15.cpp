#include "tekken6_funcs.15.h"

DEFINE_REX_FUNC(sub_82170AD0) {
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r3,76
	ctx.r11.s64 = ctx.r3.s64 + 76;
	// lfs f0,2880(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,0(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,56(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,60(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f0,80(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,76(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f0,92(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 84, temp.u32);
loc_82170B58:
	// stfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// stfs f0,36(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// stfs f0,28(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// stfs f0,24(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfsu f0,20(r11)
	ea = 20 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82170b58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82170B58;
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// stfs f0,384(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 384, temp.u32);
	// li r5,816
	ctx.r5.s64 = 816;
	// stfs f0,380(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f0,376(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 376, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,404(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 404, temp.u32);
	// addi r10,r31,520
	ctx.r10.s64 = ctx.r31.s64 + 520;
	// stfs f0,400(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// stfs f0,420(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 420, temp.u32);
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// stfs f0,412(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// stfs f0,408(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 408, temp.u32);
	// stfs f0,436(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 436, temp.u32);
	// stfs f0,432(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 432, temp.u32);
	// stfs f0,428(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 428, temp.u32);
	// stfs f0,424(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 424, temp.u32);
	// stfs f0,452(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 452, temp.u32);
	// stfs f0,448(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 448, temp.u32);
	// stfs f0,444(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 444, temp.u32);
	// stfs f0,440(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 440, temp.u32);
	// stfs f0,468(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 468, temp.u32);
	// stfs f0,464(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 464, temp.u32);
	// stfs f0,460(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 460, temp.u32);
	// stfs f0,456(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 456, temp.u32);
	// stfs f0,484(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 484, temp.u32);
	// stfs f0,480(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 480, temp.u32);
	// stfs f0,476(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 476, temp.u32);
	// stfs f0,472(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 472, temp.u32);
	// stfs f0,500(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 500, temp.u32);
	// stfs f0,496(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 496, temp.u32);
	// stfs f0,492(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 492, temp.u32);
	// stfs f0,488(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 488, temp.u32);
	// stfs f0,504(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 504, temp.u32);
	// stfs f0,516(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 516, temp.u32);
	// stfs f0,512(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 512, temp.u32);
	// stfs f0,508(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 508, temp.u32);
	// stw r11,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r11.u32);
	// stw r11,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r11.u32);
	// stfs f0,528(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 528, temp.u32);
	// stfs f0,552(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 552, temp.u32);
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// stfs f0,556(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 556, temp.u32);
	// stfs f0,536(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 536, temp.u32);
	// stfs f0,532(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 532, temp.u32);
	// stfs f0,548(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 548, temp.u32);
	// stfs f0,544(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 544, temp.u32);
	// stfs f0,540(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 540, temp.u32);
	// stw r11,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r11.u32);
	// stw r11,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r11.u32);
	// stw r11,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r11.u32);
	// stw r11,576(r31)
	REX_STORE_U32(ctx.r31.u32 + 576, ctx.r11.u32);
	// stw r11,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r11.u32);
	// stw r11,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r11.u32);
	// stw r11,588(r31)
	REX_STORE_U32(ctx.r31.u32 + 588, ctx.r11.u32);
	// stfs f0,616(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 616, temp.u32);
	// stfs f0,620(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 620, temp.u32);
	// stw r11,624(r31)
	REX_STORE_U32(ctx.r31.u32 + 624, ctx.r11.u32);
	// stfs f0,600(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 600, temp.u32);
	// stfs f0,596(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 596, temp.u32);
	// stfs f0,592(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 592, temp.u32);
	// stfs f0,612(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 612, temp.u32);
	// stfs f0,608(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 608, temp.u32);
	// stfs f0,604(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 604, temp.u32);
	// stw r11,628(r31)
	REX_STORE_U32(ctx.r31.u32 + 628, ctx.r11.u32);
	// stw r11,632(r31)
	REX_STORE_U32(ctx.r31.u32 + 632, ctx.r11.u32);
	// stw r11,636(r31)
	REX_STORE_U32(ctx.r31.u32 + 636, ctx.r11.u32);
	// stw r11,640(r31)
	REX_STORE_U32(ctx.r31.u32 + 640, ctx.r11.u32);
	// stw r11,644(r31)
	REX_STORE_U32(ctx.r31.u32 + 644, ctx.r11.u32);
	// bl 0x826a03b0
	ctx.lr = 0x82170C98;
	rexcrt_memset(ctx, base);
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

DEFINE_REX_FUNC(sub_82187EB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v0,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,32
	ctx.r11.s64 = 32;
	// lvx128 v13,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8218AEB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// lvx128 v7,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x1)));
	// vmsum3fp128 v6,v7,v7
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v7.f32), 0xEF));
	// vspltisw v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,-32
	ctx.r11.s64 = ctx.r1.s64 + -32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vcfsx v9,v0,1
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v0.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vrsqrtefp v0,v6
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v6.f32))));
	// vmulfp128 v13,v6,v9
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vcmpeqfp v8,v6,v12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v10,v0,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v9,v13,v10,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v9,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v0,v6,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v0,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vspltw v5,v13,0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0xFF));
	// stvewx v5,r0,r11
	ea = (ctx.r11.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v5.u32[3 - ((ea & 0xF) >> 2)]);
	// lfs f0,3084(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3084);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x8218af10
	if (!ctx.cr6.lt) goto loc_8218AF10;
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_8218AF10:
	// vrefp v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v13.f32)));
	// vupkd3d128 v11,v12,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v12.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v12.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v11 = vTemp;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// vspltw v8,v11,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x0));
	// stw r11,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// stw r11,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// stw r11,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r11.u32);
	// stw r9,-4(r1)
	REX_STORE_U32(ctx.r1.u32 + -4, ctx.r9.u32);
	// lvx128 v6,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v5,v13,v0,v8
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v11,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vmaddfp v0,v0,v5,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v8,v13,v0,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v0,v8,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v11,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v0,v7,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v13,v0,v12,v6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// stvx128 v13,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821935E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0284
	ctx.lr = 0x821935E8;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r24,-32108
	ctx.r24.s64 = -2104229888;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lis r23,-32256
	ctx.r23.s64 = -2113929216;
	// lwz r11,-2208(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -2208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8219361c
	if (ctx.cr6.eq) goto loc_8219361C;
	// bl 0x822cd6f8
	ctx.lr = 0x82193608;
	sub_822CD6F8(ctx, base);
	// addi r11,r3,-6
	ctx.r11.s64 = ctx.r3.s64 + -6;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82193684
	if (!ctx.cr6.eq) goto loc_82193684;
loc_8219361C:
	// lwz r3,500(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 500);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8219363c
	if (ctx.cr6.eq) goto loc_8219363C;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,504(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 504);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82193640
	if (ctx.cr6.eq) goto loc_82193640;
loc_8219363C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82193640:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82193660
	if (ctx.cr6.eq) goto loc_82193660;
	// lwz r10,60(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r11,30048(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82193664
	if (!ctx.cr6.eq) goto loc_82193664;
loc_82193660:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82193664:
	// addi r31,r25,160
	ctx.r31.s64 = ctx.r25.s64 + 160;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x821844a8
	ctx.lr = 0x82193670;
	sub_821844A8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r25,96
	ctx.r4.s64 = ctx.r25.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82189f70
	ctx.lr = 0x82193684;
	sub_82189F70(ctx, base);
loc_82193684:
	// lwz r11,448(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 448);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82193698
	if (ctx.cr6.eq) goto loc_82193698;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8219369c
	goto loc_8219369C;
loc_82193698:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8219369C:
	// li r31,16
	ctx.r31.s64 = 16;
	// li r28,32
	ctx.r28.s64 = 32;
	// li r29,48
	ctx.r29.s64 = 48;
	// addi r11,r11,96
	ctx.r11.s64 = ctx.r11.s64 + 96;
	// li r9,5
	ctx.r9.s64 = 5;
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r4,-32
	ctx.r4.s64 = -32;
	// li r5,-16
	ctx.r5.s64 = -16;
loc_821936C4:
	// addi r3,r11,-96
	ctx.r3.s64 = ctx.r11.s64 + -96;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// lvx128 v30,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r3,r31
	ea = (ctx.r3.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v28,v30,0
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v30.u32), 0xFF));
	// lvx128 v27,r3,r28
	ea = (ctx.r3.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v26,v29,0
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v29.u32), 0xFF));
	// lvx128 v25,r3,r29
	ea = (ctx.r3.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v24,v27,0
	simde_mm_store_si128((simde__m128i*)ctx.v24.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v27.u32), 0xFF));
	// lvx128 v23,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v22,v25,0
	simde_mm_store_si128((simde__m128i*)ctx.v22.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0xFF));
	// vmulfp128 v10,v28,v23
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vspltw v11,v30,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v30.u32), 0xAA));
	// vmulfp128 v8,v26,v23
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v26.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vspltw v9,v29,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v29.u32), 0xAA));
	// vmulfp128 v6,v24,v23
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v24.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vspltw v7,v27,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v27.u32), 0xAA));
	// vmulfp128 v4,v22,v23
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v22.f32), simde_mm_load_ps(ctx.v23.f32)));
	// lvx128 v0,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v5,v25,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0xAA));
	// lvx128 v13,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v3,v30,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v30.u32), 0x55));
	// lvx128 v12,r10,r6
	ea = (ctx.r10.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v2,v29,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v29.u32), 0x55));
	// vspltw v1,v27,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v27.u32), 0x55));
	// vspltw v31,v25,2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0x55));
	// vspltw v30,v30,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v30.u32), 0x0));
	// vspltw v28,v27,3
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v27.u32), 0x0));
	// vspltw v29,v29,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v29.u32), 0x0));
	// vmaddfp v11,v11,v0,v10
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw v27,v25,3
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0x0));
	// vmaddfp v10,v9,v0,v8
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v9,v7,v0,v6
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v5,v0,v4
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v11,v3,v13,v11
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
	// stvx128 v13,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,160
	ctx.r11.s64 = ctx.r11.s64 + 160;
	// bne 0x821936c4
	if (!ctx.cr0.eq) goto loc_821936C4;
	// lwz r3,440(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 440);
	// bl 0x8222dcd8
	ctx.lr = 0x82193794;
	sub_8222DCD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,68
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 68, ctx.xer);
	// beq cr6,0x821937a8
	if (ctx.cr6.eq) goto loc_821937A8;
	// cmpwi cr6,r3,69
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 69, ctx.xer);
	// bne cr6,0x821937bc
	if (!ctx.cr6.eq) goto loc_821937BC;
loc_821937A8:
	// lwz r11,416(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 416);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821937bc
	if (ctx.cr6.eq) goto loc_821937BC;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8218c920
	ctx.lr = 0x821937BC;
	sub_8218C920(ctx, base);
loc_821937BC:
	// cmpwi cr6,r30,82
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 82, ctx.xer);
	// bne cr6,0x82193988
	if (!ctx.cr6.eq) goto loc_82193988;
	// addi r27,r25,160
	ctx.r27.s64 = ctx.r25.s64 + 160;
	// li r4,1303
	ctx.r4.s64 = 1303;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82189348
	ctx.lr = 0x821937D4;
	sub_82189348(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82187ad8
	ctx.lr = 0x821937E4;
	sub_82187AD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82187ad8
	ctx.lr = 0x821937F4;
	sub_82187AD8(ctx, base);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82193988
	if (ctx.cr6.eq) goto loc_82193988;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82193988
	if (ctx.cr6.eq) goto loc_82193988;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82193988
	if (ctx.cr6.eq) goto loc_82193988;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v12,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r26,64
	ctx.r8.s64 = ctx.r26.s64 + 64;
	// lvx128 v8,r30,r28
	ea = (ctx.r30.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r30,r31
	ea = (ctx.r30.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v1,v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xFF));
	// vspltw v3,v9,0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0xFF));
	// addi r11,r30,64
	ctx.r11.s64 = ctx.r30.s64 + 64;
	// vspltw v7,v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xFF));
	// addi r10,r3,64
	ctx.r10.s64 = ctx.r3.s64 + 64;
	// lfs f0,2880(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// vspltw v29,v9,1
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0xAA));
	// stfs f0,48(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// vspltw v31,v8,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0xAA));
	// stfs f0,52(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// vspltw v27,v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xAA));
	// stfs f0,56(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// vspltw v5,v9,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0x55));
	// lvx128 v26,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v6,v8,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0x55));
	// lvx128 v0,r8,r31
	ea = (ctx.r8.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v4,v12,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0x55));
	// lvx128 v13,r8,r28
	ea = (ctx.r8.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v10,v8,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), 0x0));
	// lvx128 v25,r30,r29
	ea = (ctx.r30.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v24,v25,0
	simde_mm_store_si128((simde__m128i*)ctx.v24.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0xFF));
	// vmulfp128 v28,v7,v26
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v26.f32)));
	// vspltw v2,v25,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0xAA));
	// vmulfp128 v30,v3,v26
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v26.f32)));
	// vspltw v7,v25,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0x55));
	// vmulfp128 v1,v1,v26
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v26.f32)));
	// vspltw v8,v12,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0x0));
	// vmulfp128 v3,v24,v26
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v24.f32), simde_mm_load_ps(ctx.v26.f32)));
	// vspltw v9,v9,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0x0));
	// vspltw v11,v25,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0x0));
	// lvx128 v12,r8,r29
	ea = (ctx.r8.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v28,v27,v0,v28
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v28.f32)));
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
	// stvx128 v8,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v10,v12,v6
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vor v23,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vmaddfp v0,v11,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v9,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r11,r28
	ea = (ctx.r11.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r29
	ea = (ctx.r11.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v0,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// lvx128 v19,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v21,r3,r28
	ea = (ctx.r3.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v20,r3,r29
	ea = (ctx.r3.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r3,r31
	ea = (ctx.r3.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v17,v22,0
	simde_mm_store_si128((simde__m128i*)ctx.v17.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), 0xFF));
	// vspltw v18,v19,0
	simde_mm_store_si128((simde__m128i*)ctx.v18.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v19.u32), 0xFF));
	// vmulfp128 v11,v17,v23
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v17.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vspltw v16,v21,0
	simde_mm_store_si128((simde__m128i*)ctx.v16.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v21.u32), 0xFF));
	// lvx128 v12,r11,r29
	ea = (ctx.r11.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v8,v19,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v19.u32), 0xAA));
	// vspltw v10,v22,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), 0xAA));
	// vmulfp128 v9,v18,v23
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v18.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vspltw v15,v20,0
	simde_mm_store_si128((simde__m128i*)ctx.v15.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v20.u32), 0xFF));
	// vmulfp128 v1,v16,v23
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v16.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vspltw v31,v21,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v21.u32), 0xAA));
	// vspltw v2,v20,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v20.u32), 0xAA));
	// vspltw v4,v19,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v19.u32), 0x55));
	// vmulfp128 v3,v15,v23
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v15.f32), simde_mm_load_ps(ctx.v23.f32)));
	// vspltw v5,v22,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), 0x55));
	// vspltw v6,v21,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v21.u32), 0x55));
	// vspltw v7,v20,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v20.u32), 0x55));
	// vmaddfp v30,v10,v0,v11
	simde_mm_store_ps(ctx.v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw v10,v21,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v21.u32), 0x0));
	// vmaddfp v29,v8,v0,v9
	simde_mm_store_ps(ctx.v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw v8,v19,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v19.u32), 0x0));
	// vspltw v9,v22,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v22.u32), 0x0));
	// vmaddfp v1,v31,v0,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v0,v2,v0,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw v11,v20,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v20.u32), 0x0));
	// vmaddfp v4,v4,v13,v29
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v29.f32)));
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
	// stvx128 v8,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r10,r31
	ea = (ctx.r10.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r10,r28
	ea = (ctx.r10.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r10,r29
	ea = (ctx.r10.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82193988:
	// lwz r11,-2208(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -2208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821939ac
	if (ctx.cr6.eq) goto loc_821939AC;
	// bl 0x822cd6f8
	ctx.lr = 0x82193998;
	sub_822CD6F8(ctx, base);
	// addi r11,r3,-6
	ctx.r11.s64 = ctx.r3.s64 + -6;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821939fc
	if (!ctx.cr6.eq) goto loc_821939FC;
loc_821939AC:
	// lwz r3,500(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 500);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821939cc
	if (ctx.cr6.eq) goto loc_821939CC;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,504(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 504);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x821939d0
	if (ctx.cr6.eq) goto loc_821939D0;
loc_821939CC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821939D0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821939f0
	if (ctx.cr6.eq) goto loc_821939F0;
	// lwz r10,60(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r11,30048(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821939f4
	if (!ctx.cr6.eq) goto loc_821939F4;
loc_821939F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821939F4:
	// addi r4,r25,160
	ctx.r4.s64 = ctx.r25.s64 + 160;
	// bl 0x82184570
	ctx.lr = 0x821939FC;
	sub_82184570(ctx, base);
loc_821939FC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821B4188) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x821b41b8
	if (!ctx.cr6.eq) goto loc_821B41B8;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,244(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,2884(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f0,13280(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13280);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,244(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 244, temp.u32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// ble cr6,0x821b41b8
	if (!ctx.cr6.gt) goto loc_821B41B8;
	// stfs f0,244(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 244, temp.u32);
loc_821B41B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821B4D40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0268
	ctx.lr = 0x821B4D48;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x821b4ea4
	if (ctx.cr6.eq) goto loc_821B4EA4;
	// lwz r16,0(r5)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r17,0
	ctx.r17.s64 = 0;
	// cmpwi cr6,r16,0
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// ble cr6,0x821b4ea4
	if (!ctx.cr6.gt) goto loc_821B4EA4;
	// addi r29,r7,8
	ctx.r29.s64 = ctx.r7.s64 + 8;
	// addi r30,r5,4
	ctx.r30.s64 = ctx.r5.s64 + 4;
	// addi r26,r3,116
	ctx.r26.s64 = ctx.r3.s64 + 116;
	// subf r22,r5,r4
	ctx.r22.u64 = ctx.r4.u64 - ctx.r5.u64;
	// subf r21,r5,r6
	ctx.r21.u64 = ctx.r6.u64 - ctx.r5.u64;
	// subf r20,r5,r7
	ctx.r20.u64 = ctx.r7.u64 - ctx.r5.u64;
	// subf r19,r7,r6
	ctx.r19.u64 = ctx.r6.u64 - ctx.r7.u64;
loc_821B4D98:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x821b4ea4
	if (ctx.cr6.eq) goto loc_821B4EA4;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x821b4ea4
	if (ctx.cr6.eq) goto loc_821B4EA4;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x821b4ea4
	if (ctx.cr6.eq) goto loc_821B4EA4;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x821b4e8c
	if (!ctx.cr6.gt) goto loc_821B4E8C;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82219630
	ctx.lr = 0x821B4DD8;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821b4df0
	if (ctx.cr6.eq) goto loc_821B4DF0;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// bl 0x821b6658
	ctx.lr = 0x821B4DE8;
	sub_821B6658(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x821b4df4
	goto loc_821B4DF4;
loc_821B4DF0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821B4DF4:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8226bf28
	ctx.lr = 0x821B4DFC;
	sub_8226BF28(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8243fa70
	ctx.lr = 0x821B4E04;
	sub_8243FA70(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// add r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x821b5f48
	ctx.lr = 0x821B4E14;
	sub_821B5F48(ctx, base);
	// lwz r11,112(r18)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r18.u32 + 112);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x821b4e50
	if (!ctx.cr6.eq) goto loc_821B4E50;
	// addi r11,r17,-19
	ctx.r11.s64 = ctx.r17.s64 + -19;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x821b4e50
	if (ctx.cr6.gt) goto loc_821B4E50;
	// addi r11,r17,-19
	ctx.r11.s64 = ctx.r17.s64 + -19;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x821b4e4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821B4E4C;
	// bdzf 4*cr6+eq,0x821b4e50
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821B4E50;
	// bdzf 4*cr6+eq,0x821b4e4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821B4E4C;
	// bne cr6,0x821b4e4c
	if (!ctx.cr6.eq) goto loc_821B4E4C;
loc_821B4E4C:
	// li r5,1
	ctx.r5.s64 = 1;
loc_821B4E50:
	// lwzx r11,r22,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r4,r11,r23
	ctx.r4.u64 = ctx.r11.u64 + ctx.r23.u64;
	// bl 0x821b5f60
	ctx.lr = 0x821B4E60;
	sub_821B5F60(ctx, base);
	// lwzx r11,r21,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r5,r19,r29
	ctx.r5.u64 = REX_LOAD_U32(ctx.r19.u32 + ctx.r29.u32);
	// add r4,r11,r25
	ctx.r4.u64 = ctx.r11.u64 + ctx.r25.u64;
	// bl 0x821b5fd8
	ctx.lr = 0x821B4E74;
	sub_821B5FD8(ctx, base);
	// lwzx r11,r20,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x821b6080
	ctx.lr = 0x821B4E88;
	sub_821B6080(ctx, base);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
loc_821B4E8C:
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r26,r26,24
	ctx.r26.s64 = ctx.r26.s64 + 24;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// cmpw cr6,r17,r16
	ctx.cr6.compare<int32_t>(ctx.r17.s32, ctx.r16.s32, ctx.xer);
	// blt cr6,0x821b4d98
	if (ctx.cr6.lt) goto loc_821B4D98;
loc_821B4EA4:
	// stw r24,2424(r18)
	REX_STORE_U32(ctx.r18.u32 + 2424, ctx.r24.u32);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x82218fa0
	ctx.lr = 0x821B4EB0;
	sub_82218FA0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x826a02b8
	__restgprlr_16(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821BAE10) {
	REX_FUNC_PROLOGUE();
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lhz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// add r6,r10,r3
	ctx.r6.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r10,r11,r3
	ctx.r10.u64 = ctx.r11.u64 + ctx.r3.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r5,0
	ctx.r5.s64 = 0;
loc_821BAE30:
	// lhz r11,48(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 48);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,60(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// ble cr6,0x821bae6c
	if (!ctx.cr6.gt) goto loc_821BAE6C;
loc_821BAE48:
	// lwz r7,36(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r8,32(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r7,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r4,60(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x821bae48
	if (ctx.cr6.lt) goto loc_821BAE48;
loc_821BAE6C:
	// addi r11,r5,1
	ctx.r11.s64 = ctx.r5.s64 + 1;
	// lwz r9,68(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// lhz r8,8(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821bae30
	if (ctx.cr6.lt) goto loc_821BAE30;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821BD2D8) {
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
	// bl 0x821b8c98
	ctx.lr = 0x821BD2F0;
	sub_821B8C98(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,13932
	ctx.r10.s64 = ctx.r11.s64 + 13932;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_821BD8B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lvx128 v0,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821BDDA8) {
	REX_FUNC_PROLOGUE();
	// li r3,11
	ctx.r3.s64 = 11;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821BE7D0) {
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
	// bl 0x821c06e0
	ctx.lr = 0x821BE7E8;
	sub_821C06E0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,14316
	ctx.r10.s64 = ctx.r11.s64 + 14316;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_821BF1C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x821BF1C8;
	__savegprlr_26(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,132(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r26,-32256
	ctx.r26.s64 = -2113929216;
	// addi r27,r11,23664
	ctx.r27.s64 = ctx.r11.s64 + 23664;
	// lhz r9,50(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 50);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821bf25c
	if (!ctx.cr6.eq) goto loc_821BF25C;
	// lwz r11,316(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf200
	if (ctx.cr6.eq) goto loc_821BF200;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x821bf204
	goto loc_821BF204;
loc_821BF200:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821BF204:
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// addi r4,r10,48
	ctx.r4.s64 = ctx.r10.s64 + 48;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf228
	if (ctx.cr6.eq) goto loc_821BF228;
	// lwz r10,20(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821bf22c
	if (ctx.cr6.eq) goto loc_821BF22C;
loc_821BF228:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821BF22C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821bf24c
	if (ctx.cr6.eq) goto loc_821BF24C;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821bf250
	if (!ctx.cr6.eq) goto loc_821BF250;
loc_821BF24C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821BF250:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,924(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 924);
	// bl 0x82322a40
	ctx.lr = 0x821BF25C;
	sub_82322A40(ctx, base);
loc_821BF25C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 156);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,128(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821BF278;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821b7ea0
	ctx.lr = 0x821BF284;
	sub_821B7EA0(ctx, base);
	// bl 0x821b4fd0
	ctx.lr = 0x821BF288;
	sub_821B4FD0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821bf2c8
	if (ctx.cr6.eq) goto loc_821BF2C8;
	// addi r31,r31,312
	ctx.r31.s64 = ctx.r31.s64 + 312;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf2b4
	if (ctx.cr6.eq) goto loc_821BF2B4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x821c0be8
	ctx.lr = 0x821BF2B0;
	sub_821C0BE8(ctx, base);
	// b 0x821bf374
	goto loc_821BF374;
loc_821BF2B4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821c0be8
	ctx.lr = 0x821BF2C4;
	sub_821C0BE8(ctx, base);
	// b 0x821bf374
	goto loc_821BF374;
loc_821BF2C8:
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf2e8
	if (ctx.cr6.eq) goto loc_821BF2E8;
	// lwz r10,20(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821bf2ec
	if (ctx.cr6.eq) goto loc_821BF2EC;
loc_821BF2E8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821BF2EC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821bf30c
	if (ctx.cr6.eq) goto loc_821BF30C;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821bf310
	if (!ctx.cr6.eq) goto loc_821BF310;
loc_821BF30C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821BF310:
	// addi r31,r31,312
	ctx.r31.s64 = ctx.r31.s64 + 312;
	// lwz r30,888(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 888);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf32c
	if (ctx.cr6.eq) goto loc_821BF32C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x821bf330
	goto loc_821BF330;
loc_821BF32C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821BF330:
	// bl 0x82513be0
	ctx.lr = 0x821BF334;
	sub_82513BE0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf348
	if (ctx.cr6.eq) goto loc_821BF348;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x821bf34c
	goto loc_821BF34C;
loc_821BF348:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821BF34C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821a6f48
	ctx.lr = 0x821BF354;
	sub_821A6F48(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8219cf18
	ctx.lr = 0x821BF35C;
	sub_8219CF18(ctx, base);
	// bl 0x82513308
	ctx.lr = 0x821BF360;
	sub_82513308(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82513bc0
	ctx.lr = 0x821BF368;
	sub_82513BC0(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821a6f48
	ctx.lr = 0x821BF374;
	sub_821A6F48(ctx, base);
loc_821BF374:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf388
	if (ctx.cr6.eq) goto loc_821BF388;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x821bf38c
	goto loc_821BF38C;
loc_821BF388:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821BF38C:
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r1,72
	ctx.r10.s64 = ctx.r1.s64 + 72;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_821BF39C:
	// ldu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U64(ea);
	ctx.r11.u32 = ea;
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x821bf39c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821BF39C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f8,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f11,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,14848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f9,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f1,f10,f0
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f6,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f4,124(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f10,f8,f0
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f7,f13,f0
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f2,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f11,f0
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f9,f0
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfs f11,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f8,f6,f0
	ctx.f8.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// lfs f9,108(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f6,f4,f0
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f5,112(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f8,92(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f6,124(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// beq cr6,0x821bf444
	if (ctx.cr6.eq) goto loc_821BF444;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x821bf448
	goto loc_821BF448;
loc_821BF444:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821BF448:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r9,r10,14672
	ctx.r9.s64 = ctx.r10.s64 + 14672;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,14672(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14672);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f11,f13,f0,f12
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// beq cr6,0x821bf480
	if (ctx.cr6.eq) goto loc_821BF480;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x821bf484
	goto loc_821BF484;
loc_821BF480:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821BF484:
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lfs f12,136(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f13,f0,f12
	ctx.f11.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// beq cr6,0x821bf4b4
	if (ctx.cr6.eq) goto loc_821BF4B4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,11167
	ctx.r4.s64 = 11167;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821c0be8
	ctx.lr = 0x821BF4AC;
	sub_821C0BE8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_821BF4B4:
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821bf4d4
	if (ctx.cr6.eq) goto loc_821BF4D4;
	// lwz r10,20(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821bf4d8
	if (ctx.cr6.eq) goto loc_821BF4D8;
loc_821BF4D4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821BF4D8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821bf4f8
	if (ctx.cr6.eq) goto loc_821BF4F8;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821bf4fc
	if (!ctx.cr6.eq) goto loc_821BF4FC;
loc_821BF4F8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821BF4FC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,888(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 888);
	// bl 0x82513be0
	ctx.lr = 0x821BF508;
	sub_82513BE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821a6f48
	ctx.lr = 0x821BF514;
	sub_821A6F48(ctx, base);
	// li r3,11167
	ctx.r3.s64 = 11167;
	// bl 0x8219cf18
	ctx.lr = 0x821BF51C;
	sub_8219CF18(ctx, base);
	// bl 0x82513308
	ctx.lr = 0x821BF520;
	sub_82513308(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82513bc0
	ctx.lr = 0x821BF528;
	sub_82513BC0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821a6f48
	ctx.lr = 0x821BF534;
	sub_821A6F48(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821D3840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x821D3848;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,4608(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4608);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d3b8c
	if (ctx.cr6.eq) goto loc_821D3B8C;
	// lbz r11,4610(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4610);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d3b8c
	if (ctx.cr6.eq) goto loc_821D3B8C;
	// lbz r11,4611(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4611);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821d3b8c
	if (!ctx.cr6.eq) goto loc_821D3B8C;
	// addi r29,r3,340
	ctx.r29.s64 = ctx.r3.s64 + 340;
	// li r5,104
	ctx.r5.s64 = 104;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x821D3884;
	rexcrt_memcpy(ctx, base);
	// addi r30,r31,464
	ctx.r30.s64 = ctx.r31.s64 + 464;
	// lwz r4,364(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82297df8
	ctx.lr = 0x821D3894;
	sub_82297DF8(ctx, base);
	// li r10,18
	ctx.r10.s64 = 18;
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r10.u32);
	// addi r4,r11,6
	ctx.r4.s64 = ctx.r11.s64 + 6;
	// bl 0x822a2680
	ctx.lr = 0x821D38AC;
	sub_822A2680(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822a2b80
	ctx.lr = 0x821D38C0;
	sub_822A2B80(ctx, base);
	// lwz r9,368(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// cmpwi cr6,r9,539
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 539, ctx.xer);
	// bne cr6,0x821d3978
	if (!ctx.cr6.eq) goto loc_821D3978;
	// lwz r11,3600(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3600);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821d3978
	if (!ctx.cr6.eq) goto loc_821D3978;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,3136
	ctx.r3.s64 = 3136;
	// bl 0x8223d420
	ctx.lr = 0x821D38F0;
	sub_8223D420(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3900
	if (ctx.cr6.eq) goto loc_821D3900;
	// bl 0x821702c8
	ctx.lr = 0x821D38FC;
	sub_821702C8(ctx, base);
	// b 0x821d3904
	goto loc_821D3904;
loc_821D3900:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821D3904:
	// stw r3,3600(r31)
	REX_STORE_U32(ctx.r31.u32 + 3600, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3978
	if (ctx.cr6.eq) goto loc_821D3978;
	// lwz r4,540(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 540);
	// bl 0x822a2680
	ctx.lr = 0x821D3918;
	sub_822A2680(ctx, base);
	// lwz r3,3600(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3600);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r3,620(r31)
	REX_STORE_U32(ctx.r31.u32 + 620, ctx.r3.u32);
	// bl 0x82298670
	ctx.lr = 0x821D3928;
	sub_82298670(ctx, base);
	// lwz r9,620(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// lwz r8,548(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// li r11,15
	ctx.r11.s64 = 15;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r8,84(r9)
	REX_STORE_U32(ctx.r9.u32 + 84, ctx.r8.u32);
	// lwz r7,620(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// lwz r6,552(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// stw r6,88(r7)
	REX_STORE_U32(ctx.r7.u32 + 88, ctx.r6.u32);
	// lwz r5,620(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// stw r11,120(r5)
	REX_STORE_U32(ctx.r5.u32 + 120, ctx.r11.u32);
	// lwz r4,620(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// stw r10,660(r4)
	REX_STORE_U32(ctx.r4.u32 + 660, ctx.r10.u32);
	// lwz r3,620(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// stw r30,152(r3)
	REX_STORE_U32(ctx.r3.u32 + 152, ctx.r30.u32);
	// lwz r11,620(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// lwz r10,3584(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3584);
	// stw r10,3120(r11)
	REX_STORE_U32(ctx.r11.u32 + 3120, ctx.r10.u32);
	// lwz r9,620(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 620);
	// lwz r8,2272(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 2272);
	// stw r8,1808(r9)
	REX_STORE_U32(ctx.r9.u32 + 1808, ctx.r8.u32);
loc_821D3978:
	// lwz r11,3604(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3604);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821d3a74
	if (!ctx.cr6.eq) goto loc_821D3A74;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,3136
	ctx.r3.s64 = 3136;
	// bl 0x8223d420
	ctx.lr = 0x821D399C;
	sub_8223D420(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d39ac
	if (ctx.cr6.eq) goto loc_821D39AC;
	// bl 0x821702c8
	ctx.lr = 0x821D39A8;
	sub_821702C8(ctx, base);
	// b 0x821d39b0
	goto loc_821D39B0;
loc_821D39AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821D39B0:
	// stw r3,3604(r31)
	REX_STORE_U32(ctx.r31.u32 + 3604, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3a74
	if (ctx.cr6.eq) goto loc_821D3A74;
	// lwz r4,540(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 540);
	// bl 0x822a2680
	ctx.lr = 0x821D39C4;
	sub_822A2680(ctx, base);
	// lwz r3,3604(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3604);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r3,624(r31)
	REX_STORE_U32(ctx.r31.u32 + 624, ctx.r3.u32);
	// bl 0x82298670
	ctx.lr = 0x821D39D4;
	sub_82298670(ctx, base);
	// lwz r8,624(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// lwz r7,548(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 548);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r11,r31,1128
	ctx.r11.s64 = ctx.r31.s64 + 1128;
	// stw r7,84(r8)
	REX_STORE_U32(ctx.r8.u32 + 84, ctx.r7.u32);
	// lwz r5,624(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r6,552(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 552);
	// stw r6,88(r5)
	REX_STORE_U32(ctx.r5.u32 + 88, ctx.r6.u32);
	// lwz r4,624(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// stw r9,120(r4)
	REX_STORE_U32(ctx.r4.u32 + 120, ctx.r9.u32);
	// lwz r3,624(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// stw r10,660(r3)
	REX_STORE_U32(ctx.r3.u32 + 660, ctx.r10.u32);
	// lwz r10,624(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// stw r30,152(r10)
	REX_STORE_U32(ctx.r10.u32 + 152, ctx.r30.u32);
	// lwz r9,624(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// lwz r8,3584(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3584);
	// stw r8,3120(r9)
	REX_STORE_U32(ctx.r9.u32 + 3120, ctx.r8.u32);
	// lwz r7,624(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// lwz r6,2272(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 2272);
	// stw r6,1808(r7)
	REX_STORE_U32(ctx.r7.u32 + 1808, ctx.r6.u32);
	// lwz r10,624(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// addi r10,r10,664
	ctx.r10.s64 = ctx.r10.s64 + 664;
loc_821D3A34:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x821d3a34
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821D3A34;
	// lwz r11,624(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// addi r4,r31,1152
	ctx.r4.s64 = ctx.r31.s64 + 1152;
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r3,r11,688
	ctx.r3.s64 = ctx.r11.s64 + 688;
	// bl 0x826a1130
	ctx.lr = 0x821D3A54;
	rexcrt_memcpy(ctx, base);
	// bl 0x82170cb0
	ctx.lr = 0x821D3A58;
	sub_82170CB0(ctx, base);
	// lwz r3,860(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 860);
	// lwz r28,624(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// lwz r27,364(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// bl 0x821c8110
	ctx.lr = 0x821D3A68;
	sub_821C8110(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x822d6c48
	ctx.lr = 0x821D3A70;
	sub_822D6C48(ctx, base);
	// stw r3,3124(r28)
	REX_STORE_U32(ctx.r28.u32 + 3124, ctx.r3.u32);
loc_821D3A74:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,448(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 448, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r29,-32114
	ctx.r29.s64 = -2104623104;
	// lfs f12,348(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f12,456(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 456, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,12688(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12688);
	ctx.f0.f64 = double(temp.f32);
	// addi r28,r29,-12664
	ctx.r28.s64 = ctx.r29.s64 + -12664;
	// lfs f13,2884(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2884);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,452(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 452, temp.u32);
	// stfs f13,460(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 460, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f1,352(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 352);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,-12664(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12664);
	// lfs f2,72(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8229b190
	ctx.lr = 0x821D3AC8;
	sub_8229B190(ctx, base);
	// lwz r11,-12664(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -12664);
	// lwz r9,1808(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 1808);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r9,2272(r31)
	REX_STORE_U32(ctx.r31.u32 + 2272, ctx.r9.u32);
	// bl 0x82298900
	ctx.lr = 0x821D3ADC;
	sub_82298900(ctx, base);
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,21
	ctx.r5.s64 = 21;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r29,r8,r28
	ctx.r29.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r28.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x822a2ca0
	ctx.lr = 0x821D3AFC;
	sub_822A2CA0(ctx, base);
	// stw r29,608(r31)
	REX_STORE_U32(ctx.r31.u32 + 608, ctx.r29.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82288110
	ctx.lr = 0x821D3B10;
	sub_82288110(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82290f20
	ctx.lr = 0x821D3B1C;
	sub_82290F20(ctx, base);
	// li r29,1
	ctx.r29.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r4,380(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
	// stw r29,1124(r31)
	REX_STORE_U32(ctx.r31.u32 + 1124, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,1104(r31)
	REX_STORE_U32(ctx.r31.u32 + 1104, ctx.r29.u32);
	// stw r7,2420(r31)
	REX_STORE_U32(ctx.r31.u32 + 2420, ctx.r7.u32);
	// bl 0x822c1f08
	ctx.lr = 0x821D3B3C;
	sub_822C1F08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822b1128
	ctx.lr = 0x821D3B44;
	sub_822B1128(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217d340
	ctx.lr = 0x821D3B4C;
	sub_8217D340(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217d400
	ctx.lr = 0x821D3B54;
	sub_8217D400(ctx, base);
	// lwz r3,3584(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3584);
	// bl 0x82230270
	ctx.lr = 0x821D3B5C;
	sub_82230270(ctx, base);
	// stw r29,1104(r31)
	REX_STORE_U32(ctx.r31.u32 + 1104, ctx.r29.u32);
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// li r5,13023
	ctx.r5.s64 = 13023;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,30044(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 30044);
	// bl 0x822189c8
	ctx.lr = 0x821D3B78;
	sub_822189C8(ctx, base);
	// lwz r11,30044(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 30044);
	// lwz r6,60(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stb r29,4611(r31)
	REX_STORE_U8(ctx.r31.u32 + 4611, ctx.r29.u8);
	// or r5,r6,r11
	ctx.r5.u64 = ctx.r6.u64 | ctx.r11.u64;
	// stw r5,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r5.u32);
loc_821D3B8C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821E4ED0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v11,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// vspltw v10,v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xFF));
	// li r11,48
	ctx.r11.s64 = 48;
	// lvx128 v9,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v3,v11,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xAA));
	// vspltw v4,v11,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x55));
	// lvx128 v26,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v2,v10,v9
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v25,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v24,v26,0
	simde_mm_store_si128((simde__m128i*)ctx.v24.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v26.u32), 0xFF));
	// lvx128 v23,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v22,v25,0
	simde_mm_store_si128((simde__m128i*)ctx.v22.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0xFF));
	// vspltw v21,v23,0
	simde_mm_store_si128((simde__m128i*)ctx.v21.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), 0xFF));
	// lvx128 v0,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v1,v26,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v26.u32), 0xAA));
	// lvx128 v13,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v31,v24,v9
	simde_mm_store_ps(ctx.v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v24.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw v30,v25,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0xAA));
	// vmulfp128 v29,v22,v9
	simde_mm_store_ps(ctx.v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v22.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw v28,v23,1
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), 0xAA));
	// vmulfp128 v27,v21,v9
	simde_mm_store_ps(ctx.v27.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v21.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw v5,v26,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v26.u32), 0x55));
	// vspltw v6,v25,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0x55));
	// lvx128 v12,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw v7,v23,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), 0x55));
	// vspltw v8,v11,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0x0));
	// vspltw v9,v26,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v26.u32), 0x0));
	// vmaddfp v3,v3,v0,v2
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vspltw v10,v25,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v25.u32), 0x0));
	// vspltw v11,v23,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v23.u32), 0x0));
	// vmaddfp v2,v1,v0,v31
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v1,v30,v0,v29
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v29.f32)));
	// vmaddfp v0,v28,v0,v27
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v27.f32)));
	// vmaddfp v4,v4,v13,v3
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v5,v5,v13,v2
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v2.f32)));
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
	// stvx128 v8,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821EE680) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x821EE688;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,80(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// bl 0x8220be68
	ctx.lr = 0x821EE694;
	sub_8220BE68(ctx, base);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lwz r29,152(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// addi r31,r11,23664
	ctx.r31.s64 = ctx.r11.s64 + 23664;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ee6c0
	if (ctx.cr6.eq) goto loc_821EE6C0;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821ee6c4
	if (ctx.cr6.eq) goto loc_821EE6C4;
loc_821EE6C0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821EE6C4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821ee6e8
	if (ctx.cr6.eq) goto loc_821EE6E8;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821ee6ec
	if (!ctx.cr6.eq) goto loc_821EE6EC;
loc_821EE6E8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821EE6EC:
	// lwz r3,848(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 848);
	// bl 0x82223748
	ctx.lr = 0x821EE6F4;
	sub_82223748(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ee764
	if (ctx.cr6.eq) goto loc_821EE764;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ee71c
	if (ctx.cr6.eq) goto loc_821EE71C;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821ee720
	if (ctx.cr6.eq) goto loc_821EE720;
loc_821EE71C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821EE720:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821ee740
	if (ctx.cr6.eq) goto loc_821EE740;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821ee744
	if (!ctx.cr6.eq) goto loc_821EE744;
loc_821EE740:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821EE744:
	// lwz r3,848(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 848);
	// bl 0x82222380
	ctx.lr = 0x821EE74C;
	sub_82222380(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,496(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 496);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EE75C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821ee7b4
	if (!ctx.cr6.eq) goto loc_821EE7B4;
loc_821EE764:
	// lwz r11,84(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 84);
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// bne cr6,0x821ee7b4
	if (!ctx.cr6.eq) goto loc_821EE7B4;
	// bl 0x82170cb0
	ctx.lr = 0x821EE774;
	sub_82170CB0(ctx, base);
	// lwz r3,848(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 848);
	// bl 0x82223748
	ctx.lr = 0x821EE77C;
	sub_82223748(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ee7a8
	if (ctx.cr6.eq) goto loc_821EE7A8;
	// bl 0x82170cb0
	ctx.lr = 0x821EE788;
	sub_82170CB0(ctx, base);
	// lwz r3,848(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 848);
	// bl 0x82222380
	ctx.lr = 0x821EE790;
	sub_82222380(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,500(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 500);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821EE7A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821ee7b4
	if (!ctx.cr6.eq) goto loc_821EE7B4;
loc_821EE7A8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_821EE7B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821F4D88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x821F4D90;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// addis r30,r3,2
	ctx.r30.s64 = ctx.r3.s64 + 131072;
	// lis r11,2
	ctx.r11.s64 = 131072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-22112
	ctx.r30.s64 = ctx.r30.s64 + -22112;
	// ori r29,r11,23492
	ctx.r29.u64 = ctx.r11.u64 | 23492;
	// cmplwi cr6,r28,200
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 200, ctx.xer);
	// bge cr6,0x821f4dfc
	if (!ctx.cr6.lt) goto loc_821F4DFC;
loc_821F4DB4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821f4dfc
	if (ctx.cr6.eq) goto loc_821F4DFC;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821f4dfc
	if (ctx.cr6.eq) goto loc_821F4DFC;
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// add r10,r31,r29
	ctx.r10.u64 = ctx.r31.u64 + ctx.r29.u64;
	// cmplwi cr6,r11,200
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 200, ctx.xer);
	// bge cr6,0x821f4dfc
	if (!ctx.cr6.lt) goto loc_821F4DFC;
	// addi r9,r11,2215
	ctx.r9.s64 = ctx.r11.s64 + 2215;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r9,6,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// add. r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x821f4dfc
	if (ctx.cr0.eq) goto loc_821F4DFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821f3290
	ctx.lr = 0x821F4DFC;
	sub_821F3290(ctx, base);
loc_821F4DFC:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r30,r30,64
	ctx.r30.s64 = ctx.r30.s64 + 64;
	// cmplwi cr6,r28,200
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 200, ctx.xer);
	// blt cr6,0x821f4db4
	if (ctx.cr6.lt) goto loc_821F4DB4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821F6768) {
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
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821f37f0
	ctx.lr = 0x821F6784;
	sub_821F37F0(ctx, base);
	// stw r3,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// li r4,49
	ctx.r4.s64 = 49;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821f37f0
	ctx.lr = 0x821F6794;
	sub_821F37F0(ctx, base);
	// stw r3,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r3.u32);
	// li r4,50
	ctx.r4.s64 = 50;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821f37f0
	ctx.lr = 0x821F67A4;
	sub_821F37F0(ctx, base);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// stw r3,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821f67d0
	if (ctx.cr6.eq) goto loc_821F67D0;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821f67d0
	if (ctx.cr6.eq) goto loc_821F67D0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821f67d0
	if (ctx.cr6.eq) goto loc_821F67D0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
loc_821F67D0:
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

DEFINE_REX_FUNC(sub_821F8DF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfs f0,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2880(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x821f8e48
	if (!ctx.cr6.gt) goto loc_821F8E48;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lfs f13,13720(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13720);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x821f8e48
	if (!ctx.cr6.lt) goto loc_821F8E48;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,13716(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13716);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13904(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13904);
	ctx.f12.f64 = double(temp.f32);
	// fmsubs f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f0,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// blr 
	return;
loc_821F8E48:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13148);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f0,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FAFB0) {
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
	// lwz r11,144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r3,144
	ctx.r30.s64 = ctx.r3.s64 + 144;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x821fb040
	if (ctx.cr6.eq) goto loc_821FB040;
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821fb040
	if (ctx.cr6.eq) goto loc_821FB040;
	// bl 0x82513bb8
	ctx.lr = 0x821FAFE8;
	sub_82513BB8(ctx, base);
	// lwz r11,148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821faffc
	if (!ctx.cr6.eq) goto loc_821FAFFC;
	// lwz r3,156(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// b 0x821fb000
	goto loc_821FB000;
loc_821FAFFC:
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
loc_821FB000:
	// bl 0x82513be0
	ctx.lr = 0x821FB004;
	sub_82513BE0(ctx, base);
	// lwz r11,148(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f3,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f3.f64 = double(temp.f32);
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bne cr6,0x821fb02c
	if (!ctx.cr6.eq) goto loc_821FB02C;
	// addi r9,r10,14096
	ctx.r9.s64 = ctx.r10.s64 + 14096;
	// lfs f1,100(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// b 0x821fb030
	goto loc_821FB030;
loc_821FB02C:
	// lfs f1,14096(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14096);
	ctx.f1.f64 = double(temp.f32);
loc_821FB030:
	// bl 0x82513670
	ctx.lr = 0x821FB034;
	sub_82513670(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821fc9e8
	ctx.lr = 0x821FB03C;
	sub_821FC9E8(ctx, base);
	// bl 0x82524b40
	ctx.lr = 0x821FB040;
	sub_82524B40(ctx, base);
loc_821FB040:
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

DEFINE_REX_FUNC(sub_821FD568) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x821fd584
	if (ctx.cr6.lt) goto loc_821FD584;
	// bne cr6,0x821fd584
	if (!ctx.cr6.eq) goto loc_821FD584;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r3,88(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 88);
	// blr 
	return;
loc_821FD584:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FDBE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x821FDBE8;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r24,0
	ctx.r24.s64 = 0;
loc_821FDC00:
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_821FDC08:
	// lwz r4,0(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x821fdc58
	if (ctx.cr6.eq) goto loc_821FDC58;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fd830
	ctx.lr = 0x821FDC1C;
	sub_821FD830(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
loc_821FDC20:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fd590
	ctx.lr = 0x821FDC30;
	sub_821FD590(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821fdc48
	if (ctx.cr6.eq) goto loc_821FDC48;
	// cmpw cr6,r30,r26
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r26.s32, ctx.xer);
	// beq cr6,0x821fdc78
	if (ctx.cr6.eq) goto loc_821FDC78;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// b 0x821fdc4c
	goto loc_821FDC4C;
loc_821FDC48:
	// li r31,20
	ctx.r31.s64 = 20;
loc_821FDC4C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,20
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 20, ctx.xer);
	// blt cr6,0x821fdc20
	if (ctx.cr6.lt) goto loc_821FDC20;
loc_821FDC58:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r29,r29,20
	ctx.r29.s64 = ctx.r29.s64 + 20;
	// cmpwi cr6,r27,23
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 23, ctx.xer);
	// blt cr6,0x821fdc08
	if (ctx.cr6.lt) goto loc_821FDC08;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// cmpwi cr6,r24,72
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 72, ctx.xer);
	// blt cr6,0x821fdc00
	if (ctx.cr6.lt) goto loc_821FDC00;
	// li r3,0
	ctx.r3.s64 = 0;
loc_821FDC78:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821FF800) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x821ff814
	if (!ctx.cr6.eq) goto loc_821FF814;
	// blr 
	return;
loc_821FF814:
	// lwz r6,0(r5)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// blt cr6,0x821ff860
	if (ctx.cr6.lt) goto loc_821FF860;
	// addi r10,r6,-2
	ctx.r10.s64 = ctx.r6.s64 + -2;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r4,r10,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821FF844:
	// lwz r9,64(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// lwzu r10,128(r11)
	ea = 128 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// bdnz 0x821ff844
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821FF844;
loc_821FF860:
	// cmpw cr6,r4,r6
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x821ff878
	if (!ctx.cr6.lt) goto loc_821FF878;
	// addi r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 1;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lwzx r9,r10,r5
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_821FF878:
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82202C10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82202C18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bgt cr6,0x82202ca0
	if (ctx.cr6.gt) goto loc_82202CA0;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82202d6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82202D6C;
	// bdzf 4*cr6+eq,0x82202d50
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82202D50;
	// bdzf 4*cr6+eq,0x82202ca0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82202CA0;
	// bne cr6,0x82202d84
	if (!ctx.cr6.eq) goto loc_82202D84;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82202C58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r3,-6
	ctx.r11.s64 = ctx.r3.s64 + -6;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x82202c98
	if (ctx.cr6.gt) goto loc_82202C98;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82202d3c
	if (ctx.cr6.eq) goto loc_82202D3C;
	// bdz 0x82202cac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82202CAC;
	// bdz 0x82202d28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82202D28;
	// bdz 0x82202c98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82202C98;
	// bdnz 0x82202c98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82202C98;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82202C94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
loc_82202C98:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
loc_82202CA0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82202CAC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82202CC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,20(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82202CD8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82202ca0
	if (!ctx.cr6.eq) goto loc_82202CA0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82202CF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82202D0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r3,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r3.u32);
	// stw r29,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82202D28:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,36(r30)
	REX_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82202D3C:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82202D50:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r10,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82202D6C:
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82202d90
	if (!ctx.cr6.eq) goto loc_82202D90;
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82202d90
	if (ctx.cr6.eq) goto loc_82202D90;
loc_82202D84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82202D90:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8220B9F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x8220BA00;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8220BA10:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,212(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 212);
	// bl 0x82234bb8
	ctx.lr = 0x8220BA1C;
	sub_82234BB8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8220ba98
	if (ctx.cr6.eq) goto loc_8220BA98;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,212(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 212);
	// bl 0x82234d48
	ctx.lr = 0x8220BA34;
	sub_82234D48(ctx, base);
	// lwz r11,6968(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 6968);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8220ba48
	if (ctx.cr6.eq) goto loc_8220BA48;
	// lwz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8220ba4c
	goto loc_8220BA4C;
loc_8220BA48:
	// li r27,0
	ctx.r27.s64 = 0;
loc_8220BA4C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,212(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 212);
	// li r31,0
	ctx.r31.s64 = 0;
	// bl 0x82234d48
	ctx.lr = 0x8220BA5C;
	sub_82234D48(ctx, base);
	// lwz r11,376(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 376);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8220ba98
	if (!ctx.cr6.gt) goto loc_8220BA98;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
loc_8220BA6C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x8220bab0
	if (ctx.cr6.eq) goto loc_8220BAB0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,212(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 212);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bl 0x82234d48
	ctx.lr = 0x8220BA8C;
	sub_82234D48(ctx, base);
	// lwz r11,376(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 376);
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8220ba6c
	if (ctx.cr6.lt) goto loc_8220BA6C;
loc_8220BA98:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,72
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 72, ctx.xer);
	// blt cr6,0x8220ba10
	if (ctx.cr6.lt) goto loc_8220BA10;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8220BAB0:
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82215650) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82215658;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,212(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 212);
	// bl 0x82233c88
	ctx.lr = 0x82215668;
	sub_82233C88(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8221569c
	if (!ctx.cr6.eq) goto loc_8221569C;
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmpwi cr6,r11,13
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 13, ctx.xer);
	// blt cr6,0x82215684
	if (ctx.cr6.lt) goto loc_82215684;
	// cmpwi cr6,r11,14
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 14, ctx.xer);
	// ble cr6,0x8221569c
	if (!ctx.cr6.gt) goto loc_8221569C;
loc_82215684:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8221569c
	if (ctx.cr6.eq) goto loc_8221569C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220c9d8
	ctx.lr = 0x8221569C;
	sub_8220C9D8(ctx, base);
loc_8221569C:
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// bgt cr6,0x822157c0
	if (ctx.cr6.gt) goto loc_822157C0;
	// lis r12,-32223
	ctx.r12.s64 = -2111766528;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,22208
	ctx.r12.s64 = ctx.r12.s64 + 22208;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_822156FC;
	case 1:
		goto loc_822157E0;
	case 2:
		goto loc_822158C8;
	case 3:
		goto loc_822159C0;
	case 4:
		goto loc_822159C0;
	case 5:
		goto loc_822159C0;
	case 6:
		goto loc_822159C0;
	case 7:
		goto loc_822159C0;
	case 8:
		goto loc_822159C0;
	case 9:
		goto loc_822159C0;
	case 10:
		goto loc_822159C0;
	case 11:
		goto loc_82216794;
	case 12:
		goto loc_822167C0;
	case 13:
		goto loc_82216A28;
	case 14:
		goto loc_82216D38;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_822156FC:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// li r28,1
	ctx.r28.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82215778
	if (ctx.cr6.eq) goto loc_82215778;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220b2f8
	ctx.lr = 0x82215714;
	sub_8220B2F8(ctx, base);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82233f30
	ctx.lr = 0x82215724;
	sub_82233F30(ctx, base);
	// bl 0x821e7e00
	ctx.lr = 0x82215728;
	sub_821E7E00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82215748
	if (ctx.cr6.eq) goto loc_82215748;
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233f30
	ctx.lr = 0x82215738;
	sub_82233F30(ctx, base);
	// bl 0x821e7e78
	ctx.lr = 0x8221573C;
	sub_821E7E78(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82215748
	if (ctx.cr6.eq) goto loc_82215748;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_82215748:
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233f38
	ctx.lr = 0x82215750;
	sub_82233F38(ctx, base);
	// bl 0x821e7e00
	ctx.lr = 0x82215754;
	sub_821E7E00(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82215770
	if (ctx.cr6.eq) goto loc_82215770;
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233f38
	ctx.lr = 0x82215764;
	sub_82233F38(ctx, base);
	// bl 0x821e7e78
	ctx.lr = 0x82215768;
	sub_821E7E78(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82215778
	if (!ctx.cr6.eq) goto loc_82215778;
loc_82215770:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
loc_82215778:
	// lwz r10,384(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x822157cc
	if (ctx.cr6.gt) goto loc_822157CC;
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r9,1940(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 1940);
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bge cr6,0x822157b0
	if (!ctx.cr6.lt) goto loc_822157B0;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,1940(r11)
	REX_STORE_U32(ctx.r11.u32 + 1940, ctx.r10.u32);
	// stw r28,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822157B0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x822157cc
	if (ctx.cr6.gt) goto loc_822157CC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
loc_822157C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822157CC:
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822157E0:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82215880
	if (ctx.cr6.eq) goto loc_82215880;
	// cmpwi cr6,r11,57
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 57, ctx.xer);
	// beq cr6,0x8221580c
	if (ctx.cr6.eq) goto loc_8221580C;
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,260(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// lwz r3,1892(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 1892);
	// bl 0x821700c0
	ctx.lr = 0x82215808;
	sub_821700C0(ctx, base);
	// b 0x822158a0
	goto loc_822158A0;
loc_8221580C:
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x822331c8
	ctx.lr = 0x82215814;
	sub_822331C8(ctx, base);
	// cmpwi cr6,r3,18
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 18, ctx.xer);
	// bne cr6,0x82215868
	if (!ctx.cr6.eq) goto loc_82215868;
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233160
	ctx.lr = 0x82215824;
	sub_82233160(ctx, base);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82233c18
	ctx.lr = 0x82215834;
	sub_82233C18(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r9,152(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 152);
	// lwz r11,84(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// addi r10,r11,-43
	ctx.r10.s64 = ctx.r11.s64 + -43;
	// subfic r8,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r8.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r6,r11
	ctx.r4.u64 = ctx.r6.u64 & ctx.r11.u64;
	// bl 0x822340f0
	ctx.lr = 0x82215858;
	sub_822340F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,260(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// bl 0x821700c0
	ctx.lr = 0x82215864;
	sub_821700C0(ctx, base);
	// b 0x822158a0
	goto loc_822158A0;
loc_82215868:
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,260(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// lwz r3,1892(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 1892);
	// bl 0x821700c0
	ctx.lr = 0x8221587C;
	sub_821700C0(ctx, base);
	// b 0x822158a0
	goto loc_822158A0;
loc_82215880:
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// li r4,21
	ctx.r4.s64 = 21;
	// lwz r10,1960(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1960);
	// lwz r3,1892(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 1892);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x8221589c
	if (ctx.cr6.eq) goto loc_8221589C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8221589C:
	// bl 0x82170088
	ctx.lr = 0x822158A0;
	sub_82170088(ctx, base);
loc_822158A0:
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82214a28
	ctx.lr = 0x822158AC;
	sub_82214A28(ctx, base);
	// cntlzw r11,r3
	ctx.r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// stw r10,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822158C8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_822158CC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821f2478
	ctx.lr = 0x822158D4;
	sub_821F2478(ctx, base);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8221591c
	if (ctx.cr6.eq) goto loc_8221591C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821f2478
	ctx.lr = 0x822158EC;
	sub_821F2478(ctx, base);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x8221590c
	if (ctx.cr6.eq) goto loc_8221590C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// ble cr6,0x8221591c
	if (!ctx.cr6.gt) goto loc_8221591C;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bgt cr6,0x8221591c
	if (ctx.cr6.gt) goto loc_8221591C;
loc_8221590C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,200(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82239400
	ctx.lr = 0x8221591C;
	sub_82239400(ctx, base);
loc_8221591C:
	// addi r30,r30,72
	ctx.r30.s64 = ctx.r30.s64 + 72;
	// cmpwi cr6,r30,360
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 360, ctx.xer);
	// blt cr6,0x822158cc
	if (ctx.cr6.lt) goto loc_822158CC;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
loc_82215930:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821f2478
	ctx.lr = 0x82215938;
	sub_821F2478(ctx, base);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8221596c
	if (ctx.cr6.eq) goto loc_8221596C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821f2478
	ctx.lr = 0x82215950;
	sub_821F2478(ctx, base);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// addi r10,r11,-3
	ctx.r10.s64 = ctx.r11.s64 + -3;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r29,r9,27,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
loc_8221596C:
	// addi r30,r30,72
	ctx.r30.s64 = ctx.r30.s64 + 72;
	// cmpwi cr6,r30,360
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 360, ctx.xer);
	// blt cr6,0x82215930
	if (ctx.cr6.lt) goto loc_82215930;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822159ac
	if (ctx.cr6.eq) goto loc_822159AC;
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233198
	ctx.lr = 0x82215994;
	sub_82233198(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233c50
	ctx.lr = 0x822159A4;
	sub_82233C50(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
loc_822159AC:
	// li r11,3
	ctx.r11.s64 = 3;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822159C0:
	// bl 0x82170cb0
	ctx.lr = 0x822159C4;
	sub_82170CB0(ctx, base);
	// lwz r3,888(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 888);
	// bl 0x821a79f8
	ctx.lr = 0x822159CC;
	sub_821A79F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
	// bl 0x82170cb0
	ctx.lr = 0x822159D8;
	sub_82170CB0(ctx, base);
	// lwz r11,864(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 864);
	// lwz r10,256(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 256);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x822157c0
	if (ctx.cr6.gt) goto loc_822157C0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8221669c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8221669C;
	// bdzf 4*cr6+eq,0x822166c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822166C0;
	// bdzf 4*cr6+eq,0x822166dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822166DC;
	// bdzf 4*cr6+eq,0x822166f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822166F0;
	// bdzf 4*cr6+eq,0x82216704
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82216704;
	// bdzf 4*cr6+eq,0x82216720
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82216720;
	// bne cr6,0x8221673c
	if (!ctx.cr6.eq) goto loc_8221673C;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82216670
	if (ctx.cr6.eq) goto loc_82216670;
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// lbz r11,9(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cmplwi cr6,r11,153
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 153, ctx.xer);
	// bgt cr6,0x82216670
	if (ctx.cr6.gt) goto loc_82216670;
	// lis r12,-32223
	ctx.r12.s64 = -2111766528;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,23124
	ctx.r12.s64 = ctx.r12.s64 + 23124;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82215CBC;
	case 1:
		goto loc_82216670;
	case 2:
		goto loc_8221611C;
	case 3:
		goto loc_82216670;
	case 4:
		goto loc_82216670;
	case 5:
		goto loc_82216200;
	case 6:
		goto loc_82216670;
	case 7:
		goto loc_82216670;
	case 8:
		goto loc_82215CF0;
	case 9:
		goto loc_82215CF0;
	case 10:
		goto loc_82216670;
	case 11:
		goto loc_82216670;
	case 12:
		goto loc_82216670;
	case 13:
		goto loc_82216670;
	case 14:
		goto loc_82216670;
	case 15:
		goto loc_82216670;
	case 16:
		goto loc_82216670;
	case 17:
		goto loc_82216670;
	case 18:
		goto loc_82216670;
	case 19:
		goto loc_82216670;
	case 20:
		goto loc_82216670;
	case 21:
		goto loc_82216670;
	case 22:
		goto loc_82216670;
	case 23:
		goto loc_82216670;
	case 24:
		goto loc_82216670;
	case 25:
		goto loc_82216670;
	case 26:
		goto loc_82216670;
	case 27:
		goto loc_82216670;
	case 28:
		goto loc_82216670;
	case 29:
		goto loc_82216670;
	case 30:
		goto loc_82216670;
	case 31:
		goto loc_82215D24;
	case 32:
		goto loc_82215D6C;
	case 33:
		goto loc_82215E1C;
	case 34:
		goto loc_82215DB4;
	case 35:
		goto loc_82215DE8;
	case 36:
		goto loc_82216670;
	case 37:
		goto loc_82215FDC;
	case 38:
		goto loc_82216024;
	case 39:
		goto loc_82215E64;
	case 40:
		goto loc_82215E98;
	case 41:
		goto loc_82215EE0;
	case 42:
		goto loc_82215F5C;
	case 43:
		goto loc_82215F28;
	case 44:
		goto loc_82216670;
	case 45:
		goto loc_82215FA4;
	case 46:
		goto loc_82216604;
	case 47:
		goto loc_82216604;
	case 48:
		goto loc_82216604;
	case 49:
		goto loc_82215DB4;
	case 50:
		goto loc_82216670;
	case 51:
		goto loc_8221606C;
	case 52:
		goto loc_822160A0;
	case 53:
		goto loc_82216604;
	case 54:
		goto loc_822160E8;
	case 55:
		goto loc_82216670;
	case 56:
		goto loc_82216248;
	case 57:
		goto loc_82216150;
	case 58:
		goto loc_82216198;
	case 59:
		goto loc_822161CC;
	case 60:
		goto loc_822161CC;
	case 61:
		goto loc_82216604;
	case 62:
		goto loc_822160E8;
	case 63:
		goto loc_82216670;
	case 64:
		goto loc_82216670;
	case 65:
		goto loc_82216670;
	case 66:
		goto loc_82216670;
	case 67:
		goto loc_82216670;
	case 68:
		goto loc_82216670;
	case 69:
		goto loc_82216670;
	case 70:
		goto loc_82216670;
	case 71:
		goto loc_82216670;
	case 72:
		goto loc_82216670;
	case 73:
		goto loc_82215CBC;
	case 74:
		goto loc_82215F28;
	case 75:
		goto loc_82215CBC;
	case 76:
		goto loc_82216604;
	case 77:
		goto loc_82216604;
	case 78:
		goto loc_82216290;
	case 79:
		goto loc_82216604;
	case 80:
		goto loc_82216604;
	case 81:
		goto loc_82216604;
	case 82:
		goto loc_82216670;
	case 83:
		goto loc_822162C4;
	case 84:
		goto loc_82216670;
	case 85:
		goto loc_82216670;
	case 86:
		goto loc_82216670;
	case 87:
		goto loc_82216670;
	case 88:
		goto loc_82216670;
	case 89:
		goto loc_82216670;
	case 90:
		goto loc_8221632C;
	case 91:
		goto loc_82216670;
	case 92:
		goto loc_822163F0;
	case 93:
		goto loc_822162F8;
	case 94:
		goto loc_82216360;
	case 95:
		goto loc_82216360;
	case 96:
		goto loc_822163A8;
	case 97:
		goto loc_82216670;
	case 98:
		goto loc_82216440;
	case 99:
		goto loc_822162F8;
	case 100:
		goto loc_822162F8;
	case 101:
		goto loc_822162F8;
	case 102:
		goto loc_82216360;
	case 103:
		goto loc_82216488;
	case 104:
		goto loc_82215F28;
	case 105:
		goto loc_822162F8;
	case 106:
		goto loc_822162F8;
	case 107:
		goto loc_822162F8;
	case 108:
		goto loc_82216670;
	case 109:
		goto loc_82216670;
	case 110:
		goto loc_82216670;
	case 111:
		goto loc_82216670;
	case 112:
		goto loc_822162F8;
	case 113:
		goto loc_822162F8;
	case 114:
		goto loc_822162F8;
	case 115:
		goto loc_8221654C;
	case 116:
		goto loc_822162F8;
	case 117:
		goto loc_822162F8;
	case 118:
		goto loc_822162F8;
	case 119:
		goto loc_822164D0;
	case 120:
		goto loc_822162F8;
	case 121:
		goto loc_82216504;
	case 122:
		goto loc_82216670;
	case 123:
		goto loc_822162F8;
	case 124:
		goto loc_8221659C;
	case 125:
		goto loc_82216670;
	case 126:
		goto loc_822162F8;
	case 127:
		goto loc_822162F8;
	case 128:
		goto loc_822165D0;
	case 129:
		goto loc_82216670;
	case 130:
		goto loc_82216360;
	case 131:
		goto loc_82216360;
	case 132:
		goto loc_82216670;
	case 133:
		goto loc_82216670;
	case 134:
		goto loc_82216670;
	case 135:
		goto loc_82216670;
	case 136:
		goto loc_82216670;
	case 137:
		goto loc_82216670;
	case 138:
		goto loc_82216670;
	case 139:
		goto loc_82216670;
	case 140:
		goto loc_82216670;
	case 141:
		goto loc_82216670;
	case 142:
		goto loc_822162F8;
	case 143:
		goto loc_82216670;
	case 144:
		goto loc_82216670;
	case 145:
		goto loc_82216670;
	case 146:
		goto loc_82216670;
	case 147:
		goto loc_82216670;
	case 148:
		goto loc_82216604;
	case 149:
		goto loc_822161CC;
	case 150:
		goto loc_822161CC;
	case 151:
		goto loc_82216290;
	case 152:
		goto loc_82216670;
	case 153:
		goto loc_82216604;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82215CBC:
	// li r6,208
	ctx.r6.s64 = 208;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215CD0;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x821b0a40
	ctx.lr = 0x82215CEC;
	sub_821B0A40(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82215CF0:
	// li r6,160
	ctx.r6.s64 = 160;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215D04;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x822172e8
	ctx.lr = 0x82215D20;
	sub_822172E8(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82215D24:
	// li r6,160
	ctx.r6.s64 = 160;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215D38;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821a5050
	ctx.lr = 0x82215D58;
	sub_821A5050(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27108
	ctx.r10.s64 = ctx.r11.s64 + 27108;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82215D6C:
	// li r6,928
	ctx.r6.s64 = 928;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215D80;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82217000
	ctx.lr = 0x82215DA0;
	sub_82217000(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,28412
	ctx.r10.s64 = ctx.r11.s64 + 28412;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82215DB4:
	// li r6,640
	ctx.r6.s64 = 640;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215DC8;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82217360
	ctx.lr = 0x82215DE4;
	sub_82217360(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82215DE8:
	// li r6,192
	ctx.r6.s64 = 192;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215DFC;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82217430
	ctx.lr = 0x82215E18;
	sub_82217430(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82215E1C:
	// li r6,272
	ctx.r6.s64 = 272;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215E30;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821b0a40
	ctx.lr = 0x82215E50;
	sub_821B0A40(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27188
	ctx.r10.s64 = ctx.r11.s64 + 27188;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82215E64:
	// li r6,192
	ctx.r6.s64 = 192;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215E78;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82217500
	ctx.lr = 0x82215E94;
	sub_82217500(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82215E98:
	// li r6,160
	ctx.r6.s64 = 160;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215EAC;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821a5050
	ctx.lr = 0x82215ECC;
	sub_821A5050(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,28684
	ctx.r10.s64 = ctx.r11.s64 + 28684;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82215EE0:
	// li r6,160
	ctx.r6.s64 = 160;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215EF4;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821a5050
	ctx.lr = 0x82215F14;
	sub_821A5050(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27252
	ctx.r10.s64 = ctx.r11.s64 + 27252;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82215F28:
	// li r6,192
	ctx.r6.s64 = 192;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215F3C;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x822175d0
	ctx.lr = 0x82215F58;
	sub_822175D0(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82215F5C:
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215F70;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82215F90;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27332
	ctx.r10.s64 = ctx.r11.s64 + 27332;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82215FA4:
	// lis r6,2
	ctx.r6.s64 = 131072;
	// li r5,16
	ctx.r5.s64 = 16;
	// ori r6,r6,33952
	ctx.r6.u64 = ctx.r6.u64 | 33952;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215FBC;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x821f7a58
	ctx.lr = 0x82215FD8;
	sub_821F7A58(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82215FDC:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82215FF0;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216010;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27444
	ctx.r10.s64 = ctx.r11.s64 + 27444;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82216024:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216038;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216058;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27500
	ctx.r10.s64 = ctx.r11.s64 + 27500;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_8221606C:
	// li r6,192
	ctx.r6.s64 = 192;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216080;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x822176b8
	ctx.lr = 0x8221609C;
	sub_822176B8(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_822160A0:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822160B4;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x822160D4;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27556
	ctx.r10.s64 = ctx.r11.s64 + 27556;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_822160E8:
	// li r6,192
	ctx.r6.s64 = 192;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822160FC;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x821f50f0
	ctx.lr = 0x82216118;
	sub_821F50F0(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_8221611C:
	// li r6,240
	ctx.r6.s64 = 240;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216130;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82217788
	ctx.lr = 0x8221614C;
	sub_82217788(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82216150:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216164;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216184;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27612
	ctx.r10.s64 = ctx.r11.s64 + 27612;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82216198:
	// li r6,192
	ctx.r6.s64 = 192;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822161AC;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x821aa938
	ctx.lr = 0x822161C8;
	sub_821AA938(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_822161CC:
	// li r6,3328
	ctx.r6.s64 = 3328;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822161E0;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x822170c0
	ctx.lr = 0x822161FC;
	sub_822170C0(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82216200:
	// li r6,928
	ctx.r6.s64 = 928;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216214;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82217000
	ctx.lr = 0x82216234;
	sub_82217000(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,28980
	ctx.r10.s64 = ctx.r11.s64 + 28980;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82216248:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x8221625C;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x8221627C;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27668
	ctx.r10.s64 = ctx.r11.s64 + 27668;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82216290:
	// li r6,1136
	ctx.r6.s64 = 1136;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822162A4;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82216db8
	ctx.lr = 0x822162C0;
	sub_82216DB8(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_822162C4:
	// li r6,176
	ctx.r6.s64 = 176;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822162D8;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x821a54e8
	ctx.lr = 0x822162F4;
	sub_821A54E8(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_822162F8:
	// li r6,640
	ctx.r6.s64 = 640;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x8221630C;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82216f60
	ctx.lr = 0x82216328;
	sub_82216F60(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_8221632C:
	// li r6,448
	ctx.r6.s64 = 448;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216340;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82216fb0
	ctx.lr = 0x8221635C;
	sub_82216FB0(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82216360:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216374;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216394;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27840
	ctx.r10.s64 = ctx.r11.s64 + 27840;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_822163A8:
	// li r6,1088
	ctx.r6.s64 = 1088;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822163BC;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82217000
	ctx.lr = 0x822163DC;
	sub_82217000(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,29092
	ctx.r10.s64 = ctx.r11.s64 + 29092;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_822163F0:
	// li r6,416
	ctx.r6.s64 = 416;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216404;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216424;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,27896
	ctx.r9.s64 = ctx.r11.s64 + 27896;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r10,116(r30)
	REX_STORE_U32(ctx.r30.u32 + 116, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82216440:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216454;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216474;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27952
	ctx.r10.s64 = ctx.r11.s64 + 27952;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_82216488:
	// li r6,128
	ctx.r6.s64 = 128;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x8221649C;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x822164BC;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,28008
	ctx.r10.s64 = ctx.r11.s64 + 28008;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_822164D0:
	// li r6,656
	ctx.r6.s64 = 656;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822164E4;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x822178d0
	ctx.lr = 0x82216500;
	sub_822178D0(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82216504:
	// li r6,1040
	ctx.r6.s64 = 1040;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216518;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82217000
	ctx.lr = 0x82216538;
	sub_82217000(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,29260
	ctx.r10.s64 = ctx.r11.s64 + 29260;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_8221654C:
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216560;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216580;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,28064
	ctx.r9.s64 = ctx.r11.s64 + 28064;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// stw r10,116(r30)
	REX_STORE_U32(ctx.r30.u32 + 116, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_8221659C:
	// li r6,640
	ctx.r6.s64 = 640;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822165B0;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82217938
	ctx.lr = 0x822165CC;
	sub_82217938(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_822165D0:
	// li r6,640
	ctx.r6.s64 = 640;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x822165E4;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// bl 0x82217990
	ctx.lr = 0x82216600;
	sub_82217990(ctx, base);
	// b 0x82216650
	goto loc_82216650;
loc_82216604:
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r31,6660
	ctx.r3.s64 = ctx.r31.s64 + 6660;
	// bl 0x82231b88
	ctx.lr = 0x82216618;
	sub_82231B88(ctx, base);
	// lwz r11,7112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221664c
	if (ctx.cr6.eq) goto loc_8221664C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ed9e8
	ctx.lr = 0x82216638;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,27388
	ctx.r10.s64 = ctx.r11.s64 + 27388;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82216650
	goto loc_82216650;
loc_8221664C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82216650:
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82217a48
	ctx.lr = 0x8221665C;
	sub_82217A48(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82216670;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82216670:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822113a0
	ctx.lr = 0x82216678;
	sub_822113A0(ctx, base);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r10,1892(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1892);
	// cmpwi cr6,r10,83
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 83, ctx.xer);
	// beq cr6,0x82216744
	if (ctx.cr6.eq) goto loc_82216744;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_8221669C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82211610
	ctx.lr = 0x822166A4;
	sub_82211610(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82211b28
	ctx.lr = 0x822166AC;
	sub_82211B28(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822166C0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82211810
	ctx.lr = 0x822166C8;
	sub_82211810(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822166DC:
	// li r11,7
	ctx.r11.s64 = 7;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822166F0:
	// li r11,8
	ctx.r11.s64 = 8;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82216704:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220cfe0
	ctx.lr = 0x8221670C;
	sub_8220CFE0(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82216720:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82215378
	ctx.lr = 0x82216728;
	sub_82215378(ctx, base);
	// li r11,10
	ctx.r11.s64 = 10;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_8221673C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82212108
	ctx.lr = 0x82216744;
	sub_82212108(ctx, base);
loc_82216744:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220b140
	ctx.lr = 0x82216750;
	sub_8220B140(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8220b140
	ctx.lr = 0x82216758;
	sub_8220B140(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8220b140
	ctx.lr = 0x82216760;
	sub_8220B140(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x8220b140
	ctx.lr = 0x82216768;
	sub_8220B140(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x8220b140
	ctx.lr = 0x82216770;
	sub_8220B140(ctx, base);
	// lwz r10,212(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// lwz r11,1940(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 1940);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,1940(r10)
	REX_STORE_U32(ctx.r10.u32 + 1940, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82216794:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220bac8
	ctx.lr = 0x8221679C;
	sub_8220BAC8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220bc10
	ctx.lr = 0x822167AC;
	sub_8220BC10(ctx, base);
	// li r11,12
	ctx.r11.s64 = 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822167C0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82214828
	ctx.lr = 0x822167C8;
	sub_82214828(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822168c0
	if (ctx.cr6.eq) goto loc_822168C0;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822167ec
	if (ctx.cr6.eq) goto loc_822167EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822167EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822167EC:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82216810
	if (ctx.cr6.eq) goto loc_82216810;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82216808;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82216818
	if (!ctx.cr6.eq) goto loc_82216818;
loc_82216810:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220bfe0
	ctx.lr = 0x82216818;
	sub_8220BFE0(ctx, base);
loc_82216818:
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// rlwinm r10,r11,28,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822168c0
	if (ctx.cr6.eq) goto loc_822168C0;
	// lwz r10,7080(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7080);
	// addi r11,r31,7076
	ctx.r11.s64 = ctx.r31.s64 + 7076;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82216858
	if (ctx.cr6.eq) goto loc_82216858;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82216858
	if (ctx.cr6.eq) goto loc_82216858;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216858
	if (ctx.cr6.eq) goto loc_82216858;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8221685c
	goto loc_8221685C;
loc_82216858:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221685C:
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x82186620
	ctx.lr = 0x82216864;
	sub_82186620(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x822168b8
	if (!ctx.cr6.eq) goto loc_822168B8;
	// addi r3,r31,316
	ctx.r3.s64 = ctx.r31.s64 + 316;
	// bl 0x8243fa70
	ctx.lr = 0x82216874;
	sub_8243FA70(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822168b8
	if (ctx.cr6.eq) goto loc_822168B8;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stw r11,180(r3)
	REX_STORE_U32(ctx.r3.u32 + 180, ctx.r11.u32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822168ac
	if (ctx.cr6.eq) goto loc_822168AC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822168A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822168b8
	if (!ctx.cr6.eq) goto loc_822168B8;
loc_822168AC:
	// addi r4,r31,96
	ctx.r4.s64 = ctx.r31.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82171a10
	ctx.lr = 0x822168B8;
	sub_82171A10(ctx, base);
loc_822168B8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220c3a0
	ctx.lr = 0x822168C0;
	sub_8220C3A0(ctx, base);
loc_822168C0:
	// addi r3,r31,340
	ctx.r3.s64 = ctx.r31.s64 + 340;
	// bl 0x8243fa70
	ctx.lr = 0x822168C8;
	sub_8243FA70(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
	// bl 0x8220a828
	ctx.lr = 0x822168D4;
	sub_8220A828(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822157c0
	if (!ctx.cr6.eq) goto loc_822157C0;
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233160
	ctx.lr = 0x822168E4;
	sub_82233160(ctx, base);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82233c18
	ctx.lr = 0x822168F4;
	sub_82233C18(ctx, base);
	// lwz r10,152(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// lwz r9,640(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 640);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x822157c0
	if (ctx.cr6.eq) goto loc_822157C0;
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x822157c0
	if (!ctx.cr6.gt) goto loc_822157C0;
	// addi r27,r31,6948
	ctx.r27.s64 = ctx.r31.s64 + 6948;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8221691C:
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216930
	if (ctx.cr6.eq) goto loc_82216930;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216934
	goto loc_82216934;
loc_82216930:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216934:
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r11,17(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 17);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82216a08
	if (ctx.cr6.gt) goto loc_82216A08;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82216990
	if (ctx.cr6.eq) goto loc_82216990;
	// bdz 0x82216990
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82216990;
	// bdz 0x82216960
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82216960;
loc_82216960:
	// lwz r3,212(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// bl 0x82233160
	ctx.lr = 0x82216968;
	sub_82233160(ctx, base);
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82233c18
	ctx.lr = 0x82216978;
	sub_82233C18(ctx, base);
	// lwz r10,152(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// lwz r9,908(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 908);
	// rlwinm r8,r9,0,20,20
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82216a08
	if (ctx.cr6.eq) goto loc_82216A08;
	// b 0x822169b8
	goto loc_822169B8;
loc_82216990:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220ae90
	ctx.lr = 0x82216998;
	sub_8220AE90(ctx, base);
	// cmpwi cr6,r3,22
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 22, ctx.xer);
	// bne cr6,0x822169b8
	if (!ctx.cr6.eq) goto loc_822169B8;
	// bl 0x822cd3c8
	ctx.lr = 0x822169A4;
	sub_822CD3C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822169b8
	if (!ctx.cr6.eq) goto loc_822169B8;
	// bl 0x822cd6f8
	ctx.lr = 0x822169B0;
	sub_822CD6F8(ctx, base);
	// cmpwi cr6,r3,16
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 16, ctx.xer);
	// bne cr6,0x82216a08
	if (!ctx.cr6.eq) goto loc_82216A08;
loc_822169B8:
	// lhz r10,18(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 18);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822169f4
	if (ctx.cr6.eq) goto loc_822169F4;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r9,24(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x822169f4
	if (ctx.cr6.lt) goto loc_822169F4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r11,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r11.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82215030
	ctx.lr = 0x822169F4;
	sub_82215030(ctx, base);
loc_822169F4:
	// lhz r11,18(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 18);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216a08
	if (ctx.cr6.eq) goto loc_82216A08;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r11,18(r30)
	REX_STORE_U16(ctx.r30.u32 + 18, ctx.r11.u16);
loc_82216A08:
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r29,r29,32
	ctx.r29.s64 = ctx.r29.s64 + 32;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8221691c
	if (ctx.cr6.lt) goto loc_8221691C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82216A28:
	// bl 0x82170cb0
	ctx.lr = 0x82216A2C;
	sub_82170CB0(ctx, base);
	// lwz r3,848(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 848);
	// bl 0x82223748
	ctx.lr = 0x82216A34;
	sub_82223748(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82216a6c
	if (ctx.cr6.eq) goto loc_82216A6C;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82216a6c
	if (!ctx.cr6.eq) goto loc_82216A6C;
	// lwz r11,212(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 212);
	// lwz r10,1936(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1936);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bgt cr6,0x82216a68
	if (ctx.cr6.gt) goto loc_82216A68;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// b 0x82216a6c
	goto loc_82216A6C;
loc_82216A68:
	// stw r28,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r28.u32);
loc_82216A6C:
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82216d24
	if (ctx.cr6.gt) goto loc_82216D24;
	// addi r30,r31,340
	ctx.r30.s64 = ctx.r31.s64 + 340;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8243fa70
	ctx.lr = 0x82216A84;
	sub_8243FA70(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82216a98
	if (ctx.cr6.eq) goto loc_82216A98;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8243fa70
	ctx.lr = 0x82216A94;
	sub_8243FA70(ctx, base);
	// stw r28,24776(r3)
	REX_STORE_U32(ctx.r3.u32 + 24776, ctx.r28.u32);
loc_82216A98:
	// lwz r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82216ae0
	if (!ctx.cr6.gt) goto loc_82216AE0;
loc_82216AA8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220feb8
	ctx.lr = 0x82216AB0;
	sub_8220FEB8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82216ad0
	if (ctx.cr6.eq) goto loc_82216AD0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8220feb8
	ctx.lr = 0x82216AC0;
	sub_8220FEB8(ctx, base);
	// lbz r11,1158(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1158);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82216ad0
	if (!ctx.cr6.eq) goto loc_82216AD0;
	// stb r28,1158(r3)
	REX_STORE_U8(ctx.r3.u32 + 1158, ctx.r28.u8);
loc_82216AD0:
	// lwz r11,368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82216aa8
	if (ctx.cr6.lt) goto loc_82216AA8;
loc_82216AE0:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82216b2c
	if (!ctx.cr6.eq) goto loc_82216B2C;
	// addic. r30,r31,396
	ctx.xer.ca = ctx.r31.u32 > 4294966899;
	ctx.r30.s64 = ctx.r31.s64 + 396;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82216b2c
	if (ctx.cr0.eq) goto loc_82216B2C;
	// li r29,5
	ctx.r29.s64 = 5;
loc_82216AF8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8243fa70
	ctx.lr = 0x82216B00;
	sub_8243FA70(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82216b20
	if (ctx.cr6.eq) goto loc_82216B20;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8243fa70
	ctx.lr = 0x82216B10;
	sub_8243FA70(ctx, base);
	// lwz r11,1280(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1280);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82216b20
	if (!ctx.cr6.eq) goto loc_82216B20;
	// stw r28,1280(r3)
	REX_STORE_U32(ctx.r3.u32 + 1280, ctx.r28.u32);
loc_82216B20:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,24
	ctx.r30.s64 = ctx.r30.s64 + 24;
	// bne 0x82216af8
	if (!ctx.cr0.eq) goto loc_82216AF8;
loc_82216B2C:
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82216b88
	if (!ctx.cr6.eq) goto loc_82216B88;
	// lwz r11,7064(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7064);
	// addi r30,r31,7060
	ctx.r30.s64 = ctx.r31.s64 + 7060;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216b50
	if (ctx.cr6.eq) goto loc_82216B50;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216b54
	goto loc_82216B54;
loc_82216B50:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216B54:
	// addi r3,r11,376
	ctx.r3.s64 = ctx.r11.s64 + 376;
	// bl 0x8243fa70
	ctx.lr = 0x82216B5C;
	sub_8243FA70(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82216b88
	if (ctx.cr6.eq) goto loc_82216B88;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216b78
	if (ctx.cr6.eq) goto loc_82216B78;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216b7c
	goto loc_82216B7C;
loc_82216B78:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216B7C:
	// addi r3,r11,376
	ctx.r3.s64 = ctx.r11.s64 + 376;
	// bl 0x8243fa70
	ctx.lr = 0x82216B84;
	sub_8243FA70(ctx, base);
	// stw r28,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r28.u32);
loc_82216B88:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82216ba4
	if (ctx.cr6.eq) goto loc_82216BA4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82216BA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82216BA4:
	// lwz r11,7064(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7064);
	// addi r10,r31,7060
	ctx.r10.s64 = ctx.r31.s64 + 7060;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216bbc
	if (ctx.cr6.eq) goto loc_82216BBC;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216bc0
	goto loc_82216BC0;
loc_82216BBC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216BC0:
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82216bf0
	if (ctx.cr6.eq) goto loc_82216BF0;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216be0
	if (ctx.cr6.eq) goto loc_82216BE0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216be4
	goto loc_82216BE4;
loc_82216BE0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216BE4:
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822157c0
	if (!ctx.cr6.eq) goto loc_822157C0;
loc_82216BF0:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216c04
	if (ctx.cr6.eq) goto loc_82216C04;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216c08
	goto loc_82216C08;
loc_82216C04:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216C08:
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82216c38
	if (ctx.cr6.eq) goto loc_82216C38;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216c28
	if (ctx.cr6.eq) goto loc_82216C28;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216c2c
	goto loc_82216C2C;
loc_82216C28:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216C2C:
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822157c0
	if (!ctx.cr6.eq) goto loc_822157C0;
loc_82216C38:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216c4c
	if (ctx.cr6.eq) goto loc_82216C4C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216c50
	goto loc_82216C50;
loc_82216C4C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216C50:
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82216c80
	if (ctx.cr6.eq) goto loc_82216C80;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216c70
	if (ctx.cr6.eq) goto loc_82216C70;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216c74
	goto loc_82216C74;
loc_82216C70:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216C74:
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822157c0
	if (!ctx.cr6.eq) goto loc_822157C0;
loc_82216C80:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216c94
	if (ctx.cr6.eq) goto loc_82216C94;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216c98
	goto loc_82216C98;
loc_82216C94:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216C98:
	// lwz r11,244(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 244);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82216cc8
	if (ctx.cr6.eq) goto loc_82216CC8;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216cb8
	if (ctx.cr6.eq) goto loc_82216CB8;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216cbc
	goto loc_82216CBC;
loc_82216CB8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216CBC:
	// lwz r11,244(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 244);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822157c0
	if (!ctx.cr6.eq) goto loc_822157C0;
loc_82216CC8:
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216cdc
	if (ctx.cr6.eq) goto loc_82216CDC;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216ce0
	goto loc_82216CE0;
loc_82216CDC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216CE0:
	// lwz r11,316(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 316);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82216d10
	if (ctx.cr6.eq) goto loc_82216D10;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82216d00
	if (ctx.cr6.eq) goto loc_82216D00;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82216d04
	goto loc_82216D04;
loc_82216D00:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82216D04:
	// lwz r11,316(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 316);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822157c0
	if (!ctx.cr6.eq) goto loc_822157C0;
loc_82216D10:
	// li r11,14
	ctx.r11.s64 = 14;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82216D24:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82216D38:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82297EA8) {
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
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82297ee4
	if (ctx.cr6.eq) goto loc_82297EE4;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82297ee8
	if (ctx.cr6.eq) goto loc_82297EE8;
loc_82297EE4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82297EE8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82297f0c
	if (ctx.cr6.eq) goto loc_82297F0C;
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
	// bne cr6,0x82297f10
	if (!ctx.cr6.eq) goto loc_82297F10;
loc_82297F0C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82297F10:
	// lwz r3,860(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 860);
	// bl 0x821c81c0
	ctx.lr = 0x82297F18;
	sub_821C81C0(ctx, base);
	// bl 0x821dad90
	ctx.lr = 0x82297F1C;
	sub_821DAD90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82297c48
	ctx.lr = 0x82297F28;
	sub_82297C48(ctx, base);
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

DEFINE_REX_FUNC(sub_8229D060) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,397
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 397, ctx.xer);
	// beq cr6,0x8229d090
	if (ctx.cr6.eq) goto loc_8229D090;
loc_8229D070:
	// cmplwi cr6,r11,349
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 349, ctx.xer);
	// blt cr6,0x8229d084
	if (ctx.cr6.lt) goto loc_8229D084;
	// rlwinm r11,r11,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229d098
	if (ctx.cr6.eq) goto loc_8229D098;
loc_8229D084:
	// lwzu r11,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// cmplwi cr6,r11,397
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 397, ctx.xer);
	// bne cr6,0x8229d070
	if (!ctx.cr6.eq) goto loc_8229D070;
loc_8229D090:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8229D098:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822A3508) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x822A3510;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r11,38
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 38, ctx.xer);
	// bge cr6,0x822a3538
	if (!ctx.cr6.lt) goto loc_822A3538;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// mulli r10,r11,3816
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(3816));
	// addi r11,r9,-12456
	ctx.r11.s64 = ctx.r9.s64 + -12456;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x822a353c
	goto loc_822A353C;
loc_822A3538:
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
loc_822A353C:
	// lis r11,-13108
	ctx.r11.s64 = -859045888;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r3,1936
	ctx.r30.s64 = ctx.r3.s64 + 1936;
	// ori r8,r11,52429
	ctx.r8.u64 = ctx.r11.u64 | 52429;
	// mulhwu r7,r9,r8
	ctx.r7.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// rlwinm r11,r7,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r28,r5,r9
	ctx.r28.u64 = ctx.r9.u64 - ctx.r5.u64;
	// bl 0x8238e4f8
	ctx.lr = 0x822A3568;
	sub_8238E4F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822a366c
	if (ctx.cr6.eq) goto loc_822A366C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a366c
	if (ctx.cr6.eq) goto loc_822A366C;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r29,r11,0,16,23
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFF00;
	// rlwinm r26,r10,0,16,23
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFF00;
	// rlwinm r29,r29,0,20,18
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// rlwinm r26,r26,0,20,18
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// bl 0x8238e3b8
	ctx.lr = 0x822A3598;
	sub_8238E3B8(ctx, base);
	// cmplw cr6,r29,r26
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x822a35b0
	if (!ctx.cr6.eq) goto loc_822A35B0;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x822a366c
	if (ctx.cr6.eq) goto loc_822A366C;
loc_822A35B0:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822a35cc
	if (ctx.cr6.eq) goto loc_822A35CC;
	// lwz r10,100(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822a35cc
	if (ctx.cr6.eq) goto loc_822A35CC;
	// li r11,1
	ctx.r11.s64 = 1;
loc_822A35CC:
	// lwz r10,3736(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3736);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822a35f0
	if (!ctx.cr6.eq) goto loc_822A35F0;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r9,3740(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3740);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x822a35f0
	if (!ctx.cr6.eq) goto loc_822A35F0;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x822a3630
	goto loc_822A3630;
loc_822A35F0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822a3630
	if (!ctx.cr6.eq) goto loc_822A3630;
	// addi r10,r28,774
	ctx.r10.s64 = ctx.r28.s64 + 774;
	// addi r9,r28,814
	ctx.r9.s64 = ctx.r28.s64 + 814;
	// addi r8,r28,854
	ctx.r8.s64 = ctx.r28.s64 + 854;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r28,894
	ctx.r6.s64 = ctx.r28.s64 + 894;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r7,r31
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r29.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stwx r10,r5,r31
	REX_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r10.u32);
	// stwx r27,r4,r31
	REX_STORE_U32(ctx.r4.u32 + ctx.r31.u32, ctx.r27.u32);
	// lwz r9,12(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stwx r9,r3,r31
	REX_STORE_U32(ctx.r3.u32 + ctx.r31.u32, ctx.r9.u32);
loc_822A3630:
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r27,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// bne cr6,0x822a366c
	if (!ctx.cr6.eq) goto loc_822A366C;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r29,3736(r31)
	REX_STORE_U32(ctx.r31.u32 + 3736, ctx.r29.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r11,39
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 39, ctx.xer);
	// stw r10,3740(r31)
	REX_STORE_U32(ctx.r31.u32 + 3740, ctx.r10.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// blt cr6,0x822a3668
	if (ctx.cr6.lt) goto loc_822A3668;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_822A3668:
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_822A366C:
	// lbz r11,7(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 7);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r9,r11,6
	ctx.r9.s64 = ctx.r11.s64 + 6;
	// addi r8,r11,262
	ctx.r8.s64 = ctx.r11.s64 + 262;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,518
	ctx.r5.s64 = ctx.r11.s64 + 518;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r7,r31
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stwx r3,r6,r31
	REX_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r3.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stwx r11,r4,r31
	REX_STORE_U32(ctx.r4.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// blt cr6,0x822a36b4
	if (ctx.cr6.lt) goto loc_822A36B4;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_822A36B4:
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B3810) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822B3998) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x822B39A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2924(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2924);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822b3a44
	if (ctx.cr6.eq) goto loc_822B3A44;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// addi r27,r11,-7856
	ctx.r27.s64 = ctx.r11.s64 + -7856;
loc_822B39C4:
	// lwz r11,2924(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2924);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r31,r11,64
	ctx.r31.s64 = ctx.r11.s64 + 64;
	// lwz r11,68(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x822b3a38
	if (!ctx.cr6.gt) goto loc_822B3A38;
	// lwz r3,3120(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 3120);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822b3a08
	if (ctx.cr6.eq) goto loc_822B3A08;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,3
	ctx.r6.s64 = 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,17
	ctx.r5.s64 = 17;
	// lwzx r4,r10,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	// bl 0x8222d7c0
	ctx.lr = 0x822B3A08;
	sub_8222D7C0(ctx, base);
loc_822B3A08:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// bge 0x822b3a1c
	if (!ctx.cr0.lt) goto loc_822B3A1C;
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
loc_822B3A1C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// beq cr6,0x822b3a38
	if (ctx.cr6.eq) goto loc_822B3A38;
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
loc_822B3A38:
	// addi r29,r29,80
	ctx.r29.s64 = ctx.r29.s64 + 80;
	// cmpwi cr6,r29,400
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 400, ctx.xer);
	// blt cr6,0x822b39c4
	if (ctx.cr6.lt) goto loc_822B39C4;
loc_822B3A44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822B6CB8) {
	REX_FUNC_PROLOGUE();
	// fsqrts f0,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(sqrt(ctx.f2.f64)));
	// fdivs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822B6D48) {
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
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,80(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lfs f1,2880(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f1.f64 = double(temp.f32);
	// blt cr6,0x822b6e08
	if (ctx.cr6.lt) goto loc_822B6E08;
	// li r11,0
	ctx.r11.s64 = 0;
	// ble cr6,0x822b6e68
	if (!ctx.cr6.gt) goto loc_822B6E68;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,88(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f8,-2856(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2856);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,24784(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24784);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,7552(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 7552);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,8152(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8152);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,-2852(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -2852);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,8148(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8148);
	ctx.f12.f64 = double(temp.f32);
loc_822B6DB0:
	// lfs f7,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// fsubs f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f0.f64));
	// lfs f6,96(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fmuls f3,f6,f11
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f2,f5,f10
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f10.f64));
	// fmsubs f1,f4,f0,f7
	ctx.f1.f64 = double(float(std::fma(ctx.f4.f64, ctx.f0.f64, -ctx.f7.f64)));
	// fmsubs f5,f7,f0,f3
	ctx.f5.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, -ctx.f3.f64)));
	// fmadds f4,f2,f13,f0
	ctx.f4.f64 = double(float(std::fma(ctx.f2.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f4,88(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// fmadds f3,f1,f13,f7
	ctx.f3.f64 = double(float(std::fma(ctx.f1.f64, ctx.f13.f64, ctx.f7.f64)));
	// stfs f3,92(r3)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// fmadds f2,f5,f13,f6
	ctx.f2.f64 = double(float(std::fma(ctx.f5.f64, ctx.f13.f64, ctx.f6.f64)));
	// stfs f2,96(r3)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lwz r10,80(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// fadds f1,f4,f9
	ctx.f1.f64 = double(float(ctx.f4.f64 + ctx.f9.f64));
	// fmr f0,f4
	ctx.f0.f64 = ctx.f4.f64;
	// fmuls f1,f1,f8
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// blt cr6,0x822b6db0
	if (ctx.cr6.lt) goto loc_822B6DB0;
	// b 0x822b6e68
	goto loc_822B6E68;
loc_822B6E08:
	// neg r10,r10
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// lfs f0,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// divw r9,r11,r10
	ctx.r9.u64 = uint32_t((ctx.r10.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r11.s32 / ctx.r10.s32 : 0);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf. r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822b6e30
	if (!ctx.cr0.eq) goto loc_822B6E30;
	// stfs f0,104(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// bl 0x822b6cc8
	ctx.lr = 0x822B6E28;
	sub_822B6CC8(ctx, base);
	// stfs f1,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// b 0x822b6e68
	goto loc_822B6E68;
loc_822B6E30:
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfs f13,104(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// fsubs f7,f0,f13
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f5,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 / ctx.f6.f64));
	// fmadds f1,f7,f5,f0
	ctx.f1.f64 = double(float(std::fma(ctx.f7.f64, ctx.f5.f64, ctx.f0.f64)));
loc_822B6E68:
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r10,r3
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// cmpwi cr6,r11,1024
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1024, ctx.xer);
	// blt cr6,0x822b6e94
	if (ctx.cr6.lt) goto loc_822B6E94;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
loc_822B6E94:
	// lwz r3,84(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822BE068) {
	REX_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822BE0B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x822BE0C0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,37
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 37, ctx.xer);
	// blt cr6,0x822be0e0
	if (ctx.cr6.lt) goto loc_822BE0E0;
	// li r11,37
	ctx.r11.s64 = 37;
loc_822BE0E0:
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// addi r10,r10,4352
	ctx.r10.s64 = ctx.r10.s64 + 4352;
	// mulli r11,r11,1408
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(1408));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r30,19
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 19, ctx.xer);
	// stw r11,4300(r31)
	REX_STORE_U32(ctx.r31.u32 + 4300, ctx.r11.u32);
	// blt cr6,0x822be104
	if (ctx.cr6.lt) goto loc_822BE104;
	// li r30,19
	ctx.r30.s64 = 19;
loc_822BE104:
	// lis r10,-32140
	ctx.r10.s64 = -2106327040;
	// mulli r29,r30,122
	ctx.r29.s64 = static_cast<int64_t>(ctx.r30.u64 * static_cast<uint64_t>(122));
	// addi r10,r10,2312
	ctx.r10.s64 = ctx.r10.s64 + 2312;
	// addi r3,r11,1000
	ctx.r3.s64 = ctx.r11.s64 + 1000;
	// add r4,r29,r10
	ctx.r4.u64 = ctx.r29.u64 + ctx.r10.u64;
	// li r5,122
	ctx.r5.s64 = 122;
	// bl 0x826a1130
	ctx.lr = 0x822BE120;
	rexcrt_memcpy(ctx, base);
	// bl 0x822d16d8
	ctx.lr = 0x822BE124;
	sub_822D16D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822be158
	if (ctx.cr6.eq) goto loc_822BE158;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822d1b78
	ctx.lr = 0x822BE134;
	sub_822D1B78(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822be158
	if (!ctx.cr6.eq) goto loc_822BE158;
	// lis r10,-32140
	ctx.r10.s64 = -2106327040;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// li r5,122
	ctx.r5.s64 = 122;
	// addi r10,r10,4752
	ctx.r10.s64 = ctx.r10.s64 + 4752;
	// addi r3,r11,1000
	ctx.r3.s64 = ctx.r11.s64 + 1000;
	// add r4,r29,r10
	ctx.r4.u64 = ctx.r29.u64 + ctx.r10.u64;
	// bl 0x826a1130
	ctx.lr = 0x822BE158;
	rexcrt_memcpy(ctx, base);
loc_822BE158:
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r30,1156(r11)
	REX_STORE_U32(ctx.r11.u32 + 1156, ctx.r30.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lhz r10,1060(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 1060);
	// lhz r9,1056(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 1056);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x822be180
	if (ctx.cr6.gt) goto loc_822BE180;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_822BE180:
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stw r10,776(r11)
	REX_STORE_U32(ctx.r11.u32 + 776, ctx.r10.u32);
	// beq cr6,0x822be1a8
	if (ctx.cr6.eq) goto loc_822BE1A8;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lis r10,-32140
	ctx.r10.s64 = -2106327040;
	// li r5,122
	ctx.r5.s64 = 122;
	// addi r3,r11,1000
	ctx.r3.s64 = ctx.r11.s64 + 1000;
	// addi r4,r10,7400
	ctx.r4.s64 = ctx.r10.s64 + 7400;
	// bl 0x826a1130
	ctx.lr = 0x822BE1A8;
	rexcrt_memcpy(ctx, base);
loc_822BE1A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822C7418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a027c
	ctx.lr = 0x822C7420;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,6
	ctx.r11.s64 = 6;
	// li r22,0
	ctx.r22.s64 = 0;
	// addi r10,r3,919
	ctx.r10.s64 = ctx.r3.s64 + 919;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r22,960(r3)
	REX_STORE_U32(ctx.r3.u32 + 960, ctx.r22.u32);
	// lfs f31,2880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// stfs f31,752(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 752, temp.u32);
	// mr r21,r22
	ctx.r21.u64 = ctx.r22.u64;
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822C7464:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x822c7464
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822C7464;
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// stb r22,915(r27)
	REX_STORE_U8(ctx.r27.u32 + 915, ctx.r22.u8);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// addi r28,r11,-8716
	ctx.r28.s64 = ctx.r11.s64 + -8716;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_822C7480:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// beq cr6,0x822c74b4
	if (ctx.cr6.eq) goto loc_822C74B4;
	// bl 0x82170670
	ctx.lr = 0x822C7490;
	sub_82170670(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// add r31,r30,r11
	ctx.r31.u64 = ctx.r30.u64 + ctx.r11.u64;
	// stwx r10,r30,r11
	REX_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r10.u32);
	// lwz r9,52(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// lwz r8,56(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// b 0x822c74c8
	goto loc_822C74C8;
loc_822C74B4:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r31,r30,r11
	ctx.r31.u64 = ctx.r30.u64 + ctx.r11.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x822a90a8
	ctx.lr = 0x822C74C8;
	sub_822A90A8(ctx, base);
loc_822C74C8:
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r7,r30,r11
	ctx.r7.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r6,r28,24
	ctx.r6.s64 = ctx.r28.s64 + 24;
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// cmpw cr6,r29,r6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r6.s32, ctx.xer);
	// stw r10,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// stw r9,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// stw r8,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r8.u32);
	// blt cr6,0x822c7480
	if (ctx.cr6.lt) goto loc_822C7480;
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// mr r23,r22
	ctx.r23.u64 = ctx.r22.u64;
	// addi r25,r11,-8692
	ctx.r25.s64 = ctx.r11.s64 + -8692;
loc_822C7508:
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// mr r24,r22
	ctx.r24.u64 = ctx.r22.u64;
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_822C7518:
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// add r31,r29,r10
	ctx.r31.u64 = ctx.r29.u64 + ctx.r10.u64;
	// add r30,r29,r11
	ctx.r30.u64 = ctx.r29.u64 + ctx.r11.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x822c6f98
	ctx.lr = 0x822C7540;
	sub_822C6F98(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822c7550
	if (ctx.cr6.eq) goto loc_822C7550;
	// li r24,1
	ctx.r24.s64 = 1;
	// li r21,1
	ctx.r21.s64 = 1;
loc_822C7550:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x82515460
	ctx.lr = 0x822C7560;
	sub_82515460(ctx, base);
	// stfs f31,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r31,r1,96
	ctx.r31.s64 = ctx.r1.s64 + 96;
	// li r30,6
	ctx.r30.s64 = 6;
loc_822C756C:
	// addi r5,r1,168
	ctx.r5.s64 = ctx.r1.s64 + 168;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82515418
	ctx.lr = 0x822C757C;
	sub_82515418(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// bne 0x822c756c
	if (!ctx.cr0.eq) goto loc_822C756C;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r11,r25,24
	ctx.r11.s64 = ctx.r25.s64 + 24;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r29,r29,12
	ctx.r29.s64 = ctx.r29.s64 + 12;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x822c7518
	if (ctx.cr6.lt) goto loc_822C7518;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x822c75b4
	if (ctx.cr6.eq) goto loc_822C75B4;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// cmpwi cr6,r23,100
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 100, ctx.xer);
	// blt cr6,0x822c7508
	if (ctx.cr6.lt) goto loc_822C7508;
loc_822C75B4:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x822c75ec
	if (ctx.cr6.eq) goto loc_822C75EC;
	// lwz r11,416(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 416);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822c75dc
	if (ctx.cr6.eq) goto loc_822C75DC;
	// lwz r11,212(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 212);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x822c75dc
	if (ctx.cr6.eq) goto loc_822C75DC;
	// li r11,2301
	ctx.r11.s64 = 2301;
	// stw r11,476(r27)
	REX_STORE_U32(ctx.r27.u32 + 476, ctx.r11.u32);
loc_822C75DC:
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82515460
	ctx.lr = 0x822C75EC;
	sub_82515460(ctx, base);
loc_822C75EC:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r8,108(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r7,112(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// stw r11,2672(r27)
	REX_STORE_U32(ctx.r27.u32 + 2672, ctx.r11.u32);
	// stw r10,2676(r27)
	REX_STORE_U32(ctx.r27.u32 + 2676, ctx.r10.u32);
	// stw r9,2680(r27)
	REX_STORE_U32(ctx.r27.u32 + 2680, ctx.r9.u32);
	// stw r8,2684(r27)
	REX_STORE_U32(ctx.r27.u32 + 2684, ctx.r8.u32);
	// stw r7,2688(r27)
	REX_STORE_U32(ctx.r27.u32 + 2688, ctx.r7.u32);
	// lwz r3,128(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,120(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r9,140(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r8,144(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r7,148(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r31,152(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r30,156(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r29,160(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r28,164(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r26,80(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r25,88(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r24,84(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stw r6,2692(r27)
	REX_STORE_U32(ctx.r27.u32 + 2692, ctx.r6.u32);
	// stw r5,2696(r27)
	REX_STORE_U32(ctx.r27.u32 + 2696, ctx.r5.u32);
	// stw r4,2700(r27)
	REX_STORE_U32(ctx.r27.u32 + 2700, ctx.r4.u32);
	// stw r3,2704(r27)
	REX_STORE_U32(ctx.r27.u32 + 2704, ctx.r3.u32);
	// stw r11,2708(r27)
	REX_STORE_U32(ctx.r27.u32 + 2708, ctx.r11.u32);
	// stw r10,2712(r27)
	REX_STORE_U32(ctx.r27.u32 + 2712, ctx.r10.u32);
	// stw r9,2716(r27)
	REX_STORE_U32(ctx.r27.u32 + 2716, ctx.r9.u32);
	// stw r8,2720(r27)
	REX_STORE_U32(ctx.r27.u32 + 2720, ctx.r8.u32);
	// stw r7,2724(r27)
	REX_STORE_U32(ctx.r27.u32 + 2724, ctx.r7.u32);
	// stw r31,2728(r27)
	REX_STORE_U32(ctx.r27.u32 + 2728, ctx.r31.u32);
	// stw r30,2732(r27)
	REX_STORE_U32(ctx.r27.u32 + 2732, ctx.r30.u32);
	// stw r29,2736(r27)
	REX_STORE_U32(ctx.r27.u32 + 2736, ctx.r29.u32);
	// stw r28,2740(r27)
	REX_STORE_U32(ctx.r27.u32 + 2740, ctx.r28.u32);
	// lwz r3,160(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 160);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r26,2660(r27)
	REX_STORE_U32(ctx.r27.u32 + 2660, ctx.r26.u32);
	// stw r25,2668(r27)
	REX_STORE_U32(ctx.r27.u32 + 2668, ctx.r25.u32);
	// stw r24,2664(r27)
	REX_STORE_U32(ctx.r27.u32 + 2664, ctx.r24.u32);
	// beq cr6,0x822c76ac
	if (ctx.cr6.eq) goto loc_822C76AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822c7418
	ctx.lr = 0x822C76AC;
	sub_822C7418(ctx, base);
loc_822C76AC:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x826a02cc
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D17F8) {
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
	// bl 0x822cd6f8
	ctx.lr = 0x822D1808;
	sub_822CD6F8(ctx, base);
	// cmpwi cr6,r3,20
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 20, ctx.xer);
	// beq cr6,0x822d1820
	if (ctx.cr6.eq) goto loc_822D1820;
	// bl 0x822cd6f8
	ctx.lr = 0x822D1814;
	sub_822CD6F8(ctx, base);
	// cmpwi cr6,r3,21
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 21, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x822d1824
	if (!ctx.cr6.eq) goto loc_822D1824;
loc_822D1820:
	// li r3,1
	ctx.r3.s64 = 1;
loc_822D1824:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822D2400) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x822D2408;
	__savegprlr_25(ctx, base);
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,1964(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 1964);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fabs f11,f0
	ctx.f11.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,76(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// lfs f12,1968(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 1968);
	ctx.f12.f64 = double(temp.f32);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// lfs f13,10336(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10336);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r27,r9,31
	ctx.r27.u64 = ctx.r9.u32 & 0x1;
	// lfs f31,2880(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// ble cr6,0x822d2464
	if (!ctx.cr6.gt) goto loc_822D2464;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f11,12688(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12688);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_822D2464:
	// fabs f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x822d2480
	if (!ctx.cr6.gt) goto loc_822D2480;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,13148(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13148);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_822D2480:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825156d0
	ctx.lr = 0x822D2488;
	sub_825156D0(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x822d25e0
	if (!ctx.cr6.gt) goto loc_822D25E0;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r10,r11,23664
	ctx.r10.s64 = ctx.r11.s64 + 23664;
	// lfs f31,-8472(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8472);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822d24cc
	if (ctx.cr6.eq) goto loc_822D24CC;
	// lwz r10,20(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822d24d0
	if (ctx.cr6.eq) goto loc_822D24D0;
loc_822D24CC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822D24D0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822d24f4
	if (ctx.cr6.eq) goto loc_822D24F4;
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
	// bne cr6,0x822d24f8
	if (!ctx.cr6.eq) goto loc_822D24F8;
loc_822D24F4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D24F8:
	// lwz r3,860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// bl 0x821c8060
	ctx.lr = 0x822D2500;
	sub_821C8060(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x822d5280
	ctx.lr = 0x822D2508;
	sub_822D5280(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x822d25c0
	if (!ctx.cr6.gt) goto loc_822D25C0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f30,6776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6776);
	ctx.f30.f64 = double(temp.f32);
loc_822D2520:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821ce820
	ctx.lr = 0x822D252C;
	sub_821CE820(ctx, base);
	// lwz r11,388(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 388);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x822d25ac
	if (ctx.cr6.eq) goto loc_822D25AC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x822d25ac
	if (ctx.cr6.eq) goto loc_822D25AC;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D2554;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,612(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 612);
	// rlwinm r8,r9,0,0,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822d25ac
	if (ctx.cr6.eq) goto loc_822D25AC;
	// addi r11,r27,1810
	ctx.r11.s64 = ctx.r27.s64 + 1810;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r31.u32);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// cmpwi cr6,r8,16383
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16383, ctx.xer);
	// bge cr6,0x822d25ac
	if (!ctx.cr6.lt) goto loc_822D25AC;
	// addi r11,r27,903
	ctx.r11.s64 = ctx.r27.s64 + 903;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x822d25ac
	if (!ctx.cr6.lt) goto loc_822D25AC;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x822d25ac
	if (!ctx.cr6.lt) goto loc_822D25AC;
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x822d25ac
	if (!ctx.cr6.gt) goto loc_822D25AC;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
loc_822D25AC:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r28
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x822d2520
	if (ctx.cr6.lt) goto loc_822D2520;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x822d25e0
	if (!ctx.cr6.eq) goto loc_822D25E0;
loc_822D25C0:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x822d22b0
	ctx.lr = 0x822D25D0;
	sub_822D22B0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
loc_822D25E0:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822DF038) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a027c
	ctx.lr = 0x822DF040;
	__savegprlr_21(ctx, base);
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x826a0cec
	ctx.lr = 0x822DF048;
	__savefpr_17(ctx, base);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,80(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lfs f0,3808(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3808);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x822df3f0
	if (ctx.cr6.gt) goto loc_822DF3F0;
	// lis r11,-32109
	ctx.r11.s64 = -2104295424;
	// addi r28,r11,23732
	ctx.r28.s64 = ctx.r11.s64 + 23732;
	// lwz r11,-8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822df3f0
	if (ctx.cr6.eq) goto loc_822DF3F0;
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,13920(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14712(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 14712);
	ctx.f13.f64 = double(temp.f32);
	// lfs f31,2884(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2884);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f0,14300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14300);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 / ctx.f10.f64));
	// fmadds f7,f8,f0,f31
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f0.f64, ctx.f31.f64)));
	// fctiwz f6,f7
	ctx.f6.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r23,84(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x822df3f0
	if (!ctx.cr6.gt) goto loc_822DF3F0;
	// li r22,4
	ctx.r22.s64 = 4;
	// cmpwi cr6,r23,4
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 4, ctx.xer);
	// ble cr6,0x822df0dc
	if (!ctx.cr6.gt) goto loc_822DF0DC;
	// mr r23,r22
	ctx.r23.u64 = ctx.r22.u64;
loc_822DF0DC:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -4);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f17,6380(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6380);
	ctx.f17.f64 = double(temp.f32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lfs f18,-10032(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10032);
	ctx.f18.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f21,3664(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 3664);
	ctx.f21.f64 = double(temp.f32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lfs f19,4268(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4268);
	ctx.f19.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f22,8096(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8096);
	ctx.f22.f64 = double(temp.f32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f20,3804(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 3804);
	ctx.f20.f64 = double(temp.f32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f23,10336(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 10336);
	ctx.f23.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f29,3556(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 3556);
	ctx.f29.f64 = double(temp.f32);
	// li r29,0
	ctx.r29.s64 = 0;
	// lfs f24,24544(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24544);
	ctx.f24.f64 = double(temp.f32);
	// lfs f25,3800(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3800);
	ctx.f25.f64 = double(temp.f32);
	// li r24,1
	ctx.r24.s64 = 1;
	// lfs f26,23580(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 23580);
	ctx.f26.f64 = double(temp.f32);
	// mr r21,r29
	ctx.r21.u64 = ctx.r29.u64;
	// lfs f27,3796(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f27.f64 = double(temp.f32);
	// li r25,20
	ctx.r25.s64 = 20;
	// lfs f30,2880(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 2880);
	ctx.f30.f64 = double(temp.f32);
loc_822DF158:
	// srawi r9,r11,11
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 11;
	// lwz r10,-160(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + -160);
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,11,0,20
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 11) & 0xFFFFF800;
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// mulli r9,r11,112
	ctx.r9.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(112));
	// stw r11,-4(r28)
	REX_STORE_U32(ctx.r28.u32 + -4, ctx.r11.u32);
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r6,68(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 68);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bge cr6,0x822df3dc
	if (!ctx.cr6.lt) goto loc_822DF3DC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,96(r30)
	REX_STORE_U32(ctx.r30.u32 + 96, ctx.r11.u32);
	// lwz r10,-16(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + -16);
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f13,4(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lfs f12,8(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// lfs f11,768(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 768);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,32(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// lfs f10,772(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 772);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,36(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// lfs f9,776(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 776);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,40(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// stfs f30,16(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f30,20(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stfs f31,24(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f31,28(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// lfs f8,768(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 768);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,48(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// lfs f7,772(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 772);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,52(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 52, temp.u32);
	// lfs f6,776(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 776);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,56(r11)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// lfs f5,780(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 780);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,60(r11)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lfs f4,768(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 768);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,64(r11)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lfs f3,772(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 772);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,68(r11)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r11.u32 + 68, temp.u32);
	// lfs f2,776(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 776);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,72(r11)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + 72, temp.u32);
	// lfs f1,780(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 780);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,76(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// lfs f0,768(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// lfs f13,772(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 772);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// lfs f12,776(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 776);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// lfs f11,780(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 780);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,92(r11)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r11.u32 + 92, temp.u32);
	// lfs f10,768(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 768);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,96(r11)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lfs f9,772(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 772);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,100(r11)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r11.u32 + 100, temp.u32);
	// lfs f8,776(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 776);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,104(r11)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// lfs f7,780(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 780);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,108(r11)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r11.u32 + 108, temp.u32);
	// stw r29,144(r11)
	REX_STORE_U32(ctx.r11.u32 + 144, ctx.r29.u32);
	// stfs f30,12(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stw r22,136(r11)
	REX_STORE_U32(ctx.r11.u32 + 136, ctx.r22.u32);
	// stfs f31,116(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 116, temp.u32);
	// stw r29,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r29.u32);
	// stfs f31,120(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 120, temp.u32);
	// stw r29,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r29.u32);
	// lwz r10,96(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// rlwinm r9,r10,9,16,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0xFE00;
	// stw r9,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r9.u32);
	// stw r29,140(r11)
	REX_STORE_U32(ctx.r11.u32 + 140, ctx.r29.u32);
	// stw r29,144(r11)
	REX_STORE_U32(ctx.r11.u32 + 144, ctx.r29.u32);
	// stw r24,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r24.u32);
	// bl 0x82518110
	ctx.lr = 0x822DF294;
	sub_82518110(ctx, base);
	// srawi r8,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 16;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f6,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmadds f3,f4,f27,f26
	ctx.f3.f64 = double(float(std::fma(ctx.f4.f64, ctx.f27.f64, ctx.f26.f64)));
	// stfs f3,52(r30)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// bl 0x82518110
	ctx.lr = 0x822DF2B8;
	sub_82518110(ctx, base);
	// srawi r6,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 16;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f2,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmadds f13,f0,f27,f26
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f27.f64, ctx.f26.f64)));
	// stfs f13,56(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// bl 0x82518110
	ctx.lr = 0x822DF2DC;
	sub_82518110(ctx, base);
	// srawi r4,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 16;
	// lfs f12,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// fmuls f11,f12,f23
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f23.f64));
	// std r3,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmsubs f7,f8,f25,f24
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f25.f64, -ctx.f24.f64)));
	// fmadds f6,f7,f29,f11
	ctx.f6.f64 = double(float(std::fma(ctx.f7.f64, ctx.f29.f64, ctx.f11.f64)));
	// stfs f6,0(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// bl 0x82518110
	ctx.lr = 0x822DF30C;
	sub_82518110(ctx, base);
	// srawi r11,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 16;
	// lfs f5,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// fmuls f4,f5,f22
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f22.f64));
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f3,104(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmadds f0,f1,f20,f22
	ctx.f0.f64 = double(float(std::fma(ctx.f1.f64, ctx.f20.f64, ctx.f22.f64)));
	// fmsubs f13,f0,f29,f4
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f29.f64, -ctx.f4.f64)));
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// bl 0x82518110
	ctx.lr = 0x822DF33C;
	sub_82518110(ctx, base);
	// srawi r9,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 16;
	// lfs f12,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stw r29,64(r30)
	REX_STORE_U32(ctx.r30.u32 + 64, ctx.r29.u32);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// fmuls f11,f12,f23
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f23.f64));
	// stw r25,68(r30)
	REX_STORE_U32(ctx.r30.u32 + 68, ctx.r25.u32);
	// std r8,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f10,112(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmsubs f7,f8,f25,f24
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f25.f64, -ctx.f24.f64)));
	// fmadds f6,f7,f29,f11
	ctx.f6.f64 = double(float(std::fma(ctx.f7.f64, ctx.f29.f64, ctx.f11.f64)));
	// stfs f6,8(r30)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// lfs f4,616(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 616);
	ctx.f4.f64 = double(temp.f32);
	// lfs f5,620(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 620);
	ctx.f5.f64 = double(temp.f32);
	// fnmsubs f28,f5,f19,f4
	ctx.f28.f64 = double(float(-std::fma(ctx.f5.f64, ctx.f19.f64, -ctx.f4.f64)));
	// fcmpu cr6,f28,f21
	ctx.cr6.compare(ctx.f28.f64, ctx.f21.f64);
	// bge cr6,0x822df388
	if (!ctx.cr6.lt) goto loc_822DF388;
	// fmr f28,f21
	ctx.f28.f64 = ctx.f21.f64;
loc_822DF388:
	// bl 0x82518110
	ctx.lr = 0x822DF38C;
	sub_82518110(ctx, base);
	// srawi r10,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 16;
	// lfs f0,620(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 620);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// stfs f31,48(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// std r9,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r9.u64);
	// lfd f13,120(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmadds f9,f10,f18,f28
	ctx.f9.f64 = double(float(std::fma(ctx.f10.f64, ctx.f18.f64, ctx.f28.f64)));
	// fdivs f8,f17,f9
	ctx.f8.f64 = double(float(ctx.f17.f64 / ctx.f9.f64));
	// stfs f8,92(r30)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r30.u32 + 92, temp.u32);
	// lfs f7,780(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 780);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,60(r30)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r30.u32 + 60, temp.u32);
	// ble 0x822df3f0
	if (!ctx.cr0.gt) goto loc_822DF3F0;
	// lwz r11,-4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -4);
loc_822DF3DC:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r21,2048
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 2048, ctx.xer);
	// stw r11,-4(r28)
	REX_STORE_U32(ctx.r28.u32 + -4, ctx.r11.u32);
	// blt cr6,0x822df158
	if (ctx.cr6.lt) goto loc_822DF158;
loc_822DF3F0:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-96
	ctx.r12.s64 = ctx.r1.s64 + -96;
	// bl 0x826a0d38
	ctx.lr = 0x822DF3FC;
	__restfpr_17(ctx, base);
	// b 0x826a02cc
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822FA1E8) {
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
	// li r31,1
	ctx.r31.s64 = 1;
loc_822FA204:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x822e88f8
	ctx.lr = 0x822FA214;
	sub_822E88F8(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,88
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 88, ctx.xer);
	// blt cr6,0x822fa204
	if (ctx.cr6.lt) goto loc_822FA204;
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

DEFINE_REX_FUNC(sub_822FBD78) {
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
	// bl 0x822fbbc0
	ctx.lr = 0x822FBD94;
	sub_822FBBC0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822fbdb8
	if (ctx.cr6.eq) goto loc_822FBDB8;
	// bl 0x8238e510
	ctx.lr = 0x822FBDA4;
	sub_8238E510(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822fbdb8
	if (ctx.cr6.eq) goto loc_822FBDB8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822fada0
	ctx.lr = 0x822FBDB8;
	sub_822FADA0(ctx, base);
loc_822FBDB8:
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

DEFINE_REX_FUNC(sub_822FD368) {
	REX_FUNC_PROLOGUE();
	// b 0x822e9230
	sub_822E9230(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822FD378) {
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
	// bl 0x822e9578
	ctx.lr = 0x822FD390;
	sub_822E9578(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,13632
	ctx.r10.s64 = ctx.r11.s64 + 13632;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_822FE3F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r4,5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 5, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x822fe42c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822FE42C;
	// bdzf 4*cr6+eq,0x822fe444
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822FE444;
	// bdzf 4*cr6+eq,0x822fe45c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822FE45C;
	// bdzf 4*cr6+eq,0x822fe474
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_822FE474;
	// bne cr6,0x822fe48c
	if (!ctx.cr6.eq) goto loc_822FE48C;
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 & ctx.r5.u64;
	// stb r7,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r7.u8);
	// blr 
	return;
loc_822FE42C:
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 & ctx.r5.u64;
	// stb r7,1(r3)
	REX_STORE_U8(ctx.r3.u32 + 1, ctx.r7.u8);
	// blr 
	return;
loc_822FE444:
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 & ctx.r5.u64;
	// stb r7,2(r3)
	REX_STORE_U8(ctx.r3.u32 + 2, ctx.r7.u8);
	// blr 
	return;
loc_822FE45C:
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 & ctx.r5.u64;
	// stb r7,3(r3)
	REX_STORE_U8(ctx.r3.u32 + 3, ctx.r7.u8);
	// blr 
	return;
loc_822FE474:
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 & ctx.r5.u64;
	// stb r7,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// blr 
	return;
loc_822FE48C:
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 & ctx.r5.u64;
	// stb r7,5(r3)
	REX_STORE_U8(ctx.r3.u32 + 5, ctx.r7.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82302740) {
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
	// addi r3,r3,176
	ctx.r3.s64 = ctx.r3.s64 + 176;
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82302778
	if (ctx.cr6.eq) goto loc_82302778;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82302778
	if (ctx.cr6.eq) goto loc_82302778;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8223cdd8
	ctx.lr = 0x82302778;
	sub_8223CDD8(ctx, base);
loc_82302778:
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// addi r3,r31,192
	ctx.r3.s64 = ctx.r31.s64 + 192;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230279c
	if (ctx.cr6.eq) goto loc_8230279C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230279c
	if (ctx.cr6.eq) goto loc_8230279C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8223cdd8
	ctx.lr = 0x8230279C;
	sub_8223CDD8(ctx, base);
loc_8230279C:
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

DEFINE_REX_FUNC(sub_82305528) {
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
	ctx.lr = 0x8230553C;
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

DEFINE_REX_FUNC(sub_82306098) {
	REX_FUNC_PROLOGUE();
	// b 0x822e9230
	sub_822E9230(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823060A0) {
	REX_FUNC_PROLOGUE();
	// b 0x822e8460
	sub_822E8460(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82306240) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82306248;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,144(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82306278
	if (ctx.cr6.eq) goto loc_82306278;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,148(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// beq cr6,0x8230627c
	if (ctx.cr6.eq) goto loc_8230627C;
loc_82306278:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8230627C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823062a0
	if (ctx.cr6.eq) goto loc_823062A0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,60(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// lwz r11,30048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x823062a4
	if (!ctx.cr6.eq) goto loc_823062A4;
loc_823062A0:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_823062A4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8235d970
	ctx.lr = 0x823062AC;
	sub_8235D970(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823062ec
	if (ctx.cr6.eq) goto loc_823062EC;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,176
	ctx.r3.s64 = ctx.r31.s64 + 176;
	// bl 0x8223cdd8
	ctx.lr = 0x823062C0;
	sub_8223CDD8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,192
	ctx.r3.s64 = ctx.r31.s64 + 192;
	// bl 0x8223cdd8
	ctx.lr = 0x823062CC;
	sub_8223CDD8(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r29,152(r30)
	REX_STORE_U32(ctx.r30.u32 + 152, ctx.r29.u32);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_823062EC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8235d980
	ctx.lr = 0x823062F4;
	sub_8235D980(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8230638c
	if (ctx.cr6.eq) goto loc_8230638C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r29,152(r30)
	REX_STORE_U32(ctx.r30.u32 + 152, ctx.r29.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,140
	ctx.r3.s64 = 140;
	// bl 0x82219630
	ctx.lr = 0x82306324;
	sub_82219630(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82306350
	if (ctx.cr6.eq) goto loc_82306350;
	// addi r5,r31,192
	ctx.r5.s64 = ctx.r31.s64 + 192;
	// addi r4,r31,176
	ctx.r4.s64 = ctx.r31.s64 + 176;
	// bl 0x822e9578
	ctx.lr = 0x8230633C;
	sub_822E9578(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r10,r11,18244
	ctx.r10.s64 = ctx.r11.s64 + 18244;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// b 0x82306354
	goto loc_82306354;
loc_82306350:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
loc_82306354:
	// addi r3,r31,152
	ctx.r3.s64 = ctx.r31.s64 + 152;
	// bl 0x8226bf28
	ctx.lr = 0x8230635C;
	sub_8226BF28(ctx, base);
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// addi r9,r11,24864
	ctx.r9.s64 = ctx.r11.s64 + 24864;
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// addi r6,r10,18193
	ctx.r6.s64 = ctx.r10.s64 + 18193;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x8230638C;
	sub_822518D8(ctx, base);
loc_8230638C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8230AED8) {
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
	// bl 0x822d1688
	ctx.lr = 0x8230AEE8;
	sub_822D1688(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8230aef4
	if (!ctx.cr6.eq) goto loc_8230AEF4;
	// bl 0x822d17f8
	ctx.lr = 0x8230AEF4;
	sub_822D17F8(ctx, base);
loc_8230AEF4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f1,18676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18676);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8230E610) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0284
	ctx.lr = 0x8230E618;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x826a0d08
	ctx.lr = 0x8230E620;
	__savefpr_24(ctx, base);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r9,r11,-32728
	ctx.r9.s64 = ctx.r11.s64 + -32728;
	// addi r8,r10,-12664
	ctx.r8.s64 = ctx.r10.s64 + -12664;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lwz r10,12(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r5,r7,r8
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwzx r11,r6,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823141a0
	ctx.lr = 0x8230E670;
	sub_823141A0(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230ef38
	if (ctx.cr6.eq) goto loc_8230EF38;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8230ef38
	if (ctx.cr6.eq) goto loc_8230EF38;
	// lwz r11,264(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230ef38
	if (ctx.cr6.eq) goto loc_8230EF38;
	// lwz r11,264(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230ef38
	if (ctx.cr6.eq) goto loc_8230EF38;
	// bl 0x822d1688
	ctx.lr = 0x8230E6A4;
	sub_822D1688(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r26,r10,32769
	ctx.r26.u64 = ctx.r10.u64 | 32769;
	// addi r28,r11,18624
	ctx.r28.s64 = ctx.r11.s64 + 18624;
	// bne cr6,0x8230e6c8
	if (!ctx.cr6.eq) goto loc_8230E6C8;
	// bl 0x822d17f8
	ctx.lr = 0x8230E6C0;
	sub_822D17F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8230e6dc
	if (ctx.cr6.eq) goto loc_8230E6DC;
loc_8230E6C8:
	// addi r5,r1,172
	ctx.r5.s64 = ctx.r1.s64 + 172;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8230c530
	ctx.lr = 0x8230E6D8;
	sub_8230C530(ctx, base);
	// b 0x8230e7f4
	goto loc_8230E7F4;
loc_8230E6DC:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r3,264
	ctx.r30.s64 = ctx.r3.s64 + 264;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230e748
	if (ctx.cr6.eq) goto loc_8230E748;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82297f48
	ctx.lr = 0x8230E6FC;
	sub_82297F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8230e748
	if (!ctx.cr6.eq) goto loc_8230E748;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// stw r10,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// stw r9,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// bge cr6,0x8230e748
	if (!ctx.cr6.lt) goto loc_8230E748;
	// addi r10,r28,64
	ctx.r10.s64 = ctx.r28.s64 + 64;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// b 0x8230e768
	goto loc_8230E768;
loc_8230E748:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82170670
	ctx.lr = 0x8230E750;
	sub_82170670(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f13,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f12,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
loc_8230E768:
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r3,264
	ctx.r30.s64 = ctx.r3.s64 + 264;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230e7d4
	if (ctx.cr6.eq) goto loc_8230E7D4;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82297f48
	ctx.lr = 0x8230E788;
	sub_82297F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8230e7d4
	if (!ctx.cr6.eq) goto loc_8230E7D4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// stw r10,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// stw r9,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// bge cr6,0x8230e7d4
	if (!ctx.cr6.lt) goto loc_8230E7D4;
	// addi r10,r28,64
	ctx.r10.s64 = ctx.r28.s64 + 64;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// b 0x8230e7f4
	goto loc_8230E7F4;
loc_8230E7D4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82170670
	ctx.lr = 0x8230E7DC;
	sub_82170670(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f13,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lfs f12,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,180(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
loc_8230E7F4:
	// addi r29,r25,16
	ctx.r29.s64 = ctx.r25.s64 + 16;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x82515460
	ctx.lr = 0x8230E808;
	sub_82515460(ctx, base);
	// lfs f2,272(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,280(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 280);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826a1000
	ctx.lr = 0x8230E814;
	sub_826A1000(ctx, base);
	// addi r31,r27,16
	ctx.r31.s64 = ctx.r27.s64 + 16;
	// frsp f24,f1
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = double(float(ctx.f1.f64));
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x82515460
	ctx.lr = 0x8230E82C;
	sub_82515460(ctx, base);
	// lfs f2,288(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,296(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826a1000
	ctx.lr = 0x8230E838;
	sub_826A1000(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// frsp f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = double(float(ctx.f1.f64));
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x82515460
	ctx.lr = 0x8230E84C;
	sub_82515460(ctx, base);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x825156d0
	ctx.lr = 0x8230E854;
	sub_825156D0(ctx, base);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3084(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3084);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lfs f30,2880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f30.f64 = double(temp.f32);
	// ble cr6,0x8230ea40
	if (!ctx.cr6.gt) goto loc_8230EA40;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// bl 0x82515460
	ctx.lr = 0x8230E888;
	sub_82515460(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x82515460
	ctx.lr = 0x8230E898;
	sub_82515460(ctx, base);
	// addi r5,r1,172
	ctx.r5.s64 = ctx.r1.s64 + 172;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82515460
	ctx.lr = 0x8230E8A8;
	sub_82515460(ctx, base);
	// stfs f30,324(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x825156d0
	ctx.lr = 0x8230E8B4;
	sub_825156D0(ctx, base);
	// stfs f30,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f30,204(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825156d0
	ctx.lr = 0x8230E8CC;
	sub_825156D0(ctx, base);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,3664(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3664);
	ctx.f31.f64 = double(temp.f32);
	// lfs f0,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x8230ea40
	if (!ctx.cr6.gt) goto loc_8230EA40;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x825156d0
	ctx.lr = 0x8230E8F0;
	sub_825156D0(ctx, base);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x8230ea40
	if (!ctx.cr6.gt) goto loc_8230EA40;
	// addi r4,r1,200
	ctx.r4.s64 = ctx.r1.s64 + 200;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// bl 0x825154a8
	ctx.lr = 0x8230E910;
	sub_825154A8(ctx, base);
	// addi r4,r1,184
	ctx.r4.s64 = ctx.r1.s64 + 184;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// bl 0x825154a8
	ctx.lr = 0x8230E91C;
	sub_825154A8(ctx, base);
	// addi r4,r1,200
	ctx.r4.s64 = ctx.r1.s64 + 200;
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// bl 0x82515750
	ctx.lr = 0x8230E928;
	sub_82515750(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f26,4284(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4284);
	ctx.f26.f64 = double(temp.f32);
	// lfs f28,2884(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2884);
	ctx.f28.f64 = double(temp.f32);
	// fcmpu cr6,f1,f26
	ctx.cr6.compare(ctx.f1.f64, ctx.f26.f64);
	// bgt cr6,0x8230e94c
	if (ctx.cr6.gt) goto loc_8230E94C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f27,4264(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4264);
	ctx.f27.f64 = double(temp.f32);
	// b 0x8230e964
	goto loc_8230E964;
loc_8230E94C:
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f28.f64);
	// blt cr6,0x8230e95c
	if (ctx.cr6.lt) goto loc_8230E95C;
	// fmr f27,f30
	ctx.f27.f64 = ctx.f30.f64;
	// b 0x8230e964
	goto loc_8230E964;
loc_8230E95C:
	// bl 0x826a1f10
	ctx.lr = 0x8230E960;
	sub_826A1F10(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = double(float(ctx.f1.f64));
loc_8230E964:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f29,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f29.f64 = double(temp.f32);
	// lfs f0,21276(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21276);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	ctx.cr6.compare(ctx.f29.f64, ctx.f0.f64);
	// ble cr6,0x8230e980
	if (!ctx.cr6.gt) goto loc_8230E980;
	// fmr f31,f28
	ctx.f31.f64 = ctx.f28.f64;
	// b 0x8230e990
	goto loc_8230E990;
loc_8230E980:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,18940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18940);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f29,f0,f28
	ctx.f0.f64 = double(float(-std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f28.f64)));
	// fadds f31,f0,f28
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f28.f64));
loc_8230E990:
	// bl 0x822d1688
	ctx.lr = 0x8230E994;
	sub_822D1688(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8230e9a8
	if (!ctx.cr6.eq) goto loc_8230E9A8;
	// bl 0x822d17f8
	ctx.lr = 0x8230E9A0;
	sub_822D17F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8230e9b4
	if (ctx.cr6.eq) goto loc_8230E9B4;
loc_8230E9A8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,18936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18936);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8230e9bc
	goto loc_8230E9BC;
loc_8230E9B4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,18932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18932);
	ctx.f0.f64 = double(temp.f32);
loc_8230E9BC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmuls f13,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f0,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// fcmpu cr6,f29,f0
	ctx.cr6.compare(ctx.f29.f64, ctx.f0.f64);
	// lfs f0,7672(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7672);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f27,f0
	ctx.f0.f64 = double(float(ctx.f27.f64 - ctx.f0.f64));
	// blt cr6,0x8230ea44
	if (ctx.cr6.lt) goto loc_8230EA44;
	// lwz r11,476(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 476);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8230ea44
	if (ctx.cr6.eq) goto loc_8230EA44;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,476(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 476);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8230ea44
	if (ctx.cr6.eq) goto loc_8230EA44;
	// fabs f12,f0
	ctx.f12.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x8230ea44
	if (!ctx.cr6.gt) goto loc_8230EA44;
	// lwz r11,648(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 648);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8230ea28
	if (!ctx.cr6.eq) goto loc_8230EA28;
	// fsel f0,f0,f26,f28
	ctx.f0.f64 = ctx.f0.f64 >= 0.0 ? ctx.f26.f64 : ctx.f28.f64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f0,7684(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7684);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f25,f13,f0,f24
	ctx.f25.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f24.f64)));
	// b 0x8230ea44
	goto loc_8230EA44;
loc_8230EA28:
	// fsel f0,f0,f28,f26
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 >= 0.0 ? ctx.f28.f64 : ctx.f26.f64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f0,7684(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7684);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f25,f13,f0,f24
	ctx.f25.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f24.f64)));
	// b 0x8230ea44
	goto loc_8230EA44;
loc_8230EA40:
	// lwz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8230EA44:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x8230ea50
	if (ctx.cr6.eq) goto loc_8230EA50;
	// fmr f25,f24
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f24.f64;
loc_8230EA50:
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f28,52(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 52);
	ctx.f28.f64 = double(temp.f32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x8230c688
	ctx.lr = 0x8230EA6C;
	sub_8230C688(ctx, base);
	// bl 0x822d1688
	ctx.lr = 0x8230EA70;
	sub_822D1688(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8230ea84
	if (!ctx.cr6.eq) goto loc_8230EA84;
	// bl 0x822d17f8
	ctx.lr = 0x8230EA7C;
	sub_822D17F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8230ea98
	if (ctx.cr6.eq) goto loc_8230EA98;
loc_8230EA84:
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8230c530
	ctx.lr = 0x8230EA94;
	sub_8230C530(ctx, base);
	// b 0x8230ebd8
	goto loc_8230EBD8;
loc_8230EA98:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r3,264
	ctx.r30.s64 = ctx.r3.s64 + 264;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230eb00
	if (ctx.cr6.eq) goto loc_8230EB00;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82297f48
	ctx.lr = 0x8230EAB8;
	sub_82297F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8230eb00
	if (!ctx.cr6.eq) goto loc_8230EB00;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bge cr6,0x8230eb00
	if (!ctx.cr6.lt) goto loc_8230EB00;
	// addi r10,r28,64
	ctx.r10.s64 = ctx.r28.s64 + 64;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x8230eb1c
	goto loc_8230EB1C;
loc_8230EB00:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82170670
	ctx.lr = 0x8230EB08;
	sub_82170670(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_8230EB1C:
	// lfs f12,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8230eb38
	if (!ctx.cr6.lt) goto loc_8230EB38;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_8230EB38:
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r3,264
	ctx.r30.s64 = ctx.r3.s64 + 264;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230eba0
	if (ctx.cr6.eq) goto loc_8230EBA0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82297f48
	ctx.lr = 0x8230EB58;
	sub_82297F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8230eba0
	if (!ctx.cr6.eq) goto loc_8230EBA0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// bge cr6,0x8230eba0
	if (!ctx.cr6.lt) goto loc_8230EBA0;
	// addi r10,r28,64
	ctx.r10.s64 = ctx.r28.s64 + 64;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x8230ebbc
	goto loc_8230EBBC;
loc_8230EBA0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82170670
	ctx.lr = 0x8230EBA8;
	sub_82170670(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
loc_8230EBBC:
	// lfs f12,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8230ebd8
	if (!ctx.cr6.lt) goto loc_8230EBD8;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
loc_8230EBD8:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f31,52(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 52);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x82307b70
	ctx.lr = 0x8230EBE4;
	sub_82307B70(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,108
	ctx.r6.s64 = ctx.r1.s64 + 108;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8230c7e0
	ctx.lr = 0x8230EBF8;
	sub_8230C7E0(ctx, base);
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// fmr f1,f25
	ctx.f1.f64 = ctx.f25.f64;
	// stw r11,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// bl 0x826a1c70
	ctx.lr = 0x8230EC1C;
	sub_826A1C70(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = ctx.f25.f64;
	// fmadds f12,f0,f31,f13
	ctx.f12.f64 = double(float(std::fma(ctx.f0.f64, ctx.f31.f64, ctx.f13.f64)));
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x826a1b90
	ctx.lr = 0x8230EC34;
	sub_826A1B90(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// fmadds f9,f11,f31,f10
	ctx.f9.f64 = double(float(std::fma(ctx.f11.f64, ctx.f31.f64, ctx.f10.f64)));
	// stfs f9,128(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// bl 0x82515460
	ctx.lr = 0x8230EC54;
	sub_82515460(ctx, base);
	// lfs f0,256(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f8,f0,f0
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lfs f1,260(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 260);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,264(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 264);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f7,f0,f0,f8
	ctx.f7.f64 = double(float(std::fma(ctx.f0.f64, ctx.f0.f64, ctx.f8.f64)));
	// fsqrts f2,f7
	ctx.f2.f64 = double(float(sqrt(ctx.f7.f64)));
	// bl 0x826a1000
	ctx.lr = 0x8230EC70;
	sub_826A1000(ctx, base);
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// bl 0x82515460
	ctx.lr = 0x8230EC84;
	sub_82515460(ctx, base);
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f6,f0,f0
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f0.f64));
	// lfs f1,244(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,248(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f5,f0,f0,f6
	ctx.f5.f64 = double(float(std::fma(ctx.f0.f64, ctx.f0.f64, ctx.f6.f64)));
	// fsqrts f2,f5
	ctx.f2.f64 = double(float(sqrt(ctx.f5.f64)));
	// bl 0x826a1000
	ctx.lr = 0x8230ECA0;
	sub_826A1000(ctx, base);
	// lfs f0,56(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// frsp f4,f1
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// fsubs f3,f31,f4
	ctx.f3.f64 = double(float(ctx.f31.f64 - ctx.f4.f64));
	// fmadds f29,f3,f0,f4
	ctx.f29.f64 = double(float(std::fma(ctx.f3.f64, ctx.f0.f64, ctx.f4.f64)));
	// beq cr6,0x8230ecbc
	if (ctx.cr6.eq) goto loc_8230ECBC;
	// fmr f29,f31
	ctx.f29.f64 = ctx.f31.f64;
loc_8230ECBC:
	// bl 0x822d1688
	ctx.lr = 0x8230ECC0;
	sub_822D1688(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8230ecd4
	if (!ctx.cr6.eq) goto loc_8230ECD4;
	// bl 0x822d17f8
	ctx.lr = 0x8230ECCC;
	sub_822D17F8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8230ece8
	if (ctx.cr6.eq) goto loc_8230ECE8;
loc_8230ECD4:
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8230c530
	ctx.lr = 0x8230ECE4;
	sub_8230C530(ctx, base);
	// b 0x8230ee28
	goto loc_8230EE28;
loc_8230ECE8:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r3,264
	ctx.r30.s64 = ctx.r3.s64 + 264;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230ed50
	if (ctx.cr6.eq) goto loc_8230ED50;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82297f48
	ctx.lr = 0x8230ED08;
	sub_82297F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8230ed50
	if (!ctx.cr6.eq) goto loc_8230ED50;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r8,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bge cr6,0x8230ed50
	if (!ctx.cr6.lt) goto loc_8230ED50;
	// addi r10,r28,64
	ctx.r10.s64 = ctx.r28.s64 + 64;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x8230ed6c
	goto loc_8230ED6C;
loc_8230ED50:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82170670
	ctx.lr = 0x8230ED58;
	sub_82170670(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_8230ED6C:
	// lfs f12,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8230ed88
	if (!ctx.cr6.lt) goto loc_8230ED88;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_8230ED88:
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r3,264
	ctx.r30.s64 = ctx.r3.s64 + 264;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8230edf0
	if (ctx.cr6.eq) goto loc_8230EDF0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82297f48
	ctx.lr = 0x8230EDA8;
	sub_82297F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x8230edf0
	if (!ctx.cr6.eq) goto loc_8230EDF0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// bge cr6,0x8230edf0
	if (!ctx.cr6.lt) goto loc_8230EDF0;
	// addi r10,r28,64
	ctx.r10.s64 = ctx.r28.s64 + 64;
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x8230ee0c
	goto loc_8230EE0C;
loc_8230EDF0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82170670
	ctx.lr = 0x8230EDF8;
	sub_82170670(ctx, base);
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,52(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
loc_8230EE0C:
	// lfs f12,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8230ee28
	if (!ctx.cr6.lt) goto loc_8230EE28;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
loc_8230EE28:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lfs f31,52(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 52);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x82307b70
	ctx.lr = 0x8230EE34;
	sub_82307B70(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,108
	ctx.r6.s64 = ctx.r1.s64 + 108;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8230c7e0
	ctx.lr = 0x8230EE48;
	sub_8230C7E0(ctx, base);
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82515460
	ctx.lr = 0x8230EE5C;
	sub_82515460(ctx, base);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x826a1b90
	ctx.lr = 0x8230EE64;
	sub_826A1B90(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stfs f13,340(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// bl 0x82515418
	ctx.lr = 0x8230EE80;
	sub_82515418(ctx, base);
	// addi r5,r1,172
	ctx.r5.s64 = ctx.r1.s64 + 172;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f30.f64;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x82515460
	ctx.lr = 0x8230EE94;
	sub_82515460(ctx, base);
	// stfs f30,308(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x825156d0
	ctx.lr = 0x8230EEA0;
	sub_825156D0(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82313a10
	ctx.lr = 0x8230EEAC;
	sub_82313A10(ctx, base);
	// lfs f29,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f29.f64 = double(temp.f32);
	// fcmpu cr6,f29,f1
	ctx.cr6.compare(ctx.f29.f64, ctx.f1.f64);
	// ble cr6,0x8230eee0
	if (!ctx.cr6.gt) goto loc_8230EEE0;
	// bl 0x82313a10
	ctx.lr = 0x8230EEBC;
	sub_82313A10(ctx, base);
	// fsubs f13,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f29.f64 - ctx.f1.f64));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,18928(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18928);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82313a10
	ctx.lr = 0x8230EED0;
	sub_82313A10(ctx, base);
	// fsubs f12,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f29.f64 - ctx.f1.f64));
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,18924(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 18924);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f30,f12,f0
	ctx.f30.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
loc_8230EEE0:
	// lfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lfs f13,140(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fadds f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f30.f64));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82307318
	ctx.lr = 0x8230EF04;
	sub_82307318(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r10,124(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// stfs f28,52(r23)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r23.u32 + 52, temp.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r8,136(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r7,140(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r6,144(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 144);
	// stw r11,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r11.u32);
	// stw r10,4(r23)
	REX_STORE_U32(ctx.r23.u32 + 4, ctx.r10.u32);
	// stw r9,8(r23)
	REX_STORE_U32(ctx.r23.u32 + 8, ctx.r9.u32);
	// stw r8,16(r23)
	REX_STORE_U32(ctx.r23.u32 + 16, ctx.r8.u32);
	// stw r7,20(r23)
	REX_STORE_U32(ctx.r23.u32 + 20, ctx.r7.u32);
	// stw r6,24(r23)
	REX_STORE_U32(ctx.r23.u32 + 24, ctx.r6.u32);
loc_8230EF38:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x826a0d54
	ctx.lr = 0x8230EF44;
	__restfpr_24(ctx, base);
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8234A408) {
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
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-14360
	ctx.r11.s64 = ctx.r11.s64 + -14360;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8234a444
	if (ctx.cr6.eq) goto loc_8234A444;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8234a448
	if (ctx.cr6.eq) goto loc_8234A448;
loc_8234A444:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8234A448:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
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
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
	// lwz r11,216(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 216);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x8234a50c
	if (ctx.cr6.lt) goto loc_8234A50C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x8234a4e8
	if (!ctx.cr6.gt) goto loc_8234A4E8;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8234a50c
	if (!ctx.cr6.eq) goto loc_8234A50C;
	// addi r5,r31,16
	ctx.r5.s64 = ctx.r31.s64 + 16;
	// bl 0x82356008
	ctx.lr = 0x8234A4D0;
	sub_82356008(ctx, base);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
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
loc_8234A4E8:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x8234a50c
	if (!ctx.cr6.eq) goto loc_8234A50C;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8234a50c
	if (ctx.cr6.eq) goto loc_8234A50C;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82356020
	ctx.lr = 0x8234A504;
	sub_82356020(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_8234A50C:
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

DEFINE_REX_FUNC(sub_82350C68) {
	REX_FUNC_PROLOGUE();
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// stw r4,148(r3)
	REX_STORE_U32(ctx.r3.u32 + 148, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82351178) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82351180;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82351198;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32107
	ctx.r9.s64 = -2104164352;
	// lwz r29,-24244(r9)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r9.u32 + -24244);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x823511e8
	if (ctx.cr6.eq) goto loc_823511E8;
	// li r31,0
	ctx.r31.s64 = 0;
loc_823511AC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823511C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823511dc
	if (ctx.cr6.eq) goto loc_823511DC;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82350d00
	ctx.lr = 0x823511DC;
	sub_82350D00(ctx, base);
loc_823511DC:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,81
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 81, ctx.xer);
	// blt cr6,0x823511ac
	if (ctx.cr6.lt) goto loc_823511AC;
loc_823511E8:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82354518) {
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
	// bl 0x823519d0
	ctx.lr = 0x82354530;
	sub_823519D0(ctx, base);
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

DEFINE_REX_FUNC(sub_82355260) {
	REX_FUNC_PROLOGUE();
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r11,-32107
	ctx.r11.s64 = -2104164352;
	// addi r11,r11,-20136
	ctx.r11.s64 = ctx.r11.s64 + -20136;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r11,284
	ctx.r11.s64 = ctx.r11.s64 + 284;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82355278:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82355288
	if (ctx.cr6.eq) goto loc_82355288;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82355288:
	// addi r11,r11,288
	ctx.r11.s64 = ctx.r11.s64 + 288;
	// bdnz 0x82355278
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82355278;
	// lis r9,-32107
	ctx.r9.s64 = -2104164352;
	// lis r8,-32107
	ctx.r8.s64 = -2104164352;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r10,-19272(r9)
	REX_STORE_U32(ctx.r9.u32 + -19272, ctx.r10.u32);
	// stw r10,-19268(r8)
	REX_STORE_U32(ctx.r8.u32 + -19268, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82356088) {
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
	// bl 0x82350c48
	ctx.lr = 0x823560A0;
	sub_82350C48(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823560b8
	if (ctx.cr6.eq) goto loc_823560B8;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82353030
	ctx.lr = 0x823560B0;
	sub_82353030(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82350b88
	ctx.lr = 0x823560B8;
	sub_82350B88(ctx, base);
loc_823560B8:
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

DEFINE_REX_FUNC(sub_8235A318) {
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
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// bgt cr6,0x8235a3a8
	if (ctx.cr6.gt) goto loc_8235A3A8;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8235a348
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8235A348;
	// bdzf 4*cr6+eq,0x8235a350
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8235A350;
	// bne cr6,0x8235a358
	if (!ctx.cr6.eq) goto loc_8235A358;
	// li r11,1841
	ctx.r11.s64 = 1841;
	// b 0x8235a35c
	goto loc_8235A35C;
loc_8235A348:
	// li r11,1842
	ctx.r11.s64 = 1842;
	// b 0x8235a35c
	goto loc_8235A35C;
loc_8235A350:
	// li r11,1843
	ctx.r11.s64 = 1843;
	// b 0x8235a35c
	goto loc_8235A35C;
loc_8235A358:
	// li r11,1844
	ctx.r11.s64 = 1844;
loc_8235A35C:
	// lis r10,-32134
	ctx.r10.s64 = -2105933824;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r10,5496
	ctx.r11.s64 = ctx.r10.s64 + 5496;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r9,r8
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8235a3a8
	if (ctx.cr6.eq) goto loc_8235A3A8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82355e28
	ctx.lr = 0x8235A380;
	sub_82355E28(ctx, base);
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8235a3a8
	if (ctx.cr6.eq) goto loc_8235A3A8;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82356008
	ctx.lr = 0x8235A398;
	sub_82356008(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8232ca38
	ctx.lr = 0x8235A3A8;
	sub_8232CA38(ctx, base);
loc_8235A3A8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8235DB60) {
	REX_FUNC_PROLOGUE();
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x8235d998
	sub_8235D998(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8235E420) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lhz r11,10(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,-21820(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -21820);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8235FED8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0280
	ctx.lr = 0x8235FEE0;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt cr6,0x823602c0
	if (ctx.cr6.lt) goto loc_823602C0;
	// cmpwi cr6,r5,2
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 2, ctx.xer);
	// bge cr6,0x823602c0
	if (!ctx.cr6.lt) goto loc_823602C0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x823602c0
	if (ctx.cr6.eq) goto loc_823602C0;
	// extsb r11,r6
	ctx.r11.s64 = ctx.r6.s8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x823602c0
	if (ctx.cr6.gt) goto loc_823602C0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82360078
	if (ctx.cr6.eq) goto loc_82360078;
	// bdz 0x82360078
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82360078;
	// bdnz 0x82360184
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82360184;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r30,r11,-22000
	ctx.r30.s64 = ctx.r11.s64 + -22000;
	// ori r23,r10,32768
	ctx.r23.u64 = ctx.r10.u64 | 32768;
loc_8235FF44:
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8235ff58
	if (!ctx.cr6.eq) goto loc_8235FF58;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x823602c0
	if (ctx.cr6.eq) goto loc_823602C0;
loc_8235FF58:
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r9,128
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 128, ctx.xer);
	// bge cr6,0x8235ff70
	if (!ctx.cr6.lt) goto loc_8235FF70;
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// b 0x8235ffcc
	goto loc_8235FFCC;
loc_8235FF70:
	// rlwinm r11,r9,0,24,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r11,192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 192, ctx.xer);
	// bne cr6,0x8235ff98
	if (!ctx.cr6.eq) goto loc_8235FF98;
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823602c0
	if (ctx.cr6.eq) goto loc_823602C0;
	// rlwimi r11,r9,6,21,25
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0x7C0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF83F);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// clrlwi r4,r11,21
	ctx.r4.u64 = ctx.r11.u32 & 0x7FF;
	// b 0x8235ffcc
	goto loc_8235FFCC;
loc_8235FF98:
	// rlwinm r11,r9,0,24,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r11,224
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 224, ctx.xer);
	// bne cr6,0x8235ff44
	if (!ctx.cr6.eq) goto loc_8235FF44;
	// lbz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823602c0
	if (ctx.cr6.eq) goto loc_823602C0;
	// lbz r11,1(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823602c0
	if (ctx.cr6.eq) goto loc_823602C0;
	// rlwimi r10,r9,6,0,25
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0) | (ctx.r10.u64 & 0xFFFFFFFF0000003F);
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// rlwimi r11,r10,6,0,25
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0) | (ctx.r11.u64 & 0xFFFFFFFF0000003F);
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
loc_8235FFCC:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8235f008
	ctx.lr = 0x8235FFD8;
	sub_8235F008(ctx, base);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82360024
	if (!ctx.cr6.eq) goto loc_82360024;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r10,65520
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65520, ctx.xer);
	// blt cr6,0x82360008
	if (ctx.cr6.lt) goto loc_82360008;
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// lbzx r9,r11,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// subfic r7,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.u64 = static_cast<uint64_t>(0) - ctx.r8.u64;
	// rlwinm r6,r8,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// addme r5,r6
	temp.u8 = (ctx.r6.u32 + 0xFFFFFFFFu < ctx.r6.u32) | (ctx.r6.u32 + 0xFFFFFFFFu + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ctx.r6.u64 + ctx.xer.ca + 0xFFFFFFFFFFFFFFFFull;
	ctx.xer.ca = temp.u8;
	// and r26,r5,r8
	ctx.r26.u64 = ctx.r5.u64 & ctx.r8.u64;
loc_82360008:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,65520
	ctx.r11.u64 = ctx.r11.u64 | 65520;
	// subfc r10,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// subf r8,r9,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r9.u64;
	// and r24,r8,r4
	ctx.r24.u64 = ctx.r8.u64 & ctx.r4.u64;
	// b 0x82360064
	goto loc_82360064;
loc_82360024:
	// clrlwi r11,r24,16
	ctx.r11.u64 = ctx.r24.u32 & 0xFFFF;
	// cmplwi cr6,r11,65530
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65530, ctx.xer);
	// bne cr6,0x82360060
	if (!ctx.cr6.eq) goto loc_82360060;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// subf. r11,r23,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r23.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x82360060
	if (ctx.cr0.lt) goto loc_82360060;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bge cr6,0x82360060
	if (!ctx.cr6.lt) goto loc_82360060;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,2403(r27)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r27.u32 + 2403);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x8235fed8
	ctx.lr = 0x82360060;
	sub_8235FED8(ctx, base);
loc_82360060:
	// addi r26,r26,-1
	ctx.r26.s64 = ctx.r26.s64 + -1;
loc_82360064:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// cmpwi cr6,r22,1024
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1024, ctx.xer);
	// blt cr6,0x8235ff44
	if (ctx.cr6.lt) goto loc_8235FF44;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d0
	__restgprlr_22(ctx, base);
	return;
loc_82360078:
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r30,r11,-22000
	ctx.r30.s64 = ctx.r11.s64 + -22000;
	// ori r23,r10,32768
	ctx.r23.u64 = ctx.r10.u64 | 32768;
loc_82360088:
	// lbz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823600a0
	if (ctx.cr6.eq) goto loc_823600A0;
	// lbz r9,1(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x823600a8
	if (!ctx.cr6.eq) goto loc_823600A8;
loc_823600A0:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x823602c0
	if (ctx.cr6.eq) goto loc_823602C0;
loc_823600A8:
	// lbz r10,2403(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 2403);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823600c8
	if (!ctx.cr6.eq) goto loc_823600C8;
	// lbz r10,1(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// clrlwi r4,r8,16
	ctx.r4.u64 = ctx.r8.u32 & 0xFFFF;
	// b 0x823600d4
	goto loc_823600D4;
loc_823600C8:
	// lbz r10,1(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// rlwimi r10,r11,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
loc_823600D4:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// bl 0x8235f008
	ctx.lr = 0x823600E4;
	sub_8235F008(ctx, base);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82360130
	if (!ctx.cr6.eq) goto loc_82360130;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r10,65520
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65520, ctx.xer);
	// blt cr6,0x82360114
	if (ctx.cr6.lt) goto loc_82360114;
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// lbzx r9,r11,r30
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// subfic r7,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.u64 = static_cast<uint64_t>(0) - ctx.r8.u64;
	// rlwinm r6,r8,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// addme r5,r6
	temp.u8 = (ctx.r6.u32 + 0xFFFFFFFFu < ctx.r6.u32) | (ctx.r6.u32 + 0xFFFFFFFFu + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ctx.r6.u64 + ctx.xer.ca + 0xFFFFFFFFFFFFFFFFull;
	ctx.xer.ca = temp.u8;
	// and r26,r5,r8
	ctx.r26.u64 = ctx.r5.u64 & ctx.r8.u64;
loc_82360114:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,65520
	ctx.r11.u64 = ctx.r11.u64 | 65520;
	// subfc r10,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// subf r8,r9,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r9.u64;
	// and r24,r8,r4
	ctx.r24.u64 = ctx.r8.u64 & ctx.r4.u64;
	// b 0x82360170
	goto loc_82360170;
loc_82360130:
	// clrlwi r11,r24,16
	ctx.r11.u64 = ctx.r24.u32 & 0xFFFF;
	// cmplwi cr6,r11,65530
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65530, ctx.xer);
	// bne cr6,0x8236016c
	if (!ctx.cr6.eq) goto loc_8236016C;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// subf. r11,r23,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r23.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x8236016c
	if (ctx.cr0.lt) goto loc_8236016C;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bge cr6,0x8236016c
	if (!ctx.cr6.lt) goto loc_8236016C;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,2403(r27)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r27.u32 + 2403);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x8235fed8
	ctx.lr = 0x8236016C;
	sub_8235FED8(ctx, base);
loc_8236016C:
	// addi r26,r26,-1
	ctx.r26.s64 = ctx.r26.s64 + -1;
loc_82360170:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// cmpwi cr6,r22,1024
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1024, ctx.xer);
	// blt cr6,0x82360088
	if (ctx.cr6.lt) goto loc_82360088;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d0
	__restgprlr_22(ctx, base);
	return;
loc_82360184:
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
	// ori r23,r9,32768
	ctx.r23.u64 = ctx.r9.u64 | 32768;
	// ori r29,r8,49152
	ctx.r29.u64 = ctx.r8.u64 | 49152;
	// addi r30,r11,10768
	ctx.r30.s64 = ctx.r11.s64 + 10768;
	// addi r28,r10,-22000
	ctx.r28.s64 = ctx.r10.s64 + -22000;
loc_823601A8:
	// lbz r10,1(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823601bc
	if (!ctx.cr6.eq) goto loc_823601BC;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x823602c0
	if (ctx.cr6.eq) goto loc_823602C0;
loc_823601BC:
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// blt cr6,0x823601f4
	if (ctx.cr6.lt) goto loc_823601F4;
	// cmplwi cr6,r11,159
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 159, ctx.xer);
	// bgt cr6,0x823601f4
	if (ctx.cr6.gt) goto loc_823601F4;
	// lbz r10,1(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rlwimi r10,r11,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r8,r23,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r23.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r4,r7,r30
	ctx.r4.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r30.u32);
	// b 0x8236021c
	goto loc_8236021C;
loc_823601F4:
	// cmplwi cr6,r11,224
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 224, ctx.xer);
	// blt cr6,0x82360218
	if (ctx.cr6.lt) goto loc_82360218;
	// lbzu r10,1(r31)
	ea = 1 + ctx.r31.u32;
	ctx.r10.u64 = REX_LOAD_U8(ea);
	ctx.r31.u32 = ea;
	// rlwimi r10,r11,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r10,r29,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r29.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r4,r9,r30
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r30.u32);
	// b 0x8236021c
	goto loc_8236021C;
loc_82360218:
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
loc_8236021C:
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8235f008
	ctx.lr = 0x82360228;
	sub_8235F008(ctx, base);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82360274
	if (!ctx.cr6.eq) goto loc_82360274;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r10,65520
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65520, ctx.xer);
	// blt cr6,0x82360258
	if (ctx.cr6.lt) goto loc_82360258;
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// lbzx r9,r11,r28
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r28.u32);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// subfic r7,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.u64 = static_cast<uint64_t>(0) - ctx.r8.u64;
	// rlwinm r6,r8,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// addme r5,r6
	temp.u8 = (ctx.r6.u32 + 0xFFFFFFFFu < ctx.r6.u32) | (ctx.r6.u32 + 0xFFFFFFFFu + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ctx.r6.u64 + ctx.xer.ca + 0xFFFFFFFFFFFFFFFFull;
	ctx.xer.ca = temp.u8;
	// and r26,r5,r8
	ctx.r26.u64 = ctx.r5.u64 & ctx.r8.u64;
loc_82360258:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,65520
	ctx.r11.u64 = ctx.r11.u64 | 65520;
	// subfc r10,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// subf r8,r9,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r9.u64;
	// and r24,r8,r4
	ctx.r24.u64 = ctx.r8.u64 & ctx.r4.u64;
	// b 0x823602b4
	goto loc_823602B4;
loc_82360274:
	// clrlwi r11,r24,16
	ctx.r11.u64 = ctx.r24.u32 & 0xFFFF;
	// cmplwi cr6,r11,65530
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65530, ctx.xer);
	// bne cr6,0x823602b0
	if (!ctx.cr6.eq) goto loc_823602B0;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// subf. r11,r23,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r23.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x823602b0
	if (ctx.cr0.lt) goto loc_823602B0;
	// cmpwi cr6,r11,256
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 256, ctx.xer);
	// bge cr6,0x823602b0
	if (!ctx.cr6.lt) goto loc_823602B0;
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,2403(r27)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r27.u32 + 2403);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r4,r11,18792
	ctx.r4.s64 = ctx.r11.s64 + 18792;
	// bl 0x8235fed8
	ctx.lr = 0x823602B0;
	sub_8235FED8(ctx, base);
loc_823602B0:
	// addi r26,r26,-1
	ctx.r26.s64 = ctx.r26.s64 + -1;
loc_823602B4:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// cmpwi cr6,r22,1024
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 1024, ctx.xer);
	// blt cr6,0x823601a8
	if (ctx.cr6.lt) goto loc_823601A8;
loc_823602C0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8237E4E8) {
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
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// addi r3,r3,104
	ctx.r3.s64 = ctx.r3.s64 + 104;
	// addi r10,r11,-14040
	ctx.r10.s64 = ctx.r11.s64 + -14040;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x8223cdb0
	ctx.lr = 0x8237E510;
	sub_8223CDB0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r8,r9,3000
	ctx.r8.s64 = ctx.r9.s64 + 3000;
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

DEFINE_REX_FUNC(sub_8237F8F8) {
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
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r31,r11,23664
	ctx.r31.s64 = ctx.r11.s64 + 23664;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237f934
	if (ctx.cr6.eq) goto loc_8237F934;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237f938
	if (ctx.cr6.eq) goto loc_8237F938;
loc_8237F934:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237F938:
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// beq cr6,0x8237f95c
	if (ctx.cr6.eq) goto loc_8237F95C;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237f960
	if (!ctx.cr6.eq) goto loc_8237F960;
loc_8237F95C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237F960:
	// lwz r11,856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 856);
	// lwz r3,428(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237f984
	if (ctx.cr6.eq) goto loc_8237F984;
	// lwz r8,432(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 432);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8237f988
	if (ctx.cr6.eq) goto loc_8237F988;
loc_8237F984:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237F988:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237f9a4
	if (ctx.cr6.eq) goto loc_8237F9A4;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8237f9a8
	if (!ctx.cr6.eq) goto loc_8237F9A8;
loc_8237F9A4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8237F9A8:
	// bl 0x82230a58
	ctx.lr = 0x8237F9AC;
	sub_82230A58(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237f9cc
	if (ctx.cr6.eq) goto loc_8237F9CC;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237f9d0
	if (ctx.cr6.eq) goto loc_8237F9D0;
loc_8237F9CC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237F9D0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,30048(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237f9f0
	if (ctx.cr6.eq) goto loc_8237F9F0;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237f9f4
	if (!ctx.cr6.eq) goto loc_8237F9F4;
loc_8237F9F0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237F9F4:
	// lwz r11,856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 856);
	// lwz r10,452(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 452);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237fa18
	if (ctx.cr6.eq) goto loc_8237FA18;
	// lwz r7,456(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 456);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8237fa1c
	if (ctx.cr6.eq) goto loc_8237FA1C;
loc_8237FA18:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237FA1C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237fa38
	if (ctx.cr6.eq) goto loc_8237FA38;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8237fa3c
	if (!ctx.cr6.eq) goto loc_8237FA3C;
loc_8237FA38:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237FA3C:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82230a58
	ctx.lr = 0x8237FA44;
	sub_82230A58(ctx, base);
	// bl 0x82269d88
	ctx.lr = 0x8237FA48;
	sub_82269D88(ctx, base);
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

DEFINE_REX_FUNC(sub_8238D958) {
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
	// addi r9,r11,-13244
	ctx.r9.s64 = ctx.r11.s64 + -13244;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8238d98c
	if (ctx.cr6.eq) goto loc_8238D98C;
	// bl 0x82573808
	ctx.lr = 0x8238D988;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8238D98C:
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

DEFINE_REX_FUNC(sub_8238E010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x8238E018;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// bl 0x82218220
	ctx.lr = 0x8238E02C;
	sub_82218220(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r3,r31,116
	ctx.r3.s64 = ctx.r31.s64 + 116;
	// addi r10,r11,21404
	ctx.r10.s64 = ctx.r11.s64 + 21404;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82226838
	ctx.lr = 0x8238E040;
	sub_82226838(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r30,260(r31)
	REX_STORE_U8(ctx.r31.u32 + 260, ctx.r30.u8);
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// stb r30,261(r31)
	REX_STORE_U8(ctx.r31.u32 + 261, ctx.r30.u8);
	// li r25,1
	ctx.r25.s64 = 1;
	// stb r30,262(r31)
	REX_STORE_U8(ctx.r31.u32 + 262, ctx.r30.u8);
	// addi r29,r10,23664
	ctx.r29.s64 = ctx.r10.s64 + 23664;
	// stb r30,263(r31)
	REX_STORE_U8(ctx.r31.u32 + 263, ctx.r30.u8);
	// lfs f0,2880(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,264(r31)
	REX_STORE_U8(ctx.r31.u32 + 264, ctx.r30.u8);
	// stb r30,265(r31)
	REX_STORE_U8(ctx.r31.u32 + 265, ctx.r30.u8);
	// stb r30,266(r31)
	REX_STORE_U8(ctx.r31.u32 + 266, ctx.r30.u8);
	// stb r30,267(r31)
	REX_STORE_U8(ctx.r31.u32 + 267, ctx.r30.u8);
	// stb r30,268(r31)
	REX_STORE_U8(ctx.r31.u32 + 268, ctx.r30.u8);
	// stb r30,269(r31)
	REX_STORE_U8(ctx.r31.u32 + 269, ctx.r30.u8);
	// stb r30,270(r31)
	REX_STORE_U8(ctx.r31.u32 + 270, ctx.r30.u8);
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
	// stw r30,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r30.u32);
	// stb r30,276(r31)
	REX_STORE_U8(ctx.r31.u32 + 276, ctx.r30.u8);
	// stb r30,277(r31)
	REX_STORE_U8(ctx.r31.u32 + 277, ctx.r30.u8);
	// stb r30,278(r31)
	REX_STORE_U8(ctx.r31.u32 + 278, ctx.r30.u8);
	// stb r30,279(r31)
	REX_STORE_U8(ctx.r31.u32 + 279, ctx.r30.u8);
	// stb r30,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r30.u8);
	// stb r30,281(r31)
	REX_STORE_U8(ctx.r31.u32 + 281, ctx.r30.u8);
	// stb r30,282(r31)
	REX_STORE_U8(ctx.r31.u32 + 282, ctx.r30.u8);
	// stb r30,283(r31)
	REX_STORE_U8(ctx.r31.u32 + 283, ctx.r30.u8);
	// stb r30,284(r31)
	REX_STORE_U8(ctx.r31.u32 + 284, ctx.r30.u8);
	// stb r30,285(r31)
	REX_STORE_U8(ctx.r31.u32 + 285, ctx.r30.u8);
	// stb r30,286(r31)
	REX_STORE_U8(ctx.r31.u32 + 286, ctx.r30.u8);
	// stb r30,287(r31)
	REX_STORE_U8(ctx.r31.u32 + 287, ctx.r30.u8);
	// stb r30,288(r31)
	REX_STORE_U8(ctx.r31.u32 + 288, ctx.r30.u8);
	// stb r30,289(r31)
	REX_STORE_U8(ctx.r31.u32 + 289, ctx.r30.u8);
	// stb r30,290(r31)
	REX_STORE_U8(ctx.r31.u32 + 290, ctx.r30.u8);
	// stb r30,291(r31)
	REX_STORE_U8(ctx.r31.u32 + 291, ctx.r30.u8);
	// stb r30,292(r31)
	REX_STORE_U8(ctx.r31.u32 + 292, ctx.r30.u8);
	// stb r30,293(r31)
	REX_STORE_U8(ctx.r31.u32 + 293, ctx.r30.u8);
	// stb r30,294(r31)
	REX_STORE_U8(ctx.r31.u32 + 294, ctx.r30.u8);
	// stb r30,295(r31)
	REX_STORE_U8(ctx.r31.u32 + 295, ctx.r30.u8);
	// stb r30,296(r31)
	REX_STORE_U8(ctx.r31.u32 + 296, ctx.r30.u8);
	// stb r30,297(r31)
	REX_STORE_U8(ctx.r31.u32 + 297, ctx.r30.u8);
	// stw r30,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r30.u32);
	// stw r30,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r30.u32);
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
	// stw r30,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r30.u32);
	// stw r30,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r30.u32);
	// stw r30,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r30.u32);
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// stw r30,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r30.u32);
	// stb r30,332(r31)
	REX_STORE_U8(ctx.r31.u32 + 332, ctx.r30.u8);
	// stb r30,333(r31)
	REX_STORE_U8(ctx.r31.u32 + 333, ctx.r30.u8);
	// stb r30,334(r31)
	REX_STORE_U8(ctx.r31.u32 + 334, ctx.r30.u8);
	// stw r30,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r30.u32);
	// stb r30,340(r31)
	REX_STORE_U8(ctx.r31.u32 + 340, ctx.r30.u8);
	// stb r30,341(r31)
	REX_STORE_U8(ctx.r31.u32 + 341, ctx.r30.u8);
	// stw r30,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r30.u32);
	// stw r30,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r30.u32);
	// stw r30,352(r31)
	REX_STORE_U32(ctx.r31.u32 + 352, ctx.r30.u32);
	// stw r30,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r30.u32);
	// stw r30,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r30.u32);
	// stw r30,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r30.u32);
	// stw r30,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r30.u32);
	// stb r30,372(r31)
	REX_STORE_U8(ctx.r31.u32 + 372, ctx.r30.u8);
	// stb r30,373(r31)
	REX_STORE_U8(ctx.r31.u32 + 373, ctx.r30.u8);
	// lwz r11,30008(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 30008);
	// lwz r7,60(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// andc r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 & ~ctx.r11.u64;
	// stw r6,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r6.u32);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238e178
	if (ctx.cr6.eq) goto loc_8238E178;
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// beq cr6,0x8238e17c
	if (ctx.cr6.eq) goto loc_8238E17C;
loc_8238E178:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_8238E17C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r26,-32256
	ctx.r26.s64 = -2113929216;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8238e1a0
	if (ctx.cr6.eq) goto loc_8238E1A0;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8238e1a4
	if (!ctx.cr6.eq) goto loc_8238E1A4;
loc_8238E1A0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8238E1A4:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,908(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 908);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238bea0
	ctx.lr = 0x8238E1B4;
	sub_8238BEA0(ctx, base);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238e1d4
	if (ctx.cr6.eq) goto loc_8238E1D4;
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// beq cr6,0x8238e1d8
	if (ctx.cr6.eq) goto loc_8238E1D8;
loc_8238E1D4:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_8238E1D8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8238e1f8
	if (ctx.cr6.eq) goto loc_8238E1F8;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8238e1fc
	if (!ctx.cr6.eq) goto loc_8238E1FC;
loc_8238E1F8:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8238E1FC:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r3,908(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 908);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8238bea0
	ctx.lr = 0x8238E20C;
	sub_8238BEA0(ctx, base);
	// stw r30,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// stb r30,262(r31)
	REX_STORE_U8(ctx.r31.u32 + 262, ctx.r30.u8);
	// stb r30,260(r31)
	REX_STORE_U8(ctx.r31.u32 + 260, ctx.r30.u8);
	// stb r30,263(r31)
	REX_STORE_U8(ctx.r31.u32 + 263, ctx.r30.u8);
	// stb r25,261(r31)
	REX_STORE_U8(ctx.r31.u32 + 261, ctx.r25.u8);
	// stb r25,265(r31)
	REX_STORE_U8(ctx.r31.u32 + 265, ctx.r25.u8);
	// stb r25,267(r31)
	REX_STORE_U8(ctx.r31.u32 + 267, ctx.r25.u8);
	// stb r30,270(r31)
	REX_STORE_U8(ctx.r31.u32 + 270, ctx.r30.u8);
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238e250
	if (ctx.cr6.eq) goto loc_8238E250;
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// beq cr6,0x8238e254
	if (ctx.cr6.eq) goto loc_8238E254;
loc_8238E250:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_8238E254:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8238e274
	if (ctx.cr6.eq) goto loc_8238E274;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8238e278
	if (!ctx.cr6.eq) goto loc_8238E278;
loc_8238E274:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8238E278:
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r9,120(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 120);
	// lwz r8,88(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 88);
	// stb r9,264(r31)
	REX_STORE_U8(ctx.r31.u32 + 264, ctx.r9.u8);
	// lbz r7,119(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 119);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// stb r7,266(r31)
	REX_STORE_U8(ctx.r31.u32 + 266, ctx.r7.u8);
	// lbz r6,116(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 116);
	// stb r6,268(r31)
	REX_STORE_U8(ctx.r31.u32 + 268, ctx.r6.u8);
	// lbz r5,118(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 118);
	// stw r30,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r30.u32);
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r30,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stb r5,269(r31)
	REX_STORE_U8(ctx.r31.u32 + 269, ctx.r5.u8);
	// bctrl 
	ctx.lr = 0x8238E2C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,269(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 269);
	// lis r4,-32248
	ctx.r4.s64 = -2113404928;
	// stb r30,276(r31)
	REX_STORE_U8(ctx.r31.u32 + 276, ctx.r30.u8);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// stb r30,277(r31)
	REX_STORE_U8(ctx.r31.u32 + 277, ctx.r30.u8);
	// addi r3,r4,-12988
	ctx.r3.s64 = ctx.r4.s64 + -12988;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r3
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// addis r7,r8,-32768
	ctx.r7.s64 = ctx.r8.s64 + -2147483648;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stw r30,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// stw r8,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r8.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r5,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r5.u32);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238e31c
	if (ctx.cr6.eq) goto loc_8238E31C;
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// beq cr6,0x8238e320
	if (ctx.cr6.eq) goto loc_8238E320;
loc_8238E31C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_8238E320:
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// lwz r10,30048(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 30048);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8238e340
	if (ctx.cr6.eq) goto loc_8238E340;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8238e344
	if (!ctx.cr6.eq) goto loc_8238E344;
loc_8238E340:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8238E344:
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238e39c
	if (ctx.cr6.eq) goto loc_8238E39C;
	// lwz r3,288(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8238e370
	if (ctx.cr6.eq) goto loc_8238E370;
	// lwz r8,292(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 292);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8238e374
	if (ctx.cr6.eq) goto loc_8238E374;
loc_8238E370:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8238E374:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238e390
	if (ctx.cr6.eq) goto loc_8238E390;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8238e394
	if (!ctx.cr6.eq) goto loc_8238E394;
loc_8238E390:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8238E394:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822844e8
	ctx.lr = 0x8238E39C;
	sub_822844E8(ctx, base);
loc_8238E39C:
	// bl 0x822f3cc8
	ctx.lr = 0x8238E3A0;
	sub_822F3CC8(ctx, base);
	// stw r3,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r3.u32);
	// bl 0x822f3cc8
	ctx.lr = 0x8238E3A8;
	sub_822F3CC8(ctx, base);
	// stw r3,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8239FEB0) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r9,r11,472
	ctx.r9.s64 = ctx.r11.s64 + 472;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r6,r10,-9297
	ctx.r6.s64 = ctx.r10.s64 + -9297;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r3,96
	ctx.r3.s64 = ctx.r3.s64 + 96;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x8239FEFC;
	sub_822518D8(ctx, base);
	// li r5,180
	ctx.r5.s64 = 180;
	// stw r30,668(r31)
	REX_STORE_U32(ctx.r31.u32 + 668, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,672(r31)
	REX_STORE_U32(ctx.r31.u32 + 672, ctx.r30.u32);
	// addi r3,r31,464
	ctx.r3.s64 = ctx.r31.s64 + 464;
	// bl 0x826a03b0
	ctx.lr = 0x8239FF14;
	rexcrt_memset(ctx, base);
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

DEFINE_REX_FUNC(sub_823A3670) {
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
	ctx.lr = 0x823A368C;
	sub_822237E0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x822680f8
	ctx.lr = 0x823A3694;
	sub_822680F8(ctx, base);
	// rlwinm r11,r3,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a36e8
	if (ctx.cr6.eq) goto loc_823A36E8;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x822680f8
	ctx.lr = 0x823A36A8;
	sub_822680F8(ctx, base);
	// rlwinm r11,r3,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a36e8
	if (ctx.cr6.eq) goto loc_823A36E8;
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,-30472
	ctx.r8.s64 = ctx.r10.s64 + -30472;
	// addi r6,r9,-9019
	ctx.r6.s64 = ctx.r9.s64 + -9019;
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
	ctx.lr = 0x823A36E8;
	sub_822518D8(ctx, base);
loc_823A36E8:
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

DEFINE_REX_FUNC(sub_823A65C0) {
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
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823a65f8
	if (ctx.cr6.eq) goto loc_823A65F8;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823a65fc
	if (ctx.cr6.eq) goto loc_823A65FC;
loc_823A65F8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823A65FC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823a6620
	if (ctx.cr6.eq) goto loc_823A6620;
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
	// bne cr6,0x823a6624
	if (!ctx.cr6.eq) goto loc_823A6624;
loc_823A6620:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823A6624:
	// lbz r11,281(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 281);
	// lbz r9,276(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 276);
	// lwz r31,848(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 848);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823a665c
	if (!ctx.cr6.eq) goto loc_823A665C;
	// lbz r4,280(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 280);
	// bl 0x8238df08
	ctx.lr = 0x823A6640;
	sub_8238DF08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823a67f0
	ctx.lr = 0x823A6650;
	sub_823A67F0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,576(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// b 0x823a66b0
	goto loc_823A66B0;
loc_823A665C:
	// lwz r11,380(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x823a6698
	if (!ctx.cr6.eq) goto loc_823A6698;
	// lbz r4,280(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 280);
	// bl 0x8238df08
	ctx.lr = 0x823A6670;
	sub_8238DF08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823a67f0
	ctx.lr = 0x823A6680;
	sub_823A67F0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,564(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 564);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823A6694;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x823a66b8
	goto loc_823A66B8;
loc_823A6698:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823a67f0
	ctx.lr = 0x823A66A8;
	sub_823A67F0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,552(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 552);
loc_823A66B0:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823A66B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823A66B8:
	// bl 0x822efb00
	ctx.lr = 0x823A66BC;
	sub_822EFB00(ctx, base);
	// bl 0x822cbe90
	ctx.lr = 0x823A66C0;
	sub_822CBE90(ctx, base);
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

DEFINE_REX_FUNC(sub_823ACA20) {
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
	// lwz r11,1208(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1208);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823aca58
	if (ctx.cr6.eq) goto loc_823ACA58;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,1212(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 1212);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823aca5c
	if (ctx.cr6.eq) goto loc_823ACA5C;
loc_823ACA58:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823ACA5C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823aca80
	if (ctx.cr6.eq) goto loc_823ACA80;
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
	// bne cr6,0x823aca84
	if (!ctx.cr6.eq) goto loc_823ACA84;
loc_823ACA80:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823ACA84:
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// lwz r3,92(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x8254b028
	ctx.lr = 0x823ACA94;
	sub_8254B028(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// li r10,12
	ctx.r10.s64 = 12;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f12,f0
	ctx.f12.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f11,f13
	ctx.f11.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.f12.u32);
	// stfiwx f11,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.f11.u32);
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

DEFINE_REX_FUNC(sub_823B4110) {
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
	// beq cr6,0x823b41ac
	if (ctx.cr6.eq) goto loc_823B41AC;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823b4154
	if (ctx.cr6.eq) goto loc_823B4154;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823b4158
	if (ctx.cr6.eq) goto loc_823B4158;
loc_823B4154:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823B4158:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823b417c
	if (ctx.cr6.eq) goto loc_823B417C;
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
	// bne cr6,0x823b4180
	if (!ctx.cr6.eq) goto loc_823B4180;
loc_823B417C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823B4180:
	// lwz r3,848(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 848);
	// bl 0x82223748
	ctx.lr = 0x823B4188;
	sub_82223748(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823b41ac
	if (ctx.cr6.eq) goto loc_823B41AC;
	// bl 0x82170cb0
	ctx.lr = 0x823B4194;
	sub_82170CB0(ctx, base);
	// lwz r3,848(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 848);
	// bl 0x82222380
	ctx.lr = 0x823B419C;
	sub_82222380(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,588(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 588);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823B41AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823B41AC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823B7370) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x823B7378;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r29,r11,30672
	ctx.r29.s64 = ctx.r11.s64 + 30672;
	// addi r30,r3,80
	ctx.r30.s64 = ctx.r3.s64 + 80;
	// addi r31,r29,4
	ctx.r31.s64 = ctx.r29.s64 + 4;
loc_823B7390:
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82298900
	ctx.lr = 0x823B7398;
	sub_82298900(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// addi r9,r29,28
	ctx.r9.s64 = ctx.r29.s64 + 28;
	// cmpw cr6,r31,r9
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r9.s32, ctx.xer);
	// lwzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// stwu r8,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r30.u32 = ea;
	// blt cr6,0x823b7390
	if (ctx.cr6.lt) goto loc_823B7390;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82298900
	ctx.lr = 0x823B73C0;
	sub_82298900(ctx, base);
	// stw r3,92(r28)
	REX_STORE_U32(ctx.r28.u32 + 92, ctx.r3.u32);
	// bl 0x822988a0
	ctx.lr = 0x823B73C8;
	sub_822988A0(ctx, base);
	// srawi r11,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 1;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r8,r9,r3
	ctx.r8.u64 = ctx.r3.u64 - ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x823b73e4
	if (!ctx.cr0.eq) goto loc_823B73E4;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,92(r28)
	REX_STORE_U32(ctx.r28.u32 + 92, ctx.r11.u32);
loc_823B73E4:
	// addi r31,r28,96
	ctx.r31.s64 = ctx.r28.s64 + 96;
	// li r30,3
	ctx.r30.s64 = 3;
	// li r29,-1
	ctx.r29.s64 = -1;
loc_823B73F0:
	// lwz r11,92(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 92);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823b740c
	if (!ctx.cr6.eq) goto loc_823B740C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82298900
	ctx.lr = 0x823B7404;
	sub_82298900(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// b 0x823b7410
	goto loc_823B7410;
loc_823B740C:
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_823B7410:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x823b73f0
	if (!ctx.cr0.eq) goto loc_823B73F0;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82298900
	ctx.lr = 0x823B7424;
	sub_82298900(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,5
	ctx.r10.s64 = ctx.r11.s64 + 5;
	// stw r10,108(r28)
	REX_STORE_U32(ctx.r28.u32 + 108, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823BC3C8) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823bc46c
	if (!ctx.cr6.eq) goto loc_823BC46C;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823bc408
	if (ctx.cr6.eq) goto loc_823BC408;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823bc40c
	if (ctx.cr6.eq) goto loc_823BC40C;
loc_823BC408:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823BC40C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823bc430
	if (ctx.cr6.eq) goto loc_823BC430;
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
	// bne cr6,0x823bc434
	if (!ctx.cr6.eq) goto loc_823BC434;
loc_823BC430:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823BC434:
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r4,1020(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 1020);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,8400
	ctx.r3.s64 = 8400;
	// bl 0x82219630
	ctx.lr = 0x823BC450;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823bc4a0
	if (ctx.cr6.eq) goto loc_823BC4A0;
	// bl 0x823bbaa8
	ctx.lr = 0x823BC45C;
	sub_823BBAA8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_823BC46C:
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,8400
	ctx.r3.s64 = 8400;
	// bl 0x82219630
	ctx.lr = 0x823BC484;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823bc4a0
	if (ctx.cr6.eq) goto loc_823BC4A0;
	// bl 0x823bbaa8
	ctx.lr = 0x823BC490;
	sub_823BBAA8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_823BC4A0:
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

DEFINE_REX_FUNC(sub_823C0410) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x823C0418;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// lis r27,-32104
	ctx.r27.s64 = -2103967744;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// bge cr6,0x823c047c
	if (!ctx.cr6.lt) goto loc_823C047C;
loc_823C043C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823c047c
	if (ctx.cr6.eq) goto loc_823C047C;
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x823c047c
	if (ctx.cr6.eq) goto loc_823C047C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823c047c
	if (ctx.cr6.eq) goto loc_823C047C;
	// cmpw cr6,r11,r26
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r26.s32, ctx.xer);
	// beq cr6,0x823c047c
	if (ctx.cr6.eq) goto loc_823C047C;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,-17576(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + -17576);
	// bl 0x823feed8
	ctx.lr = 0x823C0470;
	sub_823FEED8(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x823c047c
	if (ctx.cr6.eq) goto loc_823C047C;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_823C047C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// blt cr6,0x823c043c
	if (ctx.cr6.lt) goto loc_823C043C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823C4398) {
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
	// addi r9,r11,-644
	ctx.r9.s64 = ctx.r11.s64 + -644;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823c43cc
	if (ctx.cr6.eq) goto loc_823C43CC;
	// bl 0x82573808
	ctx.lr = 0x823C43C8;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_823C43CC:
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

DEFINE_REX_FUNC(sub_823C5018) {
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
	// lis r10,18
	ctx.r10.s64 = 1179648;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r9,r10,988
	ctx.r9.u64 = ctx.r10.u64 | 988;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwzx r10,r11,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x823c5054
	if (!ctx.cr6.gt) goto loc_823C5054;
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
loc_823C5054:
	// addis r4,r11,18
	ctx.r4.s64 = ctx.r11.s64 + 1179648;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// addi r4,r4,1012
	ctx.r4.s64 = ctx.r4.s64 + 1012;
	// bl 0x826a1130
	ctx.lr = 0x823C5064;
	rexcrt_memcpy(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823C70D8) {
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
	// bl 0x823bb1b0
	ctx.lr = 0x823C70F4;
	sub_823BB1B0(ctx, base);
	// li r8,154
	ctx.r8.s64 = 154;
	// addi r11,r31,200
	ctx.r11.s64 = ctx.r31.s64 + 200;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// addi r11,r31,224
	ctx.r11.s64 = ctx.r31.s64 + 224;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_823C7110:
	// stw r9,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r9.u32);
	// addi r9,r11,-24
	ctx.r9.s64 = ctx.r11.s64 + -24;
	// stw r11,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r11.u32);
	// stw r10,-16(r11)
	REX_STORE_U32(ctx.r11.u32 + -16, ctx.r10.u32);
	// stw r10,-12(r11)
	REX_STORE_U32(ctx.r11.u32 + -12, ctx.r10.u32);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// bdnz 0x823c7110
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823C7110;
	// stw r10,3892(r31)
	REX_STORE_U32(ctx.r31.u32 + 3892, ctx.r10.u32);
	// stw r10,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// stw r10,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r10.u32);
	// stw r10,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_823C8F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0274
	ctx.lr = 0x823C8F70;
	__savegprlr_19(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28608(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28608);
	// addi r21,r3,28608
	ctx.r21.s64 = ctx.r3.s64 + 28608;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C8F94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// bne cr6,0x823c99f0
	if (!ctx.cr6.eq) goto loc_823C99F0;
	// li r3,12
	ctx.r3.s64 = 12;
	// lwz r30,8928(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// bl 0x822685b8
	ctx.lr = 0x823C8FAC;
	sub_822685B8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c9010
	if (ctx.cr6.eq) goto loc_823C9010;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2331
	ctx.r3.s64 = 2331;
	// bl 0x8235ce40
	ctx.lr = 0x823C8FC4;
	sub_8235CE40(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r11,8932(r31)
	REX_STORE_U32(ctx.r31.u32 + 8932, ctx.r11.u32);
	// lis r9,-32195
	ctx.r9.s64 = -2109931520;
	// addi r11,r10,-178
	ctx.r11.s64 = ctx.r10.s64 + -178;
	// li r20,0
	ctx.r20.s64 = 0;
	// addi r8,r9,-30640
	ctx.r8.s64 = ctx.r9.s64 + -30640;
	// addi r6,r11,-2
	ctx.r6.s64 = ctx.r11.s64 + -2;
	// stw r20,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r20.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r20,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r20.u32);
	// stw r20,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r20.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x823C9004;
	sub_822518D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x826a02c4
	__restgprlr_19(ctx, base);
	return;
loc_823C9010:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268578
	ctx.lr = 0x823C9018;
	sub_82268578(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c907c
	if (ctx.cr6.eq) goto loc_823C907C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2332
	ctx.r3.s64 = 2332;
	// bl 0x8235ce40
	ctx.lr = 0x823C9030;
	sub_8235CE40(ctx, base);
	// lis r11,-32195
	ctx.r11.s64 = -2109931520;
	// li r20,0
	ctx.r20.s64 = 0;
	// addi r10,r11,-30640
	ctx.r10.s64 = ctx.r11.s64 + -30640;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r20,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r20.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// stw r9,8932(r31)
	REX_STORE_U32(ctx.r31.u32 + 8932, ctx.r9.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// addi r11,r8,-178
	ctx.r11.s64 = ctx.r8.s64 + -178;
	// stw r20,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r20.u32);
	// stw r20,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r20.u32);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x823C9070;
	sub_822518D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x826a02c4
	__restgprlr_19(ctx, base);
	return;
loc_823C907C:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x822680f8
	ctx.lr = 0x823C9084;
	sub_822680F8(ctx, base);
	// rlwinm r11,r3,0,16,16
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c910c
	if (ctx.cr6.eq) goto loc_823C910C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C90A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824aa178
	ctx.lr = 0x823C90B4;
	sub_824AA178(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r31,8940
	ctx.r3.s64 = ctx.r31.s64 + 8940;
	// lwz r4,16(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// bl 0x8226bf28
	ctx.lr = 0x823C90C4;
	sub_8226BF28(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82218850
	ctx.lr = 0x823C90CC;
	sub_82218850(ctx, base);
	// lis r8,-32195
	ctx.r8.s64 = -2109931520;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r20,0
	ctx.r20.s64 = 0;
	// addi r5,r8,-29528
	ctx.r5.s64 = ctx.r8.s64 + -29528;
	// addi r6,r7,-178
	ctx.r6.s64 = ctx.r7.s64 + -178;
	// stw r20,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r20.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// stw r20,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r20.u32);
	// stw r20,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r20.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x823C9100;
	sub_822518D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x826a02c4
	__restgprlr_19(ctx, base);
	return;
loc_823C910C:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268170
	ctx.lr = 0x823C9114;
	sub_82268170(ctx, base);
	// rlwinm r11,r3,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x100000;
	// li r20,0
	ctx.r20.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9144
	if (ctx.cr6.eq) goto loc_823C9144;
	// lwz r11,8928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9138
	if (ctx.cr6.eq) goto loc_823C9138;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x823c91d0
	goto loc_823C91D0;
loc_823C9138:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x823c91d0
	goto loc_823C91D0;
loc_823C9144:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268170
	ctx.lr = 0x823C914C;
	sub_82268170(ctx, base);
	// rlwinm r11,r3,0,10,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9178
	if (ctx.cr6.eq) goto loc_823C9178;
	// lwz r11,8928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x823c91d4
	if (ctx.cr6.lt) goto loc_823C91D4;
	// stw r20,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r20.u32);
	// b 0x823c91d4
	goto loc_823C91D4;
loc_823C9178:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268198
	ctx.lr = 0x823C9180;
	sub_82268198(ctx, base);
	// rlwinm r11,r3,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c91a0
	if (ctx.cr6.eq) goto loc_823C91A0;
	// lwz r11,8928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c91d4
	if (ctx.cr6.eq) goto loc_823C91D4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x823c91d0
	goto loc_823C91D0;
loc_823C91A0:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268198
	ctx.lr = 0x823C91A8;
	sub_82268198(ctx, base);
	// rlwinm r11,r3,0,10,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c91d4
	if (ctx.cr6.eq) goto loc_823C91D4;
	// lwz r11,8928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x823c91d4
	if (ctx.cr6.lt) goto loc_823C91D4;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_823C91D0:
	// stw r11,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r11.u32);
loc_823C91D4:
	// li r3,12
	ctx.r3.s64 = 12;
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// bl 0x82268198
	ctx.lr = 0x823C91E0;
	sub_82268198(ctx, base);
	// rlwinm r11,r3,0,9,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x400000;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// li r28,-255
	ctx.r28.s64 = -255;
	// ori r24,r10,15120
	ctx.r24.u64 = ctx.r10.u64 | 15120;
	// li r22,255
	ctx.r22.s64 = 255;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9280
	if (ctx.cr6.eq) goto loc_823C9280;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268148
	ctx.lr = 0x823C9204;
	sub_82268148(ctx, base);
	// rlwinm r11,r3,0,10,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x300000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823c9280
	if (!ctx.cr6.eq) goto loc_823C9280;
	// lwz r11,8936(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c931c
	if (ctx.cr6.eq) goto loc_823C931C;
	// lwz r10,8928(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// blt cr6,0x823c9254
	if (ctx.cr6.lt) goto loc_823C9254;
	// addi r11,r11,-6
	ctx.r11.s64 = ctx.r11.s64 + -6;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// stw r11,8936(r31)
	REX_STORE_U32(ctx.r31.u32 + 8936, ctx.r11.u32);
	// blt cr6,0x823c9248
	if (ctx.cr6.lt) goto loc_823C9248;
	// addi r11,r10,-6
	ctx.r11.s64 = ctx.r10.s64 + -6;
	// stwx r28,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r28.u32);
	// stw r11,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r11.u32);
	// b 0x823c9318
	goto loc_823C9318;
loc_823C9248:
	// stw r20,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r20.u32);
	// stwx r28,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r28.u32);
	// b 0x823c9318
	goto loc_823C9318;
loc_823C9254:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x823c926c
	if (!ctx.cr6.lt) goto loc_823C926C;
	// stw r20,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r20.u32);
	// stw r20,8936(r31)
	REX_STORE_U32(ctx.r31.u32 + 8936, ctx.r20.u32);
	// stwx r28,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r28.u32);
	// b 0x823c9318
	goto loc_823C9318;
loc_823C926C:
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r20,8936(r31)
	REX_STORE_U32(ctx.r31.u32 + 8936, ctx.r20.u32);
	// stwx r28,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r28.u32);
	// stw r11,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r11.u32);
	// b 0x823c9318
	goto loc_823C9318;
loc_823C9280:
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268198
	ctx.lr = 0x823C9288;
	sub_82268198(ctx, base);
	// rlwinm r11,r3,0,8,8
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x800000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c931c
	if (ctx.cr6.eq) goto loc_823C931C;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82268148
	ctx.lr = 0x823C929C;
	sub_82268148(ctx, base);
	// rlwinm r11,r3,0,10,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x300000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823c931c
	if (!ctx.cr6.eq) goto loc_823C931C;
	// lwz r10,8936(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r9,r10,6
	ctx.r9.s64 = ctx.r10.s64 + 6;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x823c931c
	if (!ctx.cr6.lt) goto loc_823C931C;
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x823c92e4
	if (!ctx.cr6.lt) goto loc_823C92E4;
	// lwz r10,8928(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// stw r9,8936(r31)
	REX_STORE_U32(ctx.r31.u32 + 8936, ctx.r9.u32);
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x823c930c
	if (!ctx.cr6.lt) goto loc_823C930C;
	// stw r10,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r10.u32);
	// b 0x823c9314
	goto loc_823C9314;
loc_823C92E4:
	// lwz r9,8928(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// subf r8,r10,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r10,r11,-6
	ctx.r10.s64 = ctx.r11.s64 + -6;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r10,8936(r31)
	REX_STORE_U32(ctx.r31.u32 + 8936, ctx.r10.u32);
	// addi r9,r9,-6
	ctx.r9.s64 = ctx.r9.s64 + -6;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r9.u32);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823c9314
	if (!ctx.cr6.lt) goto loc_823C9314;
loc_823C930C:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8928(r31)
	REX_STORE_U32(ctx.r31.u32 + 8928, ctx.r11.u32);
loc_823C9314:
	// stwx r22,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r22.u32);
loc_823C9318:
	// li r29,1
	ctx.r29.s64 = 1;
loc_823C931C:
	// lwz r11,8928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// lis r10,2
	ctx.r10.s64 = 131072;
	// lis r9,3
	ctx.r9.s64 = 196608;
	// ori r25,r10,45920
	ctx.r25.u64 = ctx.r10.u64 | 45920;
	// ori r23,r9,12384
	ctx.r23.u64 = ctx.r9.u64 | 12384;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823c9340
	if (!ctx.cr6.eq) goto loc_823C9340;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x823c95ac
	if (ctx.cr6.eq) goto loc_823C95AC;
loc_823C9340:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2330
	ctx.r3.s64 = 2330;
	// bl 0x8235ce40
	ctx.lr = 0x823C9350;
	sub_8235CE40(ctx, base);
	// lwz r11,8928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8928);
	// lwz r10,8936(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823c9370
	if (!ctx.cr6.lt) goto loc_823C9370;
	// stw r11,8936(r31)
	REX_STORE_U32(ctx.r31.u32 + 8936, ctx.r11.u32);
	// stwx r28,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r28.u32);
	// b 0x823c9398
	goto loc_823C9398;
loc_823C9370:
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x823c938c
	if (ctx.cr6.lt) goto loc_823C938C;
	// addi r10,r11,-5
	ctx.r10.s64 = ctx.r11.s64 + -5;
	// stwx r22,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r22.u32);
	// stw r10,8936(r31)
	REX_STORE_U32(ctx.r31.u32 + 8936, ctx.r10.u32);
	// b 0x823c9398
	goto loc_823C9398;
loc_823C938C:
	// subfic r10,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r29.u64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r8,r30
	ctx.r30.u64 = ctx.r8.u64 & ctx.r30.u64;
loc_823C9398:
	// lwz r10,8936(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// add r3,r31,r23
	ctx.r3.u64 = ctx.r31.u64 + ctx.r23.u64;
	// lwzx r9,r31,r23
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,68(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 68);
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r5,r11,30
	ctx.r5.s64 = ctx.r11.s64 + 30;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// bctrl 
	ctx.lr = 0x823C93D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823c95ac
	if (ctx.cr6.eq) goto loc_823C95AC;
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r28,40
	ctx.r28.s64 = 40;
	// mr r27,r20
	ctx.r27.u64 = ctx.r20.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x823c953c
	if (!ctx.cr6.gt) goto loc_823C953C;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lis r11,2
	ctx.r11.s64 = 131072;
	// add r30,r31,r25
	ctx.r30.u64 = ctx.r31.u64 + ctx.r25.u64;
	// addi r29,r29,-544
	ctx.r29.s64 = ctx.r29.s64 + -544;
	// ori r26,r11,12928
	ctx.r26.u64 = ctx.r11.u64 | 12928;
loc_823C9400:
	// lwz r11,8936(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823c94dc
	if (ctx.cr6.lt) goto loc_823C94DC;
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x823c94dc
	if (!ctx.cr6.lt) goto loc_823C94DC;
	// subf r19,r26,r30
	ctx.r19.u64 = ctx.r30.u64 - ctx.r26.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C943C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lwz r8,96(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823C9454;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// extsh r28,r28
	ctx.r28.s64 = ctx.r28.s16;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r7,r28,16
	ctx.r7.s64 = ctx.r28.s64 + 16;
	// li r4,88
	ctx.r4.s64 = 88;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C947C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,96(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823C9494;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r7,r28,4
	ctx.r7.s64 = ctx.r28.s64 + 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C94B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,96(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823C94D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r7,r28,72
	ctx.r7.s64 = ctx.r28.s64 + 72;
	// extsh r28,r7
	ctx.r28.s64 = ctx.r7.s16;
	// b 0x823c9524
	goto loc_823C9524;
loc_823C94DC:
	// subf r3,r26,r30
	ctx.r3.u64 = ctx.r30.u64 - ctx.r26.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C94F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823C950C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,100(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x823C9524;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823C9524:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r29,r29,1120
	ctx.r29.s64 = ctx.r29.s64 + 1120;
	// addi r30,r30,320
	ctx.r30.s64 = ctx.r30.s64 + 320;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823c9400
	if (ctx.cr6.lt) goto loc_823C9400;
loc_823C953C:
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// lwz r11,8936(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// addi r3,r3,14480
	ctx.r3.s64 = ctx.r3.s64 + 14480;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// ble cr6,0x823c9560
	if (!ctx.cr6.gt) goto loc_823C9560;
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x823c9568
	goto loc_823C9568;
loc_823C9560:
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
loc_823C9568:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C9570;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// lwz r11,8936(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r3,r3,14800
	ctx.r3.s64 = ctx.r3.s64 + 14800;
	// addi r9,r11,6
	ctx.r9.s64 = ctx.r11.s64 + 6;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bge cr6,0x823c959c
	if (!ctx.cr6.lt) goto loc_823C959C;
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x823c95a4
	goto loc_823C95A4;
loc_823C959C:
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
loc_823C95A4:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823C95AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_823C95AC:
	// lwzx r11,r31,r24
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// add r10,r31,r24
	ctx.r10.u64 = ctx.r31.u64 + ctx.r24.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823c960c
	if (ctx.cr6.eq) goto loc_823C960C;
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// addze. r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x823c95d0
	if (ctx.cr0.eq) goto loc_823C95D0;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// b 0x823c95e4
	goto loc_823C95E4;
loc_823C95D0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x823c95e0
	if (!ctx.cr6.gt) goto loc_823C95E0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x823c95e4
	goto loc_823C95E4;
loc_823C95E0:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_823C95E4:
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// divw r5,r10,r22
	ctx.r5.u64 = uint32_t((ctx.r22.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r22.s32 == -1)) ? ctx.r10.s32 / ctx.r22.s32 : 0);
	// bl 0x82367ba8
	ctx.lr = 0x823C960C;
	sub_82367BA8(ctx, base);
loc_823C960C:
	// lwz r10,8936(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x823c9624
	if (ctx.cr6.lt) goto loc_823C9624;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_823C9624:
	// lwz r11,8936(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8936);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823c9694
	if (!ctx.cr6.lt) goto loc_823C9694;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r8,r11,88
	ctx.r8.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(88));
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r30,r11,r10
	ctx.r30.u64 = ctx.r10.u64 - ctx.r11.u64;
	// rlwinm r7,r7,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// add r9,r8,r31
	ctx.r9.u64 = ctx.r8.u64 + ctx.r31.u64;
	// add r6,r7,r31
	ctx.r6.u64 = ctx.r7.u64 + ctx.r31.u64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r29,r9,128
	ctx.r29.s64 = ctx.r9.s64 + 128;
	// add r28,r6,r25
	ctx.r28.u64 = ctx.r6.u64 + ctx.r25.u64;
	// ori r27,r11,65535
	ctx.r27.u64 = ctx.r11.u64 | 65535;
loc_823C965C:
	// bl 0x823c7898
	ctx.lr = 0x823C9660;
	sub_823C7898(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x823c6f80
	ctx.lr = 0x823C9668;
	sub_823C6F80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x82368f00
	ctx.lr = 0x823C9684;
	sub_82368F00(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,88
	ctx.r29.s64 = ctx.r29.s64 + 88;
	// addi r28,r28,320
	ctx.r28.s64 = ctx.r28.s64 + 320;
	// bne 0x823c965c
	if (!ctx.cr0.eq) goto loc_823C965C;
loc_823C9694:
	// lis r11,26214
	ctx.r11.s64 = 1717960704;
	// lwz r9,72(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwzx r8,r31,r23
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r23.u32);
	// li r7,80
	ctx.r7.s64 = 80;
	// ori r6,r11,26215
	ctx.r6.u64 = ctx.r11.u64 | 26215;
	// add r3,r31,r23
	ctx.r3.u64 = ctx.r31.u64 + ctx.r23.u64;
	// mulhw r5,r9,r6
	ctx.r5.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32)) >> 32;
	// lwz r4,92(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 92);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// srawi r11,r5,4
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 4;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r9,r10,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r10.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// subf r6,r9,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r9.u64;
	// divw r4,r6,r7
	ctx.r4.u64 = uint32_t((ctx.r7.s32 && !(ctx.r6.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r6.s32 / ctx.r7.s32 : 0);
	// subfic r11,r4,255
	ctx.xer.ca = ctx.r4.u32 <= 255;
	ctx.r11.u64 = static_cast<uint64_t>(255) - ctx.r4.u64;
	// clrlwi r4,r11,24
	ctx.r4.u64 = ctx.r11.u32 & 0xFF;
	// bctrl 
	ctx.lr = 0x823C96F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821ca958
	ctx.lr = 0x823C96F8;
	sub_821CA958(ctx, base);
	// ori r30,r3,32
	ctx.r30.u64 = ctx.r3.u64 | 32;
	// bl 0x8235e5a0
	ctx.lr = 0x823C9700;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823c9710
	if (!ctx.cr6.eq) goto loc_823C9710;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// b 0x823c9720
	goto loc_823C9720;
loc_823C9710:
	// bl 0x8235e5a0
	ctx.lr = 0x823C9714;
	sub_8235E5A0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x823616a0
	ctx.lr = 0x823C971C;
	sub_823616A0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823C9720:
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r29,r11,23664
	ctx.r29.s64 = ctx.r11.s64 + 23664;
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9748
	if (ctx.cr6.eq) goto loc_823C9748;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823c974c
	if (ctx.cr6.eq) goto loc_823C974C;
loc_823C9748:
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_823C974C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r27,-32256
	ctx.r27.s64 = -2113929216;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823c9774
	if (ctx.cr6.eq) goto loc_823C9774;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r9,30048(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x823c9778
	if (!ctx.cr6.eq) goto loc_823C9778;
loc_823C9774:
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_823C9778:
	// lwz r10,900(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 900);
	// li r28,-1
	ctx.r28.s64 = -1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823c97a0
	if (ctx.cr6.eq) goto loc_823C97A0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r4,9538
	ctx.r4.s64 = 9538;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x823719b0
	ctx.lr = 0x823C979C;
	sub_823719B0(ctx, base);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
loc_823C97A0:
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// ble cr6,0x823c984c
	if (!ctx.cr6.gt) goto loc_823C984C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821ca958
	ctx.lr = 0x823C97B4;
	sub_821CA958(ctx, base);
	// ori r30,r3,202
	ctx.r30.u64 = ctx.r3.u64 | 202;
	// bl 0x8235e5a0
	ctx.lr = 0x823C97BC;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823c97cc
	if (!ctx.cr6.eq) goto loc_823C97CC;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// b 0x823c97dc
	goto loc_823C97DC;
loc_823C97CC:
	// bl 0x8235e5a0
	ctx.lr = 0x823C97D0;
	sub_8235E5A0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x823616a0
	ctx.lr = 0x823C97D8;
	sub_823616A0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823C97DC:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c97fc
	if (ctx.cr6.eq) goto loc_823C97FC;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823c9800
	if (ctx.cr6.eq) goto loc_823C9800;
loc_823C97FC:
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_823C9800:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823c9824
	if (ctx.cr6.eq) goto loc_823C9824;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r9,30048(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x823c9828
	if (!ctx.cr6.eq) goto loc_823C9828;
loc_823C9824:
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_823C9828:
	// lwz r10,900(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 900);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823c984c
	if (ctx.cr6.eq) goto loc_823C984C;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r4,9535
	ctx.r4.s64 = 9535;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x823719b0
	ctx.lr = 0x823C9848;
	sub_823719B0(ctx, base);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
loc_823C984C:
	// lis r10,3
	ctx.r10.s64 = 196608;
	// ori r9,r10,15124
	ctx.r9.u64 = ctx.r10.u64 | 15124;
	// lwzx r5,r31,r9
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x823c98c0
	if (ctx.cr6.eq) goto loc_823C98C0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c987c
	if (ctx.cr6.eq) goto loc_823C987C;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823c9880
	if (ctx.cr6.eq) goto loc_823C9880;
loc_823C987C:
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_823C9880:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823c98a0
	if (ctx.cr6.eq) goto loc_823C98A0;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r9,30048(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x823c98a4
	if (!ctx.cr6.eq) goto loc_823C98A4;
loc_823C98A0:
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_823C98A4:
	// lwz r3,900(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 900);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823c98c0
	if (ctx.cr6.eq) goto loc_823C98C0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823719b0
	ctx.lr = 0x823C98C0;
	sub_823719B0(ctx, base);
loc_823C98C0:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821ca958
	ctx.lr = 0x823C98C8;
	sub_821CA958(ctx, base);
	// ori r31,r3,23
	ctx.r31.u64 = ctx.r3.u64 | 23;
	// bl 0x8235e5a0
	ctx.lr = 0x823C98D0;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823c98e0
	if (!ctx.cr6.eq) goto loc_823C98E0;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// b 0x823c98f0
	goto loc_823C98F0;
loc_823C98E0:
	// bl 0x8235e5a0
	ctx.lr = 0x823C98E4;
	sub_8235E5A0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823616a0
	ctx.lr = 0x823C98EC;
	sub_823616A0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823C98F0:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9910
	if (ctx.cr6.eq) goto loc_823C9910;
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823c9914
	if (ctx.cr6.eq) goto loc_823C9914;
loc_823C9910:
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_823C9914:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823c9934
	if (ctx.cr6.eq) goto loc_823C9934;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x823c9938
	if (!ctx.cr6.eq) goto loc_823C9938;
loc_823C9934:
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_823C9938:
	// lwz r11,900(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 900);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c9958
	if (ctx.cr6.eq) goto loc_823C9958;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r4,-8154
	ctx.r4.s64 = -8154;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x823719b0
	ctx.lr = 0x823C9958;
	sub_823719B0(ctx, base);
loc_823C9958:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821ca958
	ctx.lr = 0x823C9960;
	sub_821CA958(ctx, base);
	// ori r31,r3,33
	ctx.r31.u64 = ctx.r3.u64 | 33;
	// bl 0x8235e5a0
	ctx.lr = 0x823C9968;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823c9978
	if (!ctx.cr6.eq) goto loc_823C9978;
	// mr r5,r20
	ctx.r5.u64 = ctx.r20.u64;
	// b 0x823c9988
	goto loc_823C9988;
loc_823C9978:
	// bl 0x8235e5a0
	ctx.lr = 0x823C997C;
	sub_8235E5A0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823616a0
	ctx.lr = 0x823C9984;
	sub_823616A0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_823C9988:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c99a8
	if (ctx.cr6.eq) goto loc_823C99A8;
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x823c99ac
	if (ctx.cr6.eq) goto loc_823C99AC;
loc_823C99A8:
	// mr r10,r20
	ctx.r10.u64 = ctx.r20.u64;
loc_823C99AC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823c99cc
	if (ctx.cr6.eq) goto loc_823C99CC;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x823c99d0
	if (!ctx.cr6.eq) goto loc_823C99D0;
loc_823C99CC:
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
loc_823C99D0:
	// lwz r11,900(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 900);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823c99f0
	if (ctx.cr6.eq) goto loc_823C99F0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x823719b0
	ctx.lr = 0x823C99F0;
	sub_823719B0(ctx, base);
loc_823C99F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x826a02c4
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240DAB0) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8240DD20) {
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
	// addi r3,r3,564
	ctx.r3.s64 = ctx.r3.s64 + 564;
	// bl 0x823cb9e8
	ctx.lr = 0x8240DD3C;
	sub_823CB9E8(ctx, base);
	// cmpwi cr6,r3,9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 9, ctx.xer);
	// bne cr6,0x8240dd5c
	if (!ctx.cr6.eq) goto loc_8240DD5C;
	// lwz r11,512(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 512);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,3
	ctx.r11.s64 = 3;
	// bne cr6,0x8240dd58
	if (!ctx.cr6.eq) goto loc_8240DD58;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8240DD58:
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
loc_8240DD5C:
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

DEFINE_REX_FUNC(sub_82410A58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82410A60;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82410398
	ctx.lr = 0x82410A6C;
	sub_82410398(ctx, base);
	// lwz r11,504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 504);
	// addi r29,r30,488
	ctx.r29.s64 = ctx.r30.s64 + 488;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82410a98
	if (ctx.cr6.eq) goto loc_82410A98;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// beq cr6,0x82410a9c
	if (ctx.cr6.eq) goto loc_82410A9C;
loc_82410A98:
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
loc_82410A9C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82410ba0
	if (ctx.cr6.eq) goto loc_82410BA0;
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
	// beq cr6,0x82410ba0
	if (ctx.cr6.eq) goto loc_82410BA0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82410ba0
	if (ctx.cr6.eq) goto loc_82410BA0;
	// lwz r3,16(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82410ae8
	if (ctx.cr6.eq) goto loc_82410AE8;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// beq cr6,0x82410aec
	if (ctx.cr6.eq) goto loc_82410AEC;
loc_82410AE8:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82410AEC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82410b08
	if (ctx.cr6.eq) goto loc_82410B08;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82410b0c
	if (!ctx.cr6.eq) goto loc_82410B0C;
loc_82410B08:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82410B0C:
	// bl 0x823c7b38
	ctx.lr = 0x82410B10;
	sub_823C7B38(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82410b30
	if (!ctx.cr6.eq) goto loc_82410B30;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// lis r10,-32191
	ctx.r10.s64 = -2109669376;
	// addi r11,r11,13763
	ctx.r11.s64 = ctx.r11.s64 + 13763;
	// addi r9,r10,4632
	ctx.r9.s64 = ctx.r10.s64 + 4632;
	// addi r6,r11,-2
	ctx.r6.s64 = ctx.r11.s64 + -2;
	// b 0x82410bc0
	goto loc_82410BC0;
loc_82410B30:
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82410b44
	if (ctx.cr6.eq) goto loc_82410B44;
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// cmplwi cr6,r11,600
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 600, ctx.xer);
	// blt cr6,0x82410be0
	if (ctx.cr6.lt) goto loc_82410BE0;
loc_82410B44:
	// bl 0x82408030
	ctx.lr = 0x82410B48;
	sub_82408030(ctx, base);
	// li r4,31
	ctx.r4.s64 = 31;
	// bl 0x82407148
	ctx.lr = 0x82410B50;
	sub_82407148(ctx, base);
	// stw r28,544(r30)
	REX_STORE_U32(ctx.r30.u32 + 544, ctx.r28.u32);
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// lis r10,-32191
	ctx.r10.s64 = -2109669376;
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// addi r11,r11,13763
	ctx.r11.s64 = ctx.r11.s64 + 13763;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// addi r9,r10,4648
	ctx.r9.s64 = ctx.r10.s64 + 4648;
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// addi r3,r30,96
	ctx.r3.s64 = ctx.r30.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x82410B88;
	sub_822518D8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8243fa70
	ctx.lr = 0x82410B90;
	sub_8243FA70(ctx, base);
	// stw r28,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_82410BA0:
	// bl 0x82408030
	ctx.lr = 0x82410BA4;
	sub_82408030(ctx, base);
	// li r4,31
	ctx.r4.s64 = 31;
	// bl 0x82407148
	ctx.lr = 0x82410BAC;
	sub_82407148(ctx, base);
	// lis r11,-32191
	ctx.r11.s64 = -2109669376;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r28,544(r30)
	REX_STORE_U32(ctx.r30.u32 + 544, ctx.r28.u32);
	// addi r9,r11,4648
	ctx.r9.s64 = ctx.r11.s64 + 4648;
	// addi r6,r10,13763
	ctx.r6.s64 = ctx.r10.s64 + 13763;
loc_82410BC0:
	// addi r3,r30,96
	ctx.r3.s64 = ctx.r30.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x82410BE0;
	sub_822518D8(ctx, base);
loc_82410BE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241AB38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// li r5,27
	ctx.r5.s64 = 27;
	// stb r11,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r11.u8);
	// addi r4,r9,15448
	ctx.r4.s64 = ctx.r9.s64 + 15448;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb218
	ctx.lr = 0x8241AB70;
	sub_821CB218(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8241aac0
	ctx.lr = 0x8241AB7C;
	sub_8241AAC0(ctx, base);
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,19548(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 19548);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8241ab9c
	if (ctx.cr6.eq) goto loc_8241AB9C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8241AB9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8241AB9C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8241ABB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82512ec8
	ctx.lr = 0x8241ABB8;
	sub_82512EC8(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r8,r9,15436
	ctx.r8.s64 = ctx.r9.s64 + 15436;
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// bl 0x821caf40
	ctx.lr = 0x8241ABCC;
	sub_821CAF40(ctx, base);
	// lwz r7,104(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x8241abe0
	if (ctx.cr6.lt) goto loc_8241ABE0;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82573808
	ctx.lr = 0x8241ABE0;
	sub_82573808(ctx, base);
loc_8241ABE0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82422090) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824220c4
	if (!ctx.cr6.eq) goto loc_824220C4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f1,2880(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f1.f64 = double(temp.f32);
	// b 0x824220e8
	goto loc_824220E8;
loc_824220C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8242b550
	ctx.lr = 0x824220CC;
	sub_8242B550(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,2884(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f13,f1
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// fsubs f12,f0,f1
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// fmadds f1,f12,f31,f11
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f31.f64, ctx.f11.f64)));
loc_824220E8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82423780) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82423BA0) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,16664
	ctx.r4.s64 = ctx.r11.s64 + 16664;
	// bl 0x82423798
	ctx.lr = 0x82423BC0;
	sub_82423798(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82423bfc
	if (ctx.cr6.lt) goto loc_82423BFC;
	// beq cr6,0x82423be4
	if (ctx.cr6.eq) goto loc_82423BE4;
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
loc_82423BE4:
	// addi r3,r31,20
	ctx.r3.s64 = ctx.r31.s64 + 20;
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
loc_82423BFC:
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
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

DEFINE_REX_FUNC(sub_82424828) {
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
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,16664
	ctx.r4.s64 = ctx.r11.s64 + 16664;
	// bl 0x82423798
	ctx.lr = 0x82424848;
	sub_82423798(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82424888
	if (ctx.cr6.lt) goto loc_82424888;
	// beq cr6,0x82424870
	if (ctx.cr6.eq) goto loc_82424870;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f1,2884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f1.f64 = double(temp.f32);
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
loc_82424870:
	// lfs f1,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
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
loc_82424888:
	// lfs f1,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
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

DEFINE_REX_FUNC(sub_82426920) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,16720
	ctx.r4.s64 = ctx.r11.s64 + 16720;
	// bl 0x82423798
	ctx.lr = 0x82426940;
	sub_82423798(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82426950
	if (!ctx.cr6.eq) goto loc_82426950;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
loc_82426950:
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

DEFINE_REX_FUNC(sub_82427EF8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,16748
	ctx.r4.s64 = ctx.r11.s64 + 16748;
	// bl 0x82423798
	ctx.lr = 0x82427F18;
	sub_82423798(ctx, base);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82427f28
	if (!ctx.cr6.eq) goto loc_82427F28;
	// addi r3,r31,32
	ctx.r3.s64 = ctx.r31.s64 + 32;
loc_82427F28:
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

DEFINE_REX_FUNC(sub_82429988) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,16800
	ctx.r4.s64 = ctx.r11.s64 + 16800;
	// bl 0x82423798
	ctx.lr = 0x824299A8;
	sub_82423798(ctx, base);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x824299e0
	if (ctx.cr6.gt) goto loc_824299E0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x824299c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824299C8;
	// bdzf 4*cr6+eq,0x824299c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824299C8;
	// bne cr6,0x824299c8
	if (!ctx.cr6.eq) goto loc_824299C8;
loc_824299C8:
	// addi r3,r31,32
	ctx.r3.s64 = ctx.r31.s64 + 32;
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
loc_824299E0:
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

DEFINE_REX_FUNC(sub_8242BFD8) {
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
	// addi r11,r4,-4
	ctx.r11.s64 = ctx.r4.s64 + -4;
	// cmplwi cr6,r11,491
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 491, ctx.xer);
	// bgt cr6,0x8242cff0
	if (ctx.cr6.gt) goto loc_8242CFF0;
	// lis r12,-32189
	ctx.r12.s64 = -2109538304;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-16376
	ctx.r12.s64 = ctx.r12.s64 + -16376;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_8242C7B8;
	case 1:
		goto loc_8242C7C4;
	case 2:
		goto loc_8242C7D0;
	case 3:
		goto loc_8242C7DC;
	case 4:
		goto loc_8242CFF0;
	case 5:
		goto loc_8242C7E8;
	case 6:
		goto loc_8242C7F4;
	case 7:
		goto loc_8242C800;
	case 8:
		goto loc_8242C80C;
	case 9:
		goto loc_8242C818;
	case 10:
		goto loc_8242C824;
	case 11:
		goto loc_8242C830;
	case 12:
		goto loc_8242CFF0;
	case 13:
		goto loc_8242CFF0;
	case 14:
		goto loc_8242C83C;
	case 15:
		goto loc_8242C848;
	case 16:
		goto loc_8242C854;
	case 17:
		goto loc_8242C860;
	case 18:
		goto loc_8242C86C;
	case 19:
		goto loc_8242C878;
	case 20:
		goto loc_8242C884;
	case 21:
		goto loc_8242C890;
	case 22:
		goto loc_8242CFF0;
	case 23:
		goto loc_8242CFF0;
	case 24:
		goto loc_8242C89C;
	case 25:
		goto loc_8242C8A8;
	case 26:
		goto loc_8242C8B4;
	case 27:
		goto loc_8242C8C0;
	case 28:
		goto loc_8242CFF0;
	case 29:
		goto loc_8242C8CC;
	case 30:
		goto loc_8242C8D8;
	case 31:
		goto loc_8242C8E4;
	case 32:
		goto loc_8242C8F0;
	case 33:
		goto loc_8242C8FC;
	case 34:
		goto loc_8242C908;
	case 35:
		goto loc_8242C914;
	case 36:
		goto loc_8242CFF0;
	case 37:
		goto loc_8242CFF0;
	case 38:
		goto loc_8242CFF0;
	case 39:
		goto loc_8242CFF0;
	case 40:
		goto loc_8242CFF0;
	case 41:
		goto loc_8242CFF0;
	case 42:
		goto loc_8242CFF0;
	case 43:
		goto loc_8242CFF0;
	case 44:
		goto loc_8242CFF0;
	case 45:
		goto loc_8242CFF0;
	case 46:
		goto loc_8242CFF0;
	case 47:
		goto loc_8242CFF0;
	case 48:
		goto loc_8242CFF0;
	case 49:
		goto loc_8242CFF0;
	case 50:
		goto loc_8242CFF0;
	case 51:
		goto loc_8242CFF0;
	case 52:
		goto loc_8242CFF0;
	case 53:
		goto loc_8242CFF0;
	case 54:
		goto loc_8242CFF0;
	case 55:
		goto loc_8242CFF0;
	case 56:
		goto loc_8242CFF0;
	case 57:
		goto loc_8242CFF0;
	case 58:
		goto loc_8242CFF0;
	case 59:
		goto loc_8242CFF0;
	case 60:
		goto loc_8242CFF0;
	case 61:
		goto loc_8242CFF0;
	case 62:
		goto loc_8242CFF0;
	case 63:
		goto loc_8242CFF0;
	case 64:
		goto loc_8242CFF0;
	case 65:
		goto loc_8242CFF0;
	case 66:
		goto loc_8242C920;
	case 67:
		goto loc_8242CFF0;
	case 68:
		goto loc_8242CFF0;
	case 69:
		goto loc_8242CFF0;
	case 70:
		goto loc_8242CFF0;
	case 71:
		goto loc_8242CFF0;
	case 72:
		goto loc_8242CFF0;
	case 73:
		goto loc_8242CFF0;
	case 74:
		goto loc_8242CFF0;
	case 75:
		goto loc_8242CFF0;
	case 76:
		goto loc_8242CFF0;
	case 77:
		goto loc_8242CFF0;
	case 78:
		goto loc_8242CFF0;
	case 79:
		goto loc_8242CFF0;
	case 80:
		goto loc_8242CFF0;
	case 81:
		goto loc_8242CFF0;
	case 82:
		goto loc_8242CFF0;
	case 83:
		goto loc_8242CFF0;
	case 84:
		goto loc_8242CFF0;
	case 85:
		goto loc_8242CFF0;
	case 86:
		goto loc_8242CFF0;
	case 87:
		goto loc_8242CFF0;
	case 88:
		goto loc_8242CFF0;
	case 89:
		goto loc_8242CFF0;
	case 90:
		goto loc_8242CFF0;
	case 91:
		goto loc_8242CFF0;
	case 92:
		goto loc_8242CFF0;
	case 93:
		goto loc_8242CFF0;
	case 94:
		goto loc_8242CFF0;
	case 95:
		goto loc_8242CFF0;
	case 96:
		goto loc_8242CFF0;
	case 97:
		goto loc_8242CFF0;
	case 98:
		goto loc_8242CFF0;
	case 99:
		goto loc_8242CFF0;
	case 100:
		goto loc_8242CFF0;
	case 101:
		goto loc_8242CFF0;
	case 102:
		goto loc_8242CFF0;
	case 103:
		goto loc_8242CFF0;
	case 104:
		goto loc_8242CFF0;
	case 105:
		goto loc_8242CFF0;
	case 106:
		goto loc_8242CFF0;
	case 107:
		goto loc_8242CFF0;
	case 108:
		goto loc_8242CFF0;
	case 109:
		goto loc_8242C92C;
	case 110:
		goto loc_8242CFF0;
	case 111:
		goto loc_8242CFF0;
	case 112:
		goto loc_8242CFF0;
	case 113:
		goto loc_8242C938;
	case 114:
		goto loc_8242C944;
	case 115:
		goto loc_8242CFF0;
	case 116:
		goto loc_8242CFF0;
	case 117:
		goto loc_8242C950;
	case 118:
		goto loc_8242C95C;
	case 119:
		goto loc_8242CFF0;
	case 120:
		goto loc_8242C968;
	case 121:
		goto loc_8242C974;
	case 122:
		goto loc_8242CFF0;
	case 123:
		goto loc_8242CFF0;
	case 124:
		goto loc_8242CFF0;
	case 125:
		goto loc_8242CFF0;
	case 126:
		goto loc_8242CFF0;
	case 127:
		goto loc_8242CFF0;
	case 128:
		goto loc_8242CFF0;
	case 129:
		goto loc_8242C980;
	case 130:
		goto loc_8242CFF0;
	case 131:
		goto loc_8242CFF0;
	case 132:
		goto loc_8242C98C;
	case 133:
		goto loc_8242C998;
	case 134:
		goto loc_8242C9A4;
	case 135:
		goto loc_8242C9B0;
	case 136:
		goto loc_8242C9BC;
	case 137:
		goto loc_8242C9C8;
	case 138:
		goto loc_8242C9D4;
	case 139:
		goto loc_8242C9E0;
	case 140:
		goto loc_8242C9EC;
	case 141:
		goto loc_8242C9F8;
	case 142:
		goto loc_8242CA04;
	case 143:
		goto loc_8242CA10;
	case 144:
		goto loc_8242CA1C;
	case 145:
		goto loc_8242CA28;
	case 146:
		goto loc_8242CFF0;
	case 147:
		goto loc_8242CFF0;
	case 148:
		goto loc_8242CA34;
	case 149:
		goto loc_8242CA40;
	case 150:
		goto loc_8242CA4C;
	case 151:
		goto loc_8242CA58;
	case 152:
		goto loc_8242CA64;
	case 153:
		goto loc_8242CA70;
	case 154:
		goto loc_8242CA7C;
	case 155:
		goto loc_8242CA88;
	case 156:
		goto loc_8242CA94;
	case 157:
		goto loc_8242CFF0;
	case 158:
		goto loc_8242CAA0;
	case 159:
		goto loc_8242CAAC;
	case 160:
		goto loc_8242CFF0;
	case 161:
		goto loc_8242CFF0;
	case 162:
		goto loc_8242CAB8;
	case 163:
		goto loc_8242CAC4;
	case 164:
		goto loc_8242CAD0;
	case 165:
		goto loc_8242CFF0;
	case 166:
		goto loc_8242CFF0;
	case 167:
		goto loc_8242CADC;
	case 168:
		goto loc_8242CAE8;
	case 169:
		goto loc_8242CFF0;
	case 170:
		goto loc_8242CFF0;
	case 171:
		goto loc_8242CFF0;
	case 172:
		goto loc_8242CFF0;
	case 173:
		goto loc_8242CFF0;
	case 174:
		goto loc_8242CFF0;
	case 175:
		goto loc_8242CFF0;
	case 176:
		goto loc_8242CFF0;
	case 177:
		goto loc_8242CAF4;
	case 178:
		goto loc_8242CB00;
	case 179:
		goto loc_8242CB0C;
	case 180:
		goto loc_8242CFF0;
	case 181:
		goto loc_8242CB18;
	case 182:
		goto loc_8242CFF0;
	case 183:
		goto loc_8242CB24;
	case 184:
		goto loc_8242CFF0;
	case 185:
		goto loc_8242CFF0;
	case 186:
		goto loc_8242CFF0;
	case 187:
		goto loc_8242CFF0;
	case 188:
		goto loc_8242CB30;
	case 189:
		goto loc_8242CFF0;
	case 190:
		goto loc_8242CB3C;
	case 191:
		goto loc_8242CFF0;
	case 192:
		goto loc_8242CFF0;
	case 193:
		goto loc_8242CFF0;
	case 194:
		goto loc_8242CB48;
	case 195:
		goto loc_8242CB54;
	case 196:
		goto loc_8242CB60;
	case 197:
		goto loc_8242CFF0;
	case 198:
		goto loc_8242CB6C;
	case 199:
		goto loc_8242CB78;
	case 200:
		goto loc_8242CFF0;
	case 201:
		goto loc_8242CB84;
	case 202:
		goto loc_8242CB90;
	case 203:
		goto loc_8242CB9C;
	case 204:
		goto loc_8242CFF0;
	case 205:
		goto loc_8242CFF0;
	case 206:
		goto loc_8242CBA8;
	case 207:
		goto loc_8242CBB4;
	case 208:
		goto loc_8242CBC0;
	case 209:
		goto loc_8242CBCC;
	case 210:
		goto loc_8242CFF0;
	case 211:
		goto loc_8242CBD8;
	case 212:
		goto loc_8242CBE4;
	case 213:
		goto loc_8242CBF0;
	case 214:
		goto loc_8242CFF0;
	case 215:
		goto loc_8242CBFC;
	case 216:
		goto loc_8242CC08;
	case 217:
		goto loc_8242CC14;
	case 218:
		goto loc_8242CFF0;
	case 219:
		goto loc_8242CC20;
	case 220:
		goto loc_8242CC2C;
	case 221:
		goto loc_8242CFF0;
	case 222:
		goto loc_8242CC38;
	case 223:
		goto loc_8242CC44;
	case 224:
		goto loc_8242CFF0;
	case 225:
		goto loc_8242CFF0;
	case 226:
		goto loc_8242CFF0;
	case 227:
		goto loc_8242CC50;
	case 228:
		goto loc_8242CC5C;
	case 229:
		goto loc_8242CFF0;
	case 230:
		goto loc_8242CFF0;
	case 231:
		goto loc_8242CC68;
	case 232:
		goto loc_8242CFF0;
	case 233:
		goto loc_8242CFF0;
	case 234:
		goto loc_8242CFF0;
	case 235:
		goto loc_8242CFF0;
	case 236:
		goto loc_8242CFF0;
	case 237:
		goto loc_8242CFF0;
	case 238:
		goto loc_8242CFF0;
	case 239:
		goto loc_8242CFF0;
	case 240:
		goto loc_8242CFF0;
	case 241:
		goto loc_8242CFF0;
	case 242:
		goto loc_8242CFF0;
	case 243:
		goto loc_8242CC74;
	case 244:
		goto loc_8242CFF0;
	case 245:
		goto loc_8242CC80;
	case 246:
		goto loc_8242CFF0;
	case 247:
		goto loc_8242CFF0;
	case 248:
		goto loc_8242CFF0;
	case 249:
		goto loc_8242CFF0;
	case 250:
		goto loc_8242CFF0;
	case 251:
		goto loc_8242CFF0;
	case 252:
		goto loc_8242CFF0;
	case 253:
		goto loc_8242CFF0;
	case 254:
		goto loc_8242CFF0;
	case 255:
		goto loc_8242CC8C;
	case 256:
		goto loc_8242CC98;
	case 257:
		goto loc_8242CFF0;
	case 258:
		goto loc_8242CCA4;
	case 259:
		goto loc_8242CFF0;
	case 260:
		goto loc_8242CFF0;
	case 261:
		goto loc_8242CCB0;
	case 262:
		goto loc_8242CCBC;
	case 263:
		goto loc_8242CFF0;
	case 264:
		goto loc_8242CFF0;
	case 265:
		goto loc_8242CFF0;
	case 266:
		goto loc_8242CCC8;
	case 267:
		goto loc_8242CCD4;
	case 268:
		goto loc_8242CCE0;
	case 269:
		goto loc_8242CFF0;
	case 270:
		goto loc_8242CCEC;
	case 271:
		goto loc_8242CCF8;
	case 272:
		goto loc_8242CFF0;
	case 273:
		goto loc_8242CFF0;
	case 274:
		goto loc_8242CD04;
	case 275:
		goto loc_8242CD10;
	case 276:
		goto loc_8242CFF0;
	case 277:
		goto loc_8242CFF0;
	case 278:
		goto loc_8242CFF0;
	case 279:
		goto loc_8242CD1C;
	case 280:
		goto loc_8242CD28;
	case 281:
		goto loc_8242CFF0;
	case 282:
		goto loc_8242CD34;
	case 283:
		goto loc_8242CD40;
	case 284:
		goto loc_8242CD4C;
	case 285:
		goto loc_8242CFF0;
	case 286:
		goto loc_8242CD58;
	case 287:
		goto loc_8242CD64;
	case 288:
		goto loc_8242CFF0;
	case 289:
		goto loc_8242CD70;
	case 290:
		goto loc_8242CD7C;
	case 291:
		goto loc_8242CFF0;
	case 292:
		goto loc_8242CFF0;
	case 293:
		goto loc_8242CFF0;
	case 294:
		goto loc_8242CD88;
	case 295:
		goto loc_8242CD94;
	case 296:
		goto loc_8242CDA0;
	case 297:
		goto loc_8242CDAC;
	case 298:
		goto loc_8242CFF0;
	case 299:
		goto loc_8242CFF0;
	case 300:
		goto loc_8242CFF0;
	case 301:
		goto loc_8242CFF0;
	case 302:
		goto loc_8242CFF0;
	case 303:
		goto loc_8242CFF0;
	case 304:
		goto loc_8242CFF0;
	case 305:
		goto loc_8242CFF0;
	case 306:
		goto loc_8242CFF0;
	case 307:
		goto loc_8242CFF0;
	case 308:
		goto loc_8242CFF0;
	case 309:
		goto loc_8242CFF0;
	case 310:
		goto loc_8242CFF0;
	case 311:
		goto loc_8242CFF0;
	case 312:
		goto loc_8242CFF0;
	case 313:
		goto loc_8242CFF0;
	case 314:
		goto loc_8242CFF0;
	case 315:
		goto loc_8242CFF0;
	case 316:
		goto loc_8242CFF0;
	case 317:
		goto loc_8242CFF0;
	case 318:
		goto loc_8242CFF0;
	case 319:
		goto loc_8242CFF0;
	case 320:
		goto loc_8242CFF0;
	case 321:
		goto loc_8242CFF0;
	case 322:
		goto loc_8242CFF0;
	case 323:
		goto loc_8242CFF0;
	case 324:
		goto loc_8242CFF0;
	case 325:
		goto loc_8242CFF0;
	case 326:
		goto loc_8242CFF0;
	case 327:
		goto loc_8242CFF0;
	case 328:
		goto loc_8242CFF0;
	case 329:
		goto loc_8242CFF0;
	case 330:
		goto loc_8242CFF0;
	case 331:
		goto loc_8242CFF0;
	case 332:
		goto loc_8242CFF0;
	case 333:
		goto loc_8242CFF0;
	case 334:
		goto loc_8242CFF0;
	case 335:
		goto loc_8242CFF0;
	case 336:
		goto loc_8242CFF0;
	case 337:
		goto loc_8242CFF0;
	case 338:
		goto loc_8242CFF0;
	case 339:
		goto loc_8242CFF0;
	case 340:
		goto loc_8242CDB8;
	case 341:
		goto loc_8242CDC4;
	case 342:
		goto loc_8242CDD0;
	case 343:
		goto loc_8242CDDC;
	case 344:
		goto loc_8242CFF0;
	case 345:
		goto loc_8242CFF0;
	case 346:
		goto loc_8242CFF0;
	case 347:
		goto loc_8242CDE8;
	case 348:
		goto loc_8242CDF4;
	case 349:
		goto loc_8242CE00;
	case 350:
		goto loc_8242CE0C;
	case 351:
		goto loc_8242CFF0;
	case 352:
		goto loc_8242CFF0;
	case 353:
		goto loc_8242CFF0;
	case 354:
		goto loc_8242CFF0;
	case 355:
		goto loc_8242CFF0;
	case 356:
		goto loc_8242CFF0;
	case 357:
		goto loc_8242CFF0;
	case 358:
		goto loc_8242CFF0;
	case 359:
		goto loc_8242CFF0;
	case 360:
		goto loc_8242CFF0;
	case 361:
		goto loc_8242CFF0;
	case 362:
		goto loc_8242CFF0;
	case 363:
		goto loc_8242CFF0;
	case 364:
		goto loc_8242CFF0;
	case 365:
		goto loc_8242CFF0;
	case 366:
		goto loc_8242CFF0;
	case 367:
		goto loc_8242CFF0;
	case 368:
		goto loc_8242CFF0;
	case 369:
		goto loc_8242CFF0;
	case 370:
		goto loc_8242CFF0;
	case 371:
		goto loc_8242CFF0;
	case 372:
		goto loc_8242CE18;
	case 373:
		goto loc_8242CE24;
	case 374:
		goto loc_8242CE30;
	case 375:
		goto loc_8242CE3C;
	case 376:
		goto loc_8242CFF0;
	case 377:
		goto loc_8242CFF0;
	case 378:
		goto loc_8242CFF0;
	case 379:
		goto loc_8242CE48;
	case 380:
		goto loc_8242CE54;
	case 381:
		goto loc_8242CE60;
	case 382:
		goto loc_8242CE6C;
	case 383:
		goto loc_8242CFF0;
	case 384:
		goto loc_8242CFF0;
	case 385:
		goto loc_8242CFF0;
	case 386:
		goto loc_8242CFF0;
	case 387:
		goto loc_8242CFF0;
	case 388:
		goto loc_8242CFF0;
	case 389:
		goto loc_8242CFF0;
	case 390:
		goto loc_8242CFF0;
	case 391:
		goto loc_8242CFF0;
	case 392:
		goto loc_8242CFF0;
	case 393:
		goto loc_8242CFF0;
	case 394:
		goto loc_8242CFF0;
	case 395:
		goto loc_8242CFF0;
	case 396:
		goto loc_8242CFF0;
	case 397:
		goto loc_8242CFF0;
	case 398:
		goto loc_8242CFF0;
	case 399:
		goto loc_8242CFF0;
	case 400:
		goto loc_8242CFF0;
	case 401:
		goto loc_8242CFF0;
	case 402:
		goto loc_8242CFF0;
	case 403:
		goto loc_8242CFF0;
	case 404:
		goto loc_8242CFF0;
	case 405:
		goto loc_8242CE78;
	case 406:
		goto loc_8242CE84;
	case 407:
		goto loc_8242CE90;
	case 408:
		goto loc_8242CE9C;
	case 409:
		goto loc_8242CFF0;
	case 410:
		goto loc_8242CEA8;
	case 411:
		goto loc_8242CEB4;
	case 412:
		goto loc_8242CEC0;
	case 413:
		goto loc_8242CECC;
	case 414:
		goto loc_8242CFF0;
	case 415:
		goto loc_8242CED8;
	case 416:
		goto loc_8242CEE4;
	case 417:
		goto loc_8242CEF0;
	case 418:
		goto loc_8242CEFC;
	case 419:
		goto loc_8242CF08;
	case 420:
		goto loc_8242CFF0;
	case 421:
		goto loc_8242CF14;
	case 422:
		goto loc_8242CF20;
	case 423:
		goto loc_8242CF2C;
	case 424:
		goto loc_8242CF38;
	case 425:
		goto loc_8242CFF0;
	case 426:
		goto loc_8242CF44;
	case 427:
		goto loc_8242CF50;
	case 428:
		goto loc_8242CF5C;
	case 429:
		goto loc_8242CF68;
	case 430:
		goto loc_8242CFF0;
	case 431:
		goto loc_8242CFF0;
	case 432:
		goto loc_8242CF74;
	case 433:
		goto loc_8242CFF0;
	case 434:
		goto loc_8242CFF0;
	case 435:
		goto loc_8242CFF0;
	case 436:
		goto loc_8242CFF0;
	case 437:
		goto loc_8242CFF0;
	case 438:
		goto loc_8242CFF0;
	case 439:
		goto loc_8242CFF0;
	case 440:
		goto loc_8242CFF0;
	case 441:
		goto loc_8242CFF0;
	case 442:
		goto loc_8242CFF0;
	case 443:
		goto loc_8242CFF0;
	case 444:
		goto loc_8242CFF0;
	case 445:
		goto loc_8242CFF0;
	case 446:
		goto loc_8242CFF0;
	case 447:
		goto loc_8242CFF0;
	case 448:
		goto loc_8242CFF0;
	case 449:
		goto loc_8242CFF0;
	case 450:
		goto loc_8242CFF0;
	case 451:
		goto loc_8242CFF0;
	case 452:
		goto loc_8242CF80;
	case 453:
		goto loc_8242CFF0;
	case 454:
		goto loc_8242CFF0;
	case 455:
		goto loc_8242CF8C;
	case 456:
		goto loc_8242CFF0;
	case 457:
		goto loc_8242CFF0;
	case 458:
		goto loc_8242CFF0;
	case 459:
		goto loc_8242CFF0;
	case 460:
		goto loc_8242CFF0;
	case 461:
		goto loc_8242CFF0;
	case 462:
		goto loc_8242CFF0;
	case 463:
		goto loc_8242CFF0;
	case 464:
		goto loc_8242CFF0;
	case 465:
		goto loc_8242CFF0;
	case 466:
		goto loc_8242CFF0;
	case 467:
		goto loc_8242CFF0;
	case 468:
		goto loc_8242CFF0;
	case 469:
		goto loc_8242CFF0;
	case 470:
		goto loc_8242CFF0;
	case 471:
		goto loc_8242CFF0;
	case 472:
		goto loc_8242CFF0;
	case 473:
		goto loc_8242CFF0;
	case 474:
		goto loc_8242CFF0;
	case 475:
		goto loc_8242CFF0;
	case 476:
		goto loc_8242CF98;
	case 477:
		goto loc_8242CFF0;
	case 478:
		goto loc_8242CFA4;
	case 479:
		goto loc_8242CFB0;
	case 480:
		goto loc_8242CFF0;
	case 481:
		goto loc_8242CFF0;
	case 482:
		goto loc_8242CFF0;
	case 483:
		goto loc_8242CFF0;
	case 484:
		goto loc_8242CFF0;
	case 485:
		goto loc_8242CFF0;
	case 486:
		goto loc_8242CFF0;
	case 487:
		goto loc_8242CFF0;
	case 488:
		goto loc_8242CFBC;
	case 489:
		goto loc_8242CFC8;
	case 490:
		goto loc_8242CFD4;
	case 491:
		goto loc_8242CFE0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8242C7B8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C7C4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C7D0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C7DC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C7E8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C7F4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C800:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C80C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C818:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C824:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C830:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C83C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C848:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C854:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C860:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C86C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C878:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C884:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C890:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C89C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8A8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8B4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8C0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8CC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8D8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8E4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8F0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C8FC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C908:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C914:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,116(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C920:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C92C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,124(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C938:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,128(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C944:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,132(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C950:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,136(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C95C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C968:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,144(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C974:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,148(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C980:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,152(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C98C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C998:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,160(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9A4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9B0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9BC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,172(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9C8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,176(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9D4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,180(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 180);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9E0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9EC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,188(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 188);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242C9F8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,192(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 192);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA04:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,196(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 196);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA10:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,200(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 200);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA1C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,204(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA28:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 208);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA34:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,212(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 212);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA40:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,216(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 216);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA4C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,220(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 220);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA58:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,224(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 224);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA64:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,228(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA70:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,232(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 232);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA7C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,236(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 236);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA88:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,240(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 240);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CA94:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,244(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 244);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CAA0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,248(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 248);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CAAC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,252(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 252);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CAB8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,256(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 256);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CAC4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,260(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 260);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CAD0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,264(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 264);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CADC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,268(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 268);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CAE8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,272(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 272);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CAF4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,276(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 276);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB00:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,280(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 280);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB0C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,284(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 284);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB18:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB24:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,292(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 292);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB30:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,296(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 296);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB3C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,300(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 300);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB48:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,304(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 304);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB54:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,308(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 308);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB60:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 312);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB6C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,316(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 316);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB78:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,320(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 320);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB84:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,324(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 324);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB90:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,328(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 328);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CB9C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,332(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 332);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBA8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 336);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBB4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 340);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBC0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,344(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 344);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBCC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,348(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 348);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBD8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,352(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 352);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBE4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,356(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 356);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBF0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,360(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 360);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CBFC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,364(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 364);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC08:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,368(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 368);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC14:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,372(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 372);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC20:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,376(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 376);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC2C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,380(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 380);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC38:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,384(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 384);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC44:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,388(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 388);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC50:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,392(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 392);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC5C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,396(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 396);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC68:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,400(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 400);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC74:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,404(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 404);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC80:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,408(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 408);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC8C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,412(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 412);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CC98:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,416(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 416);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCA4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,420(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 420);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCB0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,424(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCBC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,428(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 428);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCC8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,432(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 432);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCD4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,436(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 436);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCE0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,440(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 440);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCEC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,444(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 444);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CCF8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,448(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 448);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD04:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,452(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 452);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD10:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,456(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 456);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD1C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,460(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 460);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD28:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,464(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 464);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD34:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 468);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD40:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,472(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 472);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD4C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,476(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 476);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD58:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,480(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 480);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD64:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,484(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 484);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD70:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,488(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 488);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD7C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,492(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 492);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD88:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,496(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 496);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CD94:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,500(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 500);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDA0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,504(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 504);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDAC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,508(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 508);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDB8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,512(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 512);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDC4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,516(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 516);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDD0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,520(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 520);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDDC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,524(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 524);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDE8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,528(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 528);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CDF4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,532(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 532);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE00:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,536(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 536);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE0C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,540(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 540);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE18:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,544(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 544);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE24:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 548);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE30:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,552(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 552);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE3C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,556(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 556);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE48:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,560(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 560);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE54:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 564);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE60:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,568(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 568);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE6C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,572(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 572);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE78:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,576(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 576);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE84:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,580(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 580);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE90:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,584(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 584);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CE9C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,588(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 588);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CEA8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,592(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 592);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CEB4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,596(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 596);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CEC0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,600(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 600);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CECC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,604(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 604);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CED8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 608);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CEE4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,612(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 612);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CEF0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,616(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 616);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CEFC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,620(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 620);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF08:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,624(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 624);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF14:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,628(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 628);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF20:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,632(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 632);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF2C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,636(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 636);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF38:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,640(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 640);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF44:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,644(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 644);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF50:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,648(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 648);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF5C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,652(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF68:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,656(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 656);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF74:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,660(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 660);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF80:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,664(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 664);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF8C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,668(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 668);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CF98:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,672(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 672);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CFA4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,676(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 676);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CFB0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,680(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 680);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CFBC:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,684(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 684);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CFC8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,688(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 688);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CFD4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,692(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 692);
	// b 0x8242cfe8
	goto loc_8242CFE8;
loc_8242CFE0:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,696(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 696);
loc_8242CFE8:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8242CFF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8242CFF0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824801B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x824801B8;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x824801e8
	if (!ctx.cr6.eq) goto loc_824801E8;
	// li r4,57
	ctx.r4.s64 = 57;
	// bl 0x822e8b30
	ctx.lr = 0x824801D4;
	sub_822E8B30(ctx, base);
	// addi r11,r3,-14
	ctx.r11.s64 = ctx.r3.s64 + -14;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8248020c
	if (!ctx.cr6.eq) goto loc_8248020C;
loc_824801E8:
	// lwz r11,7540(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7540);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824803f8
	if (!ctx.cr6.eq) goto loc_824803F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82480070
	ctx.lr = 0x824801FC;
	sub_82480070(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,7540(r31)
	REX_STORE_U32(ctx.r31.u32 + 7540, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8248020C:
	// li r26,0
	ctx.r26.s64 = 0;
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// li r30,47
	ctx.r30.s64 = 47;
	// stw r26,7540(r31)
	REX_STORE_U32(ctx.r31.u32 + 7540, ctx.r26.u32);
	// addi r29,r31,872
	ctx.r29.s64 = ctx.r31.s64 + 872;
	// li r28,10
	ctx.r28.s64 = 10;
	// addi r27,r11,-11688
	ctx.r27.s64 = ctx.r11.s64 + -11688;
loc_82480228:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82480318
	if (ctx.cr6.eq) goto loc_82480318;
	// lwz r3,-700(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -700);
	// bl 0x822f3a98
	ctx.lr = 0x8248023C;
	sub_822F3A98(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r30,-10
	ctx.r4.s64 = ctx.r30.s64 + -10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r5,r11,r27
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt cr6,0x8248025c
	if (ctx.cr6.lt) goto loc_8248025C;
	// bl 0x822e8a50
	ctx.lr = 0x82480258;
	sub_822E8A50(ctx, base);
	// b 0x82480264
	goto loc_82480264;
loc_8248025C:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x822e88f8
	ctx.lr = 0x82480264;
	sub_822E88F8(ctx, base);
loc_82480264:
	// lwz r3,-696(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -696);
	// bl 0x822f3a98
	ctx.lr = 0x8248026C;
	sub_822F3A98(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwzx r5,r11,r27
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt cr6,0x8248028c
	if (ctx.cr6.lt) goto loc_8248028C;
	// bl 0x822e8a50
	ctx.lr = 0x82480288;
	sub_822E8A50(ctx, base);
	// b 0x82480294
	goto loc_82480294;
loc_8248028C:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x822e88f8
	ctx.lr = 0x82480294;
	sub_822E88F8(ctx, base);
loc_82480294:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x824802ac
	if (ctx.cr6.eq) goto loc_824802AC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x824802ac
	if (ctx.cr6.eq) goto loc_824802AC;
	// stw r26,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r26.u32);
loc_824802AC:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x824802d0
	if (!ctx.cr6.gt) goto loc_824802D0;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r4,r30,-46
	ctx.r4.s64 = ctx.r30.s64 + -46;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e8a50
	ctx.lr = 0x824802C8;
	sub_822E8A50(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8248034c
	goto loc_8248034C;
loc_824802D0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x824802f4
	if (!ctx.cr6.eq) goto loc_824802F4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-46
	ctx.r4.s64 = ctx.r30.s64 + -46;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e88f8
	ctx.lr = 0x824802EC;
	sub_822E88F8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8248034c
	goto loc_8248034C;
loc_824802F4:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// li r5,43
	ctx.r5.s64 = 43;
	// beq cr6,0x82480304
	if (ctx.cr6.eq) goto loc_82480304;
	// li r5,45
	ctx.r5.s64 = 45;
loc_82480304:
	// addi r4,r30,-46
	ctx.r4.s64 = ctx.r30.s64 + -46;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e8a50
	ctx.lr = 0x82480310;
	sub_822E8A50(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8248034c
	goto loc_8248034C;
loc_82480318:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-10
	ctx.r4.s64 = ctx.r30.s64 + -10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e88f8
	ctx.lr = 0x82480328;
	sub_822E88F8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e88f8
	ctx.lr = 0x82480338;
	sub_822E88F8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-46
	ctx.r4.s64 = ctx.r30.s64 + -46;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e88f8
	ctx.lr = 0x82480348;
	sub_822E88F8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
loc_8248034C:
	// addi r4,r30,-20
	ctx.r4.s64 = ctx.r30.s64 + -20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e88f8
	ctx.lr = 0x82480358;
	sub_822E88F8(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,736
	ctx.r29.s64 = ctx.r29.s64 + 736;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bne 0x82480228
	if (!ctx.cr0.eq) goto loc_82480228;
	// li r4,26
	ctx.r4.s64 = 26;
	// lwz r5,7520(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7520);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822e88f8
	ctx.lr = 0x82480378;
	sub_822E88F8(ctx, base);
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,7524(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7524);
	// bl 0x822e88f8
	ctx.lr = 0x82480388;
	sub_822E88F8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r3,92(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,24
	ctx.r4.s64 = 24;
	// lfs f0,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8254b028
	ctx.lr = 0x824803AC;
	sub_8254B028(ctx, base);
	// lwz r9,7536(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7536);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lfs f13,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// lwz r3,92(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// li r4,24
	ctx.r4.s64 = 24;
	// lfs f1,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f0,-12852(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12852);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f2,f10,f0,f13
	ctx.f2.f64 = double(float(std::fma(ctx.f10.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8254ae50
	ctx.lr = 0x824803E8;
	sub_8254AE50(ctx, base);
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,7544(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7544);
	// bl 0x822e88f8
	ctx.lr = 0x824803F8;
	sub_822E88F8(ctx, base);
loc_824803F8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824909E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x824909F0;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x82218220
	ctx.lr = 0x82490A00;
	sub_82218220(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r25,r8,21712
	ctx.r25.s64 = ctx.r8.s64 + 21712;
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r8,r6,-7408
	ctx.r8.s64 = ctx.r6.s64 + -7408;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r26,-32256
	ctx.r26.s64 = -2113929216;
	// lwz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r7,r9,-7536
	ctx.r7.s64 = ctx.r9.s64 + -7536;
	// lwz r27,12(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stw r7,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r7.u32);
	// addi r29,r31,88
	ctx.r29.s64 = ctx.r31.s64 + 88;
	// addi r7,r9,-7416
	ctx.r7.s64 = ctx.r9.s64 + -7416;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r30,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r30.u32);
	// addi r11,r29,8
	ctx.r11.s64 = ctx.r29.s64 + 8;
	// stw r25,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r25.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r4,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r4.u32);
	// li r4,12
	ctx.r4.s64 = 12;
	// stw r6,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r6.u32);
	// stw r27,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r27.u32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r7.u32);
	// stw r30,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// stw r28,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r28.u32);
	// stw r30,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r11,30044(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 30044);
	// or r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r9,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r9.u32);
	// lwz r6,30044(r26)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r26.u32 + 30044);
	// bl 0x822189c8
	ctx.lr = 0x82490AAC;
	sub_822189C8(ctx, base);
	// lis r8,-32183
	ctx.r8.s64 = -2109145088;
	// addi r7,r8,1416
	ctx.r7.s64 = ctx.r8.s64 + 1416;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x82490AD8;
	sub_822518D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82495FC0) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82496004
	if (!ctx.cr6.eq) goto loc_82496004;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82496004
	if (!ctx.cr6.eq) goto loc_82496004;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82496004
	if (!ctx.cr6.eq) goto loc_82496004;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82496008
	if (ctx.cr6.eq) goto loc_82496008;
loc_82496004:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82496008:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82497A38) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82497A40;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82497a80
	if (ctx.cr6.eq) goto loc_82497A80;
loc_82497A60:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82497a74
	if (ctx.cr6.eq) goto loc_82497A74;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8241a760
	ctx.lr = 0x82497A74;
	sub_8241A760(ctx, base);
loc_82497A74:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,464
	ctx.r31.s64 = ctx.r31.s64 + 464;
	// bne 0x82497a60
	if (!ctx.cr0.eq) goto loc_82497A60;
loc_82497A80:
	// mulli r11,r29,464
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(464));
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249A828) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8249a858
	if (ctx.cr6.eq) goto loc_8249A858;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249A858;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8249A858:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8249a878
	if (ctx.cr6.eq) goto loc_8249A878;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8249A878;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8249A878:
	// lwsync 
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x824bcf38
	ctx.lr = 0x8249A888;
	sub_824BCF38(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x824bd3b8
	ctx.lr = 0x8249A894;
	sub_824BD3B8(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x824bd0a8
	ctx.lr = 0x8249A89C;
	sub_824BD0A8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x824a0740
	ctx.lr = 0x8249A8A4;
	sub_824A0740(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x824a0a48
	ctx.lr = 0x8249A8AC;
	sub_824A0A48(ctx, base);
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

DEFINE_REX_FUNC(sub_8249DB70) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8249DB98) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82248c98
	sub_82248C98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8249E3E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// addi r11,r11,-18500
	ctx.r11.s64 = ctx.r11.s64 + -18500;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8249e410
	if (ctx.cr6.eq) goto loc_8249E410;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8249e414
	if (ctx.cr6.eq) goto loc_8249E414;
loc_8249E410:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8249E414:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r9,30048(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30048);
	// beq cr6,0x8249e438
	if (ctx.cr6.eq) goto loc_8249E438;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8249e43c
	if (!ctx.cr6.eq) goto loc_8249E43C;
loc_8249E438:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8249E43C:
	// lwz r3,288(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 288);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8249e45c
	if (ctx.cr6.eq) goto loc_8249E45C;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,292(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 292);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8249e460
	if (ctx.cr6.eq) goto loc_8249E460;
loc_8249E45C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8249E460:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8249e47c
	if (ctx.cr6.eq) goto loc_8249E47C;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8249e480
	if (!ctx.cr6.eq) goto loc_8249E480;
loc_8249E47C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8249E480:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8249cf58
	sub_8249CF58(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824A1AA0) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x824a1ad4
	if (!ctx.cr6.eq) goto loc_824A1AD4;
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
loc_824A1AD4:
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824a1ae4
	if (ctx.cr6.eq) goto loc_824A1AE4;
	// bl 0x824bd0a8
	ctx.lr = 0x824A1AE4;
	sub_824BD0A8(ctx, base);
loc_824A1AE4:
	// li r11,-1
	ctx.r11.s64 = -1;
	// lbz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 24);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_824A4518) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x824A4520;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// addis r25,r3,2
	ctx.r25.s64 = ctx.r3.s64 + 131072;
	// lis r11,2
	ctx.r11.s64 = 131072;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r25,r25,264
	ctx.r25.s64 = ctx.r25.s64 + 264;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// lis r24,-32256
	ctx.r24.s64 = -2113929216;
	// ori r26,r11,3240
	ctx.r26.u64 = ctx.r11.u64 | 3240;
loc_824A454C:
	// lwz r10,16(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824a456c
	if (ctx.cr6.eq) goto loc_824A456C;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r9,20(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 20);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x824a4570
	if (ctx.cr6.eq) goto loc_824A4570;
loc_824A456C:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_824A4570:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r9,30048(r24)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r24.u32 + 30048);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a4594
	if (ctx.cr6.eq) goto loc_824A4594;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 & ctx.r9.u64;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x824a4598
	if (!ctx.cr6.eq) goto loc_824A4598;
loc_824A4594:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_824A4598:
	// lwz r11,256(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 256);
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x824a4650
	if (!ctx.cr6.lt) goto loc_824A4650;
	// lwz r11,16(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a45c4
	if (ctx.cr6.eq) goto loc_824A45C4;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,20(r25)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r25.u32 + 20);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x824a45c8
	if (ctx.cr6.eq) goto loc_824A45C8;
loc_824A45C4:
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_824A45C8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824a45e4
	if (ctx.cr6.eq) goto loc_824A45E4;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x824a45e8
	if (!ctx.cr6.eq) goto loc_824A45E8;
loc_824A45E4:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_824A45E8:
	// lwz r10,248(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 248);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824a4620
	if (ctx.cr6.eq) goto loc_824A4620;
	// lwz r9,252(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 252);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x824a4620
	if (!ctx.cr6.gt) goto loc_824A4620;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x824a4620
	if (ctx.cr6.lt) goto loc_824A4620;
	// lwz r11,256(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 256);
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x824a4620
	if (!ctx.cr6.lt) goto loc_824A4620;
	// lhzx r11,r29,r10
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + ctx.r10.u32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// b 0x824a4624
	goto loc_824A4624;
loc_824A4620:
	// li r11,-1
	ctx.r11.s64 = -1;
loc_824A4624:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwzx r4,r10,r26
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r26.u32);
	// bl 0x824a26a8
	ctx.lr = 0x824A4640;
	sub_824A26A8(ctx, base);
	// or r27,r3,r27
	ctx.r27.u64 = ctx.r3.u64 | ctx.r27.u64;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// b 0x824a454c
	goto loc_824A454C;
loc_824A4650:
	// lwz r9,96(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 96);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addi r10,r30,88
	ctx.r10.s64 = ctx.r30.s64 + 88;
	// stw r28,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// beq cr6,0x824a46f4
	if (ctx.cr6.eq) goto loc_824A46F4;
	// lis r11,-32182
	ctx.r11.s64 = -2109079552;
	// addi r8,r11,17000
	ctx.r8.s64 = ctx.r11.s64 + 17000;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x824a46b0
	if (!ctx.cr6.eq) goto loc_824A46B0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824a476c
	if (ctx.cr6.eq) goto loc_824A476C;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x824a46b0
	if (!ctx.cr6.eq) goto loc_824A46B0;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x824a46b0
	if (!ctx.cr6.eq) goto loc_824A46B0;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x824a476c
	if (ctx.cr6.eq) goto loc_824A476C;
loc_824A46B0:
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r9,r7,1860
	ctx.r9.s64 = ctx.r7.s64 + 1860;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r4,4(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r9,8(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stw r5,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r5.u32);
	// stw r4,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r4.u32);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r28,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r28.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_824A46F4:
	// lis r11,-32182
	ctx.r11.s64 = -2109079552;
	// addi r8,r11,14792
	ctx.r8.s64 = ctx.r11.s64 + 14792;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x824a4738
	if (!ctx.cr6.eq) goto loc_824A4738;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824a476c
	if (ctx.cr6.eq) goto loc_824A476C;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x824a4738
	if (!ctx.cr6.eq) goto loc_824A4738;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x824a4738
	if (!ctx.cr6.eq) goto loc_824A4738;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x824a476c
	if (ctx.cr6.eq) goto loc_824A476C;
loc_824A4738:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r7,r8,1860
	ctx.r7.s64 = ctx.r8.s64 + 1860;
	// lwz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r5,4(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r4,8(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stw r7,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r7.u32);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// stw r4,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// stw r9,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r28,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r28.u32);
loc_824A476C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824B67B0) {
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
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824b683c
	if (ctx.cr6.eq) goto loc_824B683C;
	// lwz r10,-4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + -4);
	// addi r30,r4,-12
	ctx.r30.s64 = ctx.r4.s64 + -12;
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x824b6820
	if (!ctx.cr6.eq) goto loc_824B6820;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824b67fc
	if (ctx.cr6.eq) goto loc_824B67FC;
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// bl 0x826ccc44
	ctx.lr = 0x824B67FC;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_824B67FC:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// beq cr6,0x824b683c
	if (ctx.cr6.eq) goto loc_824B683C;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x826ccc54
	ctx.lr = 0x824B681C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x824b683c
	goto loc_824B683C;
loc_824B6820:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x824b6820
	if (!ctx.cr0.eq) goto loc_824B6820;
loc_824B683C:
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

DEFINE_REX_FUNC(sub_824BCDF0) {
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
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// addi r3,r11,-3824
	ctx.r3.s64 = ctx.r11.s64 + -3824;
	// bl 0x824c9510
	ctx.lr = 0x824BCE08;
	sub_824C9510(ctx, base);
	// lis r10,-32104
	ctx.r10.s64 = -2103967744;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-3832(r10)
	REX_STORE_U32(ctx.r10.u32 + -3832, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824BD278) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r4,2208(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 2208);
	// bl 0x826ccf24
	ctx.lr = 0x824BD29C;
	__imp__ObReferenceObjectByHandle(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x824bd2dc
	if (ctx.cr0.lt) goto loc_824BD2DC;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// cmpwi cr6,r31,15
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 15, ctx.xer);
	// bne cr6,0x824bd2b8
	if (!ctx.cr6.eq) goto loc_824BD2B8;
	// li r4,16
	ctx.r4.s64 = 16;
	// b 0x824bd2c4
	goto loc_824BD2C4;
loc_824BD2B8:
	// cmpwi cr6,r31,-15
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -15, ctx.xer);
	// bne cr6,0x824bd2c4
	if (!ctx.cr6.eq) goto loc_824BD2C4;
	// li r4,-16
	ctx.r4.s64 = -16;
loc_824BD2C4:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x826ccf14
	ctx.lr = 0x824BD2CC;
	__imp__KeSetBasePriorityThread(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x826ccf04
	ctx.lr = 0x824BD2D4;
	__imp__ObDereferenceObject(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824bd2e4
	goto loc_824BD2E4;
loc_824BD2DC:
	// bl 0x824bfd90
	ctx.lr = 0x824BD2E0;
	sub_824BFD90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_824BD2E4:
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

DEFINE_REX_FUNC(sub_824BFE08) {
	REX_FUNC_PROLOGUE();
	// b 0x824bfd98
	sub_824BFD98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824BFFD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x824BFFE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x824bff30
	ctx.lr = 0x824BFFF8;
	sub_824BFF30(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824c0078
	if (ctx.cr0.eq) goto loc_824C0078;
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r11,7(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 7);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824c0060
	if (ctx.cr0.eq) goto loc_824C0060;
	// lbz r11,202(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 202);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824c0060
	if (ctx.cr6.eq) goto loc_824C0060;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824bff30
	ctx.lr = 0x824C0038;
	sub_824BFF30(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,48(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r11,r11,12,0,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFFFF000;
	// srawi r11,r11,12
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 12;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// stb r10,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r10.u8);
loc_824C0060:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r11,7(r29)
	REX_STORE_U8(ctx.r29.u32 + 7, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824bfe90
	ctx.lr = 0x824C0078;
	sub_824BFE90(ctx, base);
loc_824C0078:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824C3DD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x824C3DE0;
	__savegprlr_24(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,80(r4)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r4.u32 + 80);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r31,24(r28)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// lwz r29,8(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x826ccc44
	ctx.lr = 0x824C3DFC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lbz r11,53(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 53);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824c3e14
	if (!ctx.cr0.eq) goto loc_824C3E14;
	// lis r30,-16384
	ctx.r30.s64 = -1073741824;
	// ori r30,r30,13
	ctx.r30.u64 = ctx.r30.u64 | 13;
	// b 0x824c3f9c
	goto loc_824C3F9C;
loc_824C3E14:
	// lwz r30,136(r24)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r24.u32 + 136);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x824c3f9c
	if (!ctx.cr6.eq) goto loc_824C3F9C;
	// lbz r11,2(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2);
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824c3e38
	if (ctx.cr0.eq) goto loc_824C3E38;
	// lis r30,-16384
	ctx.r30.s64 = -1073741824;
	// ori r30,r30,296
	ctx.r30.u64 = ctx.r30.u64 | 296;
	// b 0x824c3f9c
	goto loc_824C3F9C;
loc_824C3E38:
	// lwz r27,12(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// bne cr6,0x824c3e78
	if (!ctx.cr6.eq) goto loc_824C3E78;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824c1a20
	ctx.lr = 0x824C3E60;
	sub_824C1A20(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x824c3f9c
	if (ctx.cr0.lt) goto loc_824C3F9C;
	// lwz r27,80(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r27,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// li r31,1
	ctx.r31.s64 = 1;
	// b 0x824c3e7c
	goto loc_824C3E7C;
loc_824C3E78:
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_824C3E7C:
	// lbz r11,2(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 2);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824c3e8c
	if (ctx.cr0.eq) goto loc_824C3E8C;
	// stw r25,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r25.u32);
loc_824C3E8C:
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x824c2f40
	ctx.lr = 0x824C3EA4;
	sub_824C2F40(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x824c3edc
	if (!ctx.cr0.lt) goto loc_824C3EDC;
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// ori r11,r11,52
	ctx.r11.u64 = ctx.r11.u64 | 52;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x824c3f9c
	if (!ctx.cr6.eq) goto loc_824C3F9C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824c3ed0
	if (ctx.cr6.eq) goto loc_824C3ED0;
	// lis r30,-16384
	ctx.r30.s64 = -1073741824;
	// ori r30,r30,15
	ctx.r30.u64 = ctx.r30.u64 | 15;
	// b 0x824c3f9c
	goto loc_824C3F9C;
loc_824C3ED0:
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// ori r30,r30,6
	ctx.r30.u64 = ctx.r30.u64 | 6;
	// b 0x824c3f9c
	goto loc_824C3F9C;
loc_824C3EDC:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x824c29e8
	ctx.lr = 0x824C3EE8;
	sub_824C29E8(ctx, base);
	// lwz r3,152(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r31,28(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 28);
	// bl 0x824c0df8
	ctx.lr = 0x824C3EF4;
	sub_824C0DF8(ctx, base);
	// std r3,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r3.u64);
	// lwz r3,156(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x824c0df8
	ctx.lr = 0x824C3F00;
	sub_824C0DF8(ctx, base);
	// lbz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 136);
	// std r3,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r3.u64);
	// rlwinm. r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r3,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r3.u64);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r3,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r3.u64);
	// beq 0x824c3f30
	if (ctx.cr0.eq) goto loc_824C3F30;
	// li r11,16
	ctx.r11.s64 = 16;
	// std r25,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r25.u64);
	// std r25,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r25.u64);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x824c3f44
	goto loc_824C3F44;
loc_824C3F30:
	// lwz r11,148(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r9,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
	// std r11,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r11.u64);
	// std r11,48(r31)
	REX_STORE_U64(ctx.r31.u32 + 48, ctx.r11.u64);
loc_824C3F44:
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// clrlwi r28,r10,26
	ctx.r28.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x824c3f70
	if (!ctx.cr6.gt) goto loc_824C3F70;
	// lis r30,-32768
	ctx.r30.s64 = -2147483648;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// ori r30,r30,5
	ctx.r30.u64 = ctx.r30.u64 | 5;
	// b 0x824c3f74
	goto loc_824C3F74;
loc_824C3F70:
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
loc_824C3F74:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,64
	ctx.r3.s64 = ctx.r31.s64 + 64;
	// bl 0x826a1130
	ctx.lr = 0x824C3F84;
	rexcrt_memcpy(ctx, base);
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// addi r10,r29,64
	ctx.r10.s64 = ctx.r29.s64 + 64;
	// stw r28,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r28.u32);
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// stw r10,20(r26)
	REX_STORE_U32(ctx.r26.u32 + 20, ctx.r10.u32);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
loc_824C3F9C:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x826ccc54
	ctx.lr = 0x824C3FA4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// stw r30,16(r26)
	REX_STORE_U32(ctx.r26.u32 + 16, ctx.r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826cd074
	ctx.lr = 0x824C3FB4;
	__imp__IoCompleteRequest(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824CE280) {
	REX_FUNC_PROLOGUE();
	// lbz r11,11956(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 11956);
	// lwz r10,11952(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 11952);
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// slw r9,r10,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// extsb. r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,11952(r3)
	REX_STORE_U32(ctx.r3.u32 + 11952, ctx.r9.u32);
	// stb r11,11956(r3)
	REX_STORE_U8(ctx.r3.u32 + 11956, ctx.r11.u8);
	// bgtlr 
	if (ctx.cr0.gt) return;
	// lwz r8,11016(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 11016);
	// lwz r10,11012(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 11012);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x824ce2fc
	if (!ctx.cr6.lt) goto loc_824CE2FC;
	// lbz r6,11956(r3)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r11,r10,2
	ctx.r11.s64 = ctx.r10.s64 + 2;
	// lbz r7,1(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// lbz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r7,r7,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// stw r11,11012(r3)
	REX_STORE_U32(ctx.r3.u32 + 11012, ctx.r11.u32);
	// extsb r6,r6
	ctx.r6.s64 = ctx.r6.s8;
	// or r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 | ctx.r4.u64;
	// neg r6,r6
	ctx.r6.s64 = static_cast<int64_t>(-ctx.r6.u64);
	// addi r10,r5,16
	ctx.r10.s64 = ctx.r5.s64 + 16;
	// slw r7,r7,r6
	ctx.r7.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r6.u8 & 0x3F));
	// extsb. r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stb r10,11956(r3)
	REX_STORE_U8(ctx.r3.u32 + 11956, ctx.r10.u8);
	// stw r9,11952(r3)
	REX_STORE_U32(ctx.r3.u32 + 11952, ctx.r9.u32);
	// bgtlr 
	if (ctx.cr0.gt) return;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x824ce308
	if (ctx.cr6.lt) goto loc_824CE308;
loc_824CE2FC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,11959(r3)
	REX_STORE_U8(ctx.r3.u32 + 11959, ctx.r11.u8);
	// blr 
	return;
loc_824CE308:
	// lbz r8,11956(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 11956);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lwz r6,11952(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 11952);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// stw r9,11012(r3)
	REX_STORE_U32(ctx.r3.u32 + 11012, ctx.r9.u32);
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | ctx.r11.u64;
	// neg r8,r8
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// addi r11,r7,16
	ctx.r11.s64 = ctx.r7.s64 + 16;
	// slw r10,r10,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stb r11,11956(r3)
	REX_STORE_U8(ctx.r3.u32 + 11956, ctx.r11.u8);
	// stw r10,11952(r3)
	REX_STORE_U32(ctx.r3.u32 + 11952, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D19F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r4,28(r1)
	REX_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10692(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 10692, temp.u32);
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r10,32(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,34,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 34) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,32(r3)
	REX_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824D2D90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x826a0d10
	ctx.lr = 0x824D2DA4;
	__savefpr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,12448(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12448);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// fmr f29,f5
	ctx.f29.f64 = ctx.f5.f64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// fmr f28,f6
	ctx.f28.f64 = ctx.f6.f64;
	// bne 0x824d2dd8
	if (!ctx.cr0.eq) goto loc_824D2DD8;
	// lwz r9,12464(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12464);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824d2fcc
	if (ctx.cr6.eq) goto loc_824D2FCC;
loc_824D2DD8:
	// lbz r11,10940(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// rlwinm. r8,r11,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x824d2dec
	if (ctx.cr0.eq) goto loc_824D2DEC;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x824d2e78
	goto loc_824D2E78;
loc_824D2DEC:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d2e70
	if (ctx.cr0.eq) goto loc_824D2E70;
	// lwz r11,12736(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12736);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x824d2e08
	if (ctx.cr6.eq) goto loc_824D2E08;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x824d2e70
	if (!ctx.cr6.eq) goto loc_824D2E70;
loc_824D2E08:
	// lwz r11,12452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12740);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824d2e20
	if (ctx.cr6.eq) goto loc_824D2E20;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824d2e70
	if (!ctx.cr6.eq) goto loc_824D2E70;
loc_824D2E20:
	// lwz r11,12456(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12744);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824d2e38
	if (ctx.cr6.eq) goto loc_824D2E38;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824d2e70
	if (!ctx.cr6.eq) goto loc_824D2E70;
loc_824D2E38:
	// lwz r11,12460(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12460);
	// lwz r10,12748(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12748);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824d2e50
	if (ctx.cr6.eq) goto loc_824D2E50;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824d2e70
	if (!ctx.cr6.eq) goto loc_824D2E70;
loc_824D2E50:
	// lwz r11,12464(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12464);
	// lwz r10,12752(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12752);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824d2e68
	if (ctx.cr6.eq) goto loc_824D2E68;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824d2e70
	if (!ctx.cr6.eq) goto loc_824D2E70;
loc_824D2E68:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x824d2e74
	goto loc_824D2E74;
loc_824D2E70:
	// li r11,0
	ctx.r11.s64 = 0;
loc_824D2E74:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
loc_824D2E78:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824d2e8c
	if (ctx.cr0.eq) goto loc_824D2E8C;
	// lwz r11,13188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13188);
	// lwz r7,13192(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 13192);
	// b 0x824d2ea0
	goto loc_824D2EA0;
loc_824D2E8C:
	// lwz r10,36(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 36);
	// rlwinm r11,r10,14,18,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 14) & 0x3FFF;
	// rlwinm r10,r10,29,17,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x7FFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
loc_824D2EA0:
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f0,f3
	ctx.f0.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f0,f30
	ctx.f0.s64 = std::isnan(ctx.f30.f64) ? int64_t(0x80000000U) : (ctx.f30.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f30.f64));
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r8,92(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x824d2ed4
	if (!ctx.cr6.lt) goto loc_824D2ED4;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_824D2ED4:
	// fctiwz f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f4.f64) ? int64_t(0x80000000U) : (ctx.f4.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x824d2ef0
	if (ctx.cr6.lt) goto loc_824D2EF0;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_824D2EF0:
	// subf. r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r10,r8,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r8.u64;
	// blt 0x824d2f04
	if (ctx.cr0.lt) goto loc_824D2F04;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x824d2f0c
	if (!ctx.cr6.lt) goto loc_824D2F0C;
loc_824D2F04:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824D2F0C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f31,12656(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 12656, temp.u32);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// stfs f30,12660(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 12660, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r11,0
	ctx.r11.s64 = 0;
	// frsp f27,f0
	ctx.f27.f64 = double(float(ctx.f0.f64));
	// stfs f29,12672(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 12672, temp.u32);
	// fcfid f0,f13
	ctx.f0.f64 = double(ctx.f13.s64);
	// stfs f28,12676(r31)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 12676, temp.u32);
	// stfs f27,12668(r31)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 12668, temp.u32);
	// stw r11,12680(r31)
	REX_STORE_U32(ctx.r31.u32 + 12680, ctx.r11.u32);
	// addi r4,r31,12684
	ctx.r4.s64 = ctx.r31.s64 + 12684;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// frsp f26,f0
	ctx.f26.f64 = double(float(ctx.f0.f64));
	// stfs f26,12664(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 12664, temp.u32);
	// bl 0x824d2618
	ctx.lr = 0x824D2F60;
	sub_824D2618(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fsubs f0,f28,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f29.f64));
	// stfs f0,10520(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 10520, temp.u32);
	// stfs f29,10524(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 10524, temp.u32);
	// lfs f0,4268(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4268);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f26,f0
	ctx.f13.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// stfs f13,10504(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 10504, temp.u32);
	// fmuls f0,f27,f0
	ctx.f0.f64 = double(float(ctx.f27.f64 * ctx.f0.f64));
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// stfs f13,10508(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 10508, temp.u32);
	// fneg f13,f0
	ctx.f13.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f13,10512(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 10512, temp.u32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfs f0,10516(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 10516, temp.u32);
	// ld r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 16);
	// oris r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 67108864;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 33554432;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 16777216;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 8388608;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 4194304;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
loc_824D2FCC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x826a0d5c
	ctx.lr = 0x824D2FD8;
	__restfpr_26(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824E52A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x824E52B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,21660(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 21660);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,16560(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16560);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824e52d0
	if (!ctx.cr6.eq) goto loc_824E52D0;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824e52fc
	goto loc_824E52FC;
loc_824E52D0:
	// bl 0x826ccd04
	ctx.lr = 0x824E52D4;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x824e52f8
	if (ctx.cr6.eq) goto loc_824E52F8;
	// lwz r11,21648(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21648);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x824e5304
	if (ctx.cr6.eq) goto loc_824E5304;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824e52f8
	if (!ctx.cr6.eq) goto loc_824E52F8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,21648(r31)
	REX_STORE_U32(ctx.r31.u32 + 21648, ctx.r11.u32);
loc_824E52F8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E52FC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_824E5304:
	// lwz r10,21656(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21656);
	// lwz r11,21652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21652);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x824e52f8
	if (ctx.cr6.eq) goto loc_824E52F8;
	// lwz r10,21640(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21640);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x824d7c38
	ctx.lr = 0x824E5324;
	sub_824D7C38(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x824e52f8
	if (!ctx.cr0.eq) goto loc_824E52F8;
	// lis r29,-32104
	ctx.r29.s64 = -2103967744;
	// li r5,480
	ctx.r5.s64 = 480;
	// addi r30,r29,18084
	ctx.r30.s64 = ctx.r29.s64 + 18084;
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// addi r4,r30,484
	ctx.r4.s64 = ctx.r30.s64 + 484;
	// bl 0x826a1130
	ctx.lr = 0x824E5344;
	rexcrt_memcpy(ctx, base);
	// lwz r11,18084(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 18084);
	// lwz r10,21640(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21640);
	// addi r4,r30,484
	ctx.r4.s64 = ctx.r30.s64 + 484;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,-4(r30)
	REX_STORE_U32(ctx.r30.u32 + -4, ctx.r11.u32);
	// lwz r11,21652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21652);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x824d92d8
	ctx.lr = 0x824E536C;
	sub_824D92D8(ctx, base);
	// lwz r11,21652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 21652);
	// lwz r10,21644(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 21644);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// stw r10,18084(r29)
	REX_STORE_U32(ctx.r29.u32 + 18084, ctx.r10.u32);
	// bne cr6,0x824e539c
	if (!ctx.cr6.eq) goto loc_824E539C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x824e53a0
	goto loc_824E53A0;
loc_824E539C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_824E53A0:
	// lwz r10,16560(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16560);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,21652(r31)
	REX_STORE_U32(ctx.r31.u32 + 21652, ctx.r11.u32);
	// stw r10,21660(r31)
	REX_STORE_U32(ctx.r31.u32 + 21660, ctx.r10.u32);
	// b 0x824e52fc
	goto loc_824E52FC;
}

DEFINE_REX_FUNC(sub_824EED68) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	ctx.r11.s64 = -2105671680;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r11,-31840
	ctx.r31.s64 = ctx.r11.s64 + -31840;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x826ccc44
	ctx.lr = 0x824EED98;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 76);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,96(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EEDB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x826ccc54
	ctx.lr = 0x824EEDBC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824F1488) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x824f14b8
	if (ctx.cr6.eq) goto loc_824F14B8;
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r3,r9,6,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0x1F;
	// blr 
	return;
loc_824F14B8:
	// lwz r9,64(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm r3,r8,6,27,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0x1F;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824F22B0) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F22D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x824f2300
	if (ctx.cr6.lt) goto loc_824F2300;
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f2300
	if (ctx.cr6.eq) goto loc_824F2300;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F2300;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824F2300:
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

DEFINE_REX_FUNC(sub_824F3D08) {
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
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,-25864
	ctx.r10.s64 = ctx.r11.s64 + -25864;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x824f5b60
	ctx.lr = 0x824F3D30;
	sub_824F5B60(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824f3d5c
	if (ctx.cr6.eq) goto loc_824F3D5C;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824F3D54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
loc_824F3D5C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824f5440
	ctx.lr = 0x824F3D64;
	sub_824F5440(ctx, base);
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

DEFINE_REX_FUNC(sub_824F5510) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x824F5518;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32104
	ctx.r11.s64 = -2103967744;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lwz r11,19456(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 19456);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwz r3,60(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// bl 0x824f1ba0
	ctx.lr = 0x824F554C;
	sub_824F1BA0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x824f55a0
	if (ctx.cr6.lt) goto loc_824F55A0;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F556C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x824f55a0
	if (ctx.cr6.lt) goto loc_824F55A0;
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r11,82(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 82);
	// stb r29,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r29.u8);
	// stb r9,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// stb r10,6(r31)
	REX_STORE_U8(ctx.r31.u32 + 6, ctx.r10.u8);
	// lhz r7,62(r30)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r30.u32 + 62);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x824f55a0
	if (!ctx.cr6.gt) goto loc_824F55A0;
	// sth r11,62(r30)
	REX_STORE_U16(ctx.r30.u32 + 62, ctx.r11.u16);
loc_824F55A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824FADB0) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x824fae14
	if (!ctx.cr6.eq) goto loc_824FAE14;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x824fae14
	if (!ctx.cr6.eq) goto loc_824FAE14;
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,56
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 56, ctx.xer);
	// bne cr6,0x824fadf0
	if (!ctx.cr6.eq) goto loc_824FADF0;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_824FADF0:
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// bne cr6,0x824fae98
	if (!ctx.cr6.eq) goto loc_824FAE98;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// addi r5,r4,56
	ctx.r5.s64 = ctx.r4.s64 + 56;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_824FAE14:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824fae40
	if (!ctx.cr6.eq) goto loc_824FAE40;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x824fae40
	if (!ctx.cr6.eq) goto loc_824FAE40;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_824FAE40:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x824fae6c
	if (!ctx.cr6.eq) goto loc_824FAE6C;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x824fae6c
	if (!ctx.cr6.eq) goto loc_824FAE6C;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_824FAE6C:
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x824fae98
	if (!ctx.cr6.eq) goto loc_824FAE98;
	// clrlwi r11,r5,24
	ctx.r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x824fae98
	if (!ctx.cr6.eq) goto loc_824FAE98;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_824FAE98:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82501A88) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x82501550
	sub_82501550(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82501AD0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x82501980
	sub_82501980(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82501E18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82501E20;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,4
	ctx.r29.s64 = ctx.r3.s64 + 4;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// bl 0x824faff0
	ctx.lr = 0x82501E3C;
	sub_824FAFF0(ctx, base);
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r31,184
	ctx.r30.s64 = ctx.r31.s64 + 184;
	// addi r8,r11,-21128
	ctx.r8.s64 = ctx.r11.s64 + -21128;
	// addi r7,r10,-21168
	ctx.r7.s64 = ctx.r10.s64 + -21168;
	// addi r6,r9,-21264
	ctx.r6.s64 = ctx.r9.s64 + -21264;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// li r5,76
	ctx.r5.s64 = 76;
	// stw r7,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826a03b0
	ctx.lr = 0x82501E74;
	rexcrt_memset(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x824fad80
	ctx.lr = 0x82501E90;
	sub_824FAD80(ctx, base);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lbz r8,69(r28)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r28.u32 + 69);
	// ori r11,r4,48000
	ctx.r11.u64 = ctx.r4.u64 | 48000;
	// lbz r6,56(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 56);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r10,r3,-21008
	ctx.r10.s64 = ctx.r3.s64 + -21008;
	// stw r8,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r8.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r4,60(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r8,264(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// ori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 | 1;
	// std r4,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lbz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 52);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stb r6,197(r31)
	REX_STORE_U8(ctx.r31.u32 + 197, ctx.r6.u8);
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stb r3,196(r31)
	REX_STORE_U8(ctx.r31.u32 + 196, ctx.r3.u8);
	// stw r7,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r7.u32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fctidz f9,f10
	ctx.f9.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r30,r5
	REX_STORE_U32(ctx.r30.u32 + ctx.r5.u32, ctx.f9.u32);
	// ori r5,r6,2
	ctx.r5.u64 = ctx.r6.u64 | 2;
	// stw r11,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// stw r5,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r5.u32);
	// lbz r4,197(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 197);
	// lbz r3,196(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 196);
	// rotlwi r11,r3,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// lwzx r10,r11,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mullw r8,r10,r4
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// sth r9,110(r31)
	REX_STORE_U16(ctx.r31.u32 + 110, ctx.r9.u16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r8,108(r31)
	REX_STORE_U16(ctx.r31.u32 + 108, ctx.r8.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8250D228) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lbz r9,13(r3)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r6,28(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mullw r4,r9,r10
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r31,24(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// subf r6,r6,r31
	ctx.r6.u64 = ctx.r31.u64 - ctx.r6.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// blt cr6,0x8250d278
	if (ctx.cr6.lt) goto loc_8250D278;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
loc_8250D278:
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// rlwinm r8,r8,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8250d2a8
	if (ctx.cr6.eq) goto loc_8250D2A8;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
loc_8250D298:
	// dcbt r8,r11
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r10,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// bdnz 0x8250d298
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8250D298;
loc_8250D2A8:
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// lfs f13,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// std r10,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r10.u64);
	// lfd f11,-32(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f13,7680(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7680);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f12,f9
	ctx.f12.f64 = double(float(ctx.f12.f64 / ctx.f9.f64));
loc_8250D2D0:
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r8,r10,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// rlwimi r8,r10,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// extsh r5,r8
	ctx.r5.s64 = ctx.r8.s16;
	// std r5,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f11,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f7,1024(r7)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r7.u32 + 1024, temp.u32);
	// lhz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// rlwinm r10,r4,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// rlwimi r10,r4,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// std r6,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r6.u64);
	// lfd f6,-24(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// stfs f2,0(r7)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// bne 0x8250d2d0
	if (!ctx.cr0.eq) goto loc_8250D2D0;
	// lbz r10,13(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r8,r10,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// subf r6,r9,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r9.u64;
	// twllei r8,0
	if (ctx.r8.s32 == 0 || ctx.r8.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r6,r8
	ctx.r11.u64 = uint32_t(ctx.r8.u32 ? ctx.r6.u32 / ctx.r8.u32 : 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8250d364
	if (!ctx.cr6.lt) goto loc_8250D364;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8250D364:
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// subf r10,r11,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r11.u64;
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8250d390
	if (!ctx.cr6.lt) goto loc_8250D390;
	// stw r10,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8250D390:
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82512070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82512078;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r27,13(r3)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r8,28(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r28,4(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r10,r27,r11
	ctx.r10.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r11.s32);
	// lwz r26,24(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r29,20(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r28
	ctx.r11.u64 = ctx.r28.u64 - ctx.r11.u64;
	// subf r6,r8,r26
	ctx.r6.u64 = ctx.r26.u64 - ctx.r8.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x825120bc
	if (ctx.cr6.lt) goto loc_825120BC;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_825120BC:
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// or r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 | ctx.r11.u64;
	// clrlwi r4,r5,27
	ctx.r4.u64 = ctx.r5.u32 & 0x1F;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x825120e0
	if (ctx.cr6.eq) goto loc_825120E0;
	// bl 0x8250c970
	ctx.lr = 0x825120D8;
	sub_8250C970(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_825120E0:
	// addi r7,r11,127
	ctx.r7.s64 = ctx.r11.s64 + 127;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r7,r7,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8251210c
	if (ctx.cr6.eq) goto loc_8251210C;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// rlwinm r7,r8,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
loc_825120FC:
	// dcbt r7,r10
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r7,r8,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// bdnz 0x825120fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825120FC;
loc_8251210C:
	// extsw r8,r6
	ctx.r8.s64 = ctx.r6.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// addi r25,r1,80
	ctx.r25.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lvlx128 v63,r0,r25
	temp.u32 = ctx.r25.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// addi r4,r4,-15168
	ctx.r4.s64 = ctx.r4.s64 + -15168;
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// addi r8,r8,-15184
	ctx.r8.s64 = ctx.r8.s64 + -15184;
	// addi r7,r7,-15232
	ctx.r7.s64 = ctx.r7.s64 + -15232;
	// addi r6,r6,-15216
	ctx.r6.s64 = ctx.r6.s64 + -15216;
	// lis r31,-32256
	ctx.r31.s64 = -2113929216;
	// addi r24,r1,88
	ctx.r24.s64 = ctx.r1.s64 + 88;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f12,26848(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 26848);
	ctx.f12.f64 = double(temp.f32);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(std::fma(ctx.f5.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lvx128 v12,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r24
	temp.u32 = ctx.r24.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v10,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vaddfp128 v62,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v13,v10,v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v12,v10,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v11,v10,v11,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v10,v9,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ble cr6,0x825122dc
	if (!ctx.cr6.gt) goto loc_825122DC;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// vspltisb v10,7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_set1_epi8(char(0x7)));
	// addi r11,r9,96
	ctx.r11.s64 = ctx.r9.s64 + 96;
	// rlwinm r8,r8,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// li r31,-80
	ctx.r31.s64 = -80;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// vslb v10,v10,v10
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v10.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// li r4,-64
	ctx.r4.s64 = -64;
	// li r5,-48
	ctx.r5.s64 = -48;
	// li r6,-32
	ctx.r6.s64 = -32;
	// li r7,-16
	ctx.r7.s64 = -16;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// li r8,16
	ctx.r8.s64 = 16;
loc_8251220C:
	// lvx128 v9,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v0,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v8,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddubm v7,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vaddubm v6,v8,v10
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vaddfp128 v59,v11,v63
	simde_mm_store_ps(ctx.v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vaddfp128 v58,v12,v63
	simde_mm_store_ps(ctx.v58.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vaddfp128 v57,v13,v63
	simde_mm_store_ps(ctx.v57.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vupkhsb128 v56,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v56.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v7.s8), simde_mm_load_si128((simde__m128i*)ctx.v7.s8))));
	// vupklsb128 v55,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v55.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vupkhsb128 v54,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v54.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v6.s8), simde_mm_load_si128((simde__m128i*)ctx.v6.s8))));
	// vupklsb128 v53,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v53.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vupkhsb128 v52,v56,v96
	simde_mm_store_si128((simde__m128i*)ctx.v52.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v56.s16), simde_mm_load_si128((simde__m128i*)ctx.v56.s16))));
	// vupklsb128 v51,v56,v96
	simde_mm_store_si128((simde__m128i*)ctx.v51.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.s16)));
	// vupkhsb128 v50,v55,v96
	simde_mm_store_si128((simde__m128i*)ctx.v50.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v55.s16), simde_mm_load_si128((simde__m128i*)ctx.v55.s16))));
	// vupklsb128 v49,v55,v96
	simde_mm_store_si128((simde__m128i*)ctx.v49.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.s16)));
	// vupkhsb128 v48,v54,v96
	simde_mm_store_si128((simde__m128i*)ctx.v48.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v54.s16), simde_mm_load_si128((simde__m128i*)ctx.v54.s16))));
	// vcsxwfp128 v47,v52,7
	simde_mm_store_ps(ctx.v47.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v52.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v46,v54,v96
	simde_mm_store_si128((simde__m128i*)ctx.v46.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v54.s16)));
	// vcsxwfp128 v45,v51,7
	simde_mm_store_ps(ctx.v45.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v51.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v44,v53,v96
	simde_mm_store_si128((simde__m128i*)ctx.v44.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v53.s16), simde_mm_load_si128((simde__m128i*)ctx.v53.s16))));
	// vcsxwfp128 v43,v50,7
	simde_mm_store_ps(ctx.v43.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v50.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v42,v53,v96
	simde_mm_store_si128((simde__m128i*)ctx.v42.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v53.s16)));
	// vcsxwfp128 v41,v49,7
	simde_mm_store_ps(ctx.v41.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v49.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v40,v48,7
	simde_mm_store_ps(ctx.v40.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v48.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v39,v46,7
	simde_mm_store_ps(ctx.v39.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v46.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v38,v44,7
	simde_mm_store_ps(ctx.v38.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v44.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v37,v42,7
	simde_mm_store_ps(ctx.v37.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v42.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vmulfp128 v36,v47,v0
	simde_mm_store_ps(ctx.v36.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v47.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v35,v45,v11
	simde_mm_store_ps(ctx.v35.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v45.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vmulfp128 v34,v43,v12
	simde_mm_store_ps(ctx.v34.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v43.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v33,v41,v13
	simde_mm_store_ps(ctx.v33.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v41.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v32,v40,v60
	simde_mm_store_ps(ctx.v32.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v40.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vmulfp128 v61,v39,v59
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v39.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vmulfp128 v60,v38,v58
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v38.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vmulfp128 v59,v37,v57
	simde_mm_store_ps(ctx.v59.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v37.f32), simde_mm_load_ps(ctx.v57.f32)));
	// vaddfp128 v0,v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v13,v13,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v12,v12,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vaddfp128 v11,v11,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v36,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// stvx128 v35,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r11,r5
	ea = (ctx.r11.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x8251220c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8251220C;
loc_825122DC:
	// subf r11,r30,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r30.u64;
	// twllei r27,0
	if (ctx.r27.s32 == 0 || ctx.r27.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r11,r27
	ctx.r11.u64 = uint32_t(ctx.r27.u32 ? ctx.r11.u32 / ctx.r27.u32 : 0);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x825122f4
	if (ctx.cr6.lt) goto loc_825122F4;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_825122F4:
	// subf r10,r29,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r29.u64;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// rlwinm r11,r10,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// blt cr6,0x8251230c
	if (ctx.cr6.lt) goto loc_8251230C;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8251230C:
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82523208) {
	REX_FUNC_PROLOGUE();
	// li r3,12
	ctx.r3.s64 = 12;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82523290) {
	REX_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825232b8
	if (ctx.cr6.eq) goto loc_825232B8;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// sth r4,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r4.u16);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r5,10(r3)
	REX_STORE_U16(ctx.r3.u32 + 10, ctx.r5.u16);
	// addi r9,r10,-13740
	ctx.r9.s64 = ctx.r10.s64 + -13740;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_825232B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82524B58) {
	REX_FUNC_PROLOGUE();
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82524b7c
	if (!ctx.cr6.eq) goto loc_82524B7C;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82524b84
	if (!ctx.cr6.eq) goto loc_82524B84;
loc_82524B7C:
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
loc_82524B84:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82524b94
	if (!ctx.cr6.eq) goto loc_82524B94;
	// lis r11,32
	ctx.r11.s64 = 2097152;
	// b 0x82524ba4
	goto loc_82524BA4;
loc_82524B94:
	// lis r8,2048
	ctx.r8.s64 = 134217728;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x82524ba4
	if (!ctx.cr6.gt) goto loc_82524BA4;
	// lis r11,2048
	ctx.r11.s64 = 134217728;
loc_82524BA4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82524bb0
	if (!ctx.cr6.eq) goto loc_82524BB0;
	// li r10,64
	ctx.r10.s64 = 64;
loc_82524BB0:
	// divwu r8,r11,r10
	ctx.r8.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// lis r7,8
	ctx.r7.s64 = 524288;
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x82524bd4
	if (!ctx.cr6.gt) goto loc_82524BD4;
	// rlwinm r10,r11,13,19,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 13) & 0x1FFF;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x82524bd4
	if (!ctx.cr6.lt) goto loc_82524BD4;
	// li r10,4
	ctx.r10.s64 = 4;
loc_82524BD4:
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825278E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// stw r6,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r7,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// addi r9,r11,-13500
	ctx.r9.s64 = ctx.r11.s64 + -13500;
	// stw r4,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r5,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825281E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x825281E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-13468
	ctx.r10.s64 = ctx.r11.s64 + -13468;
	// addi r29,r3,24
	ctx.r29.s64 = ctx.r3.s64 + 24;
	// li r30,3
	ctx.r30.s64 = 3;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_82528204:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82535ee0
	ctx.lr = 0x8252820C;
	sub_82535EE0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,400
	ctx.r29.s64 = ctx.r29.s64 + 400;
	// bge 0x82528204
	if (!ctx.cr0.lt) goto loc_82528204;
	// addi r3,r31,1624
	ctx.r3.s64 = ctx.r31.s64 + 1624;
	// bl 0x82536350
	ctx.lr = 0x82528220;
	sub_82536350(ctx, base);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r10,1700(r31)
	REX_STORE_U32(ctx.r31.u32 + 1700, ctx.r10.u32);
	// stw r10,1704(r31)
	REX_STORE_U32(ctx.r31.u32 + 1704, ctx.r10.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r10,1708(r31)
	REX_STORE_U32(ctx.r31.u32 + 1708, ctx.r10.u32);
	// li r9,-2
	ctx.r9.s64 = -2;
loc_82528240:
	// stw r9,1712(r11)
	REX_STORE_U32(ctx.r11.u32 + 1712, ctx.r9.u32);
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82528240
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82528240;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82529B60) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// lis r10,-32050
	ctx.r10.s64 = -2100428800;
	// lwz r11,-1544(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -1544);
	// stw r11,-1548(r10)
	REX_STORE_U32(ctx.r10.u32 + -1548, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8252A068) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8252A088:
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addic r7,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// subfe r6,r7,r8
	temp.u8 = (~ctx.r7.u32 + ctx.r8.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r6,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8252a088
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8252A088;
	// lis r11,-32058
	ctx.r11.s64 = -2100953088;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r10,r11,24960
	ctx.r10.s64 = ctx.r11.s64 + 24960;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x824e3b60
	ctx.lr = 0x8252A0C0;
	sub_824E3B60(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8252CA58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x8252CA60;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r4,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r4.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x826ccc44
	ctx.lr = 0x8252CA74;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,68(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 68);
	// addi r3,r27,32
	ctx.r3.s64 = ctx.r27.s64 + 32;
	// lwz r10,80(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 80);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8252ca9c
	if (!ctx.cr6.eq) goto loc_8252CA9C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826ccc54
	ctx.lr = 0x8252CA90;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_8252CA9C:
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// bl 0x8251b390
	ctx.lr = 0x8252CAA4;
	sub_8251B390(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8252cdd0
	ctx.lr = 0x8252CAAC;
	sub_8252CDD0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8252caec
	if (ctx.cr6.eq) goto loc_8252CAEC;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_8252CAC0:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8252cadc
	if (ctx.cr6.eq) goto loc_8252CADC;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r27,896
	ctx.r3.s64 = ctx.r27.s64 + 896;
	// bl 0x8252a5b0
	ctx.lr = 0x8252CADC;
	sub_8252A5B0(ctx, base);
loc_8252CADC:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x8252cac0
	if (ctx.cr6.lt) goto loc_8252CAC0;
loc_8252CAEC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8252cdd0
	ctx.lr = 0x8252CAF4;
	sub_8252CDD0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8252cb28
	if (ctx.cr6.eq) goto loc_8252CB28;
	// addi r31,r30,252
	ctx.r31.s64 = ctx.r30.s64 + 252;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_8252CB04:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x8252cb1c
	if (ctx.cr6.eq) goto loc_8252CB1C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r27,896
	ctx.r3.s64 = ctx.r27.s64 + 896;
	// bl 0x8252a5b0
	ctx.lr = 0x8252CB1C;
	sub_8252A5B0(ctx, base);
loc_8252CB1C:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x8252cb04
	if (!ctx.cr0.eq) goto loc_8252CB04;
loc_8252CB28:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826ccc54
	ctx.lr = 0x8252CB30;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82533AB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// vspltisw v13,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// rlwinm r31,r7,30,2,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// clrlwi r30,r10,30
	ctx.r30.u64 = ctx.r10.u32 & 0x3;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// vor v0,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// li r7,32
	ctx.r7.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82533ba8
	if (ctx.cr6.eq) goto loc_82533BA8;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82533AF0:
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp v10,v0,v12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)));
	// lvx128 v9,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// lvx128 v6,r10,r3
	ea = (ctx.r10.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvx128 v7,r6,r8
	ea = (ctx.r6.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp v3,v10,v7
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)));
	// stvx128 v6,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v5,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v4,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// lvx128 v2,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v31,r10,r3
	ea = (ctx.r10.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stvx128 v2,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp v28,v3,v2
	simde_mm_store_ps(ctx.v28.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)));
	// stvx128 v31,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stvx128 v29,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// lvx128 v27,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r10,r3
	ea = (ctx.r10.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v25,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v24,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stvx128 v27,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v26,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp v0,v28,v27
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v27.f32)));
	// stvx128 v25,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// bdnz 0x82533af0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82533AF0;
loc_82533BA8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82533bec
	if (ctx.cr6.eq) goto loc_82533BEC;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82533BB8:
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp v0,v0,v12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)));
	// lvx128 v10,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// bdnz 0x82533bb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82533BB8;
loc_82533BEC:
	// vmaddfp v0,v0,v1,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254A7D8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
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

DEFINE_REX_FUNC(sub_8254AA60) {
	REX_FUNC_PROLOGUE();
	// stw r4,240(r3)
	REX_STORE_U32(ctx.r3.u32 + 240, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254AC70) {
	REX_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x8256b240
	sub_8256B240(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8254AD40) {
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
	ctx.lr = 0x8254AD50;
	sub_8256B208(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8254ad6c
	if (!ctx.cr6.eq) goto loc_8254AD6C;
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
loc_8254AD6C:
	// bl 0x8256c6c8
	ctx.lr = 0x8254AD70;
	sub_8256C6C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254BA68) {
	REX_FUNC_PROLOGUE();
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,4(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r11,r9,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rlwinm r10,r8,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rlwinm r7,r9,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addic. r11,r6,64
	ctx.xer.ca = ctx.r6.u32 > 4294967231;
	ctx.r11.s64 = ctx.r6.s64 + 64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// or r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 | ctx.r11.u64;
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// bne 0x8254ba94
	if (!ctx.cr0.eq) goto loc_8254BA94;
	// rlwinm r11,r10,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_8254BA94:
	// lis r10,-32050
	ctx.r10.s64 = -2100428800;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// lwz r10,6004(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 6004);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r3,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8254D8F0) {
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
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-5364
	ctx.r9.s64 = ctx.r11.s64 + -5364;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8254d924
	if (ctx.cr6.eq) goto loc_8254D924;
	// bl 0x82573808
	ctx.lr = 0x8254D920;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8254D924:
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

DEFINE_REX_FUNC(sub_8254EDE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x8254EDE8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,5996(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5996);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x8254ee0c
	if (!ctx.cr6.lt) goto loc_8254EE0C;
	// bl 0x823d4968
	ctx.lr = 0x8254EE04;
	sub_823D4968(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_8254EE0C:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r28,44
	ctx.r28.s64 = 44;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254ee28
	if (ctx.cr6.eq) goto loc_8254EE28;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// divw r11,r9,r28
	ctx.r11.u64 = uint32_t((ctx.r28.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r9.s32 / ctx.r28.s32 : 0);
loc_8254EE28:
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x8254eec8
	if (!ctx.cr6.lt) goto loc_8254EEC8;
	// mulli r27,r4,44
	ctx.r27.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(44));
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8254be00
	ctx.lr = 0x8254EE40;
	sub_8254BE00(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// ble cr6,0x8254ee5c
	if (!ctx.cr6.gt) goto loc_8254EE5C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8254EE5C:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lbz r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// stb r9,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x8254de58
	ctx.lr = 0x8254EE84;
	sub_8254DE58(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r8,r3,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r3.u64;
	// divw r28,r8,r28
	ctx.r28.u64 = uint32_t((ctx.r28.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r8.s32 / ctx.r28.s32 : 0);
	// beq cr6,0x8254eeb0
	if (ctx.cr6.eq) goto loc_8254EEB0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lbz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x8254bd30
	ctx.lr = 0x8254EEA8;
	sub_8254BD30(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8254bf90
	ctx.lr = 0x8254EEB0;
	sub_8254BF90(ctx, base);
loc_8254EEB0:
	// mulli r11,r28,44
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(44));
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// add r10,r27,r29
	ctx.r10.u64 = ctx.r27.u64 + ctx.r29.u64;
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
loc_8254EEC8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825529F8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r10,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r11,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r11.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825521d8
	ctx.lr = 0x82552A2C;
	sub_825521D8(ctx, base);
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

DEFINE_REX_FUNC(sub_825562C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x825562D0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,5996(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5996);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x825562f4
	if (!ctx.cr6.lt) goto loc_825562F4;
	// bl 0x823d4968
	ctx.lr = 0x825562EC;
	sub_823D4968(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_825562F4:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8255630c
	if (ctx.cr6.eq) goto loc_8255630C;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r11,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 2;
loc_8255630C:
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82556390
	if (!ctx.cr6.lt) goto loc_82556390;
	// rlwinm r28,r4,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8254be00
	ctx.lr = 0x82556324;
	sub_8254BE00(ctx, base);
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82556340
	if (!ctx.cr6.gt) goto loc_82556340;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82556340:
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255635c
	if (ctx.cr0.eq) goto loc_8255635C;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x826a2460
	ctx.lr = 0x8255635C;
	sub_826A2460(ctx, base);
loc_8255635C:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r10,r3,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r3.u64;
	// srawi r29,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r29.s64 = ctx.r10.s32 >> 2;
	// beq cr6,0x82556378
	if (ctx.cr6.eq) goto loc_82556378;
	// bl 0x8254bf90
	ctx.lr = 0x82556378;
	sub_8254BF90(ctx, base);
loc_82556378:
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// add r10,r28,r30
	ctx.r10.u64 = ctx.r28.u64 + ctx.r30.u64;
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
loc_82556390:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255BEF0) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32050
	ctx.r8.s64 = -2100428800;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// addi r7,r8,9588
	ctx.r7.s64 = ctx.r8.s64 + 9588;
	// addi r9,r11,-4844
	ctx.r9.s64 = ctx.r11.s64 + -4844;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,9588(r8)
	REX_STORE_U32(ctx.r8.u32 + 9588, ctx.r9.u32);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// stw r11,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r11.u32);
	// stw r10,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8255C580) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8255C588;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x825502f8
	ctx.lr = 0x8255C5A0;
	sub_825502F8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8255c5d4
	if (ctx.cr6.eq) goto loc_8255C5D4;
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C5C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x8255C5C8;
	sub_8254B160(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_8255C5D4:
	// addi r4,r31,24
	ctx.r4.s64 = ctx.r31.s64 + 24;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8255edb0
	ctx.lr = 0x8255C5E4;
	sub_8255EDB0(ctx, base);
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,48(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,24(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8255c600
	if (ctx.cr6.eq) goto loc_8255C600;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8255c604
	if (ctx.cr6.eq) goto loc_8255C604;
loc_8255C600:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255C604:
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8255c668
	if (ctx.cr6.eq) goto loc_8255C668;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8255c660
	if (!ctx.cr6.eq) goto loc_8255C660;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255C61C:
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8255c62c
	if (!ctx.cr6.eq) goto loc_8255C62C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255C62C:
	// lwz r3,28(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// beq cr6,0x8255c670
	if (ctx.cr6.eq) goto loc_8255C670;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C64C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x8255C654;
	sub_8254B160(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_8255C660:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8255c61c
	goto loc_8255C61C;
loc_8255C668:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8255C670:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x8255C678;
	sub_8254B160(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82562468) {
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
	// lwz r11,96(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 96);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,168(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 168);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825624A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x825624b4
	if (!ctx.cr6.eq) goto loc_825624B4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_825624B4:
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// beq cr6,0x825624d4
	if (ctx.cr6.eq) goto loc_825624D4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825624D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825624D4:
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

DEFINE_REX_FUNC(sub_82563E28) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x82563E30;
	__savegprlr_25(ctx, base);
	// lis r26,-32050
	ctx.r26.s64 = -2100428800;
	// lwz r27,10832(r26)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r26.u32 + 10832);
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82564324
	if (!ctx.cr6.eq) goto loc_82564324;
	// lis r9,-32050
	ctx.r9.s64 = -2100428800;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// addi r25,r9,10240
	ctx.r25.s64 = ctx.r9.s64 + 10240;
	// addi r11,r11,-1720
	ctx.r11.s64 = ctx.r11.s64 + -1720;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stw r11,10240(r9)
	REX_STORE_U32(ctx.r9.u32 + 10240, ctx.r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r11,r8,-328
	ctx.r11.s64 = ctx.r8.s64 + -328;
	// addi r9,r9,-340
	ctx.r9.s64 = ctx.r9.s64 + -340;
	// stw r11,48(r25)
	REX_STORE_U32(ctx.r25.u32 + 48, ctx.r11.u32);
	// ori r11,r27,1
	ctx.r11.u64 = ctx.r27.u64 | 1;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// stw r9,32(r25)
	REX_STORE_U32(ctx.r25.u32 + 32, ctx.r9.u32);
	// stw r11,10832(r26)
	REX_STORE_U32(ctx.r26.u32 + 10832, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r11,12(r25)
	REX_STORE_U32(ctx.r25.u32 + 12, ctx.r11.u32);
	// addi r9,r6,-356
	ctx.r9.s64 = ctx.r6.s64 + -356;
	// addi r10,r10,-1752
	ctx.r10.s64 = ctx.r10.s64 + -1752;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,80(r25)
	REX_STORE_U32(ctx.r25.u32 + 80, ctx.r9.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// stw r10,16(r25)
	REX_STORE_U32(ctx.r25.u32 + 16, ctx.r10.u32);
	// stw r11,28(r25)
	REX_STORE_U32(ctx.r25.u32 + 28, ctx.r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r10,r7,-1664
	ctx.r10.s64 = ctx.r7.s64 + -1664;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r9,8(r25)
	REX_STORE_U32(ctx.r25.u32 + 8, ctx.r9.u32);
	// stw r10,64(r25)
	REX_STORE_U32(ctx.r25.u32 + 64, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,44(r25)
	REX_STORE_U32(ctx.r25.u32 + 44, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r10,4(r25)
	REX_STORE_U32(ctx.r25.u32 + 4, ctx.r10.u32);
	// stw r9,24(r25)
	REX_STORE_U32(ctx.r25.u32 + 24, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,60(r25)
	REX_STORE_U32(ctx.r25.u32 + 60, ctx.r11.u32);
	// li r9,-4
	ctx.r9.s64 = -4;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,20(r25)
	REX_STORE_U32(ctx.r25.u32 + 20, ctx.r10.u32);
	// stw r9,40(r25)
	REX_STORE_U32(ctx.r25.u32 + 40, ctx.r9.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,76(r25)
	REX_STORE_U32(ctx.r25.u32 + 76, ctx.r11.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r10,36(r25)
	REX_STORE_U32(ctx.r25.u32 + 36, ctx.r10.u32);
	// stw r10,52(r25)
	REX_STORE_U32(ctx.r25.u32 + 52, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,56(r25)
	REX_STORE_U32(ctx.r25.u32 + 56, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,92(r25)
	REX_STORE_U32(ctx.r25.u32 + 92, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stw r10,68(r25)
	REX_STORE_U32(ctx.r25.u32 + 68, ctx.r10.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// stw r9,72(r25)
	REX_STORE_U32(ctx.r25.u32 + 72, ctx.r9.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// stw r10,84(r25)
	REX_STORE_U32(ctx.r25.u32 + 84, ctx.r10.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// stw r9,88(r25)
	REX_STORE_U32(ctx.r25.u32 + 88, ctx.r9.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// stw r11,104(r25)
	REX_STORE_U32(ctx.r25.u32 + 104, ctx.r11.u32);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// stw r10,100(r25)
	REX_STORE_U32(ctx.r25.u32 + 100, ctx.r10.u32);
	// lis r31,-32246
	ctx.r31.s64 = -2113273856;
	// lis r30,-32246
	ctx.r30.s64 = -2113273856;
	// lis r29,-32246
	ctx.r29.s64 = -2113273856;
	// lis r28,-32246
	ctx.r28.s64 = -2113273856;
	// addi r8,r8,-372
	ctx.r8.s64 = ctx.r8.s64 + -372;
	// addi r7,r7,-388
	ctx.r7.s64 = ctx.r7.s64 + -388;
	// addi r6,r6,-400
	ctx.r6.s64 = ctx.r6.s64 + -400;
	// addi r5,r5,-412
	ctx.r5.s64 = ctx.r5.s64 + -412;
	// addi r4,r4,-424
	ctx.r4.s64 = ctx.r4.s64 + -424;
	// addi r3,r3,-440
	ctx.r3.s64 = ctx.r3.s64 + -440;
	// addi r31,r31,-456
	ctx.r31.s64 = ctx.r31.s64 + -456;
	// addi r30,r30,-1648
	ctx.r30.s64 = ctx.r30.s64 + -1648;
	// addi r29,r29,-468
	ctx.r29.s64 = ctx.r29.s64 + -468;
	// addi r28,r28,-484
	ctx.r28.s64 = ctx.r28.s64 + -484;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,120(r25)
	REX_STORE_U32(ctx.r25.u32 + 120, ctx.r11.u32);
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r8,96(r25)
	REX_STORE_U32(ctx.r25.u32 + 96, ctx.r8.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,140(r25)
	REX_STORE_U32(ctx.r25.u32 + 140, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,116(r25)
	REX_STORE_U32(ctx.r25.u32 + 116, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,108(r25)
	REX_STORE_U32(ctx.r25.u32 + 108, ctx.r9.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r8,132(r25)
	REX_STORE_U32(ctx.r25.u32 + 132, ctx.r8.u32);
	// li r8,9
	ctx.r8.s64 = 9;
	// stw r6,128(r25)
	REX_STORE_U32(ctx.r25.u32 + 128, ctx.r6.u32);
	// li r6,10
	ctx.r6.s64 = 10;
	// stw r11,168(r25)
	REX_STORE_U32(ctx.r25.u32 + 168, ctx.r11.u32);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r5,144(r25)
	REX_STORE_U32(ctx.r25.u32 + 144, ctx.r5.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r7,112(r25)
	REX_STORE_U32(ctx.r25.u32 + 112, ctx.r7.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r10,136(r25)
	REX_STORE_U32(ctx.r25.u32 + 136, ctx.r10.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r9,124(r25)
	REX_STORE_U32(ctx.r25.u32 + 124, ctx.r9.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r8,156(r25)
	REX_STORE_U32(ctx.r25.u32 + 156, ctx.r8.u32);
	// li r8,11
	ctx.r8.s64 = 11;
	// stw r6,172(r25)
	REX_STORE_U32(ctx.r25.u32 + 172, ctx.r6.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,204(r25)
	REX_STORE_U32(ctx.r25.u32 + 204, ctx.r11.u32);
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// stw r5,196(r25)
	REX_STORE_U32(ctx.r25.u32 + 196, ctx.r5.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r7,152(r25)
	REX_STORE_U32(ctx.r25.u32 + 152, ctx.r7.u32);
	// li r7,-2
	ctx.r7.s64 = -2;
	// stw r4,160(r25)
	REX_STORE_U32(ctx.r25.u32 + 160, ctx.r4.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,164(r25)
	REX_STORE_U32(ctx.r25.u32 + 164, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,148(r25)
	REX_STORE_U32(ctx.r25.u32 + 148, ctx.r9.u32);
	// addi r11,r11,-492
	ctx.r11.s64 = ctx.r11.s64 + -492;
	// stw r8,188(r25)
	REX_STORE_U32(ctx.r25.u32 + 188, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,180(r25)
	REX_STORE_U32(ctx.r25.u32 + 180, ctx.r9.u32);
	// li r9,13
	ctx.r9.s64 = 13;
	// stw r3,176(r25)
	REX_STORE_U32(ctx.r25.u32 + 176, ctx.r3.u32);
	// li r3,14
	ctx.r3.s64 = 14;
	// stw r30,208(r25)
	REX_STORE_U32(ctx.r25.u32 + 208, ctx.r30.u32);
	// lis r30,-32246
	ctx.r30.s64 = -2113273856;
	// stw r6,212(r25)
	REX_STORE_U32(ctx.r25.u32 + 212, ctx.r6.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// stw r31,192(r25)
	REX_STORE_U32(ctx.r25.u32 + 192, ctx.r31.u32);
	// lis r31,-32246
	ctx.r31.s64 = -2113273856;
	// stw r5,244(r25)
	REX_STORE_U32(ctx.r25.u32 + 244, ctx.r5.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// stw r7,184(r25)
	REX_STORE_U32(ctx.r25.u32 + 184, ctx.r7.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r10,200(r25)
	REX_STORE_U32(ctx.r25.u32 + 200, ctx.r10.u32);
	// stw r4,216(r25)
	REX_STORE_U32(ctx.r25.u32 + 216, ctx.r4.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// stw r10,248(r25)
	REX_STORE_U32(ctx.r25.u32 + 248, ctx.r10.u32);
	// addi r10,r30,-500
	ctx.r10.s64 = ctx.r30.s64 + -500;
	// stw r29,224(r25)
	REX_STORE_U32(ctx.r25.u32 + 224, ctx.r29.u32);
	// lis r29,-32246
	ctx.r29.s64 = -2113273856;
	// stw r8,232(r25)
	REX_STORE_U32(ctx.r25.u32 + 232, ctx.r8.u32);
	// addi r8,r6,-1508
	ctx.r8.s64 = ctx.r6.s64 + -1508;
	// stw r9,220(r25)
	REX_STORE_U32(ctx.r25.u32 + 220, ctx.r9.u32);
	// addi r9,r31,-1500
	ctx.r9.s64 = ctx.r31.s64 + -1500;
	// stw r3,236(r25)
	REX_STORE_U32(ctx.r25.u32 + 236, ctx.r3.u32);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// stw r11,256(r25)
	REX_STORE_U32(ctx.r25.u32 + 256, ctx.r11.u32);
	// addi r11,r5,-512
	ctx.r11.s64 = ctx.r5.s64 + -512;
	// stw r7,228(r25)
	REX_STORE_U32(ctx.r25.u32 + 228, ctx.r7.u32);
	// addi r7,r4,-524
	ctx.r7.s64 = ctx.r4.s64 + -524;
	// stw r10,320(r25)
	REX_STORE_U32(ctx.r25.u32 + 320, ctx.r10.u32);
	// addi r6,r29,-532
	ctx.r6.s64 = ctx.r29.s64 + -532;
	// stw r28,240(r25)
	REX_STORE_U32(ctx.r25.u32 + 240, ctx.r28.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// stw r9,272(r25)
	REX_STORE_U32(ctx.r25.u32 + 272, ctx.r9.u32);
	// addi r10,r3,-1684
	ctx.r10.s64 = ctx.r3.s64 + -1684;
	// stw r8,288(r25)
	REX_STORE_U32(ctx.r25.u32 + 288, ctx.r8.u32);
	// stw r11,352(r25)
	REX_STORE_U32(ctx.r25.u32 + 352, ctx.r11.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r10,384(r25)
	REX_STORE_U32(ctx.r25.u32 + 384, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r7,304(r25)
	REX_STORE_U32(ctx.r25.u32 + 304, ctx.r7.u32);
	// stw r11,252(r25)
	REX_STORE_U32(ctx.r25.u32 + 252, ctx.r11.u32);
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r10,260(r25)
	REX_STORE_U32(ctx.r25.u32 + 260, ctx.r10.u32);
	// addi r9,r4,-548
	ctx.r9.s64 = ctx.r4.s64 + -548;
	// stw r11,268(r25)
	REX_STORE_U32(ctx.r25.u32 + 268, ctx.r11.u32);
	// li r11,17
	ctx.r11.s64 = 17;
	// stw r10,276(r25)
	REX_STORE_U32(ctx.r25.u32 + 276, ctx.r10.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// stw r11,284(r25)
	REX_STORE_U32(ctx.r25.u32 + 284, ctx.r11.u32);
	// li r11,18
	ctx.r11.s64 = 18;
	// stw r10,292(r25)
	REX_STORE_U32(ctx.r25.u32 + 292, ctx.r10.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stw r11,300(r25)
	REX_STORE_U32(ctx.r25.u32 + 300, ctx.r11.u32);
	// li r11,19
	ctx.r11.s64 = 19;
	// stw r10,308(r25)
	REX_STORE_U32(ctx.r25.u32 + 308, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,316(r25)
	REX_STORE_U32(ctx.r25.u32 + 316, ctx.r11.u32);
	// li r11,20
	ctx.r11.s64 = 20;
	// stw r10,324(r25)
	REX_STORE_U32(ctx.r25.u32 + 324, ctx.r10.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,332(r25)
	REX_STORE_U32(ctx.r25.u32 + 332, ctx.r11.u32);
	// li r11,21
	ctx.r11.s64 = 21;
	// stw r10,340(r25)
	REX_STORE_U32(ctx.r25.u32 + 340, ctx.r10.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// stw r11,348(r25)
	REX_STORE_U32(ctx.r25.u32 + 348, ctx.r11.u32);
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r10,356(r25)
	REX_STORE_U32(ctx.r25.u32 + 356, ctx.r10.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// stw r11,364(r25)
	REX_STORE_U32(ctx.r25.u32 + 364, ctx.r11.u32);
	// li r11,23
	ctx.r11.s64 = 23;
	// stw r10,372(r25)
	REX_STORE_U32(ctx.r25.u32 + 372, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r6,336(r25)
	REX_STORE_U32(ctx.r25.u32 + 336, ctx.r6.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// stw r11,380(r25)
	REX_STORE_U32(ctx.r25.u32 + 380, ctx.r11.u32);
	// addi r11,r7,-560
	ctx.r11.s64 = ctx.r7.s64 + -560;
	// stw r9,368(r25)
	REX_STORE_U32(ctx.r25.u32 + 368, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,388(r25)
	REX_STORE_U32(ctx.r25.u32 + 388, ctx.r10.u32);
	// addi r10,r6,-1672
	ctx.r10.s64 = ctx.r6.s64 + -1672;
	// stw r11,416(r25)
	REX_STORE_U32(ctx.r25.u32 + 416, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,264(r25)
	REX_STORE_U32(ctx.r25.u32 + 264, ctx.r9.u32);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// stw r9,280(r25)
	REX_STORE_U32(ctx.r25.u32 + 280, ctx.r9.u32);
	// lis r31,-32246
	ctx.r31.s64 = -2113273856;
	// stw r9,296(r25)
	REX_STORE_U32(ctx.r25.u32 + 296, ctx.r9.u32);
	// addi r7,r4,-1712
	ctx.r7.s64 = ctx.r4.s64 + -1712;
	// stw r9,312(r25)
	REX_STORE_U32(ctx.r25.u32 + 312, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,432(r25)
	REX_STORE_U32(ctx.r25.u32 + 432, ctx.r10.u32);
	// li r10,24
	ctx.r10.s64 = 24;
	// stw r11,392(r25)
	REX_STORE_U32(ctx.r25.u32 + 392, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,328(r25)
	REX_STORE_U32(ctx.r25.u32 + 328, ctx.r9.u32);
	// addi r6,r3,-1776
	ctx.r6.s64 = ctx.r3.s64 + -1776;
	// stw r9,344(r25)
	REX_STORE_U32(ctx.r25.u32 + 344, ctx.r9.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// stw r9,360(r25)
	REX_STORE_U32(ctx.r25.u32 + 360, ctx.r9.u32);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// stw r9,376(r25)
	REX_STORE_U32(ctx.r25.u32 + 376, ctx.r9.u32);
	// addi r9,r8,-568
	ctx.r9.s64 = ctx.r8.s64 + -568;
	// stw r10,396(r25)
	REX_STORE_U32(ctx.r25.u32 + 396, ctx.r10.u32);
	// li r10,25
	ctx.r10.s64 = 25;
	// stw r11,408(r25)
	REX_STORE_U32(ctx.r25.u32 + 408, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,400(r25)
	REX_STORE_U32(ctx.r25.u32 + 400, ctx.r9.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,412(r25)
	REX_STORE_U32(ctx.r25.u32 + 412, ctx.r10.u32);
	// li r10,26
	ctx.r10.s64 = 26;
	// addi r8,r5,-1736
	ctx.r8.s64 = ctx.r5.s64 + -1736;
	// stw r11,424(r25)
	REX_STORE_U32(ctx.r25.u32 + 424, ctx.r11.u32);
	// addi r5,r31,-576
	ctx.r5.s64 = ctx.r31.s64 + -576;
	// stw r9,404(r25)
	REX_STORE_U32(ctx.r25.u32 + 404, ctx.r9.u32);
	// stw r10,428(r25)
	REX_STORE_U32(ctx.r25.u32 + 428, ctx.r10.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r9,420(r25)
	REX_STORE_U32(ctx.r25.u32 + 420, ctx.r9.u32);
	// li r10,27
	ctx.r10.s64 = 27;
	// stw r11,440(r25)
	REX_STORE_U32(ctx.r25.u32 + 440, ctx.r11.u32);
	// stw r11,456(r25)
	REX_STORE_U32(ctx.r25.u32 + 456, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,444(r25)
	REX_STORE_U32(ctx.r25.u32 + 444, ctx.r10.u32);
	// li r10,28
	ctx.r10.s64 = 28;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,436(r25)
	REX_STORE_U32(ctx.r25.u32 + 436, ctx.r9.u32);
	// stw r10,460(r25)
	REX_STORE_U32(ctx.r25.u32 + 460, ctx.r10.u32);
	// li r10,29
	ctx.r10.s64 = 29;
	// stw r9,452(r25)
	REX_STORE_U32(ctx.r25.u32 + 452, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,472(r25)
	REX_STORE_U32(ctx.r25.u32 + 472, ctx.r11.u32);
	// lis r31,-32246
	ctx.r31.s64 = -2113273856;
	// stw r10,476(r25)
	REX_STORE_U32(ctx.r25.u32 + 476, ctx.r10.u32);
	// li r10,30
	ctx.r10.s64 = 30;
	// stw r11,488(r25)
	REX_STORE_U32(ctx.r25.u32 + 488, ctx.r11.u32);
	// li r11,31
	ctx.r11.s64 = 31;
	// stw r9,468(r25)
	REX_STORE_U32(ctx.r25.u32 + 468, ctx.r9.u32);
	// stw r10,492(r25)
	REX_STORE_U32(ctx.r25.u32 + 492, ctx.r10.u32);
	// addi r10,r4,-1768
	ctx.r10.s64 = ctx.r4.s64 + -1768;
	// stw r9,484(r25)
	REX_STORE_U32(ctx.r25.u32 + 484, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,508(r25)
	REX_STORE_U32(ctx.r25.u32 + 508, ctx.r11.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,512(r25)
	REX_STORE_U32(ctx.r25.u32 + 512, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,504(r25)
	REX_STORE_U32(ctx.r25.u32 + 504, ctx.r9.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r11,516(r25)
	REX_STORE_U32(ctx.r25.u32 + 516, ctx.r11.u32);
	// stw r11,532(r25)
	REX_STORE_U32(ctx.r25.u32 + 532, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,520(r25)
	REX_STORE_U32(ctx.r25.u32 + 520, ctx.r10.u32);
	// stw r9,524(r25)
	REX_STORE_U32(ctx.r25.u32 + 524, ctx.r9.u32);
	// li r9,33
	ctx.r9.s64 = 33;
	// stw r10,536(r25)
	REX_STORE_U32(ctx.r25.u32 + 536, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,548(r25)
	REX_STORE_U32(ctx.r25.u32 + 548, ctx.r11.u32);
	// li r11,34
	ctx.r11.s64 = 34;
	// stw r6,480(r25)
	REX_STORE_U32(ctx.r25.u32 + 480, ctx.r6.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// stw r8,448(r25)
	REX_STORE_U32(ctx.r25.u32 + 448, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,540(r25)
	REX_STORE_U32(ctx.r25.u32 + 540, ctx.r9.u32);
	// addi r9,r6,-1760
	ctx.r9.s64 = ctx.r6.s64 + -1760;
	// stw r10,552(r25)
	REX_STORE_U32(ctx.r25.u32 + 552, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,556(r25)
	REX_STORE_U32(ctx.r25.u32 + 556, ctx.r11.u32);
	// li r11,35
	ctx.r11.s64 = 35;
	// stw r7,464(r25)
	REX_STORE_U32(ctx.r25.u32 + 464, ctx.r7.u32);
	// addi r7,r3,-1772
	ctx.r7.s64 = ctx.r3.s64 + -1772;
	// stw r8,500(r25)
	REX_STORE_U32(ctx.r25.u32 + 500, ctx.r8.u32);
	// addi r8,r31,-584
	ctx.r8.s64 = ctx.r31.s64 + -584;
	// stw r9,560(r25)
	REX_STORE_U32(ctx.r25.u32 + 560, ctx.r9.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,564(r25)
	REX_STORE_U32(ctx.r25.u32 + 564, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,572(r25)
	REX_STORE_U32(ctx.r25.u32 + 572, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r5,496(r25)
	REX_STORE_U32(ctx.r25.u32 + 496, ctx.r5.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r7,528(r25)
	REX_STORE_U32(ctx.r25.u32 + 528, ctx.r7.u32);
	// stw r8,544(r25)
	REX_STORE_U32(ctx.r25.u32 + 544, ctx.r8.u32);
	// stw r9,568(r25)
	REX_STORE_U32(ctx.r25.u32 + 568, ctx.r9.u32);
	// stw r10,576(r25)
	REX_STORE_U32(ctx.r25.u32 + 576, ctx.r10.u32);
	// stw r9,580(r25)
	REX_STORE_U32(ctx.r25.u32 + 580, ctx.r9.u32);
	// stw r11,584(r25)
	REX_STORE_U32(ctx.r25.u32 + 584, ctx.r11.u32);
	// stw r10,588(r25)
	REX_STORE_U32(ctx.r25.u32 + 588, ctx.r10.u32);
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
loc_82564324:
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// addi r3,r11,10240
	ctx.r3.s64 = ctx.r11.s64 + 10240;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8257F900) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x8257F908;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,132(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r27,416(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 416);
	// addi r26,r3,132
	ctx.r26.s64 = ctx.r3.s64 + 132;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8257fb78
	if (!ctx.cr6.eq) goto loc_8257FB78;
	// addi r29,r3,1768
	ctx.r29.s64 = ctx.r3.s64 + 1768;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826ccc44
	ctx.lr = 0x8257F930;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lbz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 424);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8257f960
	if (!ctx.cr6.eq) goto loc_8257F960;
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r10,19340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 19340);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8257F954;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r30,424(r31)
	REX_STORE_U8(ctx.r31.u32 + 424, ctx.r30.u8);
	// stw r9,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r9.u32);
loc_8257F960:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826ccc54
	ctx.lr = 0x8257F968;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8257f9b4
	if (!ctx.cr6.lt) goto loc_8257F9B4;
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,144
	ctx.r3.s64 = ctx.r31.s64 + 144;
	// lwz r10,19336(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 19336);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8257F98C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8257f9b4
	if (!ctx.cr6.lt) goto loc_8257F9B4;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// ori r10,r11,13
	ctx.r10.u64 = ctx.r11.u64 | 13;
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257F9B4:
	// lbz r11,705(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 705);
	// extsw r4,r27
	ctx.r4.s64 = ctx.r27.s32;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8257fadc
	if (!ctx.cr6.eq) goto loc_8257FADC;
	// lis r29,-32050
	ctx.r29.s64 = -2100428800;
	// lwz r11,19348(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 19348);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8257F9D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r28,-32050
	ctx.r28.s64 = -2100428800;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lwz r4,720(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// lwz r10,19344(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 19344);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8257F9F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rotlwi r9,r3,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,1760(r31)
	REX_STORE_U32(ctx.r31.u32 + 1760, ctx.r9.u32);
	// beq cr6,0x8257fab8
	if (ctx.cr6.eq) goto loc_8257FAB8;
	// lwz r11,720(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 720);
	// lwz r10,708(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 708);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8257fa3c
	if (ctx.cr6.lt) goto loc_8257FA3C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8257c5c0
	ctx.lr = 0x8257FA20;
	sub_8257C5C0(ctx, base);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// ori r10,r11,69
	ctx.r10.u64 = ctx.r11.u64 | 69;
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257FA3C:
	// lwz r8,16(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,712(r31)
	REX_STORE_U32(ctx.r31.u32 + 712, ctx.r8.u32);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r10,32768
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32768, ctx.xer);
	// ble cr6,0x8257fa74
	if (!ctx.cr6.gt) goto loc_8257FA74;
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// ori r10,r11,69
	ctx.r10.u64 = ctx.r11.u64 | 69;
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257FA74:
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r10,19348(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 19348);
	// add r9,r11,r27
	ctx.r9.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8257FA90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,19344(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 19344);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// addi r4,r31,724
	ctx.r4.s64 = ctx.r31.s64 + 724;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8257FAA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rotlwi r7,r3,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r7,1760(r31)
	REX_STORE_U32(ctx.r31.u32 + 1760, ctx.r7.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8257fb20
	if (!ctx.cr6.eq) goto loc_8257FB20;
loc_8257FAB8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8257c5c0
	ctx.lr = 0x8257FAC0;
	sub_8257C5C0(ctx, base);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// ori r10,r11,68
	ctx.r10.u64 = ctx.r11.u64 | 68;
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257FADC:
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// lwz r10,19348(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 19348);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8257FAEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32050
	ctx.r9.s64 = -2100428800;
	// lwz r4,492(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 492);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r8,19344(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 19344);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8257FB08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rotlwi r7,r3,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r7,1760(r31)
	REX_STORE_U32(ctx.r31.u32 + 1760, ctx.r7.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8257fab8
	if (ctx.cr6.eq) goto loc_8257FAB8;
	// li r11,2048
	ctx.r11.s64 = 2048;
	// stw r11,712(r31)
	REX_STORE_U32(ctx.r31.u32 + 712, ctx.r11.u32);
loc_8257FB20:
	// lwz r11,416(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8257fc5c
	if (!ctx.cr6.eq) goto loc_8257FC5C;
	// lbz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8257fc5c
	if (!ctx.cr6.eq) goto loc_8257FC5C;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r8,3
	ctx.r8.s64 = 3;
loc_8257FB40:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8257fb68
	if (!ctx.cr6.eq) goto loc_8257FB68;
	// stwcx. r8,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r8.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8257fb40
	if (!ctx.cr0.eq) goto loc_8257FB40;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257FB68:
	// stwcx. r10,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257FB78:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x8257fc5c
	if (!ctx.cr6.eq) goto loc_8257FC5C;
	// lwz r11,464(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 464);
	// lwz r10,480(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 480);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8257fb98
	if (!ctx.cr6.gt) goto loc_8257FB98;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
loc_8257FB98:
	// lis r10,-32050
	ctx.r10.s64 = -2100428800;
	// lwz r11,712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 712);
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// add r9,r11,r27
	ctx.r9.u64 = ctx.r11.u64 + ctx.r27.u64;
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// lwz r8,19348(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 19348);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8257FBB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r7,-32050
	ctx.r7.s64 = -2100428800;
	// lwz r4,492(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 492);
	// extsw r5,r30
	ctx.r5.s64 = ctx.r30.s32;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r6,19344(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 19344);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8257FBD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rotlwi r5,r3,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r5,1760(r31)
	REX_STORE_U32(ctx.r31.u32 + 1760, ctx.r5.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8257fc0c
	if (!ctx.cr6.eq) goto loc_8257FC0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8257c5c0
	ctx.lr = 0x8257FBEC;
	sub_8257C5C0(ctx, base);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r10,r11,68
	ctx.r10.u64 = ctx.r11.u64 | 68;
	// stw r30,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r30.u32);
	// stw r30,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// stw r10,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257FC0C:
	// lwz r11,416(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 416);
	// cmpw cr6,r27,r11
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8257fc5c
	if (!ctx.cr6.eq) goto loc_8257FC5C;
	// lbz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8257fc5c
	if (!ctx.cr6.eq) goto loc_8257FC5C;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r8,5
	ctx.r8.s64 = 5;
loc_8257FC2C:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r26
	ea = ctx.r26.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8257fc54
	if (!ctx.cr6.eq) goto loc_8257FC54;
	// stwcx. r8,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r8.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8257fc2c
	if (!ctx.cr0.eq) goto loc_8257FC2C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8257FC54:
	// stwcx. r10,0,r26
	ea = ctx.r26.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
loc_8257FC5C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8259A260) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a026c
	ctx.lr = 0x8259A268;
	__savegprlr_17(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r21,r5
	ctx.r21.u64 = ctx.r5.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8259a290
	if (!ctx.cr6.eq) goto loc_8259A290;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02bc
	__restgprlr_17(ctx, base);
	return;
loc_8259A290:
	// addi r23,r4,-24
	ctx.r23.s64 = ctx.r4.s64 + -24;
	// addi r22,r6,24
	ctx.r22.s64 = ctx.r6.s64 + 24;
	// cmplwi cr6,r23,50
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 50, ctx.xer);
	// blt cr6,0x8259a720
	if (ctx.cr6.lt) goto loc_8259A720;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r24,r22,32
	ctx.r24.u64 = ctx.r22.u64 & 0xFFFFFFFF;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r11,r24,r11
	ctx.r11.u64 = ctx.r24.u64 + ctx.r11.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,48
	ctx.r4.s64 = ctx.r11.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82588bc0
	ctx.lr = 0x8259A2C0;
	sub_82588BC0(ctx, base);
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// bne cr6,0x8259a720
	if (!ctx.cr6.eq) goto loc_8259A720;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8259a720
	if (ctx.cr6.eq) goto loc_8259A720;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r23,64
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 64, ctx.xer);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// clrlwi r25,r8,16
	ctx.r25.u64 = ctx.r8.u32 & 0xFFFF;
	// blt cr6,0x8259a720
	if (ctx.cr6.lt) goto loc_8259A720;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,4
	ctx.r5.s64 = 4;
	// add r11,r24,r11
	ctx.r11.u64 = ctx.r24.u64 + ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,60
	ctx.r4.s64 = ctx.r11.s64 + 60;
	// bl 0x82588bc0
	ctx.lr = 0x8259A314;
	sub_82588BC0(ctx, base);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bne cr6,0x8259a720
	if (!ctx.cr6.eq) goto loc_8259A720;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8259a720
	if (ctx.cr6.eq) goto loc_8259A720;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// li r28,64
	ctx.r28.s64 = 64;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rotlwi r7,r10,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r4,1(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rotlwi r10,r4,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// clrlwi r26,r3,16
	ctx.r26.u64 = ctx.r3.u32 & 0xFFFF;
	// beq cr6,0x8259a3f0
	if (ctx.cr6.eq) goto loc_8259A3F0;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8259a3f0
	if (!ctx.cr6.gt) goto loc_8259A3F0;
loc_8259A37C:
	// addi r30,r28,2
	ctx.r30.s64 = ctx.r28.s64 + 2;
	// addi r11,r30,2
	ctx.r11.s64 = ctx.r30.s64 + 2;
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// bgt cr6,0x8259a720
	if (ctx.cr6.gt) goto loc_8259A720;
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82588bc0
	ctx.lr = 0x8259A3AC;
	sub_82588BC0(ctx, base);
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// bne cr6,0x8259a720
	if (!ctx.cr6.eq) goto loc_8259A720;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8259a720
	if (ctx.cr6.eq) goto loc_8259A720;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// rotlwi r11,r9,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// cmpw cr6,r29,r27
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r27.s32, ctx.xer);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r11,r7,16
	ctx.r11.u64 = ctx.r7.u32 & 0xFFFF;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r28,r11,2
	ctx.r28.s64 = ctx.r11.s64 + 2;
	// blt cr6,0x8259a37c
	if (ctx.cr6.lt) goto loc_8259A37C;
loc_8259A3F0:
	// clrlwi r27,r26,16
	ctx.r27.u64 = ctx.r26.u32 & 0xFFFF;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8259a630
	if (ctx.cr6.eq) goto loc_8259A630;
	// lhz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 240);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x8259a414
	if (!ctx.cr6.eq) goto loc_8259A414;
loc_8259A408:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02bc
	__restgprlr_17(ctx, base);
	return;
loc_8259A414:
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bgt cr6,0x8259a408
	if (ctx.cr6.gt) goto loc_8259A408;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r29,0
	ctx.r29.s64 = 0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// sth r25,244(r10)
	REX_STORE_U16(ctx.r10.u32 + 244, ctx.r25.u16);
	// ble cr6,0x8259a630
	if (!ctx.cr6.gt) goto loc_8259A630;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r26,r11,6248
	ctx.r26.s64 = ctx.r11.s64 + 6248;
loc_8259A448:
	// addi r11,r28,22
	ctx.r11.s64 = ctx.r28.s64 + 22;
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// bgt cr6,0x8259a720
	if (ctx.cr6.gt) goto loc_8259A720;
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r24
	ctx.r11.u64 = ctx.r11.u64 + ctx.r24.u64;
	// li r5,22
	ctx.r5.s64 = 22;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82588bc0
	ctx.lr = 0x8259A474;
	sub_82588BC0(ctx, base);
	// cmplwi cr6,r3,22
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 22, ctx.xer);
	// bne cr6,0x8259a720
	if (!ctx.cr6.eq) goto loc_8259A720;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8259a720
	if (ctx.cr6.eq) goto loc_8259A720;
	// lbz r8,3(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbz r6,1(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// add r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 + ctx.r5.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r26,16
	ctx.r5.s64 = ctx.r26.s64 + 16;
	// rlwinm r8,r4,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// add r3,r8,r6
	ctx.r3.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lbz r6,1(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rlwinm r8,r3,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lbz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rotlwi r8,r6,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// add r3,r8,r7
	ctx.r3.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lbz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,1(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// lbzu r6,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r6.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzu r8,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r8.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzu r4,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r4.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzu r25,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r25.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzu r20,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r20.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzu r19,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r19.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzu r18,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r18.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzu r17,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r17.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// sth r3,100(r1)
	REX_STORE_U16(ctx.r1.u32 + 100, ctx.r3.u16);
	// stb r8,105(r1)
	REX_STORE_U8(ctx.r1.u32 + 105, ctx.r8.u8);
	// stb r6,104(r1)
	REX_STORE_U8(ctx.r1.u32 + 104, ctx.r6.u8);
	// stb r4,106(r1)
	REX_STORE_U8(ctx.r1.u32 + 106, ctx.r4.u8);
	// sth r7,102(r1)
	REX_STORE_U16(ctx.r1.u32 + 102, ctx.r7.u16);
	// stb r20,108(r1)
	REX_STORE_U8(ctx.r1.u32 + 108, ctx.r20.u8);
	// stb r25,107(r1)
	REX_STORE_U8(ctx.r1.u32 + 107, ctx.r25.u8);
	// stb r19,109(r1)
	REX_STORE_U8(ctx.r1.u32 + 109, ctx.r19.u8);
	// stb r17,111(r1)
	REX_STORE_U8(ctx.r1.u32 + 111, ctx.r17.u8);
	// stb r18,110(r1)
	REX_STORE_U8(ctx.r1.u32 + 110, ctx.r18.u8);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_8259A55C:
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// subf. r8,r8,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8259a57c
	if (!ctx.cr0.eq) goto loc_8259A57C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// bne cr6,0x8259a55c
	if (!ctx.cr6.eq) goto loc_8259A55C;
loc_8259A57C:
	// lhz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 240);
	// cntlzw r10,r8
	ctx.r10.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpw cr6,r29,r27
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r27.s32, ctx.xer);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r30
	ctx.r7.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stwx r9,r7,r31
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r6,1(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// rotlwi r9,r6,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// lhz r11,240(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 240);
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 3);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// sth r4,248(r11)
	REX_STORE_U16(ctx.r11.u32 + 248, ctx.r4.u16);
	// lhz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 240);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// sth r8,240(r31)
	REX_STORE_U16(ctx.r31.u32 + 240, ctx.r8.u16);
	// addi r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 2;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r5,3(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// rotlwi r10,r5,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r11,r4,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r3,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r28,r11,22
	ctx.r28.s64 = ctx.r11.s64 + 22;
	// blt cr6,0x8259a448
	if (ctx.cr6.lt) goto loc_8259A448;
loc_8259A630:
	// addi r30,r28,24
	ctx.r30.s64 = ctx.r28.s64 + 24;
	// cmplw cr6,r30,r23
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x8259a714
	if (!ctx.cr6.lt) goto loc_8259A714;
	// add r6,r28,r22
	ctx.r6.u64 = ctx.r28.u64 + ctx.r22.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825981d0
	ctx.lr = 0x8259A650;
	sub_825981D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8259a724
	if (!ctx.cr6.eq) goto loc_8259A724;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,6056
	ctx.r11.s64 = ctx.r11.s64 + 6056;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
loc_8259A668:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8259a688
	if (!ctx.cr0.eq) goto loc_8259A688;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8259a668
	if (!ctx.cr6.eq) goto loc_8259A668;
loc_8259A688:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8259a6c8
	if (ctx.cr6.eq) goto loc_8259A6C8;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,6184
	ctx.r11.s64 = ctx.r11.s64 + 6184;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
loc_8259A6A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8259a6c0
	if (!ctx.cr0.eq) goto loc_8259A6C0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8259a6a0
	if (!ctx.cr6.eq) goto loc_8259A6A0;
loc_8259A6C0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8259a714
	if (!ctx.cr6.eq) goto loc_8259A714;
loc_8259A6C8:
	// lwz r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// add r11,r30,r22
	ctx.r11.u64 = ctx.r30.u64 + ctx.r22.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// addi r10,r4,-24
	ctx.r10.s64 = ctx.r4.s64 + -24;
	// ld r8,40(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// mr r30,r9
	ctx.r30.u64 = ctx.r9.u64;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r11,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r11.u64);
	// cmpld cr6,r7,r8
	ctx.cr6.compare<uint64_t>(ctx.r7.u64, ctx.r8.u64, ctx.xer);
	// bgt cr6,0x8259a408
	if (ctx.cr6.gt) goto loc_8259A408;
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825987a0
	ctx.lr = 0x8259A708;
	sub_825987A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8259a724
	if (!ctx.cr6.eq) goto loc_8259A724;
	// std r30,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r30.u64);
loc_8259A714:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02bc
	__restgprlr_17(ctx, base);
	return;
loc_8259A720:
	// li r3,3
	ctx.r3.s64 = 3;
loc_8259A724:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02bc
	__restgprlr_17(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825BE380) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0270
	ctx.lr = 0x825BE388;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// li r24,0
	ctx.r24.s64 = 0;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r23,r24
	ctx.r23.u64 = ctx.r24.u64;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x825beae8
	if (ctx.cr6.eq) goto loc_825BEAE8;
	// li r20,3
	ctx.r20.s64 = 3;
	// li r18,6
	ctx.r18.s64 = 6;
	// li r21,7
	ctx.r21.s64 = 7;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r19,8
	ctx.r19.s64 = 8;
loc_825BE3BC:
	// lwz r11,36(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x825beac8
	if (ctx.cr6.gt) goto loc_825BEAC8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x825beac8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825BEAC8;
	// bdzf 4*cr6+eq,0x825beac8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825BEAC8;
	// bdzf 4*cr6+eq,0x825be428
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825BE428;
	// bdzf 4*cr6+eq,0x825beac8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825BEAC8;
	// bdzf 4*cr6+eq,0x825beac8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825BEAC8;
	// bdzf 4*cr6+eq,0x825be5bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825BE5BC;
	// bne cr6,0x825be940
	if (!ctx.cr6.eq) goto loc_825BE940;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825bc978
	ctx.lr = 0x825BE3F4;
	sub_825BC978(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825beae8
	if (ctx.cr6.lt) goto loc_825BEAE8;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r20,36(r28)
	REX_STORE_U32(ctx.r28.u32 + 36, ctx.r20.u32);
	// sth r24,150(r28)
	REX_STORE_U16(ctx.r28.u32 + 150, ctx.r24.u16);
	// stw r24,72(r28)
	REX_STORE_U32(ctx.r28.u32 + 72, ctx.r24.u32);
	// sth r24,148(r28)
	REX_STORE_U16(ctx.r28.u32 + 148, ctx.r24.u16);
	// sth r24,202(r11)
	REX_STORE_U16(ctx.r11.u32 + 202, ctx.r24.u16);
	// stw r24,76(r28)
	REX_STORE_U32(ctx.r28.u32 + 76, ctx.r24.u32);
	// stw r24,200(r28)
	REX_STORE_U32(ctx.r28.u32 + 200, ctx.r24.u32);
	// stw r24,208(r28)
	REX_STORE_U32(ctx.r28.u32 + 208, ctx.r24.u32);
	// b 0x825beac8
	goto loc_825BEAC8;
loc_825BE428:
	// lwz r11,204(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825be508
	if (!ctx.cr6.eq) goto loc_825BE508;
	// lwz r11,20(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825beae0
	if (ctx.cr6.eq) goto loc_825BEAE0;
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// lhz r10,150(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x825be4fc
	if (!ctx.cr6.lt) goto loc_825BE4FC;
loc_825BE458:
	// lhz r11,150(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// lwz r10,584(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// mulli r10,r6,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(1776));
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r5,40(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x825be4a4
	if (ctx.cr6.eq) goto loc_825BE4A4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825bdde8
	ctx.lr = 0x825BE498;
	sub_825BDDE8(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825beae8
	if (ctx.cr6.lt) goto loc_825BEAE8;
loc_825BE4A4:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lhz r10,118(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 118);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lhz r8,202(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 202);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x825beae0
	if (ctx.cr6.gt) goto loc_825BEAE0;
	// stw r24,72(r28)
	REX_STORE_U32(ctx.r28.u32 + 72, ctx.r24.u32);
	// sth r24,148(r28)
	REX_STORE_U16(ctx.r28.u32 + 148, ctx.r24.u16);
	// sth r24,202(r11)
	REX_STORE_U16(ctx.r11.u32 + 202, ctx.r24.u16);
	// lhz r11,150(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// stw r24,76(r28)
	REX_STORE_U32(ctx.r28.u32 + 76, ctx.r24.u32);
	// stw r24,200(r28)
	REX_STORE_U32(ctx.r28.u32 + 200, ctx.r24.u32);
	// stw r24,208(r28)
	REX_STORE_U32(ctx.r28.u32 + 208, ctx.r24.u32);
	// extsh r5,r8
	ctx.r5.s64 = ctx.r8.s16;
	// sth r10,150(r28)
	REX_STORE_U16(ctx.r28.u32 + 150, ctx.r10.u16);
	// lhz r7,580(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// cmpw cr6,r5,r6
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x825be458
	if (ctx.cr6.lt) goto loc_825BE458;
loc_825BE4FC:
	// stw r18,36(r28)
	REX_STORE_U32(ctx.r28.u32 + 36, ctx.r18.u32);
	// sth r24,150(r28)
	REX_STORE_U16(ctx.r28.u32 + 150, ctx.r24.u16);
	// b 0x825beac8
	goto loc_825BEAC8;
loc_825BE508:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x825be5b4
	if (!ctx.cr6.eq) goto loc_825BE5B4;
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// lhz r10,150(r28)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x825be5b0
	if (!ctx.cr6.lt) goto loc_825BE5B0;
loc_825BE528:
	// lhz r11,150(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r10,584(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// mulli r10,r6,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(1776));
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x825bdad0
	ctx.lr = 0x825BE55C;
	sub_825BDAD0(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825beae8
	if (ctx.cr6.lt) goto loc_825BEAE8;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lhz r10,118(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 118);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lhz r8,202(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 202);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x825beae0
	if (ctx.cr6.gt) goto loc_825BEAE0;
	// stw r24,72(r28)
	REX_STORE_U32(ctx.r28.u32 + 72, ctx.r24.u32);
	// sth r24,202(r11)
	REX_STORE_U16(ctx.r11.u32 + 202, ctx.r24.u16);
	// lhz r11,150(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r10,150(r28)
	REX_STORE_U16(ctx.r28.u32 + 150, ctx.r10.u16);
	// lhz r8,580(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// cmpw cr6,r5,r7
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x825be528
	if (ctx.cr6.lt) goto loc_825BE528;
loc_825BE5B0:
	// stw r21,36(r28)
	REX_STORE_U32(ctx.r28.u32 + 36, ctx.r21.u32);
loc_825BE5B4:
	// sth r24,150(r28)
	REX_STORE_U16(ctx.r28.u32 + 150, ctx.r24.u16);
	// b 0x825beac8
	goto loc_825BEAC8;
loc_825BE5BC:
	// sth r24,150(r28)
	REX_STORE_U16(ctx.r28.u32 + 150, ctx.r24.u16);
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x825be658
	if (!ctx.cr6.gt) goto loc_825BE658;
loc_825BE5D0:
	// lhz r11,150(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// lwz r10,584(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r10
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// mulli r10,r6,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(1776));
	// add r30,r10,r11
	ctx.r30.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r5,40(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x825be634
	if (!ctx.cr6.eq) goto loc_825BE634;
	// lwz r10,424(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r9,118(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 118);
	// lwz r11,56(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 56);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// lwz r7,12(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r6,0(r7)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x826a03b0
	ctx.lr = 0x825BE630;
	rexcrt_memset(ctx, base);
	// stw r24,48(r30)
	REX_STORE_U32(ctx.r30.u32 + 48, ctx.r24.u32);
loc_825BE634:
	// lhz r11,150(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 150);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// sth r10,150(r28)
	REX_STORE_U16(ctx.r28.u32 + 150, ctx.r10.u16);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lhz r7,580(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x825be5d0
	if (ctx.cr6.lt) goto loc_825BE5D0;
loc_825BE658:
	// lwz r10,656(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 656);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x825be7b8
	if (!ctx.cr6.eq) goto loc_825BE7B8;
	// lwz r8,584(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// lwz r9,320(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lhz r10,34(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// lwz r30,364(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// lwz r27,368(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 368);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// lhz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// mulli r8,r6,1776
	ctx.r8.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(1776));
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lhz r4,118(r5)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r5.u32 + 118);
	// extsh r25,r4
	ctx.r25.s64 = ctx.r4.s16;
	// bne cr6,0x825beae0
	if (!ctx.cr6.eq) goto loc_825BEAE0;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x825be7b8
	if (!ctx.cr6.gt) goto loc_825BE7B8;
	// addi r26,r31,664
	ctx.r26.s64 = ctx.r31.s64 + 664;
loc_825BE6A8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x825be714
	if (!ctx.cr6.gt) goto loc_825BE714;
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
loc_825BE6B4:
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// mulli r10,r9,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(1776));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,424(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// lwz r7,56(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r6,12(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// lhz r5,0(r6)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// extsh r8,r5
	ctx.r8.s64 = ctx.r5.s16;
	// add r4,r8,r29
	ctx.r4.u64 = ctx.r8.u64 + ctx.r29.u64;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r3,r7
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// stwx r8,r10,r30
	REX_STORE_U32(ctx.r10.u32 + ctx.r30.u32, ctx.r8.u32);
	// lwz r7,40(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x825be6fc
	if (!ctx.cr6.eq) goto loc_825BE6FC;
	// stwx r24,r10,r27
	REX_STORE_U32(ctx.r10.u32 + ctx.r27.u32, ctx.r24.u32);
	// b 0x825be700
	goto loc_825BE700;
loc_825BE6FC:
	// stwx r22,r10,r27
	REX_STORE_U32(ctx.r10.u32 + ctx.r27.u32, ctx.r22.u32);
loc_825BE700:
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// lhz r10,34(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x825be6b4
	if (ctx.cr6.lt) goto loc_825BE6B4;
loc_825BE714:
	// lwz r11,500(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 500);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825BE734;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,504(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 504);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825BE750;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r10,34(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x825be7ac
	if (!ctx.cr6.gt) goto loc_825BE7AC;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// rlwinm r9,r24,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
loc_825BE764:
	// lwz r8,320(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// mulli r10,r11,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(1776));
	// lwzx r7,r9,r30
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// lwz r4,424(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 424);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,56(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// lhz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + 0);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// add r6,r10,r29
	ctx.r6.u64 = ctx.r10.u64 + ctx.r29.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r5,r3
	REX_STORE_U32(ctx.r5.u32 + ctx.r3.u32, ctx.r7.u32);
	// lhz r10,34(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x825be764
	if (ctx.cr6.lt) goto loc_825BE764;
loc_825BE7AC:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r25
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x825be6a8
	if (ctx.cr6.lt) goto loc_825BE6A8;
loc_825BE7B8:
	// lwz r11,184(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x825be874
	if (!ctx.cr6.eq) goto loc_825BE874;
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x825be874
	if (!ctx.cr6.eq) goto loc_825BE874;
	// lwz r11,584(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lhz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// mulli r11,r7,1776
	ctx.r11.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(1776));
	// mulli r9,r6,1776
	ctx.r9.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(1776));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r5,424(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// lwz r4,424(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 424);
	// lhz r3,118(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 118);
	// lwz r7,56(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r9,56(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// lwz r11,12(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r8,12(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lhz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lhz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// beq cr6,0x825be874
	if (ctx.cr6.eq) goto loc_825BE874;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// subf r10,r11,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r11.u64;
loc_825BE848:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwzx r8,r10,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// srawi r7,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 1;
	// subf r6,r7,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r7.u64;
	// stwx r6,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r6.u32);
	// rotlwi r8,r6,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x825be848
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825BE848;
loc_825BE874:
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// lhz r10,34(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x825beae0
	if (!ctx.cr6.eq) goto loc_825BEAE0;
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x825be89c
	if (!ctx.cr6.eq) goto loc_825BE89C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825b6140
	ctx.lr = 0x825BE89C;
	sub_825B6140(ctx, base);
loc_825BE89C:
	// lhz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 208);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x825be8b0
	if (ctx.cr6.eq) goto loc_825BE8B0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825b60a0
	ctx.lr = 0x825BE8B0;
	sub_825B60A0(ctx, base);
loc_825BE8B0:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x825be938
	if (!ctx.cr6.eq) goto loc_825BE938;
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x825be938
	if (!ctx.cr6.eq) goto loc_825BE938;
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x825be938
	if (!ctx.cr6.gt) goto loc_825BE938;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_825BE8E0:
	// lwz r8,584(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lhz r9,168(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 168);
	// lhzx r7,r11,r8
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r8.u32);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// mulli r11,r6,1776
	ctx.r11.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(1776));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r11,1456
	ctx.r7.s64 = ctx.r11.s64 + 1456;
	// addi r5,r11,1616
	ctx.r5.s64 = ctx.r11.s64 + 1616;
	// lwz r4,56(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// lhz r11,118(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 118);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// bl 0x825b6478
	ctx.lr = 0x825BE91C;
	sub_825B6478(ctx, base);
	// lhz r8,580(r31)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// extsh r30,r10
	ctx.r30.s64 = ctx.r10.s16;
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r30,r7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x825be8e0
	if (ctx.cr6.lt) goto loc_825BE8E0;
loc_825BE938:
	// stw r21,36(r28)
	REX_STORE_U32(ctx.r28.u32 + 36, ctx.r21.u32);
	// b 0x825beac8
	goto loc_825BEAC8;
loc_825BE940:
	// lbz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 200);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825be9e4
	if (ctx.cr6.eq) goto loc_825BE9E4;
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x825be9e4
	if (!ctx.cr6.gt) goto loc_825BE9E4;
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_825BE964:
	// lwz r9,584(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// lwz r10,320(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lhzx r7,r11,r9
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r9.u32);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// mulli r11,r6,1776
	ctx.r11.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(1776));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,424(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// lhz r4,118(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 118);
	// lwz r9,56(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// extsh r11,r4
	ctx.r11.s64 = ctx.r4.s16;
	// lwz r3,12(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// ble cr6,0x825be9c8
	if (!ctx.cr6.gt) goto loc_825BE9C8;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_825BE9B0:
	// lbz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 200);
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// extsb r7,r11
	ctx.r7.s64 = ctx.r11.s8;
	// slw r6,r9,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// stwu r6,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x825be9b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825BE9B0;
loc_825BE9C8:
	// lhz r10,580(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x825be964
	if (ctx.cr6.lt) goto loc_825BE964;
loc_825BE9E4:
	// lhz r11,580(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x825bea58
	if (!ctx.cr6.gt) goto loc_825BEA58;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// rlwinm r9,r24,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_825BE9FC:
	// lwz r10,584(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwz r8,320(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// lhzx r5,r9,r10
	ctx.r5.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// mulli r10,r4,1776
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(1776));
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r3,424(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 424);
	// lhz r10,114(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 114);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// lwz r7,12(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,8(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lhz r8,0(r7)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r7.u32 + 0);
	// lhzx r3,r6,r5
	ctx.r3.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r5.u32);
	// add r10,r3,r8
	ctx.r10.u64 = ctx.r3.u64 + ctx.r8.u64;
	// sth r10,0(r7)
	REX_STORE_U16(ctx.r7.u32 + 0, ctx.r10.u16);
	// lhz r7,580(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x825be9fc
	if (ctx.cr6.lt) goto loc_825BE9FC;
loc_825BEA58:
	// lwz r11,176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 176);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x825beac4
	if (!ctx.cr6.eq) goto loc_825BEAC4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x825beac4
	if (!ctx.cr6.gt) goto loc_825BEAC4;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// rlwinm r8,r24,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
loc_825BEA74:
	// lwz r10,584(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 584);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwz r6,320(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// lwz r9,356(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// lhzx r4,r8,r10
	ctx.r4.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// mulli r7,r3,1776
	ctx.r7.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(1776));
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r5,118(r7)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r7.u32 + 118);
	// lwzx r6,r10,r9
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// extsh r7,r5
	ctx.r7.s64 = ctx.r5.s16;
	// add r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stwx r4,r10,r9
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// lhz r3,580(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 580);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x825bea74
	if (ctx.cr6.lt) goto loc_825BEA74;
loc_825BEAC4:
	// stw r19,36(r28)
	REX_STORE_U32(ctx.r28.u32 + 36, ctx.r19.u32);
loc_825BEAC8:
	// lwz r11,36(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x825be3bc
	if (!ctx.cr6.eq) goto loc_825BE3BC;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02c0
	__restgprlr_18(ctx, base);
	return;
loc_825BEAE0:
	// lis r23,-32764
	ctx.r23.s64 = -2147221504;
	// ori r23,r23,2
	ctx.r23.u64 = ctx.r23.u64 | 2;
loc_825BEAE8:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02c0
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FF678) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x825FF680;
	__savegprlr_24(ctx, base);
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// li r28,128
	ctx.r28.s64 = 128;
	// lwz r9,12(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// li r11,0
	ctx.r11.s64 = 0;
	// srawi r27,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r27.s64 = ctx.r10.s32 >> 1;
	// subf r26,r9,r8
	ctx.r26.u64 = ctx.r8.u64 - ctx.r9.u64;
	// rlwinm r25,r27,0,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x825ffa90
	if (!ctx.cr6.gt) goto loc_825FFA90;
	// lis r9,-32640
	ctx.r9.s64 = -2139095040;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r29,r9,32896
	ctx.r29.u64 = ctx.r9.u64 | 32896;
loc_825FF6B0:
	// lwz r9,60(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 60);
	// srawi r8,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 2;
	// lbzx r30,r8,r9
	ctx.r30.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825ff6d8
	if (!ctx.cr6.eq) goto loc_825FF6D8;
	// stwx r29,r11,r3
	REX_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r29.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stwx r29,r11,r5
	REX_STORE_U32(ctx.r11.u32 + ctx.r5.u32, ctx.r29.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// b 0x825ffa88
	goto loc_825FFA88;
loc_825FF6D8:
	// clrlwi r9,r30,26
	ctx.r9.u64 = ctx.r30.u32 & 0x3F;
	// rlwinm r9,r9,0,30,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x825ff898
	if (!ctx.cr6.eq) goto loc_825FF898;
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// lwz r31,64(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lwz r8,12(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r30,r10,r9
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// mullw r31,r30,r26
	ctx.r31.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r26.s32);
	// srawi r31,r31,20
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xFFFFF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r31,r8
	ctx.r8.u64 = ctx.r31.u64 + ctx.r8.u64;
	// blt cr6,0x825ff748
	if (ctx.cr6.lt) goto loc_825FF748;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ff748
	if (ctx.cr6.lt) goto loc_825FF748;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ff748
	if (!ctx.cr6.lt) goto loc_825FF748;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ff750
	goto loc_825FF750;
loc_825FF748:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FF750:
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r30,r10,r9
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r9,r10,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mullw r8,r30,r26
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ff7b8
	if (ctx.cr6.lt) goto loc_825FF7B8;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ff7b8
	if (ctx.cr6.lt) goto loc_825FF7B8;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ff7b8
	if (!ctx.cr6.lt) goto loc_825FF7B8;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ff7c0
	goto loc_825FF7C0;
loc_825FF7B8:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FF7C0:
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r30,r10,r9
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r9,r10,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mullw r8,r30,r26
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ff828
	if (ctx.cr6.lt) goto loc_825FF828;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ff828
	if (ctx.cr6.lt) goto loc_825FF828;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ff828
	if (!ctx.cr6.lt) goto loc_825FF828;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ff830
	goto loc_825FF830;
loc_825FF828:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FF830:
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r30,r10,r9
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r9,r10,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mullw r8,r30,r26
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ffa78
	if (ctx.cr6.lt) goto loc_825FFA78;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ffa78
	if (ctx.cr6.lt) goto loc_825FFA78;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ffa78
	if (!ctx.cr6.lt) goto loc_825FFA78;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ffa80
	goto loc_825FFA80;
loc_825FF898:
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ff904
	if (ctx.cr6.eq) goto loc_825FF904;
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r24,r9,r10
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r9,r8,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mullw r8,r24,r26
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ff904
	if (ctx.cr6.lt) goto loc_825FF904;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ff904
	if (ctx.cr6.lt) goto loc_825FF904;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ff904
	if (!ctx.cr6.lt) goto loc_825FF904;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ff90c
	goto loc_825FF90C;
loc_825FF904:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FF90C:
	// rlwinm r9,r30,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x4;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ff980
	if (ctx.cr6.eq) goto loc_825FF980;
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r24,r9,r10
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r9,r8,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mullw r8,r24,r26
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ff980
	if (ctx.cr6.lt) goto loc_825FF980;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ff980
	if (ctx.cr6.lt) goto loc_825FF980;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ff980
	if (!ctx.cr6.lt) goto loc_825FF980;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ff988
	goto loc_825FF988;
loc_825FF980:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FF988:
	// rlwinm r9,r30,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x10;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ff9fc
	if (ctx.cr6.eq) goto loc_825FF9FC;
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r24,r9,r10
	ctx.r24.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r9,r8,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mullw r8,r24,r26
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ff9fc
	if (ctx.cr6.lt) goto loc_825FF9FC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ff9fc
	if (ctx.cr6.lt) goto loc_825FF9FC;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ff9fc
	if (!ctx.cr6.lt) goto loc_825FF9FC;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ffa04
	goto loc_825FFA04;
loc_825FF9FC:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FFA04:
	// rlwinm r9,r30,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x40;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ffa78
	if (ctx.cr6.eq) goto loc_825FFA78;
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r30,r9,r10
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r9,r8,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mullw r8,r30,r26
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ffa78
	if (ctx.cr6.lt) goto loc_825FFA78;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ffa78
	if (ctx.cr6.lt) goto loc_825FFA78;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ffa78
	if (!ctx.cr6.lt) goto loc_825FFA78;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ffa80
	goto loc_825FFA80;
loc_825FFA78:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FFA80:
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_825FFA88:
	// cmpw cr6,r11,r25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r25.s32, ctx.xer);
	// blt cr6,0x825ff6b0
	if (ctx.cr6.lt) goto loc_825FF6B0;
loc_825FFA90:
	// cmpw cr6,r25,r27
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x825ffb44
	if (ctx.cr6.eq) goto loc_825FFB44;
	// lwz r10,60(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 60);
	// srawi r9,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 2;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// lbzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// bge cr6,0x825ffb44
	if (!ctx.cr6.lt) goto loc_825FFB44;
	// clrlwi r30,r10,24
	ctx.r30.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r29,1
	ctx.r29.s64 = 1;
loc_825FFAB8:
	// rlwinm r9,r11,1,29,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x6;
	// slw r8,r29,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r9.u8 & 0x3F));
	// and r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 & ctx.r30.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825ffb2c
	if (ctx.cr6.eq) goto loc_825FFB2C;
	// lwz r9,68(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// lwz r8,64(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lwz r31,12(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwzx r25,r9,r10
	ctx.r25.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r9,r8,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mullw r8,r25,r26
	ctx.r8.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r26.s32);
	// srawi r8,r8,20
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 20;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// blt cr6,0x825ffb2c
	if (ctx.cr6.lt) goto loc_825FFB2C;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// blt cr6,0x825ffb2c
	if (ctx.cr6.lt) goto loc_825FFB2C;
	// lwz r31,4(r7)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// bge cr6,0x825ffb2c
	if (!ctx.cr6.lt) goto loc_825FFB2C;
	// srawi r31,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r8.s32 >> 1;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// mullw r9,r31,r27
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r8,r9,r4
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// stbx r8,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r8.u8);
	// lbzx r9,r9,r6
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// stbx r9,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u8);
	// b 0x825ffb34
	goto loc_825FFB34;
loc_825FFB2C:
	// stbx r28,r11,r3
	REX_STORE_U8(ctx.r11.u32 + ctx.r3.u32, ctx.r28.u8);
	// stbx r28,r11,r5
	REX_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u8);
loc_825FFB34:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x825ffab8
	if (ctx.cr6.lt) goto loc_825FFAB8;
loc_825FFB44:
	// add r3,r27,r3
	ctx.r3.u64 = ctx.r27.u64 + ctx.r3.u64;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8261C630) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32049
	ctx.r10.s64 = -2100363264;
	// lwz r11,-14144(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -14144);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-14144(r10)
	REX_STORE_U32(ctx.r10.u32 + -14144, ctx.r11.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lis r11,-32049
	ctx.r11.s64 = -2100363264;
	// beq cr6,0x8261c654
	if (ctx.cr6.eq) goto loc_8261C654;
	// lwz r3,-24392(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -24392);
	// blr 
	return;
loc_8261C654:
	// addi r8,r11,-24392
	ctx.r8.s64 = ctx.r11.s64 + -24392;
	// li r10,10240
	ctx.r10.s64 = 10240;
	// addi r9,r8,8
	ctx.r9.s64 = ctx.r8.s64 + 8;
	// li r11,-5120
	ctx.r11.s64 = -5120;
	// addi r9,r9,5120
	ctx.r9.s64 = ctx.r9.s64 + 5120;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r9,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_8261C670:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8261c680
	if (!ctx.cr6.lt) goto loc_8261C680;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8261c690
	goto loc_8261C690;
loc_8261C680:
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// li r10,255
	ctx.r10.s64 = 255;
	// bgt cr6,0x8261c690
	if (ctx.cr6.gt) goto loc_8261C690;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8261C690:
	// addi r9,r8,8
	ctx.r9.s64 = ctx.r8.s64 + 8;
	// addi r9,r9,5120
	ctx.r9.s64 = ctx.r9.s64 + 5120;
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8261c670
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261C670;
	// addi r11,r8,8
	ctx.r11.s64 = ctx.r8.s64 + 8;
	// addi r3,r11,5120
	ctx.r3.s64 = ctx.r11.s64 + 5120;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261E088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0274
	ctx.lr = 0x8261E090;
	__savegprlr_19(ctx, base);
	// lis r31,-32048
	ctx.r31.s64 = -2100297728;
	// lwz r22,92(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// add r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r21,84(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// neg r11,r9
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r9.u64);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r29,r11,28
	ctx.r29.u64 = ctx.r11.u32 & 0xF;
	// lwz r11,16192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16192);
	// addi r3,r6,-1
	ctx.r3.s64 = ctx.r6.s64 + -1;
	// cmpw cr6,r4,r5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r26,r11,r10
	ctx.r26.u64 = ctx.r10.u64 - ctx.r11.u64;
	// add r6,r6,r29
	ctx.r6.u64 = ctx.r6.u64 + ctx.r29.u64;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// srawi r20,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r20.s64 = ctx.r9.s32 >> 3;
	// subfic r6,r22,0
	ctx.xer.ca = ctx.r22.u32 <= 0;
	ctx.r6.u64 = static_cast<uint64_t>(0) - ctx.r22.u64;
	// subf r27,r11,r9
	ctx.r27.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subfe r9,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r9,r9,0,27,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1C;
	// rlwinm r9,r9,0,29,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// addi r23,r9,20
	ctx.r23.s64 = ctx.r9.s64 + 20;
	// bge cr6,0x8261e194
	if (!ctx.cr6.lt) goto loc_8261E194;
	// subf r25,r26,r10
	ctx.r25.u64 = ctx.r10.u64 - ctx.r26.u64;
	// subf r24,r4,r5
	ctx.r24.u64 = ctx.r5.u64 - ctx.r4.u64;
loc_8261E0F4:
	// lbzx r6,r25,r28
	ctx.r6.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r28.u32);
	// add r10,r27,r28
	ctx.r10.u64 = ctx.r27.u64 + ctx.r28.u64;
	// lbz r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// rldicr r30,r6,8,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r6.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// rldicr r19,r4,8,63
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r4.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// or r6,r30,r6
	ctx.r6.u64 = ctx.r30.u64 | ctx.r6.u64;
	// or r4,r19,r4
	ctx.r4.u64 = ctx.r19.u64 | ctx.r4.u64;
	// rldicr r30,r6,16,47
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r6.u64, 16) & 0xFFFFFFFFFFFF0000;
	// rldicr r19,r4,16,47
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r4.u64, 16) & 0xFFFFFFFFFFFF0000;
	// or r6,r30,r6
	ctx.r6.u64 = ctx.r30.u64 | ctx.r6.u64;
	// or r30,r19,r4
	ctx.r30.u64 = ctx.r19.u64 | ctx.r4.u64;
	// rldicr r4,r6,32,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF00000000;
	// rldicr r19,r30,32,31
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r30.u64, 32) & 0xFFFFFFFF00000000;
	// or r4,r4,r6
	ctx.r4.u64 = ctx.r4.u64 | ctx.r6.u64;
	// or r30,r19,r30
	ctx.r30.u64 = ctx.r19.u64 | ctx.r30.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8261e158
	if (!ctx.cr6.gt) goto loc_8261E158;
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_8261E144:
	// lbz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// stbx r6,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r6.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x8261e144
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261E144;
	// lwz r11,16192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16192);
loc_8261E158:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8261e184
	if (!ctx.cr6.gt) goto loc_8261E184;
	// subf r6,r10,r28
	ctx.r6.u64 = ctx.r28.u64 - ctx.r10.u64;
loc_8261E168:
	// stdx r4,r6,r10
	REX_STORE_U64(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u64);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// std r30,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r30.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// lwz r11,16192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16192);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8261e168
	if (ctx.cr6.lt) goto loc_8261E168;
loc_8261E184:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// add r28,r28,r21
	ctx.r28.u64 = ctx.r28.u64 + ctx.r21.u64;
	// add r3,r3,r21
	ctx.r3.u64 = ctx.r3.u64 + ctx.r21.u64;
	// bne 0x8261e0f4
	if (!ctx.cr0.eq) goto loc_8261E0F4;
loc_8261E194:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8261e1e0
	if (ctx.cr6.eq) goto loc_8261E1E0;
	// mullw r11,r23,r21
	ctx.r11.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r21.s32);
	// subf r11,r11,r26
	ctx.r11.u64 = ctx.r26.u64 - ctx.r11.u64;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// ble cr6,0x8261e1e0
	if (!ctx.cr6.gt) goto loc_8261E1E0;
	// subf r10,r26,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r26.u64;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
loc_8261E1B4:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x8261e1d4
	if (!ctx.cr6.gt) goto loc_8261E1D4;
	// mtctr r20
	ctx.ctr.u64 = ctx.r20.u64;
loc_8261E1C4:
	// ld r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// stdx r7,r10,r11
	REX_STORE_U64(ctx.r10.u32 + ctx.r11.u32, ctx.r7.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x8261e1c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261E1C4;
loc_8261E1D4:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r10,r10,r21
	ctx.r10.u64 = ctx.r10.u64 + ctx.r21.u64;
	// bne 0x8261e1b4
	if (!ctx.cr0.eq) goto loc_8261E1B4;
loc_8261E1E0:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8261e244
	if (ctx.cr6.eq) goto loc_8261E244;
	// subf r8,r21,r28
	ctx.r8.u64 = ctx.r28.u64 - ctx.r21.u64;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// neg r11,r5
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// beq cr6,0x8261e200
	if (ctx.cr6.eq) goto loc_8261E200;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// b 0x8261e204
	goto loc_8261E204;
loc_8261E200:
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
loc_8261E204:
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8261e244
	if (!ctx.cr6.gt) goto loc_8261E244;
	// subf r10,r8,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r8.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8261E218:
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x8261e238
	if (!ctx.cr6.gt) goto loc_8261E238;
	// mtctr r20
	ctx.ctr.u64 = ctx.r20.u64;
loc_8261E228:
	// ld r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// stdx r7,r10,r11
	REX_STORE_U64(ctx.r10.u32 + ctx.r11.u32, ctx.r7.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x8261e228
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261E228;
loc_8261E238:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r10,r10,r21
	ctx.r10.u64 = ctx.r10.u64 + ctx.r21.u64;
	// bne 0x8261e218
	if (!ctx.cr0.eq) goto loc_8261E218;
loc_8261E244:
	// b 0x826a02c4
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82629128) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r9,r4,-2
	ctx.r9.s64 = ctx.r4.s64 + -2;
	// lhz r8,50(r3)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r3.u32 + 50);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// lhz r7,52(r3)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r3.u32 + 52);
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// cntlzw r5,r9
	ctx.r5.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// srawi r4,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 16;
	// srw r9,r8,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
	// rlwinm r5,r5,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// li r11,0
	ctx.r11.s64 = 0;
	// srw r8,r7,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r10.u8 & 0x3F));
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8262916c
	if (!ctx.cr6.eq) goto loc_8262916C;
	// li r11,1
	ctx.r11.s64 = 1;
loc_8262916C:
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// lhz r31,16(r6)
	ctx.r31.u64 = REX_LOAD_U16(ctx.r6.u32 + 16);
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// lhz r6,18(r6)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r6.u32 + 18);
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r8,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// srw r8,r31,r30
	ctx.r8.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r31.u32 >> (ctx.r30.u8 & 0x3F));
	// add r31,r9,r11
	ctx.r31.u64 = ctx.r9.u64 + ctx.r11.u64;
	// srw r9,r6,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r7.u8 & 0x3F));
	// subfic r7,r11,-7
	ctx.xer.ca = ctx.r11.u32 <= 4294967289;
	ctx.r7.u64 = static_cast<uint64_t>(-7) - ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r30,r7,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r9,r9,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// slw r8,r30,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x826291d8
	if (!ctx.cr6.gt) goto loc_826291D8;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// b 0x826291ec
	goto loc_826291EC;
loc_826291D8:
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// not r5,r11
	ctx.r5.u64 = ~ctx.r11.u64;
	// and r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 & ctx.r9.u64;
	// and r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 & ctx.r6.u64;
loc_826291EC:
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x826291fc
	if (!ctx.cr6.lt) goto loc_826291FC;
	// subf r11,r9,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r9.u64;
	// b 0x82629208
	goto loc_82629208;
loc_826291FC:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x8262920c
	if (!ctx.cr6.gt) goto loc_8262920C;
	// subf r11,r9,r7
	ctx.r11.u64 = ctx.r7.u64 - ctx.r9.u64;
loc_82629208:
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
loc_8262920C:
	// cmpw cr6,r6,r8
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8262922c
	if (!ctx.cr6.lt) goto loc_8262922C;
	// subf r11,r6,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r6.u64;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwimi r3,r4,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8262922C:
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x8262923c
	if (!ctx.cr6.gt) goto loc_8262923C;
	// subf r11,r6,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r6.u64;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
loc_8262923C:
	// rlwimi r3,r4,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8262F708) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0278
	ctx.lr = 0x8262F710;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F740;
	rexcrt_memcpy(ctx, base);
	// lwz r28,284(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r29,r29,r28
	ctx.r29.u64 = ctx.r29.u64 + ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F75C;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r21,r30,r31
	ctx.r21.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r20,r29,r28
	ctx.r20.u64 = ctx.r29.u64 + ctx.r28.u64;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// addi r9,r27,-1
	ctx.r9.s64 = ctx.r27.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F774:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f774
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F774;
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r30,276(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r29,292(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// addi r10,r24,-1
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// add r23,r25,r30
	ctx.r23.u64 = ctx.r25.u64 + ctx.r30.u64;
	// add r22,r27,r29
	ctx.r22.u64 = ctx.r27.u64 + ctx.r29.u64;
	// addi r9,r26,-1
	ctx.r9.s64 = ctx.r26.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F7A0:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f7a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F7A0;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// add r25,r24,r30
	ctx.r25.u64 = ctx.r24.u64 + ctx.r30.u64;
	// add r24,r26,r29
	ctx.r24.u64 = ctx.r26.u64 + ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F7C4;
	rexcrt_memcpy(ctx, base);
	// add r27,r21,r31
	ctx.r27.u64 = ctx.r21.u64 + ctx.r31.u64;
	// add r26,r20,r28
	ctx.r26.u64 = ctx.r20.u64 + ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F7DC;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// addi r10,r23,-1
	ctx.r10.s64 = ctx.r23.s64 + -1;
	// addi r9,r22,-1
	ctx.r9.s64 = ctx.r22.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F7F4:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f7f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F7F4;
	// li r11,8
	ctx.r11.s64 = 8;
	// add r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 + ctx.r30.u64;
	// add r22,r22,r29
	ctx.r22.u64 = ctx.r22.u64 + ctx.r29.u64;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// addi r9,r24,-1
	ctx.r9.s64 = ctx.r24.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F818:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f818
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F818;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r25,r25,r30
	ctx.r25.u64 = ctx.r25.u64 + ctx.r30.u64;
	// add r24,r24,r29
	ctx.r24.u64 = ctx.r24.u64 + ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F83C;
	rexcrt_memcpy(ctx, base);
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F854;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// addi r10,r23,-1
	ctx.r10.s64 = ctx.r23.s64 + -1;
	// addi r9,r22,-1
	ctx.r9.s64 = ctx.r22.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F86C:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f86c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F86C;
	// li r11,8
	ctx.r11.s64 = 8;
	// add r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 + ctx.r30.u64;
	// add r22,r22,r29
	ctx.r22.u64 = ctx.r22.u64 + ctx.r29.u64;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// addi r9,r24,-1
	ctx.r9.s64 = ctx.r24.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F890:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f890
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F890;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r25,r25,r30
	ctx.r25.u64 = ctx.r25.u64 + ctx.r30.u64;
	// add r24,r24,r29
	ctx.r24.u64 = ctx.r24.u64 + ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F8B4;
	rexcrt_memcpy(ctx, base);
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F8CC;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// addi r10,r23,-1
	ctx.r10.s64 = ctx.r23.s64 + -1;
	// addi r9,r22,-1
	ctx.r9.s64 = ctx.r22.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F8E4:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f8e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F8E4;
	// li r11,8
	ctx.r11.s64 = 8;
	// add r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 + ctx.r30.u64;
	// add r22,r22,r29
	ctx.r22.u64 = ctx.r22.u64 + ctx.r29.u64;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// addi r9,r24,-1
	ctx.r9.s64 = ctx.r24.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F908:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f908
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F908;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r25,r25,r30
	ctx.r25.u64 = ctx.r25.u64 + ctx.r30.u64;
	// add r24,r24,r29
	ctx.r24.u64 = ctx.r24.u64 + ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F92C;
	rexcrt_memcpy(ctx, base);
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F944;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// addi r10,r23,-1
	ctx.r10.s64 = ctx.r23.s64 + -1;
	// addi r9,r22,-1
	ctx.r9.s64 = ctx.r22.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F95C:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f95c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F95C;
	// li r11,8
	ctx.r11.s64 = 8;
	// add r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 + ctx.r30.u64;
	// add r22,r22,r29
	ctx.r22.u64 = ctx.r22.u64 + ctx.r29.u64;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// addi r9,r24,-1
	ctx.r9.s64 = ctx.r24.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F980:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f980
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F980;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r25,r25,r30
	ctx.r25.u64 = ctx.r25.u64 + ctx.r30.u64;
	// add r24,r24,r29
	ctx.r24.u64 = ctx.r24.u64 + ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F9A4;
	rexcrt_memcpy(ctx, base);
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262F9BC;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// addi r10,r23,-1
	ctx.r10.s64 = ctx.r23.s64 + -1;
	// addi r9,r22,-1
	ctx.r9.s64 = ctx.r22.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F9D4:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f9d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F9D4;
	// li r11,8
	ctx.r11.s64 = 8;
	// add r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 + ctx.r30.u64;
	// add r22,r22,r29
	ctx.r22.u64 = ctx.r22.u64 + ctx.r29.u64;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// addi r9,r24,-1
	ctx.r9.s64 = ctx.r24.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262F9F8:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262f9f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262F9F8;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r25,r25,r30
	ctx.r25.u64 = ctx.r25.u64 + ctx.r30.u64;
	// add r21,r24,r29
	ctx.r21.u64 = ctx.r24.u64 + ctx.r29.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262FA1C;
	rexcrt_memcpy(ctx, base);
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262FA34;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r26,r26,r28
	ctx.r26.u64 = ctx.r26.u64 + ctx.r28.u64;
	// addi r10,r23,-1
	ctx.r10.s64 = ctx.r23.s64 + -1;
	// addi r9,r22,-1
	ctx.r9.s64 = ctx.r22.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262FA4C:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262fa4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262FA4C;
	// li r11,8
	ctx.r11.s64 = 8;
	// add r24,r23,r30
	ctx.r24.u64 = ctx.r23.u64 + ctx.r30.u64;
	// addi r10,r25,-1
	ctx.r10.s64 = ctx.r25.s64 + -1;
	// addi r9,r21,-1
	ctx.r9.s64 = ctx.r21.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262FA6C:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x8262fa6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262FA6C;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r30,r25,r30
	ctx.r30.u64 = ctx.r25.u64 + ctx.r30.u64;
	// bl 0x826a1130
	ctx.lr = 0x8262FA8C;
	rexcrt_memcpy(ctx, base);
	// add r4,r27,r31
	ctx.r4.u64 = ctx.r27.u64 + ctx.r31.u64;
	// add r3,r26,r28
	ctx.r3.u64 = ctx.r26.u64 + ctx.r28.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x826a1130
	ctx.lr = 0x8262FA9C;
	rexcrt_memcpy(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// add r10,r22,r29
	ctx.r10.u64 = ctx.r22.u64 + ctx.r29.u64;
	// addi r9,r24,-1
	ctx.r9.s64 = ctx.r24.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8262FAB0:
	// lbzu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// stbu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r11.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8262fab0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262FAB0;
	// li r9,8
	ctx.r9.s64 = 8;
	// add r10,r21,r29
	ctx.r10.u64 = ctx.r21.u64 + ctx.r29.u64;
	// addi r11,r30,-1
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8262FAD0:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8262fad0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8262FAD0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02c8
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826415A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmpw cr6,r3,r8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x826415b4
	if (ctx.cr6.lt) goto loc_826415B4;
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// b 0x826415b8
	goto loc_826415B8;
loc_826415B4:
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_826415B8:
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x826415c8
	if (!ctx.cr6.gt) goto loc_826415C8;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// b 0x826415d4
	goto loc_826415D4;
loc_826415C8:
	// cmpw cr6,r5,r8
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x826415d4
	if (!ctx.cr6.gt) goto loc_826415D4;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_826415D4:
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x826415e4
	if (!ctx.cr6.gt) goto loc_826415E4;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// b 0x826415f0
	goto loc_826415F0;
loc_826415E4:
	// cmpw cr6,r7,r8
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x826415f0
	if (!ctx.cr6.gt) goto loc_826415F0;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
loc_826415F0:
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// ble cr6,0x82641600
	if (!ctx.cr6.gt) goto loc_82641600;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// b 0x8264160c
	goto loc_8264160C;
loc_82641600:
	// cmpw cr6,r4,r8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x8264160c
	if (!ctx.cr6.gt) goto loc_8264160C;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
loc_8264160C:
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// ble cr6,0x8264161c
	if (!ctx.cr6.gt) goto loc_8264161C;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// b 0x82641628
	goto loc_82641628;
loc_8264161C:
	// cmpw cr6,r6,r8
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x82641628
	if (!ctx.cr6.gt) goto loc_82641628;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_82641628:
	// subf r11,r11,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subfc r10,r9,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r9.u32;
	ctx.r10.u64 = ctx.r11.u64 - ctx.r9.u64;
	// eqv r9,r9,r11
	ctx.r9.u64 = ~(ctx.r9.u64 ^ ctx.r11.u64);
	// rlwinm r8,r9,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// clrlwi r3,r7,31
	ctx.r3.u64 = ctx.r7.u32 & 0x1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826426C8) {
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
	// li r11,1024
	ctx.r11.s64 = 1024;
	// stw r4,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// beq cr6,0x82642704
	if (ctx.cr6.eq) goto loc_82642704;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r6,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// b 0x82642708
	goto loc_82642708;
loc_82642704:
	// stw r6,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r6.u32);
loc_82642708:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82642730
	if (!ctx.cr6.gt) goto loc_82642730;
	// addi r5,r31,8
	ctx.r5.s64 = ctx.r31.s64 + 8;
loc_82642718:
	// lwzu r3,4(r5)
	ea = 4 + ctx.r5.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r5.u32 = ea;
	// bl 0x82642248
	ctx.lr = 0x82642720;
	sub_82642248(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82642718
	if (ctx.cr6.lt) goto loc_82642718;
loc_82642730:
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

DEFINE_REX_FUNC(sub_82643490) {
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
	// lwz r3,60(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826434d8
	if (ctx.cr6.eq) goto loc_826434D8;
	// bl 0x825eeda8
	ctx.lr = 0x826434B4;
	sub_825EEDA8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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
loc_826434D8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82649768) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x82649770;
	__savegprlr_14(ctx, base);
	// lwz r27,104(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r26,108(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// lwz r10,80(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r9,92(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// srawi r22,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r22.s64 = ctx.r10.s32 >> 1;
	// lwz r11,112(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 112);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r10,116(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// stw r3,20(r1)
	REX_STORE_U32(ctx.r1.u32 + 20, ctx.r3.u32);
	// stw r27,-264(r1)
	REX_STORE_U32(ctx.r1.u32 + -264, ctx.r27.u32);
	// stw r26,-268(r1)
	REX_STORE_U32(ctx.r1.u32 + -268, ctx.r26.u32);
	// stw r4,-248(r1)
	REX_STORE_U32(ctx.r1.u32 + -248, ctx.r4.u32);
	// ble cr6,0x8264b2d0
	if (!ctx.cr6.gt) goto loc_8264B2D0;
	// addi r30,r9,-1
	ctx.r30.s64 = ctx.r9.s64 + -1;
	// fsub f8,f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = ctx.f2.f64 - ctx.f1.f64;
	// addi r29,r10,-1
	ctx.r29.s64 = ctx.r10.s64 + -1;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// stw r30,-316(r1)
	REX_STORE_U32(ctx.r1.u32 + -316, ctx.r30.u32);
	// lis r11,-32245
	ctx.r11.s64 = -2113208320;
	// stw r29,-320(r1)
	REX_STORE_U32(ctx.r1.u32 + -320, ctx.r29.u32);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// stw r8,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r8.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// lfd f9,6624(r11)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r11.u32 + 6624);
	// li r24,16
	ctx.r24.s64 = 16;
	// lfd f11,6560(r10)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r10.u32 + 6560);
	// li r25,128
	ctx.r25.s64 = 128;
	// lfd f6,14704(r9)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r9.u32 + 14704);
	// lfd f10,7304(r7)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r7.u32 + 7304);
	// lfd f7,-2368(r6)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r6.u32 + -2368);
loc_826497F8:
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// lwz r10,96(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f0,f8
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f8.f64;
	// std r11,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.r11.u64);
	// lfd f13,-168(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r7,-312(r1)
	REX_STORE_U32(ctx.r1.u32 + -312, ctx.r7.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// fmadd f12,f12,f3,f4
	ctx.f12.f64 = std::fma(ctx.f12.f64, ctx.f3.f64, ctx.f4.f64);
	// beq cr6,0x82649830
	if (ctx.cr6.eq) goto loc_82649830;
	// fsub f13,f3,f7
	ctx.f13.f64 = ctx.f3.f64 - ctx.f7.f64;
	// fmul f13,f13,f10
	ctx.f13.f64 = ctx.f13.f64 * ctx.f10.f64;
	// b 0x82649834
	goto loc_82649834;
loc_82649830:
	// fmr f13,f6
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f6.f64;
loc_82649834:
	// fadd f13,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 + ctx.f12.f64;
	// lwz r9,80(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r10,100(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// fmul f12,f13,f10
	ctx.f12.f64 = ctx.f13.f64 * ctx.f10.f64;
	// fctiwz f5,f13
	ctx.f5.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f5,-224(r1)
	REX_STORE_U64(ctx.r1.u32 + -224, ctx.f5.u64);
	// lwz r11,-220(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// fctiwz f2,f12
	ctx.f2.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f2,-240(r1)
	REX_STORE_U64(ctx.r1.u32 + -240, ctx.f2.u64);
	// lwz r6,-236(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// rlwinm r6,r6,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// stw r10,-260(r1)
	REX_STORE_U32(ctx.r1.u32 + -260, ctx.r10.u32);
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// std r5,-208(r1)
	REX_STORE_U64(ctx.r1.u32 + -208, ctx.r5.u64);
	// lfd f12,-208(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -208);
	// std r6,-200(r1)
	REX_STORE_U64(ctx.r1.u32 + -200, ctx.r6.u64);
	// fcfid f5,f12
	ctx.f5.f64 = double(ctx.f12.s64);
	// lfd f12,-200(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -200);
	// fmsub f2,f13,f9,f5
	ctx.f2.f64 = std::fma(ctx.f13.f64, ctx.f9.f64, -ctx.f5.f64);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// fctiwz f2,f2
	ctx.f2.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f2,-224(r1)
	REX_STORE_U64(ctx.r1.u32 + -224, ctx.f2.u64);
	// lwz r9,-220(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// mullw r31,r9,r9
	ctx.r31.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r9.s32);
	// fcfid f5,f12
	ctx.f5.f64 = double(ctx.f12.s64);
	// fmsub f13,f13,f11,f5
	ctx.f13.f64 = std::fma(ctx.f13.f64, ctx.f11.f64, -ctx.f5.f64);
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-232(r1)
	REX_STORE_U64(ctx.r1.u32 + -232, ctx.f12.u64);
	// lwz r6,-228(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// mullw r5,r6,r6
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r6.s32);
	// srawi r5,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 8;
	// mullw r6,r5,r6
	ctx.r6.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// stw r5,-300(r1)
	REX_STORE_U32(ctx.r1.u32 + -300, ctx.r5.u32);
	// srawi r5,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 8;
	// srawi r6,r31,8
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r31.s32 >> 8;
	// stw r5,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r5.u32);
	// mullw r9,r6,r9
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// stw r6,-280(r1)
	REX_STORE_U32(ctx.r1.u32 + -280, ctx.r6.u32);
	// srawi r6,r9,8
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 8;
	// stw r6,-272(r1)
	REX_STORE_U32(ctx.r1.u32 + -272, ctx.r6.u32);
	// ble cr6,0x8264a94c
	if (!ctx.cr6.gt) goto loc_8264A94C;
	// lwz r9,84(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8264a94c
	if (!ctx.cr6.lt) goto loc_8264A94C;
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,-276(r1)
	REX_STORE_U32(ctx.r1.u32 + -276, ctx.r9.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8264ab3c
	if (!ctx.cr6.gt) goto loc_8264AB3C;
loc_8264990C:
	// fadd f0,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 + ctx.f1.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-360(r1)
	REX_STORE_U64(ctx.r1.u32 + -360, ctx.f13.u64);
	// lwz r11,-356(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -356);
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// std r6,-216(r1)
	REX_STORE_U64(ctx.r1.u32 + -216, ctx.r6.u64);
	// lfd f12,-216(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -216);
	// fcfid f5,f12
	ctx.f5.f64 = double(ctx.f12.s64);
	// fmsub f2,f0,f11,f5
	ctx.f2.f64 = std::fma(ctx.f0.f64, ctx.f11.f64, -ctx.f5.f64);
	// fctiwz f13,f2
	ctx.f13.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f13,-360(r1)
	REX_STORE_U64(ctx.r1.u32 + -360, ctx.f13.u64);
	// lwz r28,-356(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + -356);
	// ble cr6,0x8264a828
	if (!ctx.cr6.gt) goto loc_8264A828;
	// lwz r9,80(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8264a828
	if (!ctx.cr6.lt) goto loc_8264A828;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r6,80(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// mullw r4,r28,r28
	ctx.r4.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r28.s32);
	// lbzx r7,r6,r10
	ctx.r7.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r9,-1(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -1);
	// lbz r5,2(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r8,1(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// add r3,r6,r10
	ctx.r3.u64 = ctx.r6.u64 + ctx.r10.u64;
	// subf r27,r6,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r6.u64;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r25,r4,8
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r25.s64 = ctx.r4.s32 >> 8;
	// add r24,r6,r10
	ctx.r24.u64 = ctx.r6.u64 + ctx.r10.u64;
	// lbz r31,1(r3)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r20,r11,1
	ctx.r20.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lbz r6,-1(r27)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r27.u32 + -1);
	// add r15,r7,r8
	ctx.r15.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lbz r10,0(r27)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r27.u32 + 0);
	// subf r16,r31,r7
	ctx.r16.u64 = ctx.r7.u64 - ctx.r31.u64;
	// lbz r29,1(r27)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r27.u32 + 1);
	// add r4,r31,r6
	ctx.r4.u64 = ctx.r31.u64 + ctx.r6.u64;
	// lbz r30,-1(r3)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r3.u32 + -1);
	// add r19,r9,r10
	ctx.r19.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r17,r4,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r26,-1(r24)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r24.u32 + -1);
	// subf r18,r29,r10
	ctx.r18.u64 = ctx.r10.u64 - ctx.r29.u64;
	// lbz r23,1(r24)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r24.u32 + 1);
	// lbz r21,2(r24)
	ctx.r21.u64 = REX_LOAD_U8(ctx.r24.u32 + 2);
	// rlwinm r19,r19,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r4,0(r24)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// add r24,r20,r30
	ctx.r24.u64 = ctx.r20.u64 + ctx.r30.u64;
	// rlwinm r20,r18,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r27,2(r27)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r27.u32 + 2);
	// subf r18,r26,r17
	ctx.r18.u64 = ctx.r17.u64 - ctx.r26.u64;
	// lbz r3,2(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// add r17,r24,r29
	ctx.r17.u64 = ctx.r24.u64 + ctx.r29.u64;
	// subf r24,r19,r4
	ctx.r24.u64 = ctx.r4.u64 - ctx.r19.u64;
	// subf r20,r4,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r4.u64;
	// subf r19,r27,r18
	ctx.r19.u64 = ctx.r18.u64 - ctx.r27.u64;
	// rlwinm r18,r17,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r20,r6,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r6.u64;
	// rlwinm r19,r19,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r17,r23,r18
	ctx.r17.u64 = ctx.r18.u64 - ctx.r23.u64;
	// add r18,r20,r23
	ctx.r18.u64 = ctx.r20.u64 + ctx.r23.u64;
	// add r24,r24,r5
	ctx.r24.u64 = ctx.r24.u64 + ctx.r5.u64;
	// add r20,r19,r21
	ctx.r20.u64 = ctx.r19.u64 + ctx.r21.u64;
	// rlwinm r14,r24,3,0,28
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r20,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r20.u32);
	// subf r20,r3,r17
	ctx.r20.u64 = ctx.r17.u64 - ctx.r3.u64;
	// subf r19,r24,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r24.u64;
	// lwz r17,-364(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// rlwinm r24,r17,1,0,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// add r14,r18,r27
	ctx.r14.u64 = ctx.r18.u64 + ctx.r27.u64;
	// rlwinm r17,r20,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r18,r5,r16
	ctx.r18.u64 = ctx.r16.u64 - ctx.r5.u64;
	// add r16,r19,r24
	ctx.r16.u64 = ctx.r19.u64 + ctx.r24.u64;
	// add r19,r20,r17
	ctx.r19.u64 = ctx.r20.u64 + ctx.r17.u64;
	// rlwinm r20,r14,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// add r24,r18,r9
	ctx.r24.u64 = ctx.r18.u64 + ctx.r9.u64;
	// subf r18,r21,r20
	ctx.r18.u64 = ctx.r20.u64 - ctx.r21.u64;
	// add r19,r16,r19
	ctx.r19.u64 = ctx.r16.u64 + ctx.r19.u64;
	// mulli r17,r15,13
	ctx.r17.s64 = static_cast<int64_t>(ctx.r15.u64 * static_cast<uint64_t>(13));
	// rlwinm r16,r24,3,0,28
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r15,r25,r28
	ctx.r15.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r28.s32);
	// add r18,r18,r26
	ctx.r18.u64 = ctx.r18.u64 + ctx.r26.u64;
	// subf r14,r17,r19
	ctx.r14.u64 = ctx.r19.u64 - ctx.r17.u64;
	// subf r19,r24,r16
	ctx.r19.u64 = ctx.r16.u64 - ctx.r24.u64;
	// rlwinm r18,r18,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r24,r15,8
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0xFF) != 0);
	ctx.r24.s64 = ctx.r15.s32 >> 8;
	// rotlwi r16,r11,2
	ctx.r16.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// subf r20,r30,r3
	ctx.r20.u64 = ctx.r3.u64 - ctx.r30.u64;
	// srawi r15,r14,1
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x1) != 0);
	ctx.r15.s64 = ctx.r14.s32 >> 1;
	// add r16,r11,r16
	ctx.r16.u64 = ctx.r11.u64 + ctx.r16.u64;
	// add r19,r18,r19
	ctx.r19.u64 = ctx.r18.u64 + ctx.r19.u64;
	// rlwinm r17,r20,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r16,-288(r1)
	REX_STORE_U32(ctx.r1.u32 + -288, ctx.r16.u32);
	// mullw r18,r15,r25
	ctx.r18.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r25.s32);
	// stw r18,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r18.u32);
	// add r20,r20,r17
	ctx.r20.u64 = ctx.r20.u64 + ctx.r17.u64;
	// subf r14,r11,r8
	ctx.r14.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r16,r7,r31
	ctx.r16.u64 = ctx.r31.u64 - ctx.r7.u64;
	// add r20,r19,r20
	ctx.r20.u64 = ctx.r19.u64 + ctx.r20.u64;
	// subf r19,r30,r9
	ctx.r19.u64 = ctx.r9.u64 - ctx.r30.u64;
	// stw r20,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r20.u32);
	// subf r20,r23,r4
	ctx.r20.u64 = ctx.r4.u64 - ctx.r23.u64;
	// rlwinm r19,r19,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r17,r3,r20
	ctx.r17.u64 = ctx.r20.u64 - ctx.r3.u64;
	// subf r20,r5,r19
	ctx.r20.u64 = ctx.r19.u64 - ctx.r5.u64;
	// subf r19,r11,r10
	ctx.r19.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r20,r6,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r6.u64;
	// subf r19,r6,r19
	ctx.r19.u64 = ctx.r19.u64 - ctx.r6.u64;
	// add r18,r20,r26
	ctx.r18.u64 = ctx.r20.u64 + ctx.r26.u64;
	// rlwinm r20,r19,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// add r15,r18,r3
	ctx.r15.u64 = ctx.r18.u64 + ctx.r3.u64;
	// subf r3,r8,r16
	ctx.r3.u64 = ctx.r16.u64 - ctx.r8.u64;
	// subf r19,r4,r20
	ctx.r19.u64 = ctx.r20.u64 - ctx.r4.u64;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + ctx.r11.u64;
	// add r19,r19,r26
	ctx.r19.u64 = ctx.r19.u64 + ctx.r26.u64;
	// rlwinm r20,r3,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r18,r9,r17
	ctx.r18.u64 = ctx.r17.u64 - ctx.r9.u64;
	// stw r20,-304(r1)
	REX_STORE_U32(ctx.r1.u32 + -304, ctx.r20.u32);
	// add r19,r19,r7
	ctx.r19.u64 = ctx.r19.u64 + ctx.r7.u64;
	// subf r20,r4,r8
	ctx.r20.u64 = ctx.r8.u64 - ctx.r4.u64;
	// subf r17,r10,r18
	ctx.r17.u64 = ctx.r18.u64 - ctx.r10.u64;
	// stw r19,-284(r1)
	REX_STORE_U32(ctx.r1.u32 + -284, ctx.r19.u32);
	// subf r19,r31,r20
	ctx.r19.u64 = ctx.r20.u64 - ctx.r31.u64;
	// add r18,r17,r30
	ctx.r18.u64 = ctx.r17.u64 + ctx.r30.u64;
	// lwz r17,-364(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// add r19,r19,r10
	ctx.r19.u64 = ctx.r19.u64 + ctx.r10.u64;
	// rlwinm r20,r15,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 1) & 0xFFFFFFFE;
	// add r18,r18,r5
	ctx.r18.u64 = ctx.r18.u64 + ctx.r5.u64;
	// stw r19,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r19.u32);
	// subf r15,r21,r20
	ctx.r15.u64 = ctx.r20.u64 - ctx.r21.u64;
	// add r20,r18,r29
	ctx.r20.u64 = ctx.r18.u64 + ctx.r29.u64;
	// mulli r18,r14,11
	ctx.r18.s64 = static_cast<int64_t>(ctx.r14.u64 * static_cast<uint64_t>(11));
	// stw r18,-308(r1)
	REX_STORE_U32(ctx.r1.u32 + -308, ctx.r18.u32);
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// add r19,r15,r27
	ctx.r19.u64 = ctx.r15.u64 + ctx.r27.u64;
	// lwz r18,-304(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + -304);
	// rotlwi r16,r7,1
	ctx.r16.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// stw r20,-256(r1)
	REX_STORE_U32(ctx.r1.u32 + -256, ctx.r20.u32);
	// rlwinm r19,r19,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r3,r18
	ctx.r3.u64 = ctx.r3.u64 + ctx.r18.u64;
	// lwz r14,-284(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -284);
	// stw r3,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r3.u32);
	// subf r20,r8,r31
	ctx.r20.u64 = ctx.r31.u64 - ctx.r8.u64;
	// stw r19,-296(r1)
	REX_STORE_U32(ctx.r1.u32 + -296, ctx.r19.u32);
	// rlwinm r19,r14,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r17,-304(r1)
	REX_STORE_U32(ctx.r1.u32 + -304, ctx.r17.u32);
	// rlwinm r17,r20,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// add r18,r16,r10
	ctx.r18.u64 = ctx.r16.u64 + ctx.r10.u64;
	// lwz r3,-364(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// add r20,r20,r17
	ctx.r20.u64 = ctx.r20.u64 + ctx.r17.u64;
	// rotlwi r17,r30,2
	ctx.r17.u64 = __builtin_rotateleft32(ctx.r30.u32, 2);
	// mr r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	// rlwinm r14,r3,3,0,28
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r29,r23
	ctx.r3.u64 = ctx.r23.u64 - ctx.r29.u64;
	// lwz r23,-308(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -308);
	// add r20,r19,r20
	ctx.r20.u64 = ctx.r19.u64 + ctx.r20.u64;
	// add r19,r30,r17
	ctx.r19.u64 = ctx.r30.u64 + ctx.r17.u64;
	// lwz r17,-288(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -288);
	// rotlwi r15,r9,3
	ctx.r15.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// subf r20,r19,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r19.u64;
	// subf r19,r16,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r16.u64;
	// lwz r14,-304(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -304);
	// stw r23,-308(r1)
	REX_STORE_U32(ctx.r1.u32 + -308, ctx.r23.u32);
	// subf r23,r9,r15
	ctx.r23.u64 = ctx.r15.u64 - ctx.r9.u64;
	// subf r16,r11,r7
	ctx.r16.u64 = ctx.r7.u64 - ctx.r11.u64;
	// lwz r15,-308(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -308);
	// add r23,r20,r23
	ctx.r23.u64 = ctx.r20.u64 + ctx.r23.u64;
	// lwz r20,-296(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -296);
	// add r15,r14,r15
	ctx.r15.u64 = ctx.r14.u64 + ctx.r15.u64;
	// stw r23,-296(r1)
	REX_STORE_U32(ctx.r1.u32 + -296, ctx.r23.u32);
	// mulli r23,r16,11
	ctx.r23.s64 = static_cast<int64_t>(ctx.r16.u64 * static_cast<uint64_t>(11));
	// lwz r14,-256(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// lwz r16,-368(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// rlwinm r18,r18,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// add r20,r20,r19
	ctx.r20.u64 = ctx.r20.u64 + ctx.r19.u64;
	// subf r18,r17,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r17.u64;
	// add r16,r14,r16
	ctx.r16.u64 = ctx.r14.u64 + ctx.r16.u64;
	// srawi r15,r15,1
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x1) != 0);
	ctx.r15.s64 = ctx.r15.s32 >> 1;
	// rlwinm r19,r3,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r14,r4,r18
	ctx.r14.u64 = ctx.r18.u64 - ctx.r4.u64;
	// lwz r18,-296(r1)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r1.u32 + -296);
	// subf r16,r26,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r26.u64;
	// add r3,r3,r19
	ctx.r3.u64 = ctx.r3.u64 + ctx.r19.u64;
	// add r23,r20,r23
	ctx.r23.u64 = ctx.r20.u64 + ctx.r23.u64;
	// srawi r18,r18,1
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x1) != 0);
	ctx.r18.s64 = ctx.r18.s32 >> 1;
	// subf r20,r27,r16
	ctx.r20.u64 = ctx.r16.u64 - ctx.r27.u64;
	// srawi r16,r14,1
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x1) != 0);
	ctx.r16.s64 = ctx.r14.s32 >> 1;
	// stw r18,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r18.u32);
	// add r14,r23,r3
	ctx.r14.u64 = ctx.r23.u64 + ctx.r3.u64;
	// lwz r3,-368(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// mullw r19,r3,r28
	ctx.r19.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r28.s32);
	// lwz r3,-300(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -300);
	// mullw r18,r15,r24
	ctx.r18.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r24.s32);
	// lwz r15,-344(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// stw r3,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r3.u32);
	// add r18,r15,r18
	ctx.r18.u64 = ctx.r15.u64 + ctx.r18.u64;
	// add r3,r20,r21
	ctx.r3.u64 = ctx.r20.u64 + ctx.r21.u64;
	// subf r20,r11,r9
	ctx.r20.u64 = ctx.r9.u64 - ctx.r11.u64;
	// add r21,r18,r19
	ctx.r21.u64 = ctx.r18.u64 + ctx.r19.u64;
	// rlwinm r23,r16,8,0,23
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 8) & 0xFFFFFF00;
	// add r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 + ctx.r6.u64;
	// srawi r19,r14,1
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x1) != 0);
	ctx.r19.s64 = ctx.r14.s32 >> 1;
	// subf r20,r6,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r6.u64;
	// add r23,r21,r23
	ctx.r23.u64 = ctx.r21.u64 + ctx.r23.u64;
	// mullw r3,r3,r24
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r24.s32);
	// mullw r21,r19,r25
	ctx.r21.s64 = int64_t(ctx.r19.s32) * int64_t(ctx.r25.s32);
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// add r18,r21,r3
	ctx.r18.u64 = ctx.r21.u64 + ctx.r3.u64;
	// subf r3,r5,r20
	ctx.r3.u64 = ctx.r20.u64 - ctx.r5.u64;
	// subf r21,r9,r30
	ctx.r21.u64 = ctx.r30.u64 - ctx.r9.u64;
	// subf r20,r10,r29
	ctx.r20.u64 = ctx.r29.u64 - ctx.r10.u64;
	// subf r30,r7,r31
	ctx.r30.u64 = ctx.r31.u64 - ctx.r7.u64;
	// add r3,r3,r8
	ctx.r3.u64 = ctx.r3.u64 + ctx.r8.u64;
	// rlwinm r19,r21,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r21,r30,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r16,r3,r27
	ctx.r16.u64 = ctx.r3.u64 + ctx.r27.u64;
	// subf r15,r31,r20
	ctx.r15.u64 = ctx.r20.u64 - ctx.r31.u64;
	// subf r14,r26,r19
	ctx.r14.u64 = ctx.r19.u64 - ctx.r26.u64;
	// add r26,r30,r21
	ctx.r26.u64 = ctx.r30.u64 + ctx.r21.u64;
	// rotlwi r20,r8,1
	ctx.r20.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// rotlwi r21,r29,2
	ctx.r21.u64 = __builtin_rotateleft32(ctx.r29.u32, 2);
	// subf r3,r8,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r8.u64;
	// rlwinm r19,r16,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r16,r31,r14
	ctx.r16.u64 = ctx.r14.u64 - ctx.r31.u64;
	// add r20,r20,r9
	ctx.r20.u64 = ctx.r20.u64 + ctx.r9.u64;
	// subf r15,r8,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r8.u64;
	// rlwinm r31,r3,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r29,r29,r21
	ctx.r29.u64 = ctx.r29.u64 + ctx.r21.u64;
	// add r26,r19,r26
	ctx.r26.u64 = ctx.r19.u64 + ctx.r26.u64;
	// subf r30,r7,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r7.u64;
	// rotlwi r19,r10,3
	ctx.r19.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// subf r15,r9,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r9.u64;
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r16,r7,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r7.u64;
	// add r14,r3,r31
	ctx.r14.u64 = ctx.r3.u64 + ctx.r31.u64;
	// subf r26,r29,r26
	ctx.r26.u64 = ctx.r26.u64 - ctx.r29.u64;
	// rlwinm r21,r30,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r29,r10,r19
	ctx.r29.u64 = ctx.r19.u64 - ctx.r10.u64;
	// subf r31,r27,r15
	ctx.r31.u64 = ctx.r15.u64 - ctx.r27.u64;
	// subf r20,r17,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r17.u64;
	// subf r3,r10,r16
	ctx.r3.u64 = ctx.r16.u64 - ctx.r10.u64;
	// subf r27,r9,r14
	ctx.r27.u64 = ctx.r14.u64 - ctx.r9.u64;
	// add r29,r26,r29
	ctx.r29.u64 = ctx.r26.u64 + ctx.r29.u64;
	// add r30,r30,r21
	ctx.r30.u64 = ctx.r30.u64 + ctx.r21.u64;
	// add r3,r3,r4
	ctx.r3.u64 = ctx.r3.u64 + ctx.r4.u64;
	// subf r26,r5,r20
	ctx.r26.u64 = ctx.r20.u64 - ctx.r5.u64;
	// add r27,r27,r5
	ctx.r27.u64 = ctx.r27.u64 + ctx.r5.u64;
	// subf r30,r10,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r10.u64;
	// srawi r29,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 1;
	// add r3,r3,r8
	ctx.r3.u64 = ctx.r3.u64 + ctx.r8.u64;
	// add r31,r31,r7
	ctx.r31.u64 = ctx.r31.u64 + ctx.r7.u64;
	// srawi r26,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 1;
	// srawi r27,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 1;
	// add r30,r30,r4
	ctx.r30.u64 = ctx.r30.u64 + ctx.r4.u64;
	// add r5,r31,r5
	ctx.r5.u64 = ctx.r31.u64 + ctx.r5.u64;
	// add r4,r3,r11
	ctx.r4.u64 = ctx.r3.u64 + ctx.r11.u64;
	// mullw r31,r26,r25
	ctx.r31.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r25.s32);
	// mullw r3,r27,r24
	ctx.r3.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r24.s32);
	// subf r8,r9,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r9.u64;
	// subf r27,r9,r11
	ctx.r27.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r16,-344(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// add r9,r31,r3
	ctx.r9.u64 = ctx.r31.u64 + ctx.r3.u64;
	// lwz r31,-336(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + -336);
	// add r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 + ctx.r11.u64;
	// srawi r3,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r30.s32 >> 1;
	// srawi r26,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r8.s32 >> 1;
	// add r30,r5,r6
	ctx.r30.u64 = ctx.r5.u64 + ctx.r6.u64;
	// mullw r8,r3,r31
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r31.s32);
	// subf r5,r10,r27
	ctx.r5.u64 = ctx.r27.u64 - ctx.r10.u64;
	// subf r27,r10,r7
	ctx.r27.u64 = ctx.r7.u64 - ctx.r10.u64;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r4,r4,r6
	ctx.r4.u64 = ctx.r4.u64 + ctx.r6.u64;
	// mullw r9,r26,r28
	ctx.r9.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	// mullw r7,r4,r28
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r28.s32);
	// add r8,r5,r6
	ctx.r8.u64 = ctx.r5.u64 + ctx.r6.u64;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,-228(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// mullw r4,r30,r24
	ctx.r4.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r24.s32);
	// mullw r3,r29,r25
	ctx.r3.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r25.s32);
	// srawi r30,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r30.s64 = ctx.r27.s32 >> 1;
	// add r5,r3,r4
	ctx.r5.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mullw r6,r8,r28
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r28.s32);
	// add r7,r18,r7
	ctx.r7.u64 = ctx.r18.u64 + ctx.r7.u64;
	// mullw r8,r30,r10
	ctx.r8.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r10.s32);
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// mullw r23,r23,r16
	ctx.r23.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r16.s32);
	// mullw r7,r7,r31
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r31.s32);
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r10,r6,r10
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// add r8,r23,r7
	ctx.r8.u64 = ctx.r23.u64 + ctx.r7.u64;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r8,r10
	ctx.r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r10,r5,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 16;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x82649dc8
	if (!ctx.cr6.gt) goto loc_82649DC8;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x82649dd4
	goto loc_82649DD4;
loc_82649DC8:
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
loc_82649DD4:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,-352(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -352);
	// lwz r9,-312(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -312);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r8,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r8.u32);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// beq cr6,0x8264a7e0
	if (ctx.cr6.eq) goto loc_8264A7E0;
	// fmul f13,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f0.f64 * ctx.f10.f64;
	// lwz r11,-236(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// lwz r8,-264(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
	// addi r9,r22,1
	ctx.r9.s64 = ctx.r22.s64 + 1;
	// mullw r10,r11,r22
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r22.s32);
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-360(r1)
	REX_STORE_U64(ctx.r1.u32 + -360, ctx.f12.u64);
	// lwz r11,-356(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -356);
	// rlwinm r7,r11,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r6,-184(r1)
	REX_STORE_U64(ctx.r1.u32 + -184, ctx.r6.u64);
	// rlwinm r23,r22,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r11,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r11.u32);
	// addi r4,r22,-1
	ctx.r4.s64 = ctx.r22.s64 + -1;
	// subf r24,r22,r10
	ctx.r24.u64 = ctx.r10.u64 - ctx.r22.u64;
	// addi r3,r23,-1
	ctx.r3.s64 = ctx.r23.s64 + -1;
	// addi r30,r23,1
	ctx.r30.s64 = ctx.r23.s64 + 1;
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r29,r22,2
	ctx.r29.s64 = ctx.r22.s64 + 2;
	// lbzx r26,r9,r10
	ctx.r26.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// addi r19,r23,2
	ctx.r19.s64 = ctx.r23.s64 + 2;
	// lbz r5,-1(r24)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r24.u32 + -1);
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lbz r8,0(r24)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r24.u32 + 0);
	// rotlwi r6,r11,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lbz r9,-1(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -1);
	// add r31,r26,r5
	ctx.r31.u64 = ctx.r26.u64 + ctx.r5.u64;
	// lbzx r27,r4,r10
	ctx.r27.u64 = REX_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// add r4,r11,r7
	ctx.r4.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r21,r9,r8
	ctx.r21.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbzx r25,r3,r10
	ctx.r25.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// lbz r28,1(r24)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r24.u32 + 1);
	// add r7,r6,r27
	ctx.r7.u64 = ctx.r6.u64 + ctx.r27.u64;
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r31,r23,r10
	ctx.r31.u64 = REX_LOAD_U8(ctx.r23.u32 + ctx.r10.u32);
	// rlwinm r6,r21,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r20,r30,r10
	ctx.r20.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r10.u32);
	// add r18,r7,r28
	ctx.r18.u64 = ctx.r7.u64 + ctx.r28.u64;
	// lbz r24,2(r24)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r24.u32 + 2);
	// subf r3,r25,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r25.u64;
	// lbz r30,2(r10)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// subf r7,r6,r31
	ctx.r7.u64 = ctx.r31.u64 - ctx.r6.u64;
	// stw r4,-288(r1)
	REX_STORE_U32(ctx.r1.u32 + -288, ctx.r4.u32);
	// rlwinm r18,r18,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r21,r29,r10
	ctx.r21.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r10.u32);
	// lfd f5,-184(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + -184);
	// subf r3,r24,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r24.u64;
	// fcfid f2,f5
	ctx.f2.f64 = double(ctx.f5.s64);
	// add r4,r7,r30
	ctx.r4.u64 = ctx.r7.u64 + ctx.r30.u64;
	// subf r7,r20,r18
	ctx.r7.u64 = ctx.r18.u64 - ctx.r20.u64;
	// lbzx r19,r19,r10
	ctx.r19.u64 = REX_LOAD_U8(ctx.r19.u32 + ctx.r10.u32);
	// rlwinm r29,r3,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r6,r10,r22
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r22.u32);
	// rlwinm r18,r4,3,0,28
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r10,1(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// subf r3,r21,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r21.u64;
	// add r17,r29,r19
	ctx.r17.u64 = ctx.r29.u64 + ctx.r19.u64;
	// subf r29,r4,r18
	ctx.r29.u64 = ctx.r18.u64 - ctx.r4.u64;
	// rlwinm r4,r3,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r17,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r3,r4
	ctx.r3.u64 = ctx.r3.u64 + ctx.r4.u64;
	// fmsub f13,f0,f9,f2
	ctx.f13.f64 = std::fma(ctx.f0.f64, ctx.f9.f64, -ctx.f2.f64);
	// subf r7,r28,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r28.u64;
	// add r29,r29,r18
	ctx.r29.u64 = ctx.r29.u64 + ctx.r18.u64;
	// add r4,r6,r10
	ctx.r4.u64 = ctx.r6.u64 + ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r29,r3
	ctx.r3.u64 = ctx.r29.u64 + ctx.r3.u64;
	// mulli r4,r4,13
	ctx.r4.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(13));
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-344(r1)
	REX_STORE_U64(ctx.r1.u32 + -344, ctx.f12.u64);
	// subf r18,r31,r7
	ctx.r18.u64 = ctx.r7.u64 - ctx.r31.u64;
	// lwz r7,-340(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -340);
	// subf r3,r4,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r4.u64;
	// mullw r4,r7,r7
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r7.s32);
	// srawi r4,r4,8
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 8;
	// mullw r29,r4,r7
	ctx.r29.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32);
	// srawi r29,r29,8
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xFF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 8;
	// srawi r14,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r14.s64 = ctx.r3.s32 >> 1;
	// subf r3,r27,r21
	ctx.r3.u64 = ctx.r21.u64 - ctx.r27.u64;
	// stw r3,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r3.u32);
	// subf r3,r5,r18
	ctx.r3.u64 = ctx.r18.u64 - ctx.r5.u64;
	// subf r16,r31,r10
	ctx.r16.u64 = ctx.r10.u64 - ctx.r31.u64;
	// lwz r17,-288(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -288);
	// add r3,r3,r20
	ctx.r3.u64 = ctx.r3.u64 + ctx.r20.u64;
	// std r23,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.r23.u64);
	// subf r18,r26,r16
	ctx.r18.u64 = ctx.r16.u64 - ctx.r26.u64;
	// add r3,r3,r24
	ctx.r3.u64 = ctx.r3.u64 + ctx.r24.u64;
	// stw r18,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r18.u32);
	// subf r15,r26,r6
	ctx.r15.u64 = ctx.r6.u64 - ctx.r26.u64;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r17,-312(r1)
	REX_STORE_U32(ctx.r1.u32 + -312, ctx.r17.u32);
	// subf r16,r11,r8
	ctx.r16.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r18,r27,r9
	ctx.r18.u64 = ctx.r9.u64 - ctx.r27.u64;
	// stw r3,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r3.u32);
	// subf r3,r30,r15
	ctx.r3.u64 = ctx.r15.u64 - ctx.r30.u64;
	// lwz r15,-344(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// subf r16,r5,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r5.u64;
	// rlwinm r18,r18,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r15,r19,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r19.u64;
	// rlwinm r16,r16,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r18,r30,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r30.u64;
	// add r15,r15,r25
	ctx.r15.u64 = ctx.r15.u64 + ctx.r25.u64;
	// subf r16,r31,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r31.u64;
	// subf r17,r5,r18
	ctx.r17.u64 = ctx.r18.u64 - ctx.r5.u64;
	// stw r15,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r15.u32);
	// add r15,r16,r25
	ctx.r15.u64 = ctx.r16.u64 + ctx.r25.u64;
	// lwz r23,-344(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// add r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 + ctx.r9.u64;
	// add r16,r17,r25
	ctx.r16.u64 = ctx.r17.u64 + ctx.r25.u64;
	// lwz r17,-364(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// rlwinm r18,r3,3,0,28
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r16,r16,r21
	ctx.r16.u64 = ctx.r16.u64 + ctx.r21.u64;
	// subf r3,r3,r18
	ctx.r3.u64 = ctx.r18.u64 - ctx.r3.u64;
	// mr r18,r17
	ctx.r18.u64 = ctx.r17.u64;
	// stw r17,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r17.u32);
	// rlwinm r17,r23,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r17,r3
	ctx.r3.u64 = ctx.r17.u64 + ctx.r3.u64;
	// lwz r17,-344(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// stw r18,-296(r1)
	REX_STORE_U32(ctx.r1.u32 + -296, ctx.r18.u32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r18,r10,r26
	ctx.r18.u64 = ctx.r26.u64 - ctx.r10.u64;
	// stw r17,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r17.u32);
	// lwz r23,-368(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// rlwinm r17,r18,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r3,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r3.u32);
	// add r3,r15,r6
	ctx.r3.u64 = ctx.r15.u64 + ctx.r6.u64;
	// lwz r15,-344(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// add r18,r18,r17
	ctx.r18.u64 = ctx.r18.u64 + ctx.r17.u64;
	// stw r15,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r15.u32);
	// rlwinm r17,r16,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r16,-368(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r18,-256(r1)
	REX_STORE_U32(ctx.r1.u32 + -256, ctx.r18.u32);
	// subf r15,r11,r10
	ctx.r15.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r3,-308(r1)
	REX_STORE_U32(ctx.r1.u32 + -308, ctx.r3.u32);
	// add r3,r23,r8
	ctx.r3.u64 = ctx.r23.u64 + ctx.r8.u64;
	// mulli r18,r15,11
	ctx.r18.s64 = static_cast<int64_t>(ctx.r15.u64 * static_cast<uint64_t>(11));
	// stw r18,-284(r1)
	REX_STORE_U32(ctx.r1.u32 + -284, ctx.r18.u32);
	// stw r3,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r3.u32);
	// lwz r15,-344(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// subf r18,r19,r17
	ctx.r18.u64 = ctx.r17.u64 - ctx.r19.u64;
	// rotlwi r3,r9,3
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// stw r18,-304(r1)
	REX_STORE_U32(ctx.r1.u32 + -304, ctx.r18.u32);
	// rotlwi r18,r6,1
	ctx.r18.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// rotlwi r17,r27,2
	ctx.r17.u64 = __builtin_rotateleft32(ctx.r27.u32, 2);
	// add r23,r18,r8
	ctx.r23.u64 = ctx.r18.u64 + ctx.r8.u64;
	// subf r18,r9,r3
	ctx.r18.u64 = ctx.r3.u64 - ctx.r9.u64;
	// lwz r3,-296(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -296);
	// std r22,-296(r1)
	REX_STORE_U64(ctx.r1.u32 + -296, ctx.r22.u64);
	// add r17,r27,r17
	ctx.r17.u64 = ctx.r27.u64 + ctx.r17.u64;
	// add r3,r3,r15
	ctx.r3.u64 = ctx.r3.u64 + ctx.r15.u64;
	// mullw r15,r14,r4
	ctx.r15.s64 = int64_t(ctx.r14.s32) * int64_t(ctx.r4.s32);
	// lwz r14,-256(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// lwz r22,-308(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -308);
	// stw r15,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r15.u32);
	// lwz r15,-284(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -284);
	// add r3,r16,r3
	ctx.r3.u64 = ctx.r16.u64 + ctx.r3.u64;
	// add r16,r22,r14
	ctx.r16.u64 = ctx.r22.u64 + ctx.r14.u64;
	// lwz r14,-364(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// add r15,r3,r15
	ctx.r15.u64 = ctx.r3.u64 + ctx.r15.u64;
	// subf r3,r17,r16
	ctx.r3.u64 = ctx.r16.u64 - ctx.r17.u64;
	// lwz r17,-304(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -304);
	// rlwinm r16,r23,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r22,-312(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -312);
	// add r3,r3,r18
	ctx.r3.u64 = ctx.r3.u64 + ctx.r18.u64;
	// stw r3,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r3.u32);
	// add r17,r17,r24
	ctx.r17.u64 = ctx.r17.u64 + ctx.r24.u64;
	// mr r23,r14
	ctx.r23.u64 = ctx.r14.u64;
	// rlwinm r14,r14,3,0,28
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r3,r17,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r18,r23,r14
	ctx.r18.u64 = ctx.r14.u64 - ctx.r23.u64;
	// lwz r14,-344(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// subf r17,r11,r6
	ctx.r17.u64 = ctx.r6.u64 - ctx.r11.u64;
	// lwz r23,-280(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -280);
	// add r18,r3,r18
	ctx.r18.u64 = ctx.r3.u64 + ctx.r18.u64;
	// mulli r17,r17,11
	ctx.r17.s64 = static_cast<int64_t>(ctx.r17.u64 * static_cast<uint64_t>(11));
	// stw r17,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r17.u32);
	// subf r3,r28,r20
	ctx.r3.u64 = ctx.r20.u64 - ctx.r28.u64;
	// subf r16,r22,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r22.u64;
	// rlwinm r17,r3,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r15,r15,1
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x1) != 0);
	ctx.r15.s64 = ctx.r15.s32 >> 1;
	// lwz r22,-368(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// subf r16,r31,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r31.u64;
	// stw r17,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r17.u32);
	// mullw r17,r15,r29
	ctx.r17.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r29.s32);
	// srawi r22,r22,1
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0x1) != 0);
	ctx.r22.s64 = ctx.r22.s32 >> 1;
	// add r17,r14,r17
	ctx.r17.u64 = ctx.r14.u64 + ctx.r17.u64;
	// subf r15,r20,r31
	ctx.r15.u64 = ctx.r31.u64 - ctx.r20.u64;
	// lwz r20,-344(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// srawi r14,r16,1
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x1) != 0);
	ctx.r14.s64 = ctx.r16.s32 >> 1;
	// mullw r16,r22,r7
	ctx.r16.s64 = int64_t(ctx.r22.s32) * int64_t(ctx.r7.s32);
	// lwz r22,-368(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// add r20,r18,r20
	ctx.r20.u64 = ctx.r18.u64 + ctx.r20.u64;
	// subf r15,r21,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r21.u64;
	// add r18,r3,r22
	ctx.r18.u64 = ctx.r3.u64 + ctx.r22.u64;
	// add r3,r17,r16
	ctx.r3.u64 = ctx.r17.u64 + ctx.r16.u64;
	// rlwinm r21,r14,8,0,23
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 8) & 0xFFFFFF00;
	// subf r17,r9,r15
	ctx.r17.u64 = ctx.r15.u64 - ctx.r9.u64;
	// add r21,r3,r21
	ctx.r21.u64 = ctx.r3.u64 + ctx.r21.u64;
	// subf r3,r8,r17
	ctx.r3.u64 = ctx.r17.u64 - ctx.r8.u64;
	// add r18,r20,r18
	ctx.r18.u64 = ctx.r20.u64 + ctx.r18.u64;
	// add r20,r3,r27
	ctx.r20.u64 = ctx.r3.u64 + ctx.r27.u64;
	// subf r3,r6,r26
	ctx.r3.u64 = ctx.r26.u64 - ctx.r6.u64;
	// subf r16,r11,r9
	ctx.r16.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subf r17,r10,r3
	ctx.r17.u64 = ctx.r3.u64 - ctx.r10.u64;
	// subf r15,r9,r27
	ctx.r15.u64 = ctx.r27.u64 - ctx.r9.u64;
	// subf r16,r5,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r5.u64;
	// add r27,r17,r11
	ctx.r27.u64 = ctx.r17.u64 + ctx.r11.u64;
	// add r20,r20,r30
	ctx.r20.u64 = ctx.r20.u64 + ctx.r30.u64;
	// subf r14,r8,r28
	ctx.r14.u64 = ctx.r28.u64 - ctx.r8.u64;
	// rlwinm r16,r16,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r17,r27,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// add r20,r20,r28
	ctx.r20.u64 = ctx.r20.u64 + ctx.r28.u64;
	// rlwinm r15,r15,1,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r14,r14,1,0,30
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r16,r30,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r30.u64;
	// add r17,r27,r17
	ctx.r17.u64 = ctx.r27.u64 + ctx.r17.u64;
	// subf r14,r26,r14
	ctx.r14.u64 = ctx.r14.u64 - ctx.r26.u64;
	// subf r15,r25,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r25.u64;
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// add r27,r16,r10
	ctx.r27.u64 = ctx.r16.u64 + ctx.r10.u64;
	// add r20,r20,r17
	ctx.r20.u64 = ctx.r20.u64 + ctx.r17.u64;
	// subf r15,r26,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r26.u64;
	// subf r16,r10,r14
	ctx.r16.u64 = ctx.r14.u64 - ctx.r10.u64;
	// add r27,r27,r24
	ctx.r27.u64 = ctx.r27.u64 + ctx.r24.u64;
	// rlwinm r26,r3,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r14,r25,r20
	ctx.r14.u64 = ctx.r20.u64 - ctx.r25.u64;
	// subf r15,r6,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r6.u64;
	// subf r16,r9,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r9.u64;
	// add r17,r3,r26
	ctx.r17.u64 = ctx.r3.u64 + ctx.r26.u64;
	// rlwinm r20,r27,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r3,r24,r16
	ctx.r3.u64 = ctx.r16.u64 - ctx.r24.u64;
	// subf r26,r24,r14
	ctx.r26.u64 = ctx.r14.u64 - ctx.r24.u64;
	// rotlwi r25,r28,2
	ctx.r25.u64 = __builtin_rotateleft32(ctx.r28.u32, 2);
	// subf r27,r8,r15
	ctx.r27.u64 = ctx.r15.u64 - ctx.r8.u64;
	// add r24,r20,r17
	ctx.r24.u64 = ctx.r20.u64 + ctx.r17.u64;
	// add r28,r28,r25
	ctx.r28.u64 = ctx.r28.u64 + ctx.r25.u64;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// rotlwi r17,r8,3
	ctx.r17.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// add r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 + ctx.r6.u64;
	// add r20,r26,r19
	ctx.r20.u64 = ctx.r26.u64 + ctx.r19.u64;
	// subf r26,r28,r24
	ctx.r26.u64 = ctx.r24.u64 - ctx.r28.u64;
	// lwz r16,-288(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -288);
	// add r25,r27,r10
	ctx.r25.u64 = ctx.r27.u64 + ctx.r10.u64;
	// ld r22,-296(r1)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r1.u32 + -296);
	// subf r24,r8,r17
	ctx.r24.u64 = ctx.r17.u64 - ctx.r8.u64;
	// add r27,r3,r30
	ctx.r27.u64 = ctx.r3.u64 + ctx.r30.u64;
	// add r20,r20,r5
	ctx.r20.u64 = ctx.r20.u64 + ctx.r5.u64;
	// add r24,r26,r24
	ctx.r24.u64 = ctx.r26.u64 + ctx.r24.u64;
	// rotlwi r28,r10,1
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// srawi r3,r18,1
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r18.s32 >> 1;
	// add r26,r27,r11
	ctx.r26.u64 = ctx.r27.u64 + ctx.r11.u64;
	// subf r19,r9,r11
	ctx.r19.u64 = ctx.r11.u64 - ctx.r9.u64;
	// add r25,r25,r11
	ctx.r25.u64 = ctx.r25.u64 + ctx.r11.u64;
	// add r17,r28,r9
	ctx.r17.u64 = ctx.r28.u64 + ctx.r9.u64;
	// mullw r18,r3,r4
	ctx.r18.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// mullw r27,r20,r29
	ctx.r27.s64 = int64_t(ctx.r20.s32) * int64_t(ctx.r29.s32);
	// add r28,r26,r5
	ctx.r28.u64 = ctx.r26.u64 + ctx.r5.u64;
	// srawi r24,r24,1
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x1) != 0);
	ctx.r24.s64 = ctx.r24.s32 >> 1;
	// add r15,r25,r5
	ctx.r15.u64 = ctx.r25.u64 + ctx.r5.u64;
	// subf r20,r8,r19
	ctx.r20.u64 = ctx.r19.u64 - ctx.r8.u64;
	// add r25,r18,r27
	ctx.r25.u64 = ctx.r18.u64 + ctx.r27.u64;
	// mullw r26,r28,r29
	ctx.r26.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r29.s32);
	// subf r3,r6,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r6.u64;
	// mullw r27,r24,r4
	ctx.r27.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r4.s32);
	// add r5,r20,r5
	ctx.r5.u64 = ctx.r20.u64 + ctx.r5.u64;
	// add r27,r27,r26
	ctx.r27.u64 = ctx.r27.u64 + ctx.r26.u64;
	// rlwinm r28,r3,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r26,r5,r7
	ctx.r26.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// subf r5,r10,r11
	ctx.r5.u64 = ctx.r11.u64 - ctx.r10.u64;
	// mullw r24,r15,r7
	ctx.r24.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r7.s32);
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + ctx.r28.u64;
	// add r27,r27,r26
	ctx.r27.u64 = ctx.r27.u64 + ctx.r26.u64;
	// rlwinm r28,r17,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r26,r5,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r24,r25,r24
	ctx.r24.u64 = ctx.r25.u64 + ctx.r24.u64;
	// lwz r25,-272(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// subf r3,r8,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r8.u64;
	// subf r20,r16,r28
	ctx.r20.u64 = ctx.r28.u64 - ctx.r16.u64;
	// add r5,r5,r26
	ctx.r5.u64 = ctx.r5.u64 + ctx.r26.u64;
	// add r26,r3,r31
	ctx.r26.u64 = ctx.r3.u64 + ctx.r31.u64;
	// lwz r3,-220(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// mullw r28,r24,r25
	ctx.r28.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r25.s32);
	// mullw r21,r21,r23
	ctx.r21.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r23.s32);
	// ld r23,-328(r1)
	ctx.r23.u64 = REX_LOAD_U64(ctx.r1.u32 + -328);
	// subf r24,r30,r20
	ctx.r24.u64 = ctx.r20.u64 - ctx.r30.u64;
	// subf r5,r9,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r9.u64;
	// add r31,r21,r28
	ctx.r31.u64 = ctx.r21.u64 + ctx.r28.u64;
	// mullw r28,r27,r3
	ctx.r28.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r3.s32);
	// srawi r24,r24,1
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x1) != 0);
	ctx.r24.s64 = ctx.r24.s32 >> 1;
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// srawi r27,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r27.s64 = ctx.r26.s32 >> 1;
	// add r31,r31,r28
	ctx.r31.u64 = ctx.r31.u64 + ctx.r28.u64;
	// srawi r5,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 1;
	// mullw r28,r24,r4
	ctx.r28.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r4.s32);
	// mullw r27,r27,r25
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r25.s32);
	// subf r30,r9,r10
	ctx.r30.u64 = ctx.r10.u64 - ctx.r9.u64;
	// mullw r9,r5,r29
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r29.s32);
	// add r10,r28,r27
	ctx.r10.u64 = ctx.r28.u64 + ctx.r27.u64;
	// srawi r5,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r30.s32 >> 1;
	// subf r8,r8,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r8.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r5,r7
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r6,r3
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r3.s32);
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r5,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// add r3,r31,r11
	ctx.r3.u64 = ctx.r31.u64 + ctx.r11.u64;
	// srawi r11,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 16;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x8264a2ec
	if (!ctx.cr6.gt) goto loc_8264A2EC;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x8264a2f8
	goto loc_8264A2F8;
loc_8264A2EC:
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
loc_8264A2F8:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// lwz r11,-320(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -320);
	// lwz r10,-360(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// addi r6,r22,-1
	ctx.r6.s64 = ctx.r22.s64 + -1;
	// lwz r5,-268(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// addi r9,r22,1
	ctx.r9.s64 = ctx.r22.s64 + 1;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stb r8,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r8.u8);
	// subf r20,r22,r10
	ctx.r20.u64 = ctx.r10.u64 - ctx.r22.u64;
	// stw r3,-320(r1)
	REX_STORE_U32(ctx.r1.u32 + -320, ctx.r3.u32);
	// lbzx r26,r9,r10
	ctx.r26.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// lbzx r5,r10,r22
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r22.u32);
	// lbz r30,2(r10)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r9,-1(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + -1);
	// lbz r8,0(r20)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r20.u32 + 0);
	// lbz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// rotlwi r3,r11,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lbzx r27,r6,r10
	ctx.r27.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// addi r6,r23,1
	ctx.r6.s64 = ctx.r23.s64 + 1;
	// lbz r28,1(r20)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r20.u32 + 1);
	// add r24,r3,r27
	ctx.r24.u64 = ctx.r3.u64 + ctx.r27.u64;
	// lbz r31,-1(r20)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r20.u32 + -1);
	// subf r3,r26,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r26.u64;
	// add r18,r24,r28
	ctx.r18.u64 = ctx.r24.u64 + ctx.r28.u64;
	// lbz r24,2(r20)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r20.u32 + 2);
	// lbzx r21,r6,r10
	ctx.r21.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// addi r6,r23,-1
	ctx.r6.s64 = ctx.r23.s64 + -1;
	// subf r19,r30,r3
	ctx.r19.u64 = ctx.r3.u64 - ctx.r30.u64;
	// rlwinm r3,r18,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// add r19,r19,r9
	ctx.r19.u64 = ctx.r19.u64 + ctx.r9.u64;
	// add r16,r26,r31
	ctx.r16.u64 = ctx.r26.u64 + ctx.r31.u64;
	// lbzx r25,r6,r10
	ctx.r25.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// addi r6,r23,2
	ctx.r6.s64 = ctx.r23.s64 + 2;
	// rlwinm r17,r19,3,0,28
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r18,r21,r3
	ctx.r18.u64 = ctx.r3.u64 - ctx.r21.u64;
	// rlwinm r16,r16,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r20,r6,r10
	ctx.r20.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// addi r6,r22,2
	ctx.r6.s64 = ctx.r22.s64 + 2;
	// lbzx r3,r6,r10
	ctx.r3.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// subf r6,r3,r18
	ctx.r6.u64 = ctx.r18.u64 - ctx.r3.u64;
	// stw r6,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r6.u32);
	// subf r6,r19,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r19.u64;
	// subf r18,r28,r8
	ctx.r18.u64 = ctx.r8.u64 - ctx.r28.u64;
	// lwz r19,-364(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// stw r6,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r6.u32);
	// rotlwi r6,r6,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// rlwinm r18,r18,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r6,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r6.u32);
	// add r17,r9,r8
	ctx.r17.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r6,1(r10)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// mr r14,r19
	ctx.r14.u64 = ctx.r19.u64;
	// lbzx r10,r23,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r23.u32 + ctx.r10.u32);
	// subf r23,r10,r18
	ctx.r23.u64 = ctx.r18.u64 - ctx.r10.u64;
	// subf r18,r31,r23
	ctx.r18.u64 = ctx.r23.u64 - ctx.r31.u64;
	// rlwinm r17,r17,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// add r18,r18,r21
	ctx.r18.u64 = ctx.r18.u64 + ctx.r21.u64;
	// subf r23,r17,r10
	ctx.r23.u64 = ctx.r10.u64 - ctx.r17.u64;
	// add r18,r18,r24
	ctx.r18.u64 = ctx.r18.u64 + ctx.r24.u64;
	// subf r17,r25,r16
	ctx.r17.u64 = ctx.r16.u64 - ctx.r25.u64;
	// rlwinm r18,r18,1,0,30
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r17,r24,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r24.u64;
	// subf r18,r20,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r20.u64;
	// add r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 + ctx.r30.u64;
	// rlwinm r17,r17,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// add r18,r18,r25
	ctx.r18.u64 = ctx.r18.u64 + ctx.r25.u64;
	// rlwinm r16,r23,3,0,28
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r18,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r18.u32);
	// add r17,r17,r20
	ctx.r17.u64 = ctx.r17.u64 + ctx.r20.u64;
	// subf r18,r23,r16
	ctx.r18.u64 = ctx.r16.u64 - ctx.r23.u64;
	// rlwinm r16,r19,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r19,-360(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// subf r23,r27,r3
	ctx.r23.u64 = ctx.r3.u64 - ctx.r27.u64;
	// rlwinm r15,r17,1,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r17,r19,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r19,r23,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// add r16,r14,r16
	ctx.r16.u64 = ctx.r14.u64 + ctx.r16.u64;
	// stw r19,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r19.u32);
	// subf r14,r11,r8
	ctx.r14.u64 = ctx.r8.u64 - ctx.r11.u64;
	// add r19,r5,r6
	ctx.r19.u64 = ctx.r5.u64 + ctx.r6.u64;
	// stw r16,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r16.u32);
	// add r18,r18,r15
	ctx.r18.u64 = ctx.r18.u64 + ctx.r15.u64;
	// lwz r15,-344(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// stw r19,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r19.u32);
	// subf r16,r11,r6
	ctx.r16.u64 = ctx.r6.u64 - ctx.r11.u64;
	// add r19,r17,r15
	ctx.r19.u64 = ctx.r17.u64 + ctx.r15.u64;
	// lwz r17,-360(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// std r22,-256(r1)
	REX_STORE_U64(ctx.r1.u32 + -256, ctx.r22.u64);
	// add r23,r23,r17
	ctx.r23.u64 = ctx.r23.u64 + ctx.r17.u64;
	// lwz r22,-368(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// lwz r15,-344(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// mulli r15,r15,13
	ctx.r15.s64 = static_cast<int64_t>(ctx.r15.u64 * static_cast<uint64_t>(13));
	// add r23,r19,r23
	ctx.r23.u64 = ctx.r19.u64 + ctx.r23.u64;
	// std r6,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.r6.u64);
	// add r18,r18,r22
	ctx.r18.u64 = ctx.r18.u64 + ctx.r22.u64;
	// mulli r19,r16,11
	ctx.r19.s64 = static_cast<int64_t>(ctx.r16.u64 * static_cast<uint64_t>(11));
	// subf r18,r15,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r15.u64;
	// add r23,r23,r19
	ctx.r23.u64 = ctx.r23.u64 + ctx.r19.u64;
	// subf r19,r27,r9
	ctx.r19.u64 = ctx.r9.u64 - ctx.r27.u64;
	// srawi r18,r18,1
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x1) != 0);
	ctx.r18.s64 = ctx.r18.s32 >> 1;
	// srawi r17,r23,1
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x1) != 0);
	ctx.r17.s64 = ctx.r23.s32 >> 1;
	// rlwinm r16,r19,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r23,r18,r4
	ctx.r23.s64 = int64_t(ctx.r18.s32) * int64_t(ctx.r4.s32);
	// mullw r19,r17,r29
	ctx.r19.s64 = int64_t(ctx.r17.s32) * int64_t(ctx.r29.s32);
	// subf r17,r30,r16
	ctx.r17.u64 = ctx.r16.u64 - ctx.r30.u64;
	// add r19,r23,r19
	ctx.r19.u64 = ctx.r23.u64 + ctx.r19.u64;
	// subf r23,r31,r17
	ctx.r23.u64 = ctx.r17.u64 - ctx.r31.u64;
	// subf r18,r21,r10
	ctx.r18.u64 = ctx.r10.u64 - ctx.r21.u64;
	// stw r19,-296(r1)
	REX_STORE_U32(ctx.r1.u32 + -296, ctx.r19.u32);
	// add r17,r23,r25
	ctx.r17.u64 = ctx.r23.u64 + ctx.r25.u64;
	// subf r16,r3,r18
	ctx.r16.u64 = ctx.r18.u64 - ctx.r3.u64;
	// add r3,r17,r3
	ctx.r3.u64 = ctx.r17.u64 + ctx.r3.u64;
	// subf r23,r9,r16
	ctx.r23.u64 = ctx.r16.u64 - ctx.r9.u64;
	// subf r16,r5,r26
	ctx.r16.u64 = ctx.r26.u64 - ctx.r5.u64;
	// stw r3,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r3.u32);
	// rotlwi r18,r11,2
	ctx.r18.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// subf r3,r6,r16
	ctx.r3.u64 = ctx.r16.u64 - ctx.r6.u64;
	// add r19,r11,r18
	ctx.r19.u64 = ctx.r11.u64 + ctx.r18.u64;
	// subf r18,r8,r23
	ctx.r18.u64 = ctx.r23.u64 - ctx.r8.u64;
	// subf r23,r10,r6
	ctx.r23.u64 = ctx.r6.u64 - ctx.r10.u64;
	// stw r19,-288(r1)
	REX_STORE_U32(ctx.r1.u32 + -288, ctx.r19.u32);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + ctx.r11.u64;
	// add r17,r18,r27
	ctx.r17.u64 = ctx.r18.u64 + ctx.r27.u64;
	// subf r18,r26,r23
	ctx.r18.u64 = ctx.r23.u64 - ctx.r26.u64;
	// rlwinm r19,r3,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r23,r18,r8
	ctx.r23.u64 = ctx.r18.u64 + ctx.r8.u64;
	// stw r19,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r19.u32);
	// add r15,r17,r30
	ctx.r15.u64 = ctx.r17.u64 + ctx.r30.u64;
	// subf r19,r31,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r31.u64;
	// stw r23,-364(r1)
	REX_STORE_U32(ctx.r1.u32 + -364, ctx.r23.u32);
	// add r23,r15,r28
	ctx.r23.u64 = ctx.r15.u64 + ctx.r28.u64;
	// rlwinm r19,r19,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r19,r10,r19
	ctx.r19.u64 = ctx.r19.u64 - ctx.r10.u64;
	// stw r23,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r23.u32);
	// subf r23,r6,r26
	ctx.r23.u64 = ctx.r26.u64 - ctx.r6.u64;
	// add r19,r19,r25
	ctx.r19.u64 = ctx.r19.u64 + ctx.r25.u64;
	// rotlwi r18,r27,2
	ctx.r18.u64 = __builtin_rotateleft32(ctx.r27.u32, 2);
	// add r17,r19,r5
	ctx.r17.u64 = ctx.r19.u64 + ctx.r5.u64;
	// lwz r14,-360(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// rlwinm r19,r23,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r15,r14,1,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// add r16,r23,r19
	ctx.r16.u64 = ctx.r23.u64 + ctx.r19.u64;
	// rotlwi r19,r5,1
	ctx.r19.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// subf r23,r20,r15
	ctx.r23.u64 = ctx.r15.u64 - ctx.r20.u64;
	// add r14,r19,r8
	ctx.r14.u64 = ctx.r19.u64 + ctx.r8.u64;
	// add r15,r27,r18
	ctx.r15.u64 = ctx.r27.u64 + ctx.r18.u64;
	// rotlwi r18,r9,3
	ctx.r18.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// rlwinm r17,r17,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// add r23,r23,r24
	ctx.r23.u64 = ctx.r23.u64 + ctx.r24.u64;
	// lwz r19,-344(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// add r17,r17,r16
	ctx.r17.u64 = ctx.r17.u64 + ctx.r16.u64;
	// lwz r22,-364(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -364);
	// subf r27,r9,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r9.u64;
	// lwz r16,-288(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -288);
	// stw r19,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r19.u32);
	// subf r19,r9,r18
	ctx.r19.u64 = ctx.r18.u64 - ctx.r9.u64;
	// rotlwi r18,r22,0
	ctx.r18.u64 = __builtin_rotateleft32(ctx.r22.u32, 0);
	// lwz r6,-360(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// rlwinm r22,r22,3,0,28
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r18,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r18.u32);
	// add r18,r3,r6
	ctx.r18.u64 = ctx.r3.u64 + ctx.r6.u64;
	// stw r27,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r27.u32);
	// subf r3,r28,r21
	ctx.r3.u64 = ctx.r21.u64 - ctx.r28.u64;
	// rlwinm r27,r23,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r23,-360(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// subf r21,r15,r17
	ctx.r21.u64 = ctx.r17.u64 - ctx.r15.u64;
	// lwz r6,-368(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// rlwinm r17,r14,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r23,r23,r22
	ctx.r23.u64 = ctx.r22.u64 - ctx.r23.u64;
	// subf r15,r11,r5
	ctx.r15.u64 = ctx.r5.u64 - ctx.r11.u64;
	// add r19,r21,r19
	ctx.r19.u64 = ctx.r21.u64 + ctx.r19.u64;
	// add r18,r6,r18
	ctx.r18.u64 = ctx.r6.u64 + ctx.r18.u64;
	// lwz r6,-280(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -280);
	// add r23,r27,r23
	ctx.r23.u64 = ctx.r27.u64 + ctx.r23.u64;
	// mulli r21,r15,11
	ctx.r21.s64 = static_cast<int64_t>(ctx.r15.u64 * static_cast<uint64_t>(11));
	// lwz r15,-296(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -296);
	// stw r6,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r6.u32);
	// ld r6,-328(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + -328);
	// rlwinm r27,r3,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r18,r25,r18
	ctx.r18.u64 = ctx.r18.u64 - ctx.r25.u64;
	// subf r17,r16,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r16.u64;
	// lwz r14,-344(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// rlwinm r14,r14,1,0,30
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r14,r25,r14
	ctx.r14.u64 = ctx.r14.u64 - ctx.r25.u64;
	// add r25,r23,r21
	ctx.r25.u64 = ctx.r23.u64 + ctx.r21.u64;
	// add r23,r3,r27
	ctx.r23.u64 = ctx.r3.u64 + ctx.r27.u64;
	// subf r27,r10,r17
	ctx.r27.u64 = ctx.r17.u64 - ctx.r10.u64;
	// srawi r21,r19,1
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r19.s32 >> 1;
	// subf r3,r24,r18
	ctx.r3.u64 = ctx.r18.u64 - ctx.r24.u64;
	// srawi r18,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r18.s64 = ctx.r27.s32 >> 1;
	// mullw r27,r21,r7
	ctx.r27.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r7.s32);
	// subf r19,r26,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r26.u64;
	// add r23,r25,r23
	ctx.r23.u64 = ctx.r25.u64 + ctx.r23.u64;
	// add r3,r3,r20
	ctx.r3.u64 = ctx.r3.u64 + ctx.r20.u64;
	// add r27,r15,r27
	ctx.r27.u64 = ctx.r15.u64 + ctx.r27.u64;
	// rlwinm r25,r18,8,0,23
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 8) & 0xFFFFFF00;
	// subf r21,r11,r9
	ctx.r21.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subf r20,r5,r19
	ctx.r20.u64 = ctx.r19.u64 - ctx.r5.u64;
	// srawi r23,r23,1
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r23.s32 >> 1;
	// add r19,r3,r31
	ctx.r19.u64 = ctx.r3.u64 + ctx.r31.u64;
	// add r25,r27,r25
	ctx.r25.u64 = ctx.r27.u64 + ctx.r25.u64;
	// subf r21,r31,r21
	ctx.r21.u64 = ctx.r21.u64 - ctx.r31.u64;
	// subf r3,r8,r20
	ctx.r3.u64 = ctx.r20.u64 - ctx.r8.u64;
	// mullw r27,r23,r4
	ctx.r27.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r4.s32);
	// mullw r23,r19,r29
	ctx.r23.s64 = int64_t(ctx.r19.s32) * int64_t(ctx.r29.s32);
	// rlwinm r21,r21,1,0,30
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 + ctx.r10.u64;
	// add r23,r27,r23
	ctx.r23.u64 = ctx.r27.u64 + ctx.r23.u64;
	// subf r27,r30,r21
	ctx.r27.u64 = ctx.r21.u64 - ctx.r30.u64;
	// subf r20,r8,r28
	ctx.r20.u64 = ctx.r28.u64 - ctx.r8.u64;
	// add r21,r3,r6
	ctx.r21.u64 = ctx.r3.u64 + ctx.r6.u64;
	// subf r3,r5,r26
	ctx.r3.u64 = ctx.r26.u64 - ctx.r5.u64;
	// rlwinm r19,r20,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// add r27,r27,r6
	ctx.r27.u64 = ctx.r27.u64 + ctx.r6.u64;
	// rlwinm r20,r3,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r15,r27,r24
	ctx.r15.u64 = ctx.r27.u64 + ctx.r24.u64;
	// add r18,r3,r20
	ctx.r18.u64 = ctx.r3.u64 + ctx.r20.u64;
	// subf r26,r26,r19
	ctx.r26.u64 = ctx.r19.u64 - ctx.r26.u64;
	// rotlwi r20,r28,2
	ctx.r20.u64 = __builtin_rotateleft32(ctx.r28.u32, 2);
	// rlwinm r17,r6,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r19,r15,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r27,r5,r11
	ctx.r27.u64 = ctx.r11.u64 - ctx.r5.u64;
	// subf r3,r6,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r6.u64;
	// add r28,r28,r20
	ctx.r28.u64 = ctx.r28.u64 + ctx.r20.u64;
	// subf r15,r6,r26
	ctx.r15.u64 = ctx.r26.u64 - ctx.r6.u64;
	// add r17,r17,r9
	ctx.r17.u64 = ctx.r17.u64 + ctx.r9.u64;
	// add r20,r19,r18
	ctx.r20.u64 = ctx.r19.u64 + ctx.r18.u64;
	// rlwinm r26,r27,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r19,r3,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rotlwi r18,r8,3
	ctx.r18.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// rlwinm r17,r17,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r15,r9,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r9.u64;
	// add r27,r27,r26
	ctx.r27.u64 = ctx.r27.u64 + ctx.r26.u64;
	// subf r26,r28,r20
	ctx.r26.u64 = ctx.r20.u64 - ctx.r28.u64;
	// add r3,r3,r19
	ctx.r3.u64 = ctx.r3.u64 + ctx.r19.u64;
	// subf r28,r24,r15
	ctx.r28.u64 = ctx.r15.u64 - ctx.r24.u64;
	// subf r20,r8,r18
	ctx.r20.u64 = ctx.r18.u64 - ctx.r8.u64;
	// subf r19,r16,r17
	ctx.r19.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r27,r8,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r8.u64;
	// add r26,r26,r20
	ctx.r26.u64 = ctx.r26.u64 + ctx.r20.u64;
	// subf r24,r30,r19
	ctx.r24.u64 = ctx.r19.u64 - ctx.r30.u64;
	// add r28,r28,r5
	ctx.r28.u64 = ctx.r28.u64 + ctx.r5.u64;
	// subf r3,r9,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r9.u64;
	// lwz r15,-360(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// add r20,r27,r10
	ctx.r20.u64 = ctx.r27.u64 + ctx.r10.u64;
	// lwz r27,-272(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// add r10,r28,r30
	ctx.r10.u64 = ctx.r28.u64 + ctx.r30.u64;
	// ld r22,-256(r1)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r1.u32 + -256);
	// add r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 + ctx.r30.u64;
	// srawi r26,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 1;
	// srawi r30,r24,1
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x1) != 0);
	ctx.r30.s64 = ctx.r24.s32 >> 1;
	// add r28,r21,r11
	ctx.r28.u64 = ctx.r21.u64 + ctx.r11.u64;
	// srawi r24,r20,1
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x1) != 0);
	ctx.r24.s64 = ctx.r20.s32 >> 1;
	// srawi r21,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r3.s32 >> 1;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mullw r10,r30,r4
	ctx.r10.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r4.s32);
	// mullw r30,r24,r27
	ctx.r30.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r27.s32);
	// subf r6,r9,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r9.u64;
	// subf r20,r9,r11
	ctx.r20.u64 = ctx.r11.u64 - ctx.r9.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// mullw r9,r21,r29
	ctx.r9.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r29.s32);
	// srawi r6,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r6,r7
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// add r30,r3,r31
	ctx.r30.u64 = ctx.r3.u64 + ctx.r31.u64;
	// add r28,r28,r31
	ctx.r28.u64 = ctx.r28.u64 + ctx.r31.u64;
	// subf r24,r8,r5
	ctx.r24.u64 = ctx.r5.u64 - ctx.r8.u64;
	// subf r3,r8,r20
	ctx.r3.u64 = ctx.r20.u64 - ctx.r8.u64;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,-220(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -220);
	// mullw r8,r26,r4
	ctx.r8.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r4.s32);
	// mullw r5,r28,r7
	ctx.r5.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r7.s32);
	// mullw r6,r30,r29
	ctx.r6.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r29.s32);
	// srawi r4,r24,1
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r24.s32 >> 1;
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// add r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 + ctx.r6.u64;
	// add r31,r23,r5
	ctx.r31.u64 = ctx.r23.u64 + ctx.r5.u64;
	// mullw r8,r4,r10
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// mullw r5,r3,r7
	ctx.r5.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// mullw r25,r25,r15
	ctx.r25.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r15.s32);
	// mullw r7,r31,r27
	ctx.r7.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r27.s32);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// mullw r10,r6,r10
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// add r11,r25,r7
	ctx.r11.u64 = ctx.r25.u64 + ctx.r7.u64;
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r5,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r11,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 16;
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x8264a798
	if (!ctx.cr6.gt) goto loc_8264A798;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x8264a7a4
	goto loc_8264A7A4;
loc_8264A798:
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
loc_8264A7A4:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// lwz r11,-316(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -316);
	// lwz r10,-260(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -260);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// lwz r3,20(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r27,-264(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
	// li r25,128
	ctx.r25.s64 = 128;
	// lwz r8,-352(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -352);
	// li r24,16
	ctx.r24.s64 = 16;
	// lwz r29,-320(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -320);
	// lwz r26,-268(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// stb r9,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r9.u8);
	// stw r30,-316(r1)
	REX_STORE_U32(ctx.r1.u32 + -316, ctx.r30.u32);
	// b 0x8264a804
	goto loc_8264A804;
loc_8264A7E0:
	// lwz r3,20(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// li r24,16
	ctx.r24.s64 = 16;
	// lwz r10,-260(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -260);
	// li r25,128
	ctx.r25.s64 = 128;
	// lwz r26,-268(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// lwz r29,-320(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -320);
	// lwz r30,-316(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -316);
	// lwz r27,-264(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
loc_8264A800:
	// li r7,1
	ctx.r7.s64 = 1;
loc_8264A804:
	// lwz r9,-276(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -276);
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r7,-312(r1)
	REX_STORE_U32(ctx.r1.u32 + -312, ctx.r7.u32);
	// stw r9,-276(r1)
	REX_STORE_U32(ctx.r1.u32 + -276, ctx.r9.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264990c
	if (ctx.cr6.lt) goto loc_8264990C;
	// lwz r4,-248(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// b 0x8264ab3c
	goto loc_8264AB3C;
loc_8264A828:
	// lwz r9,80(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8264a918
	if (!ctx.cr6.lt) goto loc_8264A918;
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8264a8a8
	if (!ctx.cr6.lt) goto loc_8264A8A8;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lbzx r6,r11,r10
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r5,1(r5)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r5.u32 + 1);
	// mullw r4,r5,r28
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r28.s32);
	// lbz r31,1(r9)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// lbz r23,0(r9)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lwz r9,-228(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// subf r31,r5,r31
	ctx.r31.u64 = ctx.r31.u64 - ctx.r5.u64;
	// mullw r5,r23,r9
	ctx.r5.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r9.s32);
	// subf r31,r23,r31
	ctx.r31.u64 = ctx.r31.u64 - ctx.r23.u64;
	// add r31,r31,r6
	ctx.r31.u64 = ctx.r31.u64 + ctx.r6.u64;
	// mullw r31,r31,r28
	ctx.r31.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r28.s32);
	// mullw r31,r31,r9
	ctx.r31.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r9.s32);
	// srawi r31,r31,8
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xFF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 8;
	// subfic r28,r28,256
	ctx.xer.ca = ctx.r28.u32 <= 256;
	ctx.r28.u64 = static_cast<uint64_t>(256) - ctx.r28.u64;
	// subf r9,r9,r28
	ctx.r9.u64 = ctx.r28.u64 - ctx.r9.u64;
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r9,r31,r9
	ctx.r9.u64 = ctx.r31.u64 + ctx.r9.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// add r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 + ctx.r5.u64;
	// srawi r5,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 8;
	// stb r5,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r5.u8);
	// b 0x8264a8d0
	goto loc_8264A8D0;
loc_8264A8A8:
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r9,-228(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// lbzx r4,r11,r10
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// subfic r6,r9,256
	ctx.xer.ca = ctx.r9.u32 <= 256;
	ctx.r6.u64 = static_cast<uint64_t>(256) - ctx.r9.u64;
	// mullw r6,r4,r6
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// lbzx r5,r5,r10
	ctx.r5.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r10.u32);
	// mullw r9,r5,r9
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// add r4,r6,r9
	ctx.r4.u64 = ctx.r6.u64 + ctx.r9.u64;
	// rlwinm r9,r4,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// stb r9,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r9.u8);
loc_8264A8D0:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r8,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r8.u32);
	// beq cr6,0x8264a800
	if (ctx.cr6.eq) goto loc_8264A800;
	// lwz r9,-236(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mullw r9,r9,r22
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r22.s32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbzx r9,r11,r27
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// stb r9,1(r29)
	REX_STORE_U8(ctx.r29.u32 + 1, ctx.r9.u8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stw r29,-320(r1)
	REX_STORE_U32(ctx.r1.u32 + -320, ctx.r29.u32);
	// lbzx r6,r11,r26
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r26.u32);
	// stb r6,1(r30)
	REX_STORE_U8(ctx.r30.u32 + 1, ctx.r6.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stw r30,-316(r1)
	REX_STORE_U32(ctx.r1.u32 + -316, ctx.r30.u32);
	// b 0x8264a804
	goto loc_8264A804;
loc_8264A918:
	// stb r24,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r24.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r8,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r8.u32);
	// beq cr6,0x8264a800
	if (ctx.cr6.eq) goto loc_8264A800;
	// stb r25,1(r29)
	REX_STORE_U8(ctx.r29.u32 + 1, ctx.r25.u8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stb r25,1(r30)
	REX_STORE_U8(ctx.r30.u32 + 1, ctx.r25.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r29,-320(r1)
	REX_STORE_U32(ctx.r1.u32 + -320, ctx.r29.u32);
	// stw r30,-316(r1)
	REX_STORE_U32(ctx.r1.u32 + -316, ctx.r30.u32);
	// b 0x8264a804
	goto loc_8264A804;
loc_8264A94C:
	// lwz r9,84(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8264aaec
	if (!ctx.cr6.lt) goto loc_8264AAEC;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// bge cr6,0x8264aa3c
	if (!ctx.cr6.lt) goto loc_8264AA3C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8264ab3c
	if (!ctx.cr6.gt) goto loc_8264AB3C;
loc_8264A974:
	// fadd f0,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 + ctx.f1.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f13.u64);
	// lwz r11,-324(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8264a9fc
	if (ctx.cr6.lt) goto loc_8264A9FC;
	// lwz r9,80(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8264a9fc
	if (!ctx.cr6.lt) goto loc_8264A9FC;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r9,-228(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -228);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lbzx r31,r11,r10
	ctx.r31.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// subfic r7,r9,256
	ctx.xer.ca = ctx.r9.u32 <= 256;
	ctx.r7.u64 = static_cast<uint64_t>(256) - ctx.r9.u64;
	// mullw r7,r31,r7
	ctx.r7.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r7.s32);
	// lbzx r5,r5,r10
	ctx.r5.u64 = REX_LOAD_U8(ctx.r5.u32 + ctx.r10.u32);
	// mullw r9,r5,r9
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r7,r9,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// stb r7,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r7.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// beq cr6,0x8264aa24
	if (ctx.cr6.eq) goto loc_8264AA24;
	// lwz r9,-236(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mullw r9,r9,r22
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r22.s32);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lbzx r9,r11,r27
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// stb r9,1(r29)
	REX_STORE_U8(ctx.r29.u32 + 1, ctx.r9.u8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lbzx r5,r11,r26
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r26.u32);
	// stb r5,1(r30)
	REX_STORE_U8(ctx.r30.u32 + 1, ctx.r5.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// b 0x8264aa28
	goto loc_8264AA28;
loc_8264A9FC:
	// stb r24,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r24.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// beq cr6,0x8264aa24
	if (ctx.cr6.eq) goto loc_8264AA24;
	// stb r25,1(r29)
	REX_STORE_U8(ctx.r29.u32 + 1, ctx.r25.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r25,1(r30)
	REX_STORE_U8(ctx.r30.u32 + 1, ctx.r25.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// b 0x8264aa28
	goto loc_8264AA28;
loc_8264AA24:
	// li r7,1
	ctx.r7.s64 = 1;
loc_8264AA28:
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264a974
	if (ctx.cr6.lt) goto loc_8264A974;
	// b 0x8264ab30
	goto loc_8264AB30;
loc_8264AA3C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8264ab3c
	if (!ctx.cr6.gt) goto loc_8264AB3C;
loc_8264AA44:
	// fadd f0,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 + ctx.f1.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f13.u64);
	// lwz r9,-324(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blt cr6,0x8264aaac
	if (ctx.cr6.lt) goto loc_8264AAAC;
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8264aaac
	if (!ctx.cr6.lt) goto loc_8264AAAC;
	// lbzx r11,r9,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stb r11,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r11.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// beq cr6,0x8264aad4
	if (ctx.cr6.eq) goto loc_8264AAD4;
	// lwz r11,-236(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -236);
	// srawi r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// mullw r11,r11,r22
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r22.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lbzx r9,r11,r27
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// stb r9,1(r29)
	REX_STORE_U8(ctx.r29.u32 + 1, ctx.r9.u8);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lbzx r5,r11,r26
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r26.u32);
	// stb r5,1(r30)
	REX_STORE_U8(ctx.r30.u32 + 1, ctx.r5.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// b 0x8264aad8
	goto loc_8264AAD8;
loc_8264AAAC:
	// stb r24,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r24.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// beq cr6,0x8264aad4
	if (ctx.cr6.eq) goto loc_8264AAD4;
	// stb r25,1(r29)
	REX_STORE_U8(ctx.r29.u32 + 1, ctx.r25.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r25,1(r30)
	REX_STORE_U8(ctx.r30.u32 + 1, ctx.r25.u8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// b 0x8264aad8
	goto loc_8264AAD8;
loc_8264AAD4:
	// li r7,1
	ctx.r7.s64 = 1;
loc_8264AAD8:
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264aa44
	if (ctx.cr6.lt) goto loc_8264AA44;
	// b 0x8264ab30
	goto loc_8264AB30;
loc_8264AAEC:
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8264ab3c
	if (!ctx.cr6.gt) goto loc_8264AB3C;
loc_8264AAFC:
	// stb r24,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r24.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// beq cr6,0x8264ab1c
	if (ctx.cr6.eq) goto loc_8264AB1C;
	// stbu r25,1(r29)
	ea = 1 + ctx.r29.u32;
	REX_STORE_U8(ea, ctx.r25.u8);
	ctx.r29.u32 = ea;
	// li r7,0
	ctx.r7.s64 = 0;
	// stbu r25,1(r30)
	ea = 1 + ctx.r30.u32;
	REX_STORE_U8(ea, ctx.r25.u8);
	ctx.r30.u32 = ea;
	// b 0x8264ab20
	goto loc_8264AB20;
loc_8264AB1C:
	// li r7,1
	ctx.r7.s64 = 1;
loc_8264AB20:
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264aafc
	if (ctx.cr6.lt) goto loc_8264AAFC;
loc_8264AB30:
	// stw r30,-316(r1)
	REX_STORE_U32(ctx.r1.u32 + -316, ctx.r30.u32);
	// stw r29,-320(r1)
	REX_STORE_U32(ctx.r1.u32 + -320, ctx.r29.u32);
	// stw r8,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r8.u32);
loc_8264AB3C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lwz r6,80(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// lis r7,-32049
	ctx.r7.s64 = -2100363264;
	// lwz r5,100(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// stw r4,-248(r1)
	REX_STORE_U32(ctx.r1.u32 + -248, ctx.r4.u32);
	// fmr f0,f8
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f8.f64;
	// std r10,-192(r1)
	REX_STORE_U64(ctx.r1.u32 + -192, ctx.r10.u64);
	// lfd f13,-192(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -192);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmadd f5,f12,f3,f4
	ctx.f5.f64 = std::fma(ctx.f12.f64, ctx.f3.f64, ctx.f4.f64);
	// fctiwz f2,f5
	ctx.f2.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f2,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f2.u64);
	// lwz r10,-324(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r31,r9
	ctx.r31.s64 = ctx.r9.s32;
	// stw r9,-6108(r7)
	REX_STORE_U32(ctx.r7.u32 + -6108, ctx.r9.u32);
	// mullw r6,r6,r10
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// std r31,-176(r1)
	REX_STORE_U64(ctx.r1.u32 + -176, ctx.r31.u64);
	// add r9,r6,r5
	ctx.r9.u64 = ctx.r6.u64 + ctx.r5.u64;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// stw r9,-260(r1)
	REX_STORE_U32(ctx.r1.u32 + -260, ctx.r9.u32);
	// lfd f13,-176(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -176);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmsub f5,f5,f11,f12
	ctx.f5.f64 = std::fma(ctx.f5.f64, ctx.f11.f64, -ctx.f12.f64);
	// fctiwz f2,f5
	ctx.f2.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f2,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f2.u64);
	// lwz r21,-324(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// mullw r7,r21,r21
	ctx.r7.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r21.s32);
	// srawi r19,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r19.s64 = ctx.r7.s32 >> 8;
	// mullw r6,r19,r21
	ctx.r6.s64 = int64_t(ctx.r19.s32) * int64_t(ctx.r21.s32);
	// srawi r18,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r18.s64 = ctx.r6.s32 >> 8;
	// ble cr6,0x8264b1b4
	if (!ctx.cr6.gt) goto loc_8264B1B4;
	// lwz r7,84(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8264b1b4
	if (!ctx.cr6.lt) goto loc_8264B1B4;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r7,-276(r1)
	REX_STORE_U32(ctx.r1.u32 + -276, ctx.r7.u32);
	// ble cr6,0x8264b2bc
	if (!ctx.cr6.gt) goto loc_8264B2BC;
loc_8264ABE0:
	// fadd f0,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 + ctx.f1.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f13.u64);
	// lwz r10,-324(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// ble cr6,0x8264b174
	if (!ctx.cr6.gt) goto loc_8264B174;
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8264b174
	if (!ctx.cr6.lt) goto loc_8264B174;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r23,80(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r11,r10,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// lis r10,-32049
	ctx.r10.s64 = -2100363264;
	// subf r28,r23,r7
	ctx.r28.u64 = ctx.r7.u64 - ctx.r23.u64;
	// add r25,r23,r7
	ctx.r25.u64 = ctx.r23.u64 + ctx.r7.u64;
	// extsw r31,r11
	ctx.r31.s64 = ctx.r11.s32;
	// lbz r4,2(r7)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r7.u32 + 2);
	// stw r11,-6108(r10)
	REX_STORE_U32(ctx.r10.u32 + -6108, ctx.r11.u32);
	// rlwinm r10,r23,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r6,-1(r28)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r28.u32 + -1);
	// lbz r29,1(r25)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r25.u32 + 1);
	// add r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lbz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// add r3,r29,r6
	ctx.r3.u64 = ctx.r29.u64 + ctx.r6.u64;
	// lbz r30,-1(r25)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r25.u32 + -1);
	// rotlwi r5,r11,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lbz r10,-1(r7)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r7.u32 + -1);
	// lbz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// rlwinm r26,r3,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// std r31,-160(r1)
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.r31.u64);
	// lfd f13,-160(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// lbz r27,-1(r8)
	ctx.r27.u64 = REX_LOAD_U8(ctx.r8.u32 + -1);
	// add r3,r5,r30
	ctx.r3.u64 = ctx.r5.u64 + ctx.r30.u64;
	// lbz r31,1(r28)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r28.u32 + 1);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// add r20,r10,r9
	ctx.r20.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r28,2(r28)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r28.u32 + 2);
	// subf r17,r27,r26
	ctx.r17.u64 = ctx.r26.u64 - ctx.r27.u64;
	// lbz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// add r15,r3,r31
	ctx.r15.u64 = ctx.r3.u64 + ctx.r31.u64;
	// lbz r24,2(r8)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r8.u32 + 2);
	// subf r16,r30,r10
	ctx.r16.u64 = ctx.r10.u64 - ctx.r30.u64;
	// lbz r26,1(r8)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r8.u32 + 1);
	// rlwinm r3,r20,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r8,1(r7)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// subf r20,r28,r17
	ctx.r20.u64 = ctx.r17.u64 - ctx.r28.u64;
	// lbzx r7,r23,r7
	ctx.r7.u64 = REX_LOAD_U8(ctx.r23.u32 + ctx.r7.u32);
	// rlwinm r17,r16,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r25,2(r25)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r25.u32 + 2);
	// subf r3,r3,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r3.u64;
	// fmsub f5,f0,f11,f12
	ctx.f5.f64 = std::fma(ctx.f0.f64, ctx.f11.f64, -ctx.f12.f64);
	// rlwinm r23,r15,1,0,30
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r17,r4,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r4.u64;
	// add r3,r3,r4
	ctx.r3.u64 = ctx.r3.u64 + ctx.r4.u64;
	// subf r23,r26,r23
	ctx.r23.u64 = ctx.r23.u64 - ctx.r26.u64;
	// add r15,r20,r24
	ctx.r15.u64 = ctx.r20.u64 + ctx.r24.u64;
	// subf r20,r6,r17
	ctx.r20.u64 = ctx.r17.u64 - ctx.r6.u64;
	// rlwinm r17,r3,3,0,28
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r23,r25,r23
	ctx.r23.u64 = ctx.r23.u64 - ctx.r25.u64;
	// subf r3,r3,r17
	ctx.r3.u64 = ctx.r17.u64 - ctx.r3.u64;
	// fctiwz f2,f5
	ctx.f2.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// rlwinm r16,r23,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// stfd f2,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f2.u64);
	// rlwinm r15,r15,1,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r14,-324(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// add r20,r20,r27
	ctx.r20.u64 = ctx.r20.u64 + ctx.r27.u64;
	// add r3,r3,r15
	ctx.r3.u64 = ctx.r3.u64 + ctx.r15.u64;
	// add r23,r23,r16
	ctx.r23.u64 = ctx.r23.u64 + ctx.r16.u64;
	// subf r17,r5,r8
	ctx.r17.u64 = ctx.r8.u64 - ctx.r5.u64;
	// add r20,r20,r25
	ctx.r20.u64 = ctx.r20.u64 + ctx.r25.u64;
	// add r16,r7,r8
	ctx.r16.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r23,r3,r23
	ctx.r23.u64 = ctx.r3.u64 + ctx.r23.u64;
	// subf r3,r29,r17
	ctx.r3.u64 = ctx.r17.u64 - ctx.r29.u64;
	// rlwinm r20,r20,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r16,r16,13
	ctx.r16.s64 = static_cast<int64_t>(ctx.r16.u64 * static_cast<uint64_t>(13));
	// mullw r15,r14,r14
	ctx.r15.s64 = int64_t(ctx.r14.s32) * int64_t(ctx.r14.s32);
	// add r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 + ctx.r9.u64;
	// subf r20,r24,r20
	ctx.r20.u64 = ctx.r20.u64 - ctx.r24.u64;
	// subf r16,r16,r23
	ctx.r16.u64 = ctx.r23.u64 - ctx.r16.u64;
	// stw r3,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r3.u32);
	// srawi r23,r15,8
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0xFF) != 0);
	ctx.r23.s64 = ctx.r15.s32 >> 8;
	// rlwinm r15,r3,3,0,28
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r20,r20,r28
	ctx.r20.u64 = ctx.r20.u64 + ctx.r28.u64;
	// srawi r3,r16,1
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r16.s32 >> 1;
	// rotlwi r17,r11,2
	ctx.r17.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// stw r20,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r20.u32);
	// stw r3,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r3.u32);
	// subf r20,r7,r29
	ctx.r20.u64 = ctx.r29.u64 - ctx.r7.u64;
	// add r3,r11,r17
	ctx.r3.u64 = ctx.r11.u64 + ctx.r17.u64;
	// lwz r16,-360(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// std r3,-240(r1)
	REX_STORE_U64(ctx.r1.u32 + -240, ctx.r3.u64);
	// subf r3,r26,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r26.u64;
	// rlwinm r17,r16,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// std r22,-232(r1)
	REX_STORE_U64(ctx.r1.u32 + -232, ctx.r22.u64);
	// subf r16,r31,r9
	ctx.r16.u64 = ctx.r9.u64 - ctx.r31.u64;
	// lwz r22,-336(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -336);
	// stw r17,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r17.u32);
	// rlwinm r17,r16,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r14,-304(r1)
	REX_STORE_U32(ctx.r1.u32 + -304, ctx.r14.u32);
	// subf r16,r25,r3
	ctx.r16.u64 = ctx.r3.u64 - ctx.r25.u64;
	// std r4,-224(r1)
	REX_STORE_U64(ctx.r1.u32 + -224, ctx.r4.u64);
	// subf r17,r5,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r5.u64;
	// subf r3,r10,r16
	ctx.r3.u64 = ctx.r16.u64 - ctx.r10.u64;
	// subf r17,r6,r17
	ctx.r17.u64 = ctx.r17.u64 - ctx.r6.u64;
	// subf r15,r22,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r22.u64;
	// add r16,r17,r26
	ctx.r16.u64 = ctx.r17.u64 + ctx.r26.u64;
	// subf r17,r9,r3
	ctx.r17.u64 = ctx.r3.u64 - ctx.r9.u64;
	// stw r15,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r15.u32);
	// subf r15,r11,r10
	ctx.r15.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,-368(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// add r17,r17,r30
	ctx.r17.u64 = ctx.r17.u64 + ctx.r30.u64;
	// subf r15,r6,r15
	ctx.r15.u64 = ctx.r15.u64 - ctx.r6.u64;
	// stw r17,-300(r1)
	REX_STORE_U32(ctx.r1.u32 + -300, ctx.r17.u32);
	// subf r17,r8,r20
	ctx.r17.u64 = ctx.r20.u64 - ctx.r8.u64;
	// rlwinm r15,r15,1,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r26,r31,r26
	ctx.r26.u64 = ctx.r26.u64 - ctx.r31.u64;
	// stw r17,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r17.u32);
	// subf r17,r4,r15
	ctx.r17.u64 = ctx.r15.u64 - ctx.r4.u64;
	// stw r26,-272(r1)
	REX_STORE_U32(ctx.r1.u32 + -272, ctx.r26.u32);
	// subf r26,r29,r7
	ctx.r26.u64 = ctx.r7.u64 - ctx.r29.u64;
	// stw r17,-296(r1)
	REX_STORE_U32(ctx.r1.u32 + -296, ctx.r17.u32);
	// add r16,r16,r28
	ctx.r16.u64 = ctx.r16.u64 + ctx.r28.u64;
	// subf r17,r4,r26
	ctx.r17.u64 = ctx.r26.u64 - ctx.r4.u64;
	// rlwinm r16,r16,1,0,30
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// add r17,r17,r10
	ctx.r17.u64 = ctx.r17.u64 + ctx.r10.u64;
	// lwz r26,-360(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// subf r16,r24,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r24.u64;
	// stw r17,-280(r1)
	REX_STORE_U32(ctx.r1.u32 + -280, ctx.r17.u32);
	// subf r15,r11,r7
	ctx.r15.u64 = ctx.r7.u64 - ctx.r11.u64;
	// stw r16,-256(r1)
	REX_STORE_U32(ctx.r1.u32 + -256, ctx.r16.u32);
	// subf r25,r30,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r30.u64;
	// mulli r15,r15,11
	ctx.r15.s64 = static_cast<int64_t>(ctx.r15.u64 * static_cast<uint64_t>(11));
	// stw r15,-308(r1)
	REX_STORE_U32(ctx.r1.u32 + -308, ctx.r15.u32);
	// lwz r17,-336(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -336);
	// add r17,r26,r17
	ctx.r17.u64 = ctx.r26.u64 + ctx.r17.u64;
	// stw r17,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r17.u32);
	// rlwinm r26,r20,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r16,-300(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -300);
	// lwz r15,-344(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// add r26,r20,r26
	ctx.r26.u64 = ctx.r20.u64 + ctx.r26.u64;
	// stw r25,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r25.u32);
	// mullw r20,r3,r19
	ctx.r20.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r19.s32);
	// lwz r22,-272(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -272);
	// stw r26,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r26.u32);
	// stw r20,-284(r1)
	REX_STORE_U32(ctx.r1.u32 + -284, ctx.r20.u32);
	// lwz r25,-280(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + -280);
	// lwz r20,-256(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// add r17,r16,r4
	ctx.r17.u64 = ctx.r16.u64 + ctx.r4.u64;
	// lwz r4,-308(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -308);
	// add r15,r15,r11
	ctx.r15.u64 = ctx.r15.u64 + ctx.r11.u64;
	// stw r25,-300(r1)
	REX_STORE_U32(ctx.r1.u32 + -300, ctx.r25.u32);
	// rotlwi r3,r17,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r17.u32, 0);
	// rotlwi r26,r15,0
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r15.u32, 0);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// rotlwi r14,r22,0
	ctx.r14.u64 = __builtin_rotateleft32(ctx.r22.u32, 0);
	// lwz r16,-360(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// rotlwi r25,r31,2
	ctx.r25.u64 = __builtin_rotateleft32(ctx.r31.u32, 2);
	// stw r17,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r17.u32);
	// lwz r17,-296(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -296);
	// stw r15,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r15.u32);
	// stw r20,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r20.u32);
	// add r17,r17,r8
	ctx.r17.u64 = ctx.r17.u64 + ctx.r8.u64;
	// rlwinm r20,r26,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r17,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r17.u32);
	// rlwinm r17,r22,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// add r26,r26,r20
	ctx.r26.u64 = ctx.r26.u64 + ctx.r20.u64;
	// lwz r15,-336(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -336);
	// add r20,r15,r28
	ctx.r20.u64 = ctx.r15.u64 + ctx.r28.u64;
	// rlwinm r15,r3,1,0,30
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r26,-256(r1)
	REX_STORE_U32(ctx.r1.u32 + -256, ctx.r26.u32);
	// rlwinm r26,r20,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r15,-296(r1)
	REX_STORE_U32(ctx.r1.u32 + -296, ctx.r15.u32);
	// add r20,r14,r17
	ctx.r20.u64 = ctx.r14.u64 + ctx.r17.u64;
	// lwz r15,-360(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// lwz r22,-368(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// add r25,r31,r25
	ctx.r25.u64 = ctx.r31.u64 + ctx.r25.u64;
	// stw r20,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r20.u32);
	// add r17,r15,r27
	ctx.r17.u64 = ctx.r15.u64 + ctx.r27.u64;
	// lwz r20,-344(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// rotlwi r15,r26,0
	ctx.r15.u64 = __builtin_rotateleft32(ctx.r26.u32, 0);
	// rlwinm r3,r17,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 1) & 0xFFFFFFFE;
	// std r23,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.r23.u64);
	// rlwinm r17,r20,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r14,-300(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -300);
	// stw r26,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r26.u32);
	// add r26,r16,r4
	ctx.r26.u64 = ctx.r16.u64 + ctx.r4.u64;
	// add r20,r20,r17
	ctx.r20.u64 = ctx.r20.u64 + ctx.r17.u64;
	// lwz r4,-280(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -280);
	// rlwinm r14,r14,3,0,28
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r17,-256(r1)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r1.u32 + -256);
	// stw r20,-368(r1)
	REX_STORE_U32(ctx.r1.u32 + -368, ctx.r20.u32);
	// rotlwi r16,r9,3
	ctx.r16.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// lwz r23,-368(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + -368);
	// subf r14,r4,r14
	ctx.r14.u64 = ctx.r14.u64 - ctx.r4.u64;
	// subf r16,r9,r16
	ctx.r16.u64 = ctx.r16.u64 - ctx.r9.u64;
	// lwz r4,-296(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -296);
	// stw r14,-300(r1)
	REX_STORE_U32(ctx.r1.u32 + -300, ctx.r14.u32);
	// add r20,r15,r22
	ctx.r20.u64 = ctx.r15.u64 + ctx.r22.u64;
	// stw r16,-344(r1)
	REX_STORE_U32(ctx.r1.u32 + -344, ctx.r16.u32);
	// subf r31,r9,r31
	ctx.r31.u64 = ctx.r31.u64 - ctx.r9.u64;
	// subf r25,r25,r20
	ctx.r25.u64 = ctx.r20.u64 - ctx.r25.u64;
	// stw r3,-336(r1)
	REX_STORE_U32(ctx.r1.u32 + -336, ctx.r3.u32);
	// add r20,r4,r17
	ctx.r20.u64 = ctx.r4.u64 + ctx.r17.u64;
	// lwz r14,-284(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -284);
	// lwz r15,-360(r1)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// rlwinm r31,r31,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r16,r11,r8
	ctx.r16.u64 = ctx.r8.u64 - ctx.r11.u64;
	// add r26,r26,r15
	ctx.r26.u64 = ctx.r26.u64 + ctx.r15.u64;
	// stw r31,-360(r1)
	REX_STORE_U32(ctx.r1.u32 + -360, ctx.r31.u32);
	// subf r15,r27,r20
	ctx.r15.u64 = ctx.r20.u64 - ctx.r27.u64;
	// srawi r4,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r26.s32 >> 1;
	// subf r20,r11,r9
	ctx.r20.u64 = ctx.r9.u64 - ctx.r11.u64;
	// rotlwi r26,r3,0
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lwz r3,-300(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -300);
	// subf r22,r6,r20
	ctx.r22.u64 = ctx.r20.u64 - ctx.r6.u64;
	// lwz r20,-344(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + -344);
	// add r26,r26,r3
	ctx.r26.u64 = ctx.r26.u64 + ctx.r3.u64;
	// add r3,r25,r20
	ctx.r3.u64 = ctx.r25.u64 + ctx.r20.u64;
	// add r20,r26,r23
	ctx.r20.u64 = ctx.r26.u64 + ctx.r23.u64;
	// mulli r17,r16,11
	ctx.r17.s64 = static_cast<int64_t>(ctx.r16.u64 * static_cast<uint64_t>(11));
	// subf r25,r28,r15
	ctx.r25.u64 = ctx.r15.u64 - ctx.r28.u64;
	// mullw r26,r4,r18
	ctx.r26.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r18.s32);
	// srawi r15,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r15.s64 = ctx.r3.s32 >> 1;
	// add r25,r25,r24
	ctx.r25.u64 = ctx.r25.u64 + ctx.r24.u64;
	// add r20,r20,r17
	ctx.r20.u64 = ctx.r20.u64 + ctx.r17.u64;
	// add r31,r14,r26
	ctx.r31.u64 = ctx.r14.u64 + ctx.r26.u64;
	// mullw r26,r15,r21
	ctx.r26.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r21.s32);
	// add r25,r25,r6
	ctx.r25.u64 = ctx.r25.u64 + ctx.r6.u64;
	// srawi r24,r20,1
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x1) != 0);
	ctx.r24.s64 = ctx.r20.s32 >> 1;
	// add r15,r31,r26
	ctx.r15.u64 = ctx.r31.u64 + ctx.r26.u64;
	// mullw r26,r25,r18
	ctx.r26.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r18.s32);
	// mullw r31,r24,r19
	ctx.r31.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r19.s32);
	// subf r16,r10,r30
	ctx.r16.u64 = ctx.r30.u64 - ctx.r10.u64;
	// add r24,r31,r26
	ctx.r24.u64 = ctx.r31.u64 + ctx.r26.u64;
	// rlwinm r26,r16,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r16,-360(r1)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r1.u32 + -360);
	// rlwinm r25,r22,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r20,r27,r26
	ctx.r20.u64 = ctx.r26.u64 - ctx.r27.u64;
	// subf r31,r5,r25
	ctx.r31.u64 = ctx.r25.u64 - ctx.r5.u64;
	// subf r25,r29,r16
	ctx.r25.u64 = ctx.r16.u64 - ctx.r29.u64;
	// add r27,r31,r27
	ctx.r27.u64 = ctx.r31.u64 + ctx.r27.u64;
	// subf r26,r8,r29
	ctx.r26.u64 = ctx.r29.u64 - ctx.r8.u64;
	// subf r25,r8,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r8.u64;
	// subf r29,r29,r20
	ctx.r29.u64 = ctx.r20.u64 - ctx.r29.u64;
	// add r16,r27,r7
	ctx.r16.u64 = ctx.r27.u64 + ctx.r7.u64;
	// rlwinm r27,r26,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r25,r10,r25
	ctx.r25.u64 = ctx.r25.u64 - ctx.r10.u64;
	// subf r14,r7,r29
	ctx.r14.u64 = ctx.r29.u64 - ctx.r7.u64;
	// subf r31,r8,r11
	ctx.r31.u64 = ctx.r11.u64 - ctx.r8.u64;
	// add r26,r26,r27
	ctx.r26.u64 = ctx.r26.u64 + ctx.r27.u64;
	// subf r29,r28,r25
	ctx.r29.u64 = ctx.r25.u64 - ctx.r28.u64;
	// rotlwi r27,r30,2
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r30.u32, 2);
	// ld r4,-224(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + -224);
	// rlwinm r17,r31,1,0,30
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// ld r23,-328(r1)
	ctx.r23.u64 = REX_LOAD_U64(ctx.r1.u32 + -328);
	// rlwinm r20,r16,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 1) & 0xFFFFFFFE;
	// ld r3,-240(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -240);
	// subf r28,r9,r14
	ctx.r28.u64 = ctx.r14.u64 - ctx.r9.u64;
	// lwz r14,-304(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + -304);
	// add r30,r30,r27
	ctx.r30.u64 = ctx.r30.u64 + ctx.r27.u64;
	// add r17,r31,r17
	ctx.r17.u64 = ctx.r31.u64 + ctx.r17.u64;
	// rotlwi r27,r10,3
	ctx.r27.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r26,r20,r26
	ctx.r26.u64 = ctx.r20.u64 + ctx.r26.u64;
	// add r31,r28,r5
	ctx.r31.u64 = ctx.r28.u64 + ctx.r5.u64;
	// subf r27,r10,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r10.u64;
	// subf r30,r30,r26
	ctx.r30.u64 = ctx.r26.u64 - ctx.r30.u64;
	// add r31,r31,r8
	ctx.r31.u64 = ctx.r31.u64 + ctx.r8.u64;
	// subf r28,r10,r17
	ctx.r28.u64 = ctx.r17.u64 - ctx.r10.u64;
	// add r29,r29,r7
	ctx.r29.u64 = ctx.r29.u64 + ctx.r7.u64;
	// add r27,r30,r27
	ctx.r27.u64 = ctx.r30.u64 + ctx.r27.u64;
	// add r30,r31,r11
	ctx.r30.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r28,r28,r4
	ctx.r28.u64 = ctx.r28.u64 + ctx.r4.u64;
	// subf r20,r10,r11
	ctx.r20.u64 = ctx.r11.u64 - ctx.r10.u64;
	// add r29,r29,r4
	ctx.r29.u64 = ctx.r29.u64 + ctx.r4.u64;
	// mullw r26,r23,r14
	ctx.r26.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r14.s32);
	// rotlwi r31,r8,1
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// add r16,r30,r6
	ctx.r16.u64 = ctx.r30.u64 + ctx.r6.u64;
	// srawi r17,r28,1
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1) != 0);
	ctx.r17.s64 = ctx.r28.s32 >> 1;
	// add r29,r29,r11
	ctx.r29.u64 = ctx.r29.u64 + ctx.r11.u64;
	// subf r30,r9,r20
	ctx.r30.u64 = ctx.r20.u64 - ctx.r9.u64;
	// rotlwi r28,r7,1
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// srawi r26,r26,8
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0xFF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 8;
	// add r31,r31,r10
	ctx.r31.u64 = ctx.r31.u64 + ctx.r10.u64;
	// srawi r27,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 1;
	// subf r10,r10,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r10.u64;
	// mullw r25,r15,r23
	ctx.r25.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r23.s32);
	// add r20,r29,r6
	ctx.r20.u64 = ctx.r29.u64 + ctx.r6.u64;
	// add r8,r30,r6
	ctx.r8.u64 = ctx.r30.u64 + ctx.r6.u64;
	// add r15,r28,r9
	ctx.r15.u64 = ctx.r28.u64 + ctx.r9.u64;
	// mullw r29,r27,r19
	ctx.r29.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r19.s32);
	// mullw r28,r16,r18
	ctx.r28.s64 = int64_t(ctx.r16.s32) * int64_t(ctx.r18.s32);
	// mullw r6,r8,r21
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r21.s32);
	// rlwinm r31,r31,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// add r8,r29,r28
	ctx.r8.u64 = ctx.r29.u64 + ctx.r28.u64;
	// subf r29,r4,r31
	ctx.r29.u64 = ctx.r31.u64 - ctx.r4.u64;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// rlwinm r4,r10,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// subf r10,r7,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r7.u64;
	// add r28,r8,r4
	ctx.r28.u64 = ctx.r8.u64 + ctx.r4.u64;
	// rlwinm r6,r15,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r31,r20,r21
	ctx.r31.s64 = int64_t(ctx.r20.s32) * int64_t(ctx.r21.s32);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r4,r5,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r5.u64;
	// add r31,r24,r31
	ctx.r31.u64 = ctx.r24.u64 + ctx.r31.u64;
	// rlwinm r30,r17,8,0,23
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 8) & 0xFFFFFF00;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// subf r8,r3,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r3.u64;
	// subf r27,r9,r7
	ctx.r27.u64 = ctx.r7.u64 - ctx.r9.u64;
	// add r6,r31,r30
	ctx.r6.u64 = ctx.r31.u64 + ctx.r30.u64;
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subf r4,r3,r29
	ctx.r4.u64 = ctx.r29.u64 - ctx.r3.u64;
	// srawi r10,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 1;
	// mullw r6,r6,r26
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r26.s32);
	// srawi r9,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 1;
	// add r8,r7,r5
	ctx.r8.u64 = ctx.r7.u64 + ctx.r5.u64;
	// add r3,r25,r6
	ctx.r3.u64 = ctx.r25.u64 + ctx.r6.u64;
	// srawi r7,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// mullw r6,r10,r19
	ctx.r6.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r19.s32);
	// mullw r4,r9,r23
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r23.s32);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// add r8,r6,r4
	ctx.r8.u64 = ctx.r6.u64 + ctx.r4.u64;
	// mullw r11,r7,r18
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r18.s32);
	// srawi r6,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r27.s32 >> 1;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// mullw r8,r6,r21
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r21.s32);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mullw r31,r28,r14
	ctx.r31.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r14.s32);
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r3,r31
	ctx.r10.u64 = ctx.r3.u64 + ctx.r31.u64;
	// rlwinm r11,r5,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r11,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 16;
	// ld r22,-232(r1)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r1.u32 + -232);
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x8264b130
	if (!ctx.cr6.gt) goto loc_8264B130;
	// li r11,255
	ctx.r11.s64 = 255;
	// b 0x8264b13c
	goto loc_8264B13C;
loc_8264B130:
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
loc_8264B13C:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,-352(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -352);
	// lwz r9,-260(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -260);
	// li r25,128
	ctx.r25.s64 = 128;
	// lwz r27,-264(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + -264);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lwz r30,-316(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + -316);
	// li r24,16
	ctx.r24.s64 = 16;
	// lwz r29,-320(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + -320);
	// lwz r26,-268(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
	// lwz r3,20(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r7,-276(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -276);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// b 0x8264b194
	goto loc_8264B194;
loc_8264B174:
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x8264b18c
	if (!ctx.cr6.lt) goto loc_8264B18C;
	// lbzx r11,r10,r9
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// stb r11,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r11.u8);
	// b 0x8264b190
	goto loc_8264B190;
loc_8264B18C:
	// stb r24,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r24.u8);
loc_8264B190:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_8264B194:
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stw r8,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r8.u32);
	// stw r7,-276(r1)
	REX_STORE_U32(ctx.r1.u32 + -276, ctx.r7.u32);
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264abe0
	if (ctx.cr6.lt) goto loc_8264ABE0;
	// lwz r4,-248(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + -248);
	// b 0x8264b2bc
	goto loc_8264B2BC;
loc_8264B1B4:
	// lwz r7,84(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8264b298
	if (!ctx.cr6.lt) goto loc_8264B298;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8264b240
	if (!ctx.cr6.lt) goto loc_8264B240;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8264b2bc
	if (!ctx.cr6.gt) goto loc_8264B2BC;
loc_8264B1D8:
	// fadd f0,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 + ctx.f1.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f13.u64);
	// lwz r11,-324(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8264b224
	if (ctx.cr6.lt) goto loc_8264B224;
	// lwz r10,80(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x8264b224
	if (!ctx.cr6.lt) goto loc_8264B224;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbzx r6,r11,r9
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// subfic r5,r21,256
	ctx.xer.ca = ctx.r21.u32 <= 256;
	ctx.r5.u64 = static_cast<uint64_t>(256) - ctx.r21.u64;
	// mullw r11,r6,r5
	ctx.r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32);
	// lbzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// mullw r10,r10,r21
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r21.s32);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// stb r5,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r5.u8);
	// b 0x8264b228
	goto loc_8264B228;
loc_8264B224:
	// stb r24,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r24.u8);
loc_8264B228:
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r7,r11
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264b1d8
	if (ctx.cr6.lt) goto loc_8264B1D8;
	// b 0x8264b2b8
	goto loc_8264B2B8;
loc_8264B240:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8264b2bc
	if (!ctx.cr6.gt) goto loc_8264B2BC;
loc_8264B24C:
	// fadd f0,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 + ctx.f1.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,-328(r1)
	REX_STORE_U64(ctx.r1.u32 + -328, ctx.f13.u64);
	// lwz r11,-324(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + -324);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8264b27c
	if (ctx.cr6.lt) goto loc_8264B27C;
	// lwz r7,80(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8264b27c
	if (!ctx.cr6.lt) goto loc_8264B27C;
	// lbzx r11,r11,r9
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// stb r11,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r11.u8);
	// b 0x8264b280
	goto loc_8264B280;
loc_8264B27C:
	// stb r24,1(r8)
	REX_STORE_U8(ctx.r8.u32 + 1, ctx.r24.u8);
loc_8264B280:
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264b24c
	if (ctx.cr6.lt) goto loc_8264B24C;
	// b 0x8264b2b8
	goto loc_8264B2B8;
loc_8264B298:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8264b2bc
	if (!ctx.cr6.gt) goto loc_8264B2BC;
loc_8264B2A4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbu r24,1(r8)
	ea = 1 + ctx.r8.u32;
	REX_STORE_U8(ea, ctx.r24.u8);
	ctx.r8.u32 = ea;
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8264b2a4
	if (ctx.cr6.lt) goto loc_8264B2A4;
loc_8264B2B8:
	// stw r8,-352(r1)
	REX_STORE_U32(ctx.r1.u32 + -352, ctx.r8.u32);
loc_8264B2BC:
	// lwz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stw r4,-248(r1)
	REX_STORE_U32(ctx.r1.u32 + -248, ctx.r4.u32);
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826497f8
	if (ctx.cr6.lt) goto loc_826497F8;
loc_8264B2D0:
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826D2CE8) {
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
	// lwz r11,2952(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2952);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,2112(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 2112);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r8,r11,732
	ctx.r8.s64 = ctx.r11.s64 + 732;
	// lwz r4,248(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r7,r11,735
	ctx.r7.s64 = ctx.r11.s64 + 735;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,266
	ctx.r10.s64 = ctx.r10.s64 + 266;
	// add r8,r11,r3
	ctx.r8.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwzx r7,r6,r3
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r7,2904(r3)
	REX_STORE_U32(ctx.r3.u32 + 2904, ctx.r7.u32);
	// lwzx r5,r5,r3
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// stw r5,2916(r3)
	REX_STORE_U32(ctx.r3.u32 + 2916, ctx.r5.u32);
	// lwz r11,2124(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 2124);
	// stw r11,2116(r3)
	REX_STORE_U32(ctx.r3.u32 + 2116, ctx.r11.u32);
	// lwzx r10,r6,r3
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// stw r10,2120(r3)
	REX_STORE_U32(ctx.r3.u32 + 2120, ctx.r10.u32);
	// stw r9,456(r3)
	REX_STORE_U32(ctx.r3.u32 + 456, ctx.r9.u32);
	// bl 0x82621158
	ctx.lr = 0x826D2D5C;
	sub_82621158(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826136c0
	ctx.lr = 0x826D2D64;
	sub_826136C0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82607e90
	ctx.lr = 0x826D2D70;
	sub_82607E90(ctx, base);
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

DEFINE_REX_FUNC(sub_826EC3D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x826EC3D8;
	__savegprlr_25(ctx, base);
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// li r11,16
	ctx.r11.s64 = 16;
	// lvx128 v63,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// vspltish v12,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0x1)));
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r31,r9,r4
	ctx.r31.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lvsl v3,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// vspltish v13,2
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x2)));
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lvx128 v46,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r3,r4
	ctx.r5.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lvsl v1,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// add r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 + ctx.r4.u64;
	// lvx128 v59,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v6,v60,v58,v1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// lvx128 v56,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r30,r7,r4
	ctx.r30.u64 = ctx.r7.u64 + ctx.r4.u64;
	// lvsl v7,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r28,1104
	ctx.r28.s64 = 1104;
	// vperm128 v4,v59,v56,v7
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v57,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v2,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v9,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// rlwinm r5,r4,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lvx128 v51,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v31,v63,v57,v2
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// lvsl v6,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v8,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v55,r10,r11
	ea = (ctx.r10.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v4,v54,v51,v6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvsl v5,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v10,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v2,v61,v55,v5
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvx128 v53,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r7,r11
	ea = (ctx.r7.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v26,v62,v46,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// lvx128 v49,r30,r11
	ea = (ctx.r30.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v31,v9,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v52,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v1,v10,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvsl v6,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v7,v0,v2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v5,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v30,v52,v49,v6
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v5,v53,v50,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvx128 v47,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v6,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v48,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvsl v4,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vslh v2,v8,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vperm128 v28,v48,v47,v4
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v27,r6,r28
	ea = (ctx.r6.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r27,48
	ctx.r27.s64 = 48;
	// vmrghb v4,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r26,96
	ctx.r26.s64 = 96;
	// li r25,144
	ctx.r25.s64 = 144;
	// vslh v29,v7,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v7.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsrah v11,v27,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// li r11,192
	ctx.r11.s64 = 192;
	// vslh v25,v6,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vmrghb v3,v0,v28
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vslh v24,v5,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// li r10,240
	ctx.r10.s64 = 240;
	// vslh v23,v4,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// li r9,288
	ctx.r9.s64 = 288;
	// vmrghb v22,v0,v26
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vaddshs v21,v1,v10
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// li r8,336
	ctx.r8.s64 = 336;
	// vaddshs v20,v31,v9
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v19,v2,v8
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vslh v17,v3,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v18,v29,v7
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v16,v25,v6
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v15,v24,v5
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v14,v23,v4
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v0,v17,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v12,v21,v22
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v22.s16)));
	// vaddshs v10,v20,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v9,v19,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v8,v18,v8
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v7,v16,v7
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vaddshs v6,v15,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v15.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v5,v14,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v14.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v4,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v3,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v2,v10,v11
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v1,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v31,v8,v11
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v30,v7,v11
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v29,v6,v11
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v28,v5,v11
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vaddshs v27,v4,v11
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// vsrah v26,v3,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v25,v2,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v24,v1,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v23,v31,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v22,v30,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v26,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v21,v29,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v29.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v25,r29,r27
	ea = (ctx.r29.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v20,v28,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v24,r29,r26
	ea = (ctx.r29.u32 + ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsrah v19,v27,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v27.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// stvx128 v23,r29,r25
	ea = (ctx.r29.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r29,r11
	ea = (ctx.r29.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v20,r29,r9
	ea = (ctx.r29.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v19,r29,r8
	ea = (ctx.r29.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82703070) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0284
	ctx.lr = 0x82703078;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// add r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// lbz r25,668(r11)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + 668);
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// addi r26,r3,232
	ctx.r26.s64 = ctx.r3.s64 + 232;
	// lwz r10,24(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// clrlwi r27,r25,30
	ctx.r27.u64 = ctx.r25.u32 & 0x3;
	// lwz r7,0(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r4,632(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 632);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x827030f0
	if (ctx.cr6.lt) goto loc_827030F0;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x82604718
	ctx.lr = 0x827030E8;
	sub_82604718(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x82703148
	goto loc_82703148;
loc_827030F0:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x82703144
	if (!ctx.cr6.gt) goto loc_82703144;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_827030FC:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r23,r3,r26
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r23,r9
	ctx.r9.u64 = ctx.r23.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x827030fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827030FC;
loc_82703144:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_82703148:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x827031b4
	if (!ctx.cr6.eq) goto loc_827031B4;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 + ctx.r24.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// srawi r10,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 3;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// srawi r6,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rldicr r10,r3,32,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000;
	// or r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 | ctx.r3.u64;
	// std r9,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r9.u64);
	// std r9,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r9.u64);
	// std r9,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r9.u64);
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// b 0x827031d0
	goto loc_827031D0;
loc_827031B4:
	// rlwinm r10,r27,2,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x826e8930
	ctx.lr = 0x827031D0;
	sub_826E8930(ctx, base);
loc_827031D0:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r25,r25,30,26,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3F;
	// lwz r4,632(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// clrlwi r27,r25,30
	ctx.r27.u64 = ctx.r25.u32 & 0x3;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x8270322c
	if (ctx.cr6.lt) goto loc_8270322C;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82604718
	ctx.lr = 0x82703224;
	sub_82604718(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x82703284
	goto loc_82703284;
loc_8270322C:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x82703280
	if (!ctx.cr6.gt) goto loc_82703280;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82703238:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r23,r3,r26
	ctx.r23.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r23,r9
	ctx.r9.u64 = ctx.r23.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x82703238
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82703238;
loc_82703280:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_82703284:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x827032f0
	if (!ctx.cr6.eq) goto loc_827032F0;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r24
	ctx.r11.u64 = ctx.r9.u64 + ctx.r24.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// srawi r10,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 3;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// srawi r6,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rldicr r10,r3,32,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFF00000000;
	// or r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 | ctx.r3.u64;
	// std r9,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r9.u64);
	// std r9,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r9.u64);
	// std r9,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r9.u64);
	// std r9,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// b 0x8270330c
	goto loc_8270330C;
loc_827032F0:
	// rlwinm r10,r27,2,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x826e8930
	ctx.lr = 0x8270330C;
	sub_826E8930(ctx, base);
loc_8270330C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r9,r25,30,26,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 30) & 0x3F;
	// lwz r4,632(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 632);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// clrlwi r27,r9,30
	ctx.r27.u64 = ctx.r9.u32 & 0x3;
	// lwz r30,40(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r5,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// dcbzl r0,r30
	ea = (ctx.r30.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x82703368
	if (ctx.cr6.lt) goto loc_82703368;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82604718
	ctx.lr = 0x82703360;
	sub_82604718(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x827033c0
	goto loc_827033C0;
loc_82703368:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x827033bc
	if (!ctx.cr6.gt) goto loc_827033BC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82703374:
	// lhz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r5,26
	ctx.r8.u64 = ctx.r5.u32 & 0x3F;
	// rlwinm r3,r5,24,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r3,r7
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r7.s32);
	// lbzx r3,r10,r4
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r29,r3,r26
	ctx.r29.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r26.u32);
	// rlwinm r5,r5,25,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r5,r5
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// rotlwi r3,r3,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// xor r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// or r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 | ctx.r9.u64;
	// subf r5,r5,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r5.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r5,r3,r30
	REX_STORE_U16(ctx.r3.u32 + ctx.r30.u32, ctx.r5.u16);
	// bdnz 0x82703374
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82703374;
loc_827033BC:
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_827033C0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// clrlwi r10,r27,31
	ctx.r10.u64 = ctx.r27.u32 & 0x1;
	// bne cr6,0x82703430
	if (!ctx.cr6.eq) goto loc_82703430;
	// lhz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 0);
	// rlwinm r9,r27,2,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r10,r24
	ctx.r11.u64 = ctx.r10.u64 + ctx.r24.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// srawi r10,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 3;
	// srawi r9,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 4;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r5,r6,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// or r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 | ctx.r6.u64;
	// rldicr r3,r4,32,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF00000000;
	// or r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 | ctx.r4.u64;
	// std r10,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r10.u64);
	// std r10,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r10.u64);
	// std r10,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r10.u64);
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_82703430:
	// rlwinm r11,r27,2,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0x8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r24
	ctx.r4.u64 = ctx.r11.u64 + ctx.r24.u64;
	// bl 0x826e8930
	ctx.lr = 0x82703448;
	sub_826E8930(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
}

