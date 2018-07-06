namespace API
{
//inline outer namespace (only 1)
	inline namespace v2
	{
		bool newfunc(bool param)
			{ if(param){ return true; } else { return false; } }
	}
	
	namespace v1
	{
		bool oldfunc(bool param)
		{ if(param) { return true; }else { return false; } }
	}
}
