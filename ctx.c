#define gDPSetTextureConvert(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTCONV, 3, type)
#define gSPPerspNormalize(pkt,s) gMoveWd(pkt, G_MW_PERSPNORM, 0, (s))
#define gDPLoadMultiBlock_4bS(pkt,timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, 0 ); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define GU_PI 3.1415926
#define gsSPSetGeometryMode(word) gsSPGeometryMode(0,(word))
#define G_RM_AA_ZB_OPA_DECAL RM_AA_ZB_OPA_DECAL(1)
#define gsSPTextureRectangle(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) {{(_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12))}}, gsImmp1(G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))), gsImmp1(G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)))
#define IM_RD 0x40
#define gsSPBranchLessZ(dl,vtx,zval,near,far,flag) gsSPBranchLessZrg(dl, vtx, zval, near, far, flag, 0, G_MAXZ)
#define G_BRANCH_Z 0x04
#define gsDPSetScissor(mode,ulx,uly,lrx,lry) {{ _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((float)(ulx)*4.0F), 12, 12) | _SHIFTL((int)((float)(uly)*4.0F), 0, 12), _SHIFTL(mode, 24, 2) | _SHIFTL((int)((float)(lrx)*4.0F), 12, 12) | _SHIFTL((int)((float)(lry)*4.0F), 0, 12) }}
#define _ULTRA64_UCODE_H_ 
#define gsSPLoadGeometryMode(word) gsSPGeometryMode(-1,(word))
#define gSPLight(pkt,l,n) gDma2p((pkt),G_MOVEMEM,(l),sizeof(Light),G_MV_LIGHT,(n)*24+24)
#define OS_VI_GAMMA_DITHER_ON 0x0004
#define G_RM_AA_ZB_OPA_TERR2 RM_AA_ZB_OPA_TERR(2)
#define RM_AA_ZB_TEX_EDGE(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define G_MTX_MUL 0x00
#define G_MWO_CLIP_RPX 0x14
#define G_MWO_CLIP_RPY 0x1c
#define G_POPMTX 0xd8
#define OS_MESG_PRI_HIGH 1
#define G_CC_BLENDIA2 ENVIRONMENT, SHADE, COMBINED, SHADE, COMBINED, 0, SHADE, 0
#define G_RM_AA_TEX_TERR2 RM_AA_TEX_TERR(2)
#define G_RM_AA_OPA_TERR2 RM_AA_OPA_TERR(2)
#define G_IM_SIZ_4b_LOAD_BLOCK G_IM_SIZ_16b
#define RM_AA_SUB_SURF(clk) AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gSPLoadGeometryMode(pkt,word) gSPGeometryMode((pkt),-1,(word))
#define G_RM_ADD2 RM_ADD(2)
#define G_RDPPIPESYNC 0xe7
#define OS_EVENT_COUNTER 3
#define gDPLoadTextureBlock(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT) -1, CALC_DXT(width, siz ##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz ##_LINE_BYTES)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define __INCLUDE_ASM_H__ 
#define gdSPDefLookAt(rightx,righty,rightz,upx,upy,upz) { {{ {{0,0,0},0,{0,0,0},0,{rightx,righty,rightz},0}}, { {{0,0x80,0},0,{0,0x80,0},0,{upx,upy,upz},0}}} }
#define CONT_OVERRUN_ERROR 0x4
#define G_IM_SIZ_DD 5
#define TRUE 1
#define OS_EVENT_RDB_LOG_DONE 16
#define G_RM_AA_SUB_TERR2 RM_AA_SUB_TERR(2)
#define gsDPWord(wordhi,wordlo) gsImmp1(G_RDPHALF_1, (unsigned int)(wordhi)), gsImmp1(G_RDPHALF_2, (unsigned int)(wordlo))
#define OS_VI_DITHER_FILTER_OFF 0x0080
#define OS_IM_RDBREAD 0x00004401
#define G_CCMUX_TEXEL0_ALPHA 8
#define OS_IM_RDBWRITE 0x00002401
#define gDPLoadTLUT(pkt,count,tmemaddr,dram) { gDPSetTextureImage(pkt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram); gDPTileSync(pkt); gDPSetTile(pkt, 0, 0, 0, tmemaddr, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0); gDPLoadSync(pkt); gDPLoadTLUTCmd(pkt, G_TX_LOADTILE, ((count)-1)); gDPPipeSync(pkt); }
#define _OS_CACHE_H_ 
#define G_SETCOMBINE 0xfc
#define gsDPFullSync() gsDPNoParam(G_RDPFULLSYNC)
#define Z_CMP 0x10
#define L_CBUTTONS CONT_C
#define gsDPSetColor(c,d) {{ _SHIFTL(c, 24, 8), (unsigned int)(d) }}
#define CONT_ERR_NOT_READY 12
#define CVG_DST_WRAP 0x100
#define A_RIGHT 0x00
#define gDPSetBlendColor(pkt,r,g,b,a) DPRGBColor(pkt, G_SETBLENDCOLOR, r,g,b,a)
#define OS_EVENT_SP 4
#define gsSPInsertMatrix(where,num) ERROR!! gsSPInsertMatrix is no longer supported.
#define A_MIX 0x10
#define CVG_DST_CLAMP 0
#define G_RM_XLU_SURF2 RM_XLU_SURF(2)
#define G_TL_LOD (1 << G_MDSFT_TEXTLOD)
#define G_RM_ZB_XLU_DECAL RM_ZB_XLU_DECAL(1)
#define G_CC_BLENDRGBDECALA TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, TEXEL0
#define _GBI_H_ 
#define gSPCullDisplayList(pkt,vstart,vend) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_CULLDL, 24, 8) | _SHIFTL((vstart)*2, 0, 16); _g->words.w1 = _SHIFTL((vend)*2, 0, 16); }
#define G_CYC_COPY (2 << G_MDSFT_CYCLETYPE)
#define A_MIXER 12
#define OS_IM_COUNTER 0x00008401
#define G_CCMUX_COMBINED 0
#define A_SETLOOP 15
#define G_MV_PMTX 6
#define G_CC_DECALRGB2 0, 0, 0, COMBINED, 0, 0, 0, SHADE
#define G_CC_DECALRGBA 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0
#define SPSTATUS_CLEAR_SSTEP 0x00000020
#define Z_TRIG CONT_G
#define aSegment(pkt,s,b) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_SEGMENT, 24, 8); _a->words.w1 = _SHIFTL(s, 24, 8) | _SHIFTL(b, 0, 24); }
#define M_PI 3.14159265358979323846
#define _gsDPLoadTextureBlockTile(timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz ##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, CALC_DXT(width, siz ##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz ##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define gSPBranchList(pkt,dl) gDma1p(pkt,G_DL,dl,0,G_DL_NOPUSH)
#define gsDPSetBlendColor(r,g,b,a) sDPRGBColor(G_SETBLENDCOLOR, r,g,b,a)
#define G_CC_1CYUV2RGB TEXEL0, K4, K5, TEXEL0, 0, 0, 0, SHADE
#define gsDPSetAlphaDither(mode) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2, mode)
#define aSaveBuffer(pkt,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_SAVEBUFF, 24, 8); _a->words.w1 = (unsigned int)(s); }
#define G_MDSFT_TEXTCONV 9
#define G_CC_MODULATERGBA G_CC_MODULATEIA
#define CONT_ADDR_CRC_ER 0x04
#define CONT_CARD_ON 0x01
#define CONT_START 0x1000
#define gDPLoadTile(pkt,t,uls,ult,lrs,lrt) gDPLoadTileGeneric(pkt, G_LOADTILE, t, uls, ult, lrs, lrt)
#define MQ_GET_COUNT(mq) ((mq)->validCount)
#define OS_EVENT_SW1 0
#define G_TEXRECT 0xe4
#define G_RM_RA_ZB_OPA_DECAL2 RM_RA_ZB_OPA_DECAL(2)
#define gsDPSetOtherMode(mode0,mode1) {{ _SHIFTL(G_RDPSETOTHERMODE,24,8)|_SHIFTL(mode0,0,24), (unsigned int)(mode1) }}
#define G_MVO_LOOKATX (0*24)
#define G_RM_ZB_PCL_SURF2 RM_ZB_PCL_SURF(2)
#define gSPLightColor(pkt,n,col) { gMoveWd(pkt, G_MW_LIGHTCOL, G_MWO_a ##n, col); gMoveWd(pkt, G_MW_LIGHTCOL, G_MWO_b ##n, col); }
#define MAXCONTROLLERS 4
#define G_TF_POINT (0 << G_MDSFT_TEXTFILT)
#define G_MTX_NOPUSH 0x00
#define _SHIFTL(v,s,w) ((unsigned int) (((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))
#define _SHIFTR(v,s,w) ((unsigned int)(((unsigned int)(v) >> (s)) & ((0x01 << (w)) - 1)))
#define G_CC_HILITERGB2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, SHADE
#define G_TX_LOADTILE 7
#define G_TL_TILE (0 << G_MDSFT_TEXTLOD)
#define G_MOVEWORD 0xdb
#define G_RM_RA_ZB_OPA_INTER2 RM_RA_ZB_OPA_INTER(2)
#define G_IM_SIZ_32b_BYTES 4
#define MQ_IS_FULL(mq) (MQ_GET_COUNT(mq) >= (mq)->msgCount)
#define G_RM_CLD_SURF2 RM_CLD_SURF(2)
#define G_RM_AA_ZB_TEX_INTER2 RM_AA_ZB_TEX_INTER(2)
#define G_RM_AA_ZB_XLU_LINE2 RM_AA_ZB_XLU_LINE(2)
#define OS_PRIORITY_PIMGR 150
#define G_RM_AA_ZB_XLU_SURF RM_AA_ZB_XLU_SURF(1)
#define SPSTATUS_SIGNAL6_SET 0x2000
#define RCP_IMASKSHIFT 16
#define G_IMMCMDSIZ 64
#define G_RM_AA_XLU_LINE2 RM_AA_XLU_LINE(2)
#define SPSTATUS_SET_HALT 0x00000002
#define G_RM_AA_ZB_SUB_TERR RM_AA_ZB_SUB_TERR(1)
#define CVG_DST_SAVE 0x300
#define gsDPSetTextureFilter(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, type)
#define G_MTX_PUSH 0x01
#define gDPLoadSync(pkt) gDPNoParam(pkt, G_RDPLOADSYNC)
#define G_RM_OPA_SURF RM_OPA_SURF(1)
#define FR_POS_FRUSTRATIO_1 0x0000ffff
#define gsDPTileSync() gsDPNoParam(G_RDPTILESYNC)
#define RM_AA_ZB_XLU_SURF(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_XLU | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define gDPSetTextureFilter(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, type)
#define G_RDP_TRI_FILL_MASK 0x08
#define G_MVO_L1 (3*24)
#define G_MVO_L2 (4*24)
#define G_MVO_L3 (5*24)
#define G_MVO_L4 (6*24)
#define G_MVO_L5 (7*24)
#define G_MVO_L7 (9*24)
#define gsSP2Triangles(v00,v01,v02,flag0,v10,v11,v12,flag1) {{ (_SHIFTL(G_TRI2, 24, 8)| __gsSP1Triangle_w1f(v00, v01, v02, flag0)), __gsSP1Triangle_w1f(v10, v11, v12, flag1) }}
#define G_CC_BLENDRGBA TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, SHADE
#define G_VTX 0x01
#define FR_POS_FRUSTRATIO_5 0x0000fffb
#define G_SETTILESIZE 0xf2
#define OS_EVENT_CART 2
#define gsSPNoOp() gsDma0p(G_SPNOOP, 0, 0)
#define G_TRI_SHADE_ZBUFF 0xcd
#define M_VIDTASK 3
#define RM_ZB_OPA_SURF(clk) Z_CMP | Z_UPD | CVG_DST_FULL | ALPHA_CVG_SEL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define G_MAXZ 0x03ff
#define G_MWO_MATRIX_YZ_YW_F 0x2c
#define G_MWO_MATRIX_YZ_YW_I 0x0c
#define G_MDSFT_BLENDMASK 0
#define RM_ZB_OVL_SURF(clk) Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_DEC | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define gsSPViewport(v) gsDma2p( G_MOVEMEM, (v), sizeof(Vp), G_MV_VIEWPORT, 0)
#define EEPROM_TYPE_4K 0x01
#define RM_AA_TEX_TERR(clk) AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_MDSFT_RENDERMODE 3
#define OS_PM_1M 0x01fe000
#define gsDPLoadMultiBlock_4bS(timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1,0), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define G_DL_PUSH 0x00
#define G_RM_AA_OPA_SURF RM_AA_OPA_SURF(1)
#define G_CCMUX_SCALE 6
#define gSPPopMatrix(pkt,n) gSPPopMatrixN((pkt), (n), 1)
#define G_OFF (0)
#define gMoveWd(pkt,index,offset,data) gDma1p((pkt), G_MOVEWORD, data, offset, index)
#define G_TRI_SHADE_TXTR_ZBUFF 0xcf
#define aInterleave(pkt,l,r) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_INTERLEAVE, 24, 8); _a->words.w1 = _SHIFTL(l, 16, 16) | _SHIFTL(r, 0, 16); }
#define __asm__(...) 
#define gsDPSetKeyR(cR,sR,wR) {{ _SHIFTL(G_SETKEYR, 24, 8), _SHIFTL(wR, 16, 12) | _SHIFTL(cR, 8, 8) | _SHIFTL(sR, 0, 8) }}
#define G_IM_SIZ_32b_LOAD_BLOCK G_IM_SIZ_32b
#define OS_PM_4K 0x0000000
#define OS_PM_4M 0x07fe000
#define OS_PRIORITY_IDLE 0
#define G_RM_AA_TEX_EDGE RM_AA_TEX_EDGE(1)
#define CONT_ERR_INVALID PFS_ERR_INVALID
#define G_MWO_CLIP_RNY 0x0c
#define G_GEOMETRYMODE 0xd9
#define OS_PM_256K 0x007e000
#define aLoadADPCM(pkt,c,d) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24); _a->words.w1 = (unsigned int) d; }
#define gDPFullSync(pkt) gDPNoParam(pkt, G_RDPFULLSYNC)
#define GBL_c1(m1a,m1b,m2a,m2b) (m1a) << 30 | (m1b) << 26 | (m2a) << 22 | (m2b) << 18
#define GBL_c2(m1a,m1b,m2a,m2b) (m1a) << 28 | (m1b) << 24 | (m2a) << 20 | (m2b) << 16
#define gDPSetColorDither(pkt,mode) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, mode)
#define _PLAYER_H 
#define G_TRI_SHADE 0xcc
#define STRINGIFY_(x) #x
#define CONT_EEPROM_BUSY 0x80
#define G_CK_KEY (1 << G_MDSFT_COMBKEY)
#define gDPSetTile(pkt,fmt,siz,line,tmem,tile,palette,cmt,maskt,shiftt,cms,masks,shifts) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETTILE, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9); _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) |_SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4); }
#define G_IM_SIZ_4b_SHIFT 2
#define G_MWO_bLIGHT_5 0x64
#define G_TRI2 0x06
#define G_MWO_bLIGHT_7 0x94
#define G_RM_ZB_XLU_SURF RM_ZB_XLU_SURF(1)
#define aPan(pkt,f,d,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_PAN, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(d, 0, 16)); _a->words.w1 = (unsigned int)(s); }
#define SPSTATUS_SIGNAL5_SET 0x1000
#define G_DL_NOPUSH 0x01
#define L_JPAD CONT_LEFT
#define GRDPCMD(x) (0xff-(x))
#define gSP2Triangles(pkt,v00,v01,v02,flag0,v10,v11,v12,flag1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TRI2, 24, 8)| __gsSP1Triangle_w1f(v00, v01, v02, flag0)); _g->words.w1 = __gsSP1Triangle_w1f(v10, v11, v12, flag1); }
#define G_RM_AA_ZB_PCL_SURF2 RM_AA_ZB_PCL_SURF(2)
#define SPSTATUS_INTERRUPT_ON_BREAK 0x0040
#define G_CC_YUV2RGB TEXEL1, K4, K5, TEXEL1, 0, 0, 0, 0
#define gsSPLoadUcodeEx(uc_start,uc_dstart,uc_dsize) {{ _SHIFTL(G_RDPHALF_1,24,8), (unsigned int)(uc_dstart), }}, {{ _SHIFTL(G_LOAD_UCODE,24,8)| _SHIFTL((int)(uc_dsize)-1,0,16), (unsigned int)(uc_start), }}
#define gSPDmaWrite(pkt,dmem,dram,size) gSPDma_io((pkt),1,(dmem),(dram),(size))
#define gsDPLoadMultiBlock_4b(timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define G_MWO_NUMLIGHT 0x00
#define G_IM_FMT_CI 2
#define G_CC_MODULATEI_PRIM TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE
#define CONT_ERR_VOICE_NO_RESPONSE 15
#define G_SETBLENDCOLOR 0xf9
#define G_RM_PASS GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)
#define A_SAVEBUFF 6
#define gsDma0p(c,s,l) {{ _SHIFTL((c), 24, 8) | _SHIFTL((l), 0, 24), (unsigned int)(s) }}
#define gDPSetTextureDetail(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTDETAIL, 2, type)
#define G_CCMUX_ENV_ALPHA 12
#define _OS_MESSAGE_H_ 
#define gsSPLookAt(la) gsSPLookAtX(la), gsSPLookAtY((char *)(la)+16)
#define OS_IM_CART 0x00000c01
#define G_MV_POINT 12
#define G_MWO_POINT_ST 0x14
#define CONT_A 0x8000
#define G_CCMUX_PRIM_LOD_FRAC 14
#define G_SHADE 0x00000004
#define __STDC_HOSTED__ 0
#define CONT_C 0x0002
#define G_RM_RA_OPA_SURF RM_RA_OPA_SURF(1)
#define SPSTATUS_SET_SSTEP 0x00000040
#define RESET_TYPE_BOOT_DISK 2
#define G_IM_FMT_IA 3
#define RM_AA_OPA_TERR(clk) AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_CC_MODULATERGBDECALA_PRIM G_CC_MODULATEIDECALA_PRIM
#define RM_AA_ZB_SUB_SURF(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gsDPSetEnvColor(r,g,b,a) sDPRGBColor(G_SETENVCOLOR, r,g,b,a)
#define gsDPSetConvert(k0,k1,k2,k3,k4,k5) {{ (_SHIFTL(G_SETCONVERT, 24, 8) | _SHIFTL(k0, 13, 9) | _SHIFTL(k1, 4, 9) | _SHIFTR(k2, 5, 4)), (_SHIFTL(k2, 27, 5) | _SHIFTL(k3, 18, 9) | _SHIFTL(k4, 9, 9) | _SHIFTL(k5, 0, 9)) }}
#define G_TD_DETAIL (2 << G_MDSFT_TEXTDETAIL)
#define A_LEFT 0x02
#define OS_PRIORITY_MAX 255
#define G_CC_MODULATEIA2 COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0
#define EEP16K_MAXBLOCKS 256
#define OS_VI_DIVOT_ON 0x0010
#define G_LIGHTING 0x00020000
#define G_TC_FILT (6 << G_MDSFT_TEXTCONV)
#define gDPSetCombineMode(pkt,a,b) gDPSetCombineLERP(pkt, a, b)
#define gsDPLoadTLUT_pal16(pal,dram) gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram), gsDPTileSync(), gsDPSetTile(0, 0, 0, (256+(((pal)&0xf)*16)), G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0), gsDPLoadSync(), gsDPLoadTLUTCmd(G_TX_LOADTILE, 15), gsDPPipeSync()
#define gsDPSetCombine(muxs0,muxs1) {{ _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(muxs0, 0, 24), (unsigned int)(muxs1) }}
#define G_CC_HILITERGBDECALA2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, TEXEL0
#define TV_TYPE_MPAL 2
#define G_BL_CLR_BL 2
#define OS_VI_DITHER_FILTER 0x10000
#define G_CC_BLENDI ENVIRONMENT, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
#define D_JPAD CONT_DOWN
#define G_TRI1 0x05
#define RCP_IMASK 0x003f0000
#define G_RM_AA_ZB_XLU_DECAL RM_AA_ZB_XLU_DECAL(1)
#define gDPTextureRectangle(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); if (pkt); _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); _g ++; _g->words.w0 = (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)); _g->words.w1 = (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)); }
#define gsDPSetKeyGB(cG,sG,wG,cB,sB,wB) {{ (_SHIFTL(G_SETKEYGB, 24, 8) | _SHIFTL(wG, 12, 12) | _SHIFTL(wB, 0, 12)), (_SHIFTL(cG, 24, 8) | _SHIFTL(sG, 16, 8) | _SHIFTL(cB, 8, 8) | _SHIFTL(sB, 0, 8)) }}
#define G_RM_AA_ZB_TEX_TERR2 RM_AA_ZB_TEX_TERR(2)
#define GPACK_ZDZ(z,dz) ((z) << 2 | (dz))
#define __gsSP1Triangle_w1(v0,v1,v2) (_SHIFTL((v0)*2,16,8)|_SHIFTL((v1)*2,8,8)|_SHIFTL((v2)*2,0,8))
#define gsSPTexture(s,t,level,tile,on) {{ (_SHIFTL(G_TEXTURE,24,8) | _SHIFTL(BOWTIE_VAL,16,8) | _SHIFTL((level),11,3) | _SHIFTL((tile),8,3) | _SHIFTL((on),1,7)), (_SHIFTL((s),16,16) | _SHIFTL((t),0,16)) }}
#define CONT_ERR_CONTRFAIL CONT_OVERRUN_ERROR
#define G_TX_LDBLK_MAX_TXL 2047
#define G_MWO_MATRIX_YX_YY_F 0x28
#define G_RM_RA_ZB_OPA_INTER RM_RA_ZB_OPA_INTER(1)
#define gsDPPipeSync() gsDPNoParam(G_RDPPIPESYNC)
#define G_TEXTURE 0xd7
#define RM_AA_OPA_SURF(clk) AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gSPSegment(pkt,segment,base) gMoveWd(pkt, G_MW_SEGMENT, (segment)*4, base)
#define gSPSetLights0(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_0); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.a,2); }
#define _ULTRA64_LIBAUDIO_H_ 
#define gDPSetFogColor(pkt,r,g,b,a) DPRGBColor(pkt, G_SETFOGCOLOR, r,g,b,a)
#define OS_VI_GAMMA_ON 0x0001
#define ZMODE_XLU 0x800
#define gDma0p(pkt,c,s,l) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8) | _SHIFTL((l), 0, 24); _g->words.w1 = (unsigned int)(s); }
#define _COMMON_H_ 
#define ACMD_SIZE 32
#define G_BL_1 2
#define RM_AA_ZB_OPA_DECAL(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | ALPHA_CVG_SEL | ZMODE_DEC | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gDma1p(pkt,c,s,l,p) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL((c), 24, 8) | _SHIFTL((p), 16, 8) | _SHIFTL((l), 0, 16)); _g->words.w1 = (unsigned int)(s); }
#define G_MW_NUMLIGHT 0x02
#define OS_YIELD_AUDIO_SIZE 0x400
#define SPSTATUS_SIGNAL4_SET 0x0800
#define gDPSetAlphaDither(pkt,mode) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2, mode)
#define gDma2p(pkt,c,adrs,len,idx,ofs) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL((c),24,8)|_SHIFTL(((len)-1)/8,19,5)| _SHIFTL((ofs)/8,8,8)|_SHIFTL((idx),0,8)); _g->words.w1 = (unsigned int)(adrs); }
#define G_LOADTLUT 0xf0
#define RM_AA_DEC_LINE(clk) AA_EN | IM_RD | CVG_DST_FULL | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define RM_AA_ZB_OPA_SURF(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define AA_EN 0x8
#define gsDPTextureRectangleFlip(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) {{ (_SHIFTL(G_TEXRECTFLIP, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)), }}, {{ _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16), _SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16) }}
#define OS_EVENT_CPU_BREAK 10
#define OS_EVENT_SP_BREAK 11
#define TXL2WORDS(txls,b_txl) MAX(1, ((txls)*(b_txl)/8))
#define __gsSPLine3D_w1f(v0,v1,wd,flag) (((flag) == 0) ? __gsSPLine3D_w1(v0, v1, wd): __gsSPLine3D_w1(v1, v0, wd))
#define gSPSetLights6(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_6); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.l[4],5); gSPLight(pkt,&name.l[5],6); gSPLight(pkt,&name.a,7); }
#define _ULTRA64_H_ 
#define G_RM_RA_OPA_SURF2 RM_RA_OPA_SURF(2)
#define RM_ZB_OPA_DECAL(clk) Z_CMP | CVG_DST_FULL | ALPHA_CVG_SEL | ZMODE_DEC | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gsDPSetPrimColor(m,l,r,g,b,a) {{ (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)), (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)) }}
#define _OS_RDP_H_ 
#define CONT_JOYPORT 0x0004
#define G_SETTIMG 0xfd
#define G_CK_NONE (0 << G_MDSFT_COMBKEY)
#define G_RM_AA_PCL_SURF2 RM_AA_PCL_SURF(2)
#define gSPModifyVertex(pkt,vtx,where,val) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_MODIFYVTX,24,8)| _SHIFTL((where),16,8)|_SHIFTL((vtx)*2,0,16)); _g->words.w1 = (unsigned int)(val); }
#define _gsDPLoadTextureBlock_4b(timg,tmem,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define gDPSetConvert(pkt,k0,k1,k2,k3,k4,k5) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETCONVERT, 24, 8) | _SHIFTL(k0, 13, 9) | _SHIFTL(k1, 4, 9) | _SHIFTR(k2, 5, 4)); _g->words.w1 = (_SHIFTL(k2, 27, 5) | _SHIFTL(k3, 18, 9) | _SHIFTL(k4, 9, 9) | _SHIFTL(k5, 0, 9)); }
#define G_TX_DXT_FRAC 11
#define gSPVertex(pkt,v,n,v0) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_VTX,24,8)|_SHIFTL((n),12,8)|_SHIFTL((v0)+(n),1,7); _g->words.w1 = (unsigned int)(v); }
#define gSPSprite2DBase(pkt,s) gDma1p(pkt, G_SPRITE2D_BASE, s, sizeof(uSprite), 0)
#define gsSPBranchLessZraw(dl,vtx,zval) {{ _SHIFTL(G_RDPHALF_1,24,8), (unsigned int)(dl), }}, {{ _SHIFTL(G_BRANCH_Z,24,8)|_SHIFTL((vtx)*5,12,12)|_SHIFTL((vtx)*2,0,12), (unsigned int)(zval), }}
#define G_MVO_L0 (2*24)
#define EXEC_PROCESS_DEFAULT 0
#define _ULTRA64_SPTASK_H_ 
#define gDPLoadMultiTile(pkt,timg,tmem,rtile,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz, width, timg); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz ##_TILE_BYTES)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz ##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }
#define gsSPPopMatrixN(n,num) gsDma2p( G_POPMTX,(num)*64,64,2,0)
#define gDPSetCombine(pkt,muxs0,muxs1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(muxs0, 0, 24); _g->words.w1 = (unsigned int)(muxs1); }
#define aSetVolume32(pkt,f,v,tr) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 16) | _SHIFTL(v, 0, 16)); _a->words.w1 = (unsigned int)(tr); }
#define G_MVO_L6 (8*24)
#define G_RM_AA_XLU_SURF RM_AA_XLU_SURF(1)
#define CONT_ERR_VOICE_WORD 14
#define gDPSetCombineLERP(pkt,a0,b0,c0,d0,Aa0,Ab0,Ac0,Ad0,a1,b1,c1,d1,Aa1,Ab1,Ac1,Ad1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(GCCc0w0(G_CCMUX_ ##a0, G_CCMUX_ ##c0, G_ACMUX_ ##Aa0, G_ACMUX_ ##Ac0) | GCCc1w0(G_CCMUX_ ##a1, G_CCMUX_ ##c1), 0, 24); _g->words.w1 = (unsigned int)(GCCc0w1(G_CCMUX_ ##b0, G_CCMUX_ ##d0, G_ACMUX_ ##Ab0, G_ACMUX_ ##Ad0) | GCCc1w1(G_CCMUX_ ##b1, G_ACMUX_ ##Aa1, G_ACMUX_ ##Ac1, G_CCMUX_ ##d1, G_ACMUX_ ##Ab1, G_ACMUX_ ##Ad1)); }
#define gsSP1Triangle(v0,v1,v2,flag) {{ _SHIFTL(G_TRI1, 24, 8)|__gsSP1Triangle_w1f(v0, v1, v2, flag), 0 }}
#define gDPLoadTextureBlockYuv(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT) -1, CALC_DXT(width, siz ##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * 1)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define G_RM_AA_ZB_PCL_SURF RM_AA_ZB_PCL_SURF(1)
#define G_TD_CLAMP (0 << G_MDSFT_TEXTDETAIL)
#define _ULTRA64_GU_H_ 
#define G_ZS_PIXEL (0 << G_MDSFT_ZSRCSEL)
#define G_CC_PRIMITIVE 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE
#define SPSTATUS_SINGLE_STEP 0x0020
#define G_MWO_POINT_XYSCREEN 0x18
#define G_MWO_MATRIX_XZ_XW_F 0x24
#define G_MWO_MATRIX_XZ_XW_I 0x04
#define gSPFogPosition(pkt,min,max) gMoveWd(pkt, G_MW_FOG, G_MWO_FOG, (_SHIFTL((128000/((max)-(min))),16,16) | _SHIFTL(((500-(min))*256/((max)-(min))),0,16)))
#define G_NOOP 0x00
#define G_MW_PERSPNORM 0x0e
#define _gsDPLoadTextureBlock(timg,tmem,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz ##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, CALC_DXT(width, siz ##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz ##_LINE_BYTES)+7)>>3), tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define G_IM_SIZ_16b_INCR 0
#define NUMLIGHTS_0 1
#define NUMLIGHTS_1 1
#define NUMLIGHTS_2 2
#define NUMLIGHTS_3 3
#define NUMLIGHTS_5 5
#define NUMLIGHTS_6 6
#define NUMLIGHTS_7 7
#define R_TRIG CONT_R
#define gsDPLoadTextureBlock(timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz ##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz ##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, CALC_DXT(width, siz ##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz ##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define G_RDP_TRI_TXTR_MASK 0x02
#define gDPSetBlendMask(pkt,mask) gDPNoOp(pkt)
#define CONT_ERR_VOICE_MEMORY 13
#define G_RM_AA_ZB_XLU_LINE RM_AA_ZB_XLU_LINE(1)
#define G_AD_NOISE (2 << G_MDSFT_ALPHADITHER)
#define G_TT_NONE (0 << G_MDSFT_TEXTLUT)
#define gDPSetMaskImage(pkt,i) gDPSetDepthImage(pkt, i)
#define _G_CC_TWOCOLORTEX PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
#define gsDPLoadMultiTile(timg,tmem,rtile,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz, width, timg), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz ##_TILE_BYTES)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC), gsDPPipeSync(), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz ##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)
#define G_RM_VISCVG2 RM_VISCVG(2)
#define G_RM_AA_ZB_SUB_SURF2 RM_AA_ZB_SUB_SURF(2)
#define gsSPGeometryMode(c,s) {{ (_SHIFTL(G_GEOMETRYMODE,24,8)|_SHIFTL(~(u32)(c),0,24)),(u32)(s) }}
#define G_CC_HILITERGB PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
#define RM_AA_ZB_PCL_SURF(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | G_AC_DITHER | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define OS_VI_NTSC_LAN1 2
#define OS_VI_NTSC_LAN2 6
#define G_CCMUX_CENTER 6
#define G_RDP_ADDR_FIXUP 3
#define G_RM_AA_SUB_SURF2 RM_AA_SUB_SURF(2)
#define G_TX_NOMIRROR 0
#define G_BZ_ORTHO 1
#define G_BL_A_FOG 1
#define G_MDSFT_RGBDITHER 6
#define RM_RA_ZB_OPA_DECAL(clk) AA_EN | Z_CMP | CVG_DST_WRAP | ALPHA_CVG_SEL | ZMODE_DEC | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define CONT_ERR_DEVICE PFS_ERR_DEVICE
#define G_CV_K0 175
#define G_CV_K1 -43
#define G_CV_K2 -89
#define G_CV_K3 222
#define G_CV_K5 42
#define G_AD_NOTPATTERN (1 << G_MDSFT_ALPHADITHER)
#define RM_AA_ZB_XLU_LINE(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_XLU | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_MDSFT_CYCLETYPE 20
#define G_CC_MODULATEIA_PRIM TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0
#define gsDPSetPrimDepth(z,dz) gsDPSetColor(G_SETPRIMDEPTH, _SHIFTL(z, 16, 16) | _SHIFTL(dz, 0, 16))
#define G_CULL_BACK 0x00000400
#define G_CC_CHROMA_KEY2 TEXEL0, CENTER, SCALE, 0, 0, 0, 0, 0
#define _G_CC_BLENDPEDECALA ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0
#define G_MOVEMEM 0xdc
#define G_TEXTURE_IMAGE_FRAC 2
#define gsSPClearGeometryMode(word) gsSPGeometryMode((word),0)
#define gDPWord(pkt,wordhi,wordlo) { Gfx *_g = (Gfx *)(pkt); gImmp1(pkt, G_RDPHALF_1, (unsigned int)(wordhi)); gImmp1(pkt, G_RDPHALF_2, (unsigned int)(wordlo)); }
#define SEGMENT_ADDR(num,off) (((num) << 24) + (off))
#define G_CC_DECALRGB 0, 0, 0, TEXEL0, 0, 0, 0, SHADE
#define G_CC_MODULATEI2 COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE
#define ZMODE_INTER 0x400
#define CONT_UP 0x0800
#define OS_IM_SI 0x00020401
#define G_RM_AA_SUB_TERR RM_AA_SUB_TERR(1)
#define G_IM_SIZ_32b 3
#define G_CCMUX_COMBINED_ALPHA 7
#define gsSPTextureL(s,t,level,xparam,tile,on) {{ (_SHIFTL(G_TEXTURE,24,8) | _SHIFTL((xparam),16,8) | _SHIFTL((level),11,3) | _SHIFTL((tile),8,3) | _SHIFTL((on),1,7)), (_SHIFTL((s),16,16) | _SHIFTL((t),0,16)) }}
#define G_CC_MODULATERGBA2 G_CC_MODULATEIA2
#define gDPLoadMultiBlock_4b(pkt,timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define OS_YIELD_DATA_SIZE 0xc00
#define G_MWO_MATRIX_ZX_ZY_F 0x30
#define gsDPSetScissorFrac(mode,ulx,uly,lrx,lry) {{ _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((ulx)), 12, 12) | _SHIFTL((int)((uly)), 0, 12), _SHIFTL(mode, 24, 2) | _SHIFTL((int)(lrx), 12, 12) | _SHIFTL((int)(lry), 0, 12) }}
#define G_MWO_MATRIX_ZX_ZY_I 0x10
#define gsDPSetTextureConvert(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTCONV, 3, type)
#define G_RM_TEX_EDGE RM_TEX_EDGE(1)
#define G_TX_NOMASK 0
#define SPSTATUS_SET_INTR_ON_BREAK 0x00000100
#define G_RM_PCL_SURF2 RM_PCL_SURF(2)
#define G_MWO_aLIGHT_1 0x00
#define G_AC_THRESHOLD (1 << G_MDSFT_ALPHACOMPARE)
#define _ULTRA64_PI_H_ 
#define STRINGIFY(x) STRINGIFY_(x)
#define gsDma2p(c,adrs,len,idx,ofs) {{ (_SHIFTL((c),24,8)|_SHIFTL(((len)-1)/8,19,5)| _SHIFTL((ofs)/8,8,8)|_SHIFTL((idx),0,8)), (unsigned int)(adrs) }}
#define G_RM_RA_ZB_OPA_SURF2 RM_RA_ZB_OPA_SURF(2)
#define CONT_TYPE_MOUSE 0x0002
#define RM_ZB_XLU_SURF(clk) Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_XLU | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_IM_FMT_YUV 1
#define G_LOAD_UCODE 0xdd
#define OS_VI_MPAL_LAN1 30
#define gDPSetOtherMode(pkt,mode0,mode1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_RDPSETOTHERMODE,24,8)|_SHIFTL(mode0,0,24); _g->words.w1 = (unsigned int)(mode1); }
#define gDPLoadTextureTile_4b(pkt,timg,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_8b, ((width)>>1), timg); gDPSetTile(pkt, fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }
#define G_CULL_FRONT 0x00000200
#define G_MWO_aLIGHT_7 0x90
#define gDPSetTextureLUT(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, type)
#define G_SETPRIMDEPTH 0xee
#define gDPPipelineMode(pkt,mode) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_PIPELINE, 1, mode)
#define G_RM_AA_ZB_TEX_EDGE2 RM_AA_ZB_TEX_EDGE(2)
#define G_MW_MATRIX 0x00
#define G_BL_CLR_MEM 1
#define G_CYC_1CYCLE (0 << G_MDSFT_CYCLETYPE)
#define G_RM_ZB_PCL_SURF RM_ZB_PCL_SURF(1)
#define G_IM_SIZ_16b 2
#define EEPROM_BLOCK_SIZE 8
#define gDPSetCycleType(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, type)
#define G_CD_MAGICSQ (0 << G_MDSFT_RGBDITHER)
#define G_LOD 0x00100000
#define CONT_EEP16K 0x4000
#define OS_EVENT_RDB_DBG_DONE 20
#define gsSPBranchLessZrg(dl,vtx,zval,near,far,flag,zmin,zmax) {{ _SHIFTL(G_RDPHALF_1,24,8), (unsigned int)(dl), }}, {{ _SHIFTL(G_BRANCH_Z,24,8)|_SHIFTL((vtx)*5,12,12)|_SHIFTL((vtx)*2,0,12), G_DEPTOZSrg(zval, near, far, flag, zmin, zmax), }}
#define G_CC_REFLECTRGB ENVIRONMENT, 0, TEXEL0, SHADE, 0, 0, 0, SHADE
#define gsSPSegment(segment,base) gsMoveWd( G_MW_SEGMENT, (segment)*4, base)
#define gsDPSetTextureImage(f,s,w,i) gsSetImage(G_SETTIMG, f, s, w, i)
#define gSPEndDisplayList(pkt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_ENDDL, 24, 8); _g->words.w1 = 0; }
#define OS_IM_SW1 0x00000501
#define SEGMENT_NUMBER(a) (((unsigned int)(a) << 4) >> 28)
#define A_RATE 0x00
#define osSpTaskStart(p) osSpTaskLoad(p); osSpTaskStartGo(p);
#define G_TEXRECTFLIP 0xe5
#define RM_AA_TEX_EDGE(clk) AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gDPLoadTLUT_pal256(pkt,dram) { gDPSetTextureImage(pkt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram); gDPTileSync(pkt); gDPSetTile(pkt, 0, 0, 0, 256, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0); gDPLoadSync(pkt); gDPLoadTLUTCmd(pkt, G_TX_LOADTILE, 255); gDPPipeSync(pkt) }
#define aSetVolume(pkt,f,v,t,r) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 16) | _SHIFTL(v, 0, 16)); _a->words.w1 = _SHIFTL(t, 16, 16) | _SHIFTL(r, 0, 16); }
#define OS_VI_NTSC_LPF1 1
#define OS_VI_NTSC_LPF2 5
#define G_IM_FMT_RGBA 0
#define G_CD_NOISE (2 << G_MDSFT_RGBDITHER)
#define RESET_TYPE_NMI 1
#define gSPTexture(pkt,s,t,level,tile,on) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXTURE,24,8) | _SHIFTL(BOWTIE_VAL,16,8) | _SHIFTL((level),11,3) | _SHIFTL((tile),8,3) | _SHIFTL((on),1,7)); _g->words.w1 = (_SHIFTL((s),16,16) | _SHIFTL((t),0,16)); }
#define _OS_EXCEPTION_H_ 
#define OS_VI_GAMMA_OFF 0x0002
#define M_TASK_FLAG0 1
#define M_TASK_FLAG1 2
#define SPSTATUS_CLEAR_INTR 0x00000008
#define _MATH_H_ 
#define EXEC_PROCESS_SLEEPING 1
#define G_RM_ZB_OPA_SURF2 RM_ZB_OPA_SURF(2)
#define OS_IM_ALL 0x003fff01
#define F3DEX_GBI_2 1
#define gsDPLoadTextureBlock_4bS(timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1,0), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define CONT_ABSOLUTE 0x0001
#define G_MWO_bLIGHT_1 0x04
#define G_MWO_bLIGHT_3 0x34
#define G_MWO_bLIGHT_4 0x4c
#define G_MWO_bLIGHT_6 0x7c
#define G_MWO_bLIGHT_8 0xac
#define SPSTATUS_SIGNAL2_SET 0x0200
#define gsDPSetRenderMode(c0,c1) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, (c0) | (c1))
#define G_LINE3D 0x08
#define gdSPDefLights6(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4,r5,g5,b5,x5,y5,z5,r6,g6,b6,x6,y6,z6) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}, {{ {r5,g5,b5},0,{r5,g5,b5},0,{x5,y5,z5},0}}, {{ {r6,g6,b6},0,{r6,g6,b6},0,{x6,y6,z6},0}}} }
#define gDPSetTileSize(pkt,t,uls,ult,lrs,lrt) gDPLoadTileGeneric(pkt, G_SETTILESIZE, t, uls, ult, lrs, lrt)
#define gsSP1Quadrangle(v0,v1,v2,v3,flag) {{ (_SHIFTL(G_QUAD, 24, 8)| __gsSP1Quadrangle_w1f(v0, v1, v2, v3, flag)), __gsSP1Quadrangle_w2f(v0, v1, v2, v3, flag) }}
#define gSPLine3D(pkt,v0,v1,flag) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_LINE3D, 24, 8)| __gsSPLine3D_w1f(v0, v1, 0, flag); _g->words.w1 = 0; }
#define gDPTextureRectangleFlip(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); if (pkt); _g->words.w0 = (_SHIFTL(G_TEXRECTFLIP, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); _g ++; _g->words.w0 = (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)); _g->words.w1 = (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)); }
#define gsSPBranchList(dl) gsDma1p( G_DL,dl,0,G_DL_NOPUSH)
#define G_MW_SEGMENT 0x06
#define G_MDSFT_ZSRCSEL 2
#define LIGHT_1 1
#define LIGHT_2 2
#define LIGHT_4 4
#define LIGHT_7 7
#define G_MDSFT_TEXTDETAIL 17
#define M2CTX 1
#define gSPDmaRead(pkt,dmem,dram,size) gSPDma_io((pkt),0,(dmem),(dram),(size))
#define gsDPLoadMultiBlockS(timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz ##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt,shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, 0 ), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz ##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define G_RM_AA_ZB_OPA_DECAL2 RM_AA_ZB_OPA_DECAL(2)
#define LIGHT_3 3
#define G_RDP_TRI_ZBUFF_MASK 0x01
#define OS_VI_NTSC_LPN1 0
#define OS_VI_NTSC_LPN2 4
#define OS_VI_GAMMA_DITHER 0x04
#define _gDPLoadTextureBlock(pkt,timg,tmem,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, CALC_DXT(width, siz ##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz ##_LINE_BYTES)+7)>>3, tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define LIGHT_8 8
#define G_TF_AVERAGE (3 << G_MDSFT_TEXTFILT)
#define OS_FLAG_CPU_BREAK 1
#define G_SPNOOP 0xe0
#define G_MDSFT_PIPELINE 23
#define LIGHT_6 6
#define gDPLoadTileGeneric(pkt,c,tile,uls,ult,lrs,lrt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12); }
#define gSP1Triangle(pkt,v0,v1,v2,flag) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_TRI1, 24, 8)| __gsSP1Triangle_w1f(v0, v1, v2, flag); _g->words.w1 = 0; }
#define gSPNoOp(pkt) gDma0p(pkt, G_SPNOOP, 0, 0)
#define gImmp0(pkt,c) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); }
#define gImmp2(pkt,c,p0,p1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = _SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8); }
#define gImmp3(pkt,c,p0,p1,p2) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = (_SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8) | _SHIFTL((p2), 0, 8)); }
#define G_AC_NONE (0 << G_MDSFT_ALPHACOMPARE)
#define OS_VI_PAL_HAF1 25
#define LIGHT_5 5
#define U_CBUTTONS CONT_E
#define G_CCMUX_SHADE 4
#define gDPSetTextureImage(pkt,f,s,w,i) gSetImage(pkt, G_SETTIMG, f, s, w, i)
#define NUMLIGHTS_4 4
#define BOWTIE_VAL 0
#define gDPSetScissor(pkt,mode,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)pkt; _g->words.w0 = _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((float)(ulx)*4.0F), 12, 12) | _SHIFTL((int)((float)(uly)*4.0F), 0, 12); _g->words.w1 = _SHIFTL(mode, 24, 2) | _SHIFTL((int)((float)(lrx)*4.0F), 12, 12) | _SHIFTL((int)((float)(lry)*4.0F), 0, 12); }
#define G_RM_AA_ZB_OPA_INTER2 RM_AA_ZB_OPA_INTER(2)
#define OS_READ 0
#define gsDPSetTile(fmt,siz,line,tmem,tile,palette,cmt,maskt,shiftt,cms,masks,shifts) {{ (_SHIFTL(G_SETTILE, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9)), (_SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4)) }}
#define G_CCMUX_NOISE 7
#define A_NOAUX 0x00
#define gsImmp1(c,p0) {{ _SHIFTL((c), 24, 8), (unsigned int)(p0) }}
#define U_JPAD CONT_UP
#define G_RM_AA_OPA_SURF2 RM_AA_OPA_SURF(2)
#define SPSTATUS_CLEAR_HALT 0x00000001
#define gSPSetGeometryMode(pkt,word) gSPGeometryMode((pkt),0,(word))
#define RM_OPA_SURF(clk) CVG_DST_CLAMP | FORCE_BL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)
#define G_IM_SIZ_8b_SHIFT 1
#define G_CCMUX_TEXEL0 1
#define G_CCMUX_TEXEL1 2
#define A_INTERLEAVE 13
#define G_ACMUX_ENVIRONMENT 5
#define G_MWO_MATRIX_WZ_WW_F 0x3c
#define G_MWO_MATRIX_WZ_WW_I 0x1c
#define RESET_TYPE_COLD_RESET 0
#define G_CCMUX_LOD_FRACTION 13
#define RM_AA_ZB_SUB_TERR(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define Z_UPD 0x20
#define G_TRI_TXTR_ZBUFF 0xcb
#define OS_EVENT_RDB_READ_DONE 15
#define G_RM_XLU_SURF RM_XLU_SURF(1)
#define gSPScisTextureRectangle(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(MAX((s16)(xh),0), 12, 12) | _SHIFTL(MAX((s16)(yh),0), 0, 12)); _g->words.w1 = (_SHIFTL((tile), 24, 3) | _SHIFTL(MAX((s16)(xl),0), 12, 12) | _SHIFTL(MAX((s16)(yl),0), 0, 12)); gImmp1(pkt, G_RDPHALF_1, (_SHIFTL(((s) - (((s16)(xl) < 0) ? (((s16)(dsdx) < 0) ? (MAX((((s16)(xl)*(s16)(dsdx))>>7),0)) : (MIN((((s16)(xl)*(s16)(dsdx))>>7),0))) : 0)), 16, 16) | _SHIFTL(((t) - (((yl) < 0) ? (((s16)(dtdy) < 0) ? (MAX((((s16)(yl)*(s16)(dtdy))>>7),0)) : (MIN((((s16)(yl)*(s16)(dtdy))>>7),0))) : 0)), 0, 16))); gImmp1(pkt, G_RDPHALF_2, (_SHIFTL((dsdx), 16, 16) | _SHIFTL((dtdy), 0, 16))); }
#define gDPSetPrimDepth(pkt,z,dz) gDPSetColor(pkt, G_SETPRIMDEPTH, _SHIFTL(z, 16, 16) | _SHIFTL(dz, 0, 16))
#define gSPForceMatrix(pkt,mptr) { gDma2p((pkt),G_MOVEMEM,(mptr),sizeof(Mtx),G_MV_MATRIX,0); gMoveWd((pkt), G_MW_FORCEMTX,0,0x00010000); }
#define gsSPDma_io(flag,dmem,dram,size) {{ _SHIFTL(G_DMA_IO,24,8)|_SHIFTL((flag),23,1)| _SHIFTL((dmem)/8,13,10)|_SHIFTL((size)-1,0,12), (unsigned int)(dram) }}
#define G_CYC_2CYCLE (1 << G_MDSFT_CYCLETYPE)
#define SP_DRAM_STACK_SIZE8 0x400
#define gsDPLoadTLUT(count,tmemaddr,dram) gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram), gsDPTileSync(), gsDPSetTile(0, 0, 0, tmemaddr, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0), gsDPLoadSync(), gsDPLoadTLUTCmd(G_TX_LOADTILE, ((count)-1)), gsDPPipeSync()
#define OS_EVENT_SW2 1
#define OS_VI_PAL_HAN1 24
#define G_MWO_CLIP_RNX 0x04
#define G_SC_EVEN_INTERLACE 2
#define gSPSetOtherMode(pkt,cmd,sft,len,data) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(cmd,24,8)|_SHIFTL(32-(sft)-(len),8,8)| _SHIFTL((len)-1,0,8)); _g->words.w1 = (unsigned int)(data); }
#define G_SETFILLCOLOR 0xf7
#define G_CC_BLENDI2 ENVIRONMENT, SHADE, COMBINED, SHADE, 0, 0, 0, SHADE
#define OS_IM_PRENMI 0x00001401
#define G_CC_BLENDIA ENVIRONMENT, SHADE, TEXEL0, SHADE, TEXEL0, 0, SHADE, 0
#define CALC_DXT_4b(width) (((1 << G_TX_DXT_FRAC) + TXL2WORDS_4b(width) - 1) / TXL2WORDS_4b(width))
#define gsMoveWd(index,offset,data) gsDma1p( G_MOVEWORD, data, offset, index)
#define G_RM_AA_PCL_SURF RM_AA_PCL_SURF(1)
#define G_ACMUX_0 7
#define gsDPLoadMultiBlock(timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz ##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, CALC_DXT(width, siz ##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz ##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define gSPSetLights1(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_1); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.a,2); }
#define gSPClearGeometryMode(pkt,word) gSPGeometryMode((pkt),(word),0)
#define G_MW_CLIP 0x04
#define SPSTATUS_SIGNAL1_SET 0x0100
#define G_CYC_FILL (3 << G_MDSFT_CYCLETYPE)
#define G_CC_ADDRGB 1, 0, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_SPECIAL_1 0xd5
#define G_SPECIAL_2 0xd4
#define G_SPECIAL_3 0xd3
#define RM_AA_ZB_XLU_DECAL(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_DEC | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_SETKEYR 0xeb
#define G_CULL_BOTH 0x00000600
#define G_RM_AA_XLU_LINE RM_AA_XLU_LINE(1)
#define gsSPSetLights3(name) gsSPNumLights(NUMLIGHTS_3), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.a,4)
#define G_BL_CLR_FOG 3
#define gSPDma_io(pkt,flag,dmem,dram,size) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_DMA_IO,24,8)|_SHIFTL((flag),23,1)| _SHIFTL((dmem)/8,13,10)|_SHIFTL((size)-1,0,12); _g->words.w1 = (unsigned int)(dram); }
#define RM_RA_ZB_OPA_INTER(clk) AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ALPHA_CVG_SEL | ZMODE_INTER | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define G_CC_BLENDPEDECALA PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0
#define START_BUTTON CONT_START
#define EXEC_PROCESS_DEAD 3
#define G_IM_SIZ_32b_TILE_BYTES 2
#define G_CC_PASS2 0, 0, 0, COMBINED, 0, 0, 0, COMBINED
#define OS_FLAG_FAULT 2
#define RM_ZB_XLU_DECAL(clk) Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_DEC | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define gDPSetCombineKey(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_COMBKEY, 1, type)
#define G_CC_BLENDPE PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, SHADE, 0
#define DPRGBColor(pkt,cmd,r,g,b,a) gDPSetColor(pkt, cmd, (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)))
#define OS_NUM_EVENTS 23
#define A_MAIN 0x00
#define G_IM_SIZ_8b_INCR 1
#define G_CC_SHADEDECALA 0, 0, 0, SHADE, 0, 0, 0, TEXEL0
#define G_BL_0 3
#define _LIBULTRA_H 
#define _gDPLoadTextureBlock_4b(pkt,timg,tmem,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define G_IM_SIZ_4b_BYTES 0
#define gsDPLoadTile(t,uls,ult,lrs,lrt) gsDPLoadTileGeneric(G_LOADTILE, t, uls, ult, lrs, lrt)
#define G_IM_SIZ_8b_LINE_BYTES G_IM_SIZ_8b_BYTES
#define gDPSetFillColor(pkt,d) gDPSetColor(pkt, G_SETFILLCOLOR, (d))
#define G_IM_SIZ_16b_SHIFT 0
#define gDPLoadTextureBlock_4bS(pkt,timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, 0 ); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define gsSPDisplayList(dl) gsDma1p( G_DL,dl,0,G_DL_PUSH)
#define EEPROM_TYPE_16K 0x02
#define gsSPSetLights0(name) gsSPNumLights(NUMLIGHTS_0), gsSPLight(&name.l[0],1), gsSPLight(&name.a,2)
#define gDPParam(pkt,cmd,param) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(cmd, 24, 8); _g->words.w1 = (param); }
#define gsSPSetLights1(name) gsSPNumLights(NUMLIGHTS_1), gsSPLight(&name.l[0],1), gsSPLight(&name.a,2)
#define G_FILLRECT 0xf6
#define FR_NEG_FRUSTRATIO_1 0x00000001
#define FR_NEG_FRUSTRATIO_2 0x00000002
#define FR_NEG_FRUSTRATIO_3 0x00000003
#define FR_NEG_FRUSTRATIO_4 0x00000004
#define FR_NEG_FRUSTRATIO_5 0x00000005
#define FR_NEG_FRUSTRATIO_6 0x00000006
#define G_ROTATE_FRAC 16
#define RM_RA_OPA_SURF(clk) AA_EN | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gDPNoParam(pkt,cmd) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(cmd, 24, 8); _g->words.w1 = 0; }
#define G_CC_HILITERGBA PRIMITIVE, SHADE, TEXEL0, SHADE, PRIMITIVE, SHADE, TEXEL0, SHADE
#define gsSPSetLights5(name) gsSPNumLights(NUMLIGHTS_5), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.l[4],5), gsSPLight(&name.a,6)
#define G_CD_ENABLE G_CD_NOISE
#define G_DMACMDSIZ 128
#define G_TC_CONV (0 << G_MDSFT_TEXTCONV)
#define CONT_EEPROM 0x8000
#define gDPFillRectangle(pkt,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10)); _g->words.w1 = (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10));}
#define CONT_B 0x4000
#define CONT_D 0x0004
#define CONT_E 0x0008
#define CONT_F 0x0001
#define CONT_G 0x2000
#define G_CC_HILITERGBDECALA PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define CONT_L 0x0020
#define CONT_R 0x0010
#define gDPSetColorImage(pkt,f,s,w,i) gSetImage(pkt, G_SETCIMG, f, s, w, i)
#define M_HVQTASK 6
#define gSPPopMatrixN(pkt,n,num) gDma2p((pkt),G_POPMTX,(num)*64,64,2,0)
#define gsDPSetDepthSource(src) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_ZSRCSEL, 1, src)
#define gsDPSetCombineKey(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_COMBKEY, 1, type)
#define gsDma1p(c,s,l,p) {{ (_SHIFTL((c), 24, 8) | _SHIFTL((p), 16, 8) | _SHIFTL((l), 0, 16)), (unsigned int)(s) }}
#define G_TRI_FILL 0xc8
#define FR_POS_FRUSTRATIO_2 0x0000fffe
#define FR_POS_FRUSTRATIO_3 0x0000fffd
#define FR_POS_FRUSTRATIO_4 0x0000fffc
#define FR_POS_FRUSTRATIO_6 0x0000fffa
#define G_BL_A_IN 0
#define gsDPLoadTLUT_pal256(dram) gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram), gsDPTileSync(), gsDPSetTile(0, 0, 0, 256, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0), gsDPLoadSync(), gsDPLoadTLUTCmd(G_TX_LOADTILE, 255), gsDPPipeSync()
#define G_ACMUX_PRIMITIVE 3
#define gsDPLoadBlock(tile,uls,ult,lrs,dxt) {{ (_SHIFTL(G_LOADBLOCK, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL((MIN(lrs,G_TX_LDBLK_MAX_TXL)), 12, 12) | _SHIFTL(dxt, 0, 12)) }}
#define G_TD_SHARPEN (1 << G_MDSFT_TEXTDETAIL)
#define G_CCMUX_SHADE_ALPHA 11
#define G_CC_MODULATERGBDECALA G_CC_MODULATEIDECALA
#define gsDPSetBlendMask(mask) gsDPNoOp()
#define aResample(pkt,f,p,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(p, 0, 16)); _a->words.w1 = (unsigned int)(s); }
#define gDPSetKeyR(pkt,cR,sR,wR) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETKEYR, 24, 8); _g->words.w1 = (_SHIFTL(wR, 16, 12) | _SHIFTL(cR, 8, 8) | _SHIFTL(sR, 0, 8)); }
#define G_CCMUX_1 6
#define gsSPSetLights2(name) gsSPNumLights(NUMLIGHTS_2), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.a,3)
#define gsSPSetLights4(name) gsSPNumLights(NUMLIGHTS_4), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.a,5)
#define G_CCMUX_TEXEL1_ALPHA 9
#define gsSPSetLights6(name) gsSPNumLights(NUMLIGHTS_6), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.l[4],5), gsSPLight(&name.l[5],6), gsSPLight(&name.a,7)
#define gsSPSetLights7(name) gsSPNumLights(NUMLIGHTS_7), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.l[4],5), gsSPLight(&name.l[5],6), gsSPLight(&name.l[6],7), gsSPLight(&name.a,8)
#define G_PM_NPRIMITIVE (0 << G_MDSFT_PIPELINE)
#define gsDPSetAlphaCompare(type) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, type)
#define G_RM_AA_ZB_TEX_INTER RM_AA_ZB_TEX_INTER(1)
#define G_RM_AA_ZB_OPA_INTER RM_AA_ZB_OPA_INTER(1)
#define SPSTATUS_SET_SIGNAL0 0x00000400
#define SPSTATUS_SET_SIGNAL1 0x00001000
#define SPSTATUS_SET_SIGNAL2 0x00004000
#define SPSTATUS_SET_SIGNAL4 0x00040000
#define SPSTATUS_SET_SIGNAL5 0x00100000
#define SPSTATUS_SET_SIGNAL6 0x00800000
#define gSetImage(pkt,cmd,fmt,siz,width,i) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(cmd, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width)-1, 0, 12); _g->words.w1 = (unsigned int)(i); }
#define G_RM_AA_ZB_XLU_DECAL2 RM_AA_ZB_XLU_DECAL(2)
#define G_CC_MODULATERGBA_PRIM2 G_CC_MODULATEIA_PRIM2
#define OS_WRITE 1
#define gsDPSetColorImage(f,s,w,i) gsSetImage(G_SETCIMG, f, s, w, i)
#define OS_VI_PAL_HPF2 27
#define G_IM_SIZ_16b_LINE_BYTES G_IM_SIZ_16b_BYTES
#define gsSPDmaRead(dmem,dram,size) gsSPDma_io(0,(dmem),(dram),(size))
#define gsDPLoadTextureBlockS(timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz ##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz ##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt,shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, 0 ), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz ##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define G_MV_MATRIX 14
#define G_CLIPPING 0x00800000
#define CVG_X_ALPHA 0x1000
#define G_PM_1PRIMITIVE (1 << G_MDSFT_PIPELINE)
#define SPSTATUS_SIGNAL0_SET 0x0080
#define G_CCMUX_ENVIRONMENT 5
#define A_VOL 0x04
#define gsSPPerspNormalize(s) gsMoveWd( G_MW_PERSPNORM, 0, (s))
#define gDPSetTextureLOD(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTLOD, 1, type)
#define G_RM_AA_ZB_XLU_INTER2 RM_AA_ZB_XLU_INTER(2)
#define GCCc0w0(saRGB0,mRGB0,saA0,mA0) (_SHIFTL((saRGB0), 20, 4) | _SHIFTL((mRGB0), 15, 5) | _SHIFTL((saA0), 12, 3) | _SHIFTL((mA0), 9, 3))
#define GCCc0w1(sbRGB0,aRGB0,sbA0,aA0) (_SHIFTL((sbRGB0), 28, 4) | _SHIFTL((aRGB0), 15, 3) | _SHIFTL((sbA0), 12, 3) | _SHIFTL((aA0), 9, 3))
#define RM_AA_SUB_TERR(clk) AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define SPSTATUS_SET_SIGNAL3 0x00010000
#define gImmp21(pkt,c,p0,p1,dat) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL((c), 24, 8) | _SHIFTL((p0), 8, 16) | _SHIFTL((p1), 0, 8)); _g->words.w1 = (unsigned int) (dat); }
#define RM_OPA_CI(clk) CVG_DST_CLAMP | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)
#define gsSPTextureRectangleFlip(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) {{(_SHIFTL(G_TEXRECTFLIP, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12))}}, gsImmp1(G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))), gsImmp1(G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)))
#define OS_MESG_BLOCK 1
#define SPSTATUS_SET_SIGNAL7 0x02000000
#define gsSPLightColor(n,col) gsMoveWd(G_MW_LIGHTCOL, G_MWO_a ##n, col), gsMoveWd(G_MW_LIGHTCOL, G_MWO_b ##n, col)
#define G_RM_AA_ZB_SUB_TERR2 RM_AA_ZB_SUB_TERR(2)
#define A_LOADBUFF 4
#define GDMACMD(x) (x)
#define G_CC_HILITERGBPASSA2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, COMBINED
#define gsSPClipRatio(r) gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RNX, FR_NEG_ ##r), gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RNY, FR_NEG_ ##r), gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RPX, FR_POS_ ##r), gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RPY, FR_POS_ ##r)
#define OS_VI_PAL_HPN1 22
#define OS_VI_PAL_HPN2 26
#define OS_EVENT_FAULT 12
#define G_MDSFT_COMBKEY 8
#define G_TEXTURE_ENABLE 0x00000000
#define gsDPSetTextureLOD(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTLOD, 1, type)
#define gsDPSetFogColor(r,g,b,a) sDPRGBColor(G_SETFOGCOLOR, r,g,b,a)
#define RM_AA_XLU_SURF(clk) AA_EN | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define OS_MESG_NOBLOCK 0
#define gSPSprite2DDraw(pkt,px,py) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SPRITE2D_DRAW, 24, 8)); _g->words.w1 = (_SHIFTL((px), 16, 16) | _SHIFTL((py), 0, 16)); }
#define gDPLoadTLUTCmd(pkt,tile,count) { Gfx *_g = (Gfx *)pkt; _g->words.w0 = _SHIFTL(G_LOADTLUT, 24, 8); _g->words.w1 = _SHIFTL((tile), 24, 3) | _SHIFTL((count), 14, 10);}
#define GIMMCMD(x) (G_IMMFIRST-(x))
#define G_CC_BLENDIDECALA ENVIRONMENT, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define G_RM_AA_ZB_SUB_SURF RM_AA_ZB_SUB_SURF(1)
#define RM_VISCVG(clk) IM_RD | FORCE_BL | GBL_c ##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_BL, G_BL_A_MEM)
#define MAX_RATIO 1.99996
#define G_MWO_aLIGHT_2 0x18
#define G_MWO_aLIGHT_3 0x30
#define G_MWO_aLIGHT_4 0x48
#define G_MWO_aLIGHT_5 0x60
#define G_MWO_aLIGHT_6 0x78
#define G_MWO_aLIGHT_8 0xa8
#define gSPSetLights2(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_2); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.a,3); }
#define gSPSetLights3(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_3); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.a,4); }
#define gSPSetLights4(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_4); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.a,5); }
#define gSPSetLights5(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_5); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.l[4],5); gSPLight(pkt,&name.a,6); }
#define gSPSetLights7(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_7); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.l[4],5); gSPLight(pkt,&name.l[5],6); gSPLight(pkt,&name.l[6],7); gSPLight(pkt,&name.a,8); }
#define gsSPLine3D(v0,v1,flag) {{ _SHIFTL(G_LINE3D, 24, 8)|__gsSPLine3D_w1f(v0, v1, 0, flag), 0 }}
#define gDPLoadTextureTile(pkt,timg,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz, width, timg); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz ##_TILE_BYTES)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz ##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }
#define OS_VI_DIVOT 0x10
#define gsSPLoadUcodeL(ucode) gsSPLoadUcode(OS_K0_TO_PHYSICAL(& ##ucode ##TextStart), OS_K0_TO_PHYSICAL(& ##ucode ##DataStart))
#define RM_ADD(clk) IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1)
#define _ABI_H_ 
#define gsSPVertex(v,n,v0) {{ (_SHIFTL(G_VTX,24,8)|_SHIFTL((n),12,8)|_SHIFTL((v0)+(n),1,7)), (unsigned int)(v) }}
#define G_CD_BAYER (1 << G_MDSFT_RGBDITHER)
#define G_CC_MODULATEIA_PRIM2 COMBINED, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0
#define G_RM_CLD_SURF RM_CLD_SURF(1)
#define SPSTATUS_SIGNAL7_SET 0x4000
#define G_MWO_SEGMENT_0 0x00
#define _ULTRA64_TIME_H_ 
#define G_MWO_SEGMENT_2 0x02
#define G_MWO_SEGMENT_3 0x03
#define G_MWO_SEGMENT_4 0x04
#define G_MWO_SEGMENT_5 0x05
#define G_MWO_SEGMENT_6 0x06
#define G_MWO_SEGMENT_7 0x07
#define G_MWO_SEGMENT_8 0x08
#define G_MWO_SEGMENT_9 0x09
#define OS_EVENT_RDB_REQ_RAMROM 18
#define G_MWO_SEGMENT_A 0x0a
#define G_MWO_SEGMENT_B 0x0b
#define G_MWO_SEGMENT_C 0x0c
#define G_MWO_SEGMENT_D 0x0d
#define G_MWO_SEGMENT_E 0x0e
#define G_MWO_SEGMENT_F 0x0f
#define gsDPSetTextureLUT(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, type)
#define OS_PM_16K 0x0006000
#define OS_PM_16M 0x1ffe000
#define gsSPDmaWrite(dmem,dram,size) gsSPDma_io(1,(dmem),(dram),(size))
#define gSPSprite2DScaleFlip(pkt,sx,sy,fx,fy) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SPRITE2D_SCALEFLIP, 24, 8) | _SHIFTL((fx), 8, 8) | _SHIFTL((fy), 0, 8)); _g->words.w1 = (_SHIFTL((sx), 16, 16) | _SHIFTL((sy), 0, 16)); }
#define A_SETBUFF 8
#define SPSTATUS_CLEAR_SIGNAL0 0x00000200
#define SPSTATUS_CLEAR_SIGNAL1 0x00000800
#define SPSTATUS_CLEAR_SIGNAL2 0x00002000
#define SPSTATUS_CLEAR_SIGNAL3 0x00008000
#define SPSTATUS_CLEAR_SIGNAL4 0x00020000
#define SPSTATUS_CLEAR_SIGNAL5 0x00080000
#define SPSTATUS_CLEAR_SIGNAL6 0x00200000
#define SPSTATUS_CLEAR_SIGNAL7 0x01000000
#define RM_RA_ZB_OPA_SURF(clk) AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define gSPTextureRectangle(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); gImmp1(pkt, G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))); gImmp1(pkt, G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)));}
#define G_TEXTURE_GEN_LINEAR 0x00080000
#define SPSTATUS_CLEAR_BROKE 0x00000004
#define gsSPModifyVertex(vtx,where,val) {{ _SHIFTL(G_MODIFYVTX,24,8)| _SHIFTL((where),16,8)|_SHIFTL((vtx)*2,0,16), (unsigned int)(val) }}
#define A_BUTTON CONT_A
#define OS_VI_DITHER_FILTER_ON 0x0040
#define CONT_ERR_NO_CONTROLLER PFS_ERR_NOPACK
#define __gsSPLine3D_w1(v0,v1,wd) (_SHIFTL((v0)*2,16,8)|_SHIFT((v1)*2,8,8)|_SHIFT((wd),0,8))
#define gsSPFogFactor(fm,fo) gsMoveWd(G_MW_FOG, G_MWO_FOG, (_SHIFTL(fm,16,16) | _SHIFTL(fo,0,16)))
#define gSPBranchLessZ(pkt,dl,vtx,zval,near,far,flag) gSPBranchLessZrg(pkt, dl, vtx, zval, near, far, flag, 0, G_MAXZ)
#define G_TX_CLAMP 0x2
#define gsSPSprite2DBase(s) gsDma1p(G_SPRITE2D_BASE, s, sizeof(uSprite), 0)
#define G_CC_MODULATERGBA_PRIM G_CC_MODULATEIA_PRIM
#define G_MWO_MATRIX_XX_XY_F 0x20
#define G_CC_ADDRGBDECALA 1, 0, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_MODULATEI_PRIM2 COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE
#define gsDPFillRectangle(ulx,uly,lrx,lry) {{ (_SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10)), (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10)) }}
#define G_MDSFT_TEXTFILT 12
#define G_SETOTHERMODE_L 0xe2
#define G_MDSFT_TEXTPERSP 19
#define gsDPPipelineMode(mode) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_PIPELINE, 1, mode)
#define TXL2WORDS_4b(txls) MAX(1, ((txls)/16))
#define gsSPCullDisplayList(vstart,vend) {{ _SHIFTL(G_CULLDL, 24, 8) | _SHIFTL((vstart)*2, 0, 16), _SHIFTL((vend)*2, 0, 16) }}
#define gsDPLoadTextureBlock_4b(timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)
#define A_INIT 0x01
#define OS_STATE_WAITING 8
#define __gsSP1Quadrangle_w1f(v0,v1,v2,v3,flag) (((flag) == 0) ? __gsSP1Triangle_w1(v0, v1, v2): ((flag) == 1) ? __gsSP1Triangle_w1(v1, v2, v3): ((flag) == 2) ? __gsSP1Triangle_w1(v2, v3, v0): __gsSP1Triangle_w1(v3, v0, v1))
#define R_JPAD CONT_RIGHT
#define aSetLoop(pkt,a) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_SETLOOP, 24, 8); _a->words.w1 = (unsigned int)(a); }
#define G_IM_FMT_I 4
#define gsDPNoParam(cmd) {{ _SHIFTL(cmd, 24, 8), 0 }}
#define A_SEGMENT 7
#define G_RM_PCL_SURF RM_PCL_SURF(1)
#define G_ACMUX_LOD_FRACTION 0
#define gdSPDefLights0(ar,ag,ab) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ { 0, 0, 0},0,{ 0, 0, 0},0,{ 0, 0, 0},0}}} }
#define gdSPDefLights1(ar,ag,ab,r1,g1,b1,x1,y1,z1) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}} }
#define gdSPDefLights2(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}} }
#define gdSPDefLights3(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}} }
#define gdSPDefLights4(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}} }
#define gdSPDefLights5(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4,r5,g5,b5,x5,y5,z5) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}, {{ {r5,g5,b5},0,{r5,g5,b5},0,{x5,y5,z5},0}}} }
#define G_AD_PATTERN (0 << G_MDSFT_ALPHADITHER)
#define gdSPDefLights7(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4,r5,g5,b5,x5,y5,z5,r6,g6,b6,x6,y6,z6,r7,g7,b7,x7,y7,z7) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}, {{ {r5,g5,b5},0,{r5,g5,b5},0,{x5,y5,z5},0}}, {{ {r6,g6,b6},0,{r6,g6,b6},0,{x6,y6,z6},0}}, {{ {r7,g7,b7},0,{r7,g7,b7},0,{x7,y7,z7},0}}} }
#define __gsSP1Quadrangle_w2f(v0,v1,v2,v3,flag) (((flag) == 0) ? __gsSP1Triangle_w1(v0, v2, v3): ((flag) == 1) ? __gsSP1Triangle_w1(v1, v3, v0): ((flag) == 2) ? __gsSP1Triangle_w1(v2, v0, v1): __gsSP1Triangle_w1(v3, v1, v2))
#define gDPSetColor(pkt,c,d) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(c, 24, 8); _g->words.w1 = (unsigned int)(d); }
#define gsDPParam(cmd,param) {{ _SHIFTL(cmd, 24, 8), (param) }}
#define G_TT_IA16 (3 << G_MDSFT_TEXTLUT)
#define gSPLoadUcodeL(pkt,ucode) gSPLoadUcode((pkt), OS_K0_TO_PHYSICAL(& ##ucode ##TextStart), OS_K0_TO_PHYSICAL(& ##ucode ##DataStart))
#define TV_TYPE_PAL 0
#define G_BL_A_SHADE 2
#define G_SETFOGCOLOR 0xf8
#define G_CCMUX_0 31
#define gSPLookAtX(pkt,l) gDma2p((pkt),G_MOVEMEM,(l),sizeof(Light),G_MV_LIGHT,G_MVO_LOOKATX)
#define gSPLookAtY(pkt,l) gDma2p((pkt),G_MOVEMEM,(l),sizeof(Light),G_MV_LIGHT,G_MVO_LOOKATY)
#define gDPScisFillRectangle(pkt,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL(MAX((lrx),0), 14, 10) | _SHIFTL(MAX((lry),0), 2, 10)); _g->words.w1 = (_SHIFTL(MAX((ulx),0), 14, 10) | _SHIFTL(MAX((uly),0), 2, 10)); }
#define G_TF_BILERP (2 << G_MDSFT_TEXTFILT)
#define G_MWO_MATRIX_XX_XY_I 0x00
#define gsDPSetMaskImage(i) gsDPSetDepthImage(i)
#define RM_ZB_PCL_SURF(clk) Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | G_AC_DITHER | GBL_c ##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)
#define A_OUT 0x02
#define OS_PRIORITY_APPMAX 127
#define G_RM_RA_ZB_OPA_SURF RM_RA_ZB_OPA_SURF(1)
#define gDPLoadBlock(pkt,tile,uls,ult,lrs,dxt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_LOADBLOCK, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL((MIN(lrs,G_TX_LDBLK_MAX_TXL)), 12, 12) | _SHIFTL(dxt, 0, 12)); }
#define G_TRI_TXTR 0xca
#define NULL (void *)0
#define _G_CC_SPARSEST PRIMITIVE, TEXEL0, LOD_FRACTION, TEXEL0, PRIMITIVE, TEXEL0, LOD_FRACTION, TEXEL0
#define G_BL_CLR_IN 0
#define OS_EVENT_PRENMI 14
#define RM_ZB_CLD_SURF(clk) Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_XLU | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_MTX 0xda
#define gSPFogFactor(pkt,fm,fo) gMoveWd(pkt, G_MW_FOG, G_MWO_FOG, (_SHIFTL(fm,16,16) | _SHIFTL(fo,0,16)))
#define RM_TEX_EDGE(clk) CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA | TEX_EDGE | AA_EN | GBL_c ##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)
#define gDPLoadTextureBlock_4b(pkt,timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define OS_VI_PAL_HPF1 23
#define OS_PRIORITY_VIMGR 254
#define OS_PRIORITY_RMONSPIN 200
#define G_RDPHALF_1 0xe1
#define G_RDPHALF_2 0xf1
#define G_CC_REFLECTRGBDECALA ENVIRONMENT, 0, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define OS_EVENT_RDB_ACK_PROF 22
#define __attribute__(...) 
#define aMix(pkt,f,g,i,o) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_MIXER, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16)); _a->words.w1 = _SHIFTL(i,16, 16) | _SHIFTL(o, 0, 16); }
#define G_MVO_LOOKATY (1*24)
#define G_RM_OPA_CI2 RM_OPA_CI(2)
#define G_RM_AA_ZB_TEX_TERR RM_AA_ZB_TEX_TERR(1)
#define _SHIFT _SHIFTL
#define SP_UCODE_SIZE 0x1000
#define gsDPSetDepthImage(i) gsSetImage(G_SETZIMG, 0, 0, 1, i)
#define G_RDPLOADSYNC 0xe6
#define OS_IM_SW2 0x00000601
#define gImmp1(pkt,c,p0) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = (unsigned int)(p0); }
#define gsDPNoOp() gsDPNoParam(G_NOOP)
#define G_IM_SIZ_4b_INCR 3
#define G_BZ_PERSP 0
#define aDMEMMove(pkt,i,o,c) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_DMEMMOVE, 24, 8) | _SHIFTL(i, 0, 24); _a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16); }
#define _ULTRA64_TYPES_H_ 
#define G_RM_NOOP2 RM_NOOP(2)
#define gDPSetDepthImage(pkt,i) gSetImage(pkt, G_SETZIMG, 0, 0, 1, i)
#define CONT_RELATIVE 0x0002
#define gDPLoadTLUT_pal16(pkt,pal,dram) { gDPSetTextureImage(pkt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram); gDPTileSync(pkt); gDPSetTile(pkt, 0, 0, 0, (256+(((pal)&0xf)*16)), G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0); gDPLoadSync(pkt); gDPLoadTLUTCmd(pkt, G_TX_LOADTILE, 15); gDPPipeSync(pkt) }
#define UNITY_PITCH 0x8000
#define G_RM_AA_ZB_DEC_LINE2 RM_AA_ZB_DEC_LINE(2)
#define gDPLoadTextureBlockYuvS(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1,0); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * 1)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define gsSPFogPosition(min,max) gsMoveWd(G_MW_FOG, G_MWO_FOG, (_SHIFTL((128000/((max)-(min))),16,16) | _SHIFTL(((500-(min))*256/((max)-(min))),0,16)))
#define MakeTexRect(xh,yh,flip,tile,xl,yl,s,t,dsdx,dtdy) G_TEXRECT, xh, yh, 0, flip, 0, tile, xl, yl, s, t, dsdx, dtdy
#define gSP1Quadrangle(pkt,v0,v1,v2,v3,flag) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_QUAD, 24, 8)| __gsSP1Quadrangle_w1f(v0, v1, v2, v3, flag)); _g->words.w1 = __gsSP1Quadrangle_w2f(v0, v1, v2, v3, flag); }
#define gDPSetDepthSource(pkt,src) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_ZSRCSEL, 1, src)
#define G_IM_SIZ_4b_LINE_BYTES G_IM_SIZ_4b_BYTES
#define gsDPLoadMultiTile_4b(timg,tmem,rtile,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_8b, ((width)>>1), timg), gsDPSetTile(fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)
#define G_RM_AA_DEC_LINE2 RM_AA_DEC_LINE(2)
#define gsImmp0(c) {{ _SHIFTL((c), 24, 8) }}
#define RM_NOOP(clk) GBL_c ##clk(0, 0, 0, 0)
#define gsImmp2(c,p0,p1) {{ _SHIFTL((c), 24, 8), _SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8)}}
#define gsImmp3(c,p0,p1,p2) {{ _SHIFTL((c), 24, 8), (_SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8) | _SHIFTL((p2), 0, 8))}}
#define RM_AA_ZB_TEX_TERR(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define gDPLoadTextureBlockS(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1,0); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz ##_LINE_BYTES)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define G_RM_AA_TEX_EDGE2 RM_AA_TEX_EDGE(2)
#define G_RM_ZB_CLD_SURF RM_ZB_CLD_SURF(1)
#define G_CD_DISABLE (3 << G_MDSFT_RGBDITHER)
#define gDPSetScissorFrac(pkt,mode,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)pkt; _g->words.w0 = _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((ulx)), 12, 12) | _SHIFTL((int)((uly)), 0, 12); _g->words.w1 = _SHIFTL(mode, 24, 2) | _SHIFTL((int)((lrx)), 12, 12) | _SHIFTL((int)((lry)), 0, 12); }
#define aADPCMdec(pkt,f,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(f, 16, 8); _a->words.w1 = (unsigned int)(s); }
#define OS_MESG_PRI_NORMAL 0
#define A_POLEF 14
#define gDPLoadMultiTile_4b(pkt,timg,tmem,rtile,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_8b, ((width)>>1), timg); gDPSetTile(pkt, fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }
#define gSPTextureRectangleFlip(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXRECTFLIP, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); gImmp1(pkt, G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))); gImmp1(pkt, G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); }
#define gSPClipRatio(pkt,r) { gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RNX, FR_NEG_ ##r); gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RNY, FR_NEG_ ##r); gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RPX, FR_POS_ ##r); gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RPY, FR_POS_ ##r); }
#define G_SETCONVERT 0xec
#define gsDPLoadSync() gsDPNoParam(G_RDPLOADSYNC)
#define OS_STATE_STOPPED 1
#define gsDPSetCycleType(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, type)
#define G_LOADTILE 0xf4
#define gsDPSetColorDither(mode) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, mode)
#define CONT_NO_RESPONSE_ERROR 0x8
#define _ULTRA64_THREAD_H_ 
#define G_CC_MODULATERGB G_CC_MODULATEI
#define A_AUX 0x08
#define gDPNoOpTag(pkt,tag) gDPParam(pkt, G_NOOP, tag)
#define G_MWO_bLIGHT_2 0x1c
#define G_CC_MODULATERGB_PRIM G_CC_MODULATEI_PRIM
#define L_TRIG CONT_L
#define aSetBuffer(pkt,f,i,o,c) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(i, 0, 16)); _a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16); }
#define G_RM_RA_ZB_OPA_DECAL RM_RA_ZB_OPA_DECAL(1)
#define gsSPPopMatrix(n) gsSPPopMatrixN( (n), 1)
#define G_TRI_SHADE_TXTR 0xce
#define OS_IM_AI 0x00040401
#define G_FOG 0x00010000
#define CONT_TYPE_MASK 0x1f07
#define OS_VI_UNK100 0x100
#define SEGMENT_OFFSET(a) ((unsigned int)(a) & 0x00ffffff)
#define __gsSP1Triangle_w1f(v0,v1,v2,flag) (((flag) == 0) ? __gsSP1Triangle_w1(v0, v1, v2): ((flag) == 1) ? __gsSP1Triangle_w1(v1, v2, v0): __gsSP1Triangle_w1(v2, v0, v1))
#define __PROCESS_H 
#define gsDPSetTexturePersp(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, type)
#define G_AC_DITHER (3 << G_MDSFT_ALPHACOMPARE)
#define G_CV_K4 114
#define gSPBranchLessZraw(pkt,dl,vtx,zval) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_RDPHALF_1,24,8); _g->words.w1 = (unsigned int)(dl); _g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_BRANCH_Z,24,8)| _SHIFTL((vtx)*5,12,12)|_SHIFTL((vtx)*2,0,12)); _g->words.w1 = (unsigned int)(zval); }
#define G_RM_ADD RM_ADD(1)
#define G_SETTILE 0xf5
#define OS_IM_DP 0x00200401
#define G_LOADBLOCK 0xf3
#define SPSTATUS_SET_INTR 0x00000010
#define ZMODE_DEC 0xc00
#define FORCE_BL 0x4000
#define F3DEX_GBI 
#define G_ZS_PRIM (1 << G_MDSFT_ZSRCSEL)
#define gDPTileSync(pkt) gDPNoParam(pkt, G_RDPTILESYNC)
#define FALSE 0
#define gsImmp21(c,p0,p1,dat) {{ _SHIFTL((c), 24, 8) | _SHIFTL((p0), 8, 16) | _SHIFTL((p1), 0, 8), (unsigned int) (dat) }}
#define G_MDSFT_BLENDER 16
#define G_SC_ODD_INTERLACE 3
#define gDPSetKeyGB(pkt,cG,sG,wG,cB,sB,wB) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETKEYGB, 24, 8) | _SHIFTL(wG, 12, 12) | _SHIFTL(wB, 0, 12)); _g->words.w1 = (_SHIFTL(cG, 24, 8) | _SHIFTL(sG, 16, 8) | _SHIFTL(cB, 8, 8) | _SHIFTL(sB, 0, 8)); }
#define G_TRI_FILL_ZBUFF 0xc9
#define G_RM_AA_ZB_OPA_TERR RM_AA_ZB_OPA_TERR(1)
#define G_ACMUX_PRIM_LOD_FRAC 6
#define G_TX_WRAP 0
#define _MBI_H_ 
#define MQ_IS_EMPTY(mq) (MQ_GET_COUNT(mq) == 0)
#define G_RM_AA_ZB_OPA_SURF2 RM_AA_ZB_OPA_SURF(2)
#define gSPLineW3D(pkt,v0,v1,wd,flag) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_LINE3D, 24, 8)| __gsSPLine3D_w1f(v0, v1, wd, flag); _g->words.w1 = 0; }
#define A_CONTINUE 0x00
#define G_RM_AA_ZB_XLU_INTER RM_AA_ZB_XLU_INTER(1)
#define TV_TYPE_NTSC 1
#define G_IM_SIZ_8b_TILE_BYTES G_IM_SIZ_8b_BYTES
#define _OS_TLB_H_ 
#define G_RDPSETOTHERMODE 0xef
#define G_RM_OPA_CI RM_OPA_CI(1)
#define RM_AA_PCL_SURF(clk) AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | G_AC_DITHER | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_CC_TEMPLERP TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0
#define OS_VI_GAMMA 0x08
#define RM_AA_ZB_OPA_TERR(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_RM_TEX_EDGE2 RM_TEX_EDGE(2)
#define G_RM_AA_SUB_SURF RM_AA_SUB_SURF(1)
#define gDPSetRenderMode(pkt,c0,c1) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, (c0) | (c1))
#define M_HVQMTASK 7
#define gsSPLookAtX(l) gsDma2p( G_MOVEMEM,(l),sizeof(Light),G_MV_LIGHT,G_MVO_LOOKATX)
#define gsSPLookAtY(l) gsDma2p( G_MOVEMEM,(l),sizeof(Light),G_MV_LIGHT,G_MVO_LOOKATY)
#define RM_AA_XLU_LINE(clk) AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_MODIFYVTX 0x02
#define RM_AA_ZB_TEX_INTER(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_INTER | TEX_EDGE | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define RM_XLU_SURF(clk) IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define gsSPLight(l,n) gsDma2p( G_MOVEMEM,(l),sizeof(Light),G_MV_LIGHT,(n)*24+24)
#define G_RM_AA_ZB_OPA_SURF RM_AA_ZB_OPA_SURF(1)
#define gDPSetHilite2Tile(pkt,tile,hilite,width,height) gDPSetTileSize(pkt, tile, (hilite)->h.x2 & 0xfff, (hilite)->h.y2 & 0xfff, ((((width)-1)*4)+(hilite)->h.x2) & 0xfff, ((((height)-1)*4)+(hilite)->h.y2) & 0xfff)
#define OS_EVENT_RDB_DATA_DONE 17
#define G_CC_SHADE 0, 0, 0, SHADE, 0, 0, 0, SHADE
#define G_MWO_FOG 0x00
#define G_RM_FOG_SHADE_A GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA)
#define G_ACMUX_1 6
#define G_CC_MODULATERGB2 G_CC_MODULATEI2
#define G_RM_VISCVG RM_VISCVG(1)
#define TEX_EDGE 0x0000
#define OS_IM_PI 0x00100401
#define G_MV_LIGHT 10
#define EEPROM_MAXBLOCKS 64
#define G_IM_SIZ_8b_BYTES 1
#define G_RM_AA_ZB_DEC_LINE RM_AA_ZB_DEC_LINE(1)
#define G_SETENVCOLOR 0xfb
#define G_RDP_TRI_SHADE_MASK 0x04
#define gsDPLoadTextureTile(timg,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz, width, timg), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz ##_TILE_BYTES)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC), gsDPPipeSync(), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz ##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)
#define gSPLoadUcodeEx(pkt,uc_start,uc_dstart,uc_dsize) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_RDPHALF_1,24,8); _g->words.w1 = (unsigned int)(uc_dstart); _g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_LOAD_UCODE,24,8)| _SHIFTL((int)(uc_dsize)-1,0,16)); _g->words.w1 = (unsigned int)(uc_start); }
#define OS_STATE_RUNNING 4
#define gsDPSetTileSize(t,uls,ult,lrs,lrt) gsDPLoadTileGeneric(G_SETTILESIZE, t, uls, ult, lrs, lrt)
#define SPSTATUS_IO_FULL 0x0010
#define OS_VI_PAL_LPF2 19
#define G_ACMUX_TEXEL0 1
#define G_ACMUX_TEXEL1 2
#define ZMODE_OPA 0
#define G_MW_FORCEMTX 0x0c
#define OS_IM_SP 0x00010401
#define G_TX_NOLOD 0
#define gsSPNumLights(n) gsMoveWd( G_MW_NUMLIGHT, G_MWO_NUMLIGHT, NUML(n))
#define G_MWO_MATRIX_WX_WY_F 0x38
#define G_MWO_MATRIX_WX_WY_I 0x18
#define OS_EVENT_RDB_FLUSH_PROF 21
#define G_MTX_PROJECTION 0x04
#define SP_UCODE_DATA_SIZE 0x800
#define NUML(n) ((n)*24)
#define G_RM_ZB_XLU_SURF2 RM_ZB_XLU_SURF(2)
#define aEnvMixer(pkt,f,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_ENVMIXER, 24, 8) | _SHIFTL(f, 16, 8); _a->words.w1 = (unsigned int)(s); }
#define G_MTX_MODELVIEW 0x00
#define RM_AA_ZB_DEC_LINE(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_DEC | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define gsSPSetOtherMode(cmd,sft,len,data) {{ _SHIFTL(cmd,24,8)|_SHIFTL(32-(sft)-(len),8,8)|_SHIFTL((len)-1,0,8), (unsigned int)(data) }}
#define OS_IM_VI 0x00080401
#define G_RM_NOOP RM_NOOP(1)
#define CLR_ON_CVG 0x80
#define G_MV_VIEWPORT 8
#define gsSPMatrix(m,p) gsDma2p( G_MTX,(m),sizeof(Mtx),(p)^G_MTX_PUSH,0)
#define G_MV_MMTX 2
#define G_SC_NON_INTERLACE 0
#define aLoadBuffer(pkt,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_LOADBUFF, 24, 8); _a->words.w1 = (unsigned int)(s); }
#define gsDPLoadTileGeneric(c,tile,uls,ult,lrs,lrt) {{ _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12)}}
#define D_CBUTTONS CONT_D
#define G_IM_SIZ_32b_LINE_BYTES 2
#define OS_VI_GAMMA_DITHER_OFF 0x0008
#define GCCc1w0(saRGB1,mRGB1) (_SHIFTL((saRGB1), 5, 4) | _SHIFTL((mRGB1), 0, 5))
#define GCCc1w1(sbRGB1,saA1,mA1,aRGB1,sbA1,aA1) (_SHIFTL((sbRGB1), 24, 4) | _SHIFTL((saA1), 21, 3) | _SHIFTL((mA1), 18, 3) | _SHIFTL((aRGB1), 6, 3) | _SHIFTL((sbA1), 3, 3) | _SHIFTL((aA1), 0, 3))
#define CALC_DXT(width,b_txl) (((1 << G_TX_DXT_FRAC) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))
#define G_IM_SIZ_4b 0
#define G_CCMUX_PRIMITIVE_ALPHA 10
#define CONT_RIGHT 0x0100
#define NUM_SEGMENTS (16)
#define G_IM_SIZ_8b_LOAD_BLOCK G_IM_SIZ_16b
#define G_MDSFT_ALPHADITHER 4
#define G_SETSCISSOR 0xed
#define G_RDPFULLSYNC 0xe9
#define G_RM_OPA_SURF2 RM_OPA_SURF(2)
#define G_RM_ZB_OPA_DECAL RM_ZB_OPA_DECAL(1)
#define gsDPSetCombineLERP(a0,b0,c0,d0,Aa0,Ab0,Ac0,Ad0,a1,b1,c1,d1,Aa1,Ab1,Ac1,Ad1) {{ _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(GCCc0w0(G_CCMUX_ ##a0, G_CCMUX_ ##c0, G_ACMUX_ ##Aa0, G_ACMUX_ ##Ac0) | GCCc1w0(G_CCMUX_ ##a1, G_CCMUX_ ##c1), 0, 24), (unsigned int)(GCCc0w1(G_CCMUX_ ##b0, G_CCMUX_ ##d0, G_ACMUX_ ##Ab0, G_ACMUX_ ##Ad0) | GCCc1w1(G_CCMUX_ ##b1, G_ACMUX_ ##Aa1, G_ACMUX_ ##Ac1, G_CCMUX_ ##d1, G_ACMUX_ ##Ab1, G_ACMUX_ ##Ad1)) }}
#define B_BUTTON CONT_B
#define G_RM_ZB_XLU_DECAL2 RM_ZB_XLU_DECAL(2)
#define G_IM_SIZ_16b_TILE_BYTES G_IM_SIZ_16b_BYTES
#define gsDPNoOpTag(tag) gsDPParam(G_NOOP, tag)
#define A_CLEARBUFF 2
#define gsDPSetFillColor(d) gsDPSetColor(G_SETFILLCOLOR, (d))
#define G_IM_SIZ_8b 1
#define G_CC_HILITERGBA2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, ENVIRONMENT, COMBINED, TEXEL0, COMBINED
#define G_RM_ZB_OPA_SURF RM_ZB_OPA_SURF(1)
#define gsSPForceMatrix(mptr) gsDma2p(G_MOVEMEM,(mptr),sizeof(Mtx),G_MV_MATRIX,0), gsMoveWd(G_MW_FORCEMTX,0,0x00010000)
#define G_DEPTOZSrg(zval,near,far,flag,zmin,zmax) (((unsigned int)FTOFIX32(((flag) == G_BZ_PERSP ? (1.0f-(float)(near)/(float)(zval)) / (1.0f-(float)(near)/(float)(far )) : ((float)(zval) - (float)(near)) / ((float)(far ) - (float)(near))))) * (((int)((zmax) - (zmin)))&~1) + (int)FTOFIX32(zmin))
#define OS_VI_NTSC_HAF1 11
#define gDPLoadMultiBlockS(pkt,timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1,0); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz ##_LINE_BYTES)+7)>>3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define gsSetImage(cmd,fmt,siz,width,i) {{ _SHIFTL(cmd, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width)-1, 0, 12), (unsigned int)(i) }}
#define G_CCMUX_K4 7
#define G_CCMUX_K5 15
#define G_RM_ZB_CLD_SURF2 RM_ZB_CLD_SURF(2)
#define gDPSetHilite1Tile(pkt,tile,hilite,width,height) gDPSetTileSize(pkt, tile, (hilite)->h.x1 & 0xfff, (hilite)->h.y1 & 0xfff, ((((width)-1)*4)+(hilite)->h.x1) & 0xfff, ((((height)-1)*4)+(hilite)->h.y1) & 0xfff)
#define G_RM_ZB_OVL_SURF RM_ZB_OVL_SURF(1)
#define G_DEPTOZS(zval,near,far,flag) G_DEPTOZSrg(zval, near, far, flag, 0, G_MAXZ)
#define _G_CC_BLENDPE ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, SHADE, 0
#define OS_PRIORITY_RMON 250
#define G_RM_AA_TEX_TERR RM_AA_TEX_TERR(1)
#define G_SETOTHERMODE_H 0xe3
#define ALPHA_CVG_SEL 0x2000
#define OS_VI_PAL_LAF1 17
#define OS_VI_PAL_LAF2 21
#define CONT_DOWN 0x0400
#define G_IM_SIZ_16b_BYTES 2
#define A_ENVMIXER 3
#define gsDPLoadTextureTile_4b(timg,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_8b, ((width)>>1), timg), gsDPSetTile(fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)
#define SPSTATUS_SIGNAL3_SET 0x0400
#define G_SETKEYGB 0xea
#define G_MDSFT_TEXTLOD 16
#define CONT_CARD_PULL 0x02
#define G_RM_ZB_OVL_SURF2 RM_ZB_OVL_SURF(2)
#define G_CC_INTERFERENCE TEXEL0, 0, TEXEL1, 0, TEXEL0, 0, TEXEL1, 0
#define gSPInsertMatrix(pkt,where,num) ERROR!! gSPInsertMatrix is no longer supported.
#define G_IM_SIZ_16b_LOAD_BLOCK G_IM_SIZ_16b
#define OS_DCACHE_ROUNDUP_SIZE(x) (u32)(((((u32)(x)+0xf)/0x10)*0x10))
#define G_MWO_MATRIX_YX_YY_I 0x08
#define gsDPSetTextureDetail(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTDETAIL, 2, type)
#define G_CC_MODULATEI TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE
#define _OS_EEPROM_H_ 
#define _gDPLoadTextureBlockTile(pkt,timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, CALC_DXT(width, siz ##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz ##_LINE_BYTES)+7)>>3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define OS_EVENT_AI 6
#define gDPSetEnvColor(pkt,r,g,b,a) DPRGBColor(pkt, G_SETENVCOLOR, r,g,b,a)
#define gSPLoadUcode(pkt,uc_start,uc_dstart) gSPLoadUcodeEx((pkt), (uc_start), (uc_dstart), SP_UCODE_DATA_SIZE)
#define CONT_TYPE_NORMAL 0x0005
#define gsSPLineW3D(v0,v1,wd,flag) {{ _SHIFTL(G_LINE3D, 24, 8)|__gsSPLine3D_w1f(v0, v1, wd, flag), 0 }}
#define OS_VI_NTSC_HAN1 10
#define gSPMatrix(pkt,m,p) gDma2p((pkt),G_MTX,(m),sizeof(Mtx),(p)^G_MTX_PUSH,0)
#define G_SETZIMG 0xfe
#define G_TC_FILTCONV (5 << G_MDSFT_TEXTCONV)
#define G_DL 0xde
#define SPSTATUS_CLEAR_INTR_ON_BREAK 0x00000080
#define R_CBUTTONS CONT_F
#define OS_PRIORITY_SIMGR 140
#define G_SETPRIMCOLOR 0xfa
#define OS_EVENT_DP 9
#define EXEC_PROCESS_WATCH 2
#define G_CC_MODULATERGB_PRIM2 G_CC_MODULATEI_PRIM2
#define OS_VI_PAL_LAN1 16
#define OS_VI_PAL_LAN2 20
#define OS_EVENT_RDB_FREE_RAMROM 19
#define G_ENDDL 0xdf
#define gSPLookAt(pkt,la) { gSPLookAtX(pkt,la) gSPLookAtY(pkt,(char *)(la)+16) }
#define G_MDSFT_TEXTLUT 14
#define A_SETVOL 9
#define G_MWO_SEGMENT_1 0x01
#define A_DMEMMOVE 10
#define GPACK_RGBA5551(r,g,b,a) ((((r)<<8) & 0xf800) | (((g)<<3) & 0x7c0) | (((b)>>2) & 0x3e) | ((a) & 0x1))
#define gDPSetTexturePersp(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, type)
#define OS_STATE_RUNNABLE 2
#define A_LOADADPCM 11
#define gsDPSetCombineMode(a,b) gsDPSetCombineLERP(a, b)
#define gSPViewport(pkt,v) gDma2p((pkt), G_MOVEMEM, (v), sizeof(Vp), G_MV_VIEWPORT, 0)
#define G_TP_PERSP (1 << G_MDSFT_TEXTPERSP)
#define G_DMA_IO 0xd6
#define OS_VI_DIVOT_OFF 0x0020
#define G_MWO_POINT_RGBA 0x10
#define CONT_LEFT 0x0200
#define G_RDPTILESYNC 0xe8
#define _ULTRA64_VI_H_ 
#define G_BL_1MA 0
#define gsDPTextureRectangle(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) {{ (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)), }}, {{ _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16), _SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16) }}
#define gDPPipeSync(pkt) gDPNoParam(pkt, G_RDPPIPESYNC)
#define CVG_DST_FULL 0x200
#define G_CC_MODULATEIDECALA_PRIM TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0
#define gsSPEndDisplayList() {{ _SHIFTL(G_ENDDL, 24, 8), 0 }}
#define RM_AA_ZB_OPA_INTER(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ALPHA_CVG_SEL | ZMODE_INTER | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define A_SPNOOP 0
#define gsSPSprite2DDraw(px,py) {{ (_SHIFTL(G_SPRITE2D_DRAW, 24, 8)), (_SHIFTL((px), 16, 16) | _SHIFTL((py), 0, 16)) }}
#define G_RM_FOG_PRIM_A GBL_c1(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_IN, G_BL_1MA)
#define _LANGUAGE_C 1
#define gSPTextureL(pkt,s,t,level,xparam,tile,on) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXTURE,24,8) | _SHIFTL((xparam),16,8) | _SHIFTL((level),11,3) | _SHIFTL((tile),8,3) | _SHIFTL((on),1,7)); _g->words.w1 = (_SHIFTL((s),16,16) | _SHIFTL((t),0,16)); }
#define gDPSetPrimColor(pkt,m,l,r,g,b,a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)); _g->words.w1 = (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)); }
#define G_RDPCMDSIZ 64
#define gSPDisplayList(pkt,dl) gDma1p(pkt,G_DL,dl,0,G_DL_PUSH)
#define G_CULLDL 0x03
#define OS_EVENT_THREADSTATUS 13
#define gDPLoadMultiBlock(pkt,timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz ##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz ##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz ##_INCR) >> siz ##_SHIFT)-1, CALC_DXT(width, siz ##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz ##_LINE_BYTES)+7)>>3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }
#define G_MW_LIGHTCOL 0x0a
#define gsSPSprite2DScaleFlip(sx,sy,fx,fy) {{ (_SHIFTL(G_SPRITE2D_SCALEFLIP, 24, 8) | _SHIFTL((fx), 8, 8) | _SHIFTL((fy), 0, 8)), (_SHIFTL((sx), 16, 16) | _SHIFTL((sy), 0, 16)) }}
#define A_RESAMPLE 5
#define G_RM_AA_OPA_TERR RM_AA_OPA_TERR(1)
#define G_MDSFT_COLORDITHER 22
#define _ULTRA64_OS_INTERNAL_H_ 
#define G_ON (1)
#define G_MW_FOG 0x08
#define gsSPLoadUcode(uc_start,uc_dstart) gsSPLoadUcodeEx((uc_start), (uc_dstart), SP_UCODE_DATA_SIZE)
#define gSPNumLights(pkt,n) gMoveWd(pkt, G_MW_NUMLIGHT, G_MWO_NUMLIGHT, NUML(n))
#define SPSTATUS_BROKE 0x0002
#define OS_EVENT_PI 8
#define _OS_LIBC_H_ 
#define sDPRGBColor(cmd,r,g,b,a) gsDPSetColor(cmd, (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)))
#define G_MDSFT_ALPHACOMPARE 0
#define G_RM_ZB_OPA_DECAL2 RM_ZB_OPA_DECAL(2)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define M_AUDTASK 2
#define G_TEXTURE_GEN 0x00040000
#define OS_VI_NTSC_LAF1 3
#define OS_EVENT_SI 5
#define OS_VI_NTSC_LAF2 7
#define G_IM_SIZ_4b_TILE_BYTES G_IM_SIZ_4b_BYTES
#define G_ZBUFFER 0x00000001
#define G_TEXTURE_SCALE_FRAC 16
#define G_QUAD 0x07
#define CONT_TYPE_VOICE 0x0100
#define OS_IM_NONE 0x00000001
#define G_BL_A_MEM 1
#define G_MWO_POINT_ZSCREEN 0x1c
#define RM_PCL_SURF(clk) CVG_DST_FULL | FORCE_BL | ZMODE_OPA | G_AC_DITHER | GBL_c ##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)
#define OS_VI_NTSC_HPF1 9
#define OS_VI_NTSC_HPF2 13
#define A_ADPCM 1
#define SPSTATUS_HALT 0x0001
#define G_CCMUX_PRIMITIVE 3
#define OS_EVENT_VI 7
#define _MIPS_SZLONG 32
#define OS_IM_CPU 0x0000ff01
#define gDPSetAlphaCompare(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, type)
#define M_GFXTASK 1
#define OS_PM_64K 0x001e000
#define gSPGeometryMode(pkt,c,s) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_GEOMETRYMODE,24,8)|_SHIFTL(~(u32)(c),0,24); _g->words.w1 = (u32)(s); }
#define OS_VI_PAL_LPF1 15
#define G_RM_AA_DEC_LINE RM_AA_DEC_LINE(1)
#define RM_CLD_SURF(clk) IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_TX_RENDERTILE 0
#define G_MTX_LOAD 0x02
#define _ULTRA64_OS_MISC_H_ 
#define gsDPLoadTLUTCmd(tile,count) {{ _SHIFTL(G_LOADTLUT, 24, 8), _SHIFTL((tile), 24, 3) | _SHIFTL((count), 14, 10) }}
#define G_ACMUX_COMBINED 0
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define G_AD_DISABLE (3 << G_MDSFT_ALPHADITHER)
#define SPSTATUS_DMA_BUSY 0x0004
#define G_IM_SIZ_32b_INCR 0
#define gDPNoOp(pkt) gDPNoParam(pkt, G_NOOP)
#define _OS_CONT_H_ 
#define INCLUDE_ASM(TYPE,FOLDER,NAME,ARGS...) __asm__( ".section .text\n" "\t.align\t2\n" "\t.globl\t"#NAME"\n" "\t.ent\t"#NAME"\n" #NAME ":\n" "\t.include \"asm/nonmatchings/"FOLDER"/"#NAME".s\"\n" "\t.set reorder\n" "\t.set at\n" "\t.end\t"#NAME );
#define G_TT_RGBA16 (2 << G_MDSFT_TEXTLUT)
#define G_RM_AA_ZB_XLU_SURF2 RM_AA_ZB_XLU_SURF(2)
#define RM_AA_ZB_XLU_INTER(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_INTER | GBL_c ##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define OS_DCACHE_ROUNDUP_ADDR(x) (void *)(((((u32)(x)+0xf)/0x10)*0x10))
#define aClearBuffer(pkt,d,c) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_CLEARBUFF, 24, 8) | _SHIFTL(d, 0, 24); _a->words.w1 = (unsigned int)(c); }
#define G_CC_MODULATEIDECALA TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0
#define G_SHADING_SMOOTH 0x00200000
#define G_RM_AA_XLU_SURF2 RM_AA_XLU_SURF(2)
#define SPSTATUS_DMA_FULL 0x0008
#define G_MWO_MATRIX_ZZ_ZW_F 0x34
#define G_ACMUX_SHADE 4
#define G_MWO_MATRIX_ZZ_ZW_I 0x14
#define G_SCALE_FRAC 8
#define aPoleFilter(pkt,f,g,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_POLEF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16)); _a->words.w1 = (unsigned int)(s); }
#define G_CC_MODULATEIA TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0
#define OS_VI_NTSC_HPN1 8
#define OS_VI_NTSC_HPN2 12
#define G_MAXFBZ 0x3fff
#define G_IM_SIZ_32b_SHIFT 0
#define G_SETCIMG 0xff
#define G_TX_MIRROR 0x1
#define _OS_AI_H_ 
#define G_CC_TRILERP TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0
#define G_TP_NONE (0 << G_MDSFT_TEXTPERSP)
#define G_RM_AA_ZB_TEX_EDGE RM_AA_ZB_TEX_EDGE(1)
#define gSPBranchLessZrg(pkt,dl,vtx,zval,near,far,flag,zmin,zmax) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_RDPHALF_1,24,8); _g->words.w1 = (unsigned int)(dl); _g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_BRANCH_Z,24,8)| _SHIFTL((vtx)*5,12,12)|_SHIFTL((vtx)*2,0,12)); _g->words.w1 = G_DEPTOZSrg(zval, near, far, flag, zmin, zmax); }
#define OS_VI_UNK200 0x200
#define OS_VI_PAL_LPN1 14
#define OS_VI_PAL_LPN2 18
#define A_LOOP 0x02
float sinf(float);
float cosf(float);
float sqrtf(float);
typedef signed char s8;
typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long int s64;
typedef unsigned long long int u64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef float f32;
typedef double f64;
typedef unsigned long size_t;
typedef u32 OSIntMask;
typedef u32 OSHWIntr;
extern OSIntMask osGetIntMask(void);
extern OSIntMask osSetIntMask(OSIntMask);
void osInitialize(void);
u32 osGetCount(void);
u32 osVirtualToPhysical(void *);
extern u32 osDpGetStatus(void);
extern void osDpSetStatus(u32);
extern void osDpGetCounters(u32 *);
extern s32 osDpSetNextBuffer(void *, u64);
typedef s32 OSPri;
typedef s32 OSId;
typedef union
{
    struct {f32 f_odd; f32 f_even;} f;
} __OSfp;
typedef struct
{
              u64 at, v0, v1, a0, a1, a2, a3;
              u64 t0, t1, t2, t3, t4, t5, t6, t7;
              u64 s0, s1, s2, s3, s4, s5, s6, s7;
              u64 t8, t9, gp, sp, s8, ra;
              u64 lo, hi;
              u32 sr, pc, cause, badvaddr, rcp;
              u32 fpcsr;
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
typedef struct
{
    u32 flag;
    u32 count;
    u64 time;
} __OSThreadprofile_s;
typedef struct OSThread_s
{
             struct OSThread_s *next;
             OSPri priority;
             struct OSThread_s **queue;
             struct OSThread_s *tlnext;
             u16 state;
             u16 flags;
             OSId id;
             int fp;
             __OSThreadprofile_s *thprof;
             __OSThreadContext context;
} OSThread;
void osCreateThread(OSThread *thread, OSId id, void (*entry)(void *),
    void *arg, void *sp, OSPri pri);
OSId osGetThreadId(OSThread *thread);
OSPri osGetThreadPri(OSThread *thread);
void osSetThreadPri(OSThread *thread, OSPri pri);
void osStartThread(OSThread *thread);
void osStopThread(OSThread *thread);
typedef u32 OSEvent;
typedef void * OSMesg;
typedef struct OSMesgQueue_s {
 OSThread *mtqueue;
 OSThread *fullqueue;
 s32 validCount;
 s32 first;
 s32 msgCount;
 OSMesg *msg;
} OSMesgQueue;
extern void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern s32 osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);
typedef struct OSTimer_str
{
    struct OSTimer_str *next;
    struct OSTimer_str *prev;
    u64 interval;
    u64 remaining;
    OSMesgQueue *mq;
    OSMesg *msg;
} OSTimer;
typedef u64 OSTime;
OSTime osGetTime(void);
void osSetTime(OSTime time);
s32 osSetTimer(OSTimer *, OSTime, OSTime, OSMesgQueue *, OSMesg);
typedef struct {
 u16 type;
 u8 status;
 u8 errno;
}OSContStatus;
typedef struct {
 u16 button;
 s8 stick_x;
 s8 stick_y;
 u8 errno;
} OSContPad;
typedef struct {
 void *address;
 u8 databuffer[32];
        u8 addressCrc;
 u8 dataCrc;
 u8 errno;
} OSContRamIo;
extern s32 osContInit(OSMesgQueue *, u8 *, OSContStatus *);
extern s32 osContReset(OSMesgQueue *, OSContStatus *);
extern s32 osContStartQuery(OSMesgQueue *);
extern s32 osContStartReadData(OSMesgQueue *);
extern s32 osContSetCh(u8);
extern void osContGetQuery(OSContStatus *);
extern void osContGetReadData(OSContPad *);
typedef u32 OSPageMask;
extern void osMapTLB(s32, OSPageMask, void *, u32, u32, s32);
extern void osMapTLBRdb(void);
extern void osUnmapTLB(s32);
extern void osUnmapTLBAll(void);
extern void osSetTLBASID(s32);
typedef struct
{
             u32 type;
             u32 flags;
             u64 *ucode_boot;
             u32 ucode_boot_size;
             u64 *ucode;
             u32 ucode_size;
             u64 *ucode_data;
             u32 ucode_data_size;
             u64 *dram_stack;
             u32 dram_stack_size;
             u64 *output_buff;
             u64 *output_buff_size;
             u64 *data_ptr;
             u32 data_size;
             u64 *yield_data_ptr;
             u32 yield_data_size;
} OSTask_t;
typedef union {
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;
typedef u32 OSYieldResult;
void osSpTaskLoad(OSTask *task);
void osSpTaskStartGo(OSTask *task);
void osSpTaskYield(void);
OSYieldResult osSpTaskYielded(OSTask *task);
extern u64 rspF3DBootStart[], rspF3DBootEnd[];
extern u64 rspF3DStart[], rspF3DEnd[];
extern u64 rspF3DDataStart[], rspF3DDataEnd[];
extern u64 rspAspMainStart[], rspAspMainEnd[];
extern u64 rspAspMainDataStart[], rspAspMainDataEnd[];
extern void osInvalDCache(void *, s32);
extern void osInvalICache(void *, s32);
extern void osWritebackDCache(void *, s32);
extern void osWritebackDCacheAll(void);
typedef struct
{
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;
typedef struct
{
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;
typedef struct
{
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;
typedef struct
{
               u16 unk00;
               u16 retraceCount;
               void* buffer;
               OSViMode *unk08;
               u32 features;
               OSMesgQueue *mq;
               OSMesg *msg;
               u32 unk18;
               u32 unk1c;
               u32 unk20;
               f32 unk24;
               u16 unk28;
               u32 unk2c;
} OSViContext;
void osCreateViManager(OSPri pri);
void osViSetMode(OSViMode *mode);
void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount);
void osViBlack(u8 active);
void osViSetSpecialFeatures(u32 func);
void osViSwapBuffer(void *vaddr);
extern OSViMode osViModeTable[];
typedef struct
{
    u32 errStatus;
    void *dramAddr;
    void *C2Addr;
    u32 sectorSize;
    u32 C1ErrNum;
    u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct
{
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 devAddr;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle_s
{
    struct OSPiHandle_s *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    __OSTranxInfo transferInfo;
} OSPiHandle;
typedef struct
{
    u8 type;
    u32 address;
} OSPiInfo;
typedef struct
{
    u16 type;
    u8 pri;
    u8 status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct
{
             OSIoMesgHdr hdr;
             void *dramAddr;
             u32 devAddr;
             u32 size;
} OSIoMesg;
s32 osPiStartDma(OSIoMesg *mb, s32 priority, s32 direction,
                 u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *mq);
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf,
                       s32 cmdMsgCnt);
OSMesgQueue *osPiGetCmdQueue(void);
s32 osPiWriteIo(u32 devAddr, u32 data);
s32 osPiReadIo(u32 devAddr, u32 *data);
extern s32 osEPiDeviceType(OSPiHandle *, OSPiInfo *);
extern s32 osEPiRawWriteIo(OSPiHandle *, u32 , u32);
extern s32 osEPiRawReadIo(OSPiHandle *, u32 , u32 *);
extern s32 osEPiRawStartDma(OSPiHandle *, s32 , u32 , void *, u32 );
extern s32 osEPiWriteIo(OSPiHandle *, u32 , u32 );
extern s32 osEPiReadIo(OSPiHandle *, u32 , u32 *);
extern s32 osEPiStartDma(OSPiHandle *, OSIoMesg *, s32);
extern s32 osEPiLinkHandle(OSPiHandle *);
OSThread *__osGetCurrFaultedThread(void);
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 unsigned char cn[4];
} Vtx_t;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 signed char n[3];
 unsigned char a;
} Vtx_tn;
typedef union {
    Vtx_t v;
    Vtx_tn n;
    long long int force_structure_alignment;
} Vtx;
typedef struct {
  void *SourceImagePointer;
  void *TlutPointer;
  short Stride;
  short SubImageWidth;
  short SubImageHeight;
  char SourceImageType;
  char SourceImageBitSize;
  short SourceImageOffsetS;
  short SourceImageOffsetT;
  char dummy[4];
} uSprite_t;
typedef union {
  uSprite_t s;
  long long int force_structure_allignment[3];
} uSprite;
typedef struct {
 unsigned char flag;
 unsigned char v[3];
} Tri;
typedef long Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int force_structure_alignment;
} Mtx;
typedef struct {
 short vscale[4];
 short vtrans[4];
} Vp_t;
typedef union {
    Vp_t vp;
    long long int force_structure_alignment;
} Vp;
typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;
typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
} Ambient_t;
typedef struct {
  int x1,y1,x2,y2;
} Hilite_t;
typedef union {
    Light_t l;
    long long int force_structure_alignment[2];
} Light;
typedef union {
    Ambient_t l;
    long long int force_structure_alignment[1];
} Ambient;
typedef struct {
    Ambient a;
    Light l[7];
} Lightsn;
typedef struct {
    Ambient a;
    Light l[1];
} Lights0;
typedef struct {
    Ambient a;
    Light l[1];
} Lights1;
typedef struct {
    Ambient a;
    Light l[2];
} Lights2;
typedef struct {
    Ambient a;
    Light l[3];
} Lights3;
typedef struct {
    Ambient a;
    Light l[4];
} Lights4;
typedef struct {
    Ambient a;
    Light l[5];
} Lights5;
typedef struct {
    Ambient a;
    Light l[6];
} Lights6;
typedef struct {
    Ambient a;
    Light l[7];
} Lights7;
typedef struct {
    Light l[2];
} LookAt;
typedef union {
    Hilite_t h;
    long int force_structure_alignment[4];
} Hilite;
typedef struct {
 int cmd:8;
 unsigned int par:8;
 unsigned int len:16;
 unsigned int addr;
} Gdma;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri tri;
} Gtri;
typedef struct {
  int cmd:8;
  int pad1:24;
  int pad2:24;
  unsigned char param:8;
} Gpopmtx;
typedef struct {
  int cmd:8;
  int pad0:8;
  int mw_index:8;
  int number:8;
  int pad1:8;
  int base:24;
} Gsegment;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeL;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeH;
typedef struct {
  unsigned char cmd;
  unsigned char lodscale;
  unsigned char tile;
  unsigned char on;
  unsigned short s;
  unsigned short t;
} Gtexture;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri line;
} Gline3D;
typedef struct {
  int cmd:8;
  int pad1:24;
  short int pad2;
  short int scale;
} Gperspnorm;
typedef struct {
                int cmd:8;
                unsigned int fmt:3;
                unsigned int siz:2;
                unsigned int pad:7;
                unsigned int wd:12;
                unsigned int dram;
} Gsetimg;
typedef struct {
  int cmd:8;
  unsigned int muxs0:24;
  unsigned int muxs1:32;
} Gsetcombine;
typedef struct {
  int cmd:8;
  unsigned char pad;
  unsigned char prim_min_level;
  unsigned char prim_level;
  unsigned long color;
} Gsetcolor;
typedef struct {
  int cmd:8;
  int x0:10;
  int x0frac:2;
  int y0:10;
  int y0frac:2;
  unsigned int pad:8;
  int x1:10;
  int x1frac:2;
  int y1:10;
  int y1frac:2;
} Gfillrect;
typedef struct {
  int cmd:8;
  unsigned int fmt:3;
  unsigned int siz:2;
  unsigned int pad0:1;
  unsigned int line:9;
  unsigned int tmem:9;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int palette:4;
  unsigned int ct:1;
  unsigned int mt:1;
  unsigned int maskt:4;
  unsigned int shiftt:4;
  unsigned int cs:1;
  unsigned int ms:1;
  unsigned int masks:4;
  unsigned int shifts:4;
} Gsettile;
typedef struct {
  int cmd:8;
  unsigned int sl:12;
  unsigned int tl:12;
  int pad:5;
  unsigned int tile:3;
  unsigned int sh:12;
  unsigned int th:12;
} Gloadtile;
typedef Gloadtile Gloadblock;
typedef Gloadtile Gsettilesize;
typedef Gloadtile Gloadtlut;
typedef struct {
  unsigned int cmd:8;
  unsigned int xl:12;
  unsigned int yl:12;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int xh:12;
  unsigned int yh:12;
  unsigned int s:16;
  unsigned int t:16;
  unsigned int dsdx:16;
  unsigned int dtdy:16;
} Gtexrect;
typedef struct {
    unsigned long w0;
    unsigned long w1;
    unsigned long w2;
    unsigned long w3;
} TexRect;
typedef struct {
 unsigned int w0;
 unsigned int w1;
} Gwords;
typedef union {
 Gwords words;
 Gdma dma;
 Gtri tri;
 Gline3D line;
 Gpopmtx popmtx;
 Gsegment segment;
 GsetothermodeH setothermodeH;
 GsetothermodeL setothermodeL;
 Gtexture texture;
 Gperspnorm perspnorm;
 Gsetimg setimg;
 Gsetcombine setcombine;
 Gsetcolor setcolor;
 Gfillrect fillrect;
 Gsettile settile;
 Gloadtile loadtile;
 Gsettilesize settilesize;
 Gloadtlut loadtlut;
        long long int force_structure_alignment;
} Gfx;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int addr;
} Aadpcm;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int addr;
} Apolef;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Aenvelope;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:8;
 unsigned int dmem:16;
 unsigned int pad2:16;
 unsigned int count:16;
} Aclearbuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:8;
 unsigned int pad2:16;
 unsigned int inL:16;
        unsigned int inR:16;
} Ainterleave;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int addr;
} Aloadbuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Aenvmixer;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int dmemi:16;
 unsigned int dmemo:16;
} Amixer;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int dmem2:16;
 unsigned int addr;
} Apan;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pitch:16;
 unsigned int addr;
} Aresample;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Areverb;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int addr;
} Asavebuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int pad2:2;
 unsigned int number:4;
 unsigned int base:24;
} Asegment;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int dmemin:16;
 unsigned int dmemout:16;
 unsigned int count:16;
} Asetbuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int vol:16;
 unsigned int voltgt:16;
 unsigned int volrate:16;
} Asetvol;
typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int dmemin:16;
    unsigned int dmemout:16;
    unsigned int count:16;
} Admemmove;
typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int count:16;
    unsigned int addr;
} Aloadadpcm;
typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int pad2:16;
    unsigned int addr;
} Asetloop;
typedef struct {
 unsigned int w0;
 unsigned int w1;
} Awords;
typedef union {
 Awords words;
 Aadpcm adpcm;
        Apolef polef;
 Aclearbuff clearbuff;
 Aenvelope envelope;
        Ainterleave interleave;
 Aloadbuff loadbuff;
        Aenvmixer envmixer;
 Aresample resample;
 Areverb reverb;
 Asavebuff savebuff;
 Asegment segment;
 Asetbuff setbuff;
 Asetvol setvol;
        Admemmove dmemmove;
        Aloadadpcm loadadpcm;
        Amixer mixer;
        Asetloop setloop;
        long long int force_union_align;
} Acmd;
typedef short ADPCM_STATE[16];
typedef short POLEF_STATE[4];
typedef short RESAMPLE_STATE[16];
typedef short ENVMIX_STATE[40];
extern s32 osEepromProbe(OSMesgQueue *);
extern s32 osEepromRead(OSMesgQueue *, u8, u8 *);
extern s32 osEepromWrite(OSMesgQueue *, u8, u8 *);
extern s32 osEepromLongRead(OSMesgQueue *, u8, u8 *, int);
extern s32 osEepromLongWrite(OSMesgQueue *, u8, u8 *, int);
extern void bcopy(const void *, void *, size_t);
extern void bzero(void *, size_t);
extern int bcmp(const void *, const void *, int);
extern int sprintf(char *s, const char *fmt, ...);
extern void osSyncPrintf(const char *fmt, ...);
void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy, float aspect,
                    float near, float far, float scale);
