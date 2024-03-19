#include "../../../utility/DxLib_Engine.h"
#include "../../../utility/tnlSequence.h"
#include "../../Button/DialogueButtons.h"
#include "../../Manager/SceneManager/SceneBase.h"
#include "SceneConversation.h"
#include "../../SceneStageMap/SceneStageMap.h"
#include "../../Manager/ImageManager/use/ImageManager.h"
#include "../../Manager/SceneManager/SceneManager.h"


int SceneConversation::_CURRENT_TEXTROW = 0;
int SceneConversation::Prologue_Epilogue = 0;


namespace {

	// CSV���[�h�֐������{��ɑΉ����Ă��Ȃ����߁A�����ɒ��Ƀe�L�X�g��u���Ă��܂�.......

	std::string prologueTextLog[140] = {

		"�E�E�E�E�E�E�E�E�E",

		"�E�E�E�E�E�E�E�E�E",

			"�E�E�E�E�E�E�E�E�E",

			"����͐[������ɂ��Ă��邩�̂悤�Ȋ��o�������B",

			"��E�E�E���E�E�E�E�܁I",

			"�̂𓮂������Ƃ��A�������l���邱�Ƃ��������Ȃ���ȏ�Ԃ̒��A����琺���������ė���B",

			"�u�䂤���Ⴓ�܁I�I�I�v",

			"�I�H�I�H�I�H",

			"�܂�ŋC�����悭�����Ă���������}�΂����̂悤�ɁA���̍b�������͉���@���N�������B",

			"�u���E�E�E�E�v",

			"�u���I�H����ƋN���Ă��������܂����ˁA�E�җl�I�v",


			"�݂��ɂޓ�����ŉ������Ȃ���A�������Ƒ̂��N�����B",

			"�u�E�E�E�����́H�v",


			"�����c�����邽�ߎ��͂����n�����A�������܍����Ɋׂ�B",

			"�����͔��Â���Ԃ������B�_��̃��C�g(�H)������Ȃ��Èł��Ƃ炵�Ă���B",

			"������m�F����Ƃ�͂蓯���悤�ɈÂ��������A������������ꏊ�͖ڂ̑O�̔��ɑ�����{��\n�̂悤���Ƃ������Ƃ��h�����ĕ��������B",

			"(�E�E�E����H�E�E�Q�ڂ��Ă�̂��H)",

			"�s�v�c�Ȃ��Ƃɖڂ��o�܂��O�܂ł̂��Ƃ��v���o���Ȃ��B�����ɂ��ꎞ�I�Ȃ��̂Ȃ̂��A\n����Ƃ��L���������Ă��܂����̂��A���ꂷ�画�f�o���Ȃ������B",

			"�������^��Ɏv�����̂͂��ꂾ���ł͂Ȃ��B",

			"������𔭂��Ă����ڂ̑O�̏����ɖڂ�������B",

			"���b�ώ@���Ă݂����A�ǂ��������Ă�����͉��̑S���m��Ȃ��l���������B",

			"(���ɕςȉ����݂����̂��ڂ��Ă邵�A�ς�������𒅂Ă���B�E�E�R�X�v�����H)",

			"(����R�X�v���C���[�ƈÈłœ�l����Ƃ��ǂ�ȏ󋵂���)",

			"�������čl���Ă��Ă��d�����Ȃ��A���ڐu���������������낤�B",

			"�u�E�E�E�E�E�E���́[�A���݂܂���B�����͂ǂ��ł����H�v",

			"�����u���Ə����͖ڂ���炵�A�����Ȑ��ŕԓ������B",

			"�u�E�E�E�E���E�v",

			"�u�́H�v",

			"�u�E�җl�A�˔@������̐��E�ւ��Ăт��Ă��܂����������l�ѐ\���グ��Ƌ��ɁA��ɂ��`��\n���邱�Ƃ��������܂��v",

			"���̖ڂ�^���������߁A��ċz�����Ă���Ăь����J���B",

			"�u���Ȃ��͎��ɂ܂����v",

			"�E�E�E�E�E�́H",

			"�u��������邨�C�����͂悭������܂����A���������Ă��������v",

			"�u���Ȃ��͎��񂾁A�����đh�����̂ł��A�l�̍��y�V�����X�鍑�z���~���E�҂Ƃ��āv",

			"-----------------------------------",

			"�u����ȃS�~������悤�ȖڂŌ��߂Ȃ��ł��������A���͐^���Ȃ̂ł��I�v",

			"���H��������Ȋ炵�Ă�̂��H���S�ɖ��ӎ��������B",

			"�u�E�җl�I���Ȃ��l�͐l�̎q�̑�\�Ƃ��ėE�҂ɑI�΂ꂽ�̂ł��B�����đI�΂ꂽ�҂͂��̐Ӗ���S�����A\n�l�X�Ɉ��J�ƒ������؂��Ȃ��Ă͂Ȃ�܂���v",

			"�u���ꂩ�炠�Ȃ��l�͏C���̓���i�ނ��ƂɂȂ�ł��傤�B�ł������S�z�ɂ͋y�т܂���I�v",

			"(�E�E�R�������Ă���悤�ɂ͌����Ȃ����Ǔ��e�����܂�ɔn���n�������B�V��̍��\���A��������\n�s�v�c�����Ȃ̂��E�E�E�H)",

			"�u���Ȃ��l���I�΂ꂽ���Ƃɂ͂͂�����Ƃ������R������̂ł��I�����ӎu���h�������A�����Ȗʎ����A\n�C�����������R���邻�̍��E�E�E�v",

			"�u�{���ł���Έ�x���񂾍��͏򉻂����܂ŁB�n��ɖ߂邱�Ƃ͋�����܂���v",

			"�u�������A���̐_�X�Ƃ̘b�������̌��ʁA�������̐���t���ō���͓����݂��邱�Ƃƒv���܂����v",

			"�u����H�v",

			"�u�͂��I�E�җl�̍����Ăђn��ɖ߂����Ƃ͐_�X�̝|�ŋւ����Ă��܂��A���v",

			"�u�E�җl�������ς�ł���������ӂ݂āA����͓���Ƃ��ĕʐ��E�ւ̓]�����F�߂�ꂽ�̂ł��v",

			"�u���܂��ẮA�E�җl�ɂ͐��񂻂̐����^�������ȐS���т��ʂ��A���́y�V�����X�鍑�z�𐳂�������\n�������҂ƂȂ��Ă������������v���܂��I�v",

			"���������Ă���̂������ς蕪����Ȃ��������A�����ŉ��͂����̉\���ɋC���t���B\n",

			"(�h�b�L�����H�I)",

			"����������Ă����̕�����Ȃ��b���͗]���������������B",

			"�ЂƂ��т��̍l���ɒH�蒅���ƁA����܂ŕ����Ă����ْ��ƕs�������������a�炢�����Ƃ�������B",

			"�i����ł����ɂǂ���������񂾁H�U���H���H�j",

			"�܂��U���Ƃ������͂Ȃ����낤�B�����ł���΂��̂悤�Ȓ��ԂɈӖ��͂Ȃ��B",

			"�ł���Ζ����H",

			"�E�E�E",

			"�������ł���Ζڂ��o�߂���S�ĖY��悤�B����Ȃ̂����̍����j���B",

			"�ЂƂ܂����𓾂邽�߁A�K���ɕԓ����Ă݂邱�Ƃɂ����B",

		   "�u���[���ƁE�E�E�E���̘b���ĉ��ɉ��������b�g�Ƃ����Ă������肷���ł����H�v",

			"�u���H�v",

			"�ӊO�Ȕ����������̂��A�ڂ̑O�̏��_(��)�̓L���g���Ƃ����\��Ōł܂�B",

			"�u���H�����Ă�����ėv����Ɏ����̐g���댯�ɎN���ĒN���Ɛ킦���Ă��Ƃł���ˁH�v",

			"�u��A�E�җl�H���A����͐l�ނɂƂ��ĂƂĂ��h���̂���g���Ȃ̂ł���H�I�I�΂ꂵ���̂�����������\n������----�v",

		   "�u���Ɖ��̉������̗E�҂��Ă̂ɑI�΂ꂽ��ł����H�����Ō����̂��Ȃ�ł����ǉ����ē��Ɏ�蕿\n�Ƃ��Ȃ����E�E�v",

		   "�b���Ղ��ď����s���������̂��A���_(��)����͐���܂ł̏Ί炪�����Ă����B",

			"�u�E�E�E�\���󂲂����܂��񂪁A����������`�����鎞�Ԃ͂������܂���B�E�җl�ɂ͈ꍏ�������n��֖߂�A\n�l�X�ɋ~���̎�������L�ׂė~�����̂ł��v",

			"(���܂ő����񂾂낤����E�E�E�E)",

		   "�u����͐V���Ȃ�`���̎n�܂�ƂȂ�ł��傤�A�E�җl�ɏ��_�̏j��������񂱂Ƃ��E�E�E�v",

		   "�u����A�b�͏I����Ă�-----�v",



		   //	"------------------------------------------------------------�Ó]--------------------------------------------------------------",

				"--------------------------------------------------------",

				"------------------------------------------",

				"----------------------------",

				   "�u�������������I�I�H�v",

				   "�u���A������ˁH�v",

				   "�ˑR�^���ÂɂȂ����Ǝv�����獡�x�͐���Ƃ͈Ⴄ�i�F���f���o���ꂽ�B",

				   "�ǂ����A�������̏��_(��)�����������ɓ]�ڂ������悤���E�E�E���āA�]�ځH�H�I�I",

				   "�j���˂��Ă݂����A���ʂɒɂ��B�܂�������Ȃ��Ƃ������������Ƃ͎v�������Ȃ������B",

				   "�i�E�E�E�E�E�E�j",

				   "�]�ڂ̍ہA���炭��u�������̑̂͂��̐����瑶�݂������Ă����B",

				   "��u�̏o�������������ߊm�؂͂Ȃ����A���炭����͖{���������B����������������Ă��M����҂�\n���Ȃ����낤�B����܂ł̎����Ɠ����悤�ɁB",

				   "�����A�{���łȂ���΂��̏󋵂��ǂ���������Ƃ����̂��B",

				   "�E�E�E�~�������߂�悤�ɕӂ�����n���A��l�̏����Ɩڂ��������B",

				   "�u�E�E�E�����l�����̂Ƃ��������ǎ��Ԃ��Ȃ��́A���������b���n�߂��v",

				   "(����E�E�E�H�f�W�����H)",

				   "���ŋߓ����悤�Ȃ��Ƃ��������悤�ȋC������̂����A�C�̂������H",

				   "�����͐錾�ʂ�A������̐��_��ԂȂǒm���Ƃł������΂���ɏ���ɘb���n�߂��B",

				   "�u�E�҂Ƃ��Đ��܂�ς�����Ƃ����̂͂��������Ă��ˁH�v",

				   "�u���A�E�E�E�E�܂��ꉞ�E�E�E�E�Ă��N�́H�v",

					"�u�������̂��Ƃ͌��B�����肱���ɗ���O�ɏ��_�l���牽���M�t�g��������Ȃ������H�v",

					"�u�M�t�g�H�v",

					"�u���̐l�Ԃ��܂Ƃ��ɖ����Ɛ킦��킯�Ȃ�����Ȃ��A�z��Ɛ키���߂ɂ͗͂��v���B�ǂ�����\n��̂悤�Ȃ��̂����܂�ĂȂ��H�v",

					"��������ꉴ�͎��g�̑̂��T�b�ƌ��n���B",

					"�u���A�E�E����H�v",

					"�E��̍b�ɐԂ���͂̂悤�Ȃ��̂������яオ���Ă���B",

				   "�u���A�����������ꂻ��I�������ˁE�E�E�키�̂�I����Łv",

				  "��͂��������r�[�A�����̃e���V���������炩�ɕ^�ς����B������Ă���Ȃɐ������̂Ȃ̂��E�E�E�H",

				 "�u����͒ʏ́y�����z�B���̍���𔭓����邱�Ƃɂ���Đ_���Ȃ�͂��s�g���邱�Ƃ��o����́v",

				"�u��̓I�Ɍ����ƁA���Ȃ��͂��ꂩ��G�Ɛ키�Ƃ��A�y�W�����P���z�ƌĂ΂��V�����s��Ȃ��Ă͂Ȃ�Ȃ��v",

				 "�u�y�W�����P���z�ɏ����Ƃ��ł���Α���Ƀ_���[�W��^������B���R������΂��̋t�ˁv",

				 "�u�V���̉񐔂͑���̃��x���ɂ���ĈقȂ邯�ǁA�v����ɑS�Ăɏ��Ă΂����̂�B�ȒP�ł���H�v",

				 "����ᛂɏ�錾�������������A���͊����Ă�����C�ɂ��Ȃ��悤�ɂ���B",

				 "����Ȃ��Ƃ��E�E�E�E�E�E",

				"�y�W�����P���z",

				"���������Ƃ��Ȃ��P�ꂾ�����B",

				"�������s�v�c�Ȃ��Ƃɉ��̂����͂����m���Ă���B",

				"�V���͏��߂ɂR�̑����̓��P��I�Ԃ��Ƃ���n�܂�A��������g�̎�Ŏ��̉�����B",

				"�����Ă���𑊎�̑I�񂾑����ƏՓ˂����A���s�����߂�̂��B",

				"�P�������A����ł��Ĕ��ɉ����[���B",

			   "(���̍��̖��^�����̎�ɁE�E�E)",

			   "�C���t���΂�����܂ŏ��_��n���ɂ��Ă��������͂������Ȃ��Ȃ��Ă����B",

			   "�]�ڂ����ۂɂ��̐g�Ŗ�����Ă��炩�A���̏󋵂ɉ��͏���������ݎn�߂Ă���̂�������Ȃ��B",

			   "���g�̓K���\�͂ɋ������A�ӂƉE�������Ƃ��ꂪ�͂��ɐk���Ă��邱�Ƃ����������B",

			   "���̐k���͈ӎ����Ă����䂪�ł����A�~�܂낤�Ƃ͂��Ă���Ȃ������B",

			   "�u�E�E�E�����܂��������Ă���݂��������ǁA���̐��E�͕�����Ȃ������A����͊o���Ƃ��āv",

				"�u�E�E�E�����v",

				"�u�E�E�E���Ⴀ�Ō�ɊȒP�ɂ��̍��̌������������ˁv",

				"���𑁂��ď�����킟�A�Ɣ�������͘b�𑱂���B",

				"�u�����H���̍��͌��݁A�X�e�B���A�V�G�[���A�n�[�s�A�A�Z�O�A�A�����čő�̓G�A���W�[�i�ɂ���Ďx�z����\n�Ă���B�܂��A�������茾���Ƃ������|���Ă����΂��Ȃ��̎g���͂����ŉʂ�������v",

				"�u������̖ړI�́H�v",

				"�u�E�E�E�����H�ł��������l�Ԃ��x�z����̂ɗ��R�Ȃ�ėv��Ȃ��񂶂�Ȃ�������H��̓͂��͈͂ɒ��x����\n�̓y�����������玩���̏��L���ɂ����A��������ȂƂ����v",

				"�����������G�E�E�E�Ƃ͎v�����������̘b�͑�̑z�������B��������Ƃ���q�o�f�Q�[���ł����������̂͂������B",

				"�����Ă݂���Ə����͖����������̂悤�ɔ��΂݁A�܂�ł��̘b�͏I���Ƃł������悤�ɘb���ς����B",

				 "�u�悵�I���Ⴀ��芸�������܂ł������ɂ��Ă��d���Ȃ����A�ړ����Ȃ���b���܂��傤�E�E�E���A\n���������Ύ��ȏЉ�܂���������v",

				  "�u���̓t�B�i�A���Ȃ��́H�v",


   "���O����",


	"�u #name�A�����Ȃ����O�ˁv",


	"�u�����ǁ[���v",


	"�u���ꂶ����߂āA�s���܂��傤���E�E�E���̍����~���Ɂv",

"���̃V�[����"


	};




