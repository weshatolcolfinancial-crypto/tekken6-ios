#include "tekken6_funcs.98.h"

DEFINE_REX_FUNC(sub_82174748) {
	REX_FUNC_PROLOGUE();
	// lhz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82175DB0) {
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
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ld r3,0(r4)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// ld r4,8(r4)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r4.u32 + 8);
	// ld r5,16(r11)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r11.u32 + 16);
	// ld r6,24(r11)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r11.u32 + 24);
	// ld r7,32(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 32);
	// ld r8,40(r11)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r11.u32 + 40);
	// ld r9,48(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 48);
	// ld r10,56(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 56);
	// bl 0x82174108
	ctx.lr = 0x82175DEC;
	sub_82174108(ctx, base);
	// vspltisw v0,-1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// vslw v11,v0,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor v0,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vsel v12,v0,v1,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8))));
	// stvx128 v12,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_8217C408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// addi r10,r1,36
	ctx.r10.s64 = ctx.r1.s64 + 36;
	// stfs f1,36(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 36, temp.u32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lvx128 v0,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-16(r1)
	REX_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r11,-12(r1)
	REX_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// stw r11,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r11.u32);
	// vor v13,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// stw r8,-4(r1)
	REX_STORE_U32(ctx.r1.u32 + -4, ctx.r8.u32);
	// lvlx v12,0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw v11,v12,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), 0xFF));
	// vmulfp128 v0,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8217FDC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// vupkd3d128 v13,v0,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v13 = vTemp;
	// vpermwi128 v12,v13,234
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x15));
	// vpermwi128 v11,v13,186
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x45));
	// vpermwi128 v10,v13,174
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x51));
	// vpermwi128 v9,v13,171
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x54));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82184A38) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,144(r3)
	REX_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82184AC8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,184(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,184(r3)
	REX_STORE_U32(ctx.r3.u32 + 184, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82184D70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x82184D78;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82184edc
	if (ctx.cr6.eq) goto loc_82184EDC;
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82184da0
	if (ctx.cr6.eq) goto loc_82184DA0;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82184da4
	goto loc_82184DA4;
loc_82184DA0:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82184DA4:
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	ctx.r11.s64 = 48;
	// addi r7,r31,64
	ctx.r7.s64 = ctx.r31.s64 + 64;
	// addi r6,r8,64
	ctx.r6.s64 = ctx.r8.s64 + 64;
	// lvx128 v13,r31,r9
	ea = (ctx.r31.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r31,128
	ctx.r5.s64 = ctx.r31.s64 + 128;
	// stvx128 v13,r8,r9
	ea = (ctx.r8.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r8,128
	ctx.r4.s64 = ctx.r8.s64 + 128;
	// lvx128 v12,r31,r10
	ea = (ctx.r31.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r31,192
	ctx.r29.s64 = ctx.r31.s64 + 192;
	// stvx128 v12,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r8,192
	ctx.r28.s64 = ctx.r8.s64 + 192;
	// lvx128 v11,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r31,256
	ctx.r27.s64 = ctx.r31.s64 + 256;
	// stvx128 v11,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,256
	ctx.r8.s64 = ctx.r8.s64 + 256;
	// lvx128 v10,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r31,320
	ctx.r26.s64 = ctx.r31.s64 + 320;
	// stvx128 v10,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r30,100
	ctx.r3.s64 = ctx.r30.s64 + 100;
	// lvx128 v9,r7,r9
	ea = (ctx.r7.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r6,r9
	ea = (ctx.r6.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r7,r10
	ea = (ctx.r7.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r6,r10
	ea = (ctx.r6.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r7,r11
	ea = (ctx.r7.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r6,r11
	ea = (ctx.r6.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v6,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v5,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v4,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,80
	ctx.r5.s64 = 80;
	// stvx128 v3,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lvx128 v2,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r29,r9
	ea = (ctx.r29.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v1,r28,r9
	ea = (ctx.r28.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v31,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v31,r28,r10
	ea = (ctx.r28.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r29,r11
	ea = (ctx.r29.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r28,r11
	ea = (ctx.r28.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v28,r27,r9
	ea = (ctx.r27.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v28,r8,r9
	ea = (ctx.r8.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r27,r10
	ea = (ctx.r27.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v27,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r27,r11
	ea = (ctx.r27.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v26,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826a1130
	ctx.lr = 0x82184E84;
	rexcrt_memcpy(ctx, base);
	// lwz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 400);
	// stw r11,180(r30)
	REX_STORE_U32(ctx.r30.u32 + 180, ctx.r11.u32);
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// stw r10,184(r30)
	REX_STORE_U32(ctx.r30.u32 + 184, ctx.r10.u32);
	// ld r9,416(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 416);
	// std r9,192(r30)
	REX_STORE_U64(ctx.r30.u32 + 192, ctx.r9.u64);
	// ld r8,424(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 424);
	// std r8,200(r30)
	REX_STORE_U64(ctx.r30.u32 + 200, ctx.r8.u64);
	// ld r7,432(r31)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r31.u32 + 432);
	// std r7,208(r30)
	REX_STORE_U64(ctx.r30.u32 + 208, ctx.r7.u64);
	// ld r6,440(r31)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r31.u32 + 440);
	// std r6,216(r30)
	REX_STORE_U64(ctx.r30.u32 + 216, ctx.r6.u64);
	// lwz r5,448(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 448);
	// stw r5,224(r30)
	REX_STORE_U32(ctx.r30.u32 + 224, ctx.r5.u32);
	// lfs f0,452(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 452);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,228(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 228, temp.u32);
	// lfs f13,456(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 456);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,232(r30)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r30.u32 + 232, temp.u32);
	// lwz r4,460(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 460);
	// stw r4,236(r30)
	REX_STORE_U32(ctx.r30.u32 + 236, ctx.r4.u32);
	// lwz r3,464(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 464);
	// stw r3,240(r30)
	REX_STORE_U32(ctx.r30.u32 + 240, ctx.r3.u32);
loc_82184EDC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82194790) {
	REX_FUNC_PROLOGUE();
	// fsqrts f0,f2
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(sqrt(ctx.f2.f64)));
	// fdivs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82194B68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82194D00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82194D08;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82194b98
	ctx.lr = 0x82194D1C;
	sub_82194B98(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r11,8112
	ctx.r4.s64 = ctx.r11.s64 + 8112;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lfs f0,8100(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8100);
	ctx.f0.f64 = double(temp.f32);
	// li r10,80
	ctx.r10.s64 = 80;
	// lvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,112
	ctx.r11.s64 = ctx.r31.s64 + 112;
	// stvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// vor v12,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// stvx128 v0,r31,r7
	ea = (ctx.r31.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v11,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// stvx128 v0,r31,r8
	ea = (ctx.r31.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v10,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// stvx128 v0,r31,r9
	ea = (ctx.r31.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v8,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// stvx128 v0,r31,r10
	ea = (ctx.r31.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v7,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// stvx128 v13,r31,r6
	ea = (ctx.r31.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r29,-32141
	ctx.r29.s64 = -2106392576;
	// stvx128 v0,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1
	ctx.r5.s64 = 1;
	// stvx128 v0,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stvx128 v0,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,224
	ctx.r11.s64 = ctx.r31.s64 + 224;
	// stfs f0,208(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 208, temp.u32);
	// stw r5,2332(r29)
	REX_STORE_U32(ctx.r29.u32 + 2332, ctx.r5.u32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,336
	ctx.r11.s64 = ctx.r31.s64 + 336;
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,448
	ctx.r11.s64 = ctx.r31.s64 + 448;
	// stfs f0,432(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 432, temp.u32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,560
	ctx.r11.s64 = ctx.r31.s64 + 560;
	// stfs f0,544(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 544, temp.u32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,672
	ctx.r11.s64 = ctx.r31.s64 + 672;
	// stfs f0,656(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 656, temp.u32);
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r11,r6
	ea = (ctx.r11.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,768(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 768, temp.u32);
	// bl 0x82170670
	ctx.lr = 0x82194E50;
	sub_82170670(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,72(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,784(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 784, temp.u32);
	// lfs f11,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// lfs f0,8088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8088);
	ctx.f0.f64 = double(temp.f32);
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,52(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lfs f8,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f8.f64 = double(temp.f32);
	// stw r11,976(r31)
	REX_STORE_U32(ctx.r31.u32 + 976, ctx.r11.u32);
	// stfs f8,984(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 984, temp.u32);
	// stfs f8,980(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 980, temp.u32);
	// lfs f7,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,996(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 996, temp.u32);
	// stfs f7,992(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 992, temp.u32);
	// stw r11,988(r31)
	REX_STORE_U32(ctx.r31.u32 + 988, ctx.r11.u32);
	// lfs f6,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,1008(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 1008, temp.u32);
	// stfs f6,1004(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 1004, temp.u32);
	// stw r11,1000(r31)
	REX_STORE_U32(ctx.r31.u32 + 1000, ctx.r11.u32);
	// lfs f5,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,1020(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 1020, temp.u32);
	// stfs f5,1016(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 1016, temp.u32);
	// stw r11,1012(r31)
	REX_STORE_U32(ctx.r31.u32 + 1012, ctx.r11.u32);
	// lfs f4,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,1032(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + 1032, temp.u32);
	// stfs f4,1028(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + 1028, temp.u32);
	// stw r11,1024(r31)
	REX_STORE_U32(ctx.r31.u32 + 1024, ctx.r11.u32);
	// lfs f3,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,1044(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r31.u32 + 1044, temp.u32);
	// stfs f3,1040(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r31.u32 + 1040, temp.u32);
	// stw r11,1036(r31)
	REX_STORE_U32(ctx.r31.u32 + 1036, ctx.r11.u32);
	// lfs f2,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,1056(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r31.u32 + 1056, temp.u32);
	// stfs f2,1052(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r31.u32 + 1052, temp.u32);
	// stw r11,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r11.u32);
	// lfs f1,784(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 784);
	ctx.f1.f64 = double(temp.f32);
	// stw r11,944(r31)
	REX_STORE_U32(ctx.r31.u32 + 944, ctx.r11.u32);
	// stfs f1,800(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 800, temp.u32);
	// stw r11,948(r31)
	REX_STORE_U32(ctx.r31.u32 + 948, ctx.r11.u32);
	// lfs f31,2880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
	// stw r11,952(r31)
	REX_STORE_U32(ctx.r31.u32 + 952, ctx.r11.u32);
	// stfs f31,788(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 788, temp.u32);
	// stw r11,956(r31)
	REX_STORE_U32(ctx.r31.u32 + 956, ctx.r11.u32);
	// stfs f31,792(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 792, temp.u32);
	// stw r11,960(r31)
	REX_STORE_U32(ctx.r31.u32 + 960, ctx.r11.u32);
	// stfs f31,796(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 796, temp.u32);
	// stw r11,964(r31)
	REX_STORE_U32(ctx.r31.u32 + 964, ctx.r11.u32);
	// stfs f31,928(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 928, temp.u32);
	// stw r11,968(r31)
	REX_STORE_U32(ctx.r31.u32 + 968, ctx.r11.u32);
	// stw r11,972(r31)
	REX_STORE_U32(ctx.r31.u32 + 972, ctx.r11.u32);
	// lwz r11,88(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 88);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82194ff0
	if (ctx.cr6.eq) goto loc_82194FF0;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x82194f9c
	if (ctx.cr6.eq) goto loc_82194F9C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,2936(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2936);
	ctx.f1.f64 = double(temp.f32);
	// beq cr6,0x82194f7c
	if (ctx.cr6.eq) goto loc_82194F7C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f3,8096(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8096);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4268(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4268);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82194c60
	ctx.lr = 0x82194F70;
	sub_82194C60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82194F7C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f3,8092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8092);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,6372(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6372);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82194c60
	ctx.lr = 0x82194F90;
	sub_82194C60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82194F9C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,1092(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1092);
	// bl 0x8218b5c0
	ctx.lr = 0x82194FA8;
	sub_8218B5C0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,6372(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4268(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4268);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f0,2884(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,8096(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8096);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82195038
	goto loc_82195038;
loc_82194FF0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,1092(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 1092);
	// bl 0x8218b5c0
	ctx.lr = 0x82194FFC;
	sub_8218B5C0(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,2884(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f13,6372(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6372);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8092(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 8092);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82195038:
	// li r7,1072
	ctx.r7.s64 = 1072;
	// stvx128 v0,r31,r7
	ea = (ctx.r31.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f8,1088(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 1088, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821AD858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r9,10
	ctx.r9.s64 = 10;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r9,920(r3)
	REX_STORE_U32(ctx.r3.u32 + 920, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,100
	ctx.r11.s64 = ctx.r3.s64 + 100;
	// stw r10,912(r3)
	REX_STORE_U32(ctx.r3.u32 + 912, ctx.r10.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,2880(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4284(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4284);
	ctx.f13.f64 = double(temp.f32);
loc_821AD880:
	// stfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 48, temp.u32);
	// stfs f13,76(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// stwu r10,80(r11)
	ea = 80 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821ad880
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821AD880;
	// stw r10,916(r3)
	REX_STORE_U32(ctx.r3.u32 + 916, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821B04D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// vupkd3d128 v13,v0,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v13 = vTemp;
	// vpermwi128 v12,v13,234
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x15));
	// vpermwi128 v11,v13,186
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x45));
	// vpermwi128 v10,v13,174
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x51));
	// vpermwi128 v9,v13,171
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x54));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821B2A30) {
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
	// lwz r3,80(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// bl 0x8220ae48
	ctx.lr = 0x821B2A50;
	sub_8220AE48(ctx, base);
	// cmpwi cr6,r3,30
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 30, ctx.xer);
	// beq cr6,0x821b2ac4
	if (ctx.cr6.eq) goto loc_821B2AC4;
	// cmpwi cr6,r3,35
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 35, ctx.xer);
	// bne cr6,0x821b2bac
	if (!ctx.cr6.eq) goto loc_821B2BAC;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r4,80(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1344
	ctx.r3.s64 = 1344;
	// bl 0x82219630
	ctx.lr = 0x821B2A7C;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821b2a90
	if (ctx.cr6.eq) goto loc_821B2A90;
	// bl 0x82326cc0
	ctx.lr = 0x821B2A88;
	sub_82326CC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x821b2a94
	goto loc_821B2A94;
loc_821B2A90:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821B2A94:
	// addi r31,r31,160
	ctx.r31.s64 = ctx.r31.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8226bf28
	ctx.lr = 0x821B2AA0;
	sub_8226BF28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243fa70
	ctx.lr = 0x821B2AA8;
	sub_8243FA70(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x82326598
	ctx.lr = 0x821B2AB0;
	sub_82326598(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243fa70
	ctx.lr = 0x821B2AB8;
	sub_8243FA70(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// b 0x821b2bac
	goto loc_821B2BAC;
loc_821B2AC4:
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r4,80(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1344
	ctx.r3.s64 = 1344;
	// bl 0x82219630
	ctx.lr = 0x821B2AE0;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821b2af4
	if (ctx.cr6.eq) goto loc_821B2AF4;
	// bl 0x82326cc0
	ctx.lr = 0x821B2AEC;
	sub_82326CC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x821b2af8
	goto loc_821B2AF8;
loc_821B2AF4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_821B2AF8:
	// addi r31,r31,160
	ctx.r31.s64 = ctx.r31.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8226bf28
	ctx.lr = 0x821B2B04;
	sub_8226BF28(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821b2b24
	if (ctx.cr6.eq) goto loc_821B2B24;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821b2b28
	if (ctx.cr6.eq) goto loc_821B2B28;
loc_821B2B24:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821B2B28:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821b2b4c
	if (ctx.cr6.eq) goto loc_821B2B4C;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821b2b50
	if (!ctx.cr6.eq) goto loc_821B2B50;
loc_821B2B4C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821B2B50:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82326598
	ctx.lr = 0x821B2B5C;
	sub_82326598(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821b2b7c
	if (ctx.cr6.eq) goto loc_821B2B7C;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821b2b80
	if (ctx.cr6.eq) goto loc_821B2B80;
loc_821B2B7C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821B2B80:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821b2ba0
	if (ctx.cr6.eq) goto loc_821B2BA0;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821b2ba4
	if (!ctx.cr6.eq) goto loc_821B2BA4;
loc_821B2BA0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821B2BA4:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r10.u32);
loc_821B2BAC:
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

DEFINE_REX_FUNC(sub_821B7F30) {
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

DEFINE_REX_FUNC(sub_821BA860) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x821BA868;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,168(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// lhz r28,8(r3)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// bl 0x821bacc8
	ctx.lr = 0x821BA87C;
	sub_821BACC8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x826a0da8
	ctx.lr = 0x821BA884;
	sub_826A0DA8(ctx, base);
	// lis r11,20971
	ctx.r11.s64 = 1374355456;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// ori r10,r11,34079
	ctx.r10.u64 = ctx.r11.u64 | 34079;
	// li r29,0
	ctx.r29.s64 = 0;
	// mulhw r8,r3,r10
	ctx.r8.s64 = (int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32)) >> 32;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// lfs f0,2884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 152, temp.u32);
	// srawi r11,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 5;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mulli r6,r7,100
	ctx.r6.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(100));
	// subf r11,r6,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r6.u64;
	// addi r27,r11,1
	ctx.r27.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x821ba8f8
	if (ctx.cr6.eq) goto loc_821BA8F8;
loc_821BA8C4:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ba3d0
	ctx.lr = 0x821BA8D8;
	sub_821BA3D0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821ba904
	if (!ctx.cr6.eq) goto loc_821BA904;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821bac40
	ctx.lr = 0x821BA8E8;
	sub_821BAC40(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x821ba8c4
	if (ctx.cr6.lt) goto loc_821BA8C4;
loc_821BA8F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA904:
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x821ba924
	if (ctx.cr6.lt) goto loc_821BA924;
	// bl 0x821b7a20
	ctx.lr = 0x821BA918;
	sub_821B7A20(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_821BA924:
	// bl 0x821b86a0
	ctx.lr = 0x821BA928;
	sub_821B86A0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821BD538) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bl 0x826a0da8
	ctx.lr = 0x821BD55C;
	sub_826A0DA8(ctx, base);
	// lis r11,6967
	ctx.r11.s64 = 456589312;
	// ori r10,r11,18507
	ctx.r10.u64 = ctx.r11.u64 | 18507;
	// mulhw r9,r3,r10
	ctx.r9.s64 = (int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32)) >> 32;
	// srawi r11,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 5;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mulli r7,r8,301
	ctx.r7.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(301));
	// subf r11,r7,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r7.u64;
	// addi r6,r11,61
	ctx.r6.s64 = ctx.r11.s64 + 61;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// stw r5,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
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

DEFINE_REX_FUNC(sub_821BEC58) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821BEC98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw v13,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_set1_epi32(int(0x1)));
	// vmsum3fp128 v8,v0,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// vspltisw v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// vcfsx v10,v13,1
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v13.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vrsqrtefp v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v8.f32))));
	// vmulfp128 v12,v8,v10
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vcmpeqfp v9,v8,v7
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmulfp128 v11,v0,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v10,v12,v11,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v10,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v0,v8,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v12,v0,v8,v9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821C2050) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x821C2058;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// addi r30,r11,23664
	ctx.r30.s64 = ctx.r11.s64 + 23664;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c2088
	if (ctx.cr6.eq) goto loc_821C2088;
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821c208c
	if (ctx.cr6.eq) goto loc_821C208C;
loc_821C2088:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821C208C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r28,-32256
	ctx.r28.s64 = -2113929216;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821c20b0
	if (ctx.cr6.eq) goto loc_821C20B0;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821c20b4
	if (!ctx.cr6.eq) goto loc_821C20B4;
loc_821C20B0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821C20B4:
	// lwz r3,932(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 932);
	// bl 0x821c3978
	ctx.lr = 0x821C20BC;
	sub_821C3978(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821c21fc
	if (ctx.cr6.eq) goto loc_821C21FC;
	// bl 0x8238e4c8
	ctx.lr = 0x821C20C8;
	sub_8238E4C8(ctx, base);
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// ori r29,r11,51711
	ctx.r29.u64 = ctx.r11.u64 | 51711;
	// beq cr6,0x821c20f4
	if (ctx.cr6.eq) goto loc_821C20F4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r3,640(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 640);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// bl 0x8243c9d8
	ctx.lr = 0x821C20F0;
	sub_8243C9D8(ctx, base);
	// stw r3,640(r31)
	REX_STORE_U32(ctx.r31.u32 + 640, ctx.r3.u32);
loc_821C20F4:
	// bl 0x8238e518
	ctx.lr = 0x821C20F8;
	sub_8238E518(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821c211c
	if (ctx.cr6.eq) goto loc_821C211C;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r3,648(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 648);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// bl 0x8243c9d8
	ctx.lr = 0x821C2118;
	sub_8243C9D8(ctx, base);
	// stw r3,648(r31)
	REX_STORE_U32(ctx.r31.u32 + 648, ctx.r3.u32);
loc_821C211C:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c213c
	if (ctx.cr6.eq) goto loc_821C213C;
	// lwz r10,20(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x821c2140
	if (ctx.cr6.eq) goto loc_821C2140;
loc_821C213C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821C2140:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821c2160
	if (ctx.cr6.eq) goto loc_821C2160;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821c2164
	if (!ctx.cr6.eq) goto loc_821C2164;
loc_821C2160:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821C2164:
	// lwz r3,932(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 932);
	// bl 0x821c3978
	ctx.lr = 0x821C216C;
	sub_821C3978(ctx, base);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x821c21fc
	if (ctx.cr6.gt) goto loc_821C21FC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821c21e0
	if (ctx.cr6.eq) goto loc_821C21E0;
	// bdz 0x821c2198
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821C2198;
	// bdz 0x821c21bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821C21BC;
	// bdz 0x821c21fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821C21FC;
	// bdz 0x821c21fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821C21FC;
	// b 0x821c21e0
	goto loc_821C21E0;
loc_821C2198:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r3,624(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 624);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// bl 0x8243c9d8
	ctx.lr = 0x821C21B0;
	sub_8243C9D8(ctx, base);
	// stw r3,624(r31)
	REX_STORE_U32(ctx.r31.u32 + 624, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_821C21BC:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r3,632(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 632);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// bl 0x8243c9d8
	ctx.lr = 0x821C21D4;
	sub_8243C9D8(ctx, base);
	// stw r3,632(r31)
	REX_STORE_U32(ctx.r31.u32 + 632, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_821C21E0:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r3,616(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 616);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// bl 0x8243c9d8
	ctx.lr = 0x821C21F8;
	sub_8243C9D8(ctx, base);
	// stw r3,616(r31)
	REX_STORE_U32(ctx.r31.u32 + 616, ctx.r3.u32);
loc_821C21FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821C9770) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x821C9778;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821c9794
	if (ctx.cr6.eq) goto loc_821C9794;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// bne cr6,0x821c97c8
	if (!ctx.cr6.eq) goto loc_821C97C8;
loc_821C9794:
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r29.u32);
	// bl 0x82298168
	ctx.lr = 0x821C97A0;
	sub_82298168(ctx, base);
	// bl 0x822d2b68
	ctx.lr = 0x821C97A4;
	sub_822D2B68(ctx, base);
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
	// bl 0x821c8b10
	ctx.lr = 0x821C97B4;
	sub_821C8B10(ctx, base);
	// stw r30,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r30.u32);
	// stw r30,580(r31)
	REX_STORE_U32(ctx.r31.u32 + 580, ctx.r30.u32);
	// stw r29,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_821C97C8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821CCB18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x821CCB20;
	__savegprlr_29(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// li r8,15
	ctx.r8.s64 = 15;
	// li r7,18
	ctx.r7.s64 = 18;
	// lfs f0,2880(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// li r6,8
	ctx.r6.s64 = 8;
	// lfs f13,2884(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2884);
	ctx.f13.f64 = double(temp.f32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
	// stw r7,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// li r31,6
	ctx.r31.s64 = 6;
	// stw r6,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// stw r5,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// stw r4,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// stw r3,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
loc_821CCB80:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwzu r4,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r4.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x82187b08
	ctx.lr = 0x821CCB8C;
	sub_82187B08(ctx, base);
	// addi r11,r3,112
	ctx.r11.s64 = ctx.r3.s64 + 112;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r3,330
	ctx.r3.s64 = 330;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f12,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82260e60
	ctx.lr = 0x821CCBBC;
	sub_82260E60(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x821ccb80
	if (!ctx.cr0.eq) goto loc_821CCB80;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821CFC18) {
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
	// lbz r11,4608(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4608);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cfc58
	if (ctx.cr6.eq) goto loc_821CFC58;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CFC40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,3120(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 3120);
	// bl 0x8222fec8
	ctx.lr = 0x821CFC48;
	sub_8222FEC8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821CFC58:
	// addi r3,r3,160
	ctx.r3.s64 = ctx.r3.s64 + 160;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821D2E90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x821D2E98;
	__savegprlr_26(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x826a0d04
	ctx.lr = 0x821D2EA0;
	__savefpr_23(ctx, base);
	// stwu r1,-864(r1)
	ea = -864 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f1.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f24,f2
	ctx.f24.f64 = ctx.f2.f64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f23,f3
	ctx.f23.f64 = ctx.f3.f64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f29,21240(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21240);
	ctx.f29.f64 = double(temp.f32);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lfs f0,21248(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 21248);
	ctx.f0.f64 = double(temp.f32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lfs f30,2880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f30.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f31,2884(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2884);
	ctx.f31.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,21236(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 21236);
	ctx.f13.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stfs f29,160(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,21232(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 21232);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,21228(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 21228);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f10,21224(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 21224);
	ctx.f10.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f9,21244(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 21244);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,21220(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21220);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,21216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 21216);
	ctx.f7.f64 = double(temp.f32);
	// lfs f28,21212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 21212);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,21208(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 21208);
	ctx.f27.f64 = double(temp.f32);
	// lfs f26,21204(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 21204);
	ctx.f26.f64 = double(temp.f32);
	// stfs f30,168(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f29,176(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f30,184(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f30,192(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f31,196(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f12,200(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f31,204(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f30,208(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f11,212(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f10,216(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f31,220(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f30,224(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f9,228(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f29,232(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f31,236(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f30,240(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f8,244(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f7,248(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f31,252(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f29,256(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f28,260(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f30,264(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f31,268(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f27,272(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f26,276(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f30,280(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f31,284(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// bl 0x82513bb8
	ctx.lr = 0x821D2FAC;
	sub_82513BB8(ctx, base);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// vspltisw v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// vupkd3d128 v13,v0,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v0.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v13 = vTemp;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// vpermwi128 v12,v13,234
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x15));
	// vpermwi128 v11,v13,186
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x45));
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// vpermwi128 v10,v13,174
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x51));
	// vpermwi128 v9,v13,171
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x54));
	// stvx128 v12,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x821d3010
	if (ctx.cr6.eq) goto loc_821D3010;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x821d3014
	if (ctx.cr6.eq) goto loc_821D3014;
loc_821D3010:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821D3014:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r9,30048(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30048);
	// beq cr6,0x821d3038
	if (ctx.cr6.eq) goto loc_821D3038;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821d303c
	if (!ctx.cr6.eq) goto loc_821D303C;
loc_821D3038:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821D303C:
	// lwz r11,884(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 884);
	// lwz r3,180(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 180);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3060
	if (ctx.cr6.eq) goto loc_821D3060;
	// lwz r8,184(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x821d3064
	if (ctx.cr6.eq) goto loc_821D3064;
loc_821D3060:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821D3064:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d3080
	if (ctx.cr6.eq) goto loc_821D3080;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821d3084
	if (!ctx.cr6.eq) goto loc_821D3084;
loc_821D3080:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821D3084:
	// bl 0x821b5e80
	ctx.lr = 0x821D3088;
	sub_821B5E80(ctx, base);
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// addi r6,r1,336
	ctx.r6.s64 = ctx.r1.s64 + 336;
	// addi r7,r1,320
	ctx.r7.s64 = ctx.r1.s64 + 320;
	// li r8,32
	ctx.r8.s64 = 32;
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// addi r31,r1,320
	ctx.r31.s64 = ctx.r1.s64 + 320;
	// stvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// lvx128 v12,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw v11,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// lvx128 v10,r3,r5
	ea = (ctx.r3.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw v9,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v12.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// stvx128 v10,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stfs f30,344(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f30,340(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f30,336(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw v8,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vmrglw v7,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vmrghw v6,v11,v8
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vmrglw v5,v11,v8
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.u32), simde_mm_load_si128((simde__m128i*)ctx.v11.u32)));
	// vmrghw v4,v9,v7
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.u32), simde_mm_load_si128((simde__m128i*)ctx.v9.u32)));
	// vmrglw v3,v9,v7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.u32), simde_mm_load_si128((simde__m128i*)ctx.v9.u32)));
	// stvx128 v6,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v5,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v4,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v3,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82513be0
	ctx.lr = 0x821D3120;
	sub_82513BE0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f30,356(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f30,360(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// stfs f31,368(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// stw r30,364(r1)
	REX_STORE_U32(ctx.r1.u32 + 364, ctx.r30.u32);
	// stfs f31,372(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stw r30,392(r1)
	REX_STORE_U32(ctx.r1.u32 + 392, ctx.r30.u32);
	// lfs f13,4268(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4268);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,396(r1)
	REX_STORE_U32(ctx.r1.u32 + 396, ctx.r30.u32);
	// fsubs f11,f24,f13
	ctx.f11.f64 = double(float(ctx.f24.f64 - ctx.f13.f64));
	// lfs f12,4272(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4272);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f8,f23,f13
	ctx.f8.f64 = double(float(ctx.f23.f64 - ctx.f13.f64));
	// lfs f0,21252(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 21252);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f10,f25,f12
	ctx.f10.f64 = double(float(ctx.f25.f64 * ctx.f12.f64));
	// stfs f31,376(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f31,380(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stw r30,412(r1)
	REX_STORE_U32(ctx.r1.u32 + 412, ctx.r30.u32);
	// stfs f30,384(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// stw r30,440(r1)
	REX_STORE_U32(ctx.r1.u32 + 440, ctx.r30.u32);
	// stfs f30,388(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stw r30,444(r1)
	REX_STORE_U32(ctx.r1.u32 + 444, ctx.r30.u32);
	// stfs f10,352(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// stw r30,460(r1)
	REX_STORE_U32(ctx.r1.u32 + 460, ctx.r30.u32);
	// stfs f10,400(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stw r30,488(r1)
	REX_STORE_U32(ctx.r1.u32 + 488, ctx.r30.u32);
	// stfs f0,404(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stw r30,492(r1)
	REX_STORE_U32(ctx.r1.u32 + 492, ctx.r30.u32);
	// stfs f30,408(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stw r30,508(r1)
	REX_STORE_U32(ctx.r1.u32 + 508, ctx.r30.u32);
	// fmuls f9,f11,f25
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f25.f64));
	// stfs f31,416(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// stfs f31,420(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// stw r30,536(r1)
	REX_STORE_U32(ctx.r1.u32 + 536, ctx.r30.u32);
	// stfs f31,424(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// stw r30,540(r1)
	REX_STORE_U32(ctx.r1.u32 + 540, ctx.r30.u32);
	// stfs f31,428(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// fmuls f7,f8,f25
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f25.f64));
	// stfs f30,432(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// stfs f31,436(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// stfs f9,448(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// stfs f30,452(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stw r30,556(r1)
	REX_STORE_U32(ctx.r1.u32 + 556, ctx.r30.u32);
	// stfs f30,456(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stw r30,584(r1)
	REX_STORE_U32(ctx.r1.u32 + 584, ctx.r30.u32);
	// stfs f31,464(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// stw r30,588(r1)
	REX_STORE_U32(ctx.r1.u32 + 588, ctx.r30.u32);
	// stfs f31,468(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// stw r30,604(r1)
	REX_STORE_U32(ctx.r1.u32 + 604, ctx.r30.u32);
	// stfs f31,472(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// stw r30,632(r1)
	REX_STORE_U32(ctx.r1.u32 + 632, ctx.r30.u32);
	// stfs f31,476(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// stw r30,636(r1)
	REX_STORE_U32(ctx.r1.u32 + 636, ctx.r30.u32);
	// stfs f31,480(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// stw r30,652(r1)
	REX_STORE_U32(ctx.r1.u32 + 652, ctx.r30.u32);
	// stfs f30,484(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// stw r30,680(r1)
	REX_STORE_U32(ctx.r1.u32 + 680, ctx.r30.u32);
	// stfs f9,496(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// stw r30,684(r1)
	REX_STORE_U32(ctx.r1.u32 + 684, ctx.r30.u32);
	// stfs f0,500(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stw r30,700(r1)
	REX_STORE_U32(ctx.r1.u32 + 700, ctx.r30.u32);
	// stfs f30,504(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stw r30,728(r1)
	REX_STORE_U32(ctx.r1.u32 + 728, ctx.r30.u32);
	// stfs f31,512(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// stw r30,732(r1)
	REX_STORE_U32(ctx.r1.u32 + 732, ctx.r30.u32);
	// stfs f31,516(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// addi r31,r1,352
	ctx.r31.s64 = ctx.r1.s64 + 352;
	// stfs f31,520(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// li r29,8
	ctx.r29.s64 = 8;
	// stfs f31,524(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// stfs f31,528(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// stfs f31,532(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// stfs f9,544(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// stfs f30,548(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// stfs f30,552(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// stfs f29,560(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// stfs f28,564(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// stfs f30,568(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// stfs f31,572(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// stfs f30,576(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// stfs f30,580(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stfs f9,592(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 592, temp.u32);
	// stfs f0,596(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 596, temp.u32);
	// stfs f30,600(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 600, temp.u32);
	// stfs f27,608(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// stfs f26,612(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// stfs f30,616(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 616, temp.u32);
	// stfs f31,620(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 620, temp.u32);
	// stfs f30,624(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 624, temp.u32);
	// stfs f31,628(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 628, temp.u32);
	// stfs f30,644(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 644, temp.u32);
	// stfs f30,648(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 648, temp.u32);
	// stfs f29,656(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 656, temp.u32);
	// stfs f7,640(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 640, temp.u32);
	// stfs f28,660(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 660, temp.u32);
	// stfs f30,664(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 664, temp.u32);
	// stfs f31,668(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 668, temp.u32);
	// stfs f31,672(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 672, temp.u32);
	// stfs f30,676(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 676, temp.u32);
	// stfs f7,688(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 688, temp.u32);
	// stfs f0,692(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 692, temp.u32);
	// stfs f30,696(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 696, temp.u32);
	// stfs f27,704(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 704, temp.u32);
	// stfs f26,708(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// stfs f30,712(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 712, temp.u32);
	// stfs f31,716(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 716, temp.u32);
	// stfs f31,720(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 720, temp.u32);
	// stfs f31,724(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 724, temp.u32);
loc_821D32D4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82515608
	ctx.lr = 0x821D32E0;
	sub_82515608(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82515418
	ctx.lr = 0x821D32F0;
	sub_82515418(ctx, base);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// bne 0x821d32d4
	if (!ctx.cr0.eq) goto loc_821D32D4;
	// rlwinm r10,r27,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 5) & 0xFFFFFFE0;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stfs f30,108(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r7,r1,464
	ctx.r7.s64 = ctx.r1.s64 + 464;
	// stfs f30,112(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r31,r8,-30496
	ctx.r31.s64 = ctx.r8.s64 + -30496;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// ld r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + 0);
	// addi r5,r1,512
	ctx.r5.s64 = ctx.r1.s64 + 512;
	// ld r29,8(r11)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// ld r27,8(r10)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r10.u32 + 8);
	// li r9,240
	ctx.r9.s64 = 240;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stfs f30,120(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stfs f30,124(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f30,128(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stfs f30,132(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r4,0(r7)
	REX_STORE_U64(ctx.r7.u32 + 0, ctx.r4.u64);
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// std r29,8(r7)
	REX_STORE_U64(ctx.r7.u32 + 8, ctx.r29.u64);
	// stfs f30,144(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// std r4,0(r6)
	REX_STORE_U64(ctx.r6.u32 + 0, ctx.r4.u64);
	// stfs f30,148(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// std r29,8(r6)
	REX_STORE_U64(ctx.r6.u32 + 8, ctx.r29.u64);
	// stfs f30,152(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// std r8,0(r5)
	REX_STORE_U64(ctx.r5.u32 + 0, ctx.r8.u64);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// std r27,8(r5)
	REX_STORE_U64(ctx.r5.u32 + 8, ctx.r27.u64);
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// std r27,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r27.u64);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_821D33C0:
	// stbu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x821d33c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821D33C0;
	// li r29,-10
	ctx.r29.s64 = -10;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// li r3,212
	ctx.r3.s64 = 212;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// bl 0x82514e88
	ctx.lr = 0x821D33F0;
	sub_82514E88(ctx, base);
	// li r11,5153
	ctx.r11.s64 = 5153;
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r30,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// bl 0x82513308
	ctx.lr = 0x821D3404;
	sub_82513308(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r30,r11,21028
	ctx.r30.s64 = ctx.r11.s64 + 21028;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,-12
	ctx.r4.s64 = ctx.r30.s64 + -12;
	// bl 0x82513e58
	ctx.lr = 0x821D341C;
	sub_82513E58(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// bl 0x82513e58
	ctx.lr = 0x821D342C;
	sub_82513E58(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82513ee8
	ctx.lr = 0x821D3434;
	sub_82513EE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// bl 0x82515b88
	ctx.lr = 0x821D3444;
	sub_82515B88(ctx, base);
	// bl 0x82524b40
	ctx.lr = 0x821D3448;
	sub_82524B40(ctx, base);
	// addi r1,r1,864
	ctx.r1.s64 = ctx.r1.s64 + 864;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x826a0d50
	ctx.lr = 0x821D3454;
	__restfpr_23(ctx, base);
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821F9328) {
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
	// bl 0x826a0da8
	ctx.lr = 0x821F9338;
	sub_826A0DA8(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,7680(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7680);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FAE68) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lfs f0,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// bl 0x82173db0
	ctx.lr = 0x821FAE98;
	sub_82173DB0(ctx, base);
	// addic r9,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// subfe r8,r9,r3
	temp.u8 = (~ctx.r9.u32 + ctx.r3.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r8,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r8.u32);
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

DEFINE_REX_FUNC(sub_821FCA90) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821fcad4
	if (!ctx.cr6.eq) goto loc_821FCAD4;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821fcad4
	if (!ctx.cr6.eq) goto loc_821FCAD4;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821fcad4
	if (!ctx.cr6.eq) goto loc_821FCAD4;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x821fcad8
	if (ctx.cr6.eq) goto loc_821FCAD8;
loc_821FCAD4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821FCAD8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FD540) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x821fd55c
	if (ctx.cr6.lt) goto loc_821FD55C;
	// bne cr6,0x821fd55c
	if (!ctx.cr6.eq) goto loc_821FD55C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r3,87(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 87);
	// blr 
	return;
loc_821FD55C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FDB10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x821FDB18;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
loc_821FDB28:
	// lwz r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x821fdb4c
	if (ctx.cr6.eq) goto loc_821FDB4C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fd830
	ctx.lr = 0x821FDB3C;
	sub_821FD830(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fd400
	ctx.lr = 0x821FDB44;
	sub_821FD400(ctx, base);
	// cmpw cr6,r29,r3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x821fdb68
	if (ctx.cr6.eq) goto loc_821FDB68;
loc_821FDB4C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// cmpwi cr6,r30,23
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 23, ctx.xer);
	// blt cr6,0x821fdb28
	if (ctx.cr6.lt) goto loc_821FDB28;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_821FDB68:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_821FEDF8) {
	REX_FUNC_PROLOGUE();
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r9,10(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 10);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FF750) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_821FFAC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x821FFAC8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x821ffb10
	if (!ctx.cr6.gt) goto loc_821FFB10;
	// li r31,0
	ctx.r31.s64 = 0;
loc_821FFAE8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// addic. r3,r11,16
	ctx.xer.ca = ctx.r11.u32 > 4294967279;
	ctx.r3.s64 = ctx.r11.s64 + 16;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821ffafc
	if (ctx.cr0.eq) goto loc_821FFAFC;
	// bl 0x821e5348
	ctx.lr = 0x821FFAFC;
	sub_821E5348(ctx, base);
loc_821FFAFC:
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,384
	ctx.r31.s64 = ctx.r31.s64 + 384;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x821ffae8
	if (ctx.cr6.lt) goto loc_821FFAE8;
loc_821FFB10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822020A8) {
	REX_FUNC_PROLOGUE();
	// mulli r3,r5,52
	ctx.r3.s64 = static_cast<int64_t>(ctx.r5.u64 * static_cast<uint64_t>(52));
	// b 0x82512fc0
	sub_82512FC0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82202250) {
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
	// addi r9,r11,25532
	ctx.r9.s64 = ctx.r11.s64 + 25532;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82202284
	if (ctx.cr6.eq) goto loc_82202284;
	// bl 0x82573808
	ctx.lr = 0x82202280;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82202284:
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

DEFINE_REX_FUNC(sub_82204198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r11,r4,-8
	ctx.r11.s64 = ctx.r4.s64 + -8;
	// addi r10,r3,-8
	ctx.r10.s64 = ctx.r3.s64 + -8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_822041A8:
	// ldu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U64(ea);
	ctx.r11.u32 = ea;
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	REX_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x822041a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822041A8;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,0(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f11,16(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// stfs f9,16(r3)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lfs f8,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// stfs f6,32(r3)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f5,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f3,4(r3)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f2,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f0,f1,f2
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f13,36(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f10,8(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// stfs f11,36(r3)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lfs f9,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// lfs f7,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// stfs f8,8(r3)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f6,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// lfs f4,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// stfs f5,24(r3)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lfs f3,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f3.f64));
	// lfs f1,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// stfs f2,40(r3)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lfs f0,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f12,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lfs f11,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f9,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// stfs f10,28(r3)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lfs f8,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// stfs f7,44(r3)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8220B0B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8220b0dc
	if (ctx.cr6.eq) goto loc_8220B0DC;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
loc_8220B0DC:
	// li r11,0
	ctx.r11.s64 = 0;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8220F4A8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,284(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 284);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8220f4c8
	if (ctx.cr6.eq) goto loc_8220F4C8;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,288(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 288);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8220f4cc
	if (ctx.cr6.eq) goto loc_8220F4CC;
loc_8220F4C8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8220F4CC:
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
	// lwz r10,284(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 284);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8220f518
	if (ctx.cr6.eq) goto loc_8220F518;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r8,288(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 288);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8220f51c
	if (ctx.cr6.eq) goto loc_8220F51C;
loc_8220F518:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8220F51C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8220f53c
	if (ctx.cr6.eq) goto loc_8220F53C;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8220f540
	if (!ctx.cr6.eq) goto loc_8220F540;
loc_8220F53C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8220F540:
	// b 0x821e49b8
	sub_821E49B8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82216F00) {
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
	// addi r31,r3,464
	ctx.r31.s64 = ctx.r3.s64 + 464;
	// li r30,28
	ctx.r30.s64 = 28;
loc_82216F1C:
	// addi r31,r31,-16
	ctx.r31.s64 = ctx.r31.s64 + -16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8223cdb0
	ctx.lr = 0x82216F28;
	sub_8223CDB0(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82216f1c
	if (!ctx.cr0.lt) goto loc_82216F1C;
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

DEFINE_REX_FUNC(sub_82217990) {
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
	// bl 0x821ed9e8
	ctx.lr = 0x822179A8;
	sub_821ED9E8(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,27724
	ctx.r9.s64 = ctx.r11.s64 + 27724;
	// addi r3,r31,384
	ctx.r3.s64 = ctx.r31.s64 + 384;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r10,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// bl 0x821ecdd0
	ctx.lr = 0x822179C4;
	sub_821ECDD0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r7,r8,29424
	ctx.r7.s64 = ctx.r8.s64 + 29424;
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
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

DEFINE_REX_FUNC(sub_82218CC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82218CD0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 24);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r10,32(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r9,28(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r8,56(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// stw r8,56(r11)
	REX_STORE_U32(ctx.r11.u32 + 56, ctx.r8.u32);
	// lwz r8,88(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// stw r7,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r7.u32);
	// beq cr6,0x82218d10
	if (ctx.cr6.eq) goto loc_82218D10;
	// stw r9,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// b 0x82218d14
	goto loc_82218D14;
loc_82218D10:
	// stw r9,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
loc_82218D14:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82218d24
	if (ctx.cr6.eq) goto loc_82218D24;
	// stw r10,32(r9)
	REX_STORE_U32(ctx.r9.u32 + 32, ctx.r10.u32);
	// b 0x82218d28
	goto loc_82218D28;
loc_82218D24:
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
loc_82218D28:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r28,16(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r28,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r28.u32);
	// stw r11,20(r28)
	REX_STORE_U32(ctx.r28.u32 + 20, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// beq cr6,0x82218d5c
	if (ctx.cr6.eq) goto loc_82218D5C;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
loc_82218D5C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82218D74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// stw r30,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// stw r30,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// stw r30,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stw r30,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// stw r30,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// stw r30,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// lwz r9,116(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 116);
	// stw r9,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// stw r31,116(r29)
	REX_STORE_U32(ctx.r29.u32 + 116, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82220168) {
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
	// bl 0x82218220
	ctx.lr = 0x82220180;
	sub_82218220(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,12332
	ctx.r7.s64 = ctx.r11.s64 + 12332;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r7,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r7.u32);
	// addi r5,r10,12260
	ctx.r5.s64 = ctx.r10.s64 + 12260;
	// addi r4,r9,31556
	ctx.r4.s64 = ctx.r9.s64 + 31556;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// addi r3,r8,31548
	ctx.r3.s64 = ctx.r8.s64 + 31548;
	// stw r5,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r5.u32);
	// addi r9,r6,31400
	ctx.r9.s64 = ctx.r6.s64 + 31400;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r10,r31,84
	ctx.r10.s64 = ctx.r31.s64 + 84;
	// stw r11,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// stw r9,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r9.u32);
	// stw r11,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// stw r11,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// stw r9,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r9.u32);
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// stw r11,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
	// stw r11,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r11.u32);
	// stw r11,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// stw r11,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// stw r9,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r9.u32);
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// stw r11,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// stw r11,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// stw r11,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r11.u32);
	// stw r9,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r9.u32);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// stw r11,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// stw r11,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82224738) {
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
	// addi r9,r11,32460
	ctx.r9.s64 = ctx.r11.s64 + 32460;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8222476c
	if (ctx.cr6.eq) goto loc_8222476C;
	// bl 0x82573808
	ctx.lr = 0x82224768;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8222476C:
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

DEFINE_REX_FUNC(sub_82225740) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-96
	ctx.r3.s64 = ctx.r3.s64 + -96;
	// b 0x82225790
	sub_82225790(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82225948) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-96
	ctx.r3.s64 = ctx.r3.s64 + -96;
	// b 0x82225950
	sub_82225950(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82225BD8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-96
	ctx.r3.s64 = ctx.r3.s64 + -96;
	// b 0x82225be0
	sub_82225BE0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82225E48) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-96
	ctx.r3.s64 = ctx.r3.s64 + -96;
	// b 0x82225e50
	sub_82225E50(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82226138) {
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
	ctx.lr = 0x82226150;
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
	ctx.lr = 0x82226170;
	sub_8223F7C0(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// addi r5,r7,-22692
	ctx.r5.s64 = ctx.r7.s64 + -22692;
	// addi r4,r6,-22700
	ctx.r4.s64 = ctx.r6.s64 + -22700;
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r4.u32);
	// bl 0x823a9f58
	ctx.lr = 0x82226190;
	sub_823A9F58(ctx, base);
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

DEFINE_REX_FUNC(sub_82227E80) {
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
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// cmpwi cr6,r11,59
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 59, ctx.xer);
	// blt cr6,0x82227ecc
	if (ctx.cr6.lt) goto loc_82227ECC;
	// lis r10,-32222
	ctx.r10.s64 = -2111700992;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,32288
	ctx.r8.s64 = ctx.r10.s64 + 32288;
	// addi r6,r9,-16835
	ctx.r6.s64 = ctx.r9.s64 + -16835;
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
	ctx.lr = 0x82227ECC;
	sub_822518D8(ctx, base);
loc_82227ECC:
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

DEFINE_REX_FUNC(sub_8222B118) {
	REX_FUNC_PROLOGUE();
	// lwz r11,248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8222b138
	if (ctx.cr6.eq) goto loc_8222B138;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,252(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 252);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8222b13c
	if (ctx.cr6.eq) goto loc_8222B13C;
loc_8222B138:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8222B13C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8222b160
	if (ctx.cr6.eq) goto loc_8222B160;
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
	// bne cr6,0x8222b164
	if (!ctx.cr6.eq) goto loc_8222B164;
loc_8222B160:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8222B164:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x821905c8
	sub_821905C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8222C2B0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,200(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8222c2d0
	if (ctx.cr6.eq) goto loc_8222C2D0;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,204(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8222c2d4
	if (ctx.cr6.eq) goto loc_8222C2D4;
loc_8222C2D0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8222C2D4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8222c2f8
	if (ctx.cr6.eq) goto loc_8222C2F8;
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
	// bne cr6,0x8222c2fc
	if (!ctx.cr6.eq) goto loc_8222C2FC;
loc_8222C2F8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8222C2FC:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x82233240
	sub_82233240(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8222DB38) {
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
	// bl 0x82218220
	ctx.lr = 0x8222DB50;
	sub_82218220(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// addi r9,r11,-16364
	ctx.r9.s64 = ctx.r11.s64 + -16364;
	// lis r8,-32141
	ctx.r8.s64 = -2106392576;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r6,r10,2288
	ctx.r6.s64 = ctx.r10.s64 + 2288;
	// addi r5,r8,876
	ctx.r5.s64 = ctx.r8.s64 + 876;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826a0b10
	ctx.lr = 0x8222DB7C;
	sub_826A0B10(ctx, base);
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// lwz r11,120(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// li r5,10003
	ctx.r5.s64 = 10003;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x8222dbd8
	if (ctx.cr6.gt) goto loc_8222DBD8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8222dbb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8222DBB4;
	// bdzf 4*cr6+eq,0x8222dbbc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8222DBBC;
	// bdzf 4*cr6+eq,0x8222dbc4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8222DBC4;
	// bdzf 4*cr6+eq,0x8222dbcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8222DBCC;
	// bne cr6,0x8222dbd4
	if (!ctx.cr6.eq) goto loc_8222DBD4;
	// li r5,10003
	ctx.r5.s64 = 10003;
	// b 0x8222dbd8
	goto loc_8222DBD8;
loc_8222DBB4:
	// li r5,10506
	ctx.r5.s64 = 10506;
	// b 0x8222dbd8
	goto loc_8222DBD8;
loc_8222DBBC:
	// li r5,11009
	ctx.r5.s64 = 11009;
	// b 0x8222dbd8
	goto loc_8222DBD8;
loc_8222DBC4:
	// li r5,11512
	ctx.r5.s64 = 11512;
	// b 0x8222dbd8
	goto loc_8222DBD8;
loc_8222DBCC:
	// li r5,12015
	ctx.r5.s64 = 12015;
	// b 0x8222dbd8
	goto loc_8222DBD8;
loc_8222DBD4:
	// li r5,12518
	ctx.r5.s64 = 12518;
loc_8222DBD8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,30044(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 30044);
	// bl 0x822189c8
	ctx.lr = 0x8222DBEC;
	sub_822189C8(ctx, base);
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

DEFINE_REX_FUNC(sub_822333D0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32117
	ctx.r11.s64 = -2104819712;
	// lwz r3,13876(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 13876);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822339D0) {
	REX_FUNC_PROLOGUE();
	// lwz r7,1948(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 1948);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x82233a54
	if (!ctx.cr6.gt) goto loc_82233A54;
loc_822339E0:
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bgt cr6,0x822339f0
	if (ctx.cr6.gt) goto loc_822339F0;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82233a38
	goto loc_82233A38;
loc_822339F0:
	// lwz r11,1888(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1888);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,10
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 10, ctx.xer);
	// bge cr6,0x82233a20
	if (!ctx.cr6.lt) goto loc_82233A20;
	// lwz r9,1952(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 1952);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,4(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// b 0x82233a34
	goto loc_82233A34;
loc_82233A20:
	// lwz r10,1952(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 1952);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
loc_82233A34:
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82233A38:
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82233a5c
	if (ctx.cr6.eq) goto loc_82233A5C;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x822339e0
	if (ctx.cr6.lt) goto loc_822339E0;
loc_82233A54:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82233A5C:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82237E88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82237E90;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,152
	ctx.r31.s64 = ctx.r3.s64 + 152;
	// li r30,72
	ctx.r30.s64 = 72;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
loc_82237EA0:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82237ec0
	if (ctx.cr6.eq) goto loc_82237EC0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82237ec4
	if (ctx.cr6.eq) goto loc_82237EC4;
loc_82237EC0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82237EC4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82237f18
	if (ctx.cr6.eq) goto loc_82237F18;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r9,30048(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// and r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82237f18
	if (ctx.cr6.eq) goto loc_82237F18;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82237f18
	if (ctx.cr6.eq) goto loc_82237F18;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82237f04
	if (ctx.cr6.eq) goto loc_82237F04;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82237F04:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// subfic r9,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r7,r10
	ctx.r3.u64 = ctx.r7.u64 & ctx.r10.u64;
	// bl 0x8220f998
	ctx.lr = 0x82237F18;
	sub_8220F998(ctx, base);
loc_82237F18:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// bne 0x82237ea0
	if (!ctx.cr0.eq) goto loc_82237EA0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8223B838) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-15916
	ctx.r9.s64 = ctx.r11.s64 + -15916;
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,8(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// stw r8,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// lwz r7,4(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r9,4(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// stw r8,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8223E960) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x8223E968;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// addi r30,r11,2288
	ctx.r30.s64 = ctx.r11.s64 + 2288;
	// addi r29,r10,876
	ctx.r29.s64 = ctx.r10.s64 + 876;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// bl 0x826a0b10
	ctx.lr = 0x8223E998;
	sub_826A0B10(ctx, base);
	// lwz r11,120(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 120);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bge cr6,0x8223ea04
	if (!ctx.cr6.lt) goto loc_8223EA04;
	// lis r3,1
	ctx.r3.s64 = 65536;
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
	// ori r3,r3,6304
	ctx.r3.u64 = ctx.r3.u64 | 6304;
	// bl 0x82219630
	ctx.lr = 0x8223E9C4;
	sub_82219630(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// beq cr6,0x8223e9fc
	if (ctx.cr6.eq) goto loc_8223E9FC;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x826a0b10
	ctx.lr = 0x8223E9E8;
	sub_826A0B10(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,120(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// bl 0x82465738
	ctx.lr = 0x8223E9F8;
	sub_82465738(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8223E9FC:
	// addi r3,r31,160
	ctx.r3.s64 = ctx.r31.s64 + 160;
	// bl 0x8226bf28
	ctx.lr = 0x8223EA04;
	sub_8226BF28(ctx, base);
loc_8223EA04:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82242998) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x822429A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x8238e4f8
	ctx.lr = 0x822429AC;
	sub_8238E4F8(ctx, base);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lis r29,-32256
	ctx.r29.s64 = -2113929216;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r31,r11,23664
	ctx.r31.s64 = ctx.r11.s64 + 23664;
	// beq cr6,0x82242a64
	if (ctx.cr6.eq) goto loc_82242A64;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822429e4
	if (ctx.cr6.eq) goto loc_822429E4;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822429e8
	if (ctx.cr6.eq) goto loc_822429E8;
loc_822429E4:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_822429E8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,30048(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82242a08
	if (ctx.cr6.eq) goto loc_82242A08;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82242a0c
	if (!ctx.cr6.eq) goto loc_82242A0C;
loc_82242A08:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82242A0C:
	// lwz r11,856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 856);
	// lwz r10,476(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 476);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82242a30
	if (ctx.cr6.eq) goto loc_82242A30;
	// lwz r7,480(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 480);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x82242a34
	if (ctx.cr6.eq) goto loc_82242A34;
loc_82242A30:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82242A34:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82242a50
	if (ctx.cr6.eq) goto loc_82242A50;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82242a54
	if (!ctx.cr6.eq) goto loc_82242A54;
loc_82242A50:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82242A54:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82230a58
	ctx.lr = 0x82242A5C;
	sub_82230A58(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82242b04
	if (ctx.cr6.eq) goto loc_82242B04;
loc_82242A64:
	// lbz r11,432(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82242a78
	if (!ctx.cr6.eq) goto loc_82242A78;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r11,432(r28)
	REX_STORE_U8(ctx.r28.u32 + 432, ctx.r11.u8);
loc_82242A78:
	// bl 0x8238e3b8
	ctx.lr = 0x82242A7C;
	sub_8238E3B8(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r4,352(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 352);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82242aa0
	if (ctx.cr6.eq) goto loc_82242AA0;
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82242aa4
	if (ctx.cr6.eq) goto loc_82242AA4;
loc_82242AA0:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82242AA4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82242ac4
	if (ctx.cr6.eq) goto loc_82242AC4;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82242ac8
	if (!ctx.cr6.eq) goto loc_82242AC8;
loc_82242AC4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82242AC8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,864(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 864);
	// bl 0x82269868
	ctx.lr = 0x82242AD4;
	sub_82269868(ctx, base);
	// lis r11,-32219
	ctx.r11.s64 = -2111504384;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r9,r11,-30312
	ctx.r9.s64 = ctx.r11.s64 + -30312;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r6,r10,-15623
	ctx.r6.s64 = ctx.r10.s64 + -15623;
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r28,96
	ctx.r3.s64 = ctx.r28.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x82242B04;
	sub_822518D8(ctx, base);
loc_82242B04:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82249D38) {
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
	// lis r31,-32104
	ctx.r31.s64 = -2103967744;
	// lwz r3,-17636(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + -17636);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82249d88
	if (!ctx.cr6.eq) goto loc_82249D88;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,196
	ctx.r3.s64 = 196;
	// bl 0x8223d420
	ctx.lr = 0x82249D70;
	sub_8223D420(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82249d80
	if (ctx.cr6.eq) goto loc_82249D80;
	// bl 0x82249848
	ctx.lr = 0x82249D7C;
	sub_82249848(ctx, base);
	// b 0x82249d84
	goto loc_82249D84;
loc_82249D80:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82249D84:
	// stw r3,-17636(r31)
	REX_STORE_U32(ctx.r31.u32 + -17636, ctx.r3.u32);
loc_82249D88:
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

DEFINE_REX_FUNC(sub_8224B6B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8224B6C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82219630
	ctx.lr = 0x8224B6E4;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8224b6f8
	if (ctx.cr6.eq) goto loc_8224B6F8;
	// bl 0x8224ab58
	ctx.lr = 0x8224B6F0;
	sub_8224AB58(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8224b6fc
	goto loc_8224B6FC;
loc_8224B6F8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8224B6FC:
	// addi r30,r31,84
	ctx.r30.s64 = ctx.r31.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8226bf28
	ctx.lr = 0x8224B708;
	sub_8226BF28(ctx, base);
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
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82219630
	ctx.lr = 0x8224B724;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8224b738
	if (ctx.cr6.eq) goto loc_8224B738;
	// bl 0x8224ac20
	ctx.lr = 0x8224B730;
	sub_8224AC20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8224b73c
	goto loc_8224B73C;
loc_8224B738:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8224B73C:
	// addi r29,r31,108
	ctx.r29.s64 = ctx.r31.s64 + 108;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8226bf28
	ctx.lr = 0x8224B748;
	sub_8226BF28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82218fa0
	ctx.lr = 0x8224B750;
	sub_82218FA0(ctx, base);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224b770
	if (ctx.cr6.eq) goto loc_8224B770;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8224b774
	if (ctx.cr6.eq) goto loc_8224B774;
loc_8224B770:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8224B774:
	// lis r31,-32256
	ctx.r31.s64 = -2113929216;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r8,30048(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 30048);
	// beq cr6,0x8224b798
	if (ctx.cr6.eq) goto loc_8224B798;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 & ctx.r8.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8224b79c
	if (!ctx.cr6.eq) goto loc_8224B79C;
loc_8224B798:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8224B79C:
	// lwz r10,16(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8224b7bc
	if (ctx.cr6.eq) goto loc_8224B7BC;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r7,20(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq cr6,0x8224b7c0
	if (ctx.cr6.eq) goto loc_8224B7C0;
loc_8224B7BC:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8224B7C0:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8224b7dc
	if (ctx.cr6.eq) goto loc_8224B7DC;
	// lwz r9,60(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8224b7e0
	if (!ctx.cr6.eq) goto loc_8224B7E0;
loc_8224B7DC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8224B7E0:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r10,84
	ctx.r3.s64 = ctx.r10.s64 + 84;
	// bl 0x8226bf28
	ctx.lr = 0x8224B7EC;
	sub_8226BF28(ctx, base);
	// lwz r10,16(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8224b80c
	if (ctx.cr6.eq) goto loc_8224B80C;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r9,20(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8224b810
	if (ctx.cr6.eq) goto loc_8224B810;
loc_8224B80C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8224B810:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r8,30048(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 30048);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224b830
	if (ctx.cr6.eq) goto loc_8224B830;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 & ctx.r8.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8224b834
	if (!ctx.cr6.eq) goto loc_8224B834;
loc_8224B830:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8224B834:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224b854
	if (ctx.cr6.eq) goto loc_8224B854;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r7,20(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// beq cr6,0x8224b858
	if (ctx.cr6.eq) goto loc_8224B858;
loc_8224B854:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8224B858:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8224b874
	if (ctx.cr6.eq) goto loc_8224B874;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8224b878
	if (!ctx.cr6.eq) goto loc_8224B878;
loc_8224B874:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8224B878:
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r11,84
	ctx.r3.s64 = ctx.r11.s64 + 84;
	// bl 0x8226bf28
	ctx.lr = 0x8224B884;
	sub_8226BF28(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82255E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// li r6,260
	ctx.r6.s64 = 260;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82255280
	ctx.lr = 0x82255E24;
	sub_82255280(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82516d80
	ctx.lr = 0x82255E2C;
	sub_82516D80(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82256FE0) {
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
	// lwz r11,192(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 192);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8225703c
	if (ctx.cr6.eq) goto loc_8225703C;
	// addi r3,r3,196
	ctx.r3.s64 = ctx.r3.s64 + 196;
	// bl 0x82517498
	ctx.lr = 0x82257008;
	sub_82517498(ctx, base);
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,28184
	ctx.r8.s64 = ctx.r10.s64 + 28184;
	// addi r6,r9,-12562
	ctx.r6.s64 = ctx.r9.s64 + -12562;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	ctx.lr = 0x8225703C;
	sub_822518D8(ctx, base);
loc_8225703C:
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

DEFINE_REX_FUNC(sub_82259598) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82513bb8
	ctx.lr = 0x822595B8;
	sub_82513BB8(ctx, base);
	// bl 0x82513308
	ctx.lr = 0x822595BC;
	sub_82513308(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,4280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4280);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f31,f0
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f13,4268(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,4272(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4272);
	ctx.f0.f64 = double(temp.f32);
	// fsel f11,f31,f13,f0
	ctx.f11.f64 = ctx.f31.f64 >= 0.0 ? ctx.f13.f64 : ctx.f0.f64;
	// lfs f0,4260(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4260);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f10,f12,f0,f11
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f11.f64)));
	// fctiwz f9,f10
	ctx.f9.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82513530
	ctx.lr = 0x822595F8;
	sub_82513530(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82513bc0
	ctx.lr = 0x82259600;
	sub_82513BC0(ctx, base);
	// bl 0x82524b40
	ctx.lr = 0x82259604;
	sub_82524B40(ctx, base);
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

DEFINE_REX_FUNC(sub_8225EB90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0278
	ctx.lr = 0x8225EB98;
	__savegprlr_20(ctx, base);
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8225ebc4
	if (!ctx.cr6.eq) goto loc_8225EBC4;
loc_8225EBB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x826a02c8
	__restgprlr_20(ctx, base);
	return;
loc_8225EBC4:
	// lwz r20,0(r21)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r22,0
	ctx.r22.s64 = 0;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x8225ecc4
	if (!ctx.cr6.gt) goto loc_8225ECC4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// addi r30,r3,4
	ctx.r30.s64 = ctx.r3.s64 + 4;
	// addi r24,r21,4
	ctx.r24.s64 = ctx.r21.s64 + 4;
	// lfs f31,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
loc_8225EBEC:
	// lwz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// add. r28,r11,r21
	ctx.r28.u64 = ctx.r11.u64 + ctx.r21.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x8225ebb4
	if (ctx.cr0.eq) goto loc_8225EBB4;
	// lwz r27,0(r28)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stw r26,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r26.u32);
	// stfs f31,4(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// rlwinm r11,r27,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r29,-4(r30)
	REX_STORE_U32(ctx.r30.u32 + -4, ctx.r29.u32);
	// li r31,0
	ctx.r31.s64 = 0;
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r27,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r27.u32);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x8225eca4
	if (!ctx.cr6.gt) goto loc_8225ECA4;
loc_8225EC24:
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// li r7,0
	ctx.r7.s64 = 0;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x8219d0f0
	ctx.lr = 0x8225EC48;
	sub_8219D0F0(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne cr6,0x8225ec90
	if (!ctx.cr6.eq) goto loc_8225EC90;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82514ea0
	ctx.lr = 0x8225EC60;
	sub_82514EA0(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r9,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,4(r30)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,0(r30)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
loc_8225EC90:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r31,r27
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x8225ec24
	if (ctx.cr6.lt) goto loc_8225EC24;
loc_8225ECA4:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// addi r24,r24,8
	ctx.r24.s64 = ctx.r24.s64 + 8;
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// cmpw cr6,r22,r20
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r20.s32, ctx.xer);
	// blt cr6,0x8225ebec
	if (ctx.cr6.lt) goto loc_8225EBEC;
	// cmpwi cr6,r25,10000
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 10000, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bge cr6,0x8225ecc8
	if (!ctx.cr6.lt) goto loc_8225ECC8;
loc_8225ECC4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8225ECC8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x826a02c8
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82267390) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,144(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r3
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8226769c
	if (ctx.cr6.eq) goto loc_8226769C;
	// lwz r6,32(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// cmpwi cr6,r6,13
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 13, ctx.xer);
	// beq cr6,0x822673cc
	if (ctx.cr6.eq) goto loc_822673CC;
	// rlwinm r11,r7,0,8,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xF00000;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822673d0
	if (!ctx.cr6.eq) goto loc_822673D0;
loc_822673CC:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822673D0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// clrlwi r11,r7,26
	ctx.r11.u64 = ctx.r7.u32 & 0x3F;
	// addi r9,r10,-10160
	ctx.r9.s64 = ctx.r10.s64 + -10160;
	// addi r10,r9,-144
	ctx.r10.s64 = ctx.r9.s64 + -144;
	// beq cr6,0x822673ec
	if (ctx.cr6.eq) goto loc_822673EC;
	// addi r10,r9,-72
	ctx.r10.s64 = ctx.r9.s64 + -72;
loc_822673EC:
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82267418
	if (ctx.cr6.eq) goto loc_82267418;
	// lwz r4,0(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// addi r31,r9,4
	ctx.r31.s64 = ctx.r9.s64 + 4;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r4,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | ctx.r30.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
loc_82267418:
	// lwz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82267444
	if (ctx.cr6.eq) goto loc_82267444;
	// lwz r4,4(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// addi r31,r9,4
	ctx.r31.s64 = ctx.r9.s64 + 4;
	// lwz r30,12(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r4,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | ctx.r30.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
loc_82267444:
	// lwz r4,16(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82267470
	if (ctx.cr6.eq) goto loc_82267470;
	// lwz r4,8(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// addi r31,r9,4
	ctx.r31.s64 = ctx.r9.s64 + 4;
	// lwz r30,20(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r4,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | ctx.r30.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
loc_82267470:
	// lwz r4,24(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8226749c
	if (ctx.cr6.eq) goto loc_8226749C;
	// lwz r4,12(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// addi r31,r9,4
	ctx.r31.s64 = ctx.r9.s64 + 4;
	// lwz r30,28(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r4,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | ctx.r30.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
loc_8226749C:
	// lwz r4,32(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x822674c8
	if (ctx.cr6.eq) goto loc_822674C8;
	// lwz r4,16(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 16);
	// addi r31,r9,4
	ctx.r31.s64 = ctx.r9.s64 + 4;
	// lwz r30,36(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r4,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | ctx.r30.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
loc_822674C8:
	// lwz r4,40(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x822674f4
	if (ctx.cr6.eq) goto loc_822674F4;
	// lwz r4,20(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 20);
	// addi r31,r9,4
	ctx.r31.s64 = ctx.r9.s64 + 4;
	// lwz r30,44(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r4,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | ctx.r30.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
loc_822674F4:
	// lwz r4,48(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82267520
	if (ctx.cr6.eq) goto loc_82267520;
	// lwz r4,24(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 24);
	// addi r31,r9,4
	ctx.r31.s64 = ctx.r9.s64 + 4;
	// lwz r30,52(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 52);
	// rlwinm r4,r4,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r4,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// or r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 | ctx.r30.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
loc_82267520:
	// lwz r4,56(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 56);
	// and r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8226754c
	if (ctx.cr6.eq) goto loc_8226754C;
	// lwz r8,28(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// addi r4,r9,4
	ctx.r4.s64 = ctx.r9.s64 + 4;
	// lwz r31,60(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// rlwinm r8,r8,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r4,r8,r4
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r4.u32);
	// or r8,r4,r31
	ctx.r8.u64 = ctx.r4.u64 | ctx.r31.u64;
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
loc_8226754C:
	// lwz r8,64(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// and r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82267574
	if (ctx.cr6.eq) goto loc_82267574;
	// lwz r4,68(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// rlwinm r8,r6,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
	// lwzx r9,r8,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// or r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 | ctx.r4.u64;
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
loc_82267574:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82267584
	if (ctx.cr6.eq) goto loc_82267584;
	// rlwinm r11,r11,0,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// b 0x822675c4
	goto loc_822675C4;
loc_82267584:
	// clrlwi r10,r7,31
	ctx.r10.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82267594
	if (ctx.cr6.eq) goto loc_82267594;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
loc_82267594:
	// rlwinm r10,r7,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822675a4
	if (ctx.cr6.eq) goto loc_822675A4;
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
loc_822675A4:
	// rlwinm r10,r7,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822675b4
	if (ctx.cr6.eq) goto loc_822675B4;
	// oris r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 4194304;
loc_822675B4:
	// rlwinm r10,r7,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822675c4
	if (ctx.cr6.eq) goto loc_822675C4;
	// oris r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 8388608;
loc_822675C4:
	// rlwinm r10,r7,0,8,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x800000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822675d4
	if (ctx.cr6.eq) goto loc_822675D4;
	// oris r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 8388608;
loc_822675D4:
	// rlwinm r9,r7,0,9,9
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x822675e4
	if (ctx.cr6.eq) goto loc_822675E4;
	// oris r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 4194304;
loc_822675E4:
	// rlwinm r8,r7,0,11,11
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822675f4
	if (ctx.cr6.eq) goto loc_822675F4;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
loc_822675F4:
	// rlwinm r7,r7,0,10,10
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82267604
	if (ctx.cr6.eq) goto loc_82267604;
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
loc_82267604:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x822676a0
	if (ctx.cr6.eq) goto loc_822676A0;
	// cmpwi cr6,r6,14
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 14, ctx.xer);
	// beq cr6,0x8226765c
	if (ctx.cr6.eq) goto loc_8226765C;
	// cmpwi cr6,r6,15
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 15, ctx.xer);
	// bne cr6,0x822676a0
	if (!ctx.cr6.eq) goto loc_822676A0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82267628
	if (ctx.cr6.eq) goto loc_82267628;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
loc_82267628:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82267634
	if (ctx.cr6.eq) goto loc_82267634;
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
loc_82267634:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82267640
	if (ctx.cr6.eq) goto loc_82267640;
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
loc_82267640:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x822676a0
	if (ctx.cr6.eq) goto loc_822676A0;
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// stw r11,288(r3)
	REX_STORE_U32(ctx.r3.u32 + 288, ctx.r11.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8226765C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82267668
	if (ctx.cr6.eq) goto loc_82267668;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
loc_82267668:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82267674
	if (ctx.cr6.eq) goto loc_82267674;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
loc_82267674:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82267680
	if (ctx.cr6.eq) goto loc_82267680;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
loc_82267680:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x822676a0
	if (ctx.cr6.eq) goto loc_822676A0;
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r11,288(r3)
	REX_STORE_U32(ctx.r3.u32 + 288, ctx.r11.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8226769C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822676A0:
	// stw r11,288(r3)
	REX_STORE_U32(ctx.r3.u32 + 288, ctx.r11.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82278F38) {
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
	// bl 0x82278e98
	ctx.lr = 0x82278F50;
	sub_82278E98(ctx, base);
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

DEFINE_REX_FUNC(sub_82279670) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82279678;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x822791b0
	ctx.lr = 0x8227968C;
	sub_822791B0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8227969c
	if (!ctx.cr6.eq) goto loc_8227969C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_8227969C:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82279370
	ctx.lr = 0x822796AC;
	sub_82279370(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8227A4E0) {
	REX_FUNC_PROLOGUE();
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r5,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// stw r6,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// b 0x82279ed8
	sub_82279ED8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8227A860) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x8227A868;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,-1
	ctx.r11.s64 = -1;
	// addi r31,r4,4
	ctx.r31.s64 = ctx.r4.s64 + 4;
	// stw r11,28(r4)
	REX_STORE_U32(ctx.r4.u32 + 28, ctx.r11.u32);
	// stw r11,32(r4)
	REX_STORE_U32(ctx.r4.u32 + 32, ctx.r11.u32);
	// addi r30,r31,24
	ctx.r30.s64 = ctx.r31.s64 + 24;
	// stw r11,36(r4)
	REX_STORE_U32(ctx.r4.u32 + 36, ctx.r11.u32);
	// lwz r3,12(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x8226a320
	ctx.lr = 0x8227A88C;
	sub_8226A320(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8227a954
	if (ctx.cr6.eq) goto loc_8227A954;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8227a8c0
	if (ctx.cr6.eq) goto loc_8227A8C0;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8227a8c4
	if (ctx.cr6.eq) goto loc_8227A8C4;
loc_8227A8C0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8227A8C4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8227a8e8
	if (ctx.cr6.eq) goto loc_8227A8E8;
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
	// bne cr6,0x8227a8ec
	if (!ctx.cr6.eq) goto loc_8227A8EC;
loc_8227A8E8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8227A8EC:
	// lwz r3,864(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 864);
	// bl 0x822699f8
	ctx.lr = 0x8227A8F4;
	sub_822699F8(ctx, base);
	// bl 0x8227c220
	ctx.lr = 0x8227A8F8;
	sub_8227C220(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8227a920
	if (ctx.cr6.lt) goto loc_8227A920;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// bl 0x822798c8
	ctx.lr = 0x8227A918;
	sub_822798C8(ctx, base);
	// stw r3,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// b 0x8227a928
	goto loc_8227A928;
loc_8227A920:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8227A928:
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// addi r30,r30,-4
	ctx.r30.s64 = ctx.r30.s64 + -4;
	// li r31,3
	ctx.r31.s64 = 3;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
loc_8227A938:
	// lwz r11,-8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x82276378
	ctx.lr = 0x8227A948;
	sub_82276378(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stwu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r30.u32 = ea;
	// bne 0x8227a938
	if (!ctx.cr0.eq) goto loc_8227A938;
loc_8227A954:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82280058) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp v12,v13,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82281AD0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82281AD8;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,340(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 340);
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// addi r30,r11,-16656
	ctx.r30.s64 = ctx.r11.s64 + -16656;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r29,r10,876
	ctx.r29.s64 = ctx.r10.s64 + 876;
	// lwz r11,68(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 68);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r9,r11,32
	ctx.r9.s64 = ctx.r11.s64 + 32;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r25,84(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r24,344(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r28,r11,r27
	ctx.r28.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x826a0b10
	ctx.lr = 0x82281B24;
	sub_826A0B10(ctx, base);
	// stw r3,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826a0b10
	ctx.lr = 0x82281B40;
	sub_826A0B10(ctx, base);
	// addi r8,r3,64
	ctx.r8.s64 = ctx.r3.s64 + 64;
	// stw r8,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r8.u32);
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281b68
	if (ctx.cr6.eq) goto loc_82281B68;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,116(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82281b6c
	if (ctx.cr6.eq) goto loc_82281B6C;
loc_82281B68:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82281B6C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r10,30048(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 30048);
	// beq cr6,0x82281b94
	if (ctx.cr6.eq) goto loc_82281B94;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82281b98
	if (!ctx.cr6.eq) goto loc_82281B98;
loc_82281B94:
	// li r26,0
	ctx.r26.s64 = 0;
loc_82281B98:
	// lwz r30,256(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82281bb8
	if (ctx.cr6.eq) goto loc_82281BB8;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,260(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82281bbc
	if (ctx.cr6.eq) goto loc_82281BBC;
loc_82281BB8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82281BBC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82281bd8
	if (ctx.cr6.eq) goto loc_82281BD8;
	// lwz r11,60(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 60);
	// and r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82281bdc
	if (!ctx.cr6.eq) goto loc_82281BDC;
loc_82281BD8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82281BDC:
	// lwz r11,64(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82281c3c
	if (!ctx.cr6.gt) goto loc_82281C3C;
loc_82281BEC:
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
	// li r3,416
	ctx.r3.s64 = 416;
	// bl 0x82219630
	ctx.lr = 0x82281C08;
	sub_82219630(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82281c28
	if (ctx.cr6.eq) goto loc_82281C28;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82281990
	ctx.lr = 0x82281C28;
	sub_82281990(ctx, base);
loc_82281C28:
	// lwz r11,64(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 64);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82281bec
	if (ctx.cr6.lt) goto loc_82281BEC;
loc_82281C3C:
	// lwz r11,12(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82281c78
	if (ctx.cr6.eq) goto loc_82281C78;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r25,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// bl 0x82281540
	ctx.lr = 0x82281C64;
	sub_82281540(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82281c78
	if (ctx.cr6.eq) goto loc_82281C78;
	// lwz r11,316(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 316);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,316(r30)
	REX_STORE_U32(ctx.r30.u32 + 316, ctx.r11.u32);
loc_82281C78:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82281C8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82294A80) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82294ac4
	if (!ctx.cr6.eq) goto loc_82294AC4;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82294ac4
	if (!ctx.cr6.eq) goto loc_82294AC4;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82294ac4
	if (!ctx.cr6.eq) goto loc_82294AC4;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82294ac8
	if (ctx.cr6.eq) goto loc_82294AC8;
loc_82294AC4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82294AC8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82298698) {
	REX_FUNC_PROLOGUE();
	// lwz r10,260(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 260);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r10,63
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 63, ctx.xer);
	// lwzx r3,r8,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// stw r10,260(r11)
	REX_STORE_U32(ctx.r11.u32 + 260, ctx.r10.u32);
	// bge cr6,0x822986cc
	if (!ctx.cr6.lt) goto loc_822986CC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,260(r11)
	REX_STORE_U32(ctx.r11.u32 + 260, ctx.r10.u32);
	// stw r10,260(r11)
	REX_STORE_U32(ctx.r11.u32 + 260, ctx.r10.u32);
	// blr 
	return;
loc_822986CC:
	// li r10,63
	ctx.r10.s64 = 63;
	// stw r10,260(r11)
	REX_STORE_U32(ctx.r11.u32 + 260, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8229A928) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x8229A930;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// addi r29,r11,-12664
	ctx.r29.s64 = ctx.r11.s64 + -12664;
	// lwz r11,-12664(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12664);
	// lwz r3,3120(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 3120);
	// bl 0x8222b690
	ctx.lr = 0x8229A948;
	sub_8222B690(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,3120(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 3120);
	// bl 0x8222b690
	ctx.lr = 0x8229A954;
	sub_8222B690(ctx, base);
	// bl 0x822d1838
	ctx.lr = 0x8229A958;
	sub_822D1838(ctx, base);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lis r27,-32256
	ctx.r27.s64 = -2113929216;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r28,r11,23664
	ctx.r28.s64 = ctx.r11.s64 + 23664;
	// bne cr6,0x8229a9dc
	if (!ctx.cr6.eq) goto loc_8229A9DC;
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229a98c
	if (ctx.cr6.eq) goto loc_8229A98C;
	// lwz r10,20(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8229a990
	if (ctx.cr6.eq) goto loc_8229A990;
loc_8229A98C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8229A990:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8229a9b0
	if (ctx.cr6.eq) goto loc_8229A9B0;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8229a9b4
	if (!ctx.cr6.eq) goto loc_8229A9B4;
loc_8229A9B0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8229A9B4:
	// lwz r3,860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// bl 0x821c8320
	ctx.lr = 0x8229A9BC;
	sub_821C8320(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8229aaa0
	if (ctx.cr6.eq) goto loc_8229AAA0;
	// bl 0x82170cb0
	ctx.lr = 0x8229A9C8;
	sub_82170CB0(ctx, base);
	// lwz r3,860(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 860);
	// bl 0x821c8320
	ctx.lr = 0x8229A9D0;
	sub_821C8320(ctx, base);
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229aaa0
	if (ctx.cr6.eq) goto loc_8229AAA0;
loc_8229A9DC:
	// lwz r30,30048(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// li r31,48
	ctx.r31.s64 = 48;
loc_8229A9E4:
	// bl 0x82170cb0
	ctx.lr = 0x8229A9E8;
	sub_82170CB0(ctx, base);
	// lwz r11,856(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 856);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r10,428(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 428);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8229aa10
	if (ctx.cr6.eq) goto loc_8229AA10;
	// lwz r8,432(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 432);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8229aa14
	if (ctx.cr6.eq) goto loc_8229AA14;
loc_8229AA10:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8229AA14:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229aa94
	if (ctx.cr6.eq) goto loc_8229AA94;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 & ctx.r30.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8229aa94
	if (ctx.cr6.eq) goto loc_8229AA94;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8229aa94
	if (ctx.cr6.eq) goto loc_8229AA94;
	// bl 0x82170cb0
	ctx.lr = 0x8229AA3C;
	sub_82170CB0(ctx, base);
	// lwz r11,856(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 856);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r10,428(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 428);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8229aa64
	if (ctx.cr6.eq) goto loc_8229AA64;
	// lwz r8,432(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 432);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8229aa68
	if (ctx.cr6.eq) goto loc_8229AA68;
loc_8229AA64:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8229AA68:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229aa84
	if (ctx.cr6.eq) goto loc_8229AA84;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 & ctx.r30.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8229aa88
	if (!ctx.cr6.eq) goto loc_8229AA88;
loc_8229AA84:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8229AA88:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x8222b690
	ctx.lr = 0x8229AA90;
	sub_8222B690(ctx, base);
	// lwz r30,30048(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
loc_8229AA94:
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// cmpwi cr6,r31,120
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 120, ctx.xer);
	// blt cr6,0x8229a9e4
	if (ctx.cr6.lt) goto loc_8229A9E4;
loc_8229AAA0:
	// bl 0x822d1838
	ctx.lr = 0x8229AAA4;
	sub_822D1838(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8229ab00
	if (ctx.cr6.eq) goto loc_8229AB00;
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229aacc
	if (ctx.cr6.eq) goto loc_8229AACC;
	// lwz r10,20(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8229aad0
	if (ctx.cr6.eq) goto loc_8229AAD0;
loc_8229AACC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8229AAD0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8229aaf0
	if (ctx.cr6.eq) goto loc_8229AAF0;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8229aaf4
	if (!ctx.cr6.eq) goto loc_8229AAF4;
loc_8229AAF0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8229AAF4:
	// lwz r3,860(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// bl 0x821c8060
	ctx.lr = 0x8229AAFC;
	sub_821C8060(ctx, base);
	// bl 0x821ce180
	ctx.lr = 0x8229AB00;
	sub_821CE180(ctx, base);
loc_8229AB00:
	// lwz r4,4(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x822c7a70
	ctx.lr = 0x8229AB0C;
	sub_822C7A70(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82171158
	ctx.lr = 0x8229AB14;
	sub_82171158(ctx, base);
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x82171158
	ctx.lr = 0x8229AB1C;
	sub_82171158(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822AEBB8) {
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
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,38
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 38, ctx.xer);
	// bge cr6,0x822aebf8
	if (!ctx.cr6.lt) goto loc_822AEBF8;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r9,25976
	ctx.r11.s64 = ctx.r9.s64 + 25976;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// b 0x822aec00
	goto loc_822AEC00;
loc_822AEBF8:
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// addi r31,r11,-8048
	ctx.r31.s64 = ctx.r11.s64 + -8048;
loc_822AEC00:
	// lwz r11,120(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 120);
	// cmplwi cr6,r11,18
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 18, ctx.xer);
	// bne cr6,0x822aec20
	if (!ctx.cr6.eq) goto loc_822AEC20;
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// addi r3,r30,688
	ctx.r3.s64 = ctx.r30.s64 + 688;
	// addi r4,r11,17192
	ctx.r4.s64 = ctx.r11.s64 + 17192;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x826a1130
	ctx.lr = 0x822AEC20;
	rexcrt_memcpy(ctx, base);
loc_822AEC20:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,692(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 692);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,11152(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11152);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,80(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// lfs f11,688(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 688);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f10,84(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// lfs f9,700(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 700);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f8,88(r31)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// lfs f7,696(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 696);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// stfs f6,92(r31)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r31.u32 + 92, temp.u32);
	// lfs f5,708(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 708);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// stfs f4,96(r31)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// lfs f3,704(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 704);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// stfs f2,100(r31)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// lfs f1,716(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 716);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,104(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 104, temp.u32);
	// lfs f12,712(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 712);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f11,108(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 108, temp.u32);
	// lfs f10,708(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 708);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f9,112(r31)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// lfs f8,704(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 704);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f7,116(r31)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
	// lfs f6,716(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 716);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// stfs f5,120(r31)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// lfs f4,712(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 712);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// stfs f3,124(r31)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r31.u32 + 124, temp.u32);
	// lfs f2,724(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 724);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// stfs f1,128(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lfs f13,720(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 720);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,132(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// lfs f11,732(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 732);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f10,136(r31)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 136, temp.u32);
	// lfs f9,728(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 728);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f8,140(r31)
	temp.f32 = float(ctx.f8.f64);
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

DEFINE_REX_FUNC(sub_822B7BB8) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822B8598) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b85b4
	if (ctx.cr6.eq) goto loc_822B85B4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_822B85B4:
	// rlwinm r8,r11,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b85c4
	if (ctx.cr6.eq) goto loc_822B85C4;
	// li r10,2
	ctx.r10.s64 = 2;
loc_822B85C4:
	// rlwinm r8,r11,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b85d4
	if (ctx.cr6.eq) goto loc_822B85D4;
	// li r10,3
	ctx.r10.s64 = 3;
loc_822B85D4:
	// rlwinm r8,r11,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b85e4
	if (ctx.cr6.eq) goto loc_822B85E4;
	// li r10,4
	ctx.r10.s64 = 4;
loc_822B85E4:
	// rlwinm r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b85f4
	if (ctx.cr6.eq) goto loc_822B85F4;
	// li r10,5
	ctx.r10.s64 = 5;
loc_822B85F4:
	// rlwinm r8,r11,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b8604
	if (ctx.cr6.eq) goto loc_822B8604;
	// li r10,6
	ctx.r10.s64 = 6;
loc_822B8604:
	// rlwinm r8,r11,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b8614
	if (ctx.cr6.eq) goto loc_822B8614;
	// li r10,7
	ctx.r10.s64 = 7;
loc_822B8614:
	// rlwinm r8,r11,0,23,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b8624
	if (ctx.cr6.eq) goto loc_822B8624;
	// li r10,8
	ctx.r10.s64 = 8;
loc_822B8624:
	// rlwinm r11,r11,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822b8634
	if (ctx.cr6.eq) goto loc_822B8634;
	// li r10,9
	ctx.r10.s64 = 9;
loc_822B8634:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b8648
	if (ctx.cr6.eq) goto loc_822B8648;
	// li r9,16384
	ctx.r9.s64 = 16384;
loc_822B8648:
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b865c
	if (ctx.cr6.eq) goto loc_822B865C;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
loc_822B865C:
	// rlwinm r8,r11,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x822b8670
	if (ctx.cr6.eq) goto loc_822B8670;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// ori r9,r9,4096
	ctx.r9.u64 = ctx.r9.u64 | 4096;
loc_822B8670:
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822b8684
	if (ctx.cr6.eq) goto loc_822B8684;
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// ori r9,r11,8192
	ctx.r9.u64 = ctx.r11.u64 | 8192;
loc_822B8684:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// rlwinm r10,r10,1,27,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1E;
	// addi r8,r11,-2824
	ctx.r8.s64 = ctx.r11.s64 + -2824;
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lhzx r6,r10,r8
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r8.u32);
	// or r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 | ctx.r7.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822BD488) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x822BD490;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32110
	ctx.r29.s64 = -2104360960;
	// lis r31,-32110
	ctx.r31.s64 = -2104360960;
	// lwz r11,4320(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4320);
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r11,908(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 908);
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x822bda84
	if (!ctx.cr6.eq) goto loc_822BDA84;
	// lwz r11,980(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 980);
	// rlwinm r10,r11,0,21,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FC;
	// rlwinm r10,r10,0,29,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC07;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822bda84
	if (ctx.cr6.eq) goto loc_822BDA84;
	// bl 0x822b97c0
	ctx.lr = 0x822BD4CC;
	sub_822B97C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822bda84
	if (!ctx.cr6.eq) goto loc_822BDA84;
	// lwz r11,964(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 964);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x822bd4f4
	if (ctx.cr6.lt) goto loc_822BD4F4;
	// lwz r11,968(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 968);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,968(r8)
	REX_STORE_U32(ctx.r8.u32 + 968, ctx.r11.u32);
	// b 0x822bd4f8
	goto loc_822BD4F8;
loc_822BD4F4:
	// stw r28,968(r8)
	REX_STORE_U32(ctx.r8.u32 + 968, ctx.r28.u32);
loc_822BD4F8:
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x822bbd08
	ctx.lr = 0x822BD500;
	sub_822BBD08(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x822bd580
	if (ctx.cr6.eq) goto loc_822BD580;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r9,156(r11)
	REX_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r8,156(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bge cr6,0x822bd570
	if (!ctx.cr6.lt) goto loc_822BD570;
	// bl 0x822988a0
	ctx.lr = 0x822BD538;
	sub_822988A0(ctx, base);
	// clrlwi r10,r3,30
	ctx.r10.u64 = ctx.r3.u32 & 0x3;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,500
	ctx.r8.s64 = ctx.r10.s64 + 500;
	// ori r7,r9,32768
	ctx.r7.u64 = ctx.r9.u64 | 32768;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,1
	ctx.r3.s64 = 1;
	// lhzx r5,r6,r11
	ctx.r5.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r11.u32);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// stw r4,156(r11)
	REX_STORE_U32(ctx.r11.u32 + 156, ctx.r4.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD570:
	// stw r28,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD580:
	// lwz r11,4320(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4320);
	// lwz r10,4300(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r11,264(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 264);
	// stw r11,132(r10)
	REX_STORE_U32(ctx.r10.u32 + 132, ctx.r11.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r28,172(r11)
	REX_STORE_U32(ctx.r11.u32 + 172, ctx.r28.u32);
	// bl 0x822b9e30
	ctx.lr = 0x822BD59C;
	sub_822B9E30(ctx, base);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r3,168(r11)
	REX_STORE_U32(ctx.r11.u32 + 168, ctx.r3.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r10,168(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x822bd5c4
	if (ctx.cr6.gt) goto loc_822BD5C4;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD5C4:
	// li r27,1
	ctx.r27.s64 = 1;
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r27,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r27.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,16
	ctx.r8.s64 = 16;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r28,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r28.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r28,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r28.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r9,104(r11)
	REX_STORE_U32(ctx.r11.u32 + 104, ctx.r9.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r8,200(r11)
	REX_STORE_U32(ctx.r11.u32 + 200, ctx.r8.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r10,972(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 972);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,972(r11)
	REX_STORE_U32(ctx.r11.u32 + 972, ctx.r7.u32);
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r6,972(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 972);
	// cmpwi cr6,r6,180
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 180, ctx.xer);
	// blt cr6,0x822bd628
	if (ctx.cr6.lt) goto loc_822BD628;
	// li r30,63
	ctx.r30.s64 = 63;
	// b 0x822bd860
	goto loc_822BD860;
loc_822BD628:
	// lwz r6,992(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 992);
	// lis r30,-32110
	ctx.r30.s64 = -2104360960;
	// rlwinm r11,r6,0,10,10
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r7,4324(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 4324);
	// beq cr6,0x822bd650
	if (ctx.cr6.eq) goto loc_822BD650;
	// lwz r11,264(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 264);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x822bd66c
	if (ctx.cr6.eq) goto loc_822BD66C;
loc_822BD650:
	// lwz r11,996(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 996);
	// cmplwi cr6,r11,1799
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1799, ctx.xer);
	// bne cr6,0x822bd69c
	if (!ctx.cr6.eq) goto loc_822BD69C;
	// lwz r11,988(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 988);
	// rlwinm r10,r11,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x822bd69c
	if (!ctx.cr6.eq) goto loc_822BD69C;
loc_822BD66C:
	// lwz r11,264(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 264);
	// lwz r10,196(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 196);
	// lwz r9,80(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x822bd69c
	if (!ctx.cr6.gt) goto loc_822BD69C;
	// bl 0x822b9ba8
	ctx.lr = 0x822BD684;
	sub_822B9BA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822bd69c
	if (!ctx.cr6.eq) goto loc_822BD69C;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD69C:
	// rlwinm r11,r6,0,11,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x100000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822bd8d0
	if (!ctx.cr6.eq) goto loc_822BD8D0;
	// lwz r11,264(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 264);
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x822bd800
	if (ctx.cr6.eq) goto loc_822BD800;
	// lwz r10,844(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 844);
	// cmpwi cr6,r10,12
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 12, ctx.xer);
	// bge cr6,0x822bd7e4
	if (!ctx.cr6.lt) goto loc_822BD7E4;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r10,196(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 196);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x822bd7e4
	if (ctx.cr6.lt) goto loc_822BD7E4;
	// lwz r11,996(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 996);
	// cmplwi cr6,r11,271
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 271, ctx.xer);
	// beq cr6,0x822bd740
	if (ctx.cr6.eq) goto loc_822BD740;
	// lwz r11,988(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 988);
	// rlwinm r10,r11,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x822bd740
	if (!ctx.cr6.eq) goto loc_822BD740;
	// lwz r11,32(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x822bd734
	if (!ctx.cr6.lt) goto loc_822BD734;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x822bd710
	if (ctx.cr6.lt) goto loc_822BD710;
	// lwz r11,48(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 48);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bgt cr6,0x822bd734
	if (ctx.cr6.gt) goto loc_822BD734;
loc_822BD710:
	// bl 0x822988a0
	ctx.lr = 0x822BD714;
	sub_822988A0(ctx, base);
	// clrlwi r11,r3,28
	ctx.r11.u64 = ctx.r3.u32 & 0xF;
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// li r10,3
	ctx.r10.s64 = 3;
	// subfic r9,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r6,r10
	ctx.r30.u64 = ctx.r6.u64 & ctx.r10.u64;
	// stw r28,68(r8)
	REX_STORE_U32(ctx.r8.u32 + 68, ctx.r28.u32);
	// b 0x822bd8c4
	goto loc_822BD8C4;
loc_822BD734:
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// stw r28,68(r8)
	REX_STORE_U32(ctx.r8.u32 + 68, ctx.r28.u32);
	// b 0x822bd8c4
	goto loc_822BD8C4;
loc_822BD740:
	// lhz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r8.u32 + 4);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x822bd7dc
	if (!ctx.cr6.eq) goto loc_822BD7DC;
	// stw r28,68(r8)
	REX_STORE_U32(ctx.r8.u32 + 68, ctx.r28.u32);
	// bl 0x822988a0
	ctx.lr = 0x822BD75C;
	sub_822988A0(ctx, base);
	// rlwinm r11,r3,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822bd780
	if (ctx.cr6.eq) goto loc_822BD780;
	// lwz r11,28(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x822bd780
	if (ctx.cr6.gt) goto loc_822BD780;
	// li r30,56
	ctx.r30.s64 = 56;
	// b 0x822bd860
	goto loc_822BD860;
loc_822BD780:
	// lwz r11,4324(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4324);
	// lwz r11,264(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 264);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x822bd7b8
	if (!ctx.cr6.eq) goto loc_822BD7B8;
	// lwz r11,4320(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4320);
	// lhz r11,180(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 180);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,16384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16384, ctx.xer);
	// bgt cr6,0x822bd7b8
	if (ctx.cr6.gt) goto loc_822BD7B8;
	// lwz r11,992(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 992);
	// rlwinm r10,r11,0,10,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822bd7d4
	if (ctx.cr6.eq) goto loc_822BD7D4;
loc_822BD7B8:
	// bl 0x822988a0
	ctx.lr = 0x822BD7BC;
	sub_822988A0(ctx, base);
	// clrlwi r11,r3,26
	ctx.r11.u64 = ctx.r3.u32 & 0x3F;
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x822bd7d4
	if (ctx.cr6.eq) goto loc_822BD7D4;
	// li r30,2
	ctx.r30.s64 = 2;
	// b 0x822bd860
	goto loc_822BD860;
loc_822BD7D4:
	// li r30,4
	ctx.r30.s64 = 4;
	// b 0x822bd860
	goto loc_822BD860;
loc_822BD7DC:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// b 0x822bd860
	goto loc_822BD860;
loc_822BD7E4:
	// lwz r11,28(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x822bd7dc
	if (ctx.cr6.gt) goto loc_822BD7DC;
	// rlwinm r11,r6,3,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0x10;
	// stw r28,68(r8)
	REX_STORE_U32(ctx.r8.u32 + 68, ctx.r28.u32);
	// ori r30,r11,40
	ctx.r30.u64 = ctx.r11.u64 | 40;
	// b 0x822bd8c4
	goto loc_822BD8C4;
loc_822BD800:
	// lwz r11,28(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x822bd8a0
	if (ctx.cr6.gt) goto loc_822BD8A0;
	// lhz r11,4(r8)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r8.u32 + 4);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x822bd7dc
	if (!ctx.cr6.eq) goto loc_822BD7DC;
	// stw r28,68(r8)
	REX_STORE_U32(ctx.r8.u32 + 68, ctx.r28.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x822bd87c
	if (!ctx.cr6.lt) goto loc_822BD87C;
	// bl 0x822988a0
	ctx.lr = 0x822BD838;
	sub_822988A0(ctx, base);
	// clrlwi r11,r3,26
	ctx.r11.u64 = ctx.r3.u32 & 0x3F;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x822bd87c
	if (!ctx.cr6.eq) goto loc_822BD87C;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bgt cr6,0x822bd87c
	if (ctx.cr6.gt) goto loc_822BD87C;
	// stw r28,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r28.u32);
	// li r30,56
	ctx.r30.s64 = 56;
loc_822BD85C:
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
loc_822BD860:
	// clrlwi r11,r30,26
	ctx.r11.u64 = ctx.r30.u32 & 0x3F;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822bd8e0
	if (!ctx.cr6.eq) goto loc_822BD8E0;
	// stw r28,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD87C:
	// bl 0x822988a0
	ctx.lr = 0x822BD880;
	sub_822988A0(ctx, base);
	// clrlwi r11,r3,20
	ctx.r11.u64 = ctx.r3.u32 & 0xFFF;
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// cmpwi cr6,r11,409
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 409, ctx.xer);
	// bge cr6,0x822bd898
	if (!ctx.cr6.lt) goto loc_822BD898;
	// li r30,7
	ctx.r30.s64 = 7;
	// b 0x822bd860
	goto loc_822BD860;
loc_822BD898:
	// li r30,3
	ctx.r30.s64 = 3;
	// b 0x822bd860
	goto loc_822BD860;
loc_822BD8A0:
	// lwz r11,32(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 32);
	// bl 0x822988a0
	ctx.lr = 0x822BD8A8;
	sub_822988A0(ctx, base);
	// clrlwi r11,r3,20
	ctx.r11.u64 = ctx.r3.u32 & 0xFFF;
	// li r30,7
	ctx.r30.s64 = 7;
	// cmpwi cr6,r11,409
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 409, ctx.xer);
	// blt cr6,0x822bd8bc
	if (ctx.cr6.lt) goto loc_822BD8BC;
	// li r30,3
	ctx.r30.s64 = 3;
loc_822BD8BC:
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r28,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r28.u32);
loc_822BD8C4:
	// cmplwi cr6,r30,128
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 128, ctx.xer);
	// bne cr6,0x822bd85c
	if (!ctx.cr6.eq) goto loc_822BD85C;
	// lwz r8,4300(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
loc_822BD8D0:
	// stw r28,8(r8)
	REX_STORE_U32(ctx.r8.u32 + 8, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD8E0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r29,r11,1604
	ctx.r29.s64 = ctx.r11.s64 + 1604;
loc_822BD8E8:
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82298900
	ctx.lr = 0x822BD8F0;
	sub_82298900(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// and r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 & ctx.r30.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822bd8e8
	if (ctx.cr6.eq) goto loc_822BD8E8;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bgt cr6,0x822bd9ec
	if (ctx.cr6.gt) goto loc_822BD9EC;
	// beq cr6,0x822bd9e0
	if (ctx.cr6.eq) goto loc_822BD9E0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x822bd9cc
	if (ctx.cr6.eq) goto loc_822BD9CC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x822bd940
	if (ctx.cr6.eq) goto loc_822BD940;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x822bda14
	if (!ctx.cr6.eq) goto loc_822BDA14;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD940:
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lhz r10,1236(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 1236);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822bd9a4
	if (ctx.cr6.eq) goto loc_822BD9A4;
	// lhz r10,1242(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 1242);
	// lhz r9,1240(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 1240);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x822bd98c
	if (!ctx.cr6.eq) goto loc_822BD98C;
	// lhz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r9,r10,29
	ctx.r9.u64 = ctx.r10.u32 & 0x7;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x822bd9b8
	if (ctx.cr6.eq) goto loc_822BD9B8;
	// li r10,16384
	ctx.r10.s64 = 16384;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD98C:
	// ble cr6,0x822bd9b8
	if (!ctx.cr6.gt) goto loc_822BD9B8;
	// li r10,16384
	ctx.r10.s64 = 16384;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD9A4:
	// lhz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// clrlwi r9,r10,29
	ctx.r9.u64 = ctx.r10.u32 & 0x7;
	// li r10,16384
	ctx.r10.s64 = 16384;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x822bd9bc
	if (!ctx.cr6.eq) goto loc_822BD9BC;
loc_822BD9B8:
	// li r10,16386
	ctx.r10.s64 = 16386;
loc_822BD9BC:
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD9CC:
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r27,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BD9E0:
	// lis r11,-32212
	ctx.r11.s64 = -2111045632;
	// addi r3,r11,-23560
	ctx.r3.s64 = ctx.r11.s64 + -23560;
	// b 0x822bda10
	goto loc_822BDA10;
loc_822BD9EC:
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// beq cr6,0x822bda08
	if (ctx.cr6.eq) goto loc_822BDA08;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// bne cr6,0x822bda14
	if (!ctx.cr6.eq) goto loc_822BDA14;
	// lis r11,-32212
	ctx.r11.s64 = -2111045632;
	// addi r3,r11,-21824
	ctx.r3.s64 = ctx.r11.s64 + -21824;
	// b 0x822bda10
	goto loc_822BDA10;
loc_822BDA08:
	// lis r11,-32212
	ctx.r11.s64 = -2111045632;
	// addi r3,r11,-23144
	ctx.r3.s64 = ctx.r11.s64 + -23144;
loc_822BDA10:
	// bl 0x822ba2b0
	ctx.lr = 0x822BDA14;
	sub_822BA2B0(ctx, base);
loc_822BDA14:
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// lwz r10,172(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x822bda60
	if (ctx.cr6.gt) goto loc_822BDA60;
	// lwz r10,972(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 972);
	// cmpwi cr6,r10,180
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 180, ctx.xer);
	// blt cr6,0x822bda50
	if (ctx.cr6.lt) goto loc_822BDA50;
	// lhz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 4);
	// rlwinm r9,r10,0,28,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xE;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x822bda50
	if (!ctx.cr6.eq) goto loc_822BDA50;
	// stw r27,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r27.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BDA50:
	// stw r28,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BDA60:
	// bl 0x822bb5b8
	ctx.lr = 0x822BDA64;
	sub_822BB5B8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x822bda78
	if (ctx.cr6.lt) goto loc_822BDA78;
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// li r10,50
	ctx.r10.s64 = 50;
	// stw r10,964(r11)
	REX_STORE_U32(ctx.r11.u32 + 964, ctx.r10.u32);
loc_822BDA78:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_822BDA84:
	// li r28,0
	ctx.r28.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r28,68(r8)
	REX_STORE_U32(ctx.r8.u32 + 68, ctx.r28.u32);
	// lwz r11,4300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4300);
	// stw r28,972(r11)
	REX_STORE_U32(ctx.r11.u32 + 972, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822DEA40) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822dea84
	if (!ctx.cr6.eq) goto loc_822DEA84;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822dea84
	if (!ctx.cr6.eq) goto loc_822DEA84;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x822dea84
	if (!ctx.cr6.eq) goto loc_822DEA84;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x822dea88
	if (ctx.cr6.eq) goto loc_822DEA88;
loc_822DEA84:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822DEA88:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822E2B40) {
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
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x822e2b70
	if (ctx.cr6.eq) goto loc_822E2B70;
	// lwz r3,16(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x822e10f0
	ctx.lr = 0x822E2B68;
	sub_822E10F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_822E2B70:
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

DEFINE_REX_FUNC(sub_822E3590) {
	REX_FUNC_PROLOGUE();
	// rlwinm r10,r5,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// subf r9,r3,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r3.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822E35A8:
	// lwzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x822e35a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822E35A8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822E6070) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,3940
	ctx.r9.s64 = ctx.r11.s64 + 3940;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822e60a4
	if (ctx.cr6.eq) goto loc_822E60A4;
	// bl 0x82573808
	ctx.lr = 0x822E60A0;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_822E60A4:
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

DEFINE_REX_FUNC(sub_822E72B8) {
	REX_FUNC_PROLOGUE();
	// rlwinm r10,r4,0,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFC0;
	// lwz r11,392(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 392);
	// rlwinm r10,r10,0,20,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFF0FFF;
	// andc r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ~ctx.r10.u64;
	// stw r9,392(r3)
	REX_STORE_U32(ctx.r3.u32 + 392, ctx.r9.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822E73A8) {
	REX_FUNC_PROLOGUE();
	// stw r4,384(r3)
	REX_STORE_U32(ctx.r3.u32 + 384, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822E74C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,132(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// addi r11,r11,18
	ctx.r11.s64 = ctx.r11.s64 + 18;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822E7A88) {
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
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x826a0d10
	ctx.lr = 0x822E7AA0;
	__savefpr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// fmr f29,f3
	ctx.f29.f64 = ctx.f3.f64;
	// fmr f28,f4
	ctx.f28.f64 = ctx.f4.f64;
	// fmr f27,f5
	ctx.f27.f64 = ctx.f5.f64;
	// fmr f26,f6
	ctx.f26.f64 = ctx.f6.f64;
	// bl 0x82513308
	ctx.lr = 0x822E7AC8;
	sub_82513308(ctx, base);
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82513670
	ctx.lr = 0x822E7AD8;
	sub_82513670(ctx, base);
	// fmr f3,f26
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f26.f64;
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x82513630
	ctx.lr = 0x822E7AE8;
	sub_82513630(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825133f0
	ctx.lr = 0x822E7AF0;
	sub_825133F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82513bc0
	ctx.lr = 0x822E7AF8;
	sub_82513BC0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x826a0d5c
	ctx.lr = 0x822E7B04;
	__restfpr_26(ctx, base);
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

DEFINE_REX_FUNC(sub_822E9D70) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822e9d98
	if (ctx.cr6.eq) goto loc_822E9D98;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x822e9d9c
	if (ctx.cr6.eq) goto loc_822E9D9C;
loc_822E9D98:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822E9D9C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822e9dc0
	if (ctx.cr6.eq) goto loc_822E9DC0;
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
	// bne cr6,0x822e9dc4
	if (!ctx.cr6.eq) goto loc_822E9DC4;
loc_822E9DC0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E9DC4:
	// lwz r11,920(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 920);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822EC3E8) {
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
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// bl 0x822ec238
	ctx.lr = 0x822EC3FC;
	sub_822EC238(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r6,30044(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 30044);
	// bl 0x822189c8
	ctx.lr = 0x822EC410;
	sub_822189C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822ECF70) {
	REX_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822ECF80) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x822ecfb8
	if (!ctx.cr6.lt) goto loc_822ECFB8;
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
loc_822ECFB8:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ecfd0
	if (ctx.cr6.eq) goto loc_822ECFD0;
	// li r4,20
	ctx.r4.s64 = 20;
	// li r3,212
	ctx.r3.s64 = 212;
	// bl 0x8219d0f8
	ctx.lr = 0x822ECFD0;
	sub_8219D0F8(ctx, base);
loc_822ECFD0:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ecff4
	if (ctx.cr6.eq) goto loc_822ECFF4;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ecff4
	if (ctx.cr6.eq) goto loc_822ECFF4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8223cdd8
	ctx.lr = 0x822ECFF4;
	sub_8223CDD8(ctx, base);
loc_822ECFF4:
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

DEFINE_REX_FUNC(sub_822EF540) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r10,r11,22844
	ctx.r10.s64 = ctx.r11.s64 + 22844;
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r8,20(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ef57c
	if (ctx.cr6.eq) goto loc_822EF57C;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822ef580
	if (ctx.cr6.eq) goto loc_822EF580;
loc_822EF57C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822EF580:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// lwz r7,30048(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 30048);
	// beq cr6,0x822ef5a8
	if (ctx.cr6.eq) goto loc_822EF5A8;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r6,r10,r7
	ctx.r6.u64 = ctx.r10.u64 & ctx.r7.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x822ef5ac
	if (!ctx.cr6.eq) goto loc_822EF5AC;
loc_822EF5A8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822EF5AC:
	// lwz r5,160(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 160);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,7964(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 7964);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bgt cr6,0x822ef5e4
	if (ctx.cr6.gt) goto loc_822EF5E4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,30572(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30572);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12924(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12924);
	ctx.f11.f64 = double(temp.f32);
	// b 0x822ef634
	goto loc_822EF634;
loc_822EF5E4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822ef5fc
	if (ctx.cr6.eq) goto loc_822EF5FC;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822ef600
	if (ctx.cr6.eq) goto loc_822EF600;
loc_822EF5FC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822EF600:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822ef61c
	if (ctx.cr6.eq) goto loc_822EF61C;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 & ctx.r7.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x822ef620
	if (!ctx.cr6.eq) goto loc_822EF620;
loc_822EF61C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822EF620:
	// lwz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 164);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
loc_822EF634:
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// lfs f13,148(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,16192
	ctx.r31.s64 = ctx.r11.s64 + 16192;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,212
	ctx.r3.s64 = 212;
	// lfs f0,2944(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2944);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// lfs f13,160(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f13,48(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// rlwinm r11,r11,0,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// lfs f13,164(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// lfs f0,168(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stfs f11,36(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// lwz r9,144(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 144);
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bl 0x82514e88
	ctx.lr = 0x822EF698;
	sub_82514E88(ctx, base);
	// stw r3,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8219d0d0
	ctx.lr = 0x822EF6A4;
	sub_8219D0D0(ctx, base);
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

DEFINE_REX_FUNC(sub_822F6EB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x822F6EB8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r27,r11,11320
	ctx.r27.s64 = ctx.r11.s64 + 11320;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
loc_822F6ED0:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x822f6f28
	if (ctx.cr6.lt) goto loc_822F6F28;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x822f3fc8
	ctx.lr = 0x822F6EE4;
	sub_822F3FC8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x822f6f18
	if (!ctx.cr6.eq) goto loc_822F6F18;
	// bl 0x822f3c28
	ctx.lr = 0x822F6EF0;
	sub_822F3C28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822f6f10
	if (ctx.cr6.eq) goto loc_822F6F10;
	// cmpwi cr6,r29,40
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 40, ctx.xer);
	// beq cr6,0x822f6f08
	if (ctx.cr6.eq) goto loc_822F6F08;
	// cmpwi cr6,r29,41
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 41, ctx.xer);
	// bne cr6,0x822f6f10
	if (!ctx.cr6.eq) goto loc_822F6F10;
loc_822F6F08:
	// li r5,12
	ctx.r5.s64 = 12;
	// b 0x822f6f1c
	goto loc_822F6F1C;
loc_822F6F10:
	// li r5,13
	ctx.r5.s64 = 13;
	// b 0x822f6f1c
	goto loc_822F6F1C;
loc_822F6F18:
	// li r5,14
	ctx.r5.s64 = 14;
loc_822F6F1C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x822e8a50
	ctx.lr = 0x822F6F28;
	sub_822E8A50(ctx, base);
loc_822F6F28:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r11,r27,172
	ctx.r11.s64 = ctx.r27.s64 + 172;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x822f6ed0
	if (ctx.cr6.lt) goto loc_822F6ED0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822FBCF0) {
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
	// bl 0x822fbbc0
	ctx.lr = 0x822FBD08;
	sub_822FBBC0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822fbd18
	if (ctx.cr6.eq) goto loc_822FBD18;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x822fa260
	ctx.lr = 0x822FBD18;
	sub_822FA260(ctx, base);
loc_822FBD18:
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

DEFINE_REX_FUNC(sub_822FC668) {
	REX_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822FC848) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x822FC850;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82219630
	ctx.lr = 0x822FC874;
	sub_82219630(ctx, base);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822fc894
	if (ctx.cr6.eq) goto loc_822FC894;
	// li r5,8791
	ctx.r5.s64 = 8791;
	// li r4,8790
	ctx.r4.s64 = 8790;
	// bl 0x8235df68
	ctx.lr = 0x822FC88C;
	sub_8235DF68(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x822fc898
	goto loc_822FC898;
loc_822FC894:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
loc_822FC898:
	// addi r29,r31,128
	ctx.r29.s64 = ctx.r31.s64 + 128;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8226bf28
	ctx.lr = 0x822FC8A4;
	sub_8226BF28(ctx, base);
	// addi r28,r31,192
	ctx.r28.s64 = ctx.r31.s64 + 192;
	// lis r5,2
	ctx.r5.s64 = 131072;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,7264
	ctx.r5.u64 = ctx.r5.u64 | 7264;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8223d2b0
	ctx.lr = 0x822FC8C4;
	sub_8223D2B0(ctx, base);
	// addi r27,r31,176
	ctx.r27.s64 = ctx.r31.s64 + 176;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4124
	ctx.r5.s64 = 4124;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8223d2b0
	ctx.lr = 0x822FC8E0;
	sub_8223D2B0(ctx, base);
	// lwz r30,144(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x822fc900
	if (ctx.cr6.eq) goto loc_822FC900;
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,20(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x822fc904
	if (ctx.cr6.eq) goto loc_822FC904;
loc_822FC900:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_822FC904:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822fc928
	if (ctx.cr6.eq) goto loc_822FC928;
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
	// bne cr6,0x822fc92c
	if (!ctx.cr6.eq) goto loc_822FC92C;
loc_822FC928:
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
loc_822FC92C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r29,r11,7568
	ctx.r29.s64 = ctx.r11.s64 + 7568;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// bl 0x8223b838
	ctx.lr = 0x822FC944;
	sub_8223B838(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r27,r10,5796
	ctx.r27.s64 = ctx.r10.s64 + 5796;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8235e048
	ctx.lr = 0x822FC960;
	sub_8235E048(ctx, base);
	// stw r29,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8223b838
	ctx.lr = 0x822FC970;
	sub_8223B838(ctx, base);
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8235ddb8
	ctx.lr = 0x822FC984;
	sub_8235DDB8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32208
	ctx.r8.s64 = -2110783488;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// stw r9,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r5,r8,-14592
	ctx.r5.s64 = ctx.r8.s64 + -14592;
	// stw r26,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// addi r6,r7,12727
	ctx.r6.s64 = ctx.r7.s64 + 12727;
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x822FC9BC;
	sub_822518D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82302268) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82302270;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82218220
	ctx.lr = 0x8230227C;
	sub_82218220(ctx, base);
	// lis r11,-32208
	ctx.r11.s64 = -2110783488;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r9,r11,8416
	ctx.r9.s64 = ctx.r11.s64 + 8416;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r3,r8,12332
	ctx.r3.s64 = ctx.r8.s64 + 12332;
	// stw r30,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// addi r7,r7,12260
	ctx.r7.s64 = ctx.r7.s64 + 12260;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// addi r6,r6,15996
	ctx.r6.s64 = ctx.r6.s64 + 15996;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// lis r29,-32255
	ctx.r29.s64 = -2113863680;
	// lis r28,-32255
	ctx.r28.s64 = -2113863680;
	// stw r7,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r7.u32);
	// stw r30,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// stw r30,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// addi r5,r5,21712
	ctx.r5.s64 = ctx.r5.s64 + 21712;
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r30,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// addi r9,r9,16080
	ctx.r9.s64 = ctx.r9.s64 + 16080;
	// stw r30,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// addi r29,r29,16072
	ctx.r29.s64 = ctx.r29.s64 + 16072;
	// stw r6,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r6.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r28,r28,16064
	ctx.r28.s64 = ctx.r28.s64 + 16064;
	// stw r4,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r4.u32);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// addi r27,r6,7568
	ctx.r27.s64 = ctx.r6.s64 + 7568;
	// stw r8,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r8.u32);
	// addi r8,r7,16004
	ctx.r8.s64 = ctx.r7.s64 + 16004;
	// stw r10,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// addi r10,r3,-16796
	ctx.r10.s64 = ctx.r3.s64 + -16796;
	// stw r5,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r5.u32);
	// addi r11,r31,120
	ctx.r11.s64 = ctx.r31.s64 + 120;
	// stw r30,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// addi r3,r31,208
	ctx.r3.s64 = ctx.r31.s64 + 208;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r29.u32);
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// stw r28,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r28.u32);
	// addi r11,r31,84
	ctx.r11.s64 = ctx.r31.s64 + 84;
	// stw r30,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r30.u32);
	// stw r30,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// stw r10,160(r31)
	REX_STORE_U32(ctx.r31.u32 + 160, ctx.r10.u32);
	// stw r30,164(r31)
	REX_STORE_U32(ctx.r31.u32 + 164, ctx.r30.u32);
	// stw r30,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r30.u32);
	// stw r30,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r30.u32);
	// stw r30,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r30.u32);
	// stw r30,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r30.u32);
	// stw r8,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r8.u32);
	// stw r30,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// stw r30,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r30.u32);
	// stw r30,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r30.u32);
	// stw r27,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r27.u32);
	// bl 0x8223b818
	ctx.lr = 0x8230238C;
	sub_8223B818(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r3,r31,224
	ctx.r3.s64 = ctx.r31.s64 + 224;
	// addi r29,r6,5796
	ctx.r29.s64 = ctx.r6.s64 + 5796;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r29.u32);
	// stw r27,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r27.u32);
	// bl 0x8223b818
	ctx.lr = 0x823023A8;
	sub_8223B818(ctx, base);
	// stw r29,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r29.u32);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82308EB0) {
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
	// lwz r11,180(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82308ee4
	if (ctx.cr6.eq) goto loc_82308EE4;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,184(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82308ee8
	if (ctx.cr6.eq) goto loc_82308EE8;
loc_82308EE4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82308EE8:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwz r9,30048(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 30048);
	// beq cr6,0x82308f0c
	if (ctx.cr6.eq) goto loc_82308F0C;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82308f10
	if (!ctx.cr6.eq) goto loc_82308F10;
loc_82308F0C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82308F10:
	// lwz r10,180(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 180);
	// lwz r4,92(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82308f34
	if (ctx.cr6.eq) goto loc_82308F34;
	// lwz r11,12(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r8,184(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82308f38
	if (ctx.cr6.eq) goto loc_82308F38;
loc_82308F34:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82308F38:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82308f54
	if (ctx.cr6.eq) goto loc_82308F54;
	// lwz r11,60(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// and r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82308f58
	if (!ctx.cr6.eq) goto loc_82308F58;
loc_82308F54:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82308F58:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82319688
	ctx.lr = 0x82308F60;
	sub_82319688(ctx, base);
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lfs f12,24(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,2884(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
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

DEFINE_REX_FUNC(sub_8230FDF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8230FDF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r6,776(r3)
	REX_STORE_U32(ctx.r3.u32 + 776, ctx.r6.u32);
	// rlwinm r10,r6,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4000;
	// stw r4,784(r3)
	REX_STORE_U32(ctx.r3.u32 + 784, ctx.r4.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r5,788(r3)
	REX_STORE_U32(ctx.r3.u32 + 788, ctx.r5.u32);
	// stw r11,752(r3)
	REX_STORE_U32(ctx.r3.u32 + 752, ctx.r11.u32);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r3,r4,3028
	ctx.r3.s64 = ctx.r4.s64 + 3028;
	// beq cr6,0x8230fe30
	if (ctx.cr6.eq) goto loc_8230FE30;
	// bl 0x8219da68
	ctx.lr = 0x8230FE2C;
	sub_8219DA68(ctx, base);
	// b 0x8230fe34
	goto loc_8230FE34;
loc_8230FE30:
	// bl 0x8219da60
	ctx.lr = 0x8230FE34;
	sub_8219DA60(ctx, base);
loc_8230FE34:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r30,r30,0,18,15
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFFFFFFFFFFF3FFF;
	// bl 0x821a4d28
	ctx.lr = 0x8230FE40;
	sub_821A4D28(ctx, base);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x8230fe58
	if (ctx.cr6.gt) goto loc_8230FE58;
loc_8230FE48:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8230f9f0
	ctx.lr = 0x8230FE50;
	sub_8230F9F0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_8230FE58:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821a4d40
	ctx.lr = 0x8230FE64;
	sub_821A4D40(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8230fe48
	if (ctx.cr6.eq) goto loc_8230FE48;
	// bl 0x82178c20
	ctx.lr = 0x8230FE70;
	sub_82178C20(ctx, base);
	// sth r3,772(r29)
	REX_STORE_U16(ctx.r29.u32 + 772, ctx.r3.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82314898) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x823148A0;
	__savegprlr_24(ctx, base);
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f29.u64);
	// stfd f30,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r27,r3,368
	ctx.r27.s64 = ctx.r3.s64 + 368;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r24,r3,512
	ctx.r24.s64 = ctx.r3.s64 + 512;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82307b68
	ctx.lr = 0x823148C4;
	sub_82307B68(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82307bf0
	ctx.lr = 0x823148D0;
	sub_82307BF0(ctx, base);
	// lfs f0,420(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 420);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,564(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 564, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82307318
	ctx.lr = 0x823148E4;
	sub_82307318(ctx, base);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r26,r11,23664
	ctx.r26.s64 = ctx.r11.s64 + 23664;
	// lwz r11,16(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8231490c
	if (ctx.cr6.eq) goto loc_8231490C;
	// lwz r10,20(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82314910
	if (ctx.cr6.eq) goto loc_82314910;
loc_8231490C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82314910:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r25,-32256
	ctx.r25.s64 = -2113929216;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82314934
	if (ctx.cr6.eq) goto loc_82314934;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82314938
	if (!ctx.cr6.eq) goto loc_82314938;
loc_82314934:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82314938:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,884(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314944;
	sub_823088F0(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r3,96
	ctx.r3.s64 = ctx.r3.s64 + 96;
	// bl 0x82307318
	ctx.lr = 0x82314950;
	sub_82307318(ctx, base);
	// bl 0x82170cb0
	ctx.lr = 0x82314954;
	sub_82170CB0(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,884(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314960;
	sub_823088F0(ctx, base);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// bl 0x82170cb0
	ctx.lr = 0x82314968;
	sub_82170CB0(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,884(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314974;
	sub_823088F0(ctx, base);
	// stw r3,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// bl 0x82170cb0
	ctx.lr = 0x8231497C;
	sub_82170CB0(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,884(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314988;
	sub_823088F0(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r3,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// li r29,3
	ctx.r29.s64 = 3;
	// lfs f31,2884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f31.f64 = double(temp.f32);
loc_8231499C:
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,752(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 752);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82314a20
	if (ctx.cr6.eq) goto loc_82314A20;
	// lwz r3,356(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 356);
	// bl 0x823190d0
	ctx.lr = 0x823149B4;
	sub_823190D0(ctx, base);
	// extsb r11,r3
	ctx.r11.s64 = ctx.r3.s8;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x823149e0
	if (ctx.cr6.eq) goto loc_823149E0;
	// addi r31,r31,96
	ctx.r31.s64 = ctx.r31.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82307318
	ctx.lr = 0x823149D0;
	sub_82307318(ctx, base);
	// addi r4,r28,448
	ctx.r4.s64 = ctx.r28.s64 + 448;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82307318
	ctx.lr = 0x823149DC;
	sub_82307318(ctx, base);
	// b 0x82314a20
	goto loc_82314A20;
loc_823149E0:
	// lfs f0,556(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 556);
	ctx.f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r5,r31,96
	ctx.r5.s64 = ctx.r31.s64 + 96;
	// lwz r9,596(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 596);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f30,564(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 564);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,420(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 420);
	ctx.f29.f64 = double(temp.f32);
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
	// fsubs f1,f31,f0
	ctx.f1.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// bl 0x8230b3d8
	ctx.lr = 0x82314A08;
	sub_8230B3D8(ctx, base);
	// stw r3,596(r31)
	REX_STORE_U32(ctx.r31.u32 + 596, ctx.r3.u32);
	// lfs f13,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f31,f30
	ctx.f12.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// fmadds f10,f12,f29,f11
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f29.f64, ctx.f11.f64)));
	// stfs f10,420(r28)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r28.u32 + 420, temp.u32);
loc_82314A20:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// bne 0x8231499c
	if (!ctx.cr0.eq) goto loc_8231499C;
	// lwz r11,16(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82314a4c
	if (ctx.cr6.eq) goto loc_82314A4C;
	// lwz r10,20(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82314a50
	if (ctx.cr6.eq) goto loc_82314A50;
loc_82314A4C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82314A50:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82314a70
	if (ctx.cr6.eq) goto loc_82314A70;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82314a74
	if (!ctx.cr6.eq) goto loc_82314A74;
loc_82314A70:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82314A74:
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,884(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314A80;
	sub_823088F0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82314b4c
	if (ctx.cr6.eq) goto loc_82314B4C;
	// lwz r11,16(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82314aa8
	if (ctx.cr6.eq) goto loc_82314AA8;
	// lwz r10,20(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82314aac
	if (ctx.cr6.eq) goto loc_82314AAC;
loc_82314AA8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82314AAC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82314acc
	if (ctx.cr6.eq) goto loc_82314ACC;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82314ad0
	if (!ctx.cr6.eq) goto loc_82314AD0;
loc_82314ACC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82314AD0:
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,884(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314ADC;
	sub_823088F0(ctx, base);
	// lbz r11,448(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 448);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82314b4c
	if (ctx.cr6.eq) goto loc_82314B4C;
	// lwz r11,16(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82314b08
	if (ctx.cr6.eq) goto loc_82314B08;
	// lwz r10,20(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82314b0c
	if (ctx.cr6.eq) goto loc_82314B0C;
loc_82314B08:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82314B0C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82314b2c
	if (ctx.cr6.eq) goto loc_82314B2C;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82314b30
	if (!ctx.cr6.eq) goto loc_82314B30;
loc_82314B2C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82314B30:
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,884(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314B3C;
	sub_823088F0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r4,r11,96
	ctx.r4.s64 = ctx.r11.s64 + 96;
	// bl 0x82307448
	ctx.lr = 0x82314B4C;
	sub_82307448(ctx, base);
loc_82314B4C:
	// lwz r11,16(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82314b6c
	if (ctx.cr6.eq) goto loc_82314B6C;
	// lwz r10,20(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82314b70
	if (ctx.cr6.eq) goto loc_82314B70;
loc_82314B6C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82314B70:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82314b90
	if (ctx.cr6.eq) goto loc_82314B90;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82314b94
	if (!ctx.cr6.eq) goto loc_82314B94;
loc_82314B90:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82314B94:
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,884(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 884);
	// bl 0x823088f0
	ctx.lr = 0x82314BA0;
	sub_823088F0(ctx, base);
	// lwz r11,496(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 496);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82314bb8
	if (ctx.cr6.eq) goto loc_82314BB8;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r3,96
	ctx.r3.s64 = ctx.r3.s64 + 96;
	// bl 0x82307318
	ctx.lr = 0x82314BB8;
	sub_82307318(ctx, base);
loc_82314BB8:
	// addi r5,r27,16
	ctx.r5.s64 = ctx.r27.s64 + 16;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82515460
	ctx.lr = 0x82314BC8;
	sub_82515460(ctx, base);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826a1000
	ctx.lr = 0x82314BD4;
	sub_826A1000(ctx, base);
	// addi r5,r24,16
	ctx.r5.s64 = ctx.r24.s64 + 16;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82515460
	ctx.lr = 0x82314BE8;
	sub_82515460(ctx, base);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826a1000
	ctx.lr = 0x82314BF4;
	sub_826A1000(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f13,596(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 596, temp.u32);
	// bl 0x82307318
	ctx.lr = 0x82314C0C;
	sub_82307318(ctx, base);
	// lwz r4,436(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 436);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x82314c6c
	if (ctx.cr6.eq) goto loc_82314C6C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r5,432(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 432);
	// bl 0x823132e0
	ctx.lr = 0x82314C24;
	sub_823132E0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bge cr6,0x82314c4c
	if (!ctx.cr6.lt) goto loc_82314C4C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,436(r28)
	REX_STORE_U32(ctx.r28.u32 + 436, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f30,-88(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82314C4C:
	// lwz r11,432(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 432);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,432(r28)
	REX_STORE_U32(ctx.r28.u32 + 432, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f30,-88(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
loc_82314C6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f30,-88(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8232CDD0) {
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
	// lis r11,-32108
	ctx.r11.s64 = -2104229888;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-2208(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -2208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8232ce0c
	if (!ctx.cr6.eq) goto loc_8232CE0C;
loc_8232CDF4:
	// li r3,-1
	ctx.r3.s64 = -1;
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
loc_8232CE0C:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8232cdf4
	if (ctx.cr6.eq) goto loc_8232CDF4;
	// bl 0x8232c780
	ctx.lr = 0x8232CE1C;
	sub_8232C780(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8232ce34
	if (ctx.cr6.eq) goto loc_8232CE34;
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,-30648(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -30648);
	// bl 0x823320b0
	ctx.lr = 0x8232CE34;
	sub_823320B0(ctx, base);
loc_8232CE34:
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

DEFINE_REX_FUNC(sub_8232EE58) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp v12,v13,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82332100) {
	REX_FUNC_PROLOGUE();
	// lbz r10,492(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 492);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// blt cr6,0x8233211c
	if (ctx.cr6.lt) goto loc_8233211C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8233211C:
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r4,460(r9)
	REX_STORE_U32(ctx.r9.u32 + 460, ctx.r4.u32);
	// lwz r8,80(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 80);
	// lbz r10,492(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 492);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// beq cr6,0x8233215c
	if (ctx.cr6.eq) goto loc_8233215C;
	// li r8,2
	ctx.r8.s64 = 2;
loc_8233215C:
	// stb r8,464(r6)
	REX_STORE_U8(ctx.r6.u32 + 464, ctx.r8.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,492(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 492);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stb r9,492(r11)
	REX_STORE_U8(ctx.r11.u32 + 492, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82333B18) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82333C90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82333C98;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,6
	ctx.r11.s64 = 6;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r31,0
	ctx.r31.s64 = 0;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// li r28,3
	ctx.r28.s64 = 3;
	// li r27,1
	ctx.r27.s64 = 1;
	// lis r30,-32256
	ctx.r30.s64 = -2113929216;
loc_82333CC8:
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82333d38
	if (!ctx.cr6.eq) goto loc_82333D38;
	// bl 0x82260bc8
	ctx.lr = 0x82333CD8;
	sub_82260BC8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82333dac
	if (ctx.cr6.eq) goto loc_82333DAC;
	// bl 0x82260bc8
	ctx.lr = 0x82333CE4;
	sub_82260BC8(ctx, base);
	// addi r10,r3,88
	ctx.r10.s64 = ctx.r3.s64 + 88;
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82333d08
	if (ctx.cr6.eq) goto loc_82333D08;
	// lwz r8,20(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82333d0c
	if (ctx.cr6.eq) goto loc_82333D0C;
loc_82333D08:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82333D0C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82333d2c
	if (ctx.cr6.eq) goto loc_82333D2C;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82333d30
	if (!ctx.cr6.eq) goto loc_82333D30;
loc_82333D2C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82333D30:
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// b 0x82333dac
	goto loc_82333DAC;
loc_82333D38:
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// bne cr6,0x82333da4
	if (!ctx.cr6.eq) goto loc_82333DA4;
	// bl 0x82260c68
	ctx.lr = 0x82333D44;
	sub_82260C68(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82333dac
	if (ctx.cr6.eq) goto loc_82333DAC;
	// bl 0x82260c68
	ctx.lr = 0x82333D50;
	sub_82260C68(ctx, base);
	// addi r10,r3,88
	ctx.r10.s64 = ctx.r3.s64 + 88;
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82333d74
	if (ctx.cr6.eq) goto loc_82333D74;
	// lwz r8,20(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82333d78
	if (ctx.cr6.eq) goto loc_82333D78;
loc_82333D74:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82333D78:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82333d98
	if (ctx.cr6.eq) goto loc_82333D98;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82333d9c
	if (!ctx.cr6.eq) goto loc_82333D9C;
loc_82333D98:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82333D9C:
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// b 0x82333dac
	goto loc_82333DAC;
loc_82333DA4:
	// bl 0x8226a320
	ctx.lr = 0x82333DA8;
	sub_8226A320(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82333DAC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82333db8
	if (ctx.cr6.eq) goto loc_82333DB8;
	// stw r27,24788(r31)
	REX_STORE_U32(ctx.r31.u32 + 24788, ctx.r27.u32);
loc_82333DB8:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x82333cc8
	if (!ctx.cr0.eq) goto loc_82333CC8;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82338910) {
	REX_FUNC_PROLOGUE();
	// b 0x82350c48
	sub_82350C48(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82338C08) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-88
	ctx.r3.s64 = ctx.r3.s64 + -88;
	// b 0x82338c20
	sub_82338C20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82338CF0) {
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
	// bl 0x8234d0d0
	ctx.lr = 0x82338D10;
	sub_8234D0D0(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82338d28
	if (ctx.cr6.eq) goto loc_82338D28;
	// bl 0x82573808
	ctx.lr = 0x82338D24;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82338D28:
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

DEFINE_REX_FUNC(sub_82339D48) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,23440
	ctx.r9.s64 = ctx.r11.s64 + 23440;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82339d7c
	if (ctx.cr6.eq) goto loc_82339D7C;
	// bl 0x82573808
	ctx.lr = 0x82339D78;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82339D7C:
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

DEFINE_REX_FUNC(sub_8233B1F0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-120
	ctx.r3.s64 = ctx.r3.s64 + -120;
	// b 0x8233b258
	sub_8233B258(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8233B638) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-84
	ctx.r3.s64 = ctx.r3.s64 + -84;
	// b 0x8233b6a8
	sub_8233B6A8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8233B6D8) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,24200
	ctx.r10.s64 = ctx.r11.s64 + 24200;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x8234d978
	ctx.lr = 0x8233B704;
	sub_8234D978(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8233b71c
	if (ctx.cr6.eq) goto loc_8233B71C;
	// bl 0x82573808
	ctx.lr = 0x8233B718;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8233B71C:
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

DEFINE_REX_FUNC(sub_8233D5E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8233D5F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8233eab0
	ctx.lr = 0x8233D5FC;
	sub_8233EAB0(ctx, base);
	// addi r3,r3,2240
	ctx.r3.s64 = ctx.r3.s64 + 2240;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8233D610;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,204(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8233d624
	if (ctx.cr6.lt) goto loc_8233D624;
	// bl 0x82572228
	ctx.lr = 0x8233D624;
	sub_82572228(ctx, base);
loc_8233D624:
	// li r30,-1
	ctx.r30.s64 = -1;
	// lwz r4,200(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r30.u32);
	// bl 0x8234d5f8
	ctx.lr = 0x8233D638;
	sub_8234D5F8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r30.u32);
	// stw r11,200(r31)
	REX_STORE_U32(ctx.r31.u32 + 200, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8233F240) {
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
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// addi r6,r11,-26356
	ctx.r6.s64 = ctx.r11.s64 + -26356;
	// addi r5,r10,876
	ctx.r5.s64 = ctx.r10.s64 + 876;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// bl 0x826a0b10
	ctx.lr = 0x8233F274;
	sub_826A0B10(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r3,120
	ctx.r3.s64 = ctx.r3.s64 + 120;
	// bl 0x82353b30
	ctx.lr = 0x8233F280;
	sub_82353B30(ctx, base);
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

DEFINE_REX_FUNC(sub_823405D8) {
	REX_FUNC_PROLOGUE();
	// b 0x824b2a38
	sub_824B2A38(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823405F0) {
	REX_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823406D8) {
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
	// lis r11,-32204
	ctx.r11.s64 = -2110521344;
	// addi r30,r3,88
	ctx.r30.s64 = ctx.r3.s64 + 88;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,1528
	ctx.r10.s64 = ctx.r11.s64 + 1528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82341280
	ctx.lr = 0x8234071C;
	sub_82341280(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82340760
	if (!ctx.cr6.eq) goto loc_82340760;
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// lis r11,-32204
	ctx.r11.s64 = -2110521344;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r10,r11,1536
	ctx.r10.s64 = ctx.r11.s64 + 1536;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82341280
	ctx.lr = 0x82340750;
	sub_82341280(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82340764
	if (ctx.cr6.eq) goto loc_82340764;
loc_82340760:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82340764:
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

DEFINE_REX_FUNC(sub_82344250) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,28660
	ctx.r10.s64 = ctx.r11.s64 + 28660;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x8234d978
	ctx.lr = 0x8234427C;
	sub_8234D978(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82344294
	if (ctx.cr6.eq) goto loc_82344294;
	// bl 0x82573808
	ctx.lr = 0x82344290;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82344294:
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

DEFINE_REX_FUNC(sub_823455D0) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,30740
	ctx.r10.s64 = ctx.r11.s64 + 30740;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x8234d978
	ctx.lr = 0x823455FC;
	sub_8234D978(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82345614
	if (ctx.cr6.eq) goto loc_82345614;
	// bl 0x82573808
	ctx.lr = 0x82345610;
	sub_82573808(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82345614:
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

DEFINE_REX_FUNC(sub_823470B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x823470B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x8223d420
	ctx.lr = 0x823470E0;
	sub_8223D420(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82347120
	if (ctx.cr6.eq) goto loc_82347120;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,2062
	ctx.r4.s64 = 2062;
	// bl 0x8234d830
	ctx.lr = 0x823470F8;
	sub_8234D830(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r10,r11,29100
	ctx.r10.s64 = ctx.r11.s64 + 29100;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// stw r28,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r28.u32);
	// bl 0x8234de38
	ctx.lr = 0x82347118;
	sub_8234DE38(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_82347120:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823490F4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82349460) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r6,r11,32116
	ctx.r6.s64 = ctx.r11.s64 + 32116;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r6,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r3,r8,32076
	ctx.r3.s64 = ctx.r8.s64 + 32076;
	// addi r5,r10,32108
	ctx.r5.s64 = ctx.r10.s64 + 32108;
	// addi r4,r9,32088
	ctx.r4.s64 = ctx.r9.s64 + 32088;
	// stw r3,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r3.u32);
	// addi r11,r7,32068
	ctx.r11.s64 = ctx.r7.s64 + 32068;
	// stw r5,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
	// stw r4,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r4.u32);
	// addi r3,r31,212
	ctx.r3.s64 = ctx.r31.s64 + 212;
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// bl 0x8223cdb0
	ctx.lr = 0x823494B8;
	sub_8223CDB0(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// addi r5,r10,25316
	ctx.r5.s64 = ctx.r10.s64 + 25316;
	// addi r3,r8,25144
	ctx.r3.s64 = ctx.r8.s64 + 25144;
	// addi r4,r9,25156
	ctx.r4.s64 = ctx.r9.s64 + 25156;
	// stw r5,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r5.u32);
	// addi r11,r7,25124
	ctx.r11.s64 = ctx.r7.s64 + 25124;
	// stw r3,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// addi r10,r6,25112
	ctx.r10.s64 = ctx.r6.s64 + 25112;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// bl 0x82351340
	ctx.lr = 0x823494FC;
	sub_82351340(ctx, base);
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

DEFINE_REX_FUNC(sub_8234CF78) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8234D0A0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,26168
	ctx.r10.s64 = ctx.r11.s64 + 26168;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x8234d978
	sub_8234D978(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8234DFE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x8234DFF0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8234e078
	if (ctx.cr6.eq) goto loc_8234E078;
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8234e188
	ctx.lr = 0x8234E020;
	sub_8234E188(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8234e818
	ctx.lr = 0x8234E028;
	sub_8234E818(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8234e078
	if (ctx.cr6.eq) goto loc_8234E078;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8234e188
	ctx.lr = 0x8234E038;
	sub_8234E188(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8234d660
	ctx.lr = 0x8234E040;
	sub_8234D660(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8234e078
	if (ctx.cr6.eq) goto loc_8234E078;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// add r10,r30,r29
	ctx.r10.u64 = ctx.r30.u64 + ctx.r29.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8234e078
	if (ctx.cr6.gt) goto loc_8234E078;
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x826a1130
	ctx.lr = 0x8234E06C;
	rexcrt_memcpy(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
loc_8234E078:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82350C80) {
	REX_FUNC_PROLOGUE();
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,148(r3)
	REX_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823510E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x823510E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2232(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2232);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82351160
	if (!ctx.cr6.gt) goto loc_82351160;
	// lis r10,-32139
	ctx.r10.s64 = -2106261504;
	// lwz r31,2236(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 2236);
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// addi r30,r10,-27756
	ctx.r30.s64 = ctx.r10.s64 + -27756;
	// addi r29,r11,-12728
	ctx.r29.s64 = ctx.r11.s64 + -12728;
loc_82351114:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826a0b10
	ctx.lr = 0x8235112C;
	sub_826A0B10(ctx, base);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82351158
	if (ctx.cr6.eq) goto loc_82351158;
	// lwz r31,12(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82351114
	if (!ctx.cr6.eq) goto loc_82351114;
	// lwz r11,96(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 96);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,96(r27)
	REX_STORE_U32(ctx.r27.u32 + 96, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_82351158:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8233aa20
	ctx.lr = 0x82351160;
	sub_8233AA20(ctx, base);
loc_82351160:
	// lwz r11,96(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 96);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,96(r27)
	REX_STORE_U32(ctx.r27.u32 + 96, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82354970) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-12632
	ctx.r6.s64 = ctx.r11.s64 + -12632;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_82354980:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
loc_82354988:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r5,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r5.u64;
	// beq cr6,0x823549ac
	if (ctx.cr6.eq) goto loc_823549AC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82354988
	if (ctx.cr6.eq) goto loc_82354988;
loc_823549AC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x823549d4
	if (ctx.cr6.eq) goto loc_823549D4;
	// addis r11,r6,1
	ctx.r11.s64 = ctx.r6.s64 + 65536;
	// addi r8,r8,24
	ctx.r8.s64 = ctx.r8.s64 + 24;
	// addi r11,r11,-7672
	ctx.r11.s64 = ctx.r11.s64 + -7672;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82354980
	if (ctx.cr6.lt) goto loc_82354980;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823549D4:
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// li r11,6
	ctx.r11.s64 = 6;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// addi r9,r4,-4
	ctx.r9.s64 = ctx.r4.s64 + -4;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-4
	ctx.r11.s64 = ctx.r10.s64 + -4;
loc_823549F4:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x823549f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823549F4;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82359B00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82359B08;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x823585b0
	ctx.lr = 0x82359B18;
	sub_823585B0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823585b0
	ctx.lr = 0x82359B24;
	sub_823585B0(ctx, base);
	// lis r11,-32134
	ctx.r11.s64 = -2105933824;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// addi r11,r11,3932
	ctx.r11.s64 = ctx.r11.s64 + 3932;
	// beq cr6,0x82359b88
	if (ctx.cr6.eq) goto loc_82359B88;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,32
	ctx.r8.s64 = ctx.r11.s64 + 32;
	// lwzx r7,r9,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82359b74
	if (ctx.cr6.eq) goto loc_82359B74;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// stwx r10,r9,r8
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u32);
	// lwz r7,660(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 660);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82359b74
	if (ctx.cr6.eq) goto loc_82359B74;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82359b74
	if (ctx.cr6.eq) goto loc_82359B74;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stwx r10,r8,r7
	REX_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
loc_82359B74:
	// lwz r8,88(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r8,18
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 18, ctx.xer);
	// beq cr6,0x82359b88
	if (ctx.cr6.eq) goto loc_82359B88;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// stwx r10,r9,r8
	REX_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u32);
loc_82359B88:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82359bf4
	if (ctx.cr6.eq) goto loc_82359BF4;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,32
	ctx.r9.s64 = ctx.r11.s64 + 32;
	// lwzx r7,r8,r9
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82359bcc
	if (ctx.cr6.eq) goto loc_82359BCC;
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// stwx r10,r8,r9
	REX_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// lwz r7,660(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 660);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82359bcc
	if (ctx.cr6.eq) goto loc_82359BCC;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x82359bcc
	if (ctx.cr6.eq) goto loc_82359BCC;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stwx r10,r9,r7
	REX_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r10.u32);
loc_82359BCC:
	// lwz r9,88(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 88);
	// cmplwi cr6,r9,18
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 18, ctx.xer);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// beq cr6,0x82359bf8
	if (ctx.cr6.eq) goto loc_82359BF8;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stwx r10,r8,r7
	REX_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// stw r10,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82359BF4:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82359BF8:
	// stw r10,36(r11)
	REX_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// stw r9,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82362788) {
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
	// lis r31,-32105
	ctx.r31.s64 = -2104033280;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,-14712(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -14712);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823627f0
	if (!ctx.cr6.eq) goto loc_823627F0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x823627dc
	if (!ctx.cr6.eq) goto loc_823627DC;
	// li r3,588
	ctx.r3.s64 = 588;
	// bl 0x82512fc0
	ctx.lr = 0x823627C4;
	sub_82512FC0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823627dc
	if (!ctx.cr6.eq) goto loc_823627DC;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,588
	ctx.r3.s64 = 588;
	// stw r11,-14712(r31)
	REX_STORE_U32(ctx.r31.u32 + -14712, ctx.r11.u32);
	// b 0x823627f4
	goto loc_823627F4;
loc_823627DC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x823614b8
	ctx.lr = 0x823627E4;
	sub_823614B8(ctx, base);
	// stw r3,-14712(r31)
	REX_STORE_U32(ctx.r31.u32 + -14712, ctx.r3.u32);
	// li r3,588
	ctx.r3.s64 = 588;
	// b 0x823627f4
	goto loc_823627F4;
loc_823627F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823627F4:
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

DEFINE_REX_FUNC(sub_82364320) {
	REX_FUNC_PROLOGUE();
	// lwz r4,132(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x82364334
	if (!ctx.cr6.lt) goto loc_82364334;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82364334:
	// b 0x82366938
	sub_82366938(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82365248) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82365250;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,5
	ctx.r11.s64 = 327680;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// ori r10,r11,32320
	ctx.r10.u64 = ctx.r11.u64 | 32320;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x823652cc
	if (ctx.cr6.lt) goto loc_823652CC;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x823652d4
	if (ctx.cr6.eq) goto loc_823652D4;
	// bl 0x8235efa8
	ctx.lr = 0x82365278;
	sub_8235EFA8(ctx, base);
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r31,r11,-21456
	ctx.r31.s64 = ctx.r11.s64 + -21456;
	// beq cr6,0x82365298
	if (ctx.cr6.eq) goto loc_82365298;
	// bl 0x8235efa8
	ctx.lr = 0x8236528C;
	sub_8235EFA8(ctx, base);
	// addi r5,r31,-40
	ctx.r5.s64 = ctx.r31.s64 + -40;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823602c8
	ctx.lr = 0x82365298;
	sub_823602C8(ctx, base);
loc_82365298:
	// bl 0x8235efa8
	ctx.lr = 0x8236529C;
	sub_8235EFA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823652b4
	if (ctx.cr6.eq) goto loc_823652B4;
	// bl 0x8235efa8
	ctx.lr = 0x823652A8;
	sub_8235EFA8(ctx, base);
	// addi r5,r31,-36
	ctx.r5.s64 = ctx.r31.s64 + -36;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823602c8
	ctx.lr = 0x823652B4;
	sub_823602C8(ctx, base);
loc_823652B4:
	// bl 0x8235efa8
	ctx.lr = 0x823652B8;
	sub_8235EFA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823653a4
	if (ctx.cr6.eq) goto loc_823653A4;
	// bl 0x8235efa8
	ctx.lr = 0x823652C4;
	sub_8235EFA8(ctx, base);
	// addi r5,r31,-32
	ctx.r5.s64 = ctx.r31.s64 + -32;
	// b 0x8236539c
	goto loc_8236539C;
loc_823652CC:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x823652e4
	if (!ctx.cr6.eq) goto loc_823652E4;
loc_823652D4:
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// addi r31,r11,-21456
	ctx.r31.s64 = ctx.r11.s64 + -21456;
	// addi r4,r31,-28
	ctx.r4.s64 = ctx.r31.s64 + -28;
	// b 0x823652f0
	goto loc_823652F0;
loc_823652E4:
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// addi r31,r11,-21456
	ctx.r31.s64 = ctx.r11.s64 + -21456;
	// addi r4,r31,-24
	ctx.r4.s64 = ctx.r31.s64 + -24;
loc_823652F0:
	// li r10,3600
	ctx.r10.s64 = 3600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// divwu r5,r30,r10
	ctx.r5.u64 = uint32_t(ctx.r10.u32 ? ctx.r30.u32 / ctx.r10.u32 : 0);
	// bl 0x826a2638
	ctx.lr = 0x82365300;
	sub_826A2638(ctx, base);
	// bl 0x8235efa8
	ctx.lr = 0x82365304;
	sub_8235EFA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8236531c
	if (ctx.cr6.eq) goto loc_8236531C;
	// bl 0x8235efa8
	ctx.lr = 0x82365310;
	sub_8235EFA8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823602c8
	ctx.lr = 0x8236531C;
	sub_823602C8(ctx, base);
loc_8236531C:
	// lis r11,-30584
	ctx.r11.s64 = -2004353024;
	// li r28,60
	ctx.r28.s64 = 60;
	// ori r29,r11,34953
	ctx.r29.u64 = ctx.r11.u64 | 34953;
	// divwu r10,r30,r28
	ctx.r10.u64 = uint32_t(ctx.r28.u32 ? ctx.r30.u32 / ctx.r28.u32 : 0);
	// addi r4,r31,-16
	ctx.r4.s64 = ctx.r31.s64 + -16;
	// mulhwu r9,r10,r29
	ctx.r9.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r8,r9,27,5,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mulli r7,r8,60
	ctx.r7.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(60));
	// subf r5,r7,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r7.u64;
	// bl 0x826a2638
	ctx.lr = 0x82365348;
	sub_826A2638(ctx, base);
	// bl 0x8235efa8
	ctx.lr = 0x8236534C;
	sub_8235EFA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82365364
	if (ctx.cr6.eq) goto loc_82365364;
	// bl 0x8235efa8
	ctx.lr = 0x82365358;
	sub_8235EFA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823602c8
	ctx.lr = 0x82365364;
	sub_823602C8(ctx, base);
loc_82365364:
	// mulhwu r11,r30,r29
	ctx.r11.u64 = (uint64_t(ctx.r30.u32) * uint64_t(ctx.r29.u32)) >> 32;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// addi r4,r31,-8
	ctx.r4.s64 = ctx.r31.s64 + -8;
	// mulli r9,r10,60
	ctx.r9.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(60));
	// subf r8,r9,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r9.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mulli r7,r8,100
	ctx.r7.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(100));
	// divwu r5,r7,r28
	ctx.r5.u64 = uint32_t(ctx.r28.u32 ? ctx.r7.u32 / ctx.r28.u32 : 0);
	// bl 0x826a2638
	ctx.lr = 0x82365388;
	sub_826A2638(ctx, base);
	// bl 0x8235efa8
	ctx.lr = 0x8236538C;
	sub_8235EFA8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823653a4
	if (ctx.cr6.eq) goto loc_823653A4;
	// bl 0x8235efa8
	ctx.lr = 0x82365398;
	sub_8235EFA8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
loc_8236539C:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x823602c8
	ctx.lr = 0x823653A4;
	sub_823602C8(ctx, base);
loc_823653A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821ca958
	ctx.lr = 0x823653AC;
	sub_821CA958(ctx, base);
	// ori r30,r3,228
	ctx.r30.u64 = ctx.r3.u64 | 228;
	// bl 0x8235e5a0
	ctx.lr = 0x823653B4;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823653d4
	if (!ctx.cr6.eq) goto loc_823653D4;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826a2638
	ctx.lr = 0x823653CC;
	sub_826A2638(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_823653D4:
	// bl 0x8235e5a0
	ctx.lr = 0x823653D8;
	sub_8235E5A0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x823616a0
	ctx.lr = 0x823653E0;
	sub_823616A0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826a2638
	ctx.lr = 0x823653F0;
	sub_826A2638(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236E018) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8236E020;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2964(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2964);
	// addi r30,r3,2964
	ctx.r30.s64 = ctx.r3.s64 + 2964;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8236E044;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,2964(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 2964);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,112(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 112);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8236E05C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8236F2C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,292(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 292);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8236f2e4
	if (!ctx.cr6.eq) goto loc_8236F2E4;
	// stw r4,4016(r11)
	REX_STORE_U32(ctx.r11.u32 + 4016, ctx.r4.u32);
	// blr 
	return;
loc_8236F2E4:
	// stw r4,4020(r11)
	REX_STORE_U32(ctx.r11.u32 + 4020, ctx.r4.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82371B0C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82371CF8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,444(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 444);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82371d18
	if (ctx.cr6.eq) goto loc_82371D18;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,448(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 448);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82371d1c
	if (ctx.cr6.eq) goto loc_82371D1C;
loc_82371D18:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82371D1C:
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
	// lwz r11,444(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 444);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82371d68
	if (ctx.cr6.eq) goto loc_82371D68;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,448(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 448);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x82371d6c
	if (ctx.cr6.eq) goto loc_82371D6C;
loc_82371D68:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82371D6C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82371d88
	if (ctx.cr6.eq) goto loc_82371D88;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82371d8c
	if (!ctx.cr6.eq) goto loc_82371D8C;
loc_82371D88:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82371D8C:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// addi r3,r11,96
	ctx.r3.s64 = ctx.r11.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// bne cr6,0x82371dac
	if (!ctx.cr6.eq) goto loc_82371DAC;
	// lwz r9,100(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_82371DAC:
	// lwz r9,96(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82376410) {
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
	// lbz r11,2972(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2972);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,-2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2, ctx.xer);
	// beq cr6,0x82376450
	if (ctx.cr6.eq) goto loc_82376450;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82376450
	if (ctx.cr6.eq) goto loc_82376450;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82376450
	if (ctx.cr6.eq) goto loc_82376450;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823764b0
	goto loc_823764B0;
loc_82376450:
	// li r10,43
	ctx.r10.s64 = 43;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r11,r30,2948
	ctx.r11.s64 = ctx.r30.s64 + 2948;
	// stw r31,2984(r30)
	REX_STORE_U32(ctx.r30.u32 + 2984, ctx.r31.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
loc_82376468:
	// stb r31,176(r11)
	REX_STORE_U8(ctx.r11.u32 + 176, ctx.r31.u8);
	// stb r10,177(r11)
	REX_STORE_U8(ctx.r11.u32 + 177, ctx.r10.u8);
	// stw r31,164(r11)
	REX_STORE_U32(ctx.r11.u32 + 164, ctx.r31.u32);
	// stb r31,178(r11)
	REX_STORE_U8(ctx.r11.u32 + 178, ctx.r31.u8);
	// stwu r31,168(r11)
	ea = 168 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82376468
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82376468;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r11,r30,3000
	ctx.r11.s64 = ctx.r30.s64 + 3000;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
loc_82376490:
	// stw r10,-8(r11)
	REX_STORE_U32(ctx.r11.u32 + -8, ctx.r10.u32);
	// stwu r31,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82376490
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82376490;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82375c68
	ctx.lr = 0x823764A8;
	sub_82375C68(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r31,2972(r30)
	REX_STORE_U8(ctx.r30.u32 + 2972, ctx.r31.u8);
loc_823764B0:
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

DEFINE_REX_FUNC(sub_8237D1F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0264
	ctx.lr = 0x8237D200;
	__savegprlr_15(ctx, base);
	// stwu r1,-800(r1)
	ea = -800 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// bl 0x82367210
	ctx.lr = 0x8237D214;
	sub_82367210(ctx, base);
	// bl 0x8238d810
	ctx.lr = 0x8237D218;
	sub_8238D810(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237dfc4
	if (ctx.cr6.eq) goto loc_8237DFC4;
	// bl 0x8238d810
	ctx.lr = 0x8237D224;
	sub_8238D810(ctx, base);
	// bl 0x8243e430
	ctx.lr = 0x8237D228;
	sub_8243E430(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237dfc4
	if (ctx.cr6.eq) goto loc_8237DFC4;
	// addic. r15,r3,160
	ctx.xer.ca = ctx.r3.u32 > 4294967135;
	ctx.r15.s64 = ctx.r3.s64 + 160;
	ctx.cr0.compare<int32_t>(ctx.r15.s32, 0, ctx.xer);
	// beq 0x8237dfc4
	if (ctx.cr0.eq) goto loc_8237DFC4;
	// lbz r3,80(r15)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r15.u32 + 80);
	// bl 0x822f39f8
	ctx.lr = 0x8237D240;
	sub_822F39F8(ctx, base);
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,500
	ctx.r5.s64 = 500;
	// li r4,1000
	ctx.r4.s64 = 1000;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8237D260;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x82305298
	ctx.lr = 0x8237D26C;
	sub_82305298(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8236f7a8
	ctx.lr = 0x8237D27C;
	sub_8236F7A8(ctx, base);
	// lwz r9,2976(r20)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r20.u32 + 2976);
	// addi r3,r20,2976
	ctx.r3.s64 = ctx.r20.s64 + 2976;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-1
	ctx.r4.s64 = -65536;
	// lwz r8,84(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8237D298;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r5,7378(r20)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r20.u32 + 7378);
	// addi r31,r20,7408
	ctx.r31.s64 = ctx.r20.s64 + 7408;
	// li r7,0
	ctx.r7.s64 = 0;
	// lhz r4,7376(r20)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r20.u32 + 7376);
	// addi r11,r5,15
	ctx.r11.s64 = ctx.r5.s64 + 15;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r5,7378(r20)
	REX_STORE_U16(ctx.r20.u32 + 7378, ctx.r5.u16);
	// bl 0x8236ccf8
	ctx.lr = 0x8237D2C0;
	sub_8236CCF8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x82305298
	ctx.lr = 0x8237D2CC;
	sub_82305298(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82228870
	ctx.lr = 0x8237D2D8;
	sub_82228870(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,90
	ctx.r5.s64 = 90;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x823689e0
	ctx.lr = 0x8237D2EC;
	sub_823689E0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x8236fb38
	ctx.lr = 0x8237D2F8;
	sub_8236FB38(ctx, base);
	// li r10,43
	ctx.r10.s64 = 43;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r15,25328
	ctx.r11.s64 = ctx.r15.s64 + 25328;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8237D314:
	// cmpwi cr6,r4,38
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 38, ctx.xer);
	// beq cr6,0x8237d35c
	if (ctx.cr6.eq) goto loc_8237D35C;
	// cmpwi cr6,r4,39
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 39, ctx.xer);
	// beq cr6,0x8237d35c
	if (ctx.cr6.eq) goto loc_8237D35C;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,344(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 344);
	// lwz r7,172(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r8,-172(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -172);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,-344(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -344);
	// lwz r5,516(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 516);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lwz r10,-860(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -860);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// add r29,r9,r29
	ctx.r29.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r30,r8,r30
	ctx.r30.u64 = ctx.r8.u64 + ctx.r30.u64;
	// add r27,r10,r27
	ctx.r27.u64 = ctx.r10.u64 + ctx.r27.u64;
loc_8237D35C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8237d314
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8237D314;
	// lis r11,15258
	ctx.r11.s64 = 999948288;
	// ori r17,r11,51711
	ctx.r17.u64 = ctx.r11.u64 | 51711;
	// cmplw cr6,r29,r17
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d37c
	if (!ctx.cr6.gt) goto loc_8237D37C;
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
loc_8237D37C:
	// cmplw cr6,r30,r17
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d388
	if (!ctx.cr6.gt) goto loc_8237D388;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
loc_8237D388:
	// cmplw cr6,r27,r17
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d394
	if (!ctx.cr6.gt) goto loc_8237D394;
	// mr r27,r17
	ctx.r27.u64 = ctx.r17.u64;
loc_8237D394:
	// lis r9,549
	ctx.r9.s64 = 35979264;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r8,-30584
	ctx.r8.s64 = -2004353024;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r24,60
	ctx.r24.s64 = 60;
	// ori r23,r9,20735
	ctx.r23.u64 = ctx.r9.u64 | 20735;
	// ori r28,r8,34953
	ctx.r28.u64 = ctx.r8.u64 | 34953;
	// li r22,3600
	ctx.r22.s64 = 3600;
	// lis r19,-32256
	ctx.r19.s64 = -2113929216;
	// addi r16,r10,-14288
	ctx.r16.s64 = ctx.r10.s64 + -14288;
	// addi r21,r11,23664
	ctx.r21.s64 = ctx.r11.s64 + 23664;
loc_8237D3C4:
	// mulli r11,r25,1120
	ctx.r11.s64 = static_cast<int64_t>(ctx.r25.u64 * static_cast<uint64_t>(1120));
	// lhz r10,7376(r20)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r20.u32 + 7376);
	// lhz r5,7378(r20)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r20.u32 + 7378);
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// addi r9,r10,20
	ctx.r9.s64 = ctx.r10.s64 + 20;
	// addi r26,r11,10288
	ctx.r26.s64 = ctx.r11.s64 + 10288;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// extsh r4,r9
	ctx.r4.s64 = ctx.r9.s16;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82367f48
	ctx.lr = 0x8237D3F0;
	sub_82367F48(ctx, base);
	// cmplwi cr6,r25,3
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 3, ctx.xer);
	// bgt cr6,0x8237d6d0
	if (ctx.cr6.gt) goto loc_8237D6D0;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8237d4e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237D4E4;
	// bdzf 4*cr6+eq,0x8237d5a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237D5A8;
	// bne cr6,0x8237d638
	if (!ctx.cr6.eq) goto loc_8237D638;
	// lwz r11,92(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 92);
	// divwu r11,r11,r24
	ctx.r11.u64 = uint32_t(ctx.r24.u32 ? ctx.r11.u32 / ctx.r24.u32 : 0);
	// cmplw cr6,r11,r23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r23.u32, ctx.xer);
	// ble cr6,0x8237d420
	if (!ctx.cr6.gt) goto loc_8237D420;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_8237D420:
	// divwu r10,r11,r24
	ctx.r10.u64 = uint32_t(ctx.r24.u32 ? ctx.r11.u32 / ctx.r24.u32 : 0);
	// mulhwu r9,r11,r28
	ctx.r9.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// mulhwu r8,r10,r28
	ctx.r8.u64 = (uint64_t(ctx.r10.u32) * uint64_t(ctx.r28.u32)) >> 32;
	// rlwinm r7,r9,27,5,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r6,r8,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// mulli r5,r7,60
	ctx.r5.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(60));
	// mulli r4,r6,60
	ctx.r4.s64 = static_cast<int64_t>(ctx.r6.u64 * static_cast<uint64_t>(60));
	// subf r3,r5,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r5.u64;
	// subf r8,r4,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r4.u64;
	// divwu r11,r11,r22
	ctx.r11.u64 = uint32_t(ctx.r22.u32 ? ctx.r11.u32 / ctx.r22.u32 : 0);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82365080
	ctx.lr = 0x8237D46C;
	sub_82365080(ctx, base);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d48c
	if (ctx.cr6.eq) goto loc_8237D48C;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237d490
	if (ctx.cr6.eq) goto loc_8237D490;
loc_8237D48C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237D490:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237d4b0
	if (ctx.cr6.eq) goto loc_8237D4B0;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237d4b4
	if (!ctx.cr6.eq) goto loc_8237D4B4;
loc_8237D4B0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237D4B4:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237d4d8
	if (ctx.cr6.eq) goto loc_8237D4D8;
	// li r5,5
	ctx.r5.s64 = 5;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237D4CC;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r16,-136
	ctx.r4.s64 = ctx.r16.s64 + -136;
	// b 0x8237d6c4
	goto loc_8237D6C4;
loc_8237D4D8:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r16,-136
	ctx.r4.s64 = ctx.r16.s64 + -136;
	// b 0x8237d6c4
	goto loc_8237D6C4;
loc_8237D4E4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82364c58
	ctx.lr = 0x8237D4F4;
	sub_82364C58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821ca958
	ctx.lr = 0x8237D4FC;
	sub_821CA958(ctx, base);
	// ori r31,r3,95
	ctx.r31.u64 = ctx.r3.u64 | 95;
	// bl 0x8235e5a0
	ctx.lr = 0x8237D504;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8237d514
	if (!ctx.cr6.eq) goto loc_8237D514;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8237d524
	goto loc_8237D524;
loc_8237D514:
	// bl 0x8235e5a0
	ctx.lr = 0x8237D518;
	sub_8235E5A0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823616a0
	ctx.lr = 0x8237D520;
	sub_823616A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8237D524:
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d544
	if (ctx.cr6.eq) goto loc_8237D544;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237d548
	if (ctx.cr6.eq) goto loc_8237D548;
loc_8237D544:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237D548:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237d568
	if (ctx.cr6.eq) goto loc_8237D568;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237d56c
	if (!ctx.cr6.eq) goto loc_8237D56C;
loc_8237D568:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237D56C:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237d58c
	if (ctx.cr6.eq) goto loc_8237D58C;
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237D584;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8237d590
	goto loc_8237D590;
loc_8237D58C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8237D590:
	// addi r4,r16,-124
	ctx.r4.s64 = ctx.r16.s64 + -124;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237D5A4;
	sub_826A2638(ctx, base);
	// b 0x8237d6d0
	goto loc_8237D6D0;
loc_8237D5A8:
	// li r7,1
	ctx.r7.s64 = 1;
	// add r6,r30,r29
	ctx.r6.u64 = ctx.r30.u64 + ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823653f8
	ctx.lr = 0x8237D5C0;
	sub_823653F8(ctx, base);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d5e0
	if (ctx.cr6.eq) goto loc_8237D5E0;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237d5e4
	if (ctx.cr6.eq) goto loc_8237D5E4;
loc_8237D5E0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237D5E4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237d604
	if (ctx.cr6.eq) goto loc_8237D604;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237d608
	if (!ctx.cr6.eq) goto loc_8237D608;
loc_8237D604:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237D608:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237d62c
	if (ctx.cr6.eq) goto loc_8237D62C;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237D620;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r16,-112
	ctx.r4.s64 = ctx.r16.s64 + -112;
	// b 0x8237d6c4
	goto loc_8237D6C4;
loc_8237D62C:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r16,-112
	ctx.r4.s64 = ctx.r16.s64 + -112;
	// b 0x8237d6c4
	goto loc_8237D6C4;
loc_8237D638:
	// lwz r4,88(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 88);
	// cmplw cr6,r4,r17
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d648
	if (!ctx.cr6.gt) goto loc_8237D648;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
loc_8237D648:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82364c58
	ctx.lr = 0x8237D654;
	sub_82364C58(ctx, base);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d674
	if (ctx.cr6.eq) goto loc_8237D674;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237d678
	if (ctx.cr6.eq) goto loc_8237D678;
loc_8237D674:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237D678:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237d698
	if (ctx.cr6.eq) goto loc_8237D698;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237d69c
	if (!ctx.cr6.eq) goto loc_8237D69C;
loc_8237D698:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237D69C:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237d6bc
	if (ctx.cr6.eq) goto loc_8237D6BC;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237D6B4;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8237d6c0
	goto loc_8237D6C0;
loc_8237D6BC:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8237D6C0:
	// addi r4,r16,-100
	ctx.r4.s64 = ctx.r16.s64 + -100;
loc_8237D6C4:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237D6D0;
	sub_826A2638(ctx, base);
loc_8237D6D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82228870
	ctx.lr = 0x8237D6D8;
	sub_82228870(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// bl 0x823689e0
	ctx.lr = 0x8237D6EC;
	sub_823689E0(ctx, base);
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// beq cr6,0x8237d700
	if (ctx.cr6.eq) goto loc_8237D700;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x8236fb38
	ctx.lr = 0x8237D700;
	sub_8236FB38(ctx, base);
loc_8237D700:
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// cmpwi cr6,r25,4
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 4, ctx.xer);
	// blt cr6,0x8237d3c4
	if (ctx.cr6.lt) goto loc_8237D3C4;
	// lhz r11,7378(r20)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r20.u32 + 7378);
	// addi r30,r20,8848
	ctx.r30.s64 = ctx.r20.s64 + 8848;
	// li r7,0
	ctx.r7.s64 = 0;
	// lhz r4,7376(r20)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r20.u32 + 7376);
	// addi r10,r11,20
	ctx.r10.s64 = ctx.r11.s64 + 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// sth r5,7378(r20)
	REX_STORE_U16(ctx.r20.u32 + 7378, ctx.r5.u16);
	// bl 0x8236ccf8
	ctx.lr = 0x8237D734;
	sub_8236CCF8(ctx, base);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d754
	if (ctx.cr6.eq) goto loc_8237D754;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237d758
	if (ctx.cr6.eq) goto loc_8237D758;
loc_8237D754:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237D758:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237d778
	if (ctx.cr6.eq) goto loc_8237D778;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237d77c
	if (!ctx.cr6.eq) goto loc_8237D77C;
loc_8237D778:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237D77C:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237d79c
	if (ctx.cr6.eq) goto loc_8237D79C;
	// li r5,9
	ctx.r5.s64 = 9;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237D794;
	sub_823646C0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8237d7a0
	goto loc_8237D7A0;
loc_8237D79C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8237D7A0:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82228870
	ctx.lr = 0x8237D7A8;
	sub_82228870(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,90
	ctx.r5.s64 = 90;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// bl 0x823689e0
	ctx.lr = 0x8237D7BC;
	sub_823689E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x8236fb38
	ctx.lr = 0x8237D7C8;
	sub_8236FB38(ctx, base);
	// lhz r11,7378(r20)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r20.u32 + 7378);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r10,r11,10
	ctx.r10.s64 = ctx.r11.s64 + 10;
	// sth r10,7378(r20)
	REX_STORE_U16(ctx.r20.u32 + 7378, ctx.r10.u16);
loc_8237D7D8:
	// mulli r11,r28,1120
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(1120));
	// lhz r10,7376(r20)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r20.u32 + 7376);
	// lhz r5,7378(r20)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r20.u32 + 7378);
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// addi r9,r10,20
	ctx.r9.s64 = ctx.r10.s64 + 20;
	// addi r27,r11,14768
	ctx.r27.s64 = ctx.r11.s64 + 14768;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// extsh r4,r9
	ctx.r4.s64 = ctx.r9.s16;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82367f48
	ctx.lr = 0x8237D804;
	sub_82367F48(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r28,7
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 7, ctx.xer);
	// bgt cr6,0x8237df60
	if (ctx.cr6.gt) goto loc_8237DF60;
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8237d8f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237D8F4;
	// bdzf 4*cr6+eq,0x8237d9b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237D9B4;
	// bdzf 4*cr6+eq,0x8237daa8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237DAA8;
	// bdzf 4*cr6+eq,0x8237dce8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237DCE8;
	// bdzf 4*cr6+eq,0x8237dce8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237DCE8;
	// bdzf 4*cr6+eq,0x8237df5c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8237DF5C;
	// bne cr6,0x8237df5c
	if (!ctx.cr6.eq) goto loc_8237DF5C;
	// lwz r4,26016(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 26016);
	// lwz r5,26020(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 26020);
	// cmplw cr6,r4,r17
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d848
	if (!ctx.cr6.gt) goto loc_8237D848;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
loc_8237D848:
	// cmplw cr6,r5,r17
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d854
	if (!ctx.cr6.gt) goto loc_8237D854;
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
loc_8237D854:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823653f8
	ctx.lr = 0x8237D864;
	sub_823653F8(ctx, base);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d884
	if (ctx.cr6.eq) goto loc_8237D884;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237d888
	if (ctx.cr6.eq) goto loc_8237D888;
loc_8237D884:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237D888:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237d8a8
	if (ctx.cr6.eq) goto loc_8237D8A8;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237d8ac
	if (!ctx.cr6.eq) goto loc_8237D8AC;
loc_8237D8A8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237D8AC:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237d8dc
	if (ctx.cr6.eq) goto loc_8237D8DC;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237D8C4;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r16,-88
	ctx.r4.s64 = ctx.r16.s64 + -88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237D8D8;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237D8DC:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r16,-88
	ctx.r4.s64 = ctx.r16.s64 + -88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237D8F0;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237D8F4:
	// lwz r4,26024(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 26024);
	// lwz r5,26028(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 26028);
	// cmplw cr6,r4,r17
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d908
	if (!ctx.cr6.gt) goto loc_8237D908;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
loc_8237D908:
	// cmplw cr6,r5,r17
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237d914
	if (!ctx.cr6.gt) goto loc_8237D914;
	// mr r5,r17
	ctx.r5.u64 = ctx.r17.u64;
loc_8237D914:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823653f8
	ctx.lr = 0x8237D924;
	sub_823653F8(ctx, base);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d944
	if (ctx.cr6.eq) goto loc_8237D944;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237d948
	if (ctx.cr6.eq) goto loc_8237D948;
loc_8237D944:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237D948:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237d968
	if (ctx.cr6.eq) goto loc_8237D968;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237d96c
	if (!ctx.cr6.eq) goto loc_8237D96C;
loc_8237D968:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237D96C:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237d99c
	if (ctx.cr6.eq) goto loc_8237D99C;
	// li r5,11
	ctx.r5.s64 = 11;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237D984;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r16,-76
	ctx.r4.s64 = ctx.r16.s64 + -76;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237D998;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237D99C:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r16,-76
	ctx.r4.s64 = ctx.r16.s64 + -76;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237D9B0;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237D9B4:
	// li r11,43
	ctx.r11.s64 = 43;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r4,r4,32320
	ctx.r4.u64 = ctx.r4.u64 | 32320;
	// addi r10,r15,300
	ctx.r10.s64 = ctx.r15.s64 + 300;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8237D9CC:
	// cmpwi cr6,r9,38
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 38, ctx.xer);
	// beq cr6,0x8237d9f4
	if (ctx.cr6.eq) goto loc_8237D9F4;
	// cmpwi cr6,r9,39
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 39, ctx.xer);
	// beq cr6,0x8237d9f4
	if (ctx.cr6.eq) goto loc_8237D9F4;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8237d9f4
	if (!ctx.cr6.gt) goto loc_8237D9F4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237d9f4
	if (ctx.cr6.eq) goto loc_8237D9F4;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
loc_8237D9F4:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8237d9cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8237D9CC;
	// cmplw cr6,r4,r17
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237da0c
	if (!ctx.cr6.gt) goto loc_8237DA0C;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
loc_8237DA0C:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82365248
	ctx.lr = 0x8237DA18;
	sub_82365248(ctx, base);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237da38
	if (ctx.cr6.eq) goto loc_8237DA38;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237da3c
	if (ctx.cr6.eq) goto loc_8237DA3C;
loc_8237DA38:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DA3C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237da5c
	if (ctx.cr6.eq) goto loc_8237DA5C;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237da60
	if (!ctx.cr6.eq) goto loc_8237DA60;
loc_8237DA5C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237DA60:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237da90
	if (ctx.cr6.eq) goto loc_8237DA90;
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DA78;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r16,-64
	ctx.r4.s64 = ctx.r16.s64 + -64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237DA8C;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237DA90:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r16,-64
	ctx.r4.s64 = ctx.r16.s64 + -64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237DAA4;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237DAA8:
	// li r11,43
	ctx.r11.s64 = 43;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r15,472
	ctx.r10.s64 = ctx.r15.s64 + 472;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8237DABC:
	// cmpwi cr6,r9,38
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 38, ctx.xer);
	// beq cr6,0x8237dadc
	if (ctx.cr6.eq) goto loc_8237DADC;
	// cmpwi cr6,r9,39
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 39, ctx.xer);
	// beq cr6,0x8237dadc
	if (ctx.cr6.eq) goto loc_8237DADC;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8237dadc
	if (!ctx.cr6.lt) goto loc_8237DADC;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8237DADC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8237dabc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8237DABC;
	// cmplw cr6,r30,r17
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237daf8
	if (!ctx.cr6.gt) goto loc_8237DAF8;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// b 0x8237db00
	goto loc_8237DB00;
loc_8237DAF8:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// ble cr6,0x8237dbf4
	if (!ctx.cr6.gt) goto loc_8237DBF4;
loc_8237DB00:
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// lwz r8,20(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237db20
	if (ctx.cr6.eq) goto loc_8237DB20;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237db24
	if (ctx.cr6.eq) goto loc_8237DB24;
loc_8237DB20:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DB24:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,30048(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237db48
	if (ctx.cr6.eq) goto loc_8237DB48;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 & ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8237db4c
	if (!ctx.cr6.eq) goto loc_8237DB4C;
loc_8237DB48:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DB4C:
	// lwz r3,896(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237db78
	if (ctx.cr6.eq) goto loc_8237DB78;
	// li r5,21
	ctx.r5.s64 = 21;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DB64;
	sub_823646C0(ctx, base);
	// lwz r8,20(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,30048(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// b 0x8237db7c
	goto loc_8237DB7C;
loc_8237DB78:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8237DB7C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237db94
	if (ctx.cr6.eq) goto loc_8237DB94;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237db98
	if (ctx.cr6.eq) goto loc_8237DB98;
loc_8237DB94:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DB98:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237dbb4
	if (ctx.cr6.eq) goto loc_8237DBB4;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8237dbb8
	if (!ctx.cr6.eq) goto loc_8237DBB8;
loc_8237DBB4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237DBB8:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237dbd8
	if (ctx.cr6.eq) goto loc_8237DBD8;
	// li r5,13
	ctx.r5.s64 = 13;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DBD0;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8237dbdc
	goto loc_8237DBDC;
loc_8237DBD8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8237DBDC:
	// addi r4,r16,-52
	ctx.r4.s64 = ctx.r16.s64 + -52;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237DBF0;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237DBF4:
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// lwz r8,20(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237dc14
	if (ctx.cr6.eq) goto loc_8237DC14;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237dc18
	if (ctx.cr6.eq) goto loc_8237DC18;
loc_8237DC14:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DC18:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,30048(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237dc3c
	if (ctx.cr6.eq) goto loc_8237DC3C;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 & ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8237dc40
	if (!ctx.cr6.eq) goto loc_8237DC40;
loc_8237DC3C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DC40:
	// lwz r3,896(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237dc6c
	if (ctx.cr6.eq) goto loc_8237DC6C;
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DC58;
	sub_823646C0(ctx, base);
	// lwz r8,20(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,30048(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// b 0x8237dc70
	goto loc_8237DC70;
loc_8237DC6C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8237DC70:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237dc88
	if (ctx.cr6.eq) goto loc_8237DC88;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237dc8c
	if (ctx.cr6.eq) goto loc_8237DC8C;
loc_8237DC88:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DC8C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237dca8
	if (ctx.cr6.eq) goto loc_8237DCA8;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8237dcac
	if (!ctx.cr6.eq) goto loc_8237DCAC;
loc_8237DCA8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237DCAC:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237dccc
	if (ctx.cr6.eq) goto loc_8237DCCC;
	// li r5,13
	ctx.r5.s64 = 13;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DCC4;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8237dcd0
	goto loc_8237DCD0;
loc_8237DCCC:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8237DCD0:
	// addi r4,r16,-40
	ctx.r4.s64 = ctx.r16.s64 + -40;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237DCE4;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237DCE8:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r6,r15,7180
	ctx.r6.s64 = ctx.r15.s64 + 7180;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8237DCF8:
	// li r11,43
	ctx.r11.s64 = 43;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8237DD0C:
	// cmpwi cr6,r7,38
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 38, ctx.xer);
	// beq cr6,0x8237dd3c
	if (ctx.cr6.eq) goto loc_8237DD3C;
	// cmpwi cr6,r28,4
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 4, ctx.xer);
	// addi r11,r9,-6536
	ctx.r11.s64 = ctx.r9.s64 + -6536;
	// beq cr6,0x8237dd24
	if (ctx.cr6.eq) goto loc_8237DD24;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_8237DD24:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237dd38
	if (ctx.cr6.eq) goto loc_8237DD38;
	// lwzx r5,r8,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x8237dd3c
	if (!ctx.cr6.lt) goto loc_8237DD3C;
loc_8237DD38:
	// lwzx r10,r8,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
loc_8237DD3C:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r9,r9,152
	ctx.r9.s64 = ctx.r9.s64 + 152;
	// bdnz 0x8237dd0c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8237DD0C;
	// addic r11,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// subfe r7,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 + ctx.r4.u64;
	// and r29,r7,r29
	ctx.r29.u64 = ctx.r7.u64 & ctx.r29.u64;
	// cmpwi cr6,r8,152
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 152, ctx.xer);
	// blt cr6,0x8237dcf8
	if (ctx.cr6.lt) goto loc_8237DCF8;
	// cmplw cr6,r4,r17
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r17.u32, ctx.xer);
	// ble cr6,0x8237dd70
	if (!ctx.cr6.gt) goto loc_8237DD70;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
loc_8237DD70:
	// cmpwi cr6,r28,4
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 4, ctx.xer);
	// bne cr6,0x8237de38
	if (!ctx.cr6.eq) goto loc_8237DE38;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82364c58
	ctx.lr = 0x8237DD84;
	sub_82364C58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821ca958
	ctx.lr = 0x8237DD8C;
	sub_821CA958(ctx, base);
	// ori r31,r3,95
	ctx.r31.u64 = ctx.r3.u64 | 95;
	// bl 0x8235e5a0
	ctx.lr = 0x8237DD94;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8237dda4
	if (!ctx.cr6.eq) goto loc_8237DDA4;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8237ddb4
	goto loc_8237DDB4;
loc_8237DDA4:
	// bl 0x8235e5a0
	ctx.lr = 0x8237DDA8;
	sub_8235E5A0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823616a0
	ctx.lr = 0x8237DDB0;
	sub_823616A0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8237DDB4:
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237ddd4
	if (ctx.cr6.eq) goto loc_8237DDD4;
	// lwz r10,20(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237ddd8
	if (ctx.cr6.eq) goto loc_8237DDD8;
loc_8237DDD4:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DDD8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237ddf8
	if (ctx.cr6.eq) goto loc_8237DDF8;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r10,30048(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8237ddfc
	if (!ctx.cr6.eq) goto loc_8237DDFC;
loc_8237DDF8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237DDFC:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237de1c
	if (ctx.cr6.eq) goto loc_8237DE1C;
	// li r5,14
	ctx.r5.s64 = 14;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DE14;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8237de20
	goto loc_8237DE20;
loc_8237DE1C:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8237DE20:
	// addi r4,r16,-12
	ctx.r4.s64 = ctx.r16.s64 + -12;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237DE34;
	sub_826A2638(ctx, base);
	// b 0x8237df60
	goto loc_8237DF60;
loc_8237DE38:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821ca958
	ctx.lr = 0x8237DE40;
	sub_821CA958(ctx, base);
	// ori r31,r3,95
	ctx.r31.u64 = ctx.r3.u64 | 95;
	// bl 0x8235e5a0
	ctx.lr = 0x8237DE48;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8237de58
	if (!ctx.cr6.eq) goto loc_8237DE58;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8237de68
	goto loc_8237DE68;
loc_8237DE58:
	// bl 0x8235e5a0
	ctx.lr = 0x8237DE5C;
	sub_8235E5A0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x823616a0
	ctx.lr = 0x8237DE64;
	sub_823616A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8237DE68:
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// lwz r8,20(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237de88
	if (ctx.cr6.eq) goto loc_8237DE88;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237de8c
	if (ctx.cr6.eq) goto loc_8237DE8C;
loc_8237DE88:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DE8C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,30048(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237deb0
	if (ctx.cr6.eq) goto loc_8237DEB0;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 & ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8237deb4
	if (!ctx.cr6.eq) goto loc_8237DEB4;
loc_8237DEB0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DEB4:
	// lwz r3,896(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237dee0
	if (ctx.cr6.eq) goto loc_8237DEE0;
	// li r5,17
	ctx.r5.s64 = 17;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DECC;
	sub_823646C0(ctx, base);
	// lwz r8,20(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + 20);
	// lwz r11,16(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,30048(r19)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r19.u32 + 30048);
	// b 0x8237dee4
	goto loc_8237DEE4;
loc_8237DEE0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8237DEE4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8237defc
	if (ctx.cr6.eq) goto loc_8237DEFC;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237df00
	if (ctx.cr6.eq) goto loc_8237DF00;
loc_8237DEFC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237DF00:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8237df1c
	if (ctx.cr6.eq) goto loc_8237DF1C;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// and r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8237df20
	if (!ctx.cr6.eq) goto loc_8237DF20;
loc_8237DF1C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237DF20:
	// lwz r3,896(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 896);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8237df40
	if (ctx.cr6.eq) goto loc_8237DF40;
	// li r5,14
	ctx.r5.s64 = 14;
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// bl 0x823646c0
	ctx.lr = 0x8237DF38;
	sub_823646C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8237df44
	goto loc_8237DF44;
loc_8237DF40:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8237DF44:
	// mr r4,r16
	ctx.r4.u64 = ctx.r16.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x826a2638
	ctx.lr = 0x8237DF5C;
	sub_826A2638(ctx, base);
loc_8237DF5C:
	// li r29,1
	ctx.r29.s64 = 1;
loc_8237DF60:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82228870
	ctx.lr = 0x8237DF68;
	sub_82228870(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r5,100
	ctx.r5.s64 = 100;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// bl 0x823689e0
	ctx.lr = 0x8237DF7C;
	sub_823689E0(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8237df90
	if (!ctx.cr6.eq) goto loc_8237DF90;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x8236fb38
	ctx.lr = 0x8237DF90;
	sub_8236FB38(ctx, base);
loc_8237DF90:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpwi cr6,r28,8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 8, ctx.xer);
	// blt cr6,0x8237d7d8
	if (ctx.cr6.lt) goto loc_8237D7D8;
	// lwz r10,0(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lhz r11,7378(r20)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r20.u32 + 7378);
	// li r4,1000
	ctx.r4.s64 = 1000;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// addi r9,r11,80
	ctx.r9.s64 = ctx.r11.s64 + 80;
	// lwz r8,72(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8237DFC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8237DFC4:
	// addi r1,r1,800
	ctx.r1.s64 = ctx.r1.s64 + 800;
	// b 0x826a02b4
	__restgprlr_15(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CCA48) {
	REX_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x823cca8c
	if (!ctx.cr6.eq) goto loc_823CCA8C;
	// lbz r11,1(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x823cca8c
	if (!ctx.cr6.eq) goto loc_823CCA8C;
	// lbz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,2(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x823cca8c
	if (!ctx.cr6.eq) goto loc_823CCA8C;
	// lbz r11,3(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,3(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823cca90
	if (ctx.cr6.eq) goto loc_823CCA90;
loc_823CCA8C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823CCA90:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823CE930) {
	REX_FUNC_PROLOGUE();
	// lwz r11,328(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 328);
	// li r10,152
	ctx.r10.s64 = 152;
	// lwz r9,332(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 332);
	// subf r8,r11,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r11.u64;
	// divw r7,r8,r10
	ctx.r7.u64 = uint32_t((ctx.r10.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r10.s32 == -1)) ? ctx.r8.s32 / ctx.r10.s32 : 0);
	// cmplw cr6,r4,r7
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x823ce950
	if (ctx.cr6.lt) goto loc_823CE950;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823CE950:
	// mulli r10,r4,152
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(152));
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823D1598) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x823D15A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// ori r9,r10,43912
	ctx.r9.u64 = ctx.r10.u64 | 43912;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r8,4
	ctx.r8.s64 = 4;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r8,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r8.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stwx r31,r3,r9
	REX_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r31.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823d15f0
	if (ctx.cr6.eq) goto loc_823D15F0;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x823d15f4
	if (ctx.cr6.eq) goto loc_823D15F4;
loc_823D15F0:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_823D15F4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823d1618
	if (ctx.cr6.eq) goto loc_823D1618;
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
	// bne cr6,0x823d161c
	if (!ctx.cr6.eq) goto loc_823D161C;
loc_823D1618:
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
loc_823D161C:
	// lwz r27,852(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + 852);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8224be70
	ctx.lr = 0x823D162C;
	sub_8224BE70(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r31,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// addi r9,r11,12400
	ctx.r9.s64 = ctx.r11.s64 + 12400;
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// addi r8,r10,12392
	ctx.r8.s64 = ctx.r10.s64 + 12392;
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// stw r8,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// stw r31,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r31.u32);
	// stw r31,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r31.u32);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x8226bf28
	ctx.lr = 0x823D1664;
	sub_8226BF28(ctx, base);
	// li r6,16
	ctx.r6.s64 = 16;
	// lis r7,-32195
	ctx.r7.s64 = -2109931520;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// addi r7,r7,2432
	ctx.r7.s64 = ctx.r7.s64 + 2432;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8224e7c8
	ctx.lr = 0x823D1694;
	sub_8224E7C8(ctx, base);
	// addi r3,r1,132
	ctx.r3.s64 = ctx.r1.s64 + 132;
	// bl 0x82218850
	ctx.lr = 0x823D169C;
	sub_82218850(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D6B00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x823D6B08;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// std r5,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// lwz r29,180(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// std r6,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r6.u64);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x823d6b48
	if (ctx.cr6.eq) goto loc_823D6B48;
	// lwz r11,12(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x823d6b48
	if (ctx.cr6.gt) goto loc_823D6B48;
	// lwz r11,16(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 16);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x823d6b4c
	if (!ctx.cr6.gt) goto loc_823D6B4C;
loc_823D6B48:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823D6B4C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r30,188(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// stw r29,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r29.u32);
	// cmplw cr6,r9,r30
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r30.u32, ctx.xer);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// bgt cr6,0x823d6b74
	if (ctx.cr6.gt) goto loc_823D6B74;
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x823d6b78
	if (!ctx.cr6.gt) goto loc_823D6B78;
loc_823D6B74:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823D6B78:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823d6b84
	if (!ctx.cr6.eq) goto loc_823D6B84;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_823D6B84:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x823d6be8
	if (ctx.cr6.eq) goto loc_823D6BE8;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// addi r9,r1,81
	ctx.r9.s64 = ctx.r1.s64 + 81;
	// lwz r27,16(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// stb r10,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r7,81(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// bl 0x823d6970
	ctx.lr = 0x823D6BBC;
	sub_823D6970(ctx, base);
	// subf r8,r30,r27
	ctx.r8.u64 = ctx.r27.u64 - ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// li r7,76
	ctx.r7.s64 = 76;
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// addi r5,r31,8
	ctx.r5.s64 = ctx.r31.s64 + 8;
	// divw r3,r8,r7
	ctx.r3.u64 = uint32_t((ctx.r7.s32 && !(ctx.r8.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r8.s32 / ctx.r7.s32 : 0);
	// mulli r11,r3,76
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(76));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823d69d8
	ctx.lr = 0x823D6BE4;
	sub_823D69D8(ctx, base);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
loc_823D6BE8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E48B8) {
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
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x826a1130
	ctx.lr = 0x823E48E4;
	rexcrt_memcpy(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_823E5C78) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823e5cfc
	if (ctx.cr6.eq) goto loc_823E5CFC;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x823e5ca8
	if (ctx.cr6.eq) goto loc_823E5CA8;
	// lis r3,-32683
	ctx.r3.s64 = -2141913088;
	// ori r3,r3,18
	ctx.r3.u64 = ctx.r3.u64 | 18;
	// blr 
	return;
loc_823E5CA8:
	// lwz r10,8(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x823e5cdc
	if (ctx.cr6.lt) goto loc_823E5CDC;
	// lwz r8,12(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r7,44(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r3,r7
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r7.u32, ctx.xer);
	// bgt cr6,0x823e5cdc
	if (ctx.cr6.gt) goto loc_823E5CDC;
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x823e5ce0
	goto loc_823E5CE0;
loc_823E5CDC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823E5CE0:
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823e5cfc
	if (ctx.cr6.eq) goto loc_823E5CFC;
	// lwz r11,12(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_823E5CFC:
	// lis r3,-32683
	ctx.r3.s64 = -2141913088;
	// ori r3,r3,8
	ctx.r3.u64 = ctx.r3.u64 | 8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823E8A60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x823E8A68;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// bl 0x823e7bf0
	ctx.lr = 0x823E8A7C;
	sub_823E7BF0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823e8a90
	if (!ctx.cr6.eq) goto loc_823E8A90;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
loc_823E8A90:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x823eec30
	ctx.lr = 0x823E8A98;
	sub_823EEC30(ctx, base);
	// bl 0x823eec30
	ctx.lr = 0x823E8A9C;
	sub_823EEC30(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823e8c88
	if (ctx.cr6.eq) goto loc_823E8C88;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,4221
	ctx.r31.s64 = ctx.r11.s64 + 4221;
	// addi r26,r10,21712
	ctx.r26.s64 = ctx.r10.s64 + 21712;
	// lfs f31,2880(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
loc_823E8AC0:
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823e8ad0
	if (!ctx.cr6.eq) goto loc_823E8AD0;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_823E8AD0:
	// addi r10,r31,203
	ctx.r10.s64 = ctx.r31.s64 + 203;
loc_823E8AD4:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq cr6,0x823e8af8
	if (ctx.cr6.eq) goto loc_823E8AF8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x823e8ad4
	if (ctx.cr6.eq) goto loc_823E8AD4;
loc_823E8AF8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x823e8c74
	if (!ctx.cr6.eq) goto loc_823E8C74;
	// addi r29,r27,28
	ctx.r29.s64 = ctx.r27.s64 + 28;
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r31,-22
	ctx.r5.s64 = ctx.r31.s64 + -22;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r31,211
	ctx.r4.s64 = ctx.r31.s64 + 211;
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,176(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f31,180(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f31,192(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f31,196(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f31,200(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f31,204(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f31,208(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f31,212(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// bl 0x823ee930
	ctx.lr = 0x823E8B84;
	sub_823EE930(ctx, base);
	// bl 0x826a2910
	ctx.lr = 0x823E8B88;
	sub_826A2910(ctx, base);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// addi r5,r31,-15
	ctx.r5.s64 = ctx.r31.s64 + -15;
	// addi r4,r31,215
	ctx.r4.s64 = ctx.r31.s64 + 215;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ee930
	ctx.lr = 0x823E8B9C;
	sub_823EE930(ctx, base);
	// bl 0x826a2910
	ctx.lr = 0x823E8BA0;
	sub_826A2910(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// sth r3,100(r1)
	REX_STORE_U16(ctx.r1.u32 + 100, ctx.r3.u16);
	// addi r28,r1,100
	ctx.r28.s64 = ctx.r1.s64 + 100;
loc_823E8BAC:
	// addi r4,r31,223
	ctx.r4.s64 = ctx.r31.s64 + 223;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826a2638
	ctx.lr = 0x823E8BBC;
	sub_826A2638(ctx, base);
	// addi r5,r31,-14
	ctx.r5.s64 = ctx.r31.s64 + -14;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ee930
	ctx.lr = 0x823E8BCC;
	sub_823EE930(ctx, base);
	// bl 0x826a45a8
	ctx.lr = 0x823E8BD0;
	sub_826A45A8(ctx, base);
	// addi r4,r31,227
	ctx.r4.s64 = ctx.r31.s64 + 227;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f0,4(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// bl 0x826a2638
	ctx.lr = 0x823E8BE8;
	sub_826A2638(ctx, base);
	// addi r5,r31,-10
	ctx.r5.s64 = ctx.r31.s64 + -10;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ee930
	ctx.lr = 0x823E8BF8;
	sub_823EE930(ctx, base);
	// bl 0x826a45a8
	ctx.lr = 0x823E8BFC;
	sub_826A45A8(ctx, base);
	// addi r4,r31,231
	ctx.r4.s64 = ctx.r31.s64 + 231;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f13,8(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// bl 0x826a2638
	ctx.lr = 0x823E8C14;
	sub_826A2638(ctx, base);
	// addi r5,r31,-6
	ctx.r5.s64 = ctx.r31.s64 + -6;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ee930
	ctx.lr = 0x823E8C24;
	sub_823EE930(ctx, base);
	// bl 0x826a45a8
	ctx.lr = 0x823E8C28;
	sub_826A45A8(ctx, base);
	// addi r4,r31,235
	ctx.r4.s64 = ctx.r31.s64 + 235;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f12,12(r28)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r28.u32 + 12, temp.u32);
	// bl 0x826a2638
	ctx.lr = 0x823E8C40;
	sub_826A2638(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ee930
	ctx.lr = 0x823E8C50;
	sub_823EE930(ctx, base);
	// bl 0x826a45a8
	ctx.lr = 0x823E8C54;
	sub_826A45A8(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// stfsu f11,16(r28)
	ea = 16 + ctx.r28.u32;
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r28.u32 = ea;
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// blt cr6,0x823e8bac
	if (ctx.cr6.lt) goto loc_823E8BAC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x823eb510
	ctx.lr = 0x823E8C74;
	sub_823EB510(ctx, base);
loc_823E8C74:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823eec90
	ctx.lr = 0x823E8C7C;
	sub_823EEC90(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x823e8ac0
	if (!ctx.cr6.eq) goto loc_823E8AC0;
loc_823E8C88:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F6928) {
	REX_FUNC_PROLOGUE();
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 8);
	// extsb r10,r9
	ctx.r10.s64 = ctx.r9.s8;
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// bgt cr6,0x823f6b84
	if (ctx.cr6.gt) goto loc_823F6B84;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x823f69a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823F69A8;
	// bdzf 4*cr6+eq,0x823f69ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823F69EC;
	// bdzf 4*cr6+eq,0x823f6a30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823F6A30;
	// bdzf 4*cr6+eq,0x823f6a74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823F6A74;
	// bdzf 4*cr6+eq,0x823f6ab8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823F6AB8;
	// bdzf 4*cr6+eq,0x823f6afc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_823F6AFC;
	// bne cr6,0x823f6b40
	if (!ctx.cr6.eq) goto loc_823F6B40;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f697c
	if (ctx.cr6.gt) goto loc_823F697C;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,50000
	ctx.r3.u64 = ctx.r3.u64 | 50000;
	// blr 
	return;
loc_823F697C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfd f0,20952(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 20952);
	// fmul f12,f13,f0
	ctx.f12.f64 = ctx.f13.f64 * ctx.f0.f64;
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F69A8:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f69c0
	if (ctx.cr6.gt) goto loc_823F69C0;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// ori r3,r3,9464
	ctx.r3.u64 = ctx.r3.u64 | 9464;
	// blr 
	return;
loc_823F69C0:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfd f0,7336(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7336);
	// fmul f12,f13,f0
	ctx.f12.f64 = ctx.f13.f64 * ctx.f0.f64;
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F69EC:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f6a04
	if (ctx.cr6.gt) goto loc_823F6A04;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// ori r3,r3,34464
	ctx.r3.u64 = ctx.r3.u64 | 34464;
	// blr 
	return;
loc_823F6A04:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfd f0,7328(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7328);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F6A30:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f6a48
	if (ctx.cr6.gt) goto loc_823F6A48;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// ori r3,r3,59464
	ctx.r3.u64 = ctx.r3.u64 | 59464;
	// blr 
	return;
loc_823F6A48:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,7320(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7320);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F6A74:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f6a8c
	if (ctx.cr6.gt) goto loc_823F6A8C;
	// lis r3,2
	ctx.r3.s64 = 131072;
	// ori r3,r3,18928
	ctx.r3.u64 = ctx.r3.u64 | 18928;
	// blr 
	return;
loc_823F6A8C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,3768(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 3768);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F6AB8:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f6ad0
	if (ctx.cr6.gt) goto loc_823F6AD0;
	// lis r3,3
	ctx.r3.s64 = 196608;
	// ori r3,r3,3392
	ctx.r3.u64 = ctx.r3.u64 | 3392;
	// blr 
	return;
loc_823F6AD0:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,7312(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7312);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F6AFC:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f6b14
	if (ctx.cr6.gt) goto loc_823F6B14;
	// lis r3,3
	ctx.r3.s64 = 196608;
	// ori r3,r3,53392
	ctx.r3.u64 = ctx.r3.u64 | 53392;
	// blr 
	return;
loc_823F6B14:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,7304(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7304);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F6B40:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x823f6b58
	if (ctx.cr6.gt) goto loc_823F6B58;
	// lis r3,9
	ctx.r3.s64 = 589824;
	// ori r3,r3,10176
	ctx.r3.u64 = ctx.r3.u64 | 10176;
	// blr 
	return;
loc_823F6B58:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f0,7296(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7296);
	// lfd f13,-16(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
loc_823F6B84:
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfd f0,7304(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7304);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82406070) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82406078;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,144(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r10,148(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// addi r31,r3,120
	ctx.r31.s64 = ctx.r3.s64 + 120;
	// stw r4,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r4.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x824060a0
	if (!ctx.cr6.gt) goto loc_824060A0;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_824060A0:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_824060BC:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x824060d4
	if (!ctx.cr6.gt) goto loc_824060D4;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_824060D4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x824060e8
	if (ctx.cr6.eq) goto loc_824060E8;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x824060ec
	if (ctx.cr6.eq) goto loc_824060EC;
loc_824060E8:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_824060EC:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8240614c
	if (ctx.cr6.eq) goto loc_8240614C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823f9590
	ctx.lr = 0x824060FC;
	sub_823F9590(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x82406158
	if (ctx.cr6.eq) goto loc_82406158;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82406140
	if (!ctx.cr6.eq) goto loc_82406140;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8240611C:
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r10,24(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82406134
	if (ctx.cr6.lt) goto loc_82406134;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_82406134:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// b 0x824060bc
	goto loc_824060BC;
loc_82406140:
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x8240611c
	goto loc_8240611C;
loc_8240614C:
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82497f08
	ctx.lr = 0x82406158;
	sub_82497F08(ctx, base);
loc_82406158:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240B418) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x8240B420;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// addi r9,r10,13344
	ctx.r9.s64 = ctx.r10.s64 + 13344;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r31,r11,16
	ctx.r31.s64 = ctx.r11.s64 + 16;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r29,3
	ctx.r29.s64 = 3;
	// addi r28,r11,-36
	ctx.r28.s64 = ctx.r11.s64 + -36;
	// li r26,17
	ctx.r26.s64 = 17;
	// li r27,2
	ctx.r27.s64 = 2;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8240B450:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240bb60
	ctx.lr = 0x8240B458;
	sub_8240BB60(ctx, base);
	// stw r26,-12(r31)
	REX_STORE_U32(ctx.r31.u32 + -12, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8240bb60
	ctx.lr = 0x8240B464;
	sub_8240BB60(ctx, base);
	// stw r27,-8(r31)
	REX_STORE_U32(ctx.r31.u32 + -8, ctx.r27.u32);
	// stw r30,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// sth r30,12(r31)
	REX_STORE_U16(ctx.r31.u32 + 12, ctx.r30.u16);
	// stwu r30,36(r28)
	ea = 36 + ctx.r28.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r28.u32 = ea;
	// stw r26,-12(r31)
	REX_STORE_U32(ctx.r31.u32 + -12, ctx.r26.u32);
	// bl 0x8240bb60
	ctx.lr = 0x8240B488;
	sub_8240BB60(ctx, base);
	// stw r27,-8(r31)
	REX_STORE_U32(ctx.r31.u32 + -8, ctx.r27.u32);
	// stw r30,-4(r31)
	REX_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// sth r30,12(r31)
	REX_STORE_U16(ctx.r31.u32 + 12, ctx.r30.u16);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// addi r31,r31,36
	ctx.r31.s64 = ctx.r31.s64 + 36;
	// bge 0x8240b450
	if (!ctx.cr0.lt) goto loc_8240B450;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8240a100
	ctx.lr = 0x8240B4B4;
	sub_8240A100(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240F248) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x8240F250;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,504(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 504);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r3,488
	ctx.r29.s64 = ctx.r3.s64 + 488;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240f284
	if (ctx.cr6.eq) goto loc_8240F284;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// beq cr6,0x8240f288
	if (ctx.cr6.eq) goto loc_8240F288;
loc_8240F284:
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
loc_8240F288:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8240f40c
	if (ctx.cr6.eq) goto loc_8240F40C;
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
	// beq cr6,0x8240f40c
	if (ctx.cr6.eq) goto loc_8240F40C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240f40c
	if (ctx.cr6.eq) goto loc_8240F40C;
	// lwz r3,16(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240f2d4
	if (ctx.cr6.eq) goto loc_8240F2D4;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// beq cr6,0x8240f2d8
	if (ctx.cr6.eq) goto loc_8240F2D8;
loc_8240F2D4:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8240F2D8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240f2f4
	if (ctx.cr6.eq) goto loc_8240F2F4;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// and r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8240f2f8
	if (!ctx.cr6.eq) goto loc_8240F2F8;
loc_8240F2F4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8240F2F8:
	// bl 0x823c7b38
	ctx.lr = 0x8240F2FC;
	sub_823C7B38(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8240f39c
	if (!ctx.cr6.eq) goto loc_8240F39C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8243fa70
	ctx.lr = 0x8240F30C;
	sub_8243FA70(ctx, base);
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240f328
	if (ctx.cr6.eq) goto loc_8240F328;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821ca958
	ctx.lr = 0x8240F320;
	sub_821CA958(ctx, base);
	// ori r3,r3,315
	ctx.r3.u64 = ctx.r3.u64 | 315;
	// b 0x8240f348
	goto loc_8240F348;
loc_8240F328:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8243fa70
	ctx.lr = 0x8240F330;
	sub_8243FA70(ctx, base);
	// lwz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240f354
	if (!ctx.cr6.eq) goto loc_8240F354;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821ca958
	ctx.lr = 0x8240F344;
	sub_821CA958(ctx, base);
	// ori r3,r3,314
	ctx.r3.u64 = ctx.r3.u64 | 314;
loc_8240F348:
	// bl 0x82248600
	ctx.lr = 0x8240F34C;
	sub_82248600(ctx, base);
	// li r4,600
	ctx.r4.s64 = 600;
	// bl 0x82411350
	ctx.lr = 0x8240F354;
	sub_82411350(ctx, base);
loc_8240F354:
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// lis r10,-32171
	ctx.r10.s64 = -2108358656;
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// addi r11,r11,13786
	ctx.r11.s64 = ctx.r11.s64 + 13786;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// addi r9,r10,648
	ctx.r9.s64 = ctx.r10.s64 + 648;
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// addi r6,r11,-2
	ctx.r6.s64 = ctx.r11.s64 + -2;
	// addi r3,r30,96
	ctx.r3.s64 = ctx.r30.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x8240F388;
	sub_822518D8(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82226798
	ctx.lr = 0x8240F390;
	sub_82226798(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_8240F39C:
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8240f3b0
	if (ctx.cr6.eq) goto loc_8240F3B0;
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// cmplwi cr6,r11,600
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 600, ctx.xer);
	// blt cr6,0x8240f44c
	if (ctx.cr6.lt) goto loc_8240F44C;
loc_8240F3B0:
	// bl 0x82408030
	ctx.lr = 0x8240F3B4;
	sub_82408030(ctx, base);
	// li r4,31
	ctx.r4.s64 = 31;
	// bl 0x82407148
	ctx.lr = 0x8240F3BC;
	sub_82407148(ctx, base);
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// stw r28,544(r30)
	REX_STORE_U32(ctx.r30.u32 + 544, ctx.r28.u32);
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// lis r10,-32191
	ctx.r10.s64 = -2109669376;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r11,r11,13786
	ctx.r11.s64 = ctx.r11.s64 + 13786;
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// addi r9,r10,4648
	ctx.r9.s64 = ctx.r10.s64 + 4648;
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// addi r3,r30,96
	ctx.r3.s64 = ctx.r30.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x822518d8
	ctx.lr = 0x8240F3F4;
	sub_822518D8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8243fa70
	ctx.lr = 0x8240F3FC;
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
loc_8240F40C:
	// bl 0x82408030
	ctx.lr = 0x8240F410;
	sub_82408030(ctx, base);
	// li r4,31
	ctx.r4.s64 = 31;
	// bl 0x82407148
	ctx.lr = 0x8240F418;
	sub_82407148(ctx, base);
	// stw r28,544(r30)
	REX_STORE_U32(ctx.r30.u32 + 544, ctx.r28.u32);
	// lis r11,-32191
	ctx.r11.s64 = -2109669376;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r31,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// addi r9,r11,4648
	ctx.r9.s64 = ctx.r11.s64 + 4648;
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r6,r10,13786
	ctx.r6.s64 = ctx.r10.s64 + 13786;
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// addi r3,r30,96
	ctx.r3.s64 = ctx.r30.s64 + 96;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x822518d8
	ctx.lr = 0x8240F44C;
	sub_822518D8(ctx, base);
loc_8240F44C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241D270) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x8241D278;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,0(r5)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x82515118
	ctx.lr = 0x8241D29C;
	sub_82515118(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x825150d0
	ctx.lr = 0x8241D2A4;
	sub_825150D0(ctx, base);
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x825158f0
	ctx.lr = 0x8241D2AC;
	sub_825158F0(ctx, base);
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// addi r30,r11,16212
	ctx.r30.s64 = ctx.r11.s64 + 16212;
	// lwz r3,3540(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3540);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// addi r4,r30,-88
	ctx.r4.s64 = ctx.r30.s64 + -88;
	// ori r6,r6,4147
	ctx.r6.u64 = ctx.r6.u64 | 4147;
	// lfs f31,2880(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2880);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82514330
	ctx.lr = 0x8241D2D8;
	sub_82514330(ctx, base);
	// lwz r3,3540(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3540);
	// rlwinm r9,r3,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8241d2fc
	if (ctx.cr6.eq) goto loc_8241D2FC;
	// addi r4,r30,-76
	ctx.r4.s64 = ctx.r30.s64 + -76;
	// lwz r5,3168(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3168);
	// li r6,51
	ctx.r6.s64 = 51;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82514330
	ctx.lr = 0x8241D2FC;
	sub_82514330(ctx, base);
loc_8241D2FC:
	// lwz r3,3540(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3540);
	// rlwinm r11,r3,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241d320
	if (ctx.cr6.eq) goto loc_8241D320;
	// addi r4,r30,-56
	ctx.r4.s64 = ctx.r30.s64 + -56;
	// lwz r5,3172(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3172);
	// li r6,51
	ctx.r6.s64 = 51;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82514330
	ctx.lr = 0x8241D320;
	sub_82514330(ctx, base);
loc_8241D320:
	// lwz r3,3540(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3540);
	// rlwinm r11,r3,0,26,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x30;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8241d374
	if (ctx.cr6.eq) goto loc_8241D374;
	// addi r4,r30,-40
	ctx.r4.s64 = ctx.r30.s64 + -40;
	// lwz r5,3176(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3176);
	// li r6,51
	ctx.r6.s64 = 51;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82514330
	ctx.lr = 0x8241D344;
	sub_82514330(ctx, base);
	// addi r4,r30,-20
	ctx.r4.s64 = ctx.r30.s64 + -20;
	// li r6,51
	ctx.r6.s64 = 51;
	// lwz r5,3184(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3184);
	// lwz r3,3540(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3540);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82514330
	ctx.lr = 0x8241D35C;
	sub_82514330(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r6,51
	ctx.r6.s64 = 51;
	// lwz r5,3180(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// lwz r3,3540(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3540);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82514330
	ctx.lr = 0x8241D374;
	sub_82514330(ctx, base);
loc_8241D374:
	// lwz r6,3540(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3540);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// li r5,51
	ctx.r5.s64 = 51;
	// li r4,1824
	ctx.r4.s64 = 1824;
	// li r3,-1
	ctx.r3.s64 = -1;
	// beq cr6,0x8241d3a0
	if (ctx.cr6.eq) goto loc_8241D3A0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,26848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26848);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82422808
	ctx.lr = 0x8241D39C;
	sub_82422808(ctx, base);
	// b 0x8241d3b0
	goto loc_8241D3B0;
loc_8241D3A0:
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82422b70
	ctx.lr = 0x8241D3B0;
	sub_82422B70(ctx, base);
loc_8241D3B0:
	// bl 0x82515918
	ctx.lr = 0x8241D3B4;
	sub_82515918(ctx, base);
	// bl 0x82515108
	ctx.lr = 0x8241D3B8;
	sub_82515108(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x82515118
	ctx.lr = 0x8241D3C4;
	sub_82515118(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82424D70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82424D78;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82423728
	ctx.lr = 0x82424D8C;
	sub_82423728(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r29,r31,8
	ctx.r29.s64 = ctx.r31.s64 + 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r29,-4
	ctx.r11.s64 = ctx.r29.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82424DA0:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82424da0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82424DA0;
	// lis r4,8200
	ctx.r4.s64 = 537395200;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r4,r4,2055
	ctx.r4.u64 = ctx.r4.u64 | 2055;
	// bl 0x82423738
	ctx.lr = 0x82424DB8;
	sub_82423738(ctx, base);
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r30,r11,16664
	ctx.r30.s64 = ctx.r11.s64 + 16664;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82423798
	ctx.lr = 0x82424DCC;
	sub_82423798(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82424dd8
	if (ctx.cr6.lt) goto loc_82424DD8;
	// bne cr6,0x82424de4
	if (!ctx.cr6.eq) goto loc_82424DE4;
loc_82424DD8:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,13920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13920);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
loc_82424DE4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423798
	ctx.lr = 0x82424DF0;
	sub_82423798(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82424e00
	if (!ctx.cr6.eq) goto loc_82424E00;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82424E00:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423798
	ctx.lr = 0x82424E0C;
	sub_82423798(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// lfs f30,12688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12688);
	ctx.f30.f64 = double(temp.f32);
	// blt cr6,0x82424e28
	if (ctx.cr6.lt) goto loc_82424E28;
	// bne cr6,0x82424e2c
	if (!ctx.cr6.eq) goto loc_82424E2C;
	// stfs f30,16(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// b 0x82424e2c
	goto loc_82424E2C;
loc_82424E28:
	// stfs f30,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
loc_82424E2C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423798
	ctx.lr = 0x82424E38;
	sub_82423798(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// lfs f31,14928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14928);
	ctx.f31.f64 = double(temp.f32);
	// blt cr6,0x82424e54
	if (ctx.cr6.lt) goto loc_82424E54;
	// bne cr6,0x82424e58
	if (!ctx.cr6.eq) goto loc_82424E58;
	// stfs f31,20(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// b 0x82424e58
	goto loc_82424E58;
loc_82424E54:
	// stfs f31,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 16, temp.u32);
loc_82424E58:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423798
	ctx.lr = 0x82424E64;
	sub_82423798(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82424e80
	if (ctx.cr6.lt) goto loc_82424E80;
	// bne cr6,0x82424e8c
	if (!ctx.cr6.eq) goto loc_82424E8C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// b 0x82424e8c
	goto loc_82424E8C;
loc_82424E80:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
loc_82424E8C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423798
	ctx.lr = 0x82424E98;
	sub_82423798(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82424eac
	if (ctx.cr6.lt) goto loc_82424EAC;
	// bne cr6,0x82424eb0
	if (!ctx.cr6.eq) goto loc_82424EB0;
	// stfs f30,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// b 0x82424eb0
	goto loc_82424EB0;
loc_82424EAC:
	// stfs f30,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
loc_82424EB0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423798
	ctx.lr = 0x82424EBC;
	sub_82423798(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82424ed0
	if (ctx.cr6.lt) goto loc_82424ED0;
	// bne cr6,0x82424ed4
	if (!ctx.cr6.eq) goto loc_82424ED4;
	// stfs f31,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// b 0x82424ed4
	goto loc_82424ED4;
loc_82424ED0:
	// stfs f31,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
loc_82424ED4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82423798
	ctx.lr = 0x82424EE0;
	sub_82423798(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x82424f08
	if (ctx.cr6.lt) goto loc_82424F08;
	// bne cr6,0x82424f14
	if (!ctx.cr6.eq) goto loc_82424F14;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,2884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f30,-48(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
loc_82424F08:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,2884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2884);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
loc_82424F14:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82434E7C) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82434EF8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82434f20
	if (ctx.cr6.eq) goto loc_82434F20;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82434f24
	if (ctx.cr6.eq) goto loc_82434F24;
loc_82434F20:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82434F24:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82434f48
	if (ctx.cr6.eq) goto loc_82434F48;
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
	// bne cr6,0x82434f4c
	if (!ctx.cr6.eq) goto loc_82434F4C;
loc_82434F48:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82434F4C:
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
	// li r5,9
	ctx.r5.s64 = 9;
	// b 0x823719c8
	sub_823719C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82437108) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82437110;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32132
	ctx.r11.s64 = -2105802752;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r31,r11,-3888
	ctx.r31.s64 = ctx.r11.s64 + -3888;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r10,-21492
	ctx.r4.s64 = ctx.r10.s64 + -21492;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x822fece8
	ctx.lr = 0x82437130;
	sub_822FECE8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r8,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r6,28(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
	// add r5,r3,r6
	ctx.r5.u64 = ctx.r3.u64 + ctx.r6.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// bl 0x826a2910
	ctx.lr = 0x82437160;
	sub_826A2910(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8243720c
	if (ctx.cr6.lt) goto loc_8243720C;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821ca958
	ctx.lr = 0x82437174;
	sub_821CA958(ctx, base);
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r11,-21516
	ctx.r4.s64 = ctx.r11.s64 + -21516;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x822fece8
	ctx.lr = 0x82437188;
	sub_822FECE8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r11,r8,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r6,28(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 28);
	// add r5,r3,r6
	ctx.r5.u64 = ctx.r3.u64 + ctx.r6.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,79
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 79, ctx.xer);
	// beq cr6,0x824371e0
	if (ctx.cr6.eq) goto loc_824371E0;
	// cmplwi cr6,r11,80
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 80, ctx.xer);
	// beq cr6,0x824371d8
	if (ctx.cr6.eq) goto loc_824371D8;
	// cmplwi cr6,r11,83
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 83, ctx.xer);
	// bne cr6,0x824371ec
	if (!ctx.cr6.eq) goto loc_824371EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824371e4
	goto loc_824371E4;
loc_824371D8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824371e4
	goto loc_824371E4;
loc_824371E0:
	// li r3,3
	ctx.r3.s64 = 3;
loc_824371E4:
	// bl 0x821ca958
	ctx.lr = 0x824371E8;
	sub_821CA958(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_824371EC:
	// bl 0x8235e5a0
	ctx.lr = 0x824371F0;
	sub_8235E5A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8243720c
	if (ctx.cr6.eq) goto loc_8243720C;
	// bl 0x8235e5a0
	ctx.lr = 0x824371FC;
	sub_8235E5A0(ctx, base);
	// or r4,r29,r28
	ctx.r4.u64 = ctx.r29.u64 | ctx.r28.u64;
	// bl 0x823616a0
	ctx.lr = 0x82437204;
	sub_823616A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
loc_8243720C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8243CB38) {
	REX_FUNC_PROLOGUE();
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// extsw r11,r4
	ctx.r11.s64 = ctx.r4.s32;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// bge cr6,0x8243cb54
	if (!ctx.cr6.lt) goto loc_8243CB54;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8243CB54:
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r3,-1
	ctx.r3.s64 = -1;
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// cmpd cr6,r11,r9
	ctx.cr6.compare<int64_t>(ctx.r11.s64, ctx.r9.s64, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8243F0C4) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8243F160) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x8243F168;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8243e430
	ctx.lr = 0x8243F170;
	sub_8243E430(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8243f2f4
	if (ctx.cr6.eq) goto loc_8243F2F4;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8243f1a4
	if (ctx.cr6.eq) goto loc_8243F1A4;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8243f1a8
	if (ctx.cr6.eq) goto loc_8243F1A8;
loc_8243F1A4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8243F1A8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8243f2d4
	if (ctx.cr6.eq) goto loc_8243F2D4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,60(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// lwz r11,30048(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 30048);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8243f2d4
	if (ctx.cr6.eq) goto loc_8243F2D4;
	// bl 0x82170cb0
	ctx.lr = 0x8243F1D0;
	sub_82170CB0(ctx, base);
	// lwz r11,1024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1024);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8243f2d4
	if (ctx.cr6.eq) goto loc_8243F2D4;
	// bl 0x82170cb0
	ctx.lr = 0x8243F1E0;
	sub_82170CB0(ctx, base);
	// lwz r11,1024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1024);
	// addi r28,r11,116
	ctx.r28.s64 = ctx.r11.s64 + 116;
	// bl 0x82170cb0
	ctx.lr = 0x8243F1EC;
	sub_82170CB0(ctx, base);
	// lwz r11,1024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1024);
	// addi r30,r11,122
	ctx.r30.s64 = ctx.r11.s64 + 122;
	// bl 0x82170cb0
	ctx.lr = 0x8243F1F8;
	sub_82170CB0(ctx, base);
	// lwz r11,1024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1024);
	// addi r29,r11,126
	ctx.r29.s64 = ctx.r11.s64 + 126;
	// bl 0x82170cb0
	ctx.lr = 0x8243F204;
	sub_82170CB0(ctx, base);
	// lwz r11,1024(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1024);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// addi r26,r11,128
	ctx.r26.s64 = ctx.r11.s64 + 128;
	// beq cr6,0x8243f2d4
	if (ctx.cr6.eq) goto loc_8243F2D4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8243f2d4
	if (ctx.cr6.eq) goto loc_8243F2D4;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8243f2d4
	if (ctx.cr6.eq) goto loc_8243F2D4;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8243f2d4
	if (ctx.cr6.eq) goto loc_8243F2D4;
	// bl 0x82170cb0
	ctx.lr = 0x8243F230;
	sub_82170CB0(ctx, base);
	// lwz r3,1024(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 1024);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8243f270
	if (ctx.cr6.eq) goto loc_8243F270;
	// bl 0x82248ee0
	ctx.lr = 0x8243F240;
	sub_82248EE0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8243f270
	if (ctx.cr6.eq) goto loc_8243F270;
	// bl 0x82437488
	ctx.lr = 0x8243F250;
	sub_82437488(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8243f260
	if (ctx.cr6.eq) goto loc_8243F260;
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x8243f264
	goto loc_8243F264;
loc_8243F260:
	// li r5,-1
	ctx.r5.s64 = -1;
loc_8243F264:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82284c80
	ctx.lr = 0x8243F270;
	sub_82284C80(ctx, base);
loc_8243F270:
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// addi r10,r31,-1
	ctx.r10.s64 = ctx.r31.s64 + -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8243F280:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8243f280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8243F280;
	// lbz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// addi r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 6;
	// addi r11,r31,10
	ctx.r11.s64 = ctx.r31.s64 + 10;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// li r5,144
	ctx.r5.s64 = 144;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stb r10,6(r31)
	REX_STORE_U8(ctx.r31.u32 + 6, ctx.r10.u8);
	// lbz r9,1(r30)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r30.u32 + 1);
	// stb r9,7(r31)
	REX_STORE_U8(ctx.r31.u32 + 7, ctx.r9.u8);
	// lbz r8,2(r30)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r30.u32 + 2);
	// stb r8,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r8.u8);
	// lbz r7,3(r30)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r30.u32 + 3);
	// stb r7,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r7.u8);
	// lbz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// stb r6,10(r31)
	REX_STORE_U8(ctx.r31.u32 + 10, ctx.r6.u8);
	// lbz r11,1(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 1);
	// stb r11,11(r31)
	REX_STORE_U8(ctx.r31.u32 + 11, ctx.r11.u8);
	// bl 0x826a1130
	ctx.lr = 0x8243F2D4;
	rexcrt_memcpy(ctx, base);
loc_8243F2D4:
	// lbz r3,240(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 240);
	// bl 0x822f39f8
	ctx.lr = 0x8243F2DC;
	sub_822F39F8(ctx, base);
	// addi r31,r31,160
	ctx.r31.s64 = ctx.r31.s64 + 160;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824424f0
	ctx.lr = 0x8243F2EC;
	sub_824424F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824425a0
	ctx.lr = 0x8243F2F4;
	sub_824425A0(ctx, base);
loc_8243F2F4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824518E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x824518E8;
	__savegprlr_14(ctx, base);
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,7364(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 7364);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245190c
	if (ctx.cr6.eq) goto loc_8245190C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2332
	ctx.r3.s64 = 2332;
	// bl 0x8235ce40
	ctx.lr = 0x8245190C;
	sub_8235CE40(ctx, base);
loc_8245190C:
	// lwz r11,7368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82451928
	if (ctx.cr6.eq) goto loc_82451928;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2331
	ctx.r3.s64 = 2331;
	// bl 0x8235ce40
	ctx.lr = 0x82451928;
	sub_8235CE40(ctx, base);
loc_82451928:
	// lwz r11,7996(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7996);
	// li r21,0
	ctx.r21.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245194c
	if (ctx.cr6.eq) goto loc_8245194C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244df68
	ctx.lr = 0x82451940;
	sub_8244DF68(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244c6c0
	ctx.lr = 0x82451948;
	sub_8244C6C0(ctx, base);
	// stw r21,7996(r31)
	REX_STORE_U32(ctx.r31.u32 + 7996, ctx.r21.u32);
loc_8245194C:
	// addis r22,r31,1
	ctx.r22.s64 = ctx.r31.s64 + 65536;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// addi r22,r22,6340
	ctx.r22.s64 = ctx.r22.s64 + 6340;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r24,r11,6344
	ctx.r24.u64 = ctx.r11.u64 | 6344;
	// stw r22,356(r1)
	REX_STORE_U32(ctx.r1.u32 + 356, ctx.r22.u32);
	// ori r11,r10,6348
	ctx.r11.u64 = ctx.r10.u64 | 6348;
	// lwz r10,0(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82453f60
	if (!ctx.cr6.eq) goto loc_82453F60;
	// add r9,r31,r24
	ctx.r9.u64 = ctx.r31.u64 + ctx.r24.u64;
	// stw r9,360(r1)
	REX_STORE_U32(ctx.r1.u32 + 360, ctx.r9.u32);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82453f60
	if (!ctx.cr6.eq) goto loc_82453F60;
	// add r9,r31,r11
	ctx.r9.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stw r9,352(r1)
	REX_STORE_U32(ctx.r1.u32 + 352, ctx.r9.u32);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82453f60
	if (!ctx.cr6.eq) goto loc_82453F60;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lwz r10,7408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7408);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lwz r9,7412(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7412);
	// addi r11,r11,6076
	ctx.r11.s64 = ctx.r11.s64 + 6076;
	// addi r29,r29,6064
	ctx.r29.s64 = ctx.r29.s64 + 6064;
	// li r22,1
	ctx.r22.s64 = 1;
	// stw r11,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r9.u32);
	// stw r22,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r22.u32);
	// stw r21,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
	// bl 0x8244bdc8
	ctx.lr = 0x824519D8;
	sub_8244BDC8(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x824519f4
	if (ctx.cr6.eq) goto loc_824519F4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2184
	ctx.r3.s64 = 2184;
	// bl 0x8235ce40
	ctx.lr = 0x824519F4;
	sub_8235CE40(ctx, base);
loc_824519F4:
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,2004
	ctx.r11.s64 = ctx.r11.s64 + 2004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82451a10
	if (!ctx.cr6.gt) goto loc_82451A10;
	// stw r11,7360(r31)
	REX_STORE_U32(ctx.r31.u32 + 7360, ctx.r11.u32);
loc_82451A10:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b7d8
	ctx.lr = 0x82451A20;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451a40
	if (ctx.cr6.eq) goto loc_82451A40;
	// lwz r5,7360(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7360);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x82451a40
	if (!ctx.cr6.gt) goto loc_82451A40;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,104(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// bl 0x82444548
	ctx.lr = 0x82451A40;
	sub_82444548(ctx, base);
loc_82451A40:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451A50;
	sub_8245B738(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451a70
	if (ctx.cr6.eq) goto loc_82451A70;
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
	ctx.lr = 0x82451A70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82451A70:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b878
	ctx.lr = 0x82451A80;
	sub_8245B878(ctx, base);
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r24,r11,-18886
	ctx.r24.s64 = ctx.r11.s64 + -18886;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r24,188(r1)
	REX_STORE_U32(ctx.r1.u32 + 188, ctx.r24.u32);
	// beq cr6,0x82451b00
	if (ctx.cr6.eq) goto loc_82451B00;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82451ab0
	if (ctx.cr6.eq) goto loc_82451AB0;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// sth r21,1120(r11)
	REX_STORE_U16(ctx.r11.u32 + 1120, ctx.r21.u16);
	// sth r21,1122(r11)
	REX_STORE_U16(ctx.r11.u32 + 1122, ctx.r21.u16);
loc_82451AB0:
	// addi r4,r24,38
	ctx.r4.s64 = ctx.r24.s64 + 38;
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// bl 0x82368998
	ctx.lr = 0x82451ABC;
	sub_82368998(ctx, base);
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82451AD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,108(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// li r9,350
	ctx.r9.s64 = 350;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,35
	ctx.r5.s64 = 35;
	// li r4,190
	ctx.r4.s64 = 190;
	// sth r9,1116(r8)
	REX_STORE_U16(ctx.r8.u32 + 1116, ctx.r9.u16);
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,68(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82451B00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82451B00:
	// stw r21,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b738
	ctx.lr = 0x82451B14;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451b44
	if (ctx.cr6.eq) goto loc_82451B44;
	// addi r4,r24,42
	ctx.r4.s64 = ctx.r24.s64 + 42;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// bl 0x82368998
	ctx.lr = 0x82451B2C;
	sub_82368998(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82451B44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82451B44:
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451B54;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451b84
	if (ctx.cr6.eq) goto loc_82451B84;
	// addi r4,r24,46
	ctx.r4.s64 = ctx.r24.s64 + 46;
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// bl 0x82368998
	ctx.lr = 0x82451B6C;
	sub_82368998(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82451B84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82451B84:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,7360(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 7360);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446c20
	ctx.lr = 0x82451B94;
	sub_82446C20(ctx, base);
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r23,-1
	ctx.r23.s64 = -1;
	// ori r18,r10,6068
	ctx.r18.u64 = ctx.r10.u64 | 6068;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82451d30
	if (ctx.cr6.eq) goto loc_82451D30;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82451e84
	if (!ctx.cr6.eq) goto loc_82451E84;
	// lwz r10,7372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// lwzx r11,r31,r18
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r18.u32);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x82451c3c
	if (!ctx.cr6.eq) goto loc_82451C3C;
	// lwz r10,7384(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7384);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451BE4;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// bl 0x82170cb0
	ctx.lr = 0x82451BF4;
	sub_82170CB0(ctx, base);
	// lwz r11,904(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 904);
	// li r4,170
	ctx.r4.s64 = 170;
	// lwz r3,228(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// bl 0x82305298
	ctx.lr = 0x82451C04;
	sub_82305298(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// bl 0x82368998
	ctx.lr = 0x82451C10;
	sub_82368998(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r4,99
	ctx.r4.s64 = 99;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,112(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 112);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82451C28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,96(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// b 0x82451e7c
	goto loc_82451E7C;
loc_82451C3C:
	// lwz r9,7384(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7384);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x82451c70
	if (ctx.cr6.lt) goto loc_82451C70;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451C5C;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// addi r4,r24,62
	ctx.r4.s64 = ctx.r24.s64 + 62;
	// b 0x82451e4c
	goto loc_82451E4C;
loc_82451C70:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// ble cr6,0x82451e84
	if (!ctx.cr6.gt) goto loc_82451E84;
	// bl 0x82170cb0
	ctx.lr = 0x82451C7C;
	sub_82170CB0(ctx, base);
	// lwz r3,908(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 908);
	// bl 0x8238d760
	ctx.lr = 0x82451C84;
	sub_8238D760(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,5004
	ctx.r11.s64 = ctx.r11.s64 + 5004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// bl 0x823f1f30
	ctx.lr = 0x82451CA4;
	sub_823F1F30(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// lhz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// bl 0x823f2050
	ctx.lr = 0x82451CC0;
	sub_823F2050(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445540
	ctx.lr = 0x82451CCC;
	sub_82445540(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823f67a8
	ctx.lr = 0x82451CE0;
	sub_823F67A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x823f4460
	ctx.lr = 0x82451CEC;
	sub_823F4460(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x823f4470
	ctx.lr = 0x82451CFC;
	sub_823F4470(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// addi r6,r24,66
	ctx.r6.s64 = ctx.r24.s64 + 66;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x826a2720
	ctx.lr = 0x82451D28;
	sub_826A2720(ctx, base);
	// lwz r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// b 0x82451e1c
	goto loc_82451E1C;
loc_82451D30:
	// lwzx r11,r31,r18
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r18.u32);
	// lwz r10,7384(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7384);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x82451d68
	if (ctx.cr6.lt) goto loc_82451D68;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451D54;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// addi r4,r24,50
	ctx.r4.s64 = ctx.r24.s64 + 50;
	// b 0x82451e4c
	goto loc_82451E4C;
loc_82451D68:
	// bl 0x82170cb0
	ctx.lr = 0x82451D6C;
	sub_82170CB0(ctx, base);
	// lwz r3,908(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 908);
	// bl 0x8238d760
	ctx.lr = 0x82451D74;
	sub_8238D760(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,5004
	ctx.r11.s64 = ctx.r11.s64 + 5004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// bl 0x823f1f30
	ctx.lr = 0x82451D94;
	sub_823F1F30(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// lhz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// bl 0x823f2050
	ctx.lr = 0x82451DB0;
	sub_823F2050(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445540
	ctx.lr = 0x82451DBC;
	sub_82445540(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823f67a8
	ctx.lr = 0x82451DD0;
	sub_823F67A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,704(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 704);
	// bl 0x823f4460
	ctx.lr = 0x82451DDC;
	sub_823F4460(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,704(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 704);
	// bl 0x823f4470
	ctx.lr = 0x82451DEC;
	sub_823F4470(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// addi r6,r24,54
	ctx.r6.s64 = ctx.r24.s64 + 54;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x826a2720
	ctx.lr = 0x82451E18;
	sub_826A2720(ctx, base);
	// lwz r4,704(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 704);
loc_82451E1C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823f4460
	ctx.lr = 0x82451E24;
	sub_823F4460(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451E3C;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451e84
	if (ctx.cr6.eq) goto loc_82451E84;
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
loc_82451E4C:
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// bl 0x82368998
	ctx.lr = 0x82451E54;
	sub_82368998(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r4,99
	ctx.r4.s64 = 99;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82451E6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,96(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82451E7C:
	// li r4,0
	ctx.r4.s64 = 0;
	// bctrl 
	ctx.lr = 0x82451E84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82451E84:
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r17,r10,50320
	ctx.r17.u64 = ctx.r10.u64 | 50320;
	// ori r19,r9,10244
	ctx.r19.u64 = ctx.r9.u64 | 10244;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82451f44
	if (!ctx.cr6.eq) goto loc_82451F44;
	// lwz r11,7448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82451f44
	if (!ctx.cr6.gt) goto loc_82451F44;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82451EBC:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// bne cr6,0x82451ecc
	if (!ctx.cr6.eq) goto loc_82451ECC;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82451ECC:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82451ebc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82451EBC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82451f44
	if (ctx.cr6.eq) goto loc_82451F44;
	// lwzx r11,r31,r19
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	// lwz r10,7392(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82451f44
	if (!ctx.cr6.eq) goto loc_82451F44;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451F00;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451f44
	if (ctx.cr6.eq) goto loc_82451F44;
	// li r4,201
	ctx.r4.s64 = 201;
	// bl 0x8245c750
	ctx.lr = 0x82451F14;
	sub_8245C750(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r4,99
	ctx.r4.s64 = 99;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82451F2C;
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
	ctx.lr = 0x82451F44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82451F44:
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82451fd0
	if (!ctx.cr6.eq) goto loc_82451FD0;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451F60;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451f9c
	if (ctx.cr6.eq) goto loc_82451F9C;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x8245c750
	ctx.lr = 0x82451F74;
	sub_8245C750(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,255
	ctx.r7.s64 = 255;
	// li r6,255
	ctx.r6.s64 = 255;
	// li r5,84
	ctx.r5.s64 = 84;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82451F9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82451F9C:
	// lwz r11,7412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7412);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r9,7408(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7408);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8245b7d8
	ctx.lr = 0x82451FC0;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82451fd0
	if (ctx.cr6.eq) goto loc_82451FD0;
	// stw r22,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r22.u32);
	// bl 0x8245b038
	ctx.lr = 0x82451FD0;
	sub_8245B038(ctx, base);
loc_82451FD0:
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82452028
	if (!ctx.cr6.eq) goto loc_82452028;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82451FEC;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452028
	if (ctx.cr6.eq) goto loc_82452028;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8245c750
	ctx.lr = 0x82452000;
	sub_8245C750(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,255
	ctx.r7.s64 = 255;
	// li r6,12
	ctx.r6.s64 = 12;
	// li r5,172
	ctx.r5.s64 = 172;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82452028;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82452028:
	// addis r25,r31,2
	ctx.r25.s64 = ctx.r31.s64 + 131072;
	// lwz r10,7380(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// li r16,-1
	ctx.r16.s64 = -1;
	// stw r22,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r22.u32);
	// addi r25,r25,-10068
	ctx.r25.s64 = ctx.r25.s64 + -10068;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// stw r25,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r25.u32);
	// stw r21,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r21.u32);
	// beq cr6,0x82452054
	if (ctx.cr6.eq) goto loc_82452054;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x82452428
	if (!ctx.cr6.eq) goto loc_82452428;
loc_82452054:
	// lwzx r11,r31,r18
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r18.u32);
	// add r30,r31,r18
	ctx.r30.u64 = ctx.r31.u64 + ctx.r18.u64;
	// lwz r9,7384(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7384);
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
	// mr r27,r21
	ctx.r27.u64 = ctx.r21.u64;
	// mr r26,r21
	ctx.r26.u64 = ctx.r21.u64;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8245213c
	if (!ctx.cr6.lt) goto loc_8245213C;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x82452108
	if (!ctx.cr6.eq) goto loc_82452108;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82448128
	ctx.lr = 0x82452090;
	sub_82448128(ctx, base);
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,5004
	ctx.r11.s64 = ctx.r11.s64 + 5004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpw cr6,r3,r9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x824520b0
	if (!ctx.cr6.eq) goto loc_824520B0;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_824520B0:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82448128
	ctx.lr = 0x824520BC;
	sub_82448128(ctx, base);
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,5004
	ctx.r11.s64 = ctx.r11.s64 + 5004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpw cr6,r3,r9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x824520dc
	if (!ctx.cr6.eq) goto loc_824520DC;
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_824520DC:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82448128
	ctx.lr = 0x824520E8;
	sub_82448128(ctx, base);
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,5004
	ctx.r11.s64 = ctx.r11.s64 + 5004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpw cr6,r3,r9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8245213c
	if (!ctx.cr6.eq) goto loc_8245213C;
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// b 0x82452138
	goto loc_82452138;
loc_82452108:
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x8245213c
	if (!ctx.cr6.eq) goto loc_8245213C;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// bl 0x82448128
	ctx.lr = 0x82452120;
	sub_82448128(ctx, base);
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,5004
	ctx.r11.s64 = ctx.r11.s64 + 5004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpw cr6,r3,r9
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8245213c
	if (!ctx.cr6.eq) goto loc_8245213C;
loc_82452138:
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_8245213C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,7384(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7384);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82452168
	if (ctx.cr6.eq) goto loc_82452168;
	// addi r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 2;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x82452168
	if (ctx.cr6.eq) goto loc_82452168;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x8245219c
	if (!ctx.cr6.eq) goto loc_8245219C;
loc_82452168:
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8245219c
	if (!ctx.cr6.eq) goto loc_8245219C;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// bl 0x82448128
	ctx.lr = 0x82452184;
	sub_82448128(ctx, base);
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x8245219c
	if (!ctx.cr6.eq) goto loc_8245219C;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_8245219C:
	// lwz r11,7448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8245221c
	if (!ctx.cr6.gt) goto loc_8245221C;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_824521B8:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// bne cr6,0x824521c8
	if (!ctx.cr6.eq) goto loc_824521C8;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_824521C8:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x824521b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824521B8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8245221c
	if (ctx.cr6.eq) goto loc_8245221C;
	// lwzx r11,r31,r19
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	// lwz r10,7392(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x8245221c
	if (!ctx.cr6.eq) goto loc_8245221C;
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8245221c
	if (!ctx.cr6.eq) goto loc_8245221C;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// bl 0x82448128
	ctx.lr = 0x82452208;
	sub_82448128(ctx, base);
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8245221c
	if (!ctx.cr6.eq) goto loc_8245221C;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_8245221C:
	// lwz r11,7448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82452290
	if (!ctx.cr6.gt) goto loc_82452290;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82452238:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// bne cr6,0x82452248
	if (!ctx.cr6.eq) goto loc_82452248;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82452248:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82452238
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82452238;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82452290
	if (ctx.cr6.eq) goto loc_82452290;
	// lwzx r11,r31,r19
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	// lwz r10,7392(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82452290
	if (!ctx.cr6.eq) goto loc_82452290;
	// stw r16,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r16.u32);
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r21,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r21.u32);
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446a18
	ctx.lr = 0x82452288;
	sub_82446A18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452428
	if (ctx.cr6.eq) goto loc_82452428;
loc_82452290:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82452428
	if (ctx.cr6.eq) goto loc_82452428;
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// stw r21,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r21.u32);
	// stw r22,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r22.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824523a4
	if (ctx.cr6.eq) goto loc_824523A4;
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8245238c
	if (!ctx.cr6.eq) goto loc_8245238C;
	// addi r6,r24,74
	ctx.r6.s64 = ctx.r24.s64 + 74;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x826a2720
	ctx.lr = 0x824522CC;
	sub_826A2720(ctx, base);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82452300
	if (ctx.cr6.eq) goto loc_82452300;
	// bl 0x82170cb0
	ctx.lr = 0x824522D8;
	sub_82170CB0(ctx, base);
	// lwz r11,904(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 904);
	// li r4,198
	ctx.r4.s64 = 198;
	// lwz r3,228(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// bl 0x82305298
	ctx.lr = 0x824522E8;
	sub_82305298(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r24,78
	ctx.r6.s64 = ctx.r24.s64 + 78;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x826a2720
	ctx.lr = 0x82452300;
	sub_826A2720(ctx, base);
loc_82452300:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82452338
	if (ctx.cr6.eq) goto loc_82452338;
	// bl 0x82170cb0
	ctx.lr = 0x8245230C;
	sub_82170CB0(ctx, base);
	// lwz r11,904(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 904);
	// li r4,199
	ctx.r4.s64 = 199;
	// lwz r3,228(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// bl 0x82305298
	ctx.lr = 0x8245231C;
	sub_82305298(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r6,r24,82
	ctx.r6.s64 = ctx.r24.s64 + 82;
	// addi r7,r1,384
	ctx.r7.s64 = ctx.r1.s64 + 384;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x826a2720
	ctx.lr = 0x82452338;
	sub_826A2720(ctx, base);
loc_82452338:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82452370
	if (ctx.cr6.eq) goto loc_82452370;
	// bl 0x82170cb0
	ctx.lr = 0x82452344;
	sub_82170CB0(ctx, base);
	// lwz r11,904(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 904);
	// li r4,200
	ctx.r4.s64 = 200;
	// lwz r3,228(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// bl 0x82305298
	ctx.lr = 0x82452354;
	sub_82305298(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r6,r24,90
	ctx.r6.s64 = ctx.r24.s64 + 90;
	// addi r7,r1,384
	ctx.r7.s64 = ctx.r1.s64 + 384;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x826a2720
	ctx.lr = 0x82452370;
	sub_826A2720(ctx, base);
loc_82452370:
	// bl 0x82459718
	ctx.lr = 0x82452374;
	sub_82459718(ctx, base);
	// bl 0x82170cb0
	ctx.lr = 0x82452378;
	sub_82170CB0(ctx, base);
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// li r5,120
	ctx.r5.s64 = 120;
	// lwz r3,900(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 900);
	// bl 0x82373588
	ctx.lr = 0x82452388;
	sub_82373588(ctx, base);
	// b 0x824523a4
	goto loc_824523A4;
loc_8245238C:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x824523a4
	if (!ctx.cr6.eq) goto loc_824523A4;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,130
	ctx.r4.s64 = 130;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x824523A4;
	sub_82446938(ctx, base);
loc_824523A4:
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x824523B4;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824523f0
	if (ctx.cr6.eq) goto loc_824523F0;
	// li r4,61
	ctx.r4.s64 = 61;
	// bl 0x8245c750
	ctx.lr = 0x824523C8;
	sub_8245C750(ctx, base);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,255
	ctx.r7.s64 = 255;
	// li r6,12
	ctx.r6.s64 = 12;
	// li r5,172
	ctx.r5.s64 = 172;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824523F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824523F0:
	// lwz r11,7412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7412);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r9,7408(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7408);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8245b7d8
	ctx.lr = 0x82452414;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452428
	if (ctx.cr6.eq) goto loc_82452428;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// bl 0x8245b038
	ctx.lr = 0x82452428;
	sub_8245B038(ctx, base);
loc_82452428:
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// stw r22,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r22.u32);
	// addi r11,r11,6504
	ctx.r11.s64 = ctx.r11.s64 + 6504;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x824524ec
	if (!ctx.cr6.eq) goto loc_824524EC;
	// lwzx r11,r31,r18
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r18.u32);
	// lwz r10,7384(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7384);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r21,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r21.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x824524ec
	if (ctx.cr6.lt) goto loc_824524EC;
	// lwz r11,7448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x824524d0
	if (!ctx.cr6.gt) goto loc_824524D0;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82452478:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// bne cr6,0x82452488
	if (!ctx.cr6.eq) goto loc_82452488;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
loc_82452488:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82452478
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82452478;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824524d0
	if (ctx.cr6.eq) goto loc_824524D0;
	// lwzx r11,r31,r19
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	// lwz r10,7392(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x824524d0
	if (!ctx.cr6.eq) goto loc_824524D0;
	// stw r16,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r16.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stw r21,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r21.u32);
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446a18
	ctx.lr = 0x824524C8;
	sub_82446A18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824524ec
	if (ctx.cr6.eq) goto loc_824524EC;
loc_824524D0:
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824524ec
	if (ctx.cr6.eq) goto loc_824524EC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,131
	ctx.r4.s64 = 131;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x824524EC;
	sub_82446938(ctx, base);
loc_824524EC:
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// stw r22,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r22.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82452548
	if (!ctx.cr6.eq) goto loc_82452548;
	// lwz r11,7372(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7372);
	// addi r10,r11,6504
	ctx.r10.s64 = ctx.r11.s64 + 6504;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82452548
	if (!ctx.cr6.eq) goto loc_82452548;
	// addi r11,r11,8004
	ctx.r11.s64 = ctx.r11.s64 + 8004;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82452548
	if (ctx.cr6.eq) goto loc_82452548;
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// stw r21,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r21.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82452548
	if (ctx.cr6.eq) goto loc_82452548;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,184
	ctx.r4.s64 = 184;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x82452548;
	sub_82446938(ctx, base);
loc_82452548:
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8245255c
	if (ctx.cr6.eq) goto loc_8245255C;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82453bc8
	if (!ctx.cr6.eq) goto loc_82453BC8;
loc_8245255C:
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453bc8
	if (ctx.cr6.eq) goto loc_82453BC8;
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453bc8
	if (ctx.cr6.eq) goto loc_82453BC8;
	// lwz r11,200(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82453bc8
	if (!ctx.cr6.eq) goto loc_82453BC8;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
	// bl 0x824459b8
	ctx.lr = 0x82452594;
	sub_824459B8(ctx, base);
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addis r20,r31,1
	ctx.r20.s64 = ctx.r31.s64 + 65536;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r20,r20,-21516
	ctx.r20.s64 = ctx.r20.s64 + -21516;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// li r24,0
	ctx.r24.s64 = 0;
	// stw r20,364(r1)
	REX_STORE_U32(ctx.r1.u32 + 364, ctx.r20.u32);
	// add r23,r3,r10
	ctx.r23.u64 = ctx.r3.u64 + ctx.r10.u64;
	// li r5,2000
	ctx.r5.s64 = 2000;
	// stw r24,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r24.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r24,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r24.u32);
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// stw r24,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r24.u32);
	// stw r23,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r23.u32);
	// bl 0x826a03b0
	ctx.lr = 0x824525D4;
	rexcrt_memset(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// li r5,2000
	ctx.r5.s64 = 2000;
	// addi r3,r3,-19516
	ctx.r3.s64 = ctx.r3.s64 + -19516;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,344(r1)
	REX_STORE_U32(ctx.r1.u32 + 344, ctx.r3.u32);
	// bl 0x826a03b0
	ctx.lr = 0x824525EC;
	rexcrt_memset(ctx, base);
	// addis r22,r31,1
	ctx.r22.s64 = ctx.r31.s64 + 65536;
	// li r5,2000
	ctx.r5.s64 = 2000;
	// addi r22,r22,-17516
	ctx.r22.s64 = ctx.r22.s64 + -17516;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// stw r22,348(r1)
	REX_STORE_U32(ctx.r1.u32 + 348, ctx.r22.u32);
	// bl 0x826a03b0
	ctx.lr = 0x82452608;
	rexcrt_memset(ctx, base);
	// lwz r21,7360(r31)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r31.u32 + 7360);
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// stw r21,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r21.u32);
	// beq cr6,0x82452620
	if (ctx.cr6.eq) goto loc_82452620;
	// cmpwi cr6,r21,10000
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 10000, ctx.xer);
	// bne cr6,0x82452630
	if (!ctx.cr6.eq) goto loc_82452630;
loc_82452620:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82447530
	ctx.lr = 0x82452628;
	sub_82447530(ctx, base);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
loc_82452630:
	// bl 0x82170cb0
	ctx.lr = 0x82452634;
	sub_82170CB0(ctx, base);
	// lwz r3,908(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 908);
	// bl 0x8238d760
	ctx.lr = 0x8245263C;
	sub_8238D760(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x823f20d8
	ctx.lr = 0x82452644;
	sub_823F20D8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x824529cc
	if (!ctx.cr6.gt) goto loc_824529CC;
loc_82452654:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823f2050
	ctx.lr = 0x82452660;
	sub_823F2050(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r29,r3,8
	ctx.r29.s64 = ctx.r3.s64 + 8;
	// cmpw cr6,r10,r21
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r21.s32, ctx.xer);
	// beq cr6,0x82452688
	if (ctx.cr6.eq) goto loc_82452688;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r26
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x82452654
	if (ctx.cr6.lt) goto loc_82452654;
	// b 0x824529cc
	goto loc_824529CC;
loc_82452688:
	// lwz r11,40(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82452788
	if (!ctx.cr6.gt) goto loc_82452788;
	// li r8,40
	ctx.r8.s64 = 40;
loc_8245269C:
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
loc_824526A0:
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824526bc
	if (ctx.cr6.eq) goto loc_824526BC;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x824526bc
	if (!ctx.cr6.gt) goto loc_824526BC;
	// lhzx r11,r29,r8
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + ctx.r8.u32);
	// b 0x824526c0
	goto loc_824526C0;
loc_824526BC:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_824526C0:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82452724
	if (ctx.cr6.eq) goto loc_82452724;
	// cmpwi cr6,r9,22
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 22, ctx.xer);
	// beq cr6,0x824526e0
	if (ctx.cr6.eq) goto loc_824526E0;
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r23
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r23.u32);
	// b 0x824526f4
	goto loc_824526F4;
loc_824526E0:
	// lbz r11,53(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + 53);
	// lbz r10,54(r23)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r23.u32 + 54);
	// rotlwi r6,r11,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
loc_824526F4:
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82452710
	if (ctx.cr6.eq) goto loc_82452710;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x82452710
	if (!ctx.cr6.gt) goto loc_82452710;
	// lhzx r11,r29,r8
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + ctx.r8.u32);
	// b 0x82452714
	goto loc_82452714;
loc_82452710:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82452714:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82452734
	if (ctx.cr6.eq) goto loc_82452734;
loc_82452724:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r9,23
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 23, ctx.xer);
	// blt cr6,0x824526a0
	if (ctx.cr6.lt) goto loc_824526A0;
	// b 0x82452774
	goto loc_82452774;
loc_82452734:
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82452750
	if (ctx.cr6.eq) goto loc_82452750;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x82452750
	if (!ctx.cr6.gt) goto loc_82452750;
	// lhzx r11,r29,r8
	ctx.r11.u64 = REX_LOAD_U16(ctx.r29.u32 + ctx.r8.u32);
	// b 0x82452754
	goto loc_82452754;
loc_82452750:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82452754:
	// lwz r10,8008(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r10,11005
	ctx.r10.s64 = ctx.r10.s64 + 11005;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r11,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r6.u32);
loc_82452774:
	// lwz r11,40(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 40);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8245269c
	if (ctx.cr6.lt) goto loc_8245269C;
loc_82452788:
	// lwz r11,44(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// mr r9,r24
	ctx.r9.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x824528b0
	if (!ctx.cr6.gt) goto loc_824528B0;
loc_82452798:
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
loc_8245279C:
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824527c8
	if (ctx.cr6.eq) goto loc_824527C8;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x824527c8
	if (!ctx.cr6.gt) goto loc_824527C8;
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r10,r29
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r29.u32);
	// b 0x824527cc
	goto loc_824527CC;
loc_824527C8:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_824527CC:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82452840
	if (ctx.cr6.eq) goto loc_82452840;
	// cmpwi cr6,r8,22
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 22, ctx.xer);
	// beq cr6,0x824527ec
	if (ctx.cr6.eq) goto loc_824527EC;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r23
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r23.u32);
	// b 0x82452800
	goto loc_82452800;
loc_824527EC:
	// lbz r11,53(r23)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + 53);
	// lbz r10,54(r23)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r23.u32 + 54);
	// rotlwi r7,r11,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// clrlwi r10,r6,16
	ctx.r10.u64 = ctx.r6.u32 & 0xFFFF;
loc_82452800:
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245282c
	if (ctx.cr6.eq) goto loc_8245282C;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8245282c
	if (!ctx.cr6.gt) goto loc_8245282C;
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r7,r29
	ctx.r11.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r29.u32);
	// b 0x82452830
	goto loc_82452830;
loc_8245282C:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82452830:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82452850
	if (ctx.cr6.eq) goto loc_82452850;
loc_82452840:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,23
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 23, ctx.xer);
	// blt cr6,0x8245279c
	if (ctx.cr6.lt) goto loc_8245279C;
	// b 0x824528a0
	goto loc_824528A0;
loc_82452850:
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245287c
	if (ctx.cr6.eq) goto loc_8245287C;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8245287c
	if (!ctx.cr6.gt) goto loc_8245287C;
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r10,r29
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r29.u32);
	// b 0x82452880
	goto loc_82452880;
loc_8245287C:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_82452880:
	// lwz r10,8012(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r10,11505
	ctx.r10.s64 = ctx.r10.s64 + 11505;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r11,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r7.u32);
loc_824528A0:
	// lwz r11,44(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 44);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82452798
	if (ctx.cr6.lt) goto loc_82452798;
loc_824528B0:
	// lwz r4,20(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r30,24(r28)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x824528c8
	if (!ctx.cr6.eq) goto loc_824528C8;
	// li r4,23
	ctx.r4.s64 = 23;
	// b 0x824528dc
	goto loc_824528DC;
loc_824528C8:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd830
	ctx.lr = 0x824528D0;
	sub_821FD830(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd4c8
	ctx.lr = 0x824528D8;
	sub_821FD4C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_824528DC:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82447e70
	ctx.lr = 0x824528E8;
	sub_82447E70(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x824529cc
	if (!ctx.cr6.eq) goto loc_824529CC;
	// lwz r4,20(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82452914
	if (ctx.cr6.eq) goto loc_82452914;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd830
	ctx.lr = 0x82452904;
	sub_821FD830(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd4c8
	ctx.lr = 0x8245290C;
	sub_821FD4C8(ctx, base);
	// cmpwi cr6,r3,18
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 18, ctx.xer);
	// beq cr6,0x82452934
	if (ctx.cr6.eq) goto loc_82452934;
loc_82452914:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823f1cc0
	ctx.lr = 0x8245291C;
	sub_823F1CC0(ctx, base);
	// cmpwi cr6,r3,19
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 19, ctx.xer);
	// beq cr6,0x82452934
	if (ctx.cr6.eq) goto loc_82452934;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823f1cc0
	ctx.lr = 0x8245292C;
	sub_823F1CC0(ctx, base);
	// cmpwi cr6,r3,20
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 20, ctx.xer);
	// bne cr6,0x824529a4
	if (!ctx.cr6.eq) goto loc_824529A4;
loc_82452934:
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
loc_82452938:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823f2050
	ctx.lr = 0x82452944;
	sub_823F2050(ctx, base);
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r30,r3,8
	ctx.r30.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82452998
	if (ctx.cr6.eq) goto loc_82452998;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd830
	ctx.lr = 0x8245295C;
	sub_821FD830(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd4c8
	ctx.lr = 0x82452964;
	sub_821FD4C8(ctx, base);
	// cmpwi cr6,r3,17
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 17, ctx.xer);
	// bne cr6,0x82452998
	if (!ctx.cr6.eq) goto loc_82452998;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82452998
	if (ctx.cr6.eq) goto loc_82452998;
	// lwz r10,8016(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// addi r10,r10,12005
	ctx.r10.s64 = ctx.r10.s64 + 12005;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r11,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,8016(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r8.u32);
loc_82452998:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r26
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x82452938
	if (ctx.cr6.lt) goto loc_82452938;
loc_824529A4:
	// lwz r11,24(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x824529cc
	if (!ctx.cr6.gt) goto loc_824529CC;
	// lwz r10,8016(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// addi r10,r10,12005
	ctx.r10.s64 = ctx.r10.s64 + 12005;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r11,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,8016(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r8.u32);
loc_824529CC:
	// lwz r11,7448(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// li r25,1
	ctx.r25.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82452ab0
	if (!ctx.cr6.gt) goto loc_82452AB0;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_824529EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// bne cr6,0x824529fc
	if (!ctx.cr6.eq) goto loc_824529FC;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_824529FC:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x824529ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824529EC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82452ab0
	if (ctx.cr6.eq) goto loc_82452AB0;
	// lwzx r11,r31,r19
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	// lwz r10,7392(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82452ab0
	if (!ctx.cr6.eq) goto loc_82452AB0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82447e70
	ctx.lr = 0x82452A30;
	sub_82447E70(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452ab0
	if (!ctx.cr6.eq) goto loc_82452AB0;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x82452ab0
	if (!ctx.cr6.gt) goto loc_82452AB0;
loc_82452A44:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823f2050
	ctx.lr = 0x82452A50;
	sub_823F2050(ctx, base);
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r30,r3,8
	ctx.r30.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82452aa4
	if (ctx.cr6.eq) goto loc_82452AA4;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd830
	ctx.lr = 0x82452A68;
	sub_821FD830(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd4c8
	ctx.lr = 0x82452A70;
	sub_821FD4C8(ctx, base);
	// cmpwi cr6,r3,17
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 17, ctx.xer);
	// bne cr6,0x82452aa4
	if (!ctx.cr6.eq) goto loc_82452AA4;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82452aa4
	if (ctx.cr6.eq) goto loc_82452AA4;
	// lwz r10,8016(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// addi r10,r10,12005
	ctx.r10.s64 = ctx.r10.s64 + 12005;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r11,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r11.u32);
	// lwz r11,8016(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r8.u32);
loc_82452AA4:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r26
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x82452a44
	if (ctx.cr6.lt) goto loc_82452A44;
loc_82452AB0:
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// lwz r11,7384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7384);
	// addi r14,r10,3160
	ctx.r14.s64 = ctx.r10.s64 + 3160;
	// lwzx r10,r31,r18
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r18.u32);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r14,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r14.u32);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82452c64
	if (ctx.cr6.eq) goto loc_82452C64;
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82452c64
	if (ctx.cr6.eq) goto loc_82452C64;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82452c64
	if (ctx.cr6.eq) goto loc_82452C64;
	// lwz r7,7448(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x82452b30
	if (!ctx.cr6.gt) goto loc_82452B30;
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82452B04:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r9,17
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 17, ctx.xer);
	// bne cr6,0x82452b14
	if (!ctx.cr6.eq) goto loc_82452B14;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_82452B14:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82452b04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82452B04;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82452b30
	if (ctx.cr6.eq) goto loc_82452B30;
	// lwzx r8,r31,r19
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	// addi r11,r8,2
	ctx.r11.s64 = ctx.r8.s64 + 2;
	// b 0x82452b38
	goto loc_82452B38;
loc_82452B30:
	// lwzx r8,r31,r19
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r19.u32);
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
loc_82452B38:
	// lwz r9,7392(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7392);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82452c64
	if (ctx.cr6.eq) goto loc_82452C64;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x82452b88
	if (!ctx.cr6.gt) goto loc_82452B88;
	// lwz r6,7448(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_82452B5C:
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r6,17
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 17, ctx.xer);
	// bne cr6,0x82452b6c
	if (!ctx.cr6.eq) goto loc_82452B6C;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_82452B6C:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82452b5c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82452B5C;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82452b88
	if (ctx.cr6.eq) goto loc_82452B88;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82452c64
	if (ctx.cr6.eq) goto loc_82452C64;
loc_82452B88:
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82452bb4
	if (!ctx.cr6.eq) goto loc_82452BB4;
	// lwz r11,7336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7336);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r10,r14
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	// cmpwi cr6,r6,20
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 20, ctx.xer);
	// beq cr6,0x82452bb4
	if (ctx.cr6.eq) goto loc_82452BB4;
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82452c64
	if (ctx.cr6.eq) goto loc_82452C64;
loc_82452BB4:
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x82452bf0
	if (!ctx.cr6.gt) goto loc_82452BF0;
	// lwz r7,7448(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 7448);
	// add r11,r31,r17
	ctx.r11.u64 = ctx.r31.u64 + ctx.r17.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82452BCC:
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r7,17
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 17, ctx.xer);
	// bne cr6,0x82452bdc
	if (!ctx.cr6.eq) goto loc_82452BDC;
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_82452BDC:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x82452bcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82452BCC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r11,r8,3
	ctx.r11.s64 = ctx.r8.s64 + 3;
	// bne cr6,0x82452bf4
	if (!ctx.cr6.eq) goto loc_82452BF4;
loc_82452BF0:
	// addi r11,r8,2
	ctx.r11.s64 = ctx.r8.s64 + 2;
loc_82452BF4:
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82452c64
	if (ctx.cr6.eq) goto loc_82452C64;
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452C08;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452c64
	if (!ctx.cr6.eq) goto loc_82452C64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452C1C;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452c64
	if (!ctx.cr6.eq) goto loc_82452C64;
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452C30;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452c64
	if (!ctx.cr6.eq) goto loc_82452C64;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452C44;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452c64
	if (!ctx.cr6.eq) goto loc_82452C64;
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452C58;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452c64
	if (!ctx.cr6.eq) goto loc_82452C64;
	// stw r24,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r24.u32);
loc_82452C64:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452C70;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452cb0
	if (ctx.cr6.eq) goto loc_82452CB0;
	// stw r16,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r16.u32);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r24,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r24.u32);
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446a18
	ctx.lr = 0x82452C94;
	sub_82446A18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452cb0
	if (ctx.cr6.eq) goto loc_82452CB0;
	// stw r24,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r24.u32);
	// stw r25,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r25.u32);
	// stw r24,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r24.u32);
	// lhz r11,34(r23)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r23.u32 + 34);
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_82452CB0:
	// lwz r11,7336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7336);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r14
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	// cmpwi cr6,r9,9
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 9, ctx.xer);
	// bne cr6,0x82452f80
	if (!ctx.cr6.eq) goto loc_82452F80;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82452cd8
	if (ctx.cr6.eq) goto loc_82452CD8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82452f80
	if (!ctx.cr6.eq) goto loc_82452F80;
loc_82452CD8:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452CE4;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452d00
	if (!ctx.cr6.eq) goto loc_82452D00;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452CF8;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452f80
	if (ctx.cr6.eq) goto loc_82452F80;
loc_82452D00:
	// li r11,180
	ctx.r11.s64 = 180;
	// li r10,182
	ctx.r10.s64 = 182;
	// li r9,183
	ctx.r9.s64 = 183;
	// stw r11,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r11.u32);
	// li r8,184
	ctx.r8.s64 = 184;
	// stw r10,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r10.u32);
	// stw r9,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r9.u32);
	// li r7,185
	ctx.r7.s64 = 185;
	// stw r8,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r8.u32);
	// li r6,186
	ctx.r6.s64 = 186;
	// li r5,187
	ctx.r5.s64 = 187;
	// stw r7,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r7.u32);
	// li r4,188
	ctx.r4.s64 = 188;
	// stw r6,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r6.u32);
	// li r3,189
	ctx.r3.s64 = 189;
	// stw r5,248(r1)
	REX_STORE_U32(ctx.r1.u32 + 248, ctx.r5.u32);
	// li r11,190
	ctx.r11.s64 = 190;
	// stw r4,252(r1)
	REX_STORE_U32(ctx.r1.u32 + 252, ctx.r4.u32);
	// li r10,191
	ctx.r10.s64 = 191;
	// stw r3,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r3.u32);
	// li r9,192
	ctx.r9.s64 = 192;
	// stw r11,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r11.u32);
	// li r8,193
	ctx.r8.s64 = 193;
	// stw r10,264(r1)
	REX_STORE_U32(ctx.r1.u32 + 264, ctx.r10.u32);
	// stw r9,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r9.u32);
	// li r7,194
	ctx.r7.s64 = 194;
	// stw r8,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r8.u32);
	// li r6,195
	ctx.r6.s64 = 195;
	// li r5,196
	ctx.r5.s64 = 196;
	// stw r7,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r7.u32);
	// li r4,197
	ctx.r4.s64 = 197;
	// stw r6,280(r1)
	REX_STORE_U32(ctx.r1.u32 + 280, ctx.r6.u32);
	// li r3,198
	ctx.r3.s64 = 198;
	// stw r5,284(r1)
	REX_STORE_U32(ctx.r1.u32 + 284, ctx.r5.u32);
	// li r11,199
	ctx.r11.s64 = 199;
	// stw r4,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r4.u32);
	// li r10,200
	ctx.r10.s64 = 200;
	// stw r3,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r3.u32);
	// li r9,201
	ctx.r9.s64 = 201;
	// stw r11,296(r1)
	REX_STORE_U32(ctx.r1.u32 + 296, ctx.r11.u32);
	// li r8,202
	ctx.r8.s64 = 202;
	// stw r10,300(r1)
	REX_STORE_U32(ctx.r1.u32 + 300, ctx.r10.u32);
	// stw r9,304(r1)
	REX_STORE_U32(ctx.r1.u32 + 304, ctx.r9.u32);
	// li r7,203
	ctx.r7.s64 = 203;
	// stw r8,308(r1)
	REX_STORE_U32(ctx.r1.u32 + 308, ctx.r8.u32);
	// li r6,204
	ctx.r6.s64 = 204;
	// li r5,205
	ctx.r5.s64 = 205;
	// stw r7,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r7.u32);
	// li r4,206
	ctx.r4.s64 = 206;
	// stw r6,316(r1)
	REX_STORE_U32(ctx.r1.u32 + 316, ctx.r6.u32);
	// li r3,207
	ctx.r3.s64 = 207;
	// stw r5,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r5.u32);
	// li r11,208
	ctx.r11.s64 = 208;
	// stw r4,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r4.u32);
	// li r10,209
	ctx.r10.s64 = 209;
	// stw r3,328(r1)
	REX_STORE_U32(ctx.r1.u32 + 328, ctx.r3.u32);
	// li r9,210
	ctx.r9.s64 = 210;
	// stw r11,332(r1)
	REX_STORE_U32(ctx.r1.u32 + 332, ctx.r11.u32);
	// li r8,321
	ctx.r8.s64 = 321;
	// stw r10,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, ctx.r10.u32);
	// stw r9,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r9.u32);
	// li r7,323
	ctx.r7.s64 = 323;
	// stw r8,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// li r6,324
	ctx.r6.s64 = 324;
	// li r5,325
	ctx.r5.s64 = 325;
	// stw r7,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// li r4,326
	ctx.r4.s64 = 326;
	// stw r6,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// li r3,327
	ctx.r3.s64 = 327;
	// stw r5,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r5.u32);
	// li r11,328
	ctx.r11.s64 = 328;
	// stw r4,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r4.u32);
	// li r10,329
	ctx.r10.s64 = 329;
	// stw r3,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// li r9,330
	ctx.r9.s64 = 330;
	// stw r11,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// li r8,331
	ctx.r8.s64 = 331;
	// stw r10,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stw r9,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// stw r8,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r8.u32);
	// mr r27,r24
	ctx.r27.u64 = ctx.r24.u64;
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// addi r30,r1,224
	ctx.r30.s64 = ctx.r1.s64 + 224;
loc_82452E54:
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r19,0(r30)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x821e89a8
	ctx.lr = 0x82452E64;
	sub_821E89A8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82452e84
	if (ctx.cr6.eq) goto loc_82452E84;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpwi cr6,r29,30
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 30, ctx.xer);
	// blt cr6,0x82452e54
	if (ctx.cr6.lt) goto loc_82452E54;
	// b 0x82452e88
	goto loc_82452E88;
loc_82452E84:
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
loc_82452E88:
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
loc_82452E90:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r9,r21
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r21.s32, ctx.xer);
	// beq cr6,0x82452eb0
	if (ctx.cr6.eq) goto loc_82452EB0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// blt cr6,0x82452e90
	if (ctx.cr6.lt) goto loc_82452E90;
	// b 0x82452eb4
	goto loc_82452EB4;
loc_82452EB0:
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
loc_82452EB4:
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
loc_82452EBC:
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r19,0(r30)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x821e89a8
	ctx.lr = 0x82452ECC;
	sub_821E89A8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82452eec
	if (ctx.cr6.eq) goto loc_82452EEC;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpwi cr6,r29,10
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 10, ctx.xer);
	// blt cr6,0x82452ebc
	if (ctx.cr6.lt) goto loc_82452EBC;
	// b 0x82452ef0
	goto loc_82452EF0;
loc_82452EEC:
	// mr r26,r25
	ctx.r26.u64 = ctx.r25.u64;
loc_82452EF0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82452f48
	if (!ctx.cr6.eq) goto loc_82452F48;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82452f48
	if (ctx.cr6.eq) goto loc_82452F48;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452F0C;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452f48
	if (ctx.cr6.eq) goto loc_82452F48;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r24,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r24.u32);
	// addi r10,r1,220
	ctx.r10.s64 = ctx.r1.s64 + 220;
	// stw r24,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r24.u32);
	// stw r11,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r11.u32);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// addi r9,r22,-4
	ctx.r9.s64 = ctx.r22.s64 + -4;
loc_82452F30:
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// lwz r8,8016(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x82452f30
	if (ctx.cr6.lt) goto loc_82452F30;
loc_82452F48:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82452f80
	if (ctx.cr6.eq) goto loc_82452F80;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452F5C;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82452f80
	if (ctx.cr6.eq) goto loc_82452F80;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// bne cr6,0x82452f80
	if (!ctx.cr6.eq) goto loc_82452F80;
	// stw r24,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r24.u32);
	// stw r25,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r25.u32);
	// stw r24,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r24.u32);
	// lhz r11,20(r23)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r23.u32 + 20);
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_82452F80:
	// lwz r11,7336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7336);
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r14
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r14.u32);
	// cmpwi cr6,r10,33
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 33, ctx.xer);
	// bne cr6,0x82453048
	if (!ctx.cr6.eq) goto loc_82453048;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82452fa8
	if (ctx.cr6.eq) goto loc_82452FA8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82453048
	if (!ctx.cr6.eq) goto loc_82453048;
loc_82452FA8:
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452FB4;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82452fd0
	if (!ctx.cr6.eq) goto loc_82452FD0;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452FC8;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453048
	if (ctx.cr6.eq) goto loc_82453048;
loc_82452FD0:
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82452FDC;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8245300c
	if (ctx.cr6.eq) goto loc_8245300C;
	// lhz r11,14(r23)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r23.u32 + 14);
	// cmplwi cr6,r11,42
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 42, ctx.xer);
	// bne cr6,0x8245300c
	if (!ctx.cr6.eq) goto loc_8245300C;
	// cmpwi cr6,r21,386
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 386, ctx.xer);
	// bne cr6,0x8245300c
	if (!ctx.cr6.eq) goto loc_8245300C;
	// stw r24,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r24.u32);
	// stw r25,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r25.u32);
	// stw r24,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r24.u32);
	// lhz r11,14(r23)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r23.u32 + 14);
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_8245300C:
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82453018;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453048
	if (ctx.cr6.eq) goto loc_82453048;
	// lhz r11,22(r23)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r23.u32 + 22);
	// cmplwi cr6,r11,386
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 386, ctx.xer);
	// bne cr6,0x82453048
	if (!ctx.cr6.eq) goto loc_82453048;
	// cmpwi cr6,r21,42
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 42, ctx.xer);
	// bne cr6,0x82453048
	if (!ctx.cr6.eq) goto loc_82453048;
	// stw r24,8016(r31)
	REX_STORE_U32(ctx.r31.u32 + 8016, ctx.r24.u32);
	// stw r25,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r25.u32);
	// stw r24,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r24.u32);
	// lhz r11,22(r23)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r23.u32 + 22);
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_82453048:
	// lwzx r11,r30,r14
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r14.u32);
	// li r15,254
	ctx.r15.s64 = 254;
	// li r16,255
	ctx.r16.s64 = 255;
	// li r17,256
	ctx.r17.s64 = 256;
	// li r18,257
	ctx.r18.s64 = 257;
	// li r19,258
	ctx.r19.s64 = 258;
	// li r20,259
	ctx.r20.s64 = 259;
	// li r21,260
	ctx.r21.s64 = 260;
	// li r22,261
	ctx.r22.s64 = 261;
	// li r23,262
	ctx.r23.s64 = 262;
	// li r24,263
	ctx.r24.s64 = 263;
	// li r25,264
	ctx.r25.s64 = 264;
	// li r26,265
	ctx.r26.s64 = 265;
	// li r27,266
	ctx.r27.s64 = 266;
	// li r28,267
	ctx.r28.s64 = 267;
	// cmpwi cr6,r11,27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 27, ctx.xer);
	// bne cr6,0x8245332c
	if (!ctx.cr6.eq) goto loc_8245332C;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x824530a0
	if (ctx.cr6.eq) goto loc_824530A0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8245332c
	if (!ctx.cr6.eq) goto loc_8245332C;
loc_824530A0:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x824530AC;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x824530c8
	if (!ctx.cr6.eq) goto loc_824530C8;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x824530C0;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8245332c
	if (ctx.cr6.eq) goto loc_8245332C;
loc_824530C8:
	// li r11,215
	ctx.r11.s64 = 215;
	// stw r15,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r15.u32);
	// li r9,216
	ctx.r9.s64 = 216;
	// stw r16,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r16.u32);
	// li r8,217
	ctx.r8.s64 = 217;
	// stw r11,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// li r7,218
	ctx.r7.s64 = 218;
	// stw r9,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r9.u32);
	// li r6,219
	ctx.r6.s64 = 219;
	// stw r8,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// li r5,220
	ctx.r5.s64 = 220;
	// stw r7,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r7.u32);
	// li r4,221
	ctx.r4.s64 = 221;
	// stw r6,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r6.u32);
	// li r11,132
	ctx.r11.s64 = 132;
	// stw r5,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// li r9,230
	ctx.r9.s64 = 230;
	// stw r4,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r4.u32);
	// li r3,131
	ctx.r3.s64 = 131;
	// stw r11,228(r1)
	REX_STORE_U32(ctx.r1.u32 + 228, ctx.r11.u32);
	// li r8,231
	ctx.r8.s64 = 231;
	// stw r9,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r9.u32);
	// li r7,232
	ctx.r7.s64 = 232;
	// stw r3,224(r1)
	REX_STORE_U32(ctx.r1.u32 + 224, ctx.r3.u32);
	// li r6,233
	ctx.r6.s64 = 233;
	// stw r8,236(r1)
	REX_STORE_U32(ctx.r1.u32 + 236, ctx.r8.u32);
	// li r5,235
	ctx.r5.s64 = 235;
	// stw r7,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r7.u32);
	// li r4,245
	ctx.r4.s64 = 245;
	// stw r6,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r6.u32);
	// li r11,247
	ctx.r11.s64 = 247;
	// stw r5,248(r1)
	REX_STORE_U32(ctx.r1.u32 + 248, ctx.r5.u32);
	// li r9,248
	ctx.r9.s64 = 248;
	// stw r4,252(r1)
	REX_STORE_U32(ctx.r1.u32 + 252, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,260(r1)
	REX_STORE_U32(ctx.r1.u32 + 260, ctx.r11.u32);
	// li r3,246
	ctx.r3.s64 = 246;
	// stw r9,264(r1)
	REX_STORE_U32(ctx.r1.u32 + 264, ctx.r9.u32);
	// li r8,249
	ctx.r8.s64 = 249;
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// li r7,250
	ctx.r7.s64 = 250;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r6,251
	ctx.r6.s64 = 251;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r5,252
	ctx.r5.s64 = 252;
	// stw r10,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r10.u32);
	// li r4,253
	ctx.r4.s64 = 253;
	// stw r10,368(r1)
	REX_STORE_U32(ctx.r1.u32 + 368, ctx.r10.u32);
	// stw r3,256(r1)
	REX_STORE_U32(ctx.r1.u32 + 256, ctx.r3.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stw r8,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r8.u32);
	// stw r7,272(r1)
	REX_STORE_U32(ctx.r1.u32 + 272, ctx.r7.u32);
	// stw r6,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r6.u32);
	// stw r5,280(r1)
	REX_STORE_U32(ctx.r1.u32 + 280, ctx.r5.u32);
	// stw r4,284(r1)
	REX_STORE_U32(ctx.r1.u32 + 284, ctx.r4.u32);
	// stw r17,296(r1)
	REX_STORE_U32(ctx.r1.u32 + 296, ctx.r17.u32);
	// stw r18,300(r1)
	REX_STORE_U32(ctx.r1.u32 + 300, ctx.r18.u32);
	// stw r19,304(r1)
	REX_STORE_U32(ctx.r1.u32 + 304, ctx.r19.u32);
	// stw r20,308(r1)
	REX_STORE_U32(ctx.r1.u32 + 308, ctx.r20.u32);
	// stw r21,312(r1)
	REX_STORE_U32(ctx.r1.u32 + 312, ctx.r21.u32);
	// stw r22,316(r1)
	REX_STORE_U32(ctx.r1.u32 + 316, ctx.r22.u32);
	// stw r23,320(r1)
	REX_STORE_U32(ctx.r1.u32 + 320, ctx.r23.u32);
	// stw r24,324(r1)
	REX_STORE_U32(ctx.r1.u32 + 324, ctx.r24.u32);
	// stw r25,328(r1)
	REX_STORE_U32(ctx.r1.u32 + 328, ctx.r25.u32);
	// stw r26,332(r1)
	REX_STORE_U32(ctx.r1.u32 + 332, ctx.r26.u32);
	// stw r27,336(r1)
	REX_STORE_U32(ctx.r1.u32 + 336, ctx.r27.u32);
	// stw r28,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r28.u32);
loc_824531D4:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x824531f4
	if (ctx.cr6.eq) goto loc_824531F4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// blt cr6,0x824531d4
	if (ctx.cr6.lt) goto loc_824531D4;
	// b 0x824531fc
	goto loc_824531FC;
loc_824531F4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_824531FC:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r1,144
	ctx.r30.s64 = ctx.r1.s64 + 144;
loc_82453204:
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r14,0(r30)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x821e89a8
	ctx.lr = 0x82453214;
	sub_821E89A8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r14,r11
	ctx.cr6.compare<int32_t>(ctx.r14.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82453234
	if (ctx.cr6.eq) goto loc_82453234;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpwi cr6,r29,7
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 7, ctx.xer);
	// blt cr6,0x82453204
	if (ctx.cr6.lt) goto loc_82453204;
	// b 0x8245323c
	goto loc_8245323C;
loc_82453234:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r11.u32);
loc_8245323C:
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
loc_82453248:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82453268
	if (ctx.cr6.eq) goto loc_82453268;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// blt cr6,0x82453248
	if (ctx.cr6.lt) goto loc_82453248;
	// b 0x82453270
	goto loc_82453270;
loc_82453268:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
loc_82453270:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r1,224
	ctx.r30.s64 = ctx.r1.s64 + 224;
loc_82453278:
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r14,0(r30)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r3,92(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x821e89a8
	ctx.lr = 0x82453288;
	sub_821E89A8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r14,r11
	ctx.cr6.compare<int32_t>(ctx.r14.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x824532ac
	if (ctx.cr6.eq) goto loc_824532AC;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpwi cr6,r29,30
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 30, ctx.xer);
	// blt cr6,0x82453278
	if (ctx.cr6.lt) goto loc_82453278;
	// lwz r10,368(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 368);
	// b 0x824532b0
	goto loc_824532B0;
loc_824532AC:
	// li r10,1
	ctx.r10.s64 = 1;
loc_824532B0:
	// lwz r11,196(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824532f0
	if (ctx.cr6.eq) goto loc_824532F0;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824532f0
	if (ctx.cr6.eq) goto loc_824532F0;
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// lwz r9,92(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// addi r11,r11,11505
	ctx.r11.s64 = ctx.r11.s64 + 11505;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r7,6(r9)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + 6);
	// stwx r7,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r7.u32);
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r6.u32);
	// b 0x824532f4
	goto loc_824532F4;
loc_824532F0:
	// lwz r9,92(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
loc_824532F4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82453328
	if (ctx.cr6.eq) goto loc_82453328;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453328
	if (ctx.cr6.eq) goto loc_82453328;
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// lhz r10,10(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 10);
	// addi r9,r11,11505
	ctx.r9.s64 = ctx.r11.s64 + 11505;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,8012(r31)
	REX_STORE_U32(ctx.r31.u32 + 8012, ctx.r7.u32);
loc_82453328:
	// lwz r14,80(r1)
	ctx.r14.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_8245332C:
	// lwz r11,7336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7336);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r14
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r14.u32);
	// cmpwi cr6,r9,19
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 19, ctx.xer);
	// bne cr6,0x82453718
	if (!ctx.cr6.eq) goto loc_82453718;
	// lwz r11,7376(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7376);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82453354
	if (ctx.cr6.eq) goto loc_82453354;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82453718
	if (!ctx.cr6.eq) goto loc_82453718;
loc_82453354:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82453360;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8245337c
	if (!ctx.cr6.eq) goto loc_8245337C;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82445c18
	ctx.lr = 0x82453374;
	sub_82445C18(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453718
	if (ctx.cr6.eq) goto loc_82453718;
loc_8245337C:
	// li r11,237
	ctx.r11.s64 = 237;
	// stw r25,492(r1)
	REX_STORE_U32(ctx.r1.u32 + 492, ctx.r25.u32);
	// li r10,238
	ctx.r10.s64 = 238;
	// stw r26,496(r1)
	REX_STORE_U32(ctx.r1.u32 + 496, ctx.r26.u32);
	// li r9,239
	ctx.r9.s64 = 239;
	// stw r11,384(r1)
	REX_STORE_U32(ctx.r1.u32 + 384, ctx.r11.u32);
	// li r8,240
	ctx.r8.s64 = 240;
	// stw r10,388(r1)
	REX_STORE_U32(ctx.r1.u32 + 388, ctx.r10.u32);
	// li r7,241
	ctx.r7.s64 = 241;
	// stw r9,392(r1)
	REX_STORE_U32(ctx.r1.u32 + 392, ctx.r9.u32);
	// li r6,242
	ctx.r6.s64 = 242;
	// stw r8,396(r1)
	REX_STORE_U32(ctx.r1.u32 + 396, ctx.r8.u32);
	// li r5,243
	ctx.r5.s64 = 243;
	// stw r7,400(r1)
	REX_STORE_U32(ctx.r1.u32 + 400, ctx.r7.u32);
	// li r4,244
	ctx.r4.s64 = 244;
	// stw r6,404(r1)
	REX_STORE_U32(ctx.r1.u32 + 404, ctx.r6.u32);
	// li r3,245
	ctx.r3.s64 = 245;
	// stw r5,408(r1)
	REX_STORE_U32(ctx.r1.u32 + 408, ctx.r5.u32);
	// li r11,246
	ctx.r11.s64 = 246;
	// stw r4,412(r1)
	REX_STORE_U32(ctx.r1.u32 + 412, ctx.r4.u32);
	// li r10,247
	ctx.r10.s64 = 247;
	// stw r3,416(r1)
	REX_STORE_U32(ctx.r1.u32 + 416, ctx.r3.u32);
	// li r9,248
	ctx.r9.s64 = 248;
	// stw r11,420(r1)
	REX_STORE_U32(ctx.r1.u32 + 420, ctx.r11.u32);
	// li r8,249
	ctx.r8.s64 = 249;
	// stw r10,424(r1)
	REX_STORE_U32(ctx.r1.u32 + 424, ctx.r10.u32);
	// li r7,250
	ctx.r7.s64 = 250;
	// stw r9,428(r1)
	REX_STORE_U32(ctx.r1.u32 + 428, ctx.r9.u32);
	// li r6,251
	ctx.r6.s64 = 251;
	// stw r8,432(r1)
	REX_STORE_U32(ctx.r1.u32 + 432, ctx.r8.u32);
	// li r5,252
	ctx.r5.s64 = 252;
	// stw r7,436(r1)
	REX_STORE_U32(ctx.r1.u32 + 436, ctx.r7.u32);
	// li r4,253
	ctx.r4.s64 = 253;
	// stw r6,440(r1)
	REX_STORE_U32(ctx.r1.u32 + 440, ctx.r6.u32);
	// li r3,268
	ctx.r3.s64 = 268;
	// stw r5,444(r1)
	REX_STORE_U32(ctx.r1.u32 + 444, ctx.r5.u32);
	// li r11,269
	ctx.r11.s64 = 269;
	// stw r4,448(r1)
	REX_STORE_U32(ctx.r1.u32 + 448, ctx.r4.u32);
	// li r10,270
	ctx.r10.s64 = 270;
	// stw r27,500(r1)
	REX_STORE_U32(ctx.r1.u32 + 500, ctx.r27.u32);
	// stw r28,504(r1)
	REX_STORE_U32(ctx.r1.u32 + 504, ctx.r28.u32);
	// li r9,271
	ctx.r9.s64 = 271;
	// li r8,272
	ctx.r8.s64 = 272;
	// stw r3,508(r1)
	REX_STORE_U32(ctx.r1.u32 + 508, ctx.r3.u32);
	// li r7,273
	ctx.r7.s64 = 273;
	// stw r11,512(r1)
	REX_STORE_U32(ctx.r1.u32 + 512, ctx.r11.u32);
	// li r6,274
	ctx.r6.s64 = 274;
	// stw r10,516(r1)
	REX_STORE_U32(ctx.r1.u32 + 516, ctx.r10.u32);
	// li r5,275
	ctx.r5.s64 = 275;
	// stw r15,452(r1)
	REX_STORE_U32(ctx.r1.u32 + 452, ctx.r15.u32);
	// li r4,276
	ctx.r4.s64 = 276;
	// stw r16,456(r1)
	REX_STORE_U32(ctx.r1.u32 + 456, ctx.r16.u32);
	// li r30,277
	ctx.r30.s64 = 277;
	// stw r17,460(r1)
	REX_STORE_U32(ctx.r1.u32 + 460, ctx.r17.u32);
	// li r29,278
	ctx.r29.s64 = 278;
	// stw r18,464(r1)
	REX_STORE_U32(ctx.r1.u32 + 464, ctx.r18.u32);
	// li r25,279
	ctx.r25.s64 = 279;
	// stw r19,468(r1)
	REX_STORE_U32(ctx.r1.u32 + 468, ctx.r19.u32);
	// li r26,280
	ctx.r26.s64 = 280;
	// stw r20,472(r1)
	REX_STORE_U32(ctx.r1.u32 + 472, ctx.r20.u32);
	// li r27,281
	ctx.r27.s64 = 281;
	// stw r21,476(r1)
	REX_STORE_U32(ctx.r1.u32 + 476, ctx.r21.u32);
	// li r28,282
	ctx.r28.s64 = 282;
	// stw r22,480(r1)
	REX_STORE_U32(ctx.r1.u32 + 480, ctx.r22.u32);
	// stw r23,484(r1)
	REX_STORE_U32(ctx.r1.u32 + 484, ctx.r23.u32);
	// li r3,283
	ctx.r3.s64 = 283;
	// stw r24,488(r1)
	REX_STORE_U32(ctx.r1.u32 + 488, ctx.r24.u32);
	// li r11,284
	ctx.r11.s64 = 284;
	// stw r9,520(r1)
	REX_STORE_U32(ctx.r1.u32 + 520, ctx.r9.u32);
	// li r10,285
	ctx.r10.s64 = 285;
	// stw r8,524(r1)
	REX_STORE_U32(ctx.r1.u32 + 524, ctx.r8.u32);
	// stw r7,528(r1)
	REX_STORE_U32(ctx.r1.u32 + 528, ctx.r7.u32);
	// stw r6,532(r1)
	REX_STORE_U32(ctx.r1.u32 + 532, ctx.r6.u32);
	// stw r5,536(r1)
	REX_STORE_U32(ctx.r1.u32 + 536, ctx.r5.u32);
	// stw r4,540(r1)
	REX_STORE_U32(ctx.r1.u32 + 540, ctx.r4.u32);
	// stw r30,544(r1)
	REX_STORE_U32(ctx.r1.u32 + 544, ctx.r30.u32);
	// stw r29,548(r1)
	REX_STORE_U32(ctx.r1.u32 + 548, ctx.r29.u32);
	// stw r25,552(r1)
	REX_STORE_U32(ctx.r1.u32 + 552, ctx.r25.u32);
	// stw r26,556(r1)
	REX_STORE_U32(ctx.r1.u32 + 556, ctx.r26.u32);
	// stw r27,560(r1)
	REX_STORE_U32(ctx.r1.u32 + 560, ctx.r27.u32);
	// stw r28,564(r1)
	REX_STORE_U32(ctx.r1.u32 + 564, ctx.r28.u32);
	// li r9,286
	ctx.r9.s64 = 286;
	// stw r11,572(r1)
	REX_STORE_U32(ctx.r1.u32 + 572, ctx.r11.u32);
	// li r8,287
	ctx.r8.s64 = 287;
	// stw r10,576(r1)
	REX_STORE_U32(ctx.r1.u32 + 576, ctx.r10.u32);
	// li r7,288
	ctx.r7.s64 = 288;
	// stw r9,580(r1)
	REX_STORE_U32(ctx.r1.u32 + 580, ctx.r9.u32);
	// li r6,289
	ctx.r6.s64 = 289;
	// stw r3,568(r1)
	REX_STORE_U32(ctx.r1.u32 + 568, ctx.r3.u32);
	// li r5,290
	ctx.r5.s64 = 290;
	// stw r8,584(r1)
	REX_STORE_U32(ctx.r1.u32 + 584, ctx.r8.u32);
	// stw r7,588(r1)
	REX_STORE_U32(ctx.r1.u32 + 588, ctx.r7.u32);
	// li r11,293
	ctx.r11.s64 = 293;
	// stw r6,592(r1)
	REX_STORE_U32(ctx.r1.u32 + 592, ctx.r6.u32);
	// li r10,294
	ctx.r10.s64 = 294;
	// stw r5,596(r1)
	REX_STORE_U32(ctx.r1.u32 + 596, ctx.r5.u32);
	// li r9,295
	ctx.r9.s64 = 295;
	// li r4,291
	ctx.r4.s64 = 291;
	// stw r11,608(r1)
	REX_STORE_U32(ctx.r1.u32 + 608, ctx.r11.u32);
	// li r3,292
	ctx.r3.s64 = 292;
	// stw r10,612(r1)
	REX_STORE_U32(ctx.r1.u32 + 612, ctx.r10.u32);
	// li r8,296
	ctx.r8.s64 = 296;
	// stw r9,616(r1)
	REX_STORE_U32(ctx.r1.u32 + 616, ctx.r9.u32);
	// li r7,297
	ctx.r7.s64 = 297;
	// stw r4,600(r1)
	REX_STORE_U32(ctx.r1.u32 + 600, ctx.r4.u32);
	// li r6,298
	ctx.r6.s64 = 298;
	// stw r3,604(r1)
	REX_STORE_U32(ctx.r1.u32 + 604, ctx.r3.u32);
	// li r5,299
	ctx.r5.s64 = 299;
	// stw r8,620(r1)
	REX_STORE_U32(ctx.r1.u32 + 620, ctx.r8.u32);
	// stw r7,624(r1)
	REX_STORE_U32(ctx.r1.u32 + 624, ctx.r7.u32);
	// li r11,302
	ctx.r11.s64 = 302;
	// stw r6,628(r1)
	REX_STORE_U32(ctx.r1.u32 + 628, ctx.r6.u32);
	// li r10,303
	ctx.r10.s64 = 303;
	// stw r5,632(r1)
	REX_STORE_U32(ctx.r1.u32 + 632, ctx.r5.u32);
	// li r9,304
	ctx.r9.s64 = 304;
	// li r4,300
	ctx.r4.s64 = 300;
	// stw r11,644(r1)
	REX_STORE_U32(ctx.r1.u32 + 644, ctx.r11.u32);
	// li r3,301
	ctx.r3.s64 = 301;
	// stw r10,648(r1)
	REX_STORE_U32(ctx.r1.u32 + 648, ctx.r10.u32);
	// li r8,305
	ctx.r8.s64 = 305;
	// stw r9,652(r1)
	REX_STORE_U32(ctx.r1.u32 + 652, ctx.r9.u32);
	// li r7,306
	ctx.r7.s64 = 306;
	// stw r4,636(r1)
	REX_STORE_U32(ctx.r1.u32 + 636, ctx.r4.u32);
	// li r6,307
	ctx.r6.s64 = 307;
	// stw r3,640(r1)
	REX_STORE_U32(ctx.r1.u32 + 640, ctx.r3.u32);
	// li r5,308
	ctx.r5.s64 = 308;
	// stw r8,656(r1)
	REX_STORE_U32(ctx.r1.u32 + 656, ctx.r8.u32);
	// li r11,311
	ctx.r11.s64 = 311;
	// stw r7,660(r1)
	REX_STORE_U32(ctx.r1.u32 + 660, ctx.r7.u32);
	// li r10,312
	ctx.r10.s64 = 312;
	// stw r6,664(r1)
	REX_STORE_U32(ctx.r1.u32 + 664, ctx.r6.u32);
	// li r9,313
	ctx.r9.s64 = 313;
	// stw r5,668(r1)
	REX_STORE_U32(ctx.r1.u32 + 668, ctx.r5.u32);
	// li r4,309
	ctx.r4.s64 = 309;
	// stw r11,680(r1)
	REX_STORE_U32(ctx.r1.u32 + 680, ctx.r11.u32);
	// li r3,310
	ctx.r3.s64 = 310;
	// stw r10,684(r1)
	REX_STORE_U32(ctx.r1.u32 + 684, ctx.r10.u32);
	// li r8,314
	ctx.r8.s64 = 314;
	// stw r9,688(r1)
	REX_STORE_U32(ctx.r1.u32 + 688, ctx.r9.u32);
	// li r7,315
	ctx.r7.s64 = 315;
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// li r6,316
	ctx.r6.s64 = 316;
	// stw r4,672(r1)
	REX_STORE_U32(ctx.r1.u32 + 672, ctx.r4.u32);
	// li r5,62
	ctx.r5.s64 = 62;
	// stw r3,676(r1)
	REX_STORE_U32(ctx.r1.u32 + 676, ctx.r3.u32);
	// stw r8,692(r1)
	REX_STORE_U32(ctx.r1.u32 + 692, ctx.r8.u32);
	// li r25,0
	ctx.r25.s64 = 0;
	// stw r7,696(r1)
	REX_STORE_U32(ctx.r1.u32 + 696, ctx.r7.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r6,700(r1)
	REX_STORE_U32(ctx.r1.u32 + 700, ctx.r6.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
loc_824535E8:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82453608
	if (ctx.cr6.eq) goto loc_82453608;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r10,80
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 80, ctx.xer);
	// blt cr6,0x824535e8
	if (ctx.cr6.lt) goto loc_824535E8;
	// b 0x8245360c
	goto loc_8245360C;
loc_82453608:
	// li r25,1
	ctx.r25.s64 = 1;
loc_8245360C:
	// lwz r24,92(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r1,384
	ctx.r30.s64 = ctx.r1.s64 + 384;
loc_82453618:
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r23,0(r30)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x821e89a8
	ctx.lr = 0x82453628;
	sub_821E89A8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r23,r11
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82453648
	if (ctx.cr6.eq) goto loc_82453648;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpwi cr6,r29,80
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 80, ctx.xer);
	// blt cr6,0x82453618
	if (ctx.cr6.lt) goto loc_82453618;
	// b 0x8245364c
	goto loc_8245364C;
loc_82453648:
	// li r28,1
	ctx.r28.s64 = 1;
loc_8245364C:
	// lwz r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_82453658:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x82453678
	if (ctx.cr6.eq) goto loc_82453678;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// blt cr6,0x82453658
	if (ctx.cr6.lt) goto loc_82453658;
	// b 0x8245367c
	goto loc_8245367C;
loc_82453678:
	// li r27,1
	ctx.r27.s64 = 1;
loc_8245367C:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
loc_82453684:
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r23,0(r30)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x821e89a8
	ctx.lr = 0x82453694;
	sub_821E89A8(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r23,r11
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x824536b4
	if (ctx.cr6.eq) goto loc_824536B4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// blt cr6,0x82453684
	if (ctx.cr6.lt) goto loc_82453684;
	// b 0x824536b8
	goto loc_824536B8;
loc_824536B4:
	// li r26,1
	ctx.r26.s64 = 1;
loc_824536B8:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x824536e8
	if (ctx.cr6.eq) goto loc_824536E8;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x824536e8
	if (ctx.cr6.eq) goto loc_824536E8;
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// lhz r10,8(r24)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + 8);
	// addi r9,r11,11005
	ctx.r9.s64 = ctx.r11.s64 + 11005;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r7.u32);
loc_824536E8:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82453718
	if (ctx.cr6.eq) goto loc_82453718;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82453718
	if (ctx.cr6.eq) goto loc_82453718;
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// lhz r10,14(r24)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + 14);
	// addi r9,r11,11005
	ctx.r9.s64 = ctx.r11.s64 + 11005;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,8008(r31)
	REX_STORE_U32(ctx.r31.u32 + 8008, ctx.r7.u32);
loc_82453718:
	// lwz r10,8016(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8245373c
	if (!ctx.cr6.gt) goto loc_8245373C;
	// lwz r25,348(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 348);
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// b 0x82453764
	goto loc_82453764;
loc_8245373C:
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82453750
	if (!ctx.cr6.gt) goto loc_82453750;
	// lwz r25,364(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 364);
	// b 0x82453760
	goto loc_82453760;
loc_82453750:
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82453764
	if (!ctx.cr6.gt) goto loc_82453764;
	// lwz r25,344(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 344);
loc_82453760:
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
loc_82453764:
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82453784
	if (ctx.cr6.gt) goto loc_82453784;
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x82453784
	if (ctx.cr6.gt) goto loc_82453784;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82453a14
	if (!ctx.cr6.gt) goto loc_82453A14;
loc_82453784:
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,19232
	ctx.r3.s64 = ctx.r3.s64 + 19232;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824537A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,192(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r9,184(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8245b7d8
	ctx.lr = 0x824537C4;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824537d4
	if (ctx.cr6.eq) goto loc_824537D4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8245ba20
	ctx.lr = 0x824537D4;
	sub_8245BA20(ctx, base);
loc_824537D4:
	// lis r11,26214
	ctx.r11.s64 = 1717960704;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// li r27,5
	ctx.r27.s64 = 5;
	// ori r28,r11,26215
	ctx.r28.u64 = ctx.r11.u64 | 26215;
loc_824537E4:
	// addi r26,r29,1
	ctx.r26.s64 = ctx.r29.s64 + 1;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x8245b7d8
	ctx.lr = 0x824537F8;
	sub_8245B7D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8245388c
	if (ctx.cr6.eq) goto loc_8245388C;
	// lwz r3,104(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// mulhw r11,r29,r28
	ctx.r11.s64 = (int64_t(ctx.r29.s32) * int64_t(ctx.r28.s32)) >> 32;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,68(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// divw r8,r29,r27
	ctx.r8.u64 = uint32_t((ctx.r27.s32 && !(ctx.r29.s32 == INT32_MIN && ctx.r27.s32 == -1)) ? ctx.r29.s32 / ctx.r27.s32 : 0);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// mulli r9,r8,95
	ctx.r9.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(95));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r9,-86
	ctx.r7.s64 = ctx.r9.s64 + -86;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r4,r5,r29
	ctx.r4.u64 = ctx.r29.u64 - ctx.r5.u64;
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// mulli r11,r4,95
	ctx.r11.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(95));
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// bctrl 
	ctx.lr = 0x82453854;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,104(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,80
	ctx.r4.s64 = 80;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82453874;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,104(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,100(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8245388C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8245388C:
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// cmpwi cr6,r26,25
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 25, ctx.xer);
	// blt cr6,0x824537e4
	if (ctx.cr6.lt) goto loc_824537E4;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_8245389C:
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x8245b7d8
	ctx.lr = 0x824538B0;
	sub_8245B7D8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824538d0
	if (ctx.cr6.eq) goto loc_824538D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8245ad40
	ctx.lr = 0x824538C4;
	sub_8245AD40(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8245af30
	ctx.lr = 0x824538D0;
	sub_8245AF30(ctx, base);
loc_824538D0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,25
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 25, ctx.xer);
	// blt cr6,0x8245389c
	if (ctx.cr6.lt) goto loc_8245389C;
	// li r26,1
	ctx.r26.s64 = 1;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// li r27,20
	ctx.r27.s64 = 20;
loc_824538EC:
	// addi r5,r29,5
	ctx.r5.s64 = ctx.r29.s64 + 5;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8245b7d8
	ctx.lr = 0x824538FC;
	sub_8245B7D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824539b4
	if (ctx.cr6.eq) goto loc_824539B4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,0(r28)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r3,104(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// bl 0x82444548
	ctx.lr = 0x82453918;
	sub_82444548(ctx, base);
	// lwz r3,104(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// li r6,255
	ctx.r6.s64 = 255;
	// li r5,255
	ctx.r5.s64 = 255;
	// li r4,255
	ctx.r4.s64 = 255;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453938;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,104(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// cmpw cr6,r29,r24
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r24.s32, ctx.xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// ble cr6,0x8245395c
	if (!ctx.cr6.gt) goto loc_8245395C;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453958;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x824539b4
	goto loc_824539B4;
loc_8245395C:
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453968;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,104(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,230
	ctx.r4.s64 = 230;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,92(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82453984;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,8008(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x824539b4
	if (ctx.cr6.eq) goto loc_824539B4;
	// lwz r11,8016(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgt cr6,0x824539b4
	if (ctx.cr6.gt) goto loc_824539B4;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245aba0
	ctx.lr = 0x824539A8;
	sub_8245ABA0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8245aac0
	ctx.lr = 0x824539B4;
	sub_8245AAC0(ctx, base);
loc_824539B4:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x824538ec
	if (!ctx.cr0.eq) goto loc_824538EC;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// stw r26,7416(r31)
	REX_STORE_U32(ctx.r31.u32 + 7416, ctx.r26.u32);
	// stw r23,7420(r31)
	REX_STORE_U32(ctx.r31.u32 + 7420, ctx.r23.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// ori r10,r11,51528
	ctx.r10.u64 = ctx.r11.u64 | 51528;
	// stw r26,7424(r31)
	REX_STORE_U32(ctx.r31.u32 + 7424, ctx.r26.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// stwx r23,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r23.u32);
	// bl 0x8245b7d8
	ctx.lr = 0x824539EC;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453a04
	if (ctx.cr6.eq) goto loc_82453A04;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// bl 0x8245ba20
	ctx.lr = 0x82453A04;
	sub_8245BA20(ctx, base);
loc_82453A04:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824455e0
	ctx.lr = 0x82453A10;
	sub_824455E0(ctx, base);
	// b 0x82453a18
	goto loc_82453A18;
loc_82453A14:
	// li r26,1
	ctx.r26.s64 = 1;
loc_82453A18:
	// lwz r11,8016(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8016);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82453aa8
	if (!ctx.cr6.gt) goto loc_82453AA8;
	// lwz r11,352(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 352);
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// bl 0x8245b738
	ctx.lr = 0x82453A3C;
	sub_8245B738(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
	// li r4,173
	ctx.r4.s64 = 173;
	// bl 0x8245c750
	ctx.lr = 0x82453A50;
	sub_8245C750(ctx, base);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,99
	ctx.r4.s64 = 99;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453A68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82453A84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,96(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82453A9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82453AA8:
	// lwz r11,8008(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8008);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82453b38
	if (!ctx.cr6.gt) goto loc_82453B38;
	// lwz r11,356(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 356);
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// bl 0x8245b738
	ctx.lr = 0x82453ACC;
	sub_8245B738(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
	// li r4,146
	ctx.r4.s64 = 146;
	// bl 0x8245c750
	ctx.lr = 0x82453AE0;
	sub_8245C750(ctx, base);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,99
	ctx.r4.s64 = 99;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453AF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82453B14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,96(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82453B2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82453B38:
	// lwz r11,8012(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8012);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82453bc8
	if (!ctx.cr6.gt) goto loc_82453BC8;
	// lwz r11,360(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 360);
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// stw r26,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// bl 0x8245b738
	ctx.lr = 0x82453B5C;
	sub_8245B738(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
	// li r4,172
	ctx.r4.s64 = 172;
	// bl 0x8245c750
	ctx.lr = 0x82453B70;
	sub_8245C750(ctx, base);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,99
	ctx.r4.s64 = 99;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453B88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82453BA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,96(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82453BBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82453BC8:
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// lwz r30,204(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453bf4
	if (ctx.cr6.eq) goto loc_82453BF4;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82453bf4
	if (!ctx.cr6.eq) goto loc_82453BF4;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,142
	ctx.r4.s64 = 142;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x82453BF4;
	sub_82446938(ctx, base);
loc_82453BF4:
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453cf8
	if (ctx.cr6.eq) goto loc_82453CF8;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453cf8
	if (ctx.cr6.eq) goto loc_82453CF8;
	// lwz r11,208(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453cf8
	if (ctx.cr6.eq) goto loc_82453CF8;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453cf8
	if (ctx.cr6.eq) goto loc_82453CF8;
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453cf8
	if (ctx.cr6.eq) goto loc_82453CF8;
	// lwz r11,200(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82453cf8
	if (!ctx.cr6.eq) goto loc_82453CF8;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,19232
	ctx.r3.s64 = ctx.r3.s64 + 19232;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453C5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32187
	ctx.r11.s64 = -2109407232;
	// lwz r9,96(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,1424
	ctx.r8.s64 = ctx.r11.s64 + 1424;
	// addi r10,r31,88
	ctx.r10.s64 = ctx.r31.s64 + 88;
	// stw r7,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// stw r7,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// stw r7,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// bne cr6,0x82453cb8
	if (!ctx.cr6.eq) goto loc_82453CB8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82453cb8
	if (!ctx.cr6.eq) goto loc_82453CB8;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82453cb8
	if (!ctx.cr6.eq) goto loc_82453CB8;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
loc_82453CB8:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r8,188(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// stw r7,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r7.u32);
	// addi r7,r8,-7
	ctx.r7.s64 = ctx.r8.s64 + -7;
	// stw r7,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r7.u32);
	// lwz r3,12(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r5,4(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r4,8(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stw r3,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// stw r4,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82453CF8:
	// lwz r11,7368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453ebc
	if (ctx.cr6.eq) goto loc_82453EBC;
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82453D10;
	sub_8245B6A8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82459fa8
	ctx.lr = 0x82453D18;
	sub_82459FA8(ctx, base);
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82453D24;
	sub_8245B6A8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82459fa8
	ctx.lr = 0x82453D2C;
	sub_82459FA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244acd0
	ctx.lr = 0x82453D34;
	sub_8244ACD0(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82453D40;
	sub_8245B6A8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82459fa8
	ctx.lr = 0x82453D48;
	sub_82459FA8(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82453D54;
	sub_8245B6A8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82459fa8
	ctx.lr = 0x82453D5C;
	sub_82459FA8(ctx, base);
	// lwz r10,192(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r9,184(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// li r4,16
	ctx.r4.s64 = 16;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8245b7d8
	ctx.lr = 0x82453D80;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453d90
	if (ctx.cr6.eq) goto loc_82453D90;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8245ba20
	ctx.lr = 0x82453D90;
	sub_8245BA20(ctx, base);
loc_82453D90:
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82453dc0
	if (ctx.cr6.eq) goto loc_82453DC0;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82453dc0
	if (!ctx.cr6.eq) goto loc_82453DC0;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82453dc8
	goto loc_82453DC8;
loc_82453DC0:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82453DC8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82453dec
	if (ctx.cr6.eq) goto loc_82453DEC;
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
	// bne cr6,0x82453df0
	if (!ctx.cr6.eq) goto loc_82453DF0;
loc_82453DEC:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82453DF0:
	// lwz r3,908(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 908);
	// bl 0x8238d760
	ctx.lr = 0x82453DF8;
	sub_8238D760(ctx, base);
	// bl 0x823f4e18
	ctx.lr = 0x82453DFC;
	sub_823F4E18(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b878
	ctx.lr = 0x82453E0C;
	sub_8245B878(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453e20
	if (ctx.cr6.eq) goto loc_82453E20;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// sth r30,1120(r11)
	REX_STORE_U16(ctx.r11.u32 + 1120, ctx.r30.u16);
	// sth r30,1122(r11)
	REX_STORE_U16(ctx.r11.u32 + 1122, ctx.r30.u16);
loc_82453E20:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82447820
	ctx.lr = 0x82453E28;
	sub_82447820(ctx, base);
	// lis r11,-32187
	ctx.r11.s64 = -2109407232;
	// lwz r9,96(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// addi r10,r31,88
	ctx.r10.s64 = ctx.r31.s64 + 88;
	// addi r8,r11,18560
	ctx.r8.s64 = ctx.r11.s64 + 18560;
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// stw r30,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r30.u32);
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// stw r30,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r30.u32);
	// bne cr6,0x82453e80
	if (!ctx.cr6.eq) goto loc_82453E80;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82453e80
	if (!ctx.cr6.eq) goto loc_82453E80;
	// lwz r9,16(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82453e80
	if (!ctx.cr6.eq) goto loc_82453E80;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
loc_82453E80:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r8,188(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// stw r30,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r6,4(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,8(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r4,12(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stw r8,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// stw r5,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// stw r4,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r4.u32);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82453EBC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244b390
	ctx.lr = 0x82453EC4;
	sub_8244B390(ctx, base);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r30,19232
	ctx.r30.s64 = ctx.r30.s64 + 19232;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453EE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x82453EF0;
	sub_8245B6A8(ctx, base);
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// lis r8,-32132
	ctx.r8.s64 = -2105802752;
	// addi r5,r9,3732
	ctx.r5.s64 = ctx.r9.s64 + 3732;
	// addi r6,r8,3700
	ctx.r6.s64 = ctx.r8.s64 + 3700;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x826a0b10
	ctx.lr = 0x82453F0C;
	sub_826A0B10(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82453f4c
	if (ctx.cr6.eq) goto loc_82453F4C;
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,136(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453F30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,68(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 68);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,320
	ctx.r5.s64 = 320;
	// li r6,0
	ctx.r6.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82453F4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82453F4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82449090
	ctx.lr = 0x82453F54;
	sub_82449090(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82453F60:
	// lwz r9,7364(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824541f8
	if (ctx.cr6.eq) goto loc_824541F8;
	// lwzx r9,r31,r24
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// add r28,r31,r24
	ctx.r28.u64 = ctx.r31.u64 + ctx.r24.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824541f8
	if (ctx.cr6.eq) goto loc_824541F8;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r10,r11,6076
	ctx.r10.u64 = ctx.r11.u64 | 6076;
	// lwzx r9,r31,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82453fac
	if (!ctx.cr6.eq) goto loc_82453FAC;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,142
	ctx.r4.s64 = 142;
	// bl 0x82446938
	ctx.lr = 0x82453FA0;
	sub_82446938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82453FAC:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,7360(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 7360);
	// bl 0x82446c20
	ctx.lr = 0x82453FB8;
	sub_82446C20(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b738
	ctx.lr = 0x82453FC8;
	sub_8245B738(ctx, base);
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82453FE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b878
	ctx.lr = 0x82453FF0;
	sub_8245B878(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454010
	if (ctx.cr6.eq) goto loc_82454010;
	// lwz r3,108(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82454010;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82454010:
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r27,2
	ctx.r27.s64 = 2;
loc_8245401C:
	// addi r5,r30,6
	ctx.r5.s64 = ctx.r30.s64 + 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8245b7d8
	ctx.lr = 0x8245402C;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8245406c
	if (ctx.cr6.eq) goto loc_8245406C;
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82454048
	if (!ctx.cr6.eq) goto loc_82454048;
	// stw r21,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r21.u32);
	// b 0x82454064
	goto loc_82454064;
loc_82454048:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82454058
	if (!ctx.cr6.eq) goto loc_82454058;
	// stw r29,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r29.u32);
	// b 0x82454064
	goto loc_82454064;
loc_82454058:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82454064
	if (!ctx.cr6.eq) goto loc_82454064;
	// stw r27,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r27.u32);
loc_82454064:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8245ba20
	ctx.lr = 0x8245406C;
	sub_8245BA20(ctx, base);
loc_8245406C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,15
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 15, ctx.xer);
	// blt cr6,0x8245401c
	if (ctx.cr6.lt) goto loc_8245401C;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82454088;
	sub_8245B738(ctx, base);
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824540A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x824540B0;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824540f0
	if (ctx.cr6.eq) goto loc_824540F0;
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
	ctx.lr = 0x824540D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824540F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824540F0:
	// lwz r11,7412(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7412);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r9,7408(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 7408);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8245b7d8
	ctx.lr = 0x82454114;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454124
	if (ctx.cr6.eq) goto loc_82454124;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8245ba20
	ctx.lr = 0x82454124;
	sub_8245BA20(ctx, base);
loc_82454124:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244a6d8
	ctx.lr = 0x82454130;
	sub_8244A6D8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824455e0
	ctx.lr = 0x8245413C;
	sub_824455E0(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b878
	ctx.lr = 0x8245414C;
	sub_8245B878(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8245416c
	if (ctx.cr6.eq) goto loc_8245416C;
	// lwz r3,108(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8245416C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8245416C:
	// stw r21,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r21.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x8245417C;
	sub_8245B6A8(ctx, base);
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82454194;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b6a8
	ctx.lr = 0x824541A0;
	sub_8245B6A8(ctx, base);
	// lwz r3,96(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824541B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// stw r21,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r21.u32);
	// lis r6,-32187
	ctx.r6.s64 = -2109407232;
	// stw r21,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r21.u32);
	// addi r11,r7,-18886
	ctx.r11.s64 = ctx.r7.s64 + -18886;
	// stw r21,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r21.u32);
	// addi r4,r6,1424
	ctx.r4.s64 = ctx.r6.s64 + 1424;
	// ld r5,120(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// addi r6,r11,-9
	ctx.r6.s64 = ctx.r11.s64 + -9;
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r4,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// ld r4,112(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// bl 0x822518d8
	ctx.lr = 0x824541EC;
	sub_822518D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_824541F8:
	// lwzx r9,r31,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
	// add r23,r31,r11
	ctx.r23.u64 = ctx.r31.u64 + ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82454218
	if (ctx.cr6.eq) goto loc_82454218;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r28,r28,-17516
	ctx.r28.s64 = ctx.r28.s64 + -17516;
	// b 0x82454240
	goto loc_82454240;
loc_82454218:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8245422c
	if (ctx.cr6.eq) goto loc_8245422C;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r28,r28,-21516
	ctx.r28.s64 = ctx.r28.s64 + -21516;
	// b 0x82454240
	goto loc_82454240;
loc_8245422C:
	// lwzx r11,r31,r24
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82454240
	if (ctx.cr6.eq) goto loc_82454240;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r28,r28,-19516
	ctx.r28.s64 = ctx.r28.s64 + -19516;
loc_82454240:
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-14008
	ctx.r30.s64 = ctx.r30.s64 + -14008;
	// addi r29,r29,6064
	ctx.r29.s64 = ctx.r29.s64 + 6064;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r21,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmpwi cr6,r11,180
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 180, ctx.xer);
	// ble cr6,0x82454300
	if (!ctx.cr6.gt) goto loc_82454300;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b7d8
	ctx.lr = 0x82454278;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454298
	if (ctx.cr6.eq) goto loc_82454298;
	// lwz r5,7360(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 7360);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x82454298
	if (!ctx.cr6.gt) goto loc_82454298;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,104(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// bl 0x82444548
	ctx.lr = 0x82454298;
	sub_82444548(ctx, base);
loc_82454298:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,7360(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 7360);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446c20
	ctx.lr = 0x824542A8;
	sub_82446C20(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b738
	ctx.lr = 0x824542B8;
	sub_8245B738(ctx, base);
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824542D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b878
	ctx.lr = 0x824542E0;
	sub_8245B878(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454300
	if (ctx.cr6.eq) goto loc_82454300;
	// lwz r3,108(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82454300;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82454300:
	// lwz r11,7344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7344);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8245431c
	if (ctx.cr6.eq) goto loc_8245431C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244bdc8
	ctx.lr = 0x8245431C;
	sub_8244BDC8(ctx, base);
loc_8245431C:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82454330
	if (ctx.cr6.eq) goto loc_82454330;
	// li r3,2184
	ctx.r3.s64 = 2184;
	// b 0x82454344
	goto loc_82454344;
loc_82454330:
	// lwz r11,7340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7340);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82454350
	if (ctx.cr6.eq) goto loc_82454350;
	// li r3,2332
	ctx.r3.s64 = 2332;
loc_82454344:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8235ce40
	ctx.lr = 0x82454350;
	sub_8235CE40(ctx, base);
loc_82454350:
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8245437c
	if (!ctx.cr6.eq) goto loc_8245437C;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8245437c
	if (!ctx.cr6.eq) goto loc_8245437C;
	// lwz r11,7340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7340);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82454600
	if (ctx.cr6.eq) goto loc_82454600;
loc_8245437C:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b878
	ctx.lr = 0x8245438C;
	sub_8245B878(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824543a0
	if (ctx.cr6.eq) goto loc_824543A0;
	// lwz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// sth r21,1120(r11)
	REX_STORE_U16(ctx.r11.u32 + 1120, ctx.r21.u16);
	// sth r21,1122(r11)
	REX_STORE_U16(ctx.r11.u32 + 1122, ctx.r21.u16);
loc_824543A0:
	// stw r21,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r21.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,7416(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7416);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r28
	ctx.r10.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r27,-4(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + -4);
	// bl 0x8245b7d8
	ctx.lr = 0x824543C4;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824543e4
	if (ctx.cr6.eq) goto loc_824543E4;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x824543fc
	if (!ctx.cr6.gt) goto loc_824543FC;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r3,104(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82444548
	ctx.lr = 0x824543E4;
	sub_82444548(ctx, base);
loc_824543E4:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x824543fc
	if (!ctx.cr6.gt) goto loc_824543FC;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446c20
	ctx.lr = 0x824543FC;
	sub_82446C20(ctx, base);
loc_824543FC:
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// li r26,23
	ctx.r26.s64 = 23;
	// addi r11,r11,23664
	ctx.r11.s64 = ctx.r11.s64 + 23664;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82454428
	if (ctx.cr6.eq) goto loc_82454428;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// beq cr6,0x8245442c
	if (ctx.cr6.eq) goto loc_8245442C;
loc_82454428:
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
loc_8245442C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82454450
	if (ctx.cr6.eq) goto loc_82454450;
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
	// bne cr6,0x82454454
	if (!ctx.cr6.eq) goto loc_82454454;
loc_82454450:
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
loc_82454454:
	// lwz r3,908(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 908);
	// bl 0x8238d760
	ctx.lr = 0x8245445C;
	sub_8238D760(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x823f20d8
	ctx.lr = 0x82454464;
	sub_823F20D8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x824544c4
	if (!ctx.cr6.gt) goto loc_824544C4;
loc_82454474:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823f2050
	ctx.lr = 0x82454480;
	sub_823F2050(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// cmpw cr6,r10,r27
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r27.s32, ctx.xer);
	// bne cr6,0x824544b8
	if (!ctx.cr6.eq) goto loc_824544B8;
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x824544a4
	if (!ctx.cr6.eq) goto loc_824544A4;
	// li r26,23
	ctx.r26.s64 = 23;
	// b 0x824544b8
	goto loc_824544B8;
loc_824544A4:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd830
	ctx.lr = 0x824544AC;
	sub_821FD830(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821fd4c8
	ctx.lr = 0x824544B4;
	sub_821FD4C8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_824544B8:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r30,r28
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x82454474
	if (ctx.cr6.lt) goto loc_82454474;
loc_824544C4:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b878
	ctx.lr = 0x824544D4;
	sub_8245B878(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824545b0
	if (ctx.cr6.eq) goto loc_824545B0;
	// li r6,350
	ctx.r6.s64 = 350;
	// lwz r3,108(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// li r5,65
	ctx.r5.s64 = 65;
	// li r4,190
	ctx.r4.s64 = 190;
	// bl 0x82369c08
	ctx.lr = 0x824544F4;
	sub_82369C08(ctx, base);
	// lwz r10,108(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// lis r11,-32247
	ctx.r11.s64 = -2113339392;
	// addi r11,r11,-18886
	ctx.r11.s64 = ctx.r11.s64 + -18886;
	// sth r21,1120(r10)
	REX_STORE_U16(ctx.r10.u32 + 1120, ctx.r21.u16);
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// sth r21,1122(r10)
	REX_STORE_U16(ctx.r10.u32 + 1122, ctx.r21.u16);
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// bl 0x82368998
	ctx.lr = 0x82454514;
	sub_82368998(ctx, base);
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8245452C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r26,23
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 23, ctx.xer);
	// beq cr6,0x824545b0
	if (ctx.cr6.eq) goto loc_824545B0;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// addi r9,r9,10240
	ctx.r9.s64 = ctx.r9.s64 + 10240;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x824545b0
	if (!ctx.cr6.gt) goto loc_824545B0;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
loc_82454554:
	// addic. r8,r11,-256
	ctx.xer.ca = ctx.r11.u32 > 255;
	ctx.r8.s64 = ctx.r11.s64 + -256;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82454568
	if (ctx.cr0.eq) goto loc_82454568;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r8,r26
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r26.s32, ctx.xer);
	// beq cr6,0x82454580
	if (ctx.cr6.eq) goto loc_82454580;
loc_82454568:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,260
	ctx.r11.s64 = ctx.r11.s64 + 260;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x82454554
	if (ctx.cr6.lt) goto loc_82454554;
	// b 0x824545b0
	goto loc_824545B0;
loc_82454580:
	// mulli r11,r10,260
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(260));
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addis r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 65536;
	// addi r4,r4,-4336
	ctx.r4.s64 = ctx.r4.s64 + -4336;
	// bl 0x82368998
	ctx.lr = 0x82454598;
	sub_82368998(ctx, base);
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,96(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824545B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824545B0:
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x824545C0;
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
	ctx.lr = 0x824545D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x824545E8;
	sub_8245B738(ctx, base);
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,100(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82454600;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82454600:
	// lwz r11,7364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7364);
	// lwz r28,7408(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 7408);
	// lwz r29,7412(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 7412);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245470c
	if (ctx.cr6.eq) goto loc_8245470C;
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82454690
	if (ctx.cr6.eq) goto loc_82454690;
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82454648
	if (!ctx.cr6.eq) goto loc_82454648;
	// li r4,189
	ctx.r4.s64 = 189;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x8245463C;
	sub_82446938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82454648:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8245466c
	if (!ctx.cr6.eq) goto loc_8245466C;
	// li r4,190
	ctx.r4.s64 = 190;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x82454660;
	sub_82446938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8245466C:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82454874
	if (!ctx.cr6.eq) goto loc_82454874;
	// li r4,192
	ctx.r4.s64 = 192;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x82454684;
	sub_82446938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_82454690:
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245470c
	if (ctx.cr6.eq) goto loc_8245470C;
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x824546c4
	if (!ctx.cr6.eq) goto loc_824546C4;
	// li r4,194
	ctx.r4.s64 = 194;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x824546B8;
	sub_82446938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_824546C4:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x824546e8
	if (!ctx.cr6.eq) goto loc_824546E8;
	// li r4,195
	ctx.r4.s64 = 195;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x824546DC;
	sub_82446938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_824546E8:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82454874
	if (!ctx.cr6.eq) goto loc_82454874;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82446938
	ctx.lr = 0x82454700;
	sub_82446938(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8245470C:
	// lwz r11,7368(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82454874
	if (ctx.cr6.eq) goto loc_82454874;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x82454728;
	sub_8245B738(ctx, base);
	// lwz r3,100(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82454740;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// li r27,2
	ctx.r27.s64 = 2;
loc_82454748:
	// addi r5,r30,6
	ctx.r5.s64 = ctx.r30.s64 + 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8245b7d8
	ctx.lr = 0x82454758;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454798
	if (ctx.cr6.eq) goto loc_82454798;
	// lwz r11,7380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 7380);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82454774
	if (!ctx.cr6.eq) goto loc_82454774;
	// stw r21,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r21.u32);
	// b 0x82454790
	goto loc_82454790;
loc_82454774:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82454784
	if (!ctx.cr6.eq) goto loc_82454784;
	// stw r25,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r25.u32);
	// b 0x82454790
	goto loc_82454790;
loc_82454784:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82454790
	if (!ctx.cr6.eq) goto loc_82454790;
	// stw r27,88(r3)
	REX_STORE_U32(ctx.r3.u32 + 88, ctx.r27.u32);
loc_82454790:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8245ba20
	ctx.lr = 0x82454798;
	sub_8245BA20(ctx, base);
loc_82454798:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,15
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 15, ctx.xer);
	// blt cr6,0x82454748
	if (ctx.cr6.lt) goto loc_82454748;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8245b738
	ctx.lr = 0x824547B4;
	sub_8245B738(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824547f4
	if (ctx.cr6.eq) goto loc_824547F4;
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
	ctx.lr = 0x824547D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,100(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824547F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824547F4:
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r4,16
	ctx.r4.s64 = 16;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x8245b7d8
	ctx.lr = 0x82454810;
	sub_8245B7D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454820
	if (ctx.cr6.eq) goto loc_82454820;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8245ba20
	ctx.lr = 0x82454820;
	sub_8245BA20(ctx, base);
loc_82454820:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244a6d8
	ctx.lr = 0x8245482C;
	sub_8244A6D8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824455e0
	ctx.lr = 0x82454838;
	sub_824455E0(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,120(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8245b878
	ctx.lr = 0x82454848;
	sub_8245B878(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82454868
	if (ctx.cr6.eq) goto loc_82454868;
	// lwz r3,108(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82454868;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82454868:
	// stw r21,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r21.u32);
	// stwx r21,r31,r24
	REX_STORE_U32(ctx.r31.u32 + ctx.r24.u32, ctx.r21.u32);
	// stw r21,0(r23)
	REX_STORE_U32(ctx.r23.u32 + 0, ctx.r21.u32);
loc_82454874:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255B178) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0284
	ctx.lr = 0x8255B180;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8255b30c
	if (ctx.cr6.eq) goto loc_8255B30C;
	// addi r4,r4,40
	ctx.r4.s64 = ctx.r4.s64 + 40;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82551380
	ctx.lr = 0x8255B1A8;
	sub_82551380(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8255b1e8
	if (ctx.cr6.eq) goto loc_8255B1E8;
	// addi r3,r30,356
	ctx.r3.s64 = ctx.r30.s64 + 356;
	// bl 0x825527c8
	ctx.lr = 0x8255B1BC;
	sub_825527C8(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r3.u32);
	// beq cr6,0x8255b594
	if (ctx.cr6.eq) goto loc_8255B594;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B1DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_8255B1E8:
	// addi r4,r30,56
	ctx.r4.s64 = ctx.r30.s64 + 56;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82551380
	ctx.lr = 0x8255B1F4;
	sub_82551380(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8255b218
	if (ctx.cr6.eq) goto loc_8255B218;
	// addi r4,r30,308
	ctx.r4.s64 = ctx.r30.s64 + 308;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825502a8
	ctx.lr = 0x8255B20C;
	sub_825502A8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_8255B218:
	// addi r4,r30,72
	ctx.r4.s64 = ctx.r30.s64 + 72;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82551380
	ctx.lr = 0x8255B224;
	sub_82551380(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8255b2c4
	if (!ctx.cr6.eq) goto loc_8255B2C4;
	// addi r4,r30,88
	ctx.r4.s64 = ctx.r30.s64 + 88;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82551380
	ctx.lr = 0x8255B23C;
	sub_82551380(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8255b2c4
	if (!ctx.cr6.eq) goto loc_8255B2C4;
	// addi r4,r30,104
	ctx.r4.s64 = ctx.r30.s64 + 104;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82551380
	ctx.lr = 0x8255B254;
	sub_82551380(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8255b2dc
	if (ctx.cr6.eq) goto loc_8255B2DC;
	// lis r11,-32128
	ctx.r11.s64 = -2105540608;
	// lwz r3,308(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 308);
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r6,r11,9696
	ctx.r6.s64 = ctx.r11.s64 + 9696;
	// addi r5,r10,9136
	ctx.r5.s64 = ctx.r10.s64 + 9136;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826a0b10
	ctx.lr = 0x8255B280;
	sub_826A0B10(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8255B290;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x8255b2c4
	if (ctx.cr6.eq) goto loc_8255B2C4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,384
	ctx.r3.s64 = ctx.r30.s64 + 384;
	// bl 0x82558380
	ctx.lr = 0x8255B2AC;
	sub_82558380(ctx, base);
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825502a8
	ctx.lr = 0x8255B2B8;
	sub_825502A8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_8255B2C4:
	// addi r4,r30,304
	ctx.r4.s64 = ctx.r30.s64 + 304;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825502a8
	ctx.lr = 0x8255B2D0;
	sub_825502A8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_8255B2DC:
	// addi r4,r30,120
	ctx.r4.s64 = ctx.r30.s64 + 120;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82551380
	ctx.lr = 0x8255B2E8;
	sub_82551380(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8255b30c
	if (ctx.cr6.eq) goto loc_8255B30C;
	// addi r4,r30,296
	ctx.r4.s64 = ctx.r30.s64 + 296;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825502a8
	ctx.lr = 0x8255B300;
	sub_825502A8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_8255B30C:
	// lwz r10,376(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 376);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r9,356(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 356);
	// addi r11,r30,356
	ctx.r11.s64 = ctx.r30.s64 + 356;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// ld r7,96(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lwz r23,0(r10)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r27,96(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_8255B344:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8255b354
	if (ctx.cr6.eq) goto loc_8255B354;
	// cmplw cr6,r27,r24
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x8255b358
	if (ctx.cr6.eq) goto loc_8255B358;
loc_8255B354:
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255B358:
	// cmplw cr6,r28,r23
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x8255b484
	if (ctx.cr6.eq) goto loc_8255B484;
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// bne cr6,0x8255b374
	if (!ctx.cr6.eq) goto loc_8255B374;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255B374:
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r9,4(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8255b38c
	if (ctx.cr6.eq) goto loc_8255B38C;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8255b390
	goto loc_8255B390;
loc_8255B38C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8255B390:
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8255b3a0
	if (!ctx.cr6.eq) goto loc_8255B3A0;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255B3A0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8255b44c
	if (!ctx.cr6.eq) goto loc_8255B44C;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// li r11,0
	ctx.r11.s64 = 0;
loc_8255B3B0:
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8255b3c0
	if (!ctx.cr6.eq) goto loc_8255B3C0;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255B3C0:
	// lwz r4,8(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B3DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r9,r3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8255b418
	if (ctx.cr6.eq) goto loc_8255B418;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x8255B3F4;
	sub_8254B160(ctx, base);
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// beq cr6,0x8255b418
	if (ctx.cr6.eq) goto loc_8255B418;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B418;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8255B418:
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x8254b160
	ctx.lr = 0x8255B420;
	sub_8254B160(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8255b46c
	if (!ctx.cr6.eq) goto loc_8255B46C;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8255b434
	if (!ctx.cr6.eq) goto loc_8255B434;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
loc_8255B434:
	// lwz r28,4(r28)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stw r28,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// beq cr6,0x8255b454
	if (ctx.cr6.eq) goto loc_8255B454;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// b 0x8255b458
	goto loc_8255B458;
loc_8255B44C:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8255b3b0
	goto loc_8255B3B0;
loc_8255B454:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8255B458:
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8255b344
	if (!ctx.cr6.eq) goto loc_8255B344;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// b 0x8255b344
	goto loc_8255B344;
loc_8255B46C:
	// stw r29,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r29.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// b 0x8255b588
	goto loc_8255B588;
loc_8255B484:
	// lwz r4,308(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 308);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B4A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r9,r3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8255b4dc
	if (ctx.cr6.eq) goto loc_8255B4DC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x8255B4B8;
	sub_8254B160(ctx, base);
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// beq cr6,0x8255b4dc
	if (ctx.cr6.eq) goto loc_8255B4DC;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B4DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8255B4DC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8254b160
	ctx.lr = 0x8255B4E4;
	sub_8254B160(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8255b46c
	if (!ctx.cr6.eq) goto loc_8255B46C;
	// lwz r4,296(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 296);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B508;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r9,r3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8255b544
	if (ctx.cr6.eq) goto loc_8255B544;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x8255B520;
	sub_8254B160(ctx, base);
	// lwz r29,0(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// beq cr6,0x8255b544
	if (ctx.cr6.eq) goto loc_8255B544;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B544;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8255B544:
	// addi r3,r1,92
	ctx.r3.s64 = ctx.r1.s64 + 92;
	// bl 0x8254b160
	ctx.lr = 0x8255B54C;
	sub_8254B160(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8255b46c
	if (!ctx.cr6.eq) goto loc_8255B46C;
	// lis r9,-32050
	ctx.r9.s64 = -2100428800;
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// addi r3,r9,9600
	ctx.r3.s64 = ctx.r9.s64 + 9600;
	// addi r11,r11,-4652
	ctx.r11.s64 = ctx.r11.s64 + -4652;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,9600(r9)
	REX_STORE_U32(ctx.r9.u32 + 9600, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r3,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r3.u32);
	// lwz r11,9600(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 9600);
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8255B588:
	// bctrl 
	ctx.lr = 0x8255B58C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254b160
	ctx.lr = 0x8255B594;
	sub_8254B160(ctx, base);
loc_8255B594:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82570518) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r8,8
	ctx.r8.s64 = 8;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r10,r3,92
	ctx.r10.s64 = ctx.r3.s64 + 92;
	// addi r11,r4,-4
	ctx.r11.s64 = ctx.r4.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8257052C:
	// lwzu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r8.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8257052c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8257052C;
	// lwz r11,128(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 128);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,128(r9)
	REX_STORE_U32(ctx.r9.u32 + 128, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825717A8) {
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
	// cmpwi cr6,r3,255
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 255, ctx.xer);
	// bne cr6,0x82571804
	if (!ctx.cr6.eq) goto loc_82571804;
	// lis r11,-32050
	ctx.r11.s64 = -2100428800;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r11,11336
	ctx.r30.s64 = ctx.r11.s64 + 11336;
	// addi r4,r30,20
	ctx.r4.s64 = ctx.r30.s64 + 20;
loc_825717D4:
	// lbz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825717e8
	if (ctx.cr6.eq) goto loc_825717E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82571160
	ctx.lr = 0x825717E8;
	sub_82571160(ctx, base);
loc_825717E8:
	// addi r4,r4,64
	ctx.r4.s64 = ctx.r4.s64 + 64;
	// addi r11,r30,4372
	ctx.r11.s64 = ctx.r30.s64 + 4372;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x825717d4
	if (ctx.cr6.lt) goto loc_825717D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82571808
	goto loc_82571808;
loc_82571804:
	// bl 0x82571160
	ctx.lr = 0x82571808;
	sub_82571160(ctx, base);
loc_82571808:
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

DEFINE_REX_FUNC(sub_82573860) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32050
	ctx.r10.s64 = -2100428800;
	// lis r9,1686
	ctx.r9.s64 = 110493696;
	// ori r8,r9,21549
	ctx.r8.u64 = ctx.r9.u64 | 21549;
	// lwz r11,19356(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 19356);
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,19356(r10)
	REX_STORE_U32(ctx.r10.u32 + 19356, ctx.r11.u32);
	// lhz r11,19356(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 19356);
	// clrlwi r3,r11,17
	ctx.r3.u64 = ctx.r11.u32 & 0x7FFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825755A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0284
	ctx.lr = 0x825755B0;
	__savegprlr_23(ctx, base);
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r25,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// lfs f30,2880(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f30.f64 = double(temp.f32);
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// lfs f31,2884(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2884);
	ctx.f31.f64 = double(temp.f32);
	// mr r23,r25
	ctx.r23.u64 = ctx.r25.u64;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fcmpu cr6,f1,f30
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// stfs f30,84(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f30,92(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bge cr6,0x8257561c
	if (!ctx.cr6.lt) goto loc_8257561C;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,24
	ctx.r3.u64 = ctx.r3.u64 | 24;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// lfd f30,-96(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_8257561C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8257563c
	if (!ctx.cr6.eq) goto loc_8257563C;
loc_82575624:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,18
	ctx.r3.u64 = ctx.r3.u64 | 18;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_8257563C:
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// stfs f3,92(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82574618
	ctx.lr = 0x8257565C;
	sub_82574618(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82574698
	ctx.lr = 0x8257566C;
	sub_82574698(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,7248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 7248);
	// bl 0x8257d520
	ctx.lr = 0x8257567C;
	sub_8257D520(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lwz r3,7248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 7248);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8257d5f0
	ctx.lr = 0x82575690;
	sub_8257D5F0(ctx, base);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// ori r24,r11,4352
	ctx.r24.u64 = ctx.r11.u64 | 4352;
loc_825756A0:
	// lwz r3,7228(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 7228);
	// lwzx r11,r28,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r3.u32);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82575768
	if (!ctx.cr6.eq) goto loc_82575768;
	// stfs f31,452(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stw r25,460(r1)
	REX_STORE_U32(ctx.r1.u32 + 460, ctx.r25.u32);
	// stfs f30,456(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f30,464(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stfs f31,468(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// stfs f31,472(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// bl 0x82577ab8
	ctx.lr = 0x825756D4;
	sub_82577AB8(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82575738
	if (ctx.cr6.eq) goto loc_82575738;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82575738
	if (ctx.cr6.eq) goto loc_82575738;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,7228(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 7228);
	// bl 0x825779e0
	ctx.lr = 0x825756F0;
	sub_825779E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825757a8
	if (ctx.cr6.eq) goto loc_825757A8;
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// lfs f3,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f3.f64 = double(temp.f32);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lfs f1,20(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,172(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
	// lwz r6,36(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lfs f2,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82572778
	ctx.lr = 0x82575720;
	sub_82572778(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825757bc
	if (!ctx.cr6.eq) goto loc_825757BC;
	// addi r3,r1,196
	ctx.r3.s64 = ctx.r1.s64 + 196;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// li r5,176
	ctx.r5.s64 = 176;
	// bl 0x826a1130
	ctx.lr = 0x82575738;
	rexcrt_memcpy(ctx, base);
loc_82575738:
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r11,r1,76
	ctx.r11.s64 = ctx.r1.s64 + 76;
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82575748:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82575748
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82575748;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r3,7228(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 7228);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82577a58
	ctx.lr = 0x82575764;
	sub_82577A58(ctx, base);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
loc_82575768:
	// addi r28,r28,364
	ctx.r28.s64 = ctx.r28.s64 + 364;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r28,r24
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r24.s32, ctx.xer);
	// blt cr6,0x825756a0
	if (ctx.cr6.lt) goto loc_825756A0;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bne cr6,0x82575794
	if (!ctx.cr6.eq) goto loc_82575794;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,7248(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 7248);
	// bl 0x8257d670
	ctx.lr = 0x8257578C;
	sub_8257D670(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82575624
	if (ctx.cr6.eq) goto loc_82575624;
loc_82575794:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_825757A8:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
loc_825757BC:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,45
	ctx.r3.u64 = ctx.r3.u64 | 45;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x826a02d4
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82585578) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82585580;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8258559C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825855c8
	if (ctx.cr6.lt) goto loc_825855C8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x824d9440
	ctx.lr = 0x825855B0;
	sub_824D9440(ctx, base);
	// stw r29,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82584f68
	ctx.lr = 0x825855BC;
	sub_82584F68(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x825855dc
	if (!ctx.cr6.lt) goto loc_825855DC;
loc_825855C8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825855DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825855DC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82587EB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x82587EC0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82587EDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82587f90
	if (ctx.cr6.lt) goto loc_82587F90;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r10,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// lwz r9,20(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r9,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82587f10
	if (ctx.cr6.eq) goto loc_82587F10;
	// stw r11,660(r31)
	REX_STORE_U32(ctx.r31.u32 + 660, ctx.r11.u32);
loc_82587F10:
	// lis r4,8332
	ctx.r4.s64 = 546045952;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// ori r4,r4,32791
	ctx.r4.u64 = ctx.r4.u64 | 32791;
	// bl 0x824c64b8
	ctx.lr = 0x82587F20;
	sub_824C64B8(ctx, base);
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82587f38
	if (!ctx.cr6.eq) goto loc_82587F38;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x82587f90
	goto loc_82587F90;
loc_82587F38:
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82587f5c
	if (ctx.cr6.eq) goto loc_82587F5C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82587F58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82587F5C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82587f90
	if (ctx.cr6.lt) goto loc_82587F90;
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82587f88
	if (ctx.cr6.eq) goto loc_82587F88;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82587F84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82587F88:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x82587fa4
	if (!ctx.cr6.lt) goto loc_82587FA4;
loc_82587F90:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82587FA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82587FA4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8258E8E8) {
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
	// lis r11,-32246
	ctx.r11.s64 = -2113273856;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,5272
	ctx.r10.s64 = ctx.r11.s64 + 5272;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x82597e08
	ctx.lr = 0x8258E914;
	sub_82597E08(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8258e934
	if (ctx.cr6.eq) goto loc_8258E934;
	// lis r4,8332
	ctx.r4.s64 = 546045952;
	// ori r4,r4,32824
	ctx.r4.u64 = ctx.r4.u64 | 32824;
	// bl 0x824c6550
	ctx.lr = 0x8258E930;
	sub_824C6550(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8258E934:
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

DEFINE_REX_FUNC(sub_82591668) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82592220) {
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
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8259225c
	if (ctx.cr6.eq) goto loc_8259225C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8259225C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8259225C:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
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

DEFINE_REX_FUNC(sub_82595318) {
	REX_FUNC_PROLOGUE();
	// lis r4,8332
	ctx.r4.s64 = 546045952;
	// ori r4,r4,32770
	ctx.r4.u64 = ctx.r4.u64 | 32770;
	// b 0x824c64b8
	sub_824C64B8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82595430) {
	REX_FUNC_PROLOGUE();
	// lwz r3,52(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82595470) {
	REX_FUNC_PROLOGUE();
	// ld r3,64(r3)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r3.u32 + 64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82595968) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0288
	ctx.lr = 0x82595970;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	ctx.r31.s64 = 0;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// stw r31,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x825957d0
	ctx.lr = 0x825959BC;
	sub_825957D0(ctx, base);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x82595a00
	if (ctx.cr6.eq) goto loc_82595A00;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r25,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stw r31,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r31,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825957d0
	ctx.lr = 0x82595A00;
	sub_825957D0(ctx, base);
loc_82595A00:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02d8
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82599348) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a027c
	ctx.lr = 0x82599350;
	__savegprlr_21(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// ld r29,0(r3)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// clrldi r11,r4,32
	ctx.r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwz r10,204(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// li r21,0
	ctx.r21.s64 = 0;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// stw r21,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r21.u32);
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r23,r11,-24
	ctx.r23.s64 = ctx.r11.s64 + -24;
	// bne cr6,0x82599400
	if (!ctx.cr6.eq) goto loc_82599400;
	// lis r11,9356
	ctx.r11.s64 = 613154816;
	// li r3,32
	ctx.r3.s64 = 32;
	// ori r22,r11,32768
	ctx.r22.u64 = ctx.r11.u64 | 32768;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// bl 0x824c64b8
	ctx.lr = 0x82599394;
	sub_824C64B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r3,204(r26)
	REX_STORE_U32(ctx.r26.u32 + 204, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82599410
	if (!ctx.cr6.eq) goto loc_82599410;
	// li r30,5
	ctx.r30.s64 = 5;
loc_825993A8:
	// lwz r31,204(r26)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r26.u32 + 204);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82599400
	if (ctx.cr6.eq) goto loc_82599400;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x824c6550
	ctx.lr = 0x825993C0;
	sub_824C6550(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x824c6550
	ctx.lr = 0x825993CC;
	sub_824C6550(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x824c6550
	ctx.lr = 0x825993D8;
	sub_824C6550(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x824c6550
	ctx.lr = 0x825993E4;
	sub_824C6550(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x824c6550
	ctx.lr = 0x825993F0;
	sub_824C6550(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// lwz r3,204(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 204);
	// bl 0x824c6550
	ctx.lr = 0x825993FC;
	sub_824C6550(ctx, base);
	// stw r21,204(r26)
	REX_STORE_U32(ctx.r26.u32 + 204, ctx.r21.u32);
loc_82599400:
	// std r23,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.r23.u64);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02cc
	__restgprlr_21(ctx, base);
	return;
loc_82599410:
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// mr r9,r21
	ctx.r9.u64 = ctx.r21.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82599420:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82599420
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82599420;
	// addi r30,r29,10
	ctx.r30.s64 = ctx.r29.s64 + 10;
	// cmpld cr6,r30,r23
	ctx.cr6.compare<uint64_t>(ctx.r30.u64, ctx.r23.u64, ctx.xer);
	// ble cr6,0x8259943c
	if (!ctx.cr6.gt) goto loc_8259943C;
	// li r30,6
	ctx.r30.s64 = 6;
	// b 0x825993a8
	goto loc_825993A8;
loc_8259943C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82588bc0
	ctx.lr = 0x82599450;
	sub_82588BC0(ctx, base);
	// cmplwi cr6,r3,10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 10, ctx.xer);
	// beq cr6,0x82599460
	if (ctx.cr6.eq) goto loc_82599460;
	// li r30,3
	ctx.r30.s64 = 3;
	// b 0x825993a8
	goto loc_825993A8;
loc_82599460:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r29,r31,12
	ctx.r29.s64 = ctx.r31.s64 + 12;
	// std r30,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r30.u64);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 2;
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// addi r27,r31,4
	ctx.r27.s64 = ctx.r31.s64 + 4;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r25,r31,6
	ctx.r25.s64 = ctx.r31.s64 + 6;
	// sth r9,0(r31)
	REX_STORE_U16(ctx.r31.u32 + 0, ctx.r9.u16);
	// addi r24,r31,8
	ctx.r24.s64 = ctx.r31.s64 + 8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,2(r31)
	REX_STORE_U16(ctx.r31.u32 + 2, ctx.r9.u16);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,4(r31)
	REX_STORE_U16(ctx.r31.u32 + 4, ctx.r9.u16);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,6(r31)
	REX_STORE_U16(ctx.r31.u32 + 6, ctx.r9.u16);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rotlwi r10,r10,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// sth r9,8(r31)
	REX_STORE_U16(ctx.r31.u32 + 8, ctx.r9.u16);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82597ee0
	ctx.lr = 0x82599534;
	sub_82597EE0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825993a8
	if (!ctx.cr6.eq) goto loc_825993A8;
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82599570
	if (ctx.cr6.eq) goto loc_82599570;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_8259955C:
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8259955c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8259955C;
loc_82599570:
	// addi r29,r31,16
	ctx.r29.s64 = ctx.r31.s64 + 16;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82597ee0
	ctx.lr = 0x8259958C;
	sub_82597EE0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825993a8
	if (!ctx.cr6.eq) goto loc_825993A8;
	// lhz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r28.u32 + 0);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825995c8
	if (ctx.cr6.eq) goto loc_825995C8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_825995B4:
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x825995b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825995B4;
loc_825995C8:
	// addi r29,r31,20
	ctx.r29.s64 = ctx.r31.s64 + 20;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82597ee0
	ctx.lr = 0x825995E4;
	sub_82597EE0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825993a8
	if (!ctx.cr6.eq) goto loc_825993A8;
	// lhz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 0);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82599620
	if (ctx.cr6.eq) goto loc_82599620;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_8259960C:
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8259960c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8259960C;
loc_82599620:
	// addi r29,r31,24
	ctx.r29.s64 = ctx.r31.s64 + 24;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82597ee0
	ctx.lr = 0x8259963C;
	sub_82597EE0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825993a8
	if (!ctx.cr6.eq) goto loc_825993A8;
	// lhz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r25.u32 + 0);
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82599678
	if (ctx.cr6.eq) goto loc_82599678;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_82599664:
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x82599664
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82599664;
loc_82599678:
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82597ee0
	ctx.lr = 0x82599694;
	sub_82597EE0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825993a8
	if (!ctx.cr6.eq) goto loc_825993A8;
	// lhz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82599400
	if (ctx.cr6.eq) goto loc_82599400;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_825996BC:
	// lbz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// stb r10,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r10.u8);
	// stbu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x825996bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825996BC;
	// std r23,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.r23.u64);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02cc
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B1398) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x825B13A0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lis r3,-32688
	ctx.r3.s64 = -2142240768;
	// lis r9,-32688
	ctx.r9.s64 = -2142240768;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// ori r27,r9,3
	ctx.r27.u64 = ctx.r9.u64 | 3;
	// addi r30,r10,-25524
	ctx.r30.s64 = ctx.r10.s64 + -25524;
loc_825B13C8:
	// extsb r31,r11
	ctx.r31.s64 = ctx.r11.s8;
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825b1404
	if (ctx.cr6.eq) goto loc_825B1404;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825B13F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x825b1418
	if (!ctx.cr6.lt) goto loc_825B1418;
	// cmplw cr6,r3,r27
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x825b1418
	if (!ctx.cr6.eq) goto loc_825B1418;
loc_825B1404:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// blt cr6,0x825b13c8
	if (ctx.cr6.lt) goto loc_825B13C8;
loc_825B1418:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825B3610) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// li r10,1
	ctx.r10.s64 = 1;
	// std r11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r11,110(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 110);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// slw r7,r10,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// std r6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// stfsx f8,r9,r4
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r4.u32, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B5C40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0270
	ctx.lr = 0x825B5C48;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// ble cr6,0x825b5d7c
	if (!ctx.cr6.gt) goto loc_825B5D7C;
	// addi r19,r5,-1
	ctx.r19.s64 = ctx.r5.s64 + -1;
	// li r23,0
	ctx.r23.s64 = 0;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// ble cr6,0x825b5d7c
	if (!ctx.cr6.gt) goto loc_825B5D7C;
	// mullw r11,r19,r6
	ctx.r11.s64 = int64_t(ctx.r19.s32) * int64_t(ctx.r6.s32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// add r26,r11,r4
	ctx.r26.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lis r11,-32245
	ctx.r11.s64 = -2113208320;
	// rlwinm r24,r5,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r6,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r22,r10,-6784
	ctx.r22.s64 = ctx.r10.s64 + -6784;
	// addi r21,r11,-7040
	ctx.r21.s64 = ctx.r11.s64 + -7040;
loc_825B5C9C:
	// lbzx r11,r23,r20
	ctx.r11.u64 = REX_LOAD_U8(ctx.r23.u32 + ctx.r20.u32);
	// addi r10,r21,128
	ctx.r10.s64 = ctx.r21.s64 + 128;
	// addi r9,r22,128
	ctx.r9.s64 = ctx.r22.s64 + 128;
	// extsb r8,r11
	ctx.r8.s64 = ctx.r11.s8;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwzx r30,r7,r10
	ctx.r30.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwzx r31,r7,r9
	ctx.r31.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// bl 0x826a1130
	ctx.lr = 0x825B5CC8;
	rexcrt_memcpy(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x826a1130
	ctx.lr = 0x825B5CD8;
	rexcrt_memcpy(ctx, base);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x825b5d6c
	if (!ctx.cr6.gt) goto loc_825B5D6C;
	// neg r11,r31
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r31.u64);
	// mtctr r28
	ctx.ctr.u64 = ctx.r28.u64;
	// extsw r4,r31
	ctx.r4.s64 = ctx.r31.s32;
	// extsw r3,r11
	ctx.r3.s64 = ctx.r11.s32;
	// extsw r8,r30
	ctx.r8.s64 = ctx.r30.s32;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// addi r9,r26,-4
	ctx.r9.s64 = ctx.r26.s64 + -4;
	// addi r10,r29,-4
	ctx.r10.s64 = ctx.r29.s64 + -4;
	// subf r7,r27,r25
	ctx.r7.u64 = ctx.r25.u64 - ctx.r27.u64;
loc_825B5D04:
	// lwzx r6,r7,r11
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// extsw r5,r5
	ctx.r5.s64 = ctx.r5.s32;
	// mulld r6,r6,r8
	ctx.r6.s64 = static_cast<int64_t>(ctx.r6.u64 * ctx.r8.u64);
	// mulld r5,r5,r4
	ctx.r5.s64 = static_cast<int64_t>(ctx.r5.u64 * ctx.r4.u64);
	// sradi r6,r6,30
	ctx.xer.ca = (ctx.r6.s64 < 0) & ((ctx.r6.u64 & 0x3FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s64 >> 30;
	// sradi r5,r5,30
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0x3FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s64 >> 30;
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// extsw r5,r5
	ctx.r5.s64 = ctx.r5.s32;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// stwu r6,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r10.u32 = ea;
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwzx r5,r7,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// extsw r5,r5
	ctx.r5.s64 = ctx.r5.s32;
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// mulld r5,r5,r3
	ctx.r5.s64 = static_cast<int64_t>(ctx.r5.u64 * ctx.r3.u64);
	// mulld r6,r6,r8
	ctx.r6.s64 = static_cast<int64_t>(ctx.r6.u64 * ctx.r8.u64);
	// sradi r5,r5,30
	ctx.xer.ca = (ctx.r5.s64 < 0) & ((ctx.r5.u64 & 0x3FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s64 >> 30;
	// sradi r31,r6,30
	ctx.xer.ca = (ctx.r6.s64 < 0) & ((ctx.r6.u64 & 0x3FFFFFFF) != 0);
	ctx.r31.s64 = ctx.r6.s64 >> 30;
	// extsw r6,r5
	ctx.r6.s64 = ctx.r5.s32;
	// extsw r5,r31
	ctx.r5.s64 = ctx.r31.s32;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// stwu r6,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r6.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x825b5d04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825B5D04;
loc_825B5D6C:
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// add r29,r18,r29
	ctx.r29.u64 = ctx.r18.u64 + ctx.r29.u64;
	// cmpw cr6,r23,r19
	ctx.cr6.compare<int32_t>(ctx.r23.s32, ctx.r19.s32, ctx.xer);
	// blt cr6,0x825b5c9c
	if (ctx.cr6.lt) goto loc_825B5C9C;
loc_825B5D7C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02c0
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C3C38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x825C3C40;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,36(r4)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r4.u32 + 36);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// srawi r11,r24,8
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r24.s32 >> 8;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r11,-32245
	ctx.r11.s64 = -2113208320;
	// addi r29,r3,224
	ctx.r29.s64 = ctx.r3.s64 + 224;
	// mr r14,r4
	ctx.r14.u64 = ctx.r4.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// addi r31,r25,516
	ctx.r31.s64 = ctx.r25.s64 + 516;
	// li r16,2
	ctx.r16.s64 = 2;
	// li r23,5
	ctx.r23.s64 = 5;
	// lis r26,-32245
	ctx.r26.s64 = -2113208320;
	// li r15,3
	ctx.r15.s64 = 3;
	// lis r18,-32245
	ctx.r18.s64 = -2113208320;
	// lis r19,-32245
	ctx.r19.s64 = -2113208320;
	// addi r22,r10,-5504
	ctx.r22.s64 = ctx.r10.s64 + -5504;
	// addi r27,r9,-760
	ctx.r27.s64 = ctx.r9.s64 + -760;
	// addi r21,r8,-6048
	ctx.r21.s64 = ctx.r8.s64 + -6048;
	// addi r28,r7,-1016
	ctx.r28.s64 = ctx.r7.s64 + -1016;
	// addi r20,r11,-6528
	ctx.r20.s64 = ctx.r11.s64 + -6528;
loc_825C3CB0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// bgt cr6,0x825c3cb0
	if (ctx.cr6.gt) goto loc_825C3CB0;
	// lis r12,-32164
	ctx.r12.s64 = -2107899904;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,15576
	ctx.r12.s64 = ctx.r12.s64 + 15576;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_825C3D14;
	case 1:
		goto loc_825C3DF0;
	case 2:
		goto loc_825C3E8C;
	case 3:
		goto loc_825C3F08;
	case 4:
		goto loc_825C3F68;
	case 5:
		goto loc_825C3CB0;
	case 6:
		goto loc_825C3CB0;
	case 7:
		goto loc_825C3CB0;
	case 8:
		goto loc_825C3CB0;
	case 9:
		goto loc_825C3CB0;
	case 10:
		goto loc_825C3CB0;
	case 11:
		goto loc_825C3CB0;
	case 12:
		goto loc_825C3CB0;
	case 13:
		goto loc_825C4030;
	case 14:
		goto loc_825C419C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_825C3D14:
	// stw r17,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r17.u32);
	// lwz r11,592(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 592);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825c3d34
	if (ctx.cr6.eq) goto loc_825C3D34;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r10,484(r14)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r14.u32 + 484);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x825c40bc
	if (ctx.cr6.eq) goto loc_825C40BC;
loc_825C3D34:
	// lhz r10,202(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 202);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r9,r24
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x825c40e4
	if (!ctx.cr6.lt) goto loc_825C40E4;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x825c4ef8
	ctx.lr = 0x825C3D68;
	sub_825C4EF8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825b7e00
	ctx.lr = 0x825C3D7C;
	sub_825B7E00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// lwz r10,600(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 600);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x825c3da8
	if (!ctx.cr6.eq) goto loc_825C3DA8;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stw r16,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r16.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3DA8:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r28
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// rlwinm r9,r10,20,12,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lbzx r8,r11,r28
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r28.u32);
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// stw r7,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r7.u32);
	// lhzx r6,r11,r28
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// rlwinm r5,r6,28,28,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xF;
	// stw r5,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r5.u32);
	// lhzx r4,r11,r28
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// clrlwi r11,r4,28
	ctx.r11.u64 = ctx.r4.u32 & 0xF;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3DF0:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x825c4ef8
	ctx.lr = 0x825C3E08;
	sub_825C4EF8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825b7e00
	ctx.lr = 0x825C3E1C;
	sub_825B7E00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// lwz r10,608(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 608);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x825c3e3c
	if (!ctx.cr6.eq) goto loc_825C3E3C;
loc_825C3E34:
	// stw r15,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r15.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3E3C:
	// lbzx r10,r11,r27
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r9,r10,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r31
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r11,6
	ctx.r5.s64 = ctx.r11.s64 + 6;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r11,r6,r27
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r27.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// stwx r10,r4,r31
	REX_STORE_U32(ctx.r4.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_825C3E7C:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x825c3cb0
	if (!ctx.cr6.eq) goto loc_825C3CB0;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3E8C:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x825c4ef8
	ctx.lr = 0x825C3EA4;
	sub_825C4EF8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x825b7e00
	ctx.lr = 0x825C3EB8;
	sub_825B7E00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// lwz r11,616(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 616);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x825c3edc
	if (!ctx.cr6.eq) goto loc_825C3EDC;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3EDC:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x825c3e7c
	if (!ctx.cr6.eq) goto loc_825C3E7C;
	// stw r16,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r16.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3F08:
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwz r4,616(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 616);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825c3540
	ctx.lr = 0x825C3F20;
	sub_825C3540(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x825c3f58
	if (!ctx.cr6.eq) goto loc_825C3F58;
	// stw r16,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r16.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3F58:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x825c3e34
	if (!ctx.cr6.eq) goto loc_825C3E34;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C3F68:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825c4510
	ctx.lr = 0x825C3F78;
	sub_825C4510(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825c3fa8
	if (ctx.cr6.eq) goto loc_825C3FA8;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// lis r11,16384
	ctx.r11.s64 = 1073741824;
	// stw r9,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// li r4,1
	ctx.r4.s64 = 1;
loc_825C3FA8:
	// lwz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825c3fcc
	if (ctx.cr6.eq) goto loc_825C3FCC;
	// and r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ctx.r10.u64;
	// subfic r8,r4,31
	ctx.xer.ca = ctx.r4.u32 <= 31;
	ctx.r8.u64 = static_cast<uint64_t>(31) - ctx.r4.u64;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r7,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r7.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
loc_825C3FCC:
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825c3ff0
	if (ctx.cr6.eq) goto loc_825C3FF0;
	// and r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ctx.r10.u64;
	// subfic r8,r4,31
	ctx.xer.ca = ctx.r4.u32 <= 31;
	ctx.r8.u64 = static_cast<uint64_t>(31) - ctx.r4.u64;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r7,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r7.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
loc_825C3FF0:
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x825c4010
	if (ctx.cr6.eq) goto loc_825C4010;
	// subfic r9,r4,31
	ctx.xer.ca = ctx.r4.u32 <= 31;
	ctx.r9.u64 = static_cast<uint64_t>(31) - ctx.r4.u64;
	// and r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 & ctx.r10.u64;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// srw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r9.u8 & 0x3F));
	// stw r7,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
loc_825C4010:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825b7e00
	ctx.lr = 0x825C4018;
	sub_825B7E00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c41b4
	if (ctx.cr6.lt) goto loc_825C41B4;
	// li r11,14
	ctx.r11.s64 = 14;
	// stw r17,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r17.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C4030:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r11,5
	ctx.r10.s64 = ctx.r11.s64 + 5;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x825c40fc
	if (!ctx.cr6.eq) goto loc_825C40FC;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// lwz r10,592(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 592);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x825c407c
	if (!ctx.cr6.eq) goto loc_825C407C;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x825c407c
	if (!ctx.cr6.gt) goto loc_825C407C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_825C407C:
	// lhz r10,202(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 202);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r8,r24
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x825c40e4
	if (!ctx.cr6.lt) goto loc_825C40E4;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// bne cr6,0x825c3cb0
	if (!ctx.cr6.eq) goto loc_825C3CB0;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r9,0,28,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xE;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// b 0x825c3cb0
	goto loc_825C3CB0;
loc_825C40BC:
	// lis r11,-32164
	ctx.r11.s64 = -2107899904;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r9,r11,14360
	ctx.r9.s64 = ctx.r11.s64 + 14360;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// stw r9,484(r30)
	REX_STORE_U32(ctx.r30.u32 + 484, ctx.r9.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x825c3818
	ctx.lr = 0x825C40DC;
	sub_825C3818(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_825C40E4:
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// stw r17,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r17.u32);
	// stw r17,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r17.u32);
	// stw r10,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_825C40FC:
	// lwz r11,592(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 592);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825c4120
	if (!ctx.cr6.eq) goto loc_825C4120;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x825c4120
	if (!ctx.cr6.gt) goto loc_825C4120;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_825C4120:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// stw r9,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r17,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r17.u32);
	// lwzx r6,r7,r31
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// stw r6,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r6.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r11,9
	ctx.r5.s64 = ctx.r11.s64 + 9;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x825c41b4
	if (!ctx.cr6.eq) goto loc_825C41B4;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825c418c
	if (ctx.cr6.eq) goto loc_825C418C;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_825C418C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_825C419C:
	// lis r11,-32164
	ctx.r11.s64 = -2107899904;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// addi r10,r11,14360
	ctx.r10.s64 = ctx.r11.s64 + 14360;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r10,484(r30)
	REX_STORE_U32(ctx.r30.u32 + 484, ctx.r10.u32);
	// bl 0x825c3818
	ctx.lr = 0x825C41B4;
	sub_825C3818(ctx, base);
loc_825C41B4:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F55C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0290
	ctx.lr = 0x825F55D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r29,236(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 236);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// mr r28,r9
	ctx.r28.u64 = ctx.r9.u64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x825f5614
	if (!ctx.cr6.gt) goto loc_825F5614;
loc_825F55FC:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x825f4f68
	ctx.lr = 0x825F5608;
	sub_825F4F68(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne 0x825f55fc
	if (!ctx.cr0.eq) goto loc_825F55FC;
loc_825F5614:
	// lwz r7,228(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 228);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x825f566c
	if (!ctx.cr6.gt) goto loc_825F566C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_825F5628:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x825f4f68
	ctx.lr = 0x825F5638;
	sub_825F4F68(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne 0x825f5628
	if (!ctx.cr0.eq) goto loc_825F5628;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x825f566c
	if (!ctx.cr6.gt) goto loc_825F566C;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_825F5650:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x825f4f68
	ctx.lr = 0x825F5660;
	sub_825F4F68(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// bne 0x825f5650
	if (!ctx.cr0.eq) goto loc_825F5650;
loc_825F566C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x826a02e0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F8108) {
	REX_FUNC_PROLOGUE();
	// lwz r10,15580(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 15580);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// bne cr6,0x825f813c
	if (!ctx.cr6.eq) goto loc_825F813C;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r4,3948(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 3948);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,15540(r11)
	REX_STORE_U32(ctx.r11.u32 + 15540, ctx.r10.u32);
	// stw r10,15544(r11)
	REX_STORE_U32(ctx.r11.u32 + 15544, ctx.r10.u32);
	// b 0x8262c838
	sub_8262C838(ctx, base);
	return;
loc_825F813C:
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x825f815c
	if (!ctx.cr6.eq) goto loc_825F815C;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r4,3948(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 3948);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,15540(r11)
	REX_STORE_U32(ctx.r11.u32 + 15540, ctx.r10.u32);
	// stw r10,15544(r11)
	REX_STORE_U32(ctx.r11.u32 + 15544, ctx.r10.u32);
	// b 0x8262c838
	sub_8262C838(ctx, base);
	return;
loc_825F815C:
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x825f8180
	if (!ctx.cr6.eq) goto loc_825F8180;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r4,3948(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 3948);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,15540(r11)
	REX_STORE_U32(ctx.r11.u32 + 15540, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,15544(r11)
	REX_STORE_U32(ctx.r11.u32 + 15544, ctx.r9.u32);
	// b 0x8262c838
	sub_8262C838(ctx, base);
	return;
loc_825F8180:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x825f81a0
	if (!ctx.cr6.eq) goto loc_825F81A0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,3948(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 3948);
	// stw r10,15540(r11)
	REX_STORE_U32(ctx.r11.u32 + 15540, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,15544(r11)
	REX_STORE_U32(ctx.r11.u32 + 15544, ctx.r9.u32);
	// b 0x8262c838
	sub_8262C838(ctx, base);
	return;
loc_825F81A0:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,15540(r11)
	REX_STORE_U32(ctx.r11.u32 + 15540, ctx.r10.u32);
	// stw r10,15544(r11)
	REX_STORE_U32(ctx.r11.u32 + 15544, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825FE1E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stb r7,-16(r1)
	REX_STORE_U8(ctx.r1.u32 + -16, ctx.r7.u8);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// srawi. r10,r6,4
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r9,r6,28
	ctx.r9.u64 = ctx.r6.u32 & 0xF;
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltb v0,v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_set1_epi8(char(0xF))));
	// ble 0x825fe230
	if (!ctx.cr0.gt) goto loc_825FE230;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_825FE20C:
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lvx128 v12,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// vaddubs v11,v12,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_adds_epu8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// vaddubs v10,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_adds_epu8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvx128 v10,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bdnz 0x825fe20c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825FE20C;
loc_825FE230:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// subf r8,r11,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r11.u64;
	// subf r6,r11,r3
	ctx.r6.u64 = ctx.r3.u64 - ctx.r11.u64;
loc_825FE244:
	// lbzx r10,r8,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r11.u32);
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// cmpwi cr6,r10,255
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 255, ctx.xer);
	// ble cr6,0x825fe260
	if (!ctx.cr6.gt) goto loc_825FE260;
	// li r10,255
	ctx.r10.s64 = 255;
loc_825FE260:
	// stbx r10,r6,r11
	REX_STORE_U8(ctx.r6.u32 + ctx.r11.u32, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x825fe244
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_825FE244;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82601360) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,2880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f3,f0
	ctx.cr6.compare(ctx.f3.f64, ctx.f0.f64);
	// ble cr6,0x826016a0
	if (!ctx.cr6.gt) goto loc_826016A0;
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// ble cr6,0x826016a0
	if (!ctx.cr6.gt) goto loc_826016A0;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lfd f0,7304(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 7304);
	// fadd f11,f1,f0
	ctx.f11.f64 = ctx.f1.f64 + ctx.f0.f64;
	// lfs f13,4268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4268);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f4,f13
	ctx.f10.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfs f13,4272(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4272);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f9,f3,f13
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fctiwz f8,f11
	ctx.f8.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f8.u64);
	// lwz r6,-12(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fcfid f5,f12
	ctx.f5.f64 = double(ctx.f12.s64);
	// fsubs f13,f2,f10
	ctx.f13.f64 = double(float(ctx.f2.f64 - ctx.f10.f64));
	// fneg f4,f10
	ctx.f4.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// frsp f12,f5
	ctx.f12.f64 = double(float(ctx.f5.f64));
	// fsubs f11,f2,f4
	ctx.f11.f64 = double(float(ctx.f2.f64 - ctx.f4.f64));
	// fadds f10,f3,f9
	ctx.f10.f64 = double(float(ctx.f3.f64 + ctx.f9.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x826013f0
	if (!ctx.cr6.gt) goto loc_826013F0;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
loc_826013F0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fctiwz f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r6,-12(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r6,4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 4, ctx.xer);
	// lfs f12,2884(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2884);
	ctx.f12.f64 = double(temp.f32);
	// blt cr6,0x82601470
	if (ctx.cr6.lt) goto loc_82601470;
	// fadds f13,f1,f12
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
	// addi r11,r6,-4
	ctx.r11.s64 = ctx.r6.s64 + -4;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fadd f9,f13,f0
	ctx.f9.f64 = ctx.f13.f64 + ctx.f0.f64;
	// fctiwz f8,f9
	ctx.f8.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f8.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
loc_8260143C:
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
	// stwx r9,r10,r7
	REX_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r9,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r9,-4(r4)
	REX_STORE_U32(ctx.r4.u32 + -4, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stwx r9,r8,r7
	REX_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u32);
	// bdnz 0x8260143c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8260143C;
loc_82601470:
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826014ac
	if (!ctx.cr6.lt) goto loc_826014AC;
	// fadds f13,f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fadd f9,f13,f0
	ctx.f9.f64 = ctx.f13.f64 + ctx.f0.f64;
	// fctiwz f8,f9
	ctx.f8.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f8.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
loc_8260149C:
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stwx r9,r10,r8
	REX_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8260149c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8260149C;
loc_826014AC:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// frsp f13,f9
	ctx.f13.f64 = double(float(ctx.f9.f64));
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgt cr6,0x826014d0
	if (ctx.cr6.gt) goto loc_826014D0;
	// fmr f13,f11
	ctx.f13.f64 = ctx.f11.f64;
loc_826014D0:
	// fctiwz f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r6,-12(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8260158c
	if (!ctx.cr6.lt) goto loc_8260158C;
	// subf r10,r11,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r11.u64;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x82601554
	if (ctx.cr6.lt) goto loc_82601554;
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// fadd f13,f10,f0
	ctx.f13.f64 = ctx.f10.f64 + ctx.f0.f64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// fctiwz f11,f13
	ctx.f11.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lwz r9,-12(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
loc_82601520:
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
	// stwx r9,r10,r7
	REX_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r9,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r9,-4(r4)
	REX_STORE_U32(ctx.r4.u32 + -4, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stwx r9,r8,r7
	REX_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u32);
	// bdnz 0x82601520
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82601520;
loc_82601554:
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x8260158c
	if (!ctx.cr6.lt) goto loc_8260158C;
	// fadd f13,f10,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f10.f64 + ctx.f0.f64;
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fctiwz f11,f13
	ctx.f11.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
loc_8260157C:
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stwx r9,r10,r8
	REX_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8260157c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8260157C;
loc_8260158C:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x826015cc
	if (!ctx.cr6.lt) goto loc_826015CC;
	// fadds f13,f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fadd f12,f13,f0
	ctx.f12.f64 = ctx.f13.f64 + ctx.f0.f64;
	// fctiwz f11,f12
	ctx.f11.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
loc_826015B0:
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r8,r9,r10
	REX_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826015b0
	if (ctx.cr6.lt) goto loc_826015B0;
loc_826015CC:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82601608
	if (!ctx.cr6.gt) goto loc_82601608;
	// fadd f13,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f1.f64 + ctx.f0.f64;
	// li r11,0
	ctx.r11.s64 = 0;
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f12.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
loc_826015EC:
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwx r8,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826015ec
	if (ctx.cr6.lt) goto loc_826015EC;
loc_82601608:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82601730
	if (!ctx.cr6.gt) goto loc_82601730;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f13,6380(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6380);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f1,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
loc_82601624:
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r8,28(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwzx r7,r11,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f12,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fsubs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fadd f8,f9,f0
	ctx.f8.f64 = ctx.f9.f64 + ctx.f0.f64;
	// fctiwz f7,f8
	ctx.f7.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,r11,r8
	REX_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.f7.u32);
	// lwz r4,32(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwzx r10,r11,r5
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r8,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r8.u64);
	// lfd f6,-8(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fsubs f3,f13,f4
	ctx.f3.f64 = double(float(ctx.f13.f64 - ctx.f4.f64));
	// fadd f2,f3,f0
	ctx.f2.f64 = ctx.f3.f64 + ctx.f0.f64;
	// fctiwz f1,f2
	ctx.f1.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f1,r11,r4
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.f1.u32);
	// lwz r7,4(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x82601624
	if (ctx.cr6.lt) goto loc_82601624;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826016A0:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82601730
	if (!ctx.cr6.gt) goto loc_82601730;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f13,2884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2884);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f1,f13
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// lfd f0,7304(r8)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 7304);
	// fadd f10,f1,f0
	ctx.f10.f64 = ctx.f1.f64 + ctx.f0.f64;
	// fadds f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f13.f64));
	// fadd f8,f11,f0
	ctx.f8.f64 = ctx.f11.f64 + ctx.f0.f64;
	// fctiwz f7,f10
	ctx.f7.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f7,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.f7.u64);
	// fadd f9,f12,f0
	ctx.f9.f64 = ctx.f12.f64 + ctx.f0.f64;
	// fctiwz f5,f8
	ctx.f5.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f5,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f5.u64);
	// fctiwz f6,f9
	ctx.f6.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// lwz r9,-4(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -4);
	// stfd f6,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.f6.u64);
	// lwz r8,-4(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -4);
	// lwz r7,-12(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -12);
loc_826016FC:
	// lwz r6,20(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r8,r11,r6
	REX_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r8.u32);
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// stwx r9,r11,r5
	REX_STORE_U32(ctx.r11.u32 + ctx.r5.u32, ctx.r9.u32);
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// stwx r7,r11,r4
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r7.u32);
	// lwz r6,32(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// stwx r9,r11,r6
	REX_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x826016fc
	if (ctx.cr6.lt) goto loc_826016FC;
loc_82601730:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826190C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0260
	ctx.lr = 0x826190D0;
	__savegprlr_14(ctx, base);
	// stwu r1,-1440(r1)
	ea = -1440 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r16,r6
	ctx.r16.u64 = ctx.r6.u64;
	// lwz r6,328(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 328);
	// mr r17,r9
	ctx.r17.u64 = ctx.r9.u64;
	// lwz r11,20624(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20624);
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// lwz r9,1524(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 1524);
	// addic r5,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r5.s64 = ctx.r6.s64 + -1;
	// lwz r15,208(r3)
	ctx.r15.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subfe r20,r5,r6
	temp.u8 = (~ctx.r5.u32 + ctx.r6.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r20.u64 = ~ctx.r5.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r18,r8
	ctx.r18.u64 = ctx.r8.u64;
	// lwz r8,20628(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20628);
	// srawi r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r6,204(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mr r14,r7
	ctx.r14.u64 = ctx.r7.u64;
	// lbz r7,4(r16)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r16.u32 + 4);
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// mullw r9,r4,r6
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// lwz r6,0(r16)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rotlwi r3,r7,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// srawi r5,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r3,r7,r3
	ctx.r3.u64 = ctx.r7.u64 + ctx.r3.u64;
	// lwz r30,3756(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3756);
	// lwz r29,3784(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 3784);
	// rlwinm r7,r3,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r24,6576(r31)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r31.u32 + 6576);
	// lwz r21,336(r31)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// lwz r28,3760(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 3760);
	// add r24,r7,r24
	ctx.r24.u64 = ctx.r7.u64 + ctx.r24.u64;
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r27,3764(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 3764);
	// mullw r4,r4,r15
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r15.s32);
	// lwz r26,3788(r31)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r31.u32 + 3788);
	// lwz r25,3792(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 3792);
	// lwz r19,1768(r31)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// stw r21,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r21.u32);
	// stw r24,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r24.u32);
	// add r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 + ctx.r5.u64;
	// rlwinm r15,r6,12,30,31
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 12) & 0x3;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r8,r30,r9
	ctx.r8.u64 = ctx.r30.u64 + ctx.r9.u64;
	// add r9,r29,r9
	ctx.r9.u64 = ctx.r29.u64 + ctx.r9.u64;
	// add r30,r8,r10
	ctx.r30.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r29,r9,r10
	ctx.r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r28,r28,r11
	ctx.r28.u64 = ctx.r28.u64 + ctx.r11.u64;
	// add r27,r27,r11
	ctx.r27.u64 = ctx.r27.u64 + ctx.r11.u64;
	// add r26,r26,r11
	ctx.r26.u64 = ctx.r26.u64 + ctx.r11.u64;
	// add r25,r25,r11
	ctx.r25.u64 = ctx.r25.u64 + ctx.r11.u64;
	// beq cr6,0x826191b4
	if (ctx.cr6.eq) goto loc_826191B4;
	// rlwinm r21,r6,8,29,31
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0x7;
	// stw r21,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r21.u32);
loc_826191B4:
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826191d8
	if (ctx.cr6.eq) goto loc_826191D8;
	// rlwinm r11,r6,10,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 10) & 0x3;
	// addi r11,r11,732
	ctx.r11.s64 = ctx.r11.s64 + 732;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// b 0x826191e0
	goto loc_826191E0;
loc_826191D8:
	// addi r11,r31,2904
	ctx.r11.s64 = ctx.r31.s64 + 2904;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
loc_826191E0:
	// rlwinm r11,r6,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8261932c
	if (ctx.cr6.eq) goto loc_8261932C;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82619334
	if (ctx.cr6.eq) goto loc_82619334;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x82619204
	if (ctx.cr6.eq) goto loc_82619204;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x826195d0
	if (!ctx.cr6.eq) goto loc_826195D0;
loc_82619204:
	// lwz r24,1532(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 1532);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// lwz r21,1540(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 1540);
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// stw r24,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r21,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// bne cr6,0x8261923c
	if (!ctx.cr6.eq) goto loc_8261923C;
	// bl 0x82633bc8
	ctx.lr = 0x82619238;
	sub_82633BC8(ctx, base);
	// b 0x82619240
	goto loc_82619240;
loc_8261923C:
	// bl 0x82633b00
	ctx.lr = 0x82619240;
	sub_82633B00(ctx, base);
loc_82619240:
	// lwz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// rlwinm r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// bne cr6,0x82619260
	if (!ctx.cr6.eq) goto loc_82619260;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// b 0x8261926c
	goto loc_8261926C;
loc_82619260:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
loc_8261926C:
	// lwz r11,3928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3928);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,512
	ctx.r6.s64 = ctx.r1.s64 + 512;
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// lwz r5,204(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82633f50
	ctx.lr = 0x82619298;
	sub_82633F50(ctx, base);
	// lwz r10,22408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22408);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826192ac
	if (ctx.cr6.eq) goto loc_826192AC;
	// stw r24,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r24.u32);
	// stw r21,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
loc_826192AC:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82634448
	ctx.lr = 0x826192BC;
	sub_82634448(ctx, base);
	// lwz r11,22408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22408);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826192e0
	if (ctx.cr6.eq) goto loc_826192E0;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633ca8
	ctx.lr = 0x826192E0;
	sub_82633CA8(ctx, base);
loc_826192E0:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633e68
	ctx.lr = 0x82619304;
	sub_82633E68(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633e68
	ctx.lr = 0x82619328;
	sub_82633E68(ctx, base);
	// b 0x826195c8
	goto loc_826195C8;
loc_8261932C:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82619358
	if (!ctx.cr6.eq) goto loc_82619358;
loc_82619334:
	// lwz r11,1548(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 1548);
	// lwz r24,1532(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 1532);
	// lwz r21,1540(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 1540);
	// lwz r10,1556(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 1556);
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// stw r24,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r24.u32);
	// stw r21,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r21.u32);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// b 0x826193a0
	goto loc_826193A0;
loc_82619358:
	// lwz r11,3984(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3984);
	// addi r9,r1,108
	ctx.r9.s64 = ctx.r1.s64 + 108;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r5,1540(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 1540);
	// addi r7,r11,-3
	ctx.r7.s64 = ctx.r11.s64 + -3;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r4,1532(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 1532);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// mr r8,r22
	ctx.r8.u64 = ctx.r22.u64;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// rlwinm r6,r6,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826342d0
	ctx.lr = 0x82619398;
	sub_826342D0(ctx, base);
	// lwz r24,96(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r21,100(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_826193A0:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bne cr6,0x826193e0
	if (!ctx.cr6.eq) goto loc_826193E0;
	// bl 0x82633bc8
	ctx.lr = 0x826193C4;
	sub_82633BC8(ctx, base);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633bc8
	ctx.lr = 0x826193DC;
	sub_82633BC8(ctx, base);
	// b 0x826193fc
	goto loc_826193FC;
loc_826193E0:
	// bl 0x82633b00
	ctx.lr = 0x826193E4;
	sub_82633B00(ctx, base);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826193FC;
	sub_82633B00(ctx, base);
loc_826193FC:
	// lwz r11,3928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3928);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,512
	ctx.r6.s64 = ctx.r1.s64 + 512;
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,204(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82633f50
	ctx.lr = 0x8261942C;
	sub_82633F50(ctx, base);
	// lwz r11,3928(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3928);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r9,108(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// lwz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addi r6,r1,768
	ctx.r6.s64 = ctx.r1.s64 + 768;
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,204(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82633f50
	ctx.lr = 0x8261945C;
	sub_82633F50(ctx, base);
	// lwz r11,3232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3232);
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,512
	ctx.r7.s64 = ctx.r1.s64 + 512;
	// li r6,16
	ctx.r6.s64 = 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r5,r1,768
	ctx.r5.s64 = ctx.r1.s64 + 768;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// bctrl 
	ctx.lr = 0x82619488;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,22408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 22408);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8261949c
	if (ctx.cr6.eq) goto loc_8261949C;
	// stw r24,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r24.u32);
	// stw r21,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r21.u32);
loc_8261949C:
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82634448
	ctx.lr = 0x826194AC;
	sub_82634448(ctx, base);
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82634448
	ctx.lr = 0x826194BC;
	sub_82634448(ctx, base);
	// lwz r11,22408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 22408);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826194e0
	if (ctx.cr6.eq) goto loc_826194E0;
	// addi r7,r1,100
	ctx.r7.s64 = ctx.r1.s64 + 100;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633ca8
	ctx.lr = 0x826194E0;
	sub_82633CA8(ctx, base);
loc_826194E0:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633e68
	ctx.lr = 0x82619504;
	sub_82633E68(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r9,108(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r6,r1,384
	ctx.r6.s64 = ctx.r1.s64 + 384;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633e68
	ctx.lr = 0x82619528;
	sub_82633E68(ctx, base);
	// lwz r11,3232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3232);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// li r6,8
	ctx.r6.s64 = 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r5,r1,384
	ctx.r5.s64 = ctx.r1.s64 + 384;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bctrl 
	ctx.lr = 0x82619554;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// lwz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633e68
	ctx.lr = 0x82619578;
	sub_82633E68(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r9,108(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// addi r6,r1,448
	ctx.r6.s64 = ctx.r1.s64 + 448;
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r8,112(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82633e68
	ctx.lr = 0x8261959C;
	sub_82633E68(ctx, base);
	// lwz r11,3232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3232);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r7,r1,320
	ctx.r7.s64 = ctx.r1.s64 + 320;
	// li r6,8
	ctx.r6.s64 = 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r5,r1,448
	ctx.r5.s64 = ctx.r1.s64 + 448;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bctrl 
	ctx.lr = 0x826195C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_826195C8:
	// lwz r21,120(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r24,116(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_826195D0:
	// lis r11,-32245
	ctx.r11.s64 = -2113208320;
	// li r22,0
	ctx.r22.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,10824
	ctx.r9.s64 = ctx.r11.s64 + 10824;
	// addi r23,r1,512
	ctx.r23.s64 = ctx.r1.s64 + 512;
	// addi r25,r1,1024
	ctx.r25.s64 = ctx.r1.s64 + 1024;
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// ori r26,r10,32768
	ctx.r26.u64 = ctx.r10.u64 | 32768;
loc_826195F4:
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// lbzx r11,r27,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r27.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82619f9c
	if (ctx.cr6.eq) goto loc_82619F9C;
	// lwz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8261976c
	if (ctx.cr6.eq) goto loc_8261976C;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// bne cr6,0x8261976c
	if (!ctx.cr6.eq) goto loc_8261976C;
	// lwz r10,2580(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2580);
	// lwz r30,84(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lbz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 8);
	// ld r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// subfic r9,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r28,0(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// clrldi r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// srd r7,r11,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r8.u8 & 0x7F));
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r5,r6,r28
	ctx.r5.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r28.u32);
	// extsh r29,r5
	ctx.r29.s64 = ctx.r5.s16;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82619710
	if (ctx.cr6.lt) goto loc_82619710;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r9,r29,28
	ctx.r9.u64 = ctx.r29.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82619708
	if (!ctx.cr6.lt) goto loc_82619708;
loc_82619670:
	// lwz r10,16(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8261969c
	if (ctx.cr6.lt) goto loc_8261969C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8a98
	ctx.lr = 0x8261968C;
	sub_825F8A98(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82619670
	if (ctx.cr6.eq) goto loc_82619670;
	// srawi r29,r29,4
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 4;
	// b 0x82619748
	goto loc_82619748;
loc_8261969C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r9,r9,8,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r5,2(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r4,r10,8,55
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r3,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// add r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 + ctx.r5.u64;
	// ld r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// neg r4,r10
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r5,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r6,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r3.u8 & 0x7F));
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r5,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r5.u64);
loc_82619708:
	// srawi r29,r29,4
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 4;
	// b 0x82619748
	goto loc_82619748;
loc_82619710:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8c28
	ctx.lr = 0x82619718;
	sub_825F8C28(ctx, base);
loc_82619718:
	// ld r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x825f8c28
	ctx.lr = 0x82619730;
	sub_825F8C28(ctx, base);
	// add r10,r29,r26
	ctx.r10.u64 = ctx.r29.u64 + ctx.r26.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r28
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r28.u32);
	// extsh r29,r8
	ctx.r29.s64 = ctx.r8.s16;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82619718
	if (ctx.cr6.lt) goto loc_82619718;
loc_82619748:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8261a280
	if (!ctx.cr6.eq) goto loc_8261A280;
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-32
	ctx.r9.s64 = ctx.r11.s64 + -32;
	// lwzx r15,r10,r11
	ctx.r15.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r21,r10,r9
	ctx.r21.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_8261976C:
	// add r11,r27,r16
	ctx.r11.u64 = ctx.r27.u64 + ctx.r16.u64;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// stb r21,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r21.u8);
	// bne cr6,0x826197bc
	if (!ctx.cr6.eq) goto loc_826197BC;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r19,1768(r31)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r5,1832(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1832);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826197A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3188);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r6,1940(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 1940);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// b 0x82619e30
	goto loc_82619E30;
loc_826197BC:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// bne cr6,0x826199a8
	if (!ctx.cr6.eq) goto loc_826199A8;
	// lwz r19,1764(r31)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r31.u32 + 1764);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r28,1
	ctx.r28.s64 = 1;
	// bl 0x826a03b0
	ctx.lr = 0x826197E0;
	rexcrt_memset(ctx, base);
	// lwz r11,3396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82619880
	if (ctx.cr6.eq) goto loc_82619880;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// bne cr6,0x8261986c
	if (!ctx.cr6.eq) goto loc_8261986C;
	// lwz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8261986c
	if (!ctx.cr6.eq) goto loc_8261986C;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8261982c
	if (!ctx.cr0.lt) goto loc_8261982C;
	// bl 0x825f8b58
	ctx.lr = 0x8261982C;
	sub_825F8B58(ctx, base);
loc_8261982C:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x82619910
	if (!ctx.cr6.eq) goto loc_82619910;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x8261985c
	if (!ctx.cr0.lt) goto loc_8261985C;
	// bl 0x825f8b58
	ctx.lr = 0x8261985C;
	sub_825F8B58(ctx, base);
loc_8261985C:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x8261990c
	if (!ctx.cr6.eq) goto loc_8261990C;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// b 0x82619910
	goto loc_82619910;
loc_8261986C:
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// rlwinm r29,r15,0,30,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 0) & 0x2;
	// clrlwi r28,r15,31
	ctx.r28.u64 = ctx.r15.u32 & 0x1;
	// stbx r15,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r15.u8);
	// b 0x82619920
	goto loc_82619920;
loc_82619880:
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x826198a4
	if (ctx.cr6.eq) goto loc_826198A4;
	// lwz r10,0(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// rlwinm r9,r10,12,30,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// rlwinm r29,r9,0,30,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// stbx r9,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r9.u8);
	// clrlwi r28,r9,31
	ctx.r28.u64 = ctx.r9.u32 & 0x1;
	// b 0x82619920
	goto loc_82619920;
loc_826198A4:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826198cc
	if (!ctx.cr0.lt) goto loc_826198CC;
	// bl 0x825f8b58
	ctx.lr = 0x826198CC;
	sub_825F8B58(ctx, base);
loc_826198CC:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x82619910
	if (!ctx.cr6.eq) goto loc_82619910;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826198fc
	if (!ctx.cr0.lt) goto loc_826198FC;
	// bl 0x825f8b58
	ctx.lr = 0x826198FC;
	sub_825F8B58(ctx, base);
loc_826198FC:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x8261990c
	if (!ctx.cr6.eq) goto loc_8261990C;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// b 0x82619910
	goto loc_82619910;
loc_8261990C:
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_82619910:
	// rlwinm r10,r29,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// or r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 | ctx.r28.u64;
	// stbx r9,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r9.u8);
loc_82619920:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x8261996c
	if (ctx.cr6.eq) goto loc_8261996C;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r5,1852(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1852);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619948;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3192);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,1768(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8261996C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8261996C:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82619e3c
	if (ctx.cr6.eq) goto loc_82619E3C;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r5,1852(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1852);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619994;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3192);
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x82619e28
	goto loc_82619E28;
loc_826199A8:
	// cmpwi cr6,r21,2
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 2, ctx.xer);
	// bne cr6,0x82619b94
	if (!ctx.cr6.eq) goto loc_82619B94;
	// lwz r19,1764(r31)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r31.u32 + 1764);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r28,1
	ctx.r28.s64 = 1;
	// bl 0x826a03b0
	ctx.lr = 0x826199CC;
	rexcrt_memset(ctx, base);
	// lwz r11,3396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82619a6c
	if (ctx.cr6.eq) goto loc_82619A6C;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// bne cr6,0x82619a58
	if (!ctx.cr6.eq) goto loc_82619A58;
	// lwz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// rlwinm r10,r11,0,3,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82619a58
	if (!ctx.cr6.eq) goto loc_82619A58;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82619a18
	if (!ctx.cr0.lt) goto loc_82619A18;
	// bl 0x825f8b58
	ctx.lr = 0x82619A18;
	sub_825F8B58(ctx, base);
loc_82619A18:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x82619afc
	if (!ctx.cr6.eq) goto loc_82619AFC;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82619a48
	if (!ctx.cr0.lt) goto loc_82619A48;
	// bl 0x825f8b58
	ctx.lr = 0x82619A48;
	sub_825F8B58(ctx, base);
loc_82619A48:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x82619af8
	if (!ctx.cr6.eq) goto loc_82619AF8;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// b 0x82619afc
	goto loc_82619AFC;
loc_82619A58:
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// rlwinm r29,r15,0,30,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 0) & 0x2;
	// clrlwi r28,r15,31
	ctx.r28.u64 = ctx.r15.u32 & 0x1;
	// stbx r15,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r15.u8);
	// b 0x82619b0c
	goto loc_82619B0C;
loc_82619A6C:
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x82619a90
	if (ctx.cr6.eq) goto loc_82619A90;
	// lwz r10,0(r16)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// rlwinm r9,r10,12,30,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// rlwinm r29,r9,0,30,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// stbx r9,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r9.u8);
	// clrlwi r28,r9,31
	ctx.r28.u64 = ctx.r9.u32 & 0x1;
	// b 0x82619b0c
	goto loc_82619B0C;
loc_82619A90:
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82619ab8
	if (!ctx.cr0.lt) goto loc_82619AB8;
	// bl 0x825f8b58
	ctx.lr = 0x82619AB8;
	sub_825F8B58(ctx, base);
loc_82619AB8:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x82619afc
	if (!ctx.cr6.eq) goto loc_82619AFC;
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82619ae8
	if (!ctx.cr0.lt) goto loc_82619AE8;
	// bl 0x825f8b58
	ctx.lr = 0x82619AE8;
	sub_825F8B58(ctx, base);
loc_82619AE8:
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// bne cr6,0x82619af8
	if (!ctx.cr6.eq) goto loc_82619AF8;
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
	// b 0x82619afc
	goto loc_82619AFC;
loc_82619AF8:
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_82619AFC:
	// rlwinm r10,r29,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// or r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 | ctx.r28.u64;
	// stbx r9,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r9.u8);
loc_82619B0C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82619b58
	if (ctx.cr6.eq) goto loc_82619B58;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r5,1856(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1856);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619B34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3196);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,1768(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619B58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82619B58:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82619e3c
	if (ctx.cr6.eq) goto loc_82619E3C;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r5,1856(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1856);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619B80;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3196);
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x82619e28
	goto loc_82619E28;
loc_82619B94:
	// cmpwi cr6,r21,4
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 4, ctx.xer);
	// bne cr6,0x82619e3c
	if (!ctx.cr6.eq) goto loc_82619E3C;
	// lwz r19,1764(r31)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r31.u32 + 1764);
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// bl 0x826a03b0
	ctx.lr = 0x82619BB0;
	rexcrt_memset(ctx, base);
	// lwz r10,2500(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 2500);
	// lbz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r10.u32 + 8);
	// subfic r9,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// clrldi r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lwz r30,84(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r28,0(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// ld r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// srd r7,r11,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r8.u8 & 0x7F));
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r5,r6,r28
	ctx.r5.u64 = REX_LOAD_U16(ctx.r6.u32 + ctx.r28.u32);
	// extsh r29,r5
	ctx.r29.s64 = ctx.r5.s16;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82619ca4
	if (ctx.cr6.lt) goto loc_82619CA4;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r9,r29,28
	ctx.r9.u64 = ctx.r29.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82619c9c
	if (!ctx.cr6.lt) goto loc_82619C9C;
loc_82619C04:
	// lwz r10,16(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82619c30
	if (ctx.cr6.lt) goto loc_82619C30;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8a98
	ctx.lr = 0x82619C20;
	sub_825F8A98(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82619c04
	if (ctx.cr6.eq) goto loc_82619C04;
	// srawi r29,r29,4
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 4;
	// b 0x82619cdc
	goto loc_82619CDC;
loc_82619C30:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r5,r10,8,55
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// stw r3,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// ld r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// neg r4,r10
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r5,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r6,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r3.u8 & 0x7F));
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r5,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r5.u64);
loc_82619C9C:
	// srawi r29,r29,4
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 4;
	// b 0x82619cdc
	goto loc_82619CDC;
loc_82619CA4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8c28
	ctx.lr = 0x82619CAC;
	sub_825F8C28(ctx, base);
loc_82619CAC:
	// ld r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x825f8c28
	ctx.lr = 0x82619CC4;
	sub_825F8C28(ctx, base);
	// add r10,r29,r26
	ctx.r10.u64 = ctx.r29.u64 + ctx.r26.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r28
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r28.u32);
	// extsh r29,r8
	ctx.r29.s64 = ctx.r8.s16;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82619cac
	if (ctx.cr6.lt) goto loc_82619CAC;
loc_82619CDC:
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// addi r30,r29,1
	ctx.r30.s64 = ctx.r29.s64 + 1;
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8261a280
	if (!ctx.cr6.eq) goto loc_8261A280;
	// addi r11,r16,14
	ctx.r11.s64 = ctx.r16.s64 + 14;
	// lwz r29,104(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r9,r30,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stbx r30,r27,r11
	REX_STORE_U8(ctx.r27.u32 + ctx.r11.u32, ctx.r30.u8);
	// beq cr6,0x82619d4c
	if (ctx.cr6.eq) goto loc_82619D4C;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r5,1860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1860);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619D28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3200);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,1768(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619D4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82619D4C:
	// rlwinm r11,r30,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82619d9c
	if (ctx.cr6.eq) goto loc_82619D9C;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r5,1860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1860);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619D78;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3200);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,1768(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619D9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82619D9C:
	// rlwinm r11,r30,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82619dec
	if (ctx.cr6.eq) goto loc_82619DEC;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r5,1860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1860);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619DC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3200);
	// li r6,2
	ctx.r6.s64 = 2;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,1768(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619DEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82619DEC:
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82619e3c
	if (ctx.cr6.eq) goto loc_82619E3C;
	// lwz r11,3180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3180);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r5,1860(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1860);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,104(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619E18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8261a278
	if (!ctx.cr6.eq) goto loc_8261A278;
	// lwz r11,3200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3200);
	// li r6,3
	ctx.r6.s64 = 3;
loc_82619E28:
	// lwz r5,1768(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 1768);
	// li r4,8
	ctx.r4.s64 = 8;
loc_82619E30:
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82619E3C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82619E3C:
	// lis r11,-32159
	ctx.r11.s64 = -2107572224;
	// lwz r10,3188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3188);
	// addi r9,r11,-24344
	ctx.r9.s64 = ctx.r11.s64 + -24344;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82619e6c
	if (!ctx.cr6.eq) goto loc_82619E6C;
	// li r9,64
	ctx.r9.s64 = 64;
	// addi r10,r19,-2
	ctx.r10.s64 = ctx.r19.s64 + -2;
	// addi r11,r19,-4
	ctx.r11.s64 = ctx.r19.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82619E60:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x82619e60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82619E60;
loc_82619E6C:
	// mr r20,r22
	ctx.r20.u64 = ctx.r22.u64;
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bge cr6,0x82619e88
	if (!ctx.cr6.lt) goto loc_82619E88;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// li r30,16
	ctx.r30.s64 = 16;
	// b 0x82619ea4
	goto loc_82619EA4;
loc_82619E88:
	// bne cr6,0x82619e98
	if (!ctx.cr6.eq) goto loc_82619E98;
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// b 0x82619ea0
	goto loc_82619EA0;
loc_82619E98:
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
loc_82619EA0:
	// li r30,8
	ctx.r30.s64 = 8;
loc_82619EA4:
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mr r9,r19
	ctx.r9.u64 = ctx.r19.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// li r4,8
	ctx.r4.s64 = 8;
loc_82619EB8:
	// li r11,2
	ctx.r11.s64 = 2;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82619EC8:
	// lhz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// lbzx r11,r3,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// add. r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x82619ee4
	if (!ctx.cr0.lt) goto loc_82619EE4;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x82619ef0
	goto loc_82619EF0;
loc_82619EE4:
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x82619ef0
	if (!ctx.cr6.gt) goto loc_82619EF0;
	// li r11,255
	ctx.r11.s64 = 255;
loc_82619EF0:
	// lhz r29,2(r9)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r9.u32 + 2);
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lbz r8,-1(r7)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r7.u32 + -1);
	// extsh r11,r29
	ctx.r11.s64 = ctx.r29.s16;
	// add. r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x82619f10
	if (!ctx.cr0.lt) goto loc_82619F10;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x82619f1c
	goto loc_82619F1C;
loc_82619F10:
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x82619f1c
	if (!ctx.cr6.gt) goto loc_82619F1C;
	// li r11,255
	ctx.r11.s64 = 255;
loc_82619F1C:
	// lhz r29,4(r9)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r9.u32 + 4);
	// stb r11,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r11.u8);
	// lbz r8,0(r7)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// extsh r11,r29
	ctx.r11.s64 = ctx.r29.s16;
	// add. r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x82619f3c
	if (!ctx.cr0.lt) goto loc_82619F3C;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x82619f48
	goto loc_82619F48;
loc_82619F3C:
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x82619f48
	if (!ctx.cr6.gt) goto loc_82619F48;
	// li r11,255
	ctx.r11.s64 = 255;
loc_82619F48:
	// lhz r29,6(r9)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r9.u32 + 6);
	// stb r11,2(r10)
	REX_STORE_U8(ctx.r10.u32 + 2, ctx.r11.u8);
	// lbz r8,1(r7)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r7.u32 + 1);
	// extsh r11,r29
	ctx.r11.s64 = ctx.r29.s16;
	// add. r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x82619f68
	if (!ctx.cr0.lt) goto loc_82619F68;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x82619f74
	goto loc_82619F74;
loc_82619F68:
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x82619f74
	if (!ctx.cr6.gt) goto loc_82619F74;
	// li r11,255
	ctx.r11.s64 = 255;
loc_82619F74:
	// stb r11,3(r10)
	REX_STORE_U8(ctx.r10.u32 + 3, ctx.r11.u8);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bdnz 0x82619ec8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82619EC8;
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + ctx.r30.u64;
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// bne 0x82619eb8
	if (!ctx.cr0.eq) goto loc_82619EB8;
	// b 0x8261a028
	goto loc_8261A028;
loc_82619F9C:
	// add r11,r27,r16
	ctx.r11.u64 = ctx.r27.u64 + ctx.r16.u64;
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// stb r22,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r22.u8);
	// bge cr6,0x82619fbc
	if (!ctx.cr6.lt) goto loc_82619FBC;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// b 0x82619fd8
	goto loc_82619FD8;
loc_82619FBC:
	// bne cr6,0x82619fcc
	if (!ctx.cr6.eq) goto loc_82619FCC;
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// b 0x82619fd4
	goto loc_82619FD4;
loc_82619FCC:
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
loc_82619FD4:
	// li r6,8
	ctx.r6.s64 = 8;
loc_82619FD8:
	// subf r7,r11,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// li r8,8
	ctx.r8.s64 = 8;
loc_82619FE4:
	// li r11,8
	ctx.r11.s64 = 8;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82619FF0:
	// lbzx r11,r7,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8261a004
	if (!ctx.cr6.lt) goto loc_8261A004;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// b 0x8261a010
	goto loc_8261A010;
loc_8261A004:
	// cmpwi cr6,r11,255
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 255, ctx.xer);
	// ble cr6,0x8261a010
	if (!ctx.cr6.gt) goto loc_8261A010;
	// li r11,255
	ctx.r11.s64 = 255;
loc_8261A010:
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82619ff0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82619FF0;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// bne 0x82619fe4
	if (!ctx.cr0.eq) goto loc_82619FE4;
loc_8261A028:
	// cmpwi cr6,r27,4
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 4, ctx.xer);
	// bge cr6,0x8261a04c
	if (!ctx.cr6.lt) goto loc_8261A04C;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// bne cr6,0x8261a044
	if (!ctx.cr6.eq) goto loc_8261A044;
	// addi r25,r25,120
	ctx.r25.s64 = ctx.r25.s64 + 120;
	// addi r23,r23,120
	ctx.r23.s64 = ctx.r23.s64 + 120;
	// b 0x8261a04c
	goto loc_8261A04C;
loc_8261A044:
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// addi r23,r23,8
	ctx.r23.s64 = ctx.r23.s64 + 8;
loc_8261A04C:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpwi cr6,r27,6
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 6, ctx.xer);
	// blt cr6,0x826195f4
	if (ctx.cr6.lt) goto loc_826195F4;
	// mr r9,r22
	ctx.r9.u64 = ctx.r22.u64;
	// addi r11,r1,1025
	ctx.r11.s64 = ctx.r1.s64 + 1025;
loc_8261A060:
	// li r8,4
	ctx.r8.s64 = 4;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8261A06C:
	// lwz r8,204(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// lbz r7,-1(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + -1);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lbz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r5,1(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r4,2(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// add r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stbx r7,r3,r14
	REX_STORE_U8(ctx.r3.u32 + ctx.r14.u32, ctx.r7.u8);
	// lwz r8,204(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r7,r8,r14
	ctx.r7.u64 = ctx.r8.u64 + ctx.r14.u64;
	// stb r6,1(r7)
	REX_STORE_U8(ctx.r7.u32 + 1, ctx.r6.u8);
	// lwz r6,204(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// mullw r8,r6,r9
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r3,r8,r14
	ctx.r3.u64 = ctx.r8.u64 + ctx.r14.u64;
	// stb r5,2(r3)
	REX_STORE_U8(ctx.r3.u32 + 2, ctx.r5.u8);
	// lwz r8,204(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r7,r8,r14
	ctx.r7.u64 = ctx.r8.u64 + ctx.r14.u64;
	// stb r4,3(r7)
	REX_STORE_U8(ctx.r7.u32 + 3, ctx.r4.u8);
	// bdnz 0x8261a06c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261A06C;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r9,16
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16, ctx.xer);
	// blt cr6,0x8261a060
	if (ctx.cr6.lt) goto loc_8261A060;
	// li r9,8
	ctx.r9.s64 = 8;
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8261A0F8:
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// addi r6,r1,129
	ctx.r6.s64 = ctx.r1.s64 + 129;
	// lbzx r5,r11,r8
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r8.u32);
	// addi r4,r1,193
	ctx.r4.s64 = ctx.r1.s64 + 193;
	// mullw r3,r9,r10
	ctx.r3.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lbzx r9,r11,r7
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r7.u32);
	// lbzx r6,r11,r6
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r6.u32);
	// lbzx r4,r11,r4
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// stbx r5,r3,r18
	REX_STORE_U8(ctx.r3.u32 + ctx.r18.u32, ctx.r5.u8);
	// lwz r21,208(r31)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r21,r21,r10
	ctx.r21.s64 = int64_t(ctx.r21.s32) * int64_t(ctx.r10.s32);
	// stbx r9,r21,r17
	REX_STORE_U8(ctx.r21.u32 + ctx.r17.u32, ctx.r9.u8);
	// addi r3,r1,130
	ctx.r3.s64 = ctx.r1.s64 + 130;
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r9,r9,r18
	ctx.r9.u64 = ctx.r9.u64 + ctx.r18.u64;
	// lbzx r3,r11,r3
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r3.u32);
	// addi r5,r1,194
	ctx.r5.s64 = ctx.r1.s64 + 194;
	// addi r30,r1,131
	ctx.r30.s64 = ctx.r1.s64 + 131;
	// addi r29,r1,195
	ctx.r29.s64 = ctx.r1.s64 + 195;
	// addi r28,r1,132
	ctx.r28.s64 = ctx.r1.s64 + 132;
	// stb r6,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r6.u8);
	// addi r27,r1,196
	ctx.r27.s64 = ctx.r1.s64 + 196;
	// lwz r6,208(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r6,r10
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// add r9,r9,r17
	ctx.r9.u64 = ctx.r9.u64 + ctx.r17.u64;
	// lbzx r5,r11,r5
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r5.u32);
	// lbzx r30,r11,r30
	ctx.r30.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// addi r26,r1,133
	ctx.r26.s64 = ctx.r1.s64 + 133;
	// lbzx r29,r11,r29
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r29.u32);
	// addi r25,r1,197
	ctx.r25.s64 = ctx.r1.s64 + 197;
	// lbzx r28,r11,r28
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r28.u32);
	// addi r24,r1,134
	ctx.r24.s64 = ctx.r1.s64 + 134;
	// lbzx r27,r11,r27
	ctx.r27.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// addi r23,r1,198
	ctx.r23.s64 = ctx.r1.s64 + 198;
	// stb r4,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r4.u8);
	// addi r22,r1,135
	ctx.r22.s64 = ctx.r1.s64 + 135;
	// lwz r6,208(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r6,r10
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// add r4,r9,r18
	ctx.r4.u64 = ctx.r9.u64 + ctx.r18.u64;
	// lbzx r26,r11,r26
	ctx.r26.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r26.u32);
	// lbzx r25,r11,r25
	ctx.r25.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r25.u32);
	// lbzx r24,r11,r24
	ctx.r24.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r24.u32);
	// lbzx r23,r11,r23
	ctx.r23.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r23.u32);
	// stb r3,2(r4)
	REX_STORE_U8(ctx.r4.u32 + 2, ctx.r3.u8);
	// lwz r3,208(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r3,r10
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// add r9,r9,r17
	ctx.r9.u64 = ctx.r9.u64 + ctx.r17.u64;
	// stb r5,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r5.u8);
	// lwz r6,208(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r6,r10
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// add r5,r9,r18
	ctx.r5.u64 = ctx.r9.u64 + ctx.r18.u64;
	// stb r30,3(r5)
	REX_STORE_U8(ctx.r5.u32 + 3, ctx.r30.u8);
	// lwz r4,208(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r4,r10
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// add r3,r9,r17
	ctx.r3.u64 = ctx.r9.u64 + ctx.r17.u64;
	// stb r29,3(r3)
	REX_STORE_U8(ctx.r3.u32 + 3, ctx.r29.u8);
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r6,r9,r18
	ctx.r6.u64 = ctx.r9.u64 + ctx.r18.u64;
	// stb r28,4(r6)
	REX_STORE_U8(ctx.r6.u32 + 4, ctx.r28.u8);
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r5,r10
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// add r4,r9,r17
	ctx.r4.u64 = ctx.r9.u64 + ctx.r17.u64;
	// stb r27,4(r4)
	REX_STORE_U8(ctx.r4.u32 + 4, ctx.r27.u8);
	// lwz r3,208(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r3,r10
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// add r9,r9,r18
	ctx.r9.u64 = ctx.r9.u64 + ctx.r18.u64;
	// stb r26,5(r9)
	REX_STORE_U8(ctx.r9.u32 + 5, ctx.r26.u8);
	// lwz r6,208(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r6,r10
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// add r5,r9,r17
	ctx.r5.u64 = ctx.r9.u64 + ctx.r17.u64;
	// stb r25,5(r5)
	REX_STORE_U8(ctx.r5.u32 + 5, ctx.r25.u8);
	// lwz r4,208(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r4,r10
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// add r3,r9,r18
	ctx.r3.u64 = ctx.r9.u64 + ctx.r18.u64;
	// stb r24,6(r3)
	REX_STORE_U8(ctx.r3.u32 + 6, ctx.r24.u8);
	// lwz r9,208(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r6,r9,r17
	ctx.r6.u64 = ctx.r9.u64 + ctx.r17.u64;
	// stb r23,6(r6)
	REX_STORE_U8(ctx.r6.u32 + 6, ctx.r23.u8);
	// lwz r5,208(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// addi r4,r1,199
	ctx.r4.s64 = ctx.r1.s64 + 199;
	// lbzx r3,r11,r22
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r22.u32);
	// mullw r9,r5,r10
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// lbzx r6,r11,r4
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r4.u32);
	// add r5,r9,r18
	ctx.r5.u64 = ctx.r9.u64 + ctx.r18.u64;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stb r3,7(r5)
	REX_STORE_U8(ctx.r5.u32 + 7, ctx.r3.u8);
	// lwz r4,208(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mullw r9,r4,r10
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// add r3,r9,r17
	ctx.r3.u64 = ctx.r9.u64 + ctx.r17.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r6,7(r3)
	REX_STORE_U8(ctx.r3.u32 + 7, ctx.r6.u8);
	// bdnz 0x8261a0f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8261A0F8;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8261A278:
	// addi r1,r1,1440
	ctx.r1.s64 = ctx.r1.s64 + 1440;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
loc_8261A280:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,1440
	ctx.r1.s64 = ctx.r1.s64 + 1440;
	// b 0x826a02b0
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266F7E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x8266F7E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8266f8c0
	if (ctx.cr6.eq) goto loc_8266F8C0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r30,-32049
	ctx.r30.s64 = -2100363264;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8266f81c
	if (ctx.cr6.eq) goto loc_8266F81C;
	// lwz r11,24460(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266F818;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
loc_8266F81C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82673730
	ctx.lr = 0x8266F824;
	sub_82673730(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8266f840
	if (ctx.cr6.eq) goto loc_8266F840;
	// lwz r11,24460(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266F83C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
loc_8266F840:
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8266f85c
	if (ctx.cr6.eq) goto loc_8266F85C;
	// lwz r11,24460(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266F858;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
loc_8266F85C:
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8266f878
	if (ctx.cr6.eq) goto loc_8266F878;
	// lwz r11,24460(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266F874;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
loc_8266F878:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8266f894
	if (ctx.cr6.eq) goto loc_8266F894;
	// lwz r11,24460(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266F890;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
loc_8266F894:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8266f8b0
	if (ctx.cr6.eq) goto loc_8266F8B0;
	// lwz r11,24460(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24460);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266F8AC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
loc_8266F8B0:
	// lwz r11,24460(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24460);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8266F8C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8266F8C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82672888) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x82672890;
	__savegprlr_27(ctx, base);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// bl 0x82671508
	ctx.lr = 0x826728B4;
	sub_82671508(ctx, base);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826727c8
	ctx.lr = 0x826728D0;
	sub_826727C8(ctx, base);
	// lwz r6,0(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x82672980
	if (!ctx.cr6.gt) goto loc_82672980;
	// rotlwi r10,r6,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// subf r8,r31,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r31.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lfs f10,4268(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4268);
	ctx.f10.f64 = double(temp.f32);
	// subf r7,r31,r29
	ctx.r7.u64 = ctx.r29.u64 - ctx.r31.u64;
	// lfs f9,2880(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2880);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,6380(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6380);
	ctx.f8.f64 = double(temp.f32);
loc_8267290C:
	// lwzx r9,r8,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// lfs f13,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f11,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fmsubs f13,f12,f10,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f10.f64, -ctx.f11.f64)));
	// fmuls f12,f0,f10
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f13,f9
	ctx.cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// beq cr6,0x8267294c
	if (ctx.cr6.eq) goto loc_8267294C;
	// fmuls f0,f13,f8
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fdivs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// b 0x82672950
	goto loc_82672950;
loc_8267294C:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_82672950:
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// fmadds f13,f0,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f13,f13,f0,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f0.f64, ctx.f11.f64)));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfsx f0,r7,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8267290c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267290C;
loc_82672980:
	// cmpwi cr6,r6,3
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 3, ctx.xer);
	// bgt cr6,0x826729c0
	if (ctx.cr6.gt) goto loc_826729C0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,36
	ctx.r10.s64 = 36;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// subf r9,r31,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r31.u64;
	// lfs f13,13280(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 13280);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_826729A4:
	// lfsu f12,28(r30)
	ctx.fpscr.disableFlushMode();
	ea = 28 + ctx.r30.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r30.u32 = ea;
	// stfsx f0,r11,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x826729a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826729A4;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
loc_826729C0:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82677388) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0280
	ctx.lr = 0x82677390;
	__savegprlr_22(ctx, base);
	// lwz r10,36(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r27,24(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r29,28(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r22,32(r3)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// beq cr6,0x826773bc
	if (ctx.cr6.eq) goto loc_826773BC;
	// li r29,1
	ctx.r29.s64 = 1;
	// li r27,1
	ctx.r27.s64 = 1;
loc_826773BC:
	// lwz r24,12(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// bne cr6,0x82677468
	if (!ctx.cr6.eq) goto loc_82677468;
	// divwu. r10,r10,r27
	ctx.r10.u64 = uint32_t(ctx.r27.u32 ? ctx.r10.u32 / ctx.r27.u32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82677538
	if (ctx.cr0.eq) goto loc_82677538;
	// lwz r30,8(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r28,r27,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r29,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
loc_826773DC:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82677454
	if (ctx.cr6.eq) goto loc_82677454;
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r3,r11,48
	ctx.r3.s64 = ctx.r11.s64 + 48;
	// addi r31,r8,108
	ctx.r31.s64 = ctx.r8.s64 + 108;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r7,r30,-4
	ctx.r7.s64 = ctx.r30.s64 + -4;
loc_826773FC:
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// ble cr6,0x8267742c
	if (!ctx.cr6.gt) goto loc_8267742C;
	// addi r6,r27,-1
	ctx.r6.s64 = ctx.r27.s64 + -1;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8267741C:
	// lfsu f13,4(r9)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r9.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r9.u32 = ea;
	// lfsu f12,4(r7)
	ea = 4 + ctx.r7.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r7.u32 = ea;
	// fmadds f0,f13,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f13.f64, ctx.f12.f64, ctx.f0.f64)));
	// bdnz 0x8267741c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267741C;
loc_8267742C:
	// dcbt r0,r3
	// dcbt r0,r31
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82677444
	if (ctx.cr6.eq) goto loc_82677444;
	// lfs f13,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
loc_82677444:
	// stfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// bne 0x826773fc
	if (!ctx.cr0.eq) goto loc_826773FC;
loc_82677454:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// add r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 + ctx.r8.u64;
	// bne 0x826773dc
	if (!ctx.cr0.eq) goto loc_826773DC;
	// b 0x82677538
	goto loc_82677538;
loc_82677468:
	// divwu. r23,r10,r27
	ctx.r23.u64 = uint32_t(ctx.r27.u32 ? ctx.r10.u32 / ctx.r27.u32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// beq 0x82677538
	if (ctx.cr0.eq) goto loc_82677538;
	// lwz r28,8(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r26,r27,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r29,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
loc_82677480:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82677524
	if (ctx.cr6.eq) goto loc_82677524;
	// clrldi r10,r7,32
	ctx.r10.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// lfs f10,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
	// std r10,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.r10.u64);
	// lfd f0,-96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r30,r8,108
	ctx.r30.s64 = ctx.r8.s64 + 108;
	// frsp f11,f0
	ctx.f11.f64 = double(float(ctx.f0.f64));
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r10,r24,-4
	ctx.r10.s64 = ctx.r24.s64 + -4;
	// addi r9,r28,-4
	ctx.r9.s64 = ctx.r28.s64 + -4;
loc_826774B8:
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f13,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fmadds f0,f0,f11,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f11.f64, ctx.f13.f64)));
	// cmplwi cr6,r27,1
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 1, ctx.xer);
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// ble cr6,0x826774fc
	if (!ctx.cr6.gt) goto loc_826774FC;
	// addi r5,r27,-1
	ctx.r5.s64 = ctx.r27.s64 + -1;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_826774E4:
	// lfsu f13,4(r10)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// lfsu f12,4(r9)
	ea = 4 + ctx.r9.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r9.u32 = ea;
	// fmadds f12,f13,f11,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f13.f64, ctx.f11.f64, ctx.f12.f64)));
	// lfsu f13,4(r6)
	ea = 4 + ctx.r6.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r6.u32 = ea;
	// fmadds f0,f12,f13,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
	// bdnz 0x826774e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826774E4;
loc_826774FC:
	// dcbt r0,r31
	// dcbt r0,r30
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82677514
	if (ctx.cr6.eq) goto loc_82677514;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
loc_82677514:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// addic. r3,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x826774b8
	if (!ctx.cr0.eq) goto loc_826774B8;
loc_82677524:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// add r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 + ctx.r8.u64;
	// cmplw cr6,r7,r23
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x82677480
	if (ctx.cr6.lt) goto loc_82677480;
loc_82677538:
	// b 0x826a02d0
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8267F580) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a027c
	ctx.lr = 0x8267F588;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mulli r11,r3,96
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(96));
	// addi r10,r11,143
	ctx.r10.s64 = ctx.r11.s64 + 143;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// mr r21,r6
	ctx.r21.u64 = ctx.r6.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r31,r10,0,0,24
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8267f5dc
	if (ctx.cr6.eq) goto loc_8267F5DC;
	// addi r10,r4,-8
	ctx.r10.s64 = ctx.r4.s64 + -8;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
loc_8267F5BC:
	// lbz r8,16(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 16);
	// lwzu r9,12(r10)
	ea = 12 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// rotlwi r6,r8,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// rotlwi r8,r8,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bdnz 0x8267f5bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267F5BC;
loc_8267F5DC:
	// add r29,r11,r31
	ctx.r29.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8267f688
	if (ctx.cr6.eq) goto loc_8267F688;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
loc_8267F5EC:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// subf r29,r31,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r31.u64;
	// bl 0x824b2438
	ctx.lr = 0x8267F600;
	sub_824B2438(ctx, base);
	// addi r10,r28,16
	ctx.r10.s64 = ctx.r28.s64 + 16;
	// stw r30,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// add r26,r31,r28
	ctx.r26.u64 = ctx.r31.u64 + ctx.r28.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r10.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8267f638
	if (!ctx.cr6.gt) goto loc_8267F638;
	// addi r10,r29,-1
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8267F62C:
	// dcbf r11,r26
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// bdnz 0x8267f62c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267F62C;
loc_8267F638:
	// rlwinm. r23,r22,0,29,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// stw r22,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r22.u32);
	// oris r11,r22,2
	ctx.r11.u64 = ctx.r22.u64 | 131072;
	// bne 0x8267f64c
	if (!ctx.cr0.eq) goto loc_8267F64C;
	// oris r11,r22,3
	ctx.r11.u64 = ctx.r22.u64 | 196608;
loc_8267F64C:
	// stw r11,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8267f7f8
	if (ctx.cr6.eq) goto loc_8267F7F8;
	// addi r29,r27,8
	ctx.r29.s64 = ctx.r27.s64 + 8;
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// li r27,1
	ctx.r27.s64 = 1;
loc_8267F668:
	// lwz r11,8(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// add r31,r25,r11
	ctx.r31.u64 = ctx.r25.u64 + ctx.r11.u64;
	// stw r26,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r26.u32);
	// lwz r11,-8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -8);
	// cmplwi cr6,r11,24000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 24000, ctx.xer);
	// bgt cr6,0x8267f6a8
	if (ctx.cr6.gt) goto loc_8267F6A8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8267f6d0
	goto loc_8267F6D0;
loc_8267F688:
	// lis r4,-22633
	ctx.r4.s64 = -1483276288;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x824c64b8
	ctx.lr = 0x8267F694;
	sub_824C64B8(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x8267f5ec
	if (!ctx.cr0.eq) goto loc_8267F5EC;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8267f860
	goto loc_8267F860;
loc_8267F6A8:
	// cmplwi cr6,r11,32000
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32000, ctx.xer);
	// bgt cr6,0x8267f6b8
	if (ctx.cr6.gt) goto loc_8267F6B8;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// b 0x8267f6d0
	goto loc_8267F6D0;
loc_8267F6B8:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,44100
	ctx.r10.u64 = ctx.r10.u64 | 44100;
	// subfc r11,r11,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
loc_8267F6D0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r9,r11,5,30,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0x3;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8267f6ec
	if (ctx.cr6.eq) goto loc_8267F6EC;
	// rlwimi r11,r10,27,3,4
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x18000000) | (ctx.r11.u64 & 0xFFFFFFFFE7FFFFFF);
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8267F6EC:
	// lbz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r11,3,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8267f710
	if (ctx.cr6.eq) goto loc_8267F710;
	// rlwimi r11,r10,29,2,2
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x20000000) | (ctx.r11.u64 & 0xFFFFFFFFDFFFFFFF);
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8267F710:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r10,1(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 1);
	// rlwinm r9,r11,12,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xF;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8267f730
	if (ctx.cr6.eq) goto loc_8267F730;
	// rlwimi r11,r10,20,8,11
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xF00000) | (ctx.r11.u64 & 0xFFFFFFFFFF0FFFFF);
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8267F730:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826cd2f4
	ctx.lr = 0x8267F738;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8267f754
	if (ctx.cr6.eq) goto loc_8267F754;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x826cd2f4
	ctx.lr = 0x8267F74C;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r27,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r27.u32);
loc_8267F754:
	// lwz r9,-4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + -4);
	// lbz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r11,17,20,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xF80;
	// rlwinm r8,r10,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8267f780
	if (ctx.cr6.eq) goto loc_8267F780;
	// rlwimi r11,r10,15,5,9
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x7C00000) | (ctx.r11.u64 & 0xFFFFFFFFF83FFFFF);
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_8267F780:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// rlwinm r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8267f7a0
	if (ctx.cr6.eq) goto loc_8267F7A0;
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r27,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r27.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_8267F7A0:
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// lwz r10,-4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + -4);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r30,r11,r26
	ctx.r30.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r30,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826cd2f4
	ctx.lr = 0x8267F7C0;
	__imp__MmGetPhysicalAddress(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8267f7dc
	if (ctx.cr6.eq) goto loc_8267F7DC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826cd2f4
	ctx.lr = 0x8267F7D4;
	__imp__MmGetPhysicalAddress(ctx, base);
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r27,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r27.u32);
loc_8267F7DC:
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r25,r25,96
	ctx.r25.s64 = ctx.r25.s64 + 96;
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// addi r29,r29,12
	ctx.r29.s64 = ctx.r29.s64 + 12;
	// add r26,r11,r30
	ctx.r26.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bne 0x8267f668
	if (!ctx.cr0.eq) goto loc_8267F668;
loc_8267F7F8:
	// clrlwi. r11,r22,31
	ctx.r11.u64 = ctx.r22.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8267f820
	if (!ctx.cr0.eq) goto loc_8267F820;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8267e8d0
	ctx.lr = 0x8267F808;
	sub_8267E8D0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge 0x8267f820
	if (!ctx.cr0.lt) goto loc_8267F820;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8267f380
	ctx.lr = 0x8267F818;
	sub_8267F380(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8267f860
	goto loc_8267F860;
loc_8267F820:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8267f858
	if (ctx.cr6.eq) goto loc_8267F858;
	// lis r11,-32127
	ctx.r11.s64 = -2105475072;
	// addi r31,r11,-15472
	ctx.r31.s64 = ctx.r11.s64 + -15472;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826ccc44
	ctx.lr = 0x8267F838;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,8(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lis r11,-32049
	ctx.r11.s64 = -2100363264;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,24608
	ctx.r11.s64 = ctx.r11.s64 + 24608;
	// lhz r10,80(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 80);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r28,r10,r11
	REX_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r28.u32);
	// bl 0x826ccc54
	ctx.lr = 0x8267F858;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8267F858:
	// stw r28,0(r21)
	REX_STORE_U32(ctx.r21.u32 + 0, ctx.r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8267F860:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x826a02cc
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8268C3C0) {
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
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// lwz r3,20(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// rlwinm. r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// beq 0x8268c424
	if (ctx.cr0.eq) goto loc_8268C424;
	// add r8,r3,r5
	ctx.r8.u64 = ctx.r3.u64 + ctx.r5.u64;
loc_8268C404:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8268c424
	if (!ctx.cr0.eq) goto loc_8268C424;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8268c404
	if (!ctx.cr6.eq) goto loc_8268C404;
loc_8268C424:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8268c444
	if (ctx.cr0.eq) goto loc_8268C444;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x826a1130
	ctx.lr = 0x8268C434;
	rexcrt_memcpy(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8267f908
	ctx.lr = 0x8268C440;
	sub_8267F908(ctx, base);
	// b 0x8268c448
	goto loc_8268C448;
loc_8268C444:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8268C448:
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

DEFINE_REX_FUNC(sub_82690040) {
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
	// lwz r11,556(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 556);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// b 0x82690074
	goto loc_82690074;
loc_82690064:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8269007c
	if (ctx.cr6.eq) goto loc_8269007C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_82690074:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82690064
	if (!ctx.cr6.eq) goto loc_82690064;
loc_8269007C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82690090
	if (ctx.cr6.eq) goto loc_82690090;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r31,352
	ctx.r3.s64 = ctx.r31.s64 + 352;
	// bl 0x826867f0
	ctx.lr = 0x82690090;
	sub_826867F0(ctx, base);
loc_82690090:
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// b 0x826900a8
	goto loc_826900A8;
loc_82690098:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x826900b0
	if (ctx.cr6.eq) goto loc_826900B0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_826900A8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82690098
	if (!ctx.cr6.eq) goto loc_82690098;
loc_826900B0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826900c4
	if (ctx.cr6.eq) goto loc_826900C4;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r31,132
	ctx.r3.s64 = ctx.r31.s64 + 132;
	// bl 0x826867f0
	ctx.lr = 0x826900C4;
	sub_826867F0(ctx, base);
loc_826900C4:
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

DEFINE_REX_FUNC(sub_82692200) {
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
	// bl 0x82691d88
	ctx.lr = 0x82692220;
	sub_82691D88(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82692230
	if (ctx.cr0.eq) goto loc_82692230;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826888c0
	ctx.lr = 0x82692230;
	sub_826888C0(ctx, base);
loc_82692230:
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

DEFINE_REX_FUNC(sub_82692FB0) {
	REX_FUNC_PROLOGUE();
	// li r3,256
	ctx.r3.s64 = 256;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82693190) {
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
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// bl 0x82692e50
	ctx.lr = 0x826931A4;
	sub_82692E50(ctx, base);
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

DEFINE_REX_FUNC(sub_82695B90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lhz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// std r8,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,7680(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7680);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82697538) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r4,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r5,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r6,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lfs f0,2880(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2880);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82697D90) {
	REX_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82698030) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8269e118
	ctx.lr = 0x8269804C;
	sub_8269E118(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// blt 0x82698198
	if (ctx.cr0.lt) goto loc_82698198;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,124(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8268f070
	ctx.lr = 0x8269806C;
	sub_8268F070(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82698198
	if (ctx.cr0.lt) goto loc_82698198;
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82697790
	ctx.lr = 0x8269807C;
	sub_82697790(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82698198
	if (ctx.cr0.lt) goto loc_82698198;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8268f2a0
	ctx.lr = 0x82698090;
	sub_8268F2A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82698124
	if (ctx.cr0.eq) goto loc_82698124;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// lwz r9,48(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 48);
	// lhz r10,12(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 12);
	// divwu r4,r11,r10
	ctx.r4.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826980C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
	// lwz r3,132(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826980E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,128(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// lis r9,-32049
	ctx.r9.s64 = -2100363264;
	// lhz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r9,24480
	ctx.r3.s64 = ctx.r9.s64 + 24480;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// mullw r4,r11,r10
	ctx.r4.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// bl 0x8267b598
	ctx.lr = 0x82698108;
	sub_8267B598(ctx, base);
	// stw r3,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82698124
	if (ctx.cr0.eq) goto loc_82698124;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r30,44(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82698130
	if (!ctx.cr6.eq) goto loc_82698130;
loc_82698124:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82698198
	goto loc_82698198;
loc_82698130:
	// lwz r3,132(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82698144;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// lwz r10,128(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,44(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,52(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// lhz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r8.u32 + 12);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// divwu r11,r11,r8
	ctx.r11.u64 = uint32_t(ctx.r8.u32 ? ctx.r11.u32 / ctx.r8.u32 : 0);
	// stw r30,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// twllei r8,0
	if (ctx.r8.s32 == 0 || ctx.r8.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82698198;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82698198:
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

DEFINE_REX_FUNC(__savegprlr_21) {
	REX_FUNC_PROLOGUE();
	// std r21,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(__restgprlr_20) {
	REX_FUNC_PROLOGUE();
	// ld r20,-104(r1)
	ctx.r20.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(__savefpr_22) {
	REX_FUNC_PROLOGUE();
	// stfd f22,-80(r12)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	REX_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	REX_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	REX_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	REX_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	REX_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	REX_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	REX_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	REX_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	REX_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826A0DE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x826A0DF0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stfd f1,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.f1.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x826a9b60
	ctx.lr = 0x826A0E10;
	sub_826A9B60(ctx, base);
	// lis r10,-16377
	ctx.r10.s64 = -1073283072;
	// lis r11,-32127
	ctx.r11.s64 = -2105475072;
	// ori r28,r10,65279
	ctx.r28.u64 = ctx.r10.u64 | 65279;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,-7504(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -7504);
	// bl 0x826a9b60
	ctx.lr = 0x826A0E2C;
	sub_826A9B60(ctx, base);
	// lhz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 160);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// rlwinm r10,r11,0,17,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF0;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi cr6,r10,32752
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32752, ctx.xer);
	// bne cr6,0x826a0ec8
	if (!ctx.cr6.eq) goto loc_826A0EC8;
	// lis r11,-32127
	ctx.r11.s64 = -2105475072;
	// lfd f0,-5776(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -5776);
	// stfd f0,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f0.u64);
	// bl 0x826a99d8
	ctx.lr = 0x826A0E54;
	sub_826A99D8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x826a0ea0
	if (!ctx.cr0.gt) goto loc_826A0EA0;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x826a0e84
	if (!ctx.cr6.gt) goto loc_826A0E84;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x826a0ea0
	if (!ctx.cr6.eq) goto loc_826A0EA0;
	// stfd f31,0(r31)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f31.u64);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x826a96d0
	ctx.lr = 0x826A0E80;
	sub_826A96D0(ctx, base);
	// b 0x826a0f0c
	goto loc_826A0F0C;
loc_826A0E84:
	// stfd f31,0(r31)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f31.u64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// lfd f1,14704(r11)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r11.u32 + 14704);
	// bl 0x826a29f8
	ctx.lr = 0x826A0E98;
	sub_826A29F8(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// b 0x826a0efc
	goto loc_826A0EFC;
loc_826A0EA0:
	// lis r11,-32248
	ctx.r11.s64 = -2113404928;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r4,28
	ctx.r4.s64 = 28;
	// li r3,8
	ctx.r3.s64 = 8;
	// lfd f0,-2368(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + -2368);
	// fadd f2,f31,f0
	ctx.f2.f64 = ctx.f31.f64 + ctx.f0.f64;
	// stfd f2,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f2.u64);
	// bl 0x826a97d8
	ctx.lr = 0x826A0EC4;
	sub_826A97D8(ctx, base);
	// b 0x826a0f0c
	goto loc_826A0F0C;
loc_826A0EC8:
	// bl 0x826a8e90
	ctx.lr = 0x826A0ECC;
	sub_826A8E90(ctx, base);
	// fsub f31,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f31.f64 - ctx.f1.f64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stfd f1,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.f1.u64);
	// stfd f31,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f31.u64);
	// lfd f0,14704(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 14704);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bne cr6,0x826a0efc
	if (!ctx.cr6.eq) goto loc_826A0EFC;
	// lhz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// rlwinm r10,r29,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x8000;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// lfd f31,80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_826A0EFC:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826a9b60
	ctx.lr = 0x826A0F08;
	sub_826A9B60(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_826A0F0C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(__savevmx_117) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__restvmx_25) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(__restvmx_77) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v77.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v78.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v79.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v80.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v81.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v82.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v83.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v84.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v85.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v86.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v87.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v88.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v89.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v90.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v91.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v92.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v93.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v94.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v95.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v96.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v97.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v98.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v99.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v100.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v101.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v102.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v103.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v104.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v105.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v106.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v107.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v108.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v109.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v110.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v111.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v112.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v113.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v114.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v115.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v116.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v117.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v118.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v119.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_826ABFD4) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-160
	ctx.r31.s64 = ctx.r12.s64 + -160;
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
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b2748
	ctx.lr = 0x826ABFF4;
	sub_826B2748(ctx, base);
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

DEFINE_REX_FUNC(sub_826AF200) {
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
	// bl 0x826a5ed0
	ctx.lr = 0x826AF214;
	sub_826A5ED0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x826af23c
	if (ctx.cr0.eq) goto loc_826AF23C;
	// lwz r3,68(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826af250
	if (!ctx.cr6.eq) goto loc_826AF250;
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x826a2768
	ctx.lr = 0x826AF230;
	sub_826A2768(ctx, base);
	// stw r3,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x826af250
	if (!ctx.cr0.eq) goto loc_826AF250;
loc_826AF23C:
	// bl 0x826a9e30
	ctx.lr = 0x826AF240;
	sub_826A9E30(ctx, base);
	// li r10,12
	ctx.r10.s64 = 12;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_826AF250:
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

DEFINE_REX_FUNC(sub_826B2010) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32048
	ctx.r10.s64 = -2100297728;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,17572(r10)
	REX_STORE_U32(ctx.r10.u32 + 17572, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826B24E0) {
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
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x826b2548
	if (ctx.cr6.lt) goto loc_826B2548;
	// lis r11,-32048
	ctx.r11.s64 = -2100297728;
	// lwz r11,17576(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 17576);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x826b2548
	if (!ctx.cr6.lt) goto loc_826B2548;
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32048
	ctx.r10.s64 = -2100297728;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,17600
	ctx.r10.s64 = ctx.r10.s64 + 17600;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(72));
	// lwzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x826b2548
	if (ctx.cr0.eq) goto loc_826B2548;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x826b2548
	if (ctx.cr6.eq) goto loc_826B2548;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x826b2564
	goto loc_826B2564;
loc_826B2548:
	// bl 0x826a9e30
	ctx.lr = 0x826B254C;
	sub_826A9E30(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x826a9e68
	ctx.lr = 0x826B2558;
	sub_826A9E68(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_826B2564:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826B71A8) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x824c64b8
	ctx.lr = 0x826B71D0;
	sub_824C64B8(ctx, base);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x826b71e8
	if (!ctx.cr0.eq) goto loc_826B71E8;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x826b71f0
	goto loc_826B71F0;
loc_826B71E8:
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_826B71F0:
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

DEFINE_REX_FUNC(sub_826B8190) {
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
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// rlwinm. r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826b81c4
	if (ctx.cr0.eq) goto loc_826B81C4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// subf r11,r6,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r6.u64;
loc_826B81B0:
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,0,r10
	REX_STORE_U32(ctx.r10.u32, ctx.f0.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826b81b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826B81B0;
loc_826B81C4:
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// bl 0x824e3c70
	ctx.lr = 0x826B81CC;
	sub_824E3C70(ctx, base);
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

DEFINE_REX_FUNC(sub_826BB768) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a028c
	ctx.lr = 0x826BB770;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r10,10(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x826bb98c
	if (ctx.cr0.eq) goto loc_826BB98C;
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// lis r4,9345
	ctx.r4.s64 = 612433920;
	// rotlwi r3,r11,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// bl 0x824c64b8
	ctx.lr = 0x826BB798;
	sub_824C64B8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// bne 0x826bb7b0
	if (!ctx.cr0.eq) goto loc_826BB7B0;
loc_826BB7A4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x826bb990
	goto loc_826BB990;
loc_826BB7B0:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r11,10(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// bl 0x826a03b0
	ctx.lr = 0x826BB7C4;
	rexcrt_memset(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// addi r10,r1,92
	ctx.r10.s64 = ctx.r1.s64 + 92;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r25,32(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
loc_826BB7D8:
	// lwzu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x826bb7d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826BB7D8;
	// lwz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lhz r10,10(r9)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + 10);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// rotlwi r8,r10,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x826bb814
	if (!ctx.cr6.gt) goto loc_826BB814;
loc_826BB808:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x826bb990
	goto loc_826BB990;
loc_826BB814:
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
	// beq cr6,0x826bb98c
	if (ctx.cr6.eq) goto loc_826BB98C;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
loc_826BB830:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// lwz r9,12(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x826bb808
	if (ctx.cr6.gt) goto loc_826BB808;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// stw r26,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r26.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r26,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r26.u32);
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x826b7548
	ctx.lr = 0x826BB870;
	sub_826B7548(ctx, base);
	// lhz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 12);
	// lhz r10,10(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 10);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhz r11,102(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r9,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r9,4(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r9,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// lhz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// sth r9,104(r1)
	REX_STORE_U16(ctx.r1.u32 + 104, ctx.r9.u16);
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x826bb8d0
	if (!ctx.cr6.gt) goto loc_826BB8D0;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// xoris r9,r26,32768
	ctx.r9.u64 = ctx.r26.u64 ^ 2147483648;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addc r11,r11,r9
	ctx.xer.ca = ctx.r11.u32 + ctx.r9.u32 < ctx.r11.u32;
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// sth r11,104(r1)
	REX_STORE_U16(ctx.r1.u32 + 104, ctx.r11.u16);
loc_826BB8D0:
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x826bb400
	ctx.lr = 0x826BB8E4;
	sub_826BB400(ctx, base);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stwx r3,r28,r11
	REX_STORE_U32(ctx.r28.u32 + ctx.r11.u32, ctx.r3.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwzx r10,r28,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x826bb7a4
	if (ctx.cr6.eq) goto loc_826BB7A4;
	// lhz r10,102(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// lhz r8,104(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 104);
	// lhz r9,100(r1)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r1.u32 + 100);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// sth r10,102(r1)
	REX_STORE_U16(ctx.r1.u32 + 102, ctx.r10.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq 0x826bb920
	if (ctx.cr0.eq) goto loc_826BB920;
	// li r10,4
	ctx.r10.s64 = 4;
loc_826BB920:
	// lwzx r8,r28,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lhz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// lwz r7,112(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r8,44(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 44);
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x826bb954
	if (ctx.cr6.eq) goto loc_826BB954;
	// li r10,4
	ctx.r10.s64 = 4;
loc_826BB954:
	// lwzx r11,r28,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lhz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 8);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// lwz r8,24(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// lhz r9,10(r8)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r8.u32 + 10);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r27,r9
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r9.u32, ctx.xer);
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// blt cr6,0x826bb830
	if (ctx.cr6.lt) goto loc_826BB830;
loc_826BB98C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BB990:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x826a02dc
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C7248) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32238
	ctx.r11.s64 = -2112749568;
	// addi r3,r11,20752
	ctx.r3.s64 = ctx.r11.s64 + 20752;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826C75F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a029c
	ctx.lr = 0x826C75F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,1452(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 1452);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r4,964
	ctx.r4.s64 = 964;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826bdf80
	ctx.lr = 0x826C7614;
	sub_826BDF80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r3,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r3.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// beq 0x826c7634
	if (ctx.cr0.eq) goto loc_826C7634;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x826c6ee0
	ctx.lr = 0x826C7630;
	sub_826C6EE0(ctx, base);
	// b 0x826c7638
	goto loc_826C7638;
loc_826C7634:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C7638:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x826a02ec
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826C8190) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
loc_826C8198:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = REX_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpwi cr7,r6,0
	ctx.cr7.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// subf. r3,r6,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr7,0x826c81e0
	if (ctx.cr7.eq) goto loc_826C81E0;
	// beq 0x826c8198
	if (ctx.cr0.eq) goto loc_826C8198;
	// cmpwi cr5,r6,65
	ctx.cr5.compare<int32_t>(ctx.r6.s32, 65, ctx.xer);
	// cmpwi cr6,r6,90
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 90, ctx.xer);
	// blt cr5,0x826c81c4
	if (ctx.cr5.lt) goto loc_826C81C4;
	// bgt cr6,0x826c81c4
	if (ctx.cr6.gt) goto loc_826C81C4;
	// ori r6,r6,32
	ctx.r6.u64 = ctx.r6.u64 | 32;
loc_826C81C4:
	// cmpwi r5,65
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 65, ctx.xer);
	// cmpwi cr1,r5,90
	ctx.cr1.compare<int32_t>(ctx.r5.s32, 90, ctx.xer);
	// blt 0x826c81d8
	if (ctx.cr0.lt) goto loc_826C81D8;
	// bgt cr1,0x826c81d8
	if (ctx.cr1.gt) goto loc_826C81D8;
	// ori r5,r5,32
	ctx.r5.u64 = ctx.r5.u64 | 32;
loc_826C81D8:
	// subf. r3,r6,r5
	ctx.r3.u64 = ctx.r5.u64 - ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x826c8198
	if (ctx.cr0.eq) goto loc_826C8198;
loc_826C81E0:
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826CAE80) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32147
	ctx.r11.s64 = -2106785792;
	// addi r3,r11,-14744
	ctx.r3.s64 = ctx.r11.s64 + -14744;
	// b 0x826a2360
	sub_826A2360(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826CB5D0) {
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
	// lis r11,-32049
	ctx.r11.s64 = -2100363264;
	// addi r3,r11,24276
	ctx.r3.s64 = ctx.r11.s64 + 24276;
	// bl 0x82664988
	ctx.lr = 0x826CB5E8;
	sub_82664988(ctx, base);
	// lis r11,-32147
	ctx.r11.s64 = -2106785792;
	// addi r3,r11,-13944
	ctx.r3.s64 = ctx.r11.s64 + -13944;
	// bl 0x826a2360
	ctx.lr = 0x826CB5F4;
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

DEFINE_REX_FUNC(sub_826CC1E8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32099
	ctx.r11.s64 = -2103640064;
	// addi r11,r11,-28544
	ctx.r11.s64 = ctx.r11.s64 + -28544;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826D2960) {
	REX_FUNC_PROLOGUE();
	// lwz r10,1368(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 1368);
	// srawi r9,r4,16
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 16;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,256
	ctx.r9.s64 = ctx.r10.s64 + 256;
	// addi r6,r8,-1
	ctx.r6.s64 = ctx.r8.s64 + -1;
	// rlwinm r4,r9,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// addi r6,r5,64
	ctx.r6.s64 = ctx.r5.s64 + 64;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// cmplwi cr6,r3,128
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 128, ctx.xer);
	// blt cr6,0x826d2a50
	if (ctx.cr6.lt) goto loc_826D2A50;
	// cmplwi cr6,r9,512
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 512, ctx.xer);
	// blt cr6,0x826d29dc
	if (ctx.cr6.lt) goto loc_826D29DC;
	// lhz r8,62(r11)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r11.u32 + 62);
	// neg r4,r8
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// subf r7,r4,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r3,r9,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r9.u64;
	// xor r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// srawi r8,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 31;
	// srawi r7,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 31;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// and r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 & ctx.r4.u64;
	// andc r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// or r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 | ctx.r7.u64;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// b 0x826d29ec
	goto loc_826D29EC;
loc_826D29DC:
	// lwz r10,1476(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1476);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r10,r9
	ctx.r8.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
loc_826D29EC:
	// cmplwi cr6,r6,128
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 128, ctx.xer);
	// blt cr6,0x826d2a38
	if (ctx.cr6.lt) goto loc_826D2A38;
	// lhz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 64);
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r10,-2
	ctx.r11.s64 = ctx.r10.s64 + -2;
	// neg r7,r10
	ctx.r7.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// subf r6,r11,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r5,r7,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r7.u64;
	// xor r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// srawi r10,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 31;
	// srawi r9,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 31;
	// and r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 & ctx.r8.u64;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// and r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 & ctx.r7.u64;
	// andc r4,r11,r6
	ctx.r4.u64 = ctx.r11.u64 & ~ctx.r6.u64;
	// or r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 | ctx.r8.u64;
	// rlwimi r3,r11,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// blr 
	return;
loc_826D2A38:
	// lwz r11,1468(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1468);
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// rlwimi r3,r11,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// blr 
	return;
loc_826D2A50:
	// lwz r10,1476(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 1476);
	// rlwinm r7,r6,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,1468(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 1468);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r10,r9
	ctx.r6.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// lhzx r5,r8,r7
	ctx.r5.u64 = REX_LOAD_U16(ctx.r8.u32 + ctx.r7.u32);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// rlwimi r3,r11,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826EEF50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0294
	ctx.lr = 0x826EEF58;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltish v0,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_set1_epi16(short(0x2)));
	// li r11,1120
	ctx.r11.s64 = 1120;
	// vspltish v13,8
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x8)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// vspltish v12,6
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0x6)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r31,1164(r6)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + 1164);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// vslh v11,v13,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v10,r6,r11
	ea = (ctx.r6.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubshs v9,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stvx128 v12,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stvx128 v9,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826e8a98
	ctx.lr = 0x826EEFBC;
	sub_826E8A98(ctx, base);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vspltish v8,-1
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_set1_epi16(short(0xFFFF)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// vspltisb v7,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_set1_epi8(char(0x0)));
	// clrlwi r11,r28,31
	ctx.r11.u64 = ctx.r28.u32 & 0x1;
	// vspltish v6,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_set1_epi16(short(0x1)));
	// li r5,1
	ctx.r5.s64 = 1;
	// vspltish v12,4
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0x4)));
	// addi r4,r11,3
	ctx.r4.s64 = ctx.r11.s64 + 3;
	// vspltish v5,5
	simde_mm_store_si128((simde__m128i*)ctx.v5.s16, simde_mm_set1_epi16(short(0x5)));
	// lvx128 v4,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// vslh v2,v8,v4
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v8.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v2.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltish v8,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_set1_epi16(short(0x0)));
	// slw r9,r5,r4
	ctx.r9.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r4.u8 & 0x3F));
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x826ef0b8
	if (!ctx.cr6.eq) goto loc_826EF0B8;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826ef1b0
	if (!ctx.cr6.gt) goto loc_826EF1B0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,4
	ctx.r8.s64 = 4;
loc_826EF01C:
	// lvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v9,v13,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsldoi128 v11,v13,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 14));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vsldoi128 v10,v13,v63,4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 12));
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// vsldoi128 v13,v13,v63,6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), 10));
	// vsubshs v4,v7,v9
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// lvx128 v3,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v1,v11,v5
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v31,v11,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v30,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v29,v11,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v28,v10,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v27,v10,v6
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v26,v31,v1
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.u16), simde_mm_load_si128((simde__m128i*)ctx.v1.u16)));
	// vadduhm v25,v29,v11
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// vslh v24,v13,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v23,v27,v28
	simde_mm_store_si128((simde__m128i*)ctx.v23.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vadduhm v22,v25,v26
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vsubshs v21,v13,v24
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// vadduhm v20,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.u16), simde_mm_load_si128((simde__m128i*)ctx.v23.u16)));
	// vadduhm v19,v21,v4
	simde_mm_store_si128((simde__m128i*)ctx.v19.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vadduhm v18,v20,v3
	simde_mm_store_si128((simde__m128i*)ctx.v18.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.u16), simde_mm_load_si128((simde__m128i*)ctx.v3.u16)));
	// vadduhm v17,v18,v19
	simde_mm_store_si128((simde__m128i*)ctx.v17.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.u16), simde_mm_load_si128((simde__m128i*)ctx.v19.u16)));
	// vsrah v16,v17,v30
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v17.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vpkshus128 v62,v16,v16
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vor v8,v8,v16
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v16.u8)));
	// stvewx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v62,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bdnz 0x826ef01c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826EF01C;
	// vand v0,v8,v2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// li r3,0
	ctx.r3.s64 = 0;
	// vcmpgtuh. v13,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), 0xFFFF);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
loc_826EF0B8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826ef1b0
	if (!ctx.cr6.gt) goto loc_826EF1B0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r10,r31,32
	ctx.r10.s64 = ctx.r31.s64 + 32;
	// li r9,-32
	ctx.r9.s64 = -32;
	// li r8,-16
	ctx.r8.s64 = -16;
loc_826EF0D0:
	// lvx128 v13,r10,r8
	ea = (ctx.r10.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v11,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v1,v13,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi v10,v11,v13,2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8), 14));
	// vsldoi128 v9,v13,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), 14));
	// vslh v31,v11,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsldoi v4,v11,v13,4
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8), 12));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vsldoi128 v3,v13,v61,4
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), 12));
	// vsubshs v30,v7,v1
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vslh v29,v10,v5
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsldoi v11,v11,v13,6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8), 10));
	// vslh v28,v9,v5
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v5.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsldoi128 v13,v13,v61,6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), 10));
	// vslh v27,v10,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// vslh v26,v10,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v25,v9,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v24,v9,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v21,v27,v29
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v29.u16)));
	// vadduhm v20,v26,v10
	simde_mm_store_si128((simde__m128i*)ctx.v20.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vslh v23,v4,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v22,v4,v6
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v4.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v19,v3,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v17,v25,v28
	simde_mm_store_si128((simde__m128i*)ctx.v17.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.u16), simde_mm_load_si128((simde__m128i*)ctx.v28.u16)));
	// vadduhm v16,v24,v9
	simde_mm_store_si128((simde__m128i*)ctx.v16.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vslh v18,v3,v6
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v3.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v6.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v15,v13,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v15.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v10,v22,v23
	simde_mm_store_si128((simde__m128i*)ctx.v10.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.u16), simde_mm_load_si128((simde__m128i*)ctx.v23.u16)));
	// vadduhm v9,v20,v21
	simde_mm_store_si128((simde__m128i*)ctx.v9.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.u16), simde_mm_load_si128((simde__m128i*)ctx.v21.u16)));
	// vadduhm v4,v18,v19
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.u16), simde_mm_load_si128((simde__m128i*)ctx.v19.u16)));
	// vslh v14,v11,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v14.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vadduhm v3,v16,v17
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// vsubshs v1,v13,v15
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16), simde_mm_load_si128((simde__m128i*)ctx.v15.s16)));
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubshs v31,v7,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// vsubshs v29,v11,v14
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vadduhm v28,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v28.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.u16), simde_mm_load_si128((simde__m128i*)ctx.v10.u16)));
	// vadduhm v27,v3,v4
	simde_mm_store_si128((simde__m128i*)ctx.v27.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v4.u16)));
	// vadduhm v26,v1,v30
	simde_mm_store_si128((simde__m128i*)ctx.v26.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v30.u16)));
	// vadduhm v25,v29,v31
	simde_mm_store_si128((simde__m128i*)ctx.v25.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.u16), simde_mm_load_si128((simde__m128i*)ctx.v31.u16)));
	// vadduhm v24,v28,v13
	simde_mm_store_si128((simde__m128i*)ctx.v24.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// vadduhm v23,v27,v13
	simde_mm_store_si128((simde__m128i*)ctx.v23.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// lvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vadduhm v22,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v22.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.u16), simde_mm_load_si128((simde__m128i*)ctx.v25.u16)));
	// vadduhm v21,v23,v26
	simde_mm_store_si128((simde__m128i*)ctx.v21.u16, simde_mm_add_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.u16), simde_mm_load_si128((simde__m128i*)ctx.v26.u16)));
	// vsrah v20,v22,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v19,v21,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vor128 v60,v8,v20
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v20.u8)));
	// vpkshus128 v59,v20,v19
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v20.s16)));
	// vor128 v8,v60,v19
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8)));
	// stvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bdnz 0x826ef0d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826EF0D0;
loc_826EF1B0:
	// vand v0,v8,v2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// li r3,0
	ctx.r3.s64 = 0;
	// vcmpgtuh. v13,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_cmpgt_epu16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v7.u16)));
	ctx.cr6.setFromMask(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), 0xFFFF);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x826a02e4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8270ABC0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x8270ABC8;
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
	// bl 0x827081d8
	ctx.lr = 0x8270ABDC;
	sub_827081D8(ctx, base);
	// lis r11,-32048
	ctx.r11.s64 = -2100297728;
	// addi r28,r31,22640
	ctx.r28.s64 = ctx.r31.s64 + 22640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,16168(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16168);
	// bl 0x8270b528
	ctx.lr = 0x8270ABF0;
	sub_8270B528(ctx, base);
	// lhz r10,16004(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// addi r29,r30,1408
	ctx.r29.s64 = ctx.r30.s64 + 1408;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r8,r10,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x82708828
	ctx.lr = 0x8270AC14;
	sub_82708828(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270acd4
	if (!ctx.cr6.eq) goto loc_8270ACD4;
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
	// bl 0x82708398
	ctx.lr = 0x8270AC3C;
	sub_82708398(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270acd4
	if (!ctx.cr6.eq) goto loc_8270ACD4;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8270acb4
	if (ctx.cr6.eq) goto loc_8270ACB4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,268(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// bl 0x8270c200
	ctx.lr = 0x8270AC5C;
	sub_8270C200(ctx, base);
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
	ctx.lr = 0x8270AC88;
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
	ctx.lr = 0x8270ACB4;
	sub_8270C3A8(ctx, base);
loc_8270ACB4:
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,15568(r31)
	REX_STORE_U32(ctx.r31.u32 + 15568, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,15560(r31)
	REX_STORE_U32(ctx.r31.u32 + 15560, ctx.r11.u32);
	// stw r11,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r11.u32);
	// bl 0x8270b870
	ctx.lr = 0x8270ACD0;
	sub_8270B870(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270ACD4:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827234F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x826a0298
	ctx.lr = 0x82723500;
	__savegprlr_28(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32048
	ctx.r11.s64 = -2100297728;
	// addi r28,r3,22640
	ctx.r28.s64 = ctx.r3.s64 + 22640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,16168(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16168);
	// bl 0x8270b528
	ctx.lr = 0x8272351C;
	sub_8270B528(ctx, base);
	// addi r29,r31,17360
	ctx.r29.s64 = ctx.r31.s64 + 17360;
	// addi r30,r31,15952
	ctx.r30.s64 = ctx.r31.s64 + 15952;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82723e00
	ctx.lr = 0x82723534;
	sub_82723E00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827235f8
	if (!ctx.cr6.eq) goto loc_827235F8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82723a00
	ctx.lr = 0x8272354C;
	sub_82723A00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827235f8
	if (!ctx.cr6.eq) goto loc_827235F8;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827227a0
	ctx.lr = 0x82723564;
	sub_827227A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x827235f8
	if (!ctx.cr6.eq) goto loc_827235F8;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827235d0
	if (ctx.cr6.eq) goto loc_827235D0;
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82723594
	if (!ctx.cr6.eq) goto loc_82723594;
	// bl 0x827226c0
	ctx.lr = 0x82723590;
	sub_827226C0(ctx, base);
	// b 0x82723598
	goto loc_82723598;
loc_82723594:
	// bl 0x82722600
	ctx.lr = 0x82723598;
	sub_82722600(ctx, base);
loc_82723598:
	// lhz r10,16004(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,3752(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// lwz r6,3748(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r5,220(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// bl 0x82605548
	ctx.lr = 0x827235D0;
	sub_82605548(ctx, base);
loc_827235D0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8270b870
	ctx.lr = 0x827235DC;
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
	// stw r11,456(r31)
	REX_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
loc_827235F8:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x826a02e8
	__restgprlr_28(ctx, base);
	return;
}