void guPerspective(Mtx *m, u16 *perspNorm, float fovy, float aspect, float near,
                   float far, float scale);
void guOrtho(Mtx *m, float left, float right, float bottom, float top,
             float near, float far, float scale);
void guTranslate(Mtx *m, float x, float y, float z);
void guRotate(Mtx *m, float a, float x, float y, float z);
void guScale(Mtx *m, float x, float y, float z);
void guMtxF2L(float mf[4][4], Mtx *m);
void guMtxIdent(Mtx *m);
void guMtxIdentF(float mf[4][4]);
void guMtxL2F(float mf[4][4], Mtx *m);
void guNormalize(float *, float *, float *);
void guLookAtReflect (Mtx *m, LookAt *l, float xEye, float yEye, float zEye,
                    float xAt, float yAt, float zAt,
                    float xUp, float yUp, float zUp);
extern u32 osAiGetStatus(void);
extern u32 osAiGetLength(void);
extern s32 osAiSetFrequency(u32);
extern s32 osAiSetNextBuffer(void *, u32);
typedef struct
{
    u8 *offset;
    s32 len;
} ALSeqData;
typedef struct
{
    s16 revision;
    s16 seqCount;
    ALSeqData seqArray[1];
} ALSeqFile;
void alSeqFileNew(ALSeqFile *f, u8 *base);
extern u32 osTvType;
extern u32 osRomBase;
extern u32 osResetType;
extern u32 osMemSize;
extern u8 osAppNmiBuffer[64];
;
typedef struct jump_buf
{
    u32 * sp;
    void *func;
    u32 regs[21];
} jmp_buf;
extern s32 setjmp(jmp_buf *jump_buf);
extern s32 longjmp(jmp_buf *jump_buf, s32 val);
typedef void (*process_func)();
struct process
{
             struct process *next;
             struct process *youngest_child;
             struct process *oldest_child;
             struct process *relative;
             struct process *parent_oldest_child;
             struct process *new_process;
             void *heap;
             u16 exec_mode;
             u16 stat;
             u16 priority;
             s16 dtor_idx;
             s32 sleep_time;
             void *base_sp;
             jmp_buf prc_jump;
             process_func destructor;
             void *user_data;
};
void HuPrcSysInit();
void HuPrcLink(struct process **root, struct process *process);
void HuPrcUnlink(struct process **root, struct process *process);
struct process * HuPrcCreate(process_func func, u16 priority, s32 stack_size, s32 extra_data_size);
void HuPrcChildLink(struct process *process, struct process *child);
void HuPrcChildUnlink(struct process *process);
struct process * HuPrcCreateChild(process_func func, u16 priority, s32 stack_size, s32 extra_data_size, struct process * parent);
void HuPrcChildWait();
struct process * HuPrcGetCurrent();
s32 HuPrcChildGet(struct process *process);
s32 HuPrcStatKill(struct process *process);
void HuPrcKill(struct process *process);
void HuPrcChildKill(struct process *process);
void HuPrcTerminate(struct process *process);
void HuPrcExit();
void HuPrcSleep(s32 time);
void HuPrcVSleep();
void HuPrcAwake(struct process *process);
void HuPrcDtor(struct process *process, process_func destructor);
void HuPrcCurrentDtor(process_func destructor);
void * HuPrcAllocMem(s32 size);
void HuPrcFreeMem(void *ptr);
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} vec3f;
typedef struct objectt {
             struct objectt *prev;
             struct objectt *next;
             u8 unk8;
             s8 unk9;
             u16 unkA;
             vec3f coords;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    struct objectIndirectt *unk3C;
    struct objectIndirectt *unk40;
    s16 unk44;
    s16 unk46;
} object;
struct objectIndirectt {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    void *unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    u16 unk3C;
    s16 *unk40;
    u16 unk44;
    s16 *unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    struct objectIndirect3t *unk5C;
};
typedef struct objectIndirect3t {
    struct objectt *unk0;
    f32 unk4;
} objectIndirect3;
typedef struct {
                             s8 id;
                             s8 cpuDifficulty;
                             u8 controller;
                             u8 character;
                             u8 flags;
                             s8 pad5[1];
                             s16 bonusCoins;
                             s16 coinsWon;
                             s16 coins;
                             s16 minigameCoins;
                             s8 stars;
                             u8 curChainIndex;
                             u8 curSpaceIndex;
                             u8 nextChainIndex;
                             u8 nextSpaceIndex;
                             s8 unk1ChainIndex;
                             s8 unk1SpaceIndex;
                             s8 reverseChainIndex;
                             s8 reverseSpaceIndex;
                             u8 flags2;
                             s8 items[3];
                             s8 bowserSuitFlag;
                             u8 turnColorStatus;
                             s8 unk1D;
    s8 unks1E1F[2];
                             struct process *process;
                             struct objectt *obj;
                             s16 minigameStar;
                             s16 maxCoins;
                             s8 happeningSpaceCount;
    s8 redSpaceCount;
    s8 blueSpaceCount;
    s8 chanceSpaceCount;
                             s8 bowserSpaceCount;
    s8 battleSpaceCount;
    s8 itemSpaceCount;
    s8 bankSpaceCount;
                             s8 gameGuySpaceCount;
    s8 unk35;
} player;
typedef struct unkStruct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
} unkStruct;
typedef struct unkStruct01 {
    f32 unk_00;
    char unk_04[4];
    f32 unk_08;
} unkStruct01;
typedef struct unkStruct02 {
vec3f unk_00;
char unk_0C[4];
} unkStruct02;
struct heap_node
{
    s32 size;
    u8 heap_constant;
    u8 used;
    struct heap_node *prev;
    struct heap_node *next;
};
typedef struct unkStruct03 {
char unk_00[0x18];
struct heap_node* unk_18;
char unk_1C[0x70];
unkStruct02* unk_8C;
} unkStruct03;
typedef struct unkStruct04 {
char unk_00[0x0C];
vec3f unk_0C;
} unkStruct04;
typedef struct unkStruct05 {
char unk_00[0x24];
s32 unk_24;
} unkStruct05;
typedef struct unkStruct06 {
    s32 unk_00;
    s32 unk_04;
    f32 unk_08;
    char unk_0C[4];
} unkStruct06;
extern s8 gCurrentPlayerIndex;
extern player gPlayers[4];
void func_80047B80_48780(struct process*, s32);
void func_80047BAC_487AC(struct process*, s32);
void func_80100CEC(u8);
extern s16 D_800CDD58;
extern s16 D_800D037C;
s32 func_800E1824(s32, s32, s32);
s32 func_800E88FC(void);
extern s16 D_800D51F8;
extern s32 D_80119470;
extern s32 D_80119474;
extern s32 D_80119478;
extern s32 D_8011947C;
void func_800E1854(s32);
extern s16 D_800D51F8;
extern s32 D_80119470;
extern s32 D_80119474;
extern s32 D_80119478;
extern s32 D_8011947C;
void HuObjInit(s32, s32);
void func_80048228_48E28(s32, s32, s32);
extern s8 D_800CD059;
void func_8004819C_48D9C(s32);
void func_800E94D0(void);
void func_800E9564(void);
void func_800E9B10(s32, s32);
void func_800E9D9C(void);
void func_800E9F4C(s32, s8*, s8*);
void func_800EA760(void);
void func_800ECD0C(s32, s8, s8);
f32 func_8008E3F0_8EFF0(f32);
f32 func_8008EF20_8FB20(f32);
f32 func_800D76D0(void*);
void func_800EB708(s32, s32, unkStruct01*);
void * HuMemMemoryAlloc(struct heap_node * heap, s32 size);
unkStruct03* func_80047EA0_48AA0(void*, s32, s32, s32);
void func_80105CC0_3D8DB0(void);
void func_800FC8C4(void*);
extern s32 D_80105540;
void func_800EC1E4(void*, s32, void*, f32);
extern s32 D_80105540;
extern unkStruct D_800CD0B0;
void func_800EBF2C(void*, s32, void*);
void func_80106308_3D93F8(void);
void func_8001C258_1CE58(s16, s32, s32);
void func_8001C448_1D048(s16);
void func_8001C814_1D414(s16, s32, s32);
void func_8001C8E4_1D4E4(s16, s32);
void* func_800D8010(s32, s32);
void func_800D8944(void*);
void func_800D8F0C(void*);
void func_801059D0_3D8AC0(void) {
    D_800CDD58 = 1;
    D_800D037C = 0;
    func_80047B80_48780(HuPrcGetCurrent(), 0x80);
    func_80100CEC(gPlayers[gCurrentPlayerIndex].controller);
    func_80047BAC_487AC(HuPrcGetCurrent(), 0x80);
    D_800CDD58 = 0;
    D_800D037C = 1;
}
void func_80105A58_3D8B48(void) {
    while (func_800E88FC() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_80119470 = func_800E1824(0, 0xA0, 1);
    D_80119474 = func_800E1824(0xD, 0xAE, 1);
    D_80119478 = func_800E1824(1, 0xBC, 1);
    D_8011947C = func_800E1824(3, 0xCA, 1);
    HuPrcSleep(3);
    D_800CDD58 = 1;
    D_800D51F8 = 1;
}
void func_80105B10_3D8C00(void) {
    D_800CDD58 = 0;
    D_800D51F8 = 0;
    func_800E1854(D_80119470);
    func_800E1854(D_80119474);
    func_800E1854(D_80119478);
    func_800E1854(D_8011947C);
}
void func_80105B64_3D8C54(void) {
    D_800CD059 = 0;
    HuObjInit(0xA, 0);
    func_80048228_48E28(0x5A, 0, 0x4190);
}
void func_80105B9C_3D8C8C(void) {
    s8 sp10;
    s8 sp11;
    HuObjInit(0xA, 0);
    func_800E94D0();
    func_800E9B10(0x13, 0x241);
    func_800E9F4C(0x1C, &sp10, &sp11);
    func_800ECD0C(0, sp10, sp11);
    func_800E9F4C(0x1B, &sp10, &sp11);
    func_800ECD0C(1, sp10, sp11);
    gPlayers[0].unk1ChainIndex = -1;
    gPlayers[0].unk1SpaceIndex = -1;
    gPlayers[1].unk1ChainIndex = -1;
    gPlayers[1].unk1SpaceIndex = -1;
    func_800E9D9C();
    func_800E9564();
    D_800CD0B0.unk_04 = 5;
    D_800CD0B0.unk_02 = 0;
    func_800EA760();
    func_8004819C_48D9C(1);
}
void func_80105C64_3D8D54(s32 arg0, s32 arg1, unkStruct01* arg2) {
    f32 temp_f20;
    func_800EB708(arg0, arg1, arg2);
    temp_f20 = func_800D76D0(arg2) + 15.0f;
    arg2->unk_00 = func_8008EF20_8FB20(temp_f20);
    arg2->unk_08 = func_8008E3F0_8EFF0(temp_f20);
}
;;
void* func_80105EB0_3D8FA0(unkStruct04* arg0) {
    unkStruct03* temp_v0;
    unkStruct02* temp_v0_2;
    temp_v0 = func_80047EA0_48AA0(&func_80105CC0_3D8DB0, 0xA, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->unk_18, sizeof(unkStruct02));
    temp_v0->unk_8C = temp_v0_2;
    temp_v0_2->unk_00.x = arg0->unk_0C.x;
    temp_v0_2->unk_00.y = arg0->unk_0C.y;
    temp_v0_2->unk_00.z = arg0->unk_0C.z;
    return temp_v0;
}
;;
;;
;;
void func_80106240_3D9330(void) {
    func_800FC8C4(&D_80105540);
}
void func_80106260_3D9350(s32 arg0, unkStruct05* arg1, s32 arg2, f32 arg3) {
    arg3 = arg3 + 0.5f;
    if (arg2 & 9) {
        func_800EC1E4(&D_80105540, arg0 + 0xC, &D_80105540, arg3);
    } else {
        func_800EC1E4(&D_80105540, arg1->unk_24 + 0xC, &D_80105540, arg3);
    }
}
void func_801062C0_3D93B0(s32 arg0, unkStruct05* arg1, s32 arg2, f32 arg3) {
    if (arg2 & 9) {
        func_800EBF2C(&D_80105540, arg0 + 0xC, &D_80105540);
    } else {
        func_800EBF2C(&D_80105540, arg1->unk_24 + 0xC, &D_80105540);
    }
}
;;
unkStruct03* func_8010645C_3D954C(s32 arg0, s32 arg1) {
    unkStruct03* temp_v0;
    unkStruct06* temp_v0_2;
    temp_v0 = func_80047EA0_48AA0(&func_80106308_3D93F8, 0xA, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->unk_18, sizeof(unkStruct06));
    temp_v0->unk_8C = temp_v0_2;
    temp_v0_2->unk_00 = arg0;
    temp_v0_2->unk_04 = arg1;
    return temp_v0;
}
;;
void* func_80106740_3D9830(s32 arg0) {
    object* temp_v0;
    temp_v0 = func_800D8010(arg0 & 0xFF, 0);
    func_8001C258_1CE58(*temp_v0->unk3C->unk40, 0x180, 0);
    func_8001C8E4_1D4E4(*temp_v0->unk3C->unk40, 0x1800);
    func_8001C448_1D048(*temp_v0->unk3C->unk40);
    func_800D8944(temp_v0);
    func_800D8F0C(temp_v0);
    func_8001C814_1D414(*temp_v0->unk3C->unk40, 2, 1);
    return temp_v0;
}
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
;;
void func_80118320_3EB410(void) {
}
;;
;;
;;