	std::string epilogueTextLog[140] = {


	"���ɂ����܂ŗ����B",

	 "�Ō�̐킢��O�ɂ��Ďv����y����B",

	"�v���Ԃ��Ό����Ċy�ȓ��ł͂Ȃ������B",

	"�ڂ��o�߂����̂킩��Ȃ��Ƃ���ɂ��āA�ˑR�u���Ȃ��͎��ɂ܂����v�Ƃ������邵�B\n���̏�E�҂Ƃ������ׂ��d�������ڂ�w���킳��邵�B",

	"����������������߂Ă�肽���قǁA���͂悭����Ă�Ǝv���B",

		"(�E�E�E�͂�)",

	"���̏󋵂ɂ��ė��΂Ɋ���͂������A���ǂ̂Ƃ��뗝���͑S�����Ă��Ȃ��B�����ɈӖ��s�����B",

	"���ꂩ��ǂꂭ�炢�o�����̂��낤�B",

	"�ꌎ�O�̂悤�ȋC�����邵�A���������΂������N���炢�o�߂��Ă���̂�������Ȃ��B",

	"�Ƃɂ������͂��̐��E�Ő������т邱�Ƃɑ��X�K���������B",

	"���������ĕʂɂ��̍����~�����߂ɐ���Ă����킯�ł͂Ȃ��A�P�ɐg�ɍ~�肩����΂̕��𕥂���\n���������ŁA�����ɒH�蒅�����̂�����s�����Ǝv���Ă���B",

	"(�ِ��E�]�����Č������牽�Ƃ����������Ƃ����E�E�E�E�[�����Ă���C���[�W���������񂾂��ǂ�)",

	"�Ⴆ�Ή��ɂ͗������ɂ��钇�Ԃ����Ȃ��B�Q�[�����ƍŏ��͈�l�ڂ��������A���ꂪ�i��ł����ɂ��\n���͒��Ԃ������Ă����B���ɂ͂���Ȓ��Ԃ����Ȃ��̂��B",

	"���ɂ͈ٔ\�͂��̂Ă������B���_����ٔ\�̗͎͂������Ă�����̂́A���ۂɐ킢���o�����Ċ������̂�\n�����Ǝ��H�Ɍ������\�͂��������̂ł͂Ȃ����A�Ƃ������ƁB",

	"�w�����x�͉^�Ɉˋ����Ă��镔�����傫���B�������L���ɂȂ邽�߂ɂ�����x�̉^��P���Ȃ��邱�Ƃ͏o���邪�A\n����͐�΂ł͂Ȃ��B���ɂ͎��s�����邵�A�s���ȏ󋵂Ɋׂ������Ƃ����x���������B",

	"�̂ɂ��̔\�͂ɂ��Ă͐F�X�^�O������Ă���̂����A����������Ƒ��ɂ܂������m��Ȃ�����������̂��낤���H",

	"�E�E�E�E����A������l�����Ƃ���œ����ȂǏo�ė��Ȃ��B",

	"(����͂����܂ł������Ȃ�)",

	"�܊p�ِ��E�ɗ����Ƃ����̂ɁA���̂Ƃ���y�������Ƃ�����Ȃ��B����͉����̃o�O���H",

	"�u�ӂӁv",

	"�������ĕ��v���ɂӂ����Ă���ƁA�ӂ��ɏ΂����̂悤�Ȃ��̂����������B",

	"���͕ӂ�����n���A�₪�Ď��E�̒[�Ɉ�̐l�e�̂悤�Ȃ��̂��m�F����B",

	"�u�E�E�E�悭�������܂ŗ����A�䂪�v�z�ɊQ���Ȃ����Ƃ��鉺�˂Ȑl�̎q��v",

	"�H",

	"���������Ȃ���l�e�͂�����Ɍ������ĕ��݂��n�߂�B",

	"�R�c�R�c�R�c�A�Ɩ��ɋK�����������̑����͂ǂ������C�������B",

	"�܂��G���E�E�E�B",

	"�������x������݂̂��Ƃł͂��邪�A���Ȃ��̂͂��ꂪ�Ⴆ����ڂ��낤�Ɛ�΂Ɍ��Ȃ̂ł���B",

	"�₪�Đl�e�͊�O�ŕ��݂��~��-----------���͌��t���������B",

	"�E�E�E�E�E�E�E�������B",

	"���܂ŐL�т��������A�����ʂ�悤�ȑ傫�ȓ��A���̂悤�ɊÂ����B",

	"�����Ƃ����Ԃɉ��͖ڂ̑O�̈���(�H)����ڂ𗣂����Ƃ��o���Ȃ��Ȃ��Ă����B",

	"���͂�ǂ��\������̂������Ȃ̂��s���Ȃقǂ̖��͂��A���͖ڂ̑O�̓G�Ɋ����Ă��܂��Ă����̂��B",

	"����������قǂ̃I�[���A���炭�b�ɕ����Ă����w���W�[�i�x�Ƃ����ŏI�ڕW�ŊԈႢ�Ȃ����낤�B",

	"�u���񂽂��w���W�[�i�x�E�E�E���ȁH�v",

	"�u�@���ɂ��A�䂱�������̒鍑���x�z����A���W�[�i���̐l�ł���v",

	"�u�������E�E�E�E�����]�T�������ȁv",

	"�ʂɎ����ł͂Ȃ����A�ꉞ�����ɒB�ɗE�҂�����Ă����킯�ł͂Ȃ��B���X�̐������z�����̓G��j���Ă����B\n�����m��Ȃ��͂����Ȃ��Ǝv���̂����E�E�E",

	"����ƃ��W�[�i�͐S�̒ꂩ��s�v�c�����Ɏ���������A������B",

	"�u�t�ɉ����ł�K�v������̂��H�܂����M�l�͎���ǂ��l�߂�����ɂł��Ȃ��Ă���̂��H�v",

		"�u�E�E�E�E�E�E�͂��[�v",

		"�S����ꂽ�A�Ƃ�������ޏ��̂��ߑ��ɏ���ē`����Ă���B���炩�ɂȂ߂��Ă���悤���������A\n���͂����s���Ɋ����Ȃ������B",

		"���W�[�i�̌��t��d���A�X�ɂ͂��̗�O�ȕ\��܂ŁA������_�ɉ����Ă��̗����U�镑���͂܂�����\n�����̂��̂��B",

		"���͂���Ȕޏ��ɋ����قǖ����ɂȂ��Ă����B����͂����{����o���邱�Ƃ���Y�����ɂ��B",

		"�u�₨���A�M�l�ɂ͍��Q�̑I����������v",

		"�w���Q�{���āA����������瑤�ւƌ�����B",

		"�u��͉�ɒ����𐾂��A��̔z���ƂȂ邩�v",

		"�u��͉�ɎE����A�o�H�̔@�������ŋ����Đ������v",

		"�u���R�����ɂ���Ă͖J��������Ă�邵�A�M�l�ɂ͓��ʂȐȂ�p�ӂ��Ă���Ă������Ǝv���Ă���B\n�ǂ����A���͂�I�Ԃ܂ł��Ȃ��낤�H�v",

		"�E�E�E�Ȃ�قǁA������Ăł͂Ȃ��Ǝv�����B",

		"���܂ł��̗��s�s�Ȑ��E�ŎU�X�����̐g���댯�ɎN���Đ���Ă����B",

		"�E�҂��Ƃ������Ď��Ě�����A���≴���키�̂��E�҂Ȃ񂾂��瓖�R���Ƒ����̐l���v���Ă���B",

		"���������͌��X�͂����̕��}�Ȑl�Ԃ��B�����܂ŗ��Ċm���ɋ����͂Ȃ������A�S�܂ŕω������킯�ł͂Ȃ��B",

		"�ʂɉ��͐l�X�̖��ɗ��������Ƃ��A������肽���Ƃ������悤�ȗ��h�Ȏu�ȂǍŏ����玝�����킹�Ă�\n���Ȃ������̂��B",

		"�u�E�E�E�������ȁA�I�Ԃ܂ł��Ȃ��v",

		"�u�ł��낤�H�Ȃ�Α���----�v",

		"�u�f��v",

		"�u�_��̋V���E�E�E���H�v",

		"�u���������̐\���o�͒f��v",

		"�u�E�E�E�����ԈႢ���H�M�l�A��̐\���o��f��A�����������̂��H�v",

		"�����Ă݂���ƁA�E�͂����悤�ɓV�����グ�A���W�[�i�͍ēx�[������f�����B",

		"�u�E�E�E�����ł���A�M�l�͂����܂ł̔n���������̂��H�v",

		"�u�܂��E�E�E�n�����Ă͔̂ے肵�Ȃ����ǂȁB�����A���͂��񂽂̂��̉��҂��镗�i�ɍ��ꂽ�񂾁B\n�����牴�����񂽂̗l�Ɏ��R�ɐ��������Ǝv�����A���ꂾ�����v",

		"�u�ق����E�E�E�������Ă���̂��H���M�l�����悤�Ƃ��Ă���͎̂��E�Ɖ����ς��ʁA�����ȑI����v",

		"�u�Ⴄ�ȁA�����I�񂾂̂͋����ł��~�Q�ł��Ȃ��w��R�̑I���x���v",

		"�u��R�̑I���H�v",

		"�����E�җE�҂ƎU�X�����g��ꑱ���ė��Ă�����񂾁A��͂����������̂�肽���悤�ɂ�点�Ă��炨���B",

		"�u----�������O���x�z���Ă��v",

		"�u�́H�v",

		"�܂�Ŕ������S�C��H�����悤�Ȋ�Ŕޏ��͐Î~�����B",

		"�u�v�͐l�X�ɂƂ��Ă̋��Ђ���菜���Ă��΂����B���ꂾ������w�x�z�x�ł����Ȃ��B��������\n�w�E���x�Ɩ��m�Ɉ˗����ꂽ�킯����Ȃ����ȁv",

		"�u�ӁA�E�E�E�͂͂��I�v",

		"���߂Ĕޏ������ɏΊ���������B���̏Ί炪���̎x�z�~�ɍX�ɉ΂�t����B",

		"�u�E�E�E�����悢�v",

		"����܂ł̏Ί炪�����������̂悤�ɔޏ��̕\��ς��A��̋�C���ς�����B�u���ɑ̐��𐮂�\n�E����\����B",

		"�u�Ȃ�΂���Ă݂�A�⏬�Ȃ�l�ԕ���I�I�v",

	"�o�g���J�n",
	};
}


