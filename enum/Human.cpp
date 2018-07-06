#include "Human.h"

Human::Human():status('z'), _organ_system(Cardiovascular)
{
}

enum Human::OrganSystem : unsigned short
	{
		Integumentary,
		Skeletal,
		Muscular,
		Lymphatic,
		Respiratory,
		Digestive,
		Nervous,
		Endocrine,
		Cardiovascular,
		Urinary,
		Reproductive
	};
