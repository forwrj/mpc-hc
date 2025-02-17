/*
 * (C) 2013-2018 see Authors.txt
 *
 * This file is part of MPC-HC.
 *
 * MPC-HC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-HC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "VersionHelpersInternal.h"

static bool IsWindows64()
{
#ifdef _WIN64
	return true;
#endif

	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandleW(L"kernel32"), "IsWow64Process");
	BOOL bIsWow64 = FALSE;
	if (fnIsWow64Process) {
		fnIsWow64Process(GetCurrentProcess(), &bIsWow64);
	}

	return !!bIsWow64;
}

namespace SysVersion
{
	inline const bool IsWin7orLater() {
		const static bool bIsWin7orLater = IsWindows7OrGreater();
		return bIsWin7orLater;
	}
	inline const bool IsWin8orLater() {
		const static bool bIsWin8orLater = IsWindows8OrGreater();
		return bIsWin8orLater;
	}
	inline const bool IsWin81orLater() {
		const static bool bIsWin81orLater = IsWindows8Point1OrGreater();
		return bIsWin81orLater;
	}
	inline const bool IsWin10orLater() {
		const static bool bIsWin10orLater = IsWindows10OrGreater();
		return bIsWin10orLater;
	}
	inline const bool IsWin10RS4orLater() {
		const static bool bIsWin10RS4orLater = IsWindowsVersionOrGreaterBuild(HIBYTE(_WIN32_WINNT_WINTHRESHOLD), LOBYTE(_WIN32_WINNT_WINTHRESHOLD), 17134);
		return bIsWin10RS4orLater;
	}
    inline const bool IsWin11orLater() {
        const static bool bIsWin11orLater = IsWindows11OrGreater();
        return bIsWin11orLater;
    }
    inline const bool IsW64() {
		const static bool bIsW64 = IsWindows64();
		return bIsW64;
	}
}