SceneConversation::SceneConversation() {

	_buttons_ptr = new DialogueButtons();

	ImageManager::GetInstance().SetBackGroundMapKey();
	ImageManager::GetInstance().SetCharacterMapKey();

}


//�@�e��@�\----------------------------------------------------------------------------------------------------------

void SceneConversation::PrintDialogueText() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		for (int i = 0; i < 140; ++i) {

			_receiveText[i] = prologueTextLog[i];
		}
		if (_CURRENT_TEXTROW < 140) {

			_receiveText[_CURRENT_TEXTROW] = prologueTextLog[_CURRENT_TEXTROW].substr(0, _printTextSpeed);
		}
	}
	else {

		for (int i = 0; i < 140; ++i) {

			_receiveText[i] = epilogueTextLog[i];
		}
		if (_CURRENT_TEXTROW < 140) {

			_receiveText[_CURRENT_TEXTROW] = epilogueTextLog[_CURRENT_TEXTROW].substr(0, _printTextSpeed);
		}
	}

}


void SceneConversation::PrintNextByInput() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		// �G���^�[�ŕ�������
		if (prologueTextLog[_CURRENT_TEXTROW].length() > _printTextSpeed) {

			_printTextSpeed += _printTextSpeed_adjustRate;
		}
		else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) && (prologueTextLog[_CURRENT_TEXTROW].length() <= _printTextSpeed)) {

			_CURRENT_TEXTROW++;
			_printTextSpeed = 0;
		}
	}
	else {

		// �G���^�[�ŕ�������
		if (epilogueTextLog[_CURRENT_TEXTROW].length() > _printTextSpeed) {

			_printTextSpeed += _printTextSpeed_adjustRate;
		}
		else if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN) && (epilogueTextLog[_CURRENT_TEXTROW].length() <= _printTextSpeed)) {

			_CURRENT_TEXTROW++;
			_printTextSpeed = 0;
		}
	}
}


