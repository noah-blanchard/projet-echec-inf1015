#pragma once

namespace model
{
	class ColorPiece
	{
	public:
		virtual ~ColorPiece() = default; // destructeur d'une classe de base doit être virtuel

		// TODO

	private:
		ColorPiece() = default; // peut pas être instancié
		ColorPiece(const ColorPiece&) = delete; // pas de copie
		ColorPiece& operator=(const ColorPiece&) = delete; // pas d'affectation
	};
}