#include <stdio.h>
#include "main_core.h"
#include "medialib.h"
#include "play.h"
#include "db.h"
void *main_core(int cmd, void *data)
{
	static int state = 0;
	static char *now_play;
	static char *media_type;
	static int playlist_position;
	static int window_size[2];
	static link_t *mlink;
	static link_t *plink;
	int ctype;
	ctype = cmd / 1000;
	switch(ctype) {
		case 1:
			switch(cmd) {
				case GENERAL_MEDIALIB_INIT:
					mlink = (link_t *)data;
					break;
				case GENERAL_PLAYLIST_INIT:
					plink = (link_t *)data;
					break;
				case GENERAL_PLAY_MODE:
					state = *((int*)data);
					break;
				case GENERAL_VOLUME:
                                  //TODO					general_volume(*((int*)data));
				case GENERAL_MUTE:
                                  //TODO					general_mute(*((int*)data));
				default:
					return NULL;
			}
			break;
		case 2:
			switch(cmd) {
				case REQUEST_STATE:
					return &state;
					break;
				case REQUEST_NOW_PLAY:
					return &now_play;
					break;
				case REQUEST_MEDIA_TYPE:
					return media_type;
					break;
				case REQUEST_PLAYLIST_POSITION:
					return &playlist_position;
					break;
				case REQUEST_WINDOW_SIZE:
					return &window_size;
					break;
				case REQUEST_VOLUME:
                                  //TODO					return request_volume();
					break;
				default:
					// 处理错误命令
					return NULL;
			}
			break;
		case 3:
			switch(cmd) {
				case MEDIALIB_SHOW:
                                  //TODO					medialib_ui_show(mlink, data);
					break;
				case MEDIALIB_BRUSH:
                                  //TODO					treeClass_data(mlink, data);
                                        //TODO					treeMedialib_data(mlink, data);
					break;
				case MEDIALIB_ADD_FILE:
                                  //TODO					medialib_add(mlink, data);
					break;
				case MEDIALIB_ADD_DIR:
                                  //TODO					medialib_add_dir(mlink, data);
					break;
				case MEDIALIB_DEL_ALL:
                                  //TODO					medialib_del_all(mlink, data);
					break;
				case MEDIALIB_SEARCH:
                                  //TODOmedialib_search(mlink, data);
					break;
				case MEDIALIB_SEND_TO_PLAYLIST:
                                  //TODOmedialib_sendto(plink, data);
					break;
				case MEDIALIB_FIND:
                                  //TODOmedialib_find(mlink, data);
					break;
				case PLAYLIST_SHOW:
                                  //TODOplaylist_ui_show(plink, data);
					break;
				case PLAYLIST_BRUSH:
                                  //TODO treePlaylist_data(plink, data);
					break;
				case PLAYLIST_ADD_FILE:
                                  //TODO	playlist_add(plink, data);
					break;
				case PLAYLIST_ADD_DIR:
                                  //TODOplaylist_add_dir(plink, data);
					break;
				case PLAYLIST_OPEN:
                                  //TODOplaylist_open(plink, data);
					break;
				case PLAYLIST_SAVE:
                                  //TODOplaylist_save(plink, data);
					break;
				case PLAYLIST_DEL:
                                  //TODOplaylist_del(plink, data);
					break;
				case PLAYLIST_DEL_ALL:
                                  //TODOplaylist_del_all(plink, data);
					break;
			}
			break;
		case 4:
			play(cmd, data);
			break;
		default:
			// 处理错误命令
			return NULL;
	}
	return NULL;
}