void SceneConversation::Control_StoryLineStream() {

	if (SceneConversation::Prologue_Epilogue == 0) {

		// �w�i�摜---------------------------------------------------------------------

		if (_CURRENT_TEXTROW == 9)
			ImageManager::GetInstance().LoadBackGroundImage("�v�����[�O");

		if (_CURRENT_TEXTROW >= 9 && _CURRENT_TEXTROW < 68)
			ImageManager::GetInstance().RenderBackGroundImage(620, 125, 0.7f, 1);

		if (_CURRENT_TEXTROW == 71)
			ImageManager::GetInstance().LoadBackGroundImage("��");

		if (_CURRENT_TEXTROW >= 71 && _CURRENT_TEXTROW < 127)
			ImageManager::GetInstance().RenderBackGroundImage(500, 50, 1.0f, 1);

		// �L�����N�^�[�摜-------------------------------------------------------------
		ShowPlayerImage_Prologue();
		ShowGoddessImage();
		ShowGirlImage();
		// �n�C���C�g
		SetPlayersHighlight_Prologue();
		SetGoddessHighlight();
		SetGirlHighlight();
		// ���O����
		//SetPlayersName();
	}
	else {

		if (_CURRENT_TEXTROW == 0) {
			ImageManager::GetInstance().LoadBackGroundImage("�G�s���[�O");
		}

		ImageManager::GetInstance().RenderBackGroundImage(620, 125, 0.7f, 1);

		//�@�G�s���[�O
		ShowPlayerImage_Epilogue();
		SetPlayersHighlight_Epilogue();
		ShowFinalBossImage();
		SetFinalBossHighlight();
	}
}


void SceneConversation::StartFinalBossBattle()
{
	if (epilogueTextLog[_CURRENT_TEXTROW] == "�o�g���J�n") {

		SceneStageMap ss;

		ss.ResetHP_BeforeStartGame(SymbolOfStageMap::TYPE::KINGDOM);
	}
}


void SceneConversation::MoveToStageMap()
{
	if (prologueTextLog[_CURRENT_TEXTROW] == "���̃V�[����") {

		_CURRENT_TEXTROW = 0;

		// �X�e�[�W�}�b�v�ŕ\������V���{����������
		[](SymbolOfStageMap* ss) {

			ss = new SymbolOfStageMap();
			ss->InstantiateButton();
			delete ss;
			ss = nullptr;
			};

		// �{�^���|�C���^�폜
		delete _buttons_ptr;
		_buttons_ptr = nullptr;

		auto scene = SceneManager::GetInstance();
		scene->ChangeScene(new SceneStageMap());
	}
}


void SceneConversation::SetPlayersName() {

	GetInputName_AtLast();

	SetDrawBright(200, 200, 200);

	SetActiveKeyInput(_inputName_hdl);

	// ���̓��[�h��`��
	DrawKeyInputModeString(640, 480);

	// ���͓r���̕������`��
	DrawKeyInputString(0, 0, _inputName_hdl);

	char buff[256];
	GetKeyInputString(buff, _inputName_hdl);
	_PLAYER_NAME = buff;

	DrawStringEx(100, 300, -1, "%s", _PLAYER_NAME.c_str());
}


void SceneConversation::GetInputName_AtLast() {

	if (prologueTextLog[_CURRENT_TEXTROW] == "���O����") {
		prologueTextLog[_CURRENT_TEXTROW] = "���O����͂��Ă�������";
	}
}

//�@�n�C���C�g�ݒ�----------------------------------------------------------------------------------------------------------
void SceneConversation::SetPlayersHighlight_Prologue() {

	if (_CURRENT_TEXTROW == 9 || _CURRENT_TEXTROW == 12 || _CURRENT_TEXTROW == 16 || _CURRENT_TEXTROW == 21 || _CURRENT_TEXTROW == 22 ||
		_CURRENT_TEXTROW == 24 || _CURRENT_TEXTROW == 27 || _CURRENT_TEXTROW == 31 || _CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 36 ||
		_CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 43 || _CURRENT_TEXTROW == 48 || _CURRENT_TEXTROW == 51 || _CURRENT_TEXTROW == 54 ||
		_CURRENT_TEXTROW == 57 || _CURRENT_TEXTROW == 60 || _CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 65 || _CURRENT_TEXTROW == 67 ||
		_CURRENT_TEXTROW == 71 || _CURRENT_TEXTROW == 76 || _CURRENT_TEXTROW == 82 || _CURRENT_TEXTROW == 86 || _CURRENT_TEXTROW == 88 ||
		_CURRENT_TEXTROW == 91 || _CURRENT_TEXTROW == 107 || _CURRENT_TEXTROW == 113 || _CURRENT_TEXTROW == 117 || _CURRENT_TEXTROW == 125) {

		_isSetPlayerBright = true;
	}
	else {
		_isSetPlayerBright = false;
	}
}


void SceneConversation::SetPlayersHighlight_Epilogue() {

	if (_CURRENT_TEXTROW == 5 || _CURRENT_TEXTROW == 11 || _CURRENT_TEXTROW == 17 || _CURRENT_TEXTROW == 23 ||
		_CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 36 || _CURRENT_TEXTROW == 54 || _CURRENT_TEXTROW == 56 ||
		_CURRENT_TEXTROW == 58 || _CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 67 || _CURRENT_TEXTROW == 70)
	{
		_isSetPlayerBright = true;
	}
	else {
		_isSetPlayerBright = false;
	}
}


void SceneConversation::SetGoddessHighlight() {

	if (_CURRENT_TEXTROW == 10 || _CURRENT_TEXTROW == 26 || _CURRENT_TEXTROW == 28 || _CURRENT_TEXTROW == 30 || _CURRENT_TEXTROW == 32 ||
		_CURRENT_TEXTROW == 33 || _CURRENT_TEXTROW == 35 || _CURRENT_TEXTROW == 37 || _CURRENT_TEXTROW == 38 || _CURRENT_TEXTROW == 40 ||
		_CURRENT_TEXTROW == 41 || _CURRENT_TEXTROW == 42 || _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 45 || _CURRENT_TEXTROW == 46 ||
		_CURRENT_TEXTROW == 58 || _CURRENT_TEXTROW == 61 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 66)
	{
		_isSetGoddessBright = true;
	}
	else {
		_isSetGoddessBright = false;
	}
}


void SceneConversation::SetGirlHighlight() {

	if (_CURRENT_TEXTROW == 81 || _CURRENT_TEXTROW == 85 || _CURRENT_TEXTROW == 87 ||
		_CURRENT_TEXTROW == 89 || _CURRENT_TEXTROW == 93 || _CURRENT_TEXTROW == 95 ||
		_CURRENT_TEXTROW == 96 || _CURRENT_TEXTROW == 97 || _CURRENT_TEXTROW == 98 ||
		_CURRENT_TEXTROW == 112 || _CURRENT_TEXTROW == 114 || _CURRENT_TEXTROW == 116 ||
		_CURRENT_TEXTROW == 118 || _CURRENT_TEXTROW == 121 || _CURRENT_TEXTROW == 122 ||
		_CURRENT_TEXTROW == 124 || _CURRENT_TEXTROW == 126)
	{
		_isSetGirlBright = true;
	}
	else {
		_isSetGirlBright = false;
	}
}


void SceneConversation::SetFinalBossHighlight() {

	if (_CURRENT_TEXTROW == 35 || _CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 40
		|| _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 46 || _CURRENT_TEXTROW == 47
		|| _CURRENT_TEXTROW == 48 || _CURRENT_TEXTROW == 55 || _CURRENT_TEXTROW == 57
		|| _CURRENT_TEXTROW == 59 || _CURRENT_TEXTROW == 61 || _CURRENT_TEXTROW == 63
		|| _CURRENT_TEXTROW == 65 || _CURRENT_TEXTROW == 67 || _CURRENT_TEXTROW == 71
		|| _CURRENT_TEXTROW == 73 || _CURRENT_TEXTROW == 75)
	{
		_isSetFinalBossBright = true;
	}
	else {
		_isSetFinalBossBright = false;
	}
}


//�@�`��----------------------------------------------------------------------------------------------------------
void SceneConversation::ShowPlayerImage_Prologue() {

	if (_isSetPlayerBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {

		ImageManager::GetInstance().LoadCharacterImage("�����G2�Q�v���C���[");
	}
	if (_CURRENT_TEXTROW < 68) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "�����G2�Q�v���C���[");
	}
	if (_CURRENT_TEXTROW > 72) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "�����G2�Q�v���C���[");
	}
}


void SceneConversation::ShowPlayerImage_Epilogue() {

	if (_isSetPlayerBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {

		ImageManager::GetInstance().LoadCharacterImage("�����G2�Q�v���C���[");
	}
	if (_CURRENT_TEXTROW < 77) {

		ImageManager::GetInstance().RenderCharacterImage(110, 560, 1.0f, 1, "�����G2�Q�v���C���[");
	}
}

void SceneConversation::ShowGirlImage() {


	if (_isSetGirlBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 71) {
		ImageManager::GetInstance().LoadCharacterImage("�V���G�b�g�Q����");
	}

	if (_CURRENT_TEXTROW > 71 && _CURRENT_TEXTROW <= 80) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "�V���G�b�g�Q����");
	}

	if (_CURRENT_TEXTROW == 81) {
		ImageManager::GetInstance().LoadCharacterImage("�m�[�}���Q����");
	}

	if (_CURRENT_TEXTROW == 81 || _CURRENT_TEXTROW == 82 || _CURRENT_TEXTROW == 83 ||
		_CURRENT_TEXTROW == 84 || _CURRENT_TEXTROW == 87 || _CURRENT_TEXTROW == 88 || _CURRENT_TEXTROW == 97 ||
		_CURRENT_TEXTROW == 113 || _CURRENT_TEXTROW == 114 || _CURRENT_TEXTROW == 115) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "�m�[�}���Q����");
	}

	if (_CURRENT_TEXTROW == 85) {
		ImageManager::GetInstance().LoadCharacterImage("�^���Q����");
	}

	if (_CURRENT_TEXTROW == 85 || _CURRENT_TEXTROW == 86 || _CURRENT_TEXTROW == 95 ||
		_CURRENT_TEXTROW == 96 || _CURRENT_TEXTROW == 112 || _CURRENT_TEXTROW == 113) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "�^���Q����");
	}

	if (_CURRENT_TEXTROW == 93) {
		ImageManager::GetInstance().LoadCharacterImage("�Ί�Q����");
	}

	if (_CURRENT_TEXTROW == 93 || _CURRENT_TEXTROW == 94 || _CURRENT_TEXTROW == 98 || _CURRENT_TEXTROW == 99 ||
		_CURRENT_TEXTROW == 100 || _CURRENT_TEXTROW == 101 || _CURRENT_TEXTROW == 102 ||
		_CURRENT_TEXTROW == 103 || _CURRENT_TEXTROW == 104 || _CURRENT_TEXTROW == 105 ||
		_CURRENT_TEXTROW == 106 || _CURRENT_TEXTROW == 107 || _CURRENT_TEXTROW == 108 ||
		_CURRENT_TEXTROW == 109 || _CURRENT_TEXTROW == 110 || _CURRENT_TEXTROW == 111 ||
		_CURRENT_TEXTROW == 121 || _CURRENT_TEXTROW == 122 || _CURRENT_TEXTROW == 123 ||
		_CURRENT_TEXTROW == 124 || _CURRENT_TEXTROW == 125 || _CURRENT_TEXTROW == 126) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "�Ί�Q����");
	}

	if (_CURRENT_TEXTROW == 89) {
		ImageManager::GetInstance().LoadCharacterImage("�{��2�Q����");
	}

	if (_CURRENT_TEXTROW == 89 || _CURRENT_TEXTROW == 90 ||
		_CURRENT_TEXTROW == 91 || _CURRENT_TEXTROW == 92) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "�{��2�Q����");
	}

	if (_CURRENT_TEXTROW == 116) {
		ImageManager::GetInstance().LoadCharacterImage("�{��1�Q����");
	}

	if (_CURRENT_TEXTROW == 116 || _CURRENT_TEXTROW == 117 || _CURRENT_TEXTROW == 118 ||
		_CURRENT_TEXTROW == 119 || _CURRENT_TEXTROW == 120) {

		ImageManager::GetInstance().RenderCharacterImage(1050, 385, 0.9f, 1, "�{��1�Q����");
	}
}


void SceneConversation::ShowGoddessImage() {

	if (_isSetGoddessBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 0) {
		ImageManager::GetInstance().LoadCharacterImage("�V���G�b�g�Q���_");
	}

	if (_CURRENT_TEXTROW < 20) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "�V���G�b�g�Q���_");
	}
	else if (_CURRENT_TEXTROW >= 20) {

		if (_CURRENT_TEXTROW == 20) {
			ImageManager::GetInstance().LoadCharacterImage("�m�[�}���Q���_");
		}

		if (_CURRENT_TEXTROW == 20 || _CURRENT_TEXTROW == 21 || _CURRENT_TEXTROW == 22 || _CURRENT_TEXTROW == 23 ||
			_CURRENT_TEXTROW == 24 || _CURRENT_TEXTROW == 25 || _CURRENT_TEXTROW == 26 || _CURRENT_TEXTROW == 27 || _CURRENT_TEXTROW == 32 ||
			_CURRENT_TEXTROW == 38 || _CURRENT_TEXTROW == 39 || _CURRENT_TEXTROW == 41 || _CURRENT_TEXTROW == 43 || _CURRENT_TEXTROW == 58 ||
			_CURRENT_TEXTROW == 59 || _CURRENT_TEXTROW == 60 || _CURRENT_TEXTROW == 66 || _CURRENT_TEXTROW == 67) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "�m�[�}���Q���_");
		}

		if (_CURRENT_TEXTROW == 28) {
			ImageManager::GetInstance().LoadCharacterImage("�^���Q���_");
		}

		if (_CURRENT_TEXTROW == 28 || _CURRENT_TEXTROW == 29 || _CURRENT_TEXTROW == 30 || _CURRENT_TEXTROW == 31 || _CURRENT_TEXTROW == 35 ||
			_CURRENT_TEXTROW == 36 || _CURRENT_TEXTROW == 42 || _CURRENT_TEXTROW == 46 || _CURRENT_TEXTROW == 47 || _CURRENT_TEXTROW == 48 ||
			_CURRENT_TEXTROW == 49 || _CURRENT_TEXTROW == 50 || _CURRENT_TEXTROW == 51 || _CURRENT_TEXTROW == 52 || _CURRENT_TEXTROW == 53 ||
			_CURRENT_TEXTROW == 54 || _CURRENT_TEXTROW == 55 || _CURRENT_TEXTROW == 56 || _CURRENT_TEXTROW == 57 || _CURRENT_TEXTROW == 61 ||
			_CURRENT_TEXTROW == 62 || _CURRENT_TEXTROW == 63 || _CURRENT_TEXTROW == 64 || _CURRENT_TEXTROW == 65) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "�^���Q���_");
		}

		if (_CURRENT_TEXTROW == 33) {
			ImageManager::GetInstance().LoadCharacterImage("�Ί�Q���_");
		}

		if (_CURRENT_TEXTROW == 33 || _CURRENT_TEXTROW == 34 || _CURRENT_TEXTROW == 37 ||
			_CURRENT_TEXTROW == 40 || _CURRENT_TEXTROW == 44 || _CURRENT_TEXTROW == 45) {

			ImageManager::GetInstance().RenderCharacterImage(1050, 520, 1.0f, 1, "�Ί�Q���_");
		}
	}
}


void SceneConversation::ShowFinalBossImage() {

	if (_isSetFinalBossBright)
		SetDrawBright(255, 255, 255);
	else
		SetDrawBright(80, 80, 80);


	if (_CURRENT_TEXTROW == 19) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�V���G�b�g");
	}

	if (_CURRENT_TEXTROW >= 19 && _CURRENT_TEXTROW <= 34) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�V���G�b�g");
	}

	if (_CURRENT_TEXTROW == 35) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW >= 35 && _CURRENT_TEXTROW <= 39) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW == 40) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�f�t�H���g");
	}

	if (_CURRENT_TEXTROW >= 40 && _CURRENT_TEXTROW <= 43) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�f�t�H���g");
	}

	if (_CURRENT_TEXTROW == 44) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW >= 44 && _CURRENT_TEXTROW <= 54) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW == 55) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�Ί�");
	}

	if (_CURRENT_TEXTROW >= 55 && _CURRENT_TEXTROW <= 56) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�Ί�");
	}

	if (_CURRENT_TEXTROW == 57) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�f�t�H���g");
	}

	if (_CURRENT_TEXTROW >= 57 && _CURRENT_TEXTROW <= 58) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�f�t�H���g");
	}

	if (_CURRENT_TEXTROW == 59) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW >= 59 && _CURRENT_TEXTROW <= 70) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW == 71) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�_���[�W_2");
	}

	if (_CURRENT_TEXTROW >= 71 && _CURRENT_TEXTROW <= 72) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�_���[�W_2");
	}

	if (_CURRENT_TEXTROW == 73) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW >= 73 && _CURRENT_TEXTROW <= 74) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�_���[�W_1");
	}

	if (_CURRENT_TEXTROW == 75) {
		ImageManager::GetInstance().LoadCharacterImage("�X�e�[�W5�Q�{�X�Q�_���[�W_4");
	}

	if (_CURRENT_TEXTROW >= 75) {
		ImageManager::GetInstance().RenderCharacterImage(1050, 435, 0.8f, 1, "�X�e�[�W5�Q�{�X�Q�_���[�W_4");
	}
}


void SceneConversation::Render(const float deltaTime) {

	SetDrawBright(255, 255, 255);

	SetFontSize(20);
	DrawBox(0, 500, 1280, 800, GetColor(20, 20, 20), true);

	// �e�L�X�g�`��
	PrintDialogueText();
	SetFontSize(22);
	DrawString(90, 550, _receiveText[_CURRENT_TEXTROW].c_str(), -1);


	// �{�^���`��
	_buttons_ptr->RenderDialogueButton();


	SetFontSize(35); // �E���ɕ\��
	DrawString(1070, 620, "Enter", -1);
}


//�@�X�V----------------------------------------------------------------------------------------------------------
void SceneConversation::Update(const float deltaTime) {

	MoveToStageMap();

	StartFinalBossBattle();

	Control_StoryLineStream();

	// �_�C�A���O�{�^��-----------------------------------------
	_buttons_ptr->AutoDialogue();
	PrintNextByInput();
}

void SceneConversation::ReleaseMem() {

	DeleteGraph(_bg_hdl);
}
